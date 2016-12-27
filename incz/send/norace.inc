<?php
    $cookieValue = $_COOKIE["noRaceChat"];
    if(strstr($cookieValue,'true')){
      $chatresult="You are already ignoring racechat";
    } else {
      print("setNoRace('true');");
      print("\r\n");
      $chatresult="You are now ignoring racechat.";
    }

?>
