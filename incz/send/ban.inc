<?php
            if(($channels==20) ||($channels==12)){
              $spammer=strstr($cinput," ");
              $spammer=ucwords(trim($spammer));
              $query="Select Id,name,channels,last_ip from Players where name='$spammer'";
              if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
                extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
                  if (!(($tgt_channels == 10)||($tgt_channels == 12)||($tgt_channels == 20))){
                    $query="update Players set banned=100 where Id = $tgt_Id";
                    mysql_query($query);
                    if($tgt_last_ip !=''){
                      $query="Insert into Ipban values('$tgt_last_ip',now(),'$tgt_name')";
                      mysql_query($query);
                      $query="Insert into Modactions values('$pname','$spammer','ip banned',now())";
                      mysql_query($query);
                      $chatresult="$spammer has been IP banned!";
                      $query="Insert into Messages values($tgt_Id,'$pname','IP banned you',26,now())";
                      mysql_query($query);
                      if (tsub($cinput,4)=="ban ") {
                      	inschat("chat1",$spammer,"has been wiped off the face of the earth!",32);
                    	inschat("chat2",$spammer,"has been wiped off the face of the earth!",32);
                    	inschat("chat3",$spammer,"has been wiped off the face of the earth!",32);
                      } else {
                   	inschat("chat1","Shimlar","banned a player!",32);
                    	inschat("chat2","Shimlar","banned a player!",32);
                    	inschat("chat3","Shimlar","banned a player!",32);
                      }
                    }else {
                    	$chatresult="Player $spammer has no valid IP.";
                    }
                  }else {
                    $chatresult="Command not applicable on Mods and Arches, use /perma instead.";
                  }
                }else {
                  $chatresult="Player $spammer does not exist";
                }
            }else {
            	$chatresult="You do not have this power!";
            }
?>
