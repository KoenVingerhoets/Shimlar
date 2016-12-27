<?php
include '../incz/constvars.inc';
init_dbx();
  $randomz = rand(1,50);
  if ($randomz != 25) {
  	print "<script language=\"javascript\" src=\"upd.js\"></script>";
  } else {
  	print "<script language=\"javascript\">";
  	include 'upd.js';
  	print "</script>";
  }
  print "<script language=\"javascript\">";
$newpl=ucwords(trim($_POST["newpl"]));
$newlogin=ucwords(trim($_POST["newlogin"]));
$maili=str_replace("www.", "", $_POST["maili"]);
$newpw=$_POST["newpw"];
$newpw2 = $_POST["newpw2"];
$rn2=$_POST["rn2"];
$gn2=$_POST["gn2"];
$statusType=$_POST["statusType"];

if ((strlen($newpl)>3) && (strlen($maili)>6) && (strlen($newlogin)>3) && false){
  if(cr_tarkista($newpl,1) && cr_tarkista($newpw,0) && cr_tarkista($newpw2,0) && cr_tarkista($maili,0) && cr_tarkista($newlogin,0)) {
    if ($newlogin != $newpl) {
    	$doContinue = true;
    	$newChannel=0;
    	$newLevel=0;
    	$newOrb=0;
    	$newOrbEquip=0;
    	$newGold=100; 
    	$stopSales=$statusType;
    	
    	// only allow 3 not activated chars / ip
    	$query = "select * from Players where last_ip = '".$_SERVER['REMOTE_ADDR']."' and pstatus = 0";
    	$result = mysql_query($query);
    	if ($result==true and mysql_num_rows($result)>4) {
    		$doContinue = false;
    		ep2(90);
    	}
    	
    	// verify with reserved
    	$query="Select Name as N from Reservation where Name='$newpl'";
      $result=mysql_query($query);
      if (($doContinue) && ($result==TRUE and mysql_num_rows($result)==1 )) {
      	$query="select * from Reservation where Name = '$newpl' and Login = '$newlogin'";
      	$result=mysql_query($query);
      	if ($result==TRUE and mysql_num_rows($result)== 0 ) {
      		// the name is in the reserved table BUT the login is incorrect
      		$doContinue = false;
      		ep2(74);
      	}
      }
      
      $query="Select Login as L from Reservation where Login='$newlogin'";
      $result=mysql_query($query);
			if (($doContinue) && ($result==TRUE and mysql_num_rows($result)==1 )) {
      	$query="select * from Reservation where Name = '$newpl' and Login = '$newlogin'";
      	$result=mysql_query($query);
      	if ($result==TRUE and mysql_num_rows($result)== 0 ) {
      		// the name is in the reserved table BUT the login is incorrect
      		$doContinue = false;
      		ep2(75);
      	}
      }
    	
    	// verify with existing players
      $query="Select name as N from Players where name='$newpl'";
      $result=mysql_query($query);
      if (($doContinue) && ($result==TRUE and mysql_num_rows($result)==1 )) {
      	$doContinue = false;
      	ep2(22);
      }
      $query="Select login as L from Players where login='$newlogin'";
      $result=mysql_query($query);
      if (($doContinue)&&($result==TRUE and mysql_num_rows($result)==1)) {
      	$doContinue = false;
      	ep2(73);
      }
      
      // verify with mod names
      $query="select name as N from Players where channels in (10,11,12,20)";
      $result=mysql_query($query);
      $num=mysql_num_rows($result);
      $i=0;
      while ($i < $num) 
      {
      	if ($doContinue) 
      	{
      		$modname=mysql_result($result,$i,"N");
      		$pos = strpos($newpl, $modname);
      		if ($pos===false) 
      		{
      			$pos = strpos($newpl, str_replace(" ","",$modname));
      			if ($pos!==false) 
      			{
      				$doContinue = false;
      				ep2(89);
      			}
      		} else {
      			$doContinue = false;
      			ep2(89);
      		}
      	}
				$i++;
			}
      
      // verify with players from previous round
      $query="select * from Reservation where Name = '$newpl'";
      $result=mysql_query($query);
      if (($doContinue)&&($result==TRUE and mysql_num_rows($result)==1 )) {
      	// there is a player with these details in the reservation table, let's now verify the rest
      	extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
      	if (($tgt_Password == $newpw) && ($tgt_Login == $newlogin)) {
      		$doContinue = true;
      		$newChannel=$tgt_Channels;
      		// for mods
      		if ($newChannel==10) 
      		{
      			$newLevel = 25;
      			$newGold = 1000;
      			$stopSales = 0;
      		}
      		// for archies
      		if ($newChannel==20) 
      		{
      			$newLevel = 100;
      			$newGold = 1000000;
      			$newOrb = 41210000;
      			$newOrbEquip = 3;
      			$stopSales = 0;
      		}
      	} else {
      		$doContinue = false;
      		ep2(74);
      	}
      }
      
      if ($doContinue){
        if($newpw==$newpw2) {
          if(strlen($newpw)>3) {
            if($rn2 < 0 || $rn2 > 8) {
              $rn2=0;
            }
            $query="Select * From Races where rid=$rn2";
            $stats=mysql_query($query);
            extract(mysql_fetch_array($stats));
            $rt=$rn2+100*min($gn2,1);
            $zone=$rn2;
            
            $newpl = better_ucwords($newpl);
          
            $query2="Insert into Players Values 
(null,'$newpl','$newpw','$maili','',1,1,$zone,$newChannel,0,0,0,0,0,0,0,$fire_bonus,$cold_bonus,$air_bonus,$arcane_bonus,$sword_bonus,$axe_bonus,$staff_bonus,$mace_bonus,$armor_bonus,1,now(),'cr',now(),1,1,1,1,'".$_SERVER['REMOTE_ADDR']."',0,0,0,'$newlogin')";
            mysql_query($query2);
            $userid = mysql_insert_id();
          
            $query4="Insert into Stats Values 
($userid,'$newpl',0,$rt,$r_str,$r_dex,$r_vit,$r_ntl,$r_wis,$r_vit,0,$newGold,0,1,$newLevel,0,0,1,0,0,now(),'',0,now(),now(),0,$stopSales,0,1080,$statusType,0)";
            mysql_query($query4);

            $query3="Insert into Inventory Values 
($userid,'$newpl',1000000,5000000,$newOrb,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,0,0,$newOrbEquip,0,0)";
            mysql_query($query3);
          
            // send email in the background
            $query5="select UNIX_TIMESTAMP(ax_time) as ax_time from Players where Id = $userid";
            $result=mysql_query($query5);
            extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
                  
            $link="http://www.shimlar.org/validate.php?u=$userid&nr=$tgt_ax_time";
            $subject = "Shimlar validation mail for character $newpl";
						$message = "To validate your character, click $link or copy it to your browser.\r\n".
							"Your login details after validation are $newlogin - $newpw.\r\n" .
							"Do NOT reply to this message.\r\n" .
							"\r\n" .
							"Lord A";
						$headers = "From: lorda@pandora.be\r\n" .
       			"X-Mailer: PHP/" . phpversion() . "\r\n" .
       			"MIME-Version: 1.0\r\n" .
       			"Content-Type: text/html; charset=utf-8\r\n" .
       			"Content-Transfer-Encoding: 8bit\r\n\r\n";
						mail($maili, $subject, $message, $headers); 
		          
            crpage($newpl,$newlogin);

          } else {
            ep2(5);
          }
        } else {
          ep2(21);
        }
      }
    } else {
      ep2(70);
    }
  } else {
    ep2(3);
  }
} else {
 ep2(4);
}
print "</script>";
close_dbx();


function crpage($crname,$crlogin) {
  print "crp(\"$crname\",\"$crlogin\");\n";
}

function better_ucwords($string) {
   $string = ucwords($string);
   $string = preg_replace('#[\\/][a-z]#e', "strtoupper('$0')", $string);
   return $string;
}

function cr_tarkista($jono,$x) {
  $jono=strtolower($jono);
  if(strstr($jono,"\""))
    return 0;
  if(strstr($jono,"\'"))
    return 0;
  if(strstr($jono,"\\"))
    return 0;
  if(strstr($jono,"<"))
    return 0;
  if(strstr($jono,">"))
    return 0;
  if(strstr($jono,"&"))
    return 0;
  if(strstr($jono,"/"))
    return 0;
  if(strstr($jono,"%"))
    return 0;
  if(strstr($jono,"`"))
    return 0;
  if(strstr($jono,"´"))
    return 0;
  for($i=123;$i<256;$i++) {
    if(strstr($jono,$i))
      return 0;
  }
  for($i=0;$i<32;$i++) {
    if(strstr($jono,$i))
      return 0;
  }
  for($i=33;$i<46+$x*2;$i++) {
    if(strstr($jono,$i))
      return 0;
  }
  for($i=58;$i<64;$i++) {
    if(strstr($jono,$i))
      return 0;
  }
  for($i=91;$i<95;$i++) {
    if(strstr($jono,$i))
      return 0;
  }

  if(strstr($jono,"fuck") || strstr($jono,"shit") || strstr($jono,"bitch") || 
			strstr($jono,"vittu") || strstr($jono,"  ") || strstr($jono,"shimlar") ||
	(strtoupper($jono)=="SLESAI") || 
	(strtoupper($jono)=="JACK HANDY") || 
	(strtoupper($jono)=="OZZYOLE" ) || 
	(strtoupper($jono)=="SOULLESS KILLER") ||
	(strtoupper($jono)=="KARI") ||
	(strtoupper($jono)=="GRILAK") ||
	(strtoupper($jono)=="BLIND_ANJEL") ||
	(strtoupper($jono)=="NIGHTDEMON") ||
	(strtoupper($jono)=="KRAGG THE GRIMM") || 
	(strtoupper($jono)=="THERETURNOFKITYOMAN") ||
	(strtoupper($jono)=="KOEN") ||
	(strtoupper($jono)=="K0EN") ||
	(strtoupper($jono)=="MICHEAL")){
    return 0;
  }
return 1;
}

?>

