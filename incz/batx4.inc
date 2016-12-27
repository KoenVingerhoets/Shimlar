<?php

$btlstr="";$damage=0;

function batproc($l,$p,$a,$k,$m){

global $REMOTEADDR,$REQUESTURI,$btlstr,$damage,$lastmon,$lvl,$spec_ma;
$REMOTEADDR = $_SERVER['REMOTE_ADDR'];
$REQUESTURI = $_SERVER['REQUEST_URI'];
if($REMOTEADDR==""){
 $REMOTEADDR=$l;
}

if(is_numeric($l) && $REQUESTURI=="/battle4.php"){

	if(tarkista($p) && tarkista($a) && tarkista($m) && $k != -1){
		$fmt=1;$kd_tax=0;$action=$a;
		$query="Lock Tables Players WRITE,Stats WRITE,Inventory WRITE,Zones WRITE,Messages WRITE,Quests WRITE,Races WRITE,Hunts WRITE,chat1 WRITE,chat4 WRITE,Clans WRITE,Kingdoms WRITE,Modactions WRITE,PKTag READ, PKLog WRITE";
		mysql_query($query);
		
		$query="Select Id,password,loc_zone,loc_x,loc_y,lastaction,banned,name as pname from Players where Id = $l";
		if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
			extract(mysql_fetch_array($result));
			
			if($p==$password && $banned !=100){
				srand(make_seed());
				$bdelay=0;$aika=100;$lastfight=0;$x=0;$y=0;$special1=0;$drop_bonus=0;
				
				$query="Select freelvl,lvl,exp,fmt,status,turns,tstatus,health,e_health,gold,align from Stats where Id=$Id";
				$result=mysql_query($query);extract(mysql_fetch_array($result));
				$lastmon=$status;

/*				
				if($lastmon==1000 && ($action=="f"||$action=="c")){
					$query="Select(now()-fight_time) as aika, (UNIX_TIMESTAMP( ) - UNIX_TIMESTAMP( pk_time ))  as pkd from Stats where Id=$Id";
					$result=mysql_query($query);
					extract(mysql_fetch_array($result));
				}else{
					$query="Select(now()-fight_time) as aika from Stats where Id=$Id";
					$result=mysql_query($query);
					extract(mysql_fetch_array($result));
				}
*/
				if($lastmon==1000 && ($action=="f"||$action=="c")){
					$query="Select (UNIX_TIMESTAMP( ) - UNIX_TIMESTAMP( pk_time ))  as pkd from Stats where Id=$Id";
					$result=mysql_query($query);
					extract(mysql_fetch_array($result));
				}
				
				switch($action)
				{
					case "n":
						include "battle/newf.inc";
						break;
					case "d":
						include "battle/newd.inc";
						break;
					case "f":
					case "c":
						include "battle/fightcast.inc";
						break;
				}
				
				$btlstr.=".";
				$ip=$REMOTEADDR;
				
				$query="Update Stats set status=$lastmon where Id=$Id";
				mysql_query($query);
				
				$query="Update Players set lastaction='$action',wrong_pw=0,last_ip='$ip' where Id=$Id";
				mysql_query($query);
				
				$query="Unlock Tables";
				mysql_query($query);
				
				if($action=="n")
					print "x10($turns);";
				
				print "x1($exp,$gold,$health,$align);";
					
				if($action=="f"|| $action=="c")
				{					
					if($special1==3)
					{
						$imsg="";
						for($i=0;$i<30;++$i)
						{
							$ix=$invlist[$i];
							$imsg.="$ix,";
						}
						$imsg.="0";
						print "x3(\"$imsg\");";
					}
				}
				
				if($lastmon<1000){
					$opponent=0;
				}
				
				$oppname=getName($opponent);
				
				// print "x2($lastmon,$lastfight,$bdelay,\"$oppname\",\"$btlstr\");";
				print "x2($lastmon,$lastfight,\"$oppname\",\"$btlstr\");";
				print "xX(\"$action\",0);";
			
			}else if($p !=$password){
				++$wrong_pw;
				$l = tarkista(getName($l));
				$query="Update Players set wrong_pw=$wrong_pw where name='$l'";
				mysql_query($query);
			
				if($wrong_pw>9){
					$ip=$REMOTEADDR;
					if($ip !=''){
						$query="Insert into Ipban values('$ip',now(),'$l')";
						mysql_query($query);
						$query="Update Players set wrong_pw=0 where name='$l'";
						mysql_query($query);
					}else{
						print "javascript:alert(\"Stop guessing passwords, your IP will be banned.\");\n";
					}
				}
				ep2(0);
			
			}else if($banned==100){
				ep2(1);
			}
		}else{
			ep2(2);
		}
	}else{
		ep2(3);
	}
}else if(strlen($l)<4){
	ep2(4);
}else if($REQUEST_URI!="/battle4.php"){
	ep2(38);
}
	usleep(1500000);
}

function make_seed(){

  list($usec,$sec)=explode(' ',microtime());

  return(float) $sec +((float) $usec * 100000);

}

?>
