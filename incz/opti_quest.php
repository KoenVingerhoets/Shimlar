<?php



include 'constvars.inc'; 



init_dbx();



$query="Optimize table Market,Quests,Ipban,chat3"; 

mysql_query($query);



close_dbx();

  

?>