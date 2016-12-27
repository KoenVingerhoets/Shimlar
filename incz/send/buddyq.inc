<?php
// status 0 = asked, 1 = buddy	
	  $spammer=strstr($cinput," ");
    $spammer=ucwords(trim($spammer));
    $query="Select distinct(P.Id),P.Name from Players as P, Buddy as B where P.name='$spammer' and P.name <> '$pname' and ((B.Id = P.Id) and (B.BuddyId = $Id))";
    if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
    	extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
   		$query="delete from Buddy where Id=$tgt_Id and BuddyId = $Id";
   	  mysql_query($query); 
      $query="Insert into Messages values($tgt_Id,'$pname','removed him/herself from your buddy list!',26,now())";
      mysql_query($query);
      $chatresult="You're no longer on the buddy list of $spammer.";     	     
  	} else {
    	$chatresult="Couldn't locate you on the buddy list from $spammer.";
  	}    
?>