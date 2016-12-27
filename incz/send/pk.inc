<?php
                 $query="Select opponent,(UNIX_TIMESTAMP( ) - UNIX_TIMESTAMP( pk_time )) as pkd from Stats where Id = $Id";
                 if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
                   extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
                   if ($tgt_opponent != 0) {
                   	if ($tgt_pkd > 600) {
                   		$chatresult="You can duel again.";
                   	} else {
                   		$tgt_pkd = 600-$tgt_pkd;
                   		$chatresult="You can duel again in $tgt_pkd seconds.";
                   	}
                   } else {
                   	$chatresult="You didn't duel yet.";
                   }
                 }else {
                  $chatresult="Invalid data.";
                 } 
?>