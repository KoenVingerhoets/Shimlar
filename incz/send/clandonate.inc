<?php
	$cdonate=strstr($cinput," ");
  $cdonate=trim($cdonate);
  
  $clandonatestring = "From $Id - $pname to Clan $clan : $cdonate";
           
  $cdonate=str_replace("-","",$cdonate);
  $cdonate=str_replace("+","",$cdonate);
  $cdonate=str_replace(".","",$cdonate);
  $cdonate=str_replace(",","",$cdonate);
            
  if (preg_match ("/^([0-9]+)$/", $cdonate)) {
 		if ($banked >= $cdonate) {
  		if ($clan > 60) {
  			mysql_query("update Kingdoms set kd_gold = kd_gold + $cdonate where kd_clan = $clan");
  			if (mysql_affected_rows()>0) {
  				$query="update Stats set banked=banked-$cdonate where Id = $Id";
  				mysql_query($query);
  				$chatresult="You added $cdonate gold to the vaults in your kingdom.  Relog to see your current bankamount.";
  				inschat("chat4",$pname,"I donated $cdonate to the vaults in our kingdom.",$clan);
  				$clandonatestring=$clandonatestring + " -- given: $cdonate";
  			} else {
  			$chatresult="Your clan has no kingdom.";
  			}
  		} else {
  			$chatresult="You are not in a clan.";
  		}
 		} else {
 			$chatresult="Aye matey... you do not have that amount of cash in yer bank!";
 		}
	} else {
    $chatresult="This is invalid input.";
	}
	kingdomGifts($clandonatestring);
?>