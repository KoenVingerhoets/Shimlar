<?php
            if(($channels>=10)&&($channels<=20)){
              $cinput=strstr($cinput," ");
              $cinput=trim($cinput);
              if($luku1==2){
                inschat("chat2",$pname,$cinput,6);
                print "c2(\"$cinput\",\"$pname\",6);";
              } else {
              	$chatresult="Only use in roleplay please.";
              }
            }else {
              $chatresult="You do not have this power!";
            }
?>