<?php
include '../incz/constvars.inc';
init_dbx();

$userid=$_GET["u"];
$nr=$_GET["nr"];

if ((strlen($userid)>0) && (strlen($nr)>9)){
	$query = "select name,UNIX_TIMESTAMP(ax_time) as ax_time,banned,login from Players where lastaction='cr' and Id = $userid and pstatus = 0";
	if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
     		extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"this");
     		if ($this_banned != 100) {
     			if ($this_ax_time==$nr) {
     				$query="update Players set lastaction='va',ax_time=now(),pstatus=1 where Id = $userid";
     				mysql_query($query);
     				$output="Your character $this_name was validated.  You can now log in with $this_login and the password you have chosen.<br>Click <a href='http://www.shimlar.org' target='_self'>here</a> to go to the game.";
     			} else {
     				$query="update Players set banned=100 where Id = $userid";
     				mysql_query($query);
     				$output="Your character $this_name was banned for trying fake validation.";
     			}
     		} else {
     			$output="Your character is already banned.";
     		}	 
     	} else {
     		$output="Your character could not be validated.";
	}
} else {
	$output="The input provided was incorrect.";
}

close_dbx();

print "<html><head><title>Character validation</title></head>";
print "<body><center>$output</center></body></html>";

?>