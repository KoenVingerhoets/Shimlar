<?php



include '../incz/constvars.inc'; 

init_dbx();

  $query="Select name,lvl,exp from Players where channels != 12 and channels != 20 and banned!=100 order by lvl desc,exp desc limit 1000";

  $result=mysql_query($query);

  $a1=mysql_num_rows($result);

  for($i=0; $i<$a1; $i++) {

    $row=mysql_fetch_row($result);

    $pname[$i]=$row[0];

    $plvl[$i]=$row[1];

    $pexp[$i]=$row[2];

  }

  for($i=0; $i<$a1; $i++) {

    print "\n$pname[$i],$plvl[$i],$pexp[$i]";

  }

close_dbx();



?>