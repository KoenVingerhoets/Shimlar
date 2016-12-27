<?php
function chatproc($l,$p){
global $special1,$special2,$special3,$special4,$REMOTE_ADDR;
$special1=0;$special2=0;$special3=0;$special4=0;
$REMOTEADDR=$_SERVER['REMOTE_ADDR'];
if($REMOTEADDR==""){
 $REMOTEADDR=$l;
}
if(is_numeric($l)){
  if(tarkista($p)){
    $special1=0;$special2=0;
    srand(make_seed());
    $query="Select Id,name,password,channels,banned,wrong_pw,lastaction from Players where Id=$l";
    if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
      extract(mysql_fetch_array($result));
      $query="Select clan,race from Stats where Id = $Id";
      $result=mysql_query($query);
      extract(mysql_fetch_array($result));
      $race%=100;
/*      if($race>=20){
        $race-=20;
      } */
      if($clan<2){
        $clan=0;
      }
      $cx_size=0;
      if($p==$password && $banned !=100){
        $cx_size=valmista_msg($Id);
        valmista_chat($name,$cx_size,$channels,$clan,$race,$Id);
        if($special2==1 || $special3==1){
          $query="Select exp,gold,health from Stats where Id = $Id";
          $result=mysql_query($query);
          extract(mysql_fetch_array($result));
          print "x1($exp,$gold,$health);";
        }
        if($special1==1 || $special3==1){
          $query="Select gold,banked from Stats where Id = $Id";
          $result=mysql_query($query);
          extract(mysql_fetch_array($result));
          print "x4($gold,$banked);";
        }
        if($special2==1 || $special3==1){
          $query="Select * from Inventory where Id = $Id";
    	  $result=mysql_query($query);
    	  extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"my");
    	  $invlist=array($my_i1,$my_i2,$my_i3,$my_i4,$my_i5,$my_i6,$my_i7,$my_i8,$my_i9,$my_i10,$my_i11,$my_i12,$my_i13,$my_i14,$my_i15,$my_i16,$my_i17,$my_i18,$my_i19,$my_i20,$my_i21,$my_i22,$my_i23,$my_i24,$my_i25,$my_i26,$my_i27,$my_i28,$my_i29,$my_i30);
          $imsg="";
          for($i=0;$i<30;$i++){
            $ix=$invlist[$i];
            $imsg.="$ix,";
          }
          $imsg.="0";
          print "x3(\"$imsg\");";
          print "x5($my_lhand,$my_rhand,$my_spellone,$my_spelltwo,$my_armor,$my_accx,$my_tradex);";
        }
        if($special4==1){
          $query="Select * from Clans where cid=$clan";
          $result=mysql_query($query);
          if($result==TRUE and mysql_num_rows($result)>0){
            extract(mysql_fetch_array($result));
            print "xC(\"$cname\",\"$cleader\",\"$cleader2\",$cpower);";
          }else {
            print "xC(\"\",\"\",\"\",0);";
          }
        }
        print "Z();";
      }else if($p !=$password){
        ++$wrong_pw;
        $query="Update Players set wrong_pw=$wrong_pw where Id = $Id";
        mysql_query($query);
        if($wrong_pw>9){
          if($REMOTEADDR !=''){
            global $REMOTEADDR;
            $query="Insert into Ipban values('$REMOTEADDR',now(),'$name')";
            mysql_query($query);
            $query="Update Players set wrong_pw=0 where Id = $Id";
            mysql_query($query);
          }else {
          print "javascript:alert(\"Stop guessing passwords,your IP will be banned.\");\n";
          }
        }
        ep2(0);
      }else if($banned==100){
        ep2(1);
      }
    }else {
      ep2(2);
    }
  }else {
    ep2(3);
  }
}else {
  ep2(4);
}
}
function valmista_msg($pid){
  $a1=0;
  global $special1,$special2,$special3,$special4,$REMOTEADDR;
  $REMOTEADDR = $_SERVER['REMOTE_ADDR'];
  $query="Select M.pfrom,M.msgtxt,M.msgtype,date_format(M.msgwhen,'%d %b %T'),I.checked from Messages M, Inventory I where M.pto=$pid and I.Id = $pid";
  if(($result=mysql_query($query))==TRUE &&($a1=mysql_num_rows($result))>0){
    $a1=min($a1,19);
    for($i=0;$i<$a1;$i++){
      $row=mysql_fetch_row($result);
      $msgn[$i]=$row[0];
      $msgtxt[$i]=$row[1];
      $msgtype[$i]=$row[2];
      $msgt[$i]=$row[3];
      $thisischecked[$i]=$row[4];
     
      switch($msgtype[$i]) {
      	case 21:
      	  $special1=1;
      	  break;
      	case 22:
      	  $special2=1;
          if(strstr($msgtxt[$i],"clan"))
            $special4=1;
          break;
        case 23:
          $special3=1;
          break;
        case 24:
          $special3=1;
          break;
        case 25:
          $special3=1;
          break;
      	case 26:
      	  $special1=1;	
      	  $special2=1;
          if(strstr($msgtxt[$i],"clan"))
            $special4=1;
          break;
	default:
	  break;
      }
      $msgn[$i]=cfix($msgn[$i]);
      $cookieValue = $_COOKIE["pIgnore"];
      if(!strstr($cookieValue,strtolower(trim($msgn[$i])))){
      	if ($thisischecked[$i] == 1) {
      		print "ct(\"$msgtxt[$i]\",\"$msgn[$i]\",$msgtype[$i]);";
      	} else {
        	print "ct(\"$msgtxt[$i] ($msgt[$i])\",\"$msgn[$i]\",$msgtype[$i]);";
      	}
      }
    }
    $query3="delete from Messages where pto = $pid limit $a1";
    mysql_query($query3);
  }
  return $a1;
}
function valmista_chat($pname,$cmax,$channels,$clan,$race,$pid){
  if($channels==10 || $channels==11 || $channels==12 || $channels==20){
    $mod_s=66;
  }else{
    $mod_s=30;
  }
  $query="Select lastchat,lastrole,lastsale,lastclan from Players where Id = $pid";
  $result=mysql_query($query);
  $row=mysql_fetch_row($result);
  $lastchat=$row[0];
  $lastrole=$row[1];
  $lastsale=$row[2];
  $lastclan=$row[3];
    $chatx=0;$gmax=10-$cmax;
    $cookieValue = $_COOKIE["pIgnore"];
    
    $query="Select msgname,msgtxt,msgtype,msgnum from chat1 where msgnum>$lastchat and msgtype !=$mod_s and (msgname !='$pname' or (msgtype>20 and msgtype<30)) order by msgnum desc limit $gmax";
    if(($result=mysql_query($query))==TRUE &&($a1=mysql_num_rows($result))>0){
      for($i=0;$i<$a1;$i++){
        $row=mysql_fetch_row($result);
        $chatnames[$chatx]=$row[0];
        $msgtxt[$chatx]=$row[1];
        if($row[2]==8 || $row[2]==19){
          $row[2]=0;
        }
        $chattype[$chatx]=$row[2];
        ++$chatx;
        if($i==0){
          $lastchat=$row[3];
        }
      }
      for($i=0;$i<$chatx;$i++){
        if(!strstr($cookieValue,strtolower(trim($chatnames[$i])))) {
      		print "c1(\"$msgtxt[$i]\",\"$chatnames[$i]\",$chattype[$i]);";
      	}
      }
    }
    $chatx=0;$a2=0;
    $query="Select msgname,msgtxt,msgtype,msgnum from chat2 where msgnum>$lastrole and msgtype !=$mod_s and (msgname !='$pname' or (msgtype>20 and msgtype<30)) order by msgnum desc limit $gmax";
    if(($result=mysql_query($query))==TRUE &&($a2=mysql_num_rows($result))>0){
      for($i=0;$i<$a2;$i++){
        $row=mysql_fetch_row($result);
        $chatnames[$chatx]=$row[0];
        $msgtxt[$chatx]=$row[1];
        if($row[2]==19){
          $row[2]=0;
        }
        $chattype[$chatx]=$row[2];
        ++$chatx;
        if($i==0){
          $lastrole=$row[3];
        }
      }
      for($i=0;$i<$chatx;$i++){
      	if(!strstr($cookieValue,strtolower(trim($chatnames[$i])))) {
        	print "c2(\"$msgtxt[$i]\",\"$chatnames[$i]\",$chattype[$i]);";
        }
      }
    }
    $chatx=0;$a2=0;
    $query="Select msgname,msgtxt,msgtype,msgnum from chat3 where msgnum>$lastsale and msgtype !=$mod_s and (msgname !='$pname' or (msgtype>20 and msgtype<30)) order by msgnum desc limit $gmax";
    if(($result=mysql_query($query))==TRUE &&($a2=mysql_num_rows($result))>0){
      for($i=0;$i<$a2;$i++){
        $row=mysql_fetch_row($result);
        $chatnames[$chatx]=$row[0];
        $msgtxt[$chatx]=$row[1];
        if($row[2]==8 || $row[2]==19){
          $row[2]=0;
        }
        $chattype[$chatx]=$row[2];
        ++$chatx;
        if($i==0){
          $lastsale=$row[3];
        }
      }
      for($i=0;$i<$chatx;$i++){
      	if(!strstr($cookieValue,strtolower(trim($chatnames[$i])))) {
        	print "c3(\"$msgtxt[$i]\",\"$chatnames[$i]\",$chattype[$i]);";
        }
      }
    }
    $chatx=0;$a2=0;
    if($channels==12 || $channels==20){
      $query="Select msgname,msgtxt,msgtype,msgnum from chat4 where msgnum>$lastclan and msgname !='$pname' order by msgnum desc limit $gmax";
    }else if($channels==10 || $channels==11){
      $query="Select msgname,msgtxt,msgtype,msgnum from chat4 where msgnum>$lastclan and (msgtype=$clan or msgtype<200 or msgtype=30) and msgname !='$pname' order by msgnum desc limit $gmax";
    }else{
      	$query="Select msgname,msgtxt,msgtype,msgnum from chat4 where msgnum>$lastclan and ((msgtype=$clan or msgtype=$race+40 or (msgtype<40 and msgtype!=30) or msgtype=13) and msgtype != 30) and msgname !='$pname' order by msgnum desc limit $gmax";
    }
    if(($result=mysql_query($query))==TRUE &&($a2=mysql_num_rows($result))>0){
      for($i=0;$i<$a2;$i++){
        $row=mysql_fetch_row($result);
        $chatnames[$chatx]=$row[0];
        $msgtxt[$chatx]=$row[1];
        if($row[2]>60){
          $cid=$row[2];
          $query2="Select cname from Clans where cid=$cid";
          $result2=mysql_query($query2);
          extract(mysql_fetch_array($result2));
          $chattype[$chatx]=$cname;
        }else{
          $chattype[$chatx]=$row[2];
        }
        ++$chatx;
        if($i==0){
          $lastclan=$row[3];
        }
      }
      $cookieValue = $_COOKIE["noRaceChat"];
      for($i=0;$i<$chatx;$i++){
        if((!strstr($cookieValue,'true'))||(((int)$chattype[$i])>140)||(((int)$chattype[$i])<39)){
        	if(!strstr($cookieValue,strtolower(trim($chatnames[$i])))) {
          	print "c4(\"$msgtxt[$i]\",\"$chatnames[$i]\",\"$chattype[$i]\");";
        	}
        }
      }
    }
    $query="Update Players set lastchat=$lastchat,lastrole=$lastrole,lastsale=$lastsale,lastclan=$lastclan where Id = $pid";
    mysql_query($query);
  return 1;
}
function cfix($jono){
  $newjono="";
  $jono=str_replace("\\","",$jono);
  $jono=str_replace("'","\'",$jono);
  $jono=str_replace("\"","\'",$jono);
  for($i=0;$i<strlen($jono);$i++){
  $xc=ord($jono[$i]);
    if($xc>32 && $xc<127){
      $newjono.=$jono[$i];
    }else {
      $newjono.=" ";
    }
  }
  return $newjono;
}
function make_seed(){
  list($usec,$sec)=explode(' ',microtime());
  return(float) $sec +((float) $usec * 100000);
}
?>