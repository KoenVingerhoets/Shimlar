<?php
include 'constvars.inc'; 
init_dbx();

$query="Unlock Tables";
mysql_query($query);
$query="Lock Tables Players,Inventory,Stats WRITE";
mysql_query($query);
$query="Update Players set channels=0 where mhd=1";
mysql_query($query);
$query="Update Players set channels=0 where channels=8 or channels=19";
mysql_query($query);
$query="Update Players set loc_zone=0,loc_x=1,loc_y=1 where jhd=1";
mysql_query($query);
$query="Update Players set mhd=mhd-1 where mhd>0";
mysql_query($query);
$query="Update Players set jhd=jhd-1 where jhd>0";
mysql_query($query);
$query="update Inventory set checked = 0 where checked = 1";
mysql_query($query);
// since stats is open, reset the stopRP and stopSales
$query="update Stats set stopRP=stopRP-1 where stopRP > 0";
mysql_query($query);
// only for non tb's
$query="update Stats set stopSales=stopSales-1 where stopSales > 0 and tstatus = 0";
mysql_query($query);

$query="Unlock Tables";
mysql_query($query);

$query="Select count(Id) as pon from Players where (now()-ax_time)<200";
$result=mysql_query($query); 
extract(mysql_fetch_array($result));
inschat("chat1","Shimlar","has $pon players online! Please <a href=\'http://www.shimlar.org/donate/\' target=\'_blank\'>support</a> the game!",32);
inschat("chat3","Shimlar","has $pon players online!",32);

// $query="delete from Ipban where banned_ip like '211.%' or banned_ip like '172.%' or banned_ip like '202.%' or banned_ip like '62.%' or banned_ip like '24.%' or banned_ip like '213.%' or banned_ip like '65.%' or banned_ip like '216.%' or banned_ip like '203.%' or banned_ip like '210.%'";
// mysql_query($query);
$query="DELETE FROM Transfers WHERE to_days(now()) - to_days(twhen) > 14";
mysql_query($query);
$query="delete from Login where to_days(now()) - to_days(log_time) > 7";
mysql_query($query);
$query="delete from Messages where to_days(now()) - to_days(msgwhen) > 7";
mysql_query($query);
$query="delete from Buddy where (to_days(now()) - to_days(TS) > 7) and (Status = 0)";
mysql_query($query);
$query="delete from PKLog where (to_days(now()) - to_days(TS) = 1)";
mysql_query($query);
for($cx=1;$cx<5;$cx++){
  $query="select msgnum from chat$cx order by msgnum desc limit 1";
  $result=mysql_query($query); $row=mysql_fetch_row($result); $msgnum_max=$row[0];
  $query="delete from chat$cx where msgnum<$msgnum_max-40";
  mysql_query($query);
}

// FAME RELATED
// $query="lock tables Fame WRITE";
// mysql_query($query);
$query="delete from Fame";
mysql_query($query);
$query="insert into Fame select s.Id, s.name, (ifnull(c.cpower,0)*1000 + (s.lvl*5000) + ((s.banked + s.gold)/100000) + s.Fame + (p.quests*1000) + ABS(s.align)*1000) as sumFame, s.lvl from Stats s left outer join Clans c on s.clan = c.cid inner join Players p on p.Id = s.Id where p.banned <> 100 and s.tstatus = 1 order by sumFame desc";
mysql_query($query);
// $query="Unlock Tables";
// mysql_query($query);

close_dbx();
  
?>