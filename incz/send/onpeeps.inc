<?php
	if($channels==20||$channels==12||$channels==10){
		$tgt=strstr($cinput," ");
            	$tgt=ucwords(trim($tgt));
            	$ts=date("M j G:i:s");
            	$skip = false;
            	switch($tgt) {
            		case "Gold":
            			$orderby = "S.gold";
            			break;
            		case "Exp":
            			$orderby = "S.exp";
            			break;
            		case "Name":
            			$orderby = "P.name";
            			break;
            		case "Lvl":
            			$orderby = "S.lvl";
            			break;
            		case "Action":
            		        $orderby = "P.ax_time";
            		        break;
            		case "Help":
            			$skip=true;
            			break;
            		case "Ip":
            			$orderby = "P.last_ip";
            			break;
            		default:
            			$orderby = "P.ax_time";
            	}
            	if (!($skip)) {			
			$query = "update Stats set pk_time=now() where Id = $Id";
                        mysql_query($query);
                        $query="Select P.name,S.lvl,S.exp,S.gold,P.last_ip from Players as P,Stats as S where (((now()-P.Ax_time)<200) && (P.channels not in (12,20)) && (P.banned!=100) && (P.Id = S.Id) && ((P.channels!=66)&&(P.mhd=0))) order by $orderby desc limit 200";
			$result=mysql_query($query);
  			$a1=mysql_num_rows($result);
  			$chatresult="<p align='left'>The $a1 people online (excluded permamuted) on $ts sorted on $tgt are: <br>";
  			$j=0;
  			$divider="<tr><th>Nr.</th><th>Name</th><th>Level</th><th>Exp.</th><th>Gold</th><th>IP</th></tr>";
  			$chatresult.="<table align='left' style={width:10px;}>";
  			$chatresult=$chatresult.$divider;
  			for($i=0; $i<$a1; $i++) {
    				$row=mysql_fetch_row($result);
    				$tgt_name[$i]=str_replace("'","\'",$row[0]);
    				$tgt_lvl[$i]=$row[1];
    				$tgt_exp[$i]=$row[2];
    				$tgt_gold[$i]=$row[3];
    				$tgt_ip[$i]=$row[4];
    				if ($channels!=10) {
    					$chatresult.="<tr><td># $i</td><td><font color=white>$tgt_name[$i]</font></td><td><font color=white>$tgt_lvl[$i]</font></td><td><font color=white>$tgt_exp[$i]</font></td><td><font color=white>$tgt_gold[$i]</font></td><td><font color=white>$tgt_ip[$i]</font></td></tr>";
    				} else {
				//	$expl_ip = explode(".",$tgt_ip[$i]);
    					$chatresult.="<tr><td># $i</td><td><font color=white>$tgt_name[$i]</font></td><td><font color=white>$tgt_lvl[$i]</font></td><td><font color=white>$tgt_exp[$i]</font></td><td colspan=2><font color=white>$tgt_gold[$i]</font></td><td><!-- . --></td></tr>"; // <font color=white>$expl_ip[2].$expl_ip[3]</font>
    				}
    				$j=$j+1;
    				if ($j==10) {
    					$j=0;
    					$chatresult=$chatresult.$divider;
    				}
  			}
  			
 			$chatresult.="</table></p>";
 		} else {
 			$chatresult="/onpeeps will show the online people, add lvl, exp, gold, name, action to sort on that. Ex.: /onpeeps gold";
 		}
	} else {
		$chatresult="Never do that again!";
	}
?>
