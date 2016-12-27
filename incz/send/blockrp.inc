<?php
            if($channels==10 || $channels==11 || $channels==12 || $channels==20){
              $spammer=strstr($cinput," ");
              $spammer=ucwords(trim($spammer));
              $query="Select Id from Players where name='$spammer'";
              if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
                extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
                $query="Update Stats set stopRP = 2 where Id = $tgt_Id";
                mysql_query($query);
                $query="Insert into Modactions values('$pname','$spammer','rp block',now())";
                mysql_query($query);
                $chatresult="$spammer has been stopped from talking in RP!";
              }else {
                $chatresult="Player $spammer does not exist";
              }
            }else {
              $chatresult="You do not have this power!";
            }
?>