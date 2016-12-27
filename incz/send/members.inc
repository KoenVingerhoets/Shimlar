<?php
	if($clan>60){
		 		$query="Select P.name,S.lvl,S.align from Players as P,Stats as S where ((S.clan = $clan) && ((now()-P.Ax_time)<200) && (P.banned!=100) && (P.Id = S.Id) && ((P.channels!=66)&&(P.mhd=0))) order by S.lvl desc limit 200";
				$result=mysql_query($query);
  			$a1=mysql_num_rows($result);
  			$chatresult="<p align='left'>The online clanmembers are: <br>";
  			$j=0;
  			$divider="<tr><th>Nr.</th><th>Name</th><th>Level</th><th>Align</th></tr>";
  			$chatresult.="<table align='left' style={width:10px;}>";
  			$chatresult=$chatresult.$divider;
  			for($i=0; $i<$a1; $i++) {
    				$row=mysql_fetch_row($result);
    				$tgt_name=str_replace("'","\'",$row[0]);
    				$tgt_lvl=$row[1];
    				$tgt_align=$row[2];
   					$chatresult.="<tr><td># $i</td><td><font color=white>$tgt_name</font></td><td><font color=white>$tgt_lvl</font></td><td><font color=white>$tgt_align</font></td></tr>";
    				$j=$j+1;
    				if ($j==10) {
    					$j=0;
    					$chatresult=$chatresult.$divider;
    				}
  			}
  			
 			$chatresult.="</table></p>";
	} else {
		$chatresult="You're not really in a clan?";
	}
?>
