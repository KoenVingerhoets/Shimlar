<?php
   $query="select (UNIX_TIMESTAMP( ) - UNIX_TIMESTAMP( pk_time )) as pkd from Stats where Id = $Id";
   $result=mysql_query($query);
   extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"this");
   if ($this_pkd < 600) {
    $resttime = 600 - $this_pkd;
    $chatresult="You'll have to wait $resttime seconds before you can strike again.";
   } else {
    $chatresult="$pname is here!! And ready to kill!";
   }
?>