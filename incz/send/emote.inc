<?php
            $cinput=strstr($cinput," ");
            $cinput=trim($cinput);
            if($channels==8){
              $cinput=strrev($cinput);
              $channels=0;
            }else if($channels==19){
              $cinput=strtolower($cinput);
              $channels=0;
            }
            if($luku1<4) {
              inschat("chat$luku1",$pname,$cinput,1);
              print "c$luku1(\"$cinput\",\"$pname\",1);";
            }
?>