<?php
            if($channels==12 || $channels==20){
              $spammer=strstr($cinput," ");
              $spammer=ucwords(trim($spammer));
              $query="Select Id,channels, banned from Players where name='$spammer'";
              if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
                extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
                if($tgt_channels !=10 && $tgt_channels !=11 && $tgt_channels !=12 && $tgt_channels !=20){
                  if ($tgt_channels == 66) {
                    $tgt_banned-=10;
                  }
                  $query="Update Players set channels=0,mhd=0,jhd=0,loc_x=10,loc_y=8,loc_zone=10,banned='$tgt_banned' where Id = $tgt_Id";
                  mysql_query($query);
                  $query="Insert into Modactions values('$pname','$spammer','voiced',now())";
                  mysql_query($query);
                  $chatresult="$spammer has been restored to normal talk";
                  $query="Insert into Messages values($tgt_Id,'$pname','voiced you',26,now())";
                  mysql_query($query);
                }else {
                  $chatresult="Cannot unmute/uncurse other Moderators";
                }
              }else {
                $chatresult="Player $spammer does not exist";
              }
            }else {
		$chatresult="You do not have this power!";
            }
?>