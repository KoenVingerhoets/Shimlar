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
		$query="Select name, email, last_ip as nimi from Players where Id=$pid and password='$pass'";
    if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
			$row=mysql_fetch_row($result);
			$query="insert into Modactions values('Lord A', '$row[0]', 'SCRIPT', now())";
			mysql_query($query);
			$query="update Players set banned = 100 where email='".$row[1]."' or last_ip = '".$row[2]."'";
			mysql_query($query);
			$query="Insert into Ipban values('".$row[2]."',now(),'".$row[0]."')";
			mysql_query($query);
    }
  }
	close_dbx();
	
} 
print "<br /><b>Warning</b>:  Cannot modify header information - headers already sent by (output started at /home/shimlar/critical.inc:10) in <b>/var/www/shimlar.org/httpdocs/game.php</b> on line <b>30</b><br />";

?>