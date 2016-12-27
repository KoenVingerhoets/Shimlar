<?php
/*


include '../incz/constvars.inc'; 

init_dbx();

//print "10 = Mods; 11 = Rp Mods; 12 = Rp Arch; 20 = Arch.<br>";

  $query="Select name,channels from Players where channels in (10,11,12,20)";
  $result=mysql_query($query);
  $a1=mysql_num_rows($result);

  for($i=0; $i<$a1; $i++) {
    $row=mysql_fetch_row($result);
    $pname=$row[0];
    
    switch($row[1]){
        case 10:
            $channels="Mod"; break;
        case 11:
            $channels="RPMod"; break;
        case 12:
            $channels="RP Arch"; break;
        case 20:
            $channels="Arch"; break;
        default:
            break;
    }
    //$channels=$row[1];
    print "$pname - $channels.<br>";
  }
print "Done :).";
close_dbx();
*/


?>
