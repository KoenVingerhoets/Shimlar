<?php
function chat_mute($channels, $pname, $cinput){
  if($channels==10 || $channels==11 || $channels==12 || $channels==20){
    $spammer=strstr($cinput," ");
    $mhd=strstr($spammer,":");
    $mhd=substr($mhd,2);
    $spammer=substr($spammer,0,(strlen($spammer)-strlen($mhd)-2));
    $spammer=ucwords(trim($spammer));
    $mhd=min($mhd,24);$mhd=max($mhd,0);
    if (($mhd==0) || ($mhd=="")) {
      $mhd=48; $qhd=72;
    } else {
      $qhd=$mhd*3;
    }
    $query="Select Id,channels,banned from Players where name='$spammer'";
    if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
      extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
      if(($tgt_channels<20)&&($tgt_channels!=12)&&($tgt_channels!=10)){ // $channels == 19 must be mutable!
        if($tgt_banned !=100){
          $tgt_banned+=10;
          if ($tgt_banned==100){
            $query="Insert into Modactions values('MODBAN','$spammer','mod action ban',now())";
            mysql_query($query);
            }
          }
        $query="Update Players set loc_zone=18,loc_x=1,loc_y=1,channels=66,banned='$tgt_banned',mhd='$mhd',qhd='$qhd',jhd='$mhd' where Id = $tgt_Id";
        mysql_query($query);
        $query="Insert into Modactions values('$pname','$spammer','muted/jailed $mhd',now())";
        mysql_query($query);
        if ($mhd==1) {
          $mhdd = "shuts up for 1 hour.";
        } else {
          $mhdd = "becomes quiet for $mhd hours.";
        }
        inschat("chat$luku1",$spammer,"$mhdd",27);
        $query="Insert into Messages values($tgt_Id,'$pname','muted you for $mhd hours.',26,now())";
        mysql_query($query);
        $chatresult="Player $spammer muted for $mhd h.";
        $chatmsg = "I muted player $spammer for $mhd h.";
        inschat("chat1",$pname,$chatmsg,30);
        inschat("chat3",$pname,$chatmsg,30);
        print "c1(\"$chatmsg\",\"$pname\",30);";
        print "c3(\"$chatmsg\",\"$pname\",30);";

      }else if($tgt_channels==66) {
        $chatresult="Player already Muted!";
      }else {
        $chatresult="Cannot Mute other Moderators, use /perma instead.";
      }
    }else {
      $chatresult="Player $spammer does not exist";
    }
  }else {
    $chatresult="You do not have this power!";
  }
  return $chatresult;
}
$chatresult=chat_mute($channels, $pname, $cinput);
?>
