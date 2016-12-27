<?php
// status 0 = asked, 1 = buddy	
	  $spammer=strstr($cinput," ");
    $spammer=ucwords(trim($spammer));
    $query="Select P.Id,P.Name from Players as P, Buddy as B where P.name='$spammer' and P.name <> '$pname' and B.Id = $Id and B.BuddyId = P.Id";
    if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
    	extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
   		$query="delete from Buddy where Id=$Id and BuddyId = $tgt_Id";
   	  mysql_query($query); 
      $query="Insert into Messages values($tgt_Id,'$pname','removed you from his/her buddylist!',26,now())";
      mysql_query($query);
      $chatresult="You removed $tgt_Name from your buddy list.";     	     
  	} else {
    	$chatresult="Couldn't remove $spammer from your buddy list.";
  	}    
?>