<?php
            if($channels==20){
              $cinput=strstr($cinput," ");
              $cinput=trim($cinput);
              inschat("chat1",$pname,$cinput,2);
              inschat("chat2",$pname,$cinput,2);
              inschat("chat3",$pname,$cinput,2);
              inschat("chat4",$pname,$cinput,2);
              print "c1(\"$cinput\",\"$pname\",2);";
              print "c2(\"$cinput\",\"$pname\",2);";
              print "c3(\"$cinput\",\"$pname\",2);";
              print "c4(\"$cinput\",\"$pname\",2);";
            }
?>