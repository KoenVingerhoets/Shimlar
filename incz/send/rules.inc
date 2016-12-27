<?php
              if(($channels > 9) && ($channels < 21)){
                 $spammer=strstr($cinput," ");
                 $spammer=ucwords(trim($spammer));
                 $query="Select Id, name from Players where name='$spammer'";
                 if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
                   extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
                   $query="Insert into Messages values($tgt_Id,'Rules','Please <a href=\'http://www.shimlar.org/rules.htm\' target=\'_blank\'>click here to see the rules</a>',6,now())";
                   mysql_query($query);
                   $chatresult="Link to rules sent to $tgt_name";
                 }else {
                  $chatresult="Player $spammer does not exist";
                 }
               }else {
                 $chatresult="You do not have this power!";
               }
?>