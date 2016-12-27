<?php
include 'constvars.inc'; 
init_dbx();

$query="Optimize Table Messages,chat1,chat2,Transfers"; 
mysql_query($query);

close_dbx();
  
?>