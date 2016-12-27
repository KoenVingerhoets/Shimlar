<?php
    $cookieValue = $_COOKIE["noRaceChat"];
    if(strstr($cookieValue,'true')){
      $chatresult="You are ignoring racechat, so you can not chat there :-)";
    } else {
      $cinput=strstr($cinput," ");
      $cinput=trim($cinput);
      if($channels==8){
        $cinput=strrev($cinput);
        $channels=0;
      }else if($channels==19){
        $cinput=strtolower($cinput);
        $channels=0;
      }
      inschat("chat4",$pname,$cinput,$race);
      print "c4(\"$cinput\",\"$pname\",$race);";
    }

?>