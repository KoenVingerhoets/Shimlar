<?php
            if($channels==10 || $channels==20 || $channels==12){
              $spammer=strstr($cinput," ");
              $spammer=ucwords(trim($spammer));
              $query="Select Id,channels,banned from Players where name='$spammer'";
              if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
                extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
                $query="Select lvl from Stats where Id = $tgt_Id";
                $result=mysql_query($query);
                extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
                if($tgt_channels !=20 && $tgt_channels !=12 && (($tgt_channels != 10) || ($channels==20))){
                  $query="update Stats set health=0, exp=0 where Id = $tgt_Id";
                  mysql_query($query);
                  $query="update Inventory set checked = 1 where Id = $tgt_Id";
                  mysql_query($query);
                  $query="Insert into Modactions values('$pname','$spammer','KILL',now())";
                  mysql_query($query);
                  $chatresult="You killed $spammer. Please id and /pm the player, there is no automated pm anymore after a /kill.";	
                  inschat("chat1",$pname,"I killed Player $spammer",30);
                  inschat("chat3",$pname,"I killed Player $spammer",30);
                  print "c1(\"I killed Player $spammer\",\"$pname\",30);";
                  print "c3(\"I killed Player $spammer\",\"$pname\",30);";

                }else {
                  $chatresult="You cannot use this command on Mods or ArchWizards! Shame on you!";
                }
              }else {
                $chatresult="Player $spammer does not exist";
              }
            }else {
              $chatresult="You do not have this power!";
            }
?>
