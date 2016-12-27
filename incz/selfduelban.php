<?php
include 'constvars.inc'; 
init_dbx();
$query	="select p.Id,p.name,s.opponent from Players p, Stats s where ((p.Id=s.Id) and (p.Id=s.opponent) and (p.banned!=100))";
$result	=mysql_query($query);
$c1	=mysql_num_rows($result);
for($i=0;$i<$c1;$i++) {
	$row	=mysql_fetch_row($result);
	$name	=$row[1];
	$id	=$row[0];
	$query	="update Players set banned=100, channels=0 where Id = $id";
	mysql_query($query);
	$query	="insert into Modactions values('Lord Morpheus', '$name', 'Self-Duel hack auto-ban', now())";
	mysql_query($query);
    $query  ="insert into chat1 values('','$name',' has been banned for bug exploitation','32')";
    mysql_query($query);
    $query  ="insert into chat2 values('','$name',' has been banned for bug exploitation','32')";
    mysql_query($query);
    $query  ="insert into chat3 values('','$name',' has been banned for bug exploitation','32')";
    mysql_query($query);
};
close_dbx();
?>