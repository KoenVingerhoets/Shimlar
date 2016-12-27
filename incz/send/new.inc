<?php
              if($channels > 9){
                 $spammer=strstr($cinput," ");
                 $spammer=ucwords(trim($spammer));
                 $query="Select Id, name from Players where name='$spammer'";
                 if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
                   extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
                   $query="Insert into Messages values($tgt_Id,'Help','Please <a href=\'http://www.gilians.de/shimlarguide\' target=\'_blank\'>click here for GodOfWar site</a> and <a href=\'http://www.shimlar.org/manual.htm\' target=\'_blank\'>here for Shimlar Manual</a>',6,now())";
                   mysql_query($query);
                   $chatresult="Links sent to $tgt_name";
                 }else {
                  $chatresult="Player $spammer does not exist";
                 }
               }else {
                 $chatresult="You do not have this power!";
               }
?>