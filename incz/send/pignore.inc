<?php

  $spammer=strstr($cinput," ");
  $spammer=strtolower(trim($spammer));
  $query="Select name from Players where name='$spammer' and channels not in (10,11,20)";
  if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
    $cookieValue = $_COOKIE["pIgnore"];
    if(strstr($cookieValue,$spammer)){
      $spammer=ucwords(trim($spammer));
      $chatresult="You are already ignoring $spammer";
    } else {
      $cookieValue = "'".$cookieValue."\"".$spammer."\",'";
      mysql_query($query);
      print("setIgn($cookieValue);");
      print("\r\n");
      $spammer=ucwords(trim($spammer));
      $chatresult="You are now ignoring $spammer.";
    }
  } else {
    $spammer=ucwords(trim($spammer));
    $chatresult="Player $spammer does not exist";
  }
  
?>
