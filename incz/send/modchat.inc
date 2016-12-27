<?php
            $cinput=strstr($cinput," ");
            $cinput=trim($cinput);
            if($channels==10 || $channels==11 || $channels==12 || $channels==20){
              inschat("chat1",$pname,$cinput,30);
              inschat("chat3",$pname,$cinput,30);
              inschat("chat4",$pname,$cinput,30);
              print "c1(\"$cinput\",\"$pname\",30);";
              print "c3(\"$cinput\",\"$pname\",30);";
              print "c4(\"$cinput\",\"$pname\",30);";
            }else {
              $chatresult="You do not have this power!";
            }
?>