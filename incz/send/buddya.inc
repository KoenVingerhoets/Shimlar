<?php
// status 0 = asked, 1 = buddy	
	  $spammer=strstr($cinput," ");
    $spammer=ucwords(trim($spammer));
    $query="SELECT DISTINCT P.Id, P.Name, B.TS FROM Players AS P LEFT JOIN Buddy AS B ON (B.BuddyId = P.Id AND B.Id =$Id) WHERE P.name = '$spammer' AND P.name <> '$pname'";
    // $query="Select distinct(P.Id),P.Name from Players as P, Buddy as B where P.name='$spammer' and P.name <> '$pname' and not ((B.Id = $Id) and (B.BuddyId = P.Id))";
    if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
    	extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
    	if ($tgt_TS == null) 
    	{
   			$query="insert into Buddy(Id,BuddyId,Status,Ts) values($Id,$tgt_Id,0,now())";
   	  	mysql_query($query); 
     		// $query="Insert into Messages values($tgt_Id,'$pname','wants to add you to his buddy list... type /buddyc $pname if you want to do so!',26,now())";
     		$query="Insert into Messages values($tgt_Id,'$pname','wants to add you to his/her buddy list... <a href=\'javascript:top.tell(&quot;#buddyc $pname&quot;);\';>click here</a> and press send to confirm!',26,now())";
      	mysql_query($query);
      	$chatresult="Your request to add $spammer to your buddy list is awaiting confirmation!";
      } else {
      	$chatresult="$spammer is already on your buddy list.";
      }     	     
  	} else {
    	$chatresult="$spammer does not exist.";
  	}    
?>