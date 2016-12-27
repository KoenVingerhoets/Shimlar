<?php
            if($channels==10 || $channels==11 || $channels==12 || $channels==20){
              $spammer=strstr($cinput," ");
              $spammer=ucwords(trim($spammer));
              $query="Select Id,channels,banned from Players where name='$spammer'";
              if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
                extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
                if((($tgt_channels<10||$tgt_channels==19)&&(strtolower($spammer)!="chronometer"))||(($tgt_channels<12)&&($channels>11))){
                  if($tgt_banned !=100){
                    $tgt_banned+=10;
                    if ($tgt_banned==100){
                      $query="Insert into Modactions values('MODBAN','$spammer','mod action ban',now())";
                      mysql_query($query);
                      }
                    }
                  $query="Update Players set loc_zone=18,loc_x=1,loc_y=1,channels=66,banned='$tgt_banned',mhd=0,qhd=72,jhd='$mhd' where Id = $tgt_Id";
                  mysql_query($query);
                  $query="Insert into Modactions values('$pname','$spammer','permamute',now())";
                  mysql_query($query);
                  $query="Insert into Messages values($tgt_Id,'$pname','has muted you for ever.',26,now())";
                  mysql_query($query);
                  inschat("chat1",$pname,"I perma muted $spammer",30);
                  inschat("chat3",$pname,"I perma muted $spammer",30);
                  $chatresult="Player $spammer permanently muted.";
                }else if($tgt_channels==66) {
                  $chatresult="Player already Muted!";
                }else if(($tgt_channels==10)||($tgt_channels==12)||($tgt_channels==20)) {
                  $query="Update Players set banned=100 where Id = $tgt_Id";
                  mysql_query($query);
                  $query="Update Players set channels=0 where name='$pname'";
                  mysql_query($query);
                  $query="Insert into Modactions values('$pname','$spammer','moderator ban',now())";
                  mysql_query($query);
                  inschat("chat1",$pname,"I banned the moderator $spammer",30);
                  inschat("chat3",$pname,"I banned the moderator $spammer",30);
                  $chatresult="Player $spammer has been banned and you have been demodded.";
                }else {
                  $chatresult="Cannot Mute other Moderators";
                }
              }else {
                $chatresult="Player $spammer does not exist";
              }
            }else {
              $chatresult="You do not have this power!";
            }
?>
