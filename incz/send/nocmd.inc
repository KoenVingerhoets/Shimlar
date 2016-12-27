<?php
            switch($channels) {
            case 8: //player cursed
              $cinput=strrev($cinput);
              $channels=0;
              break;
            case 19: //player caps-cursed
              $cinput=strtolower($cinput);
              if($align>99) { //good align, yellow color
                $channels=3;
              } else if($align<-99) { //evil align, red color
                $channels=4;
              } else { //smurfs
                $channels=0;
              }
              break;
            case 0:
              if($align>99) { //good align, yellow color
                $channels=3;
              } else if($align<-99) { //evil align, red color
                $channels=4;
              } else { //smurfs
                $channels=0;
              }
              break;
            case 10:  //chat mod
              if($align>99) {
                $channels=10;
              } else if($align<-99) {
                $channels=11;
              } else {
                $channels=17;
              }
              break;
            case 11: //rp mod
              if($align>99) {
                $channels=63;
              } else if($align<-99) {
                $channels=64;
              } else {
                $channels=62;
              }
            }
            if($luku1==4 && $clan>1){
           	  inschat("chat4",$pname,$cinput,$clan);
              $query="Select cname from Clans where cid=$clan";
              $result=mysql_query($query);
              extract(mysql_fetch_array($result));
              print "c4(\"$cinput\",\"$pname\",\"$cname\");";
            } else if ($luku1<4){
              inschat("chat$luku1",$pname,$cinput,$channels);
              print "c$luku1(\"$cinput\",\"$pname\",$channels);";
            }

?>