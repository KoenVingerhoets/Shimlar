<?php
$a1=0;
function sproc($l,$p,$k,$target){
global $REMOTEADDR,$a1;
$REMOTEADDR = $_SERVER['REMOTE_ADDR'];
if($REMOTEADDR==""){
 $REMOTEADDR=$l;
}
$pword=$p;
$luku1=(int)$k+1;
$cinput=substr($target,0,min(strlen($target),200));
if(is_numeric($l)){
if(tarkista($pword) && tarkista($k)){
  $query="Select Id,ign,password,channels,banned,wrong_pw,name as pname,surname from Players where Id=$l";
  if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
    extract(mysql_fetch_array($result));
    $query="Select clan,lvl,race,align,stopRP,stopSales,banked from Stats where Id = $Id";
    $result=mysql_query($query);
    extract(mysql_fetch_array($result));
    $race=($race%100)+40;
    if(mysql_num_rows($result)==1 && $pword==$password && $banned !=100){
      $chatresult="x";$x=0;
      if($lvl>24){
      	if (($stopRP!=0 && $luku1==2) || ($stopSales!=0 && $luku1==3)) {
    	  $chatresult("You can only read in this channel.");
        } else {
          $cinput=cfix($cinput);
          $cinput=trim($cinput);
          $cinput=filterSymbols($cinput);
          $a1=sp_check($cinput);
          if($a1==1 && $channels !=66){
            if($cinput[0]!='/'){
              require_once "send/nocmd.inc";  //plain chat line, no commands
            }else{
              require_once "send/cmds2.inc";  //all chat /commands
            }
          }else {
            if($a1==2)
              $chatresult="Can't Send Empty Message";
            if($a1==3)
              $chatresult="Are you trying to spam?";
            if($a1==4)
              $chatresult="Swearing is not allowed";
            if($channels==66)
              $chatresult="You are muted.";
          }
        }
      }else if($lvl<25){
        $chatresult="You need to be level 25 to chat. Read the <a href='http://www.shimlar.org/manual.htm' target='_blank'>Manual</a> and <a href='http://www.shimlar.org/faq.htm' target='_blank'>FAQ</a> if you need help.";
      }
      print "xA(\"$chatresult\");";
      $ip=$REMOTEADDR;
      $query="Update Players set lastaction='h',ax_time=now(),wrong_pw=0,last_ip='$ip' where Id = $Id";
      mysql_query($query);
    }else if($p !=$password){
      ++$wrong_pw;
      if($wrong_pw>9){
        if($REMOTEADDR !=''){
          $query="Insert into Ipban values('$REMOTEADDR',now(),'$pname')";
          mysql_query($query);
          $query="Update Players set wrong_pw=0,banned=100 where name = '$pname'";
          mysql_query($query);
          $query="Insert into Modactions values('Password', '$pname', '$wrong_pw', now())";
          mysql_query($query);
        }else {
          print "alert(\"Stop guessing passwords, your IP will be banned.\");\n";
        }
      } else {
      	$query="Update Players set wrong_pw=$wrong_pw where Id = $Id";
        mysql_query($query);
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
function cfix($jono){
  $jono=str_replace("&","n",$jono);
  $jono=str_replace("\\","",$jono);
  $jono=str_replace("'","\'",$jono);
  $jono=str_replace("\"","\'",$jono);
  $jono=str_replace("<","(",$jono);
  $jono=str_replace(">",")",$jono);
  $jono=str_replace("[","(",$jono);
  $jono=str_replace("]",")",$jono);
  $jono=str_replace("ö","&ouml;",$jono);
  $jono=str_replace("ä","&auml;",$jono);
  $jono=str_replace("é","&eacute;",$jono);
  $jono=str_replace("è","&egrave;",$jono);
  $jono=str_replace("ê","&ecirc;",$jono);
  $jono=str_replace("ü","&uuml;",$jono);
  $jono=str_replace("å","&aring;",$jono);
  $jono=str_replace("�","&agrave;",$jono);
  $jono=str_replace("shimlarscript","",$jono);
  return $jono;
}

function sp_check($jono) {
  $a1=1;
  if(strlen($jono)<1)
    $a1=2;
  else if(strstr(strtolower($jono),"vittu") ||
     strstr(strtolower($jono),"fuck")  ||
     strstr(strtolower($jono),"shit")  ||
     strstr(strtolower($jono),"v*ttu") ||
     strstr(strtolower($jono),"f*ck")  ||
     strstr(strtolower($jono),"fu*k")  ||
     strstr(strtolower($jono),"sh*t")  ||
     strstr(strtolower($jono),"uttiv") ||
     strstr(strtolower($jono),"kcuf")  ||
     strstr(strtolower($jono),"tihs")  ||
     strstr(strtolower($jono),"utt*v") ||
     strstr(strtolower($jono),"kc*f")  ||
     strstr(strtolower($jono),"utt*v") ||
     strstr(strtolower($jono),"nigger") ||
     strstr(strtolower($jono),"nigga") ||
     strstr(strtolower($jono),"cunt") ||
     strstr(strtolower($jono),"t*hs")  )
    $a1=4;
  else if(strlen($jono)>50) {
    if(strstr($jono," ")==FALSE) {
    $a1=3;
    } else if(strlen($jono)>100) {
      $jono1=substr($jono,50);
      if(strstr($jono1," ")==FALSE) {
        $a1=3;
      } else if(strlen($jono)>150) {
        $jono2=substr($jono,100);
        if(strstr($jono2," ")==FALSE) {
          $a1=3;
        }
      }
    }
  }
  
  return $a1;
}

function filterSymbols ($jono) {
$newjono="";
for($i=0;$i<strlen($jono);$i++) {
  $xc=ord($jono[$i]);
    if(($xc>32 && $xc<127) || $jono[$i]==" "){
      $newjono.=$jono[$i];
    }
  }
  return $newjono;
}

 function tsub($jono,$tx){
    $newjono=substr($jono,1,min(strlen($jono),$tx));
    return strtolower($newjono);
  }
  function zsub($jono){
    $jx=strpos($jono," ");
    if($jx == 0){
      $newjono=substr($jono,1,strlen($jono));
      return strtolower($newjono);
    }else{
      $newjono=substr($jono,1,$jx);
      return strtolower($newjono);
    }
  }
?>