<?php
		 		$query="Select P.name,(UNIX_TIMESTAMP( ) - UNIX_TIMESTAMP( ax_time )  ) as ax_time,S.lvl,S.align,coalesce(B2.Id,0) from Players as P,Stats as S,Buddy as B left outer join Buddy as B2 on B2.Id = B.BuddyId and B2.BuddyId = B.Id where ((B.BuddyId = P.Id) && (B.Id = $Id) && (B.Status = 1) && (P.banned!=100) && (P.Id = S.Id) && ((P.channels!=66)&&(P.mhd=0))) order by P.ax_time desc limit 200";
				$result=mysql_query($query);
  			$a1=mysql_num_rows($result);
  			if ($a1>0) {
  			$chatresult="<p align='left'>Your buddies: <br>";
  			$j=0;
  			$divider="<tr><th>Name</th><th>Mutual</th><th>Level</th><th>Align</th></tr>";
  			$chatresult.="<table align='left' style={width:10px;}>";
  			$chatresult=$chatresult.$divider;
  			for($i=0; $i<$a1; $i++) {
    				$row=mysql_fetch_row($result);
    				$tgt_name=str_replace("'","\'",$row[0]);
    				$tgt_lvl=$row[2];
    				$tgt_align=$row[3];
    				$tgt_ax_time=$row[1];
    				$tgt_mutual=$row[4];
    				if ($tgt_mutual !=0) {
    					$tgt_mutual="yes";
    				} else {
    					$tgt_mutual = "no";
    				}
    				$ff="";
    				$fa="</font>";
    				$jf="<a href=\'javascript:top.tell(&quot;$tgt_name&quot;);\'>";
    				$ja="</a>";
    				if ($tgt_ax_time < 200) { // prollie online
    					$ff="<font color=green>";
						} else { 
							if ($tgt_ax_time < 900) { // could be online
								$ff="<font color=yellow>";
							} else { // not online
								$ff="<font color=red>";
							}
						}						
   					$chatresult.="<tr><td><b>$jf $ff $tgt_name $fa $ja</b></td><td><font color=white>$tgt_mutual</font></td><td><font color=white>$tgt_lvl</font></td><td><font color=white>$tgt_align</font></td></tr>";
    				$j=$j+1;
    				if ($j==10) {
    					$j=0;
    					$chatresult=$chatresult.$divider;
    				}
  			}
  			
 			$chatresult.="</table></p>";
	} else {
		$chatresult="You have no buddies listed.";
	}
?>
