<?php
                 $query="Select quests,qhd from Players where Id = $Id";
                 if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
                   extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
                   if ($tgt_qhd == 0) {
                   	$qinfo = "now!";
                   } else {
                   	$qinfo = "for another in $tgt_qhd hours.";
                   }
                   $chatresult="You have completed $tgt_quests quest(s), you can sign up $qinfo";
                 }else {
                  $chatresult="Invalid data.";
                 } 
?>