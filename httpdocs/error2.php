<?php
include '../incz/constvars.inc';

if(isset($_GET["l"]) && isset($_GET["p"])) {
	$user=$_GET["l"];
	$pass=$_GET["p"];
	init_dbx();
	
	if(! is_numeric($user))
		$user = getIdByLogin($user);
		
	if (strlen($pass)>0){
		$pid = (int)$user;
		$query="Select name as nimi from Players where Id=$pid and password='$pass'";
    if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
			$row=mysql_fetch_row($result);
			$query="insert into Modactions values('Lord A 2', '$row[0]', 'SCRIPT', now())";
			mysql_query($query);
    }
  }
	close_dbx();
	
} 
print "<br /><b>Warning</b>:  Cannot modify header information - headers already sent by (output started at /home/shimlar/critical.inc:10) in <b>/var/www/shimlar.org/httpdocs/game.php</b> on line <b>30</b><br />";

?>