<?php
   $query="select PKill from Stats where Id = $Id";
   $result=mysql_query($query);
   extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"this");
   if ($this_PKill == 0) {
    $chatresult="You did not kill anyone yet.";
   } else {
    $chatresult="You have killed $this_PKill player(s).";
   }
?>