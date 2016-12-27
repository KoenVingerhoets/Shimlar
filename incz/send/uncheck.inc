<?php
            if($channels==10 || $channels==20 || $channels==12){
              $spammer=strstr($cinput," ");
              $spammer=ucwords(trim($spammer));
              $query="Select banned from Players where name='$spammer'";
              if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
                $query="update Inventory set checked=0 where pname='$spammer'";
                mysql_query($query);
		$chatresult="$spammer is able to trade.";	
              }else {
                $chatresult="Player $spammer does not exist";
              }
            }else {
              $chatresult="You do not have this power!";
            }
?>
