<?php

		$cinput=strstr($cinput," ");
    $cinput=trim($cinput);
    
    $query="select BuddyId from Buddy where Id = $Id and Status = 1";
    if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)>0)
    {
    	$a1=mysql_num_rows($result);
    	for	($i=0;$i<$a1;$i++) 
    	{
    		$row=mysql_fetch_row($result);
    		$tgt_id=$row[0];
    		$query="Insert into Messages values($tgt_id,'$pname','$cinput',5,now())";
        mysql_query($query);                   
    	}
    	$chatresult="You say to your buddies: $cinput";
    } 
    else 
    {
    	$chatresult="You have no buddies in your list.";
    }
?>
