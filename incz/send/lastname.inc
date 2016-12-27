<?php
            $cinput=strstr($cinput," ");
            $cinput=trim($cinput);
            if (cr_tarkista($cinput,1)) {
              if($lvl>=50 && strlen($cinput)>=3 && strlen($cinput)<=20){
                if($cinput=="null") {                	
              	  $chatresult="Last Name Reset";
              	  sqlP(surname,"",$Id);
              	  $surname = strtoupper($surname);
              	  
              	  if (is_substr("7TH HEAVEN",$surname) ||
              	  		is_substr("DEMANDRED", $surname) ||
              	  		is_substr("STAR SHOOTER", $surname) ||
              	  		is_substr("RESEMBLANCE", $surname) ||
              	  		is_substr("BLACK CHOCOBO", $surname)) 
              	  {
              	  			inschat("chat1",$pname,"My last name ".$surname." is reset and can no longer be used for MACROING!",30);
              	  			// print "c1(\"My last name ".$surname." is reset and no longer used for MACROING!\",\"$pname\",30);";
              	  }              	  
                } else {
              	  $chatresult="Last Name Set";
              	  sqlP(surname,$cinput,$Id);             	  
              	  
              	  $cinput=strtoupper($cinput);
              	  
              	  if (is_substr("7TH HEAVEN",$cinput) ||
              	  		is_substr("DEMANDRED", $cinput) ||
              	  		is_substr("STAR SHOOTER", $cinput) ||
              	  		is_substr("RESEMBLANCE", $cinput) ||
              	  		is_substr("BLACK CHOCOBO", $cinput)) 
              	  {
              	  			inschat("chat1",$pname,"My last name ".$cinput." can be used for MACROING!",30);
              	  			// print "c1(\"My last name ".$cinput." is used for MACROING!\",\"$pname\",30);";
              	  }              	
              	}              	  
              }else if($lvl<50){
                $chatresult="Must be level 50 or more to set Last Name";
              }else if(strlen($cinput)<3){
                $chatresult="Last Name must be longer then 3 chars.";
              }else if(strlen($cinput)>12){
                $chatresult="Last Name must be less than 21 characters long";
              }
            } else {
            	$chatresult="Lastname not approved!";
            }
            
function is_substr($needle, $haystack){ 
        $pos = strpos($haystack, $needle); 
 
        if ($pos === false) { 
                return false; 
        } else { 
                return true; 
        } 
} 
            
function cr_tarkista($jono,$x) {
  $jono=strtolower($jono);
  if(strstr($jono,"\""))
    return 0;
  if(strstr($jono,"\'"))
    return 0;
  if(strstr($jono,"\\"))
    return 0;
  if(strstr($jono,"<"))
    return 0;
  if(strstr($jono,">"))
    return 0;
  if(strstr($jono,"&"))
    return 0;
  if(strstr($jono,"/"))
    return 0;
  if(strstr($jono,"%"))
    return 0;
  if(strstr($jono,"`"))
    return 0;
  if(strstr($jono,"´"))
    return 0;
  for($i=123;$i<256;$i++) {
    if(strstr($jono,$i))
      return 0;
  }
  for($i=0;$i<32;$i++) {
    if(strstr($jono,$i))
      return 0;
  }
  for($i=33;$i<46+$x*2;$i++) {
    if(strstr($jono,$i))
      return 0;
  }
  for($i=58;$i<64;$i++) {
    if(strstr($jono,$i))
      return 0;
  }
  for($i=91;$i<95;$i++) {
    if(strstr($jono,$i))
      return 0;
  }

  if(strstr($jono,"fuck") || strstr($jono,"shit") || strstr($jono,"bitch") || 
strstr($jono,"vittu") || strstr($jono,"  ")){
    return 0;
  }
return 1;
}

?>