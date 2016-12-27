<?php
            if($clan>1){
              $query="Select cname,cleader,cleader2 from Clans where cid=$clan";
              $result=mysql_query($query);
              extract(mysql_fetch_array($result));
              if($pname==$cleader || $pname==$cleader2){
                $cinput=strstr($cinput," ");
                $cinput=trim($cinput);
                $query="select Id as spId,name from Stats where clan=$clan";
                $result=mysql_query($query);
                while($row=mysql_fetch_array($result)){
                  $query="Insert into Messages values($row[spId],'$pname','(clan info) $cinput',5,now())";
                  mysql_query($query);
                }
                $chatresult="You tell all members of $cname: $cinput";
              }else {
                $chatresult="You do not have this power!";
              }
            }
?>