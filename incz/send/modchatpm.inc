<?php
            if(($channels == 10) || ($channels == 11) || ($channels ==12)|| ($channels == 20)){
            	$cinput=strstr($cinput," ");
              $cinput=trim($cinput);
              $query="Select Id as spId from Players where channels in (10,11,12,20) and Id <> $Id";
              $result=mysql_query($query);
              while($row=mysql_fetch_array($result)){
                  $query="Insert into Messages values($row[spId],'$pname','(mod) $cinput',5,now())";
                  mysql_query($query);
              }
              $chatresult="You tell all mods: $cinput";
            }else {
              $chatresult="You do not have this power!";
            }            
?>