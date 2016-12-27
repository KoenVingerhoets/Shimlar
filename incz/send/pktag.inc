<?php
            $cinput=strstr($cinput," ");
            $cinput=trim($cinput);
            if (cr_tarkista($cinput,1)) {
              if($lvl>=100 && strlen($cinput)>=3 && strlen($cinput)<=150){
                if($cinput=="null") {
              	  $chatresult="PK tag removed";
              	  $query="delete from PKTag where Id = $Id";
              	  mysql_query($query);
                } else {
                	if(is_substr(":pk:", $cinput)) 
                	{
                		$query="select * from PKTag where Id = $Id";
                		if(($result=mysql_query($query))==TRUE &&(mysql_num_rows($result)==1)){
	                		// exists already!
  	              		$query="update PKTag set pktag = '$cinput' where Id = $Id";
    	            		mysql_query($query);
      	          		$chatresult="PK tag updated to $cinput";
        	        	} else {
          	      		// new tag!
            	    		$query="insert into PKTag(Id,pktag) values($Id,'$cinput')";
              	  		mysql_query($query);
                			$chatresult="PK tag set to $cinput";
                		}
                	} else {
                		$chatresult="PK Tag must contain :pk:, please read the manual";
                	}
                }
              }else if($lvl<50){
                $chatresult="Must be level 100 or more to set a PK tag";
              }else if(strlen($cinput)<3){
                $chatresult="PK tag must be longer then 3 chars.";
              }else if(strlen($cinput)>150){
                $chatresult="PK tag can't be longer then 150 chars";
              }
            } else {
            	$chatresult="PK tag not approved!";
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
 		if($i!=126) {
    	if(strstr($jono,$i))
      	return 0;
    }
  }
  for($i=0;$i<32;$i++) {
    if(strstr($jono,$i))
      return 0;
  }
  for($i=34;$i<40;$i++) {
  	if ($i!=35) {
    	if(strstr($jono,$i))
      	return 0;
    }
  }
  for($i=60;$i<64;$i++) {
  	if (($i!=61)&&($i!=63)) {
    	if(strstr($jono,$i))
      	return 0;
    }
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