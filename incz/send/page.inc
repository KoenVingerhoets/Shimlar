<?php
            if($channels==10 || $channels==11 || $channels==20 || $channels==12){
              $query="select Id as spId,name from Players where channels=20 || channels=12";
              $result=mysql_query($query);
              $paget=date("M j G:i:s T");
              while($row=mysql_fetch_array($result)){
                $query="Insert into Messages values($row[spId],'$pname','DISTRESS CALL: ARCH NEEDED! - $paget',5)";
                mysql_query($query);
              }
              $query="Insert into Modactions values('$pname','distress','distress',now())";
              mysql_query($query);
              $chatresult="Distress call made!!";
            }else {
              $chatresult="You do not have this power!";
            }
?>