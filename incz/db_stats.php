<?php
include 'constvars.inc'; 
init_dbx();

# update the db_stats table with latest stats

# update the total players count
$query="SELECT COUNT(Id) as ptotal from Players";
$result=mysql_query($query); 
extract(mysql_fetch_array($result));
$query="Update db_stats set stat_value=$ptotal, date_modified=now() where stat_name='Total'";
mysql_query($query);

# update the inactive players count
$query="SELECT COUNT(*) as inactive FROM Players P INNER JOIN Stats S ON P.Id = S.Id WHERE ((P.banned=100) OR (S.lvl<100)) AND ((TO_DAYS(NOW()) - TO_DAYS(P.ax_time)) >= 30) AND (S.gold+S.banked)<10000000 AND P.channels NOT IN (12,20)";
$result=mysql_query($query); 
extract(mysql_fetch_array($result));
$query="Update db_stats set stat_value=$inactive, date_modified=now() where stat_name='Inactive'";
mysql_query($query);

# update the muted players count
$query="SELECT COUNT(Id) as muted from Players where channels=66";
$result=mysql_query($query); 
extract(mysql_fetch_array($result));
$query="Update db_stats set stat_value=$muted, date_modified=now() where stat_name='Muted'";
mysql_query($query);

# update the banned players count
$query="SELECT COUNT(Id) as ban_count from Players where banned=100";
$result=mysql_query($query); 
extract(mysql_fetch_array($result));
$query="Update db_stats set stat_value=$ban_count, date_modified=now() where stat_name='Banned'";
mysql_query($query);

close_dbx();
  
?>