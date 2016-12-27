<?php
include 'constvars.inc'; 
init_dbx();
$query="Unlock Tables";
mysql_query($query);
$query="Lock Tables Players WRITE, Stats WRITE, Clans WRITE, Inventory WRITE, Buddy WRITE";
mysql_query($query);
$query="Select Stats.clan, Stats.lvl,Players.banned,Players.Id from Players,Stats where Players.Id=Stats.Id and Stats.clan>50 order by Stats.clan"; 
$result=mysql_query($query);
$oldClan = 0;
$clanPoints = 0;

while ($row=mysql_fetch_row($result)) {
    $clan=$row[0];
    $lvl=$row[1];
    $ban=$row[2];
    $id=$row[3];
    if ($clan == $oldClan) {
    	if ($ban!=100) {
      	$clanPoints += clanp($lvl);
      } else {
      	$query="update Stats set clan = 0 where Id = $id";
      	mysql_query($query);
      }
    } else {
      if ($oldClan != 0) {     
        $query="Update Clans set cpower=$clanPoints where cid=$oldClan";
        mysql_query($query);
      }
      $oldClan = $clan;
      $clanPoints = clanp($lvl);
    }  
  }
if ($oldClan != 0) {     
  $query="Update Clans set cpower=$clanPoints where cid=$oldClan";
  mysql_query($query);
}

// clean the not regged chars
$query="select Id from Players where (pstatus = 0) and (lastaction = 'cr') and ((to_days(now()) - to_days(act_time)) > 5)";
$result = mysql_query($query);
while ($row=mysql_fetch_row($result)) {
    $pid=$row[0];
    $query="delete from Inventory where Id = $pid";
    mysql_query($query);
    $query="delete from Stats where Id = $pid";
    mysql_query($query);
    $query="delete from Players where Id = $pid";
    mysql_query($query);
}

// clean the not regged buddies
$query="delete from Buddy where (status = 0) and ((to_days(now()) - to_days(TS)) > 5)";
mysql_query($query);

$query="Unlock Tables";
mysql_query($query);

close_dbx();
?>

