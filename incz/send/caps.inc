<?php
            if($channels==10 || $channels==11 || $channels==12 || $channels==20){
              $spammer=strstr($cinput," ");
              $spammer=ucwords(trim($spammer));
              $query="Select Id,channels from Players where name='$spammer'";
              if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
                extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
                if($tgt_channels<10 || $tgt_channels==19){
                  $query="Update Players set channels=19 where Id = $tgt_Id";
                  mysql_query($query);
                  $query="Insert into Modactions values('$pname','$spammer','lc-cursed',now())";
                  mysql_query($query);
                  $chatresult="$spammer has been Lowercase-cursed!";
                  $query="Insert into Messages values('$spammer','$pname','lowercase-cursed you for one hour.',26,now())";
                  mysql_query($query);
                }else if($tgt_channels==66) {
                  $chatresult="Player already Muted!";
                }else {
                  $chatresult="Cannot Lc-curse other Moderators";
                }
              }else {
                $chatresult="Player $spammer does not exist";
              }
            }else {
              $chatresult="You do not have this power!";
            }
?>