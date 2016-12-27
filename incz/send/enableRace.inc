<?php
    $cookieValue = $_COOKIE["noRaceChat"];
    if(!strstr($cookieValue,'true')){
      $chatresult="You are not ignoring racechat";
    } else {
      print("setNoRace('false');");
      print("\r\n");
      $chatresult="You are no longer ignoring racechat.";
    }

?>
