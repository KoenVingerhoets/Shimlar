<?php
// status 0 = asked, 1 = buddy	
	  $spammer=strstr($cinput," ");
    $spammer=ucwords(trim($spammer));
    $query="Select P.Id,P.Name from Players as P, Buddy as B where P.name='$spammer' and P.name <> '$pname' and ((B.Id = P.Id) and (B.BuddyId = $Id) and (B.Status = 0))";
    if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
    	extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
   		$query="update Buddy set Status = 1, TS = now() where Id=$tgt_Id and BuddyId = $Id";
   	  mysql_query($query); 
      $query="Insert into Messages values($tgt_Id,'$pname','shows on your buddy list now!',26,now())";
      mysql_query($query);
      $chatresult="$spammer asked to have you on his/her buddy list, which you confirmed.";     	     
  	} else {
    	$chatresult="Couldn't confirm the buddy request from $spammer.";
  	}    
?>