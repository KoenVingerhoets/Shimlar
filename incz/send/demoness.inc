<?php
            if($channels==10 || $channels==12 || $channels==20){
              $cinput=strstr($cinput," ");
              $cinput=trim($cinput);
              if ($luku1<4){
                inschat("chat2",$pname,$cinput,8);
                print "c2(\"$cinput\",\"$pname\",8);";
	        }
            }else {
              $chatresult="You do not have this power!";
            }
?>