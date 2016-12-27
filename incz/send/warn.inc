<?php
            if(($channels>=10)&&($channels<=20)){
              $cinput=strstr($cinput," ");
              $cinput=trim($cinput);
              if($luku1<5){
              	switch ($cinput){
              	  case "ooc" :
              	    $cinput = "Please do not post too much OOC in Roleplay. Thank you. :)";
              	    break;
              	  case "beg" :
              	    $cinput = "Please do not beg. Earn your gold/items. :)";
              	    break;
              	  case "play" :
              	    $cinput = "Please play nice amongst each other. Thank you. :)";
              	    break;
              	  case "help" :
              	    $cinput = "Please read the manual and/or chat rules. :)";
              	    break;
              	  case "pm" :
              	    $cinput = "Do not post PMs in chat!";
              	    break;
              	  case "spam" :
              	    $cinput = "Do not spam. Thank you. :)";
              	    break;
              	  case "caps" :
              	    $cinput = "CAPS ARE ANNOYING! case and point. :)";
              	    break;
              	}
                inschat("chat$luku1",$pname,$cinput,13);
                print "c$luku1(\"$cinput\",\"$pname\",13);";
              }
            }else {
              $chatresult="You do not have this power!";
            }
?>