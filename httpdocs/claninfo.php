<?php

$id = $_GET["id"];
if (is_numeric($id)) {
	if ($id > 1) {

		include '../incz/constvars.inc'; 

		init_dbx();

  		$query="Select P.name,S.lvl,S.exp from Players P, Stats S where P.channels != 12 and P.channels != 20 and P.banned!=100 and S.Clan = $id and S.Id = P.Id order by P.name ";

  		$result=mysql_query($query);

  		$a1=mysql_num_rows($result);

  		for($i=0; $i<$a1; $i++) {

    			$row=mysql_fetch_row($result);

    			$pname[$i]=$row[0];

    			$plvl[$i]=$row[1];

    			$pexp[$i]=$row[2];

  		}
  		print "<html><head><title>Shimlar clan info</title></head><body>";
  		print "<table border='0' width='80%' align='center'>";

  		for($i=0; $i<$a1; $i++) {
     			print "<tr><td>$pname[$i]</td><td>$plvl[$i]</td><td>$pexp[$i]</td></tr>";
  		}
  		
  		if ($a1 == 0) {
  			print "<tr><td>Nothing for $id.</td></tr>";
  		}
  
  		print "</table>";
  		print "</body></html>";

		close_dbx();
	} else {
		print "What a tiny number.";
	}
} else {
	print "That's not a number.";
}
?>
