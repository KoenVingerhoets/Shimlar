<?php
            $accs=accn($Id);
            if($accs==41210000){
                if($channels==20||$channels==12){
                  $msg=0;
                  $order = "last_ip";
                  if(tsub($cinput,7)=="macro: "){
                    $msg=1; $order="name";
                  }
                  $query="Select name,last_ip, Id from Players where (now()-ax_time)<200 and channels not in (10,11,12,20) order by $order";
                  if(($result=mysql_query($query))==TRUE){
                    $c2=mysql_num_rows($result);
                    $chatresult="The following $c2 people are online: <br><table border=0 align='left'>";
                    if($msg==1){
                      $cinput=strstr($cinput,":");
                      $cinput=trim(substr($cinput,2));
                      $tellt=date("M j G:i:s");
                      $msgtp=date("s");
                      if($msgtp<20){
		        	$msgtp=5;
	                }else{
                        if($msgtp<40){
                          $msgtp=15;
                        }else{
                          $msgtp=16;
                        }
                      }
                      $chatresult="The following $c2 people are online on $tellt.<br>They saw '$cinput'.<br><table align='left' style={width:10px;}>";
                    }
                    for($c1=0;$c1<$c2;$c1++){
                      $row=mysql_fetch_row($result); 
                      $tgt_name[$c1]=$row[0];
                      $tgt_lip[$c1]=$row[1];
                      $tgt_lid[$c1]=$row[2];
                      $chatresult.="<tr><td>$tgt_lip[$c1]</td><td align='right'>$tgt_name[$c1]</td></tr>";
                      if($msg==1){
                        $query="Insert into Messages values($tgt_lid[$c1],'$pname','$cinput - $tellt',$msgtp,now())";
                        mysql_query($query);
                      }
                    }
                    $chatresult.="</table>";
                  }else {
                    $chatresult.="No data";
                  }
                } else {
                  $query="Select name from Players where (now()-ax_time)<200 and channels !=20 limit 201";
                  if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)<201){
                    $c2=mysql_num_rows($result);
                    $chatresult="The following people are online: ";
                    for($c1=0;$c1<$c2;$c1++){
                      $row=mysql_fetch_row($result); 
                      $tgt_name=$row[0];
                      $chatresult.="$tgt_name";
                      if($c1<($c2-1)){
                        $chatresult.=", ";
                      }
                    }
                  } else {
                    $chatresult.="There are over 200 players online.";
                  }  
                }
             }else {
                $chatresult="You do not have the item equipped.";
             }
?>