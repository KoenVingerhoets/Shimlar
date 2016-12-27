<?php
// status 0 = asked, 1 = married, 2 = divorced
   $query="select I.Id,I.accx,coalesce(W.pId2,0) as wedded from Inventory I left outer join Wedding W on W.pId1 = I.Id and W.Status in (0,1) where I.pname='$pname'";
   $result=mysql_query($query);
   extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"this");
   if ((int)$this_wedded == 0) {
     if ($this_accx != 0) {
     	$query="select i$this_accx as ring from Inventory where Id = $this_Id"; 
     	$result=mysql_query($query);
     	extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"this");
     	if ($this_ring == 41050000) {
	  $spammer=strstr($cinput," ");
          $spammer=ucwords(trim($spammer));
          $query="Select I.Id,I.accx, coalesce(W.pId2,0) as wedded from Inventory I left outer join Wedding W on W.pId1 = I.Id and W.Status in (0,1) where I.pname='$spammer' and I.pname <> '$pname'";
          if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
            extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
            if ((int)$tgt_wedded == 0) {
              $query="select i$tgt_accx as ring from Inventory where Id = $tgt_Id"; 
              $result=mysql_query($query);
              extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
              if ($tgt_ring == 41050000) {
       	         $query="insert into Wedding(pId1,pId2,Status,Ts) values($this_Id,$tgt_Id,0,now())";
       	         mysql_query($query); // insert twice for faster searching
       	         // $query="insert into Wedding(pId1,pId2,Status,Ts) values($tgt_Id,$this_Id,0,now())";
       	         // mysql_query($query);
       	         $query="Insert into Messages values($tgt_Id,'$pname','wants to marry you... type /yesido if you want to do so!',26,now())";
       	         mysql_query($query);
       	         $query="update Inventory set i$this_accx = 0, accx = 0 where Id = $this_Id";
                 mysql_query($query);    
                 $query="update Inventory set i$tgt_accx = 0, accx = 0 where Id = $tgt_Id";
                 mysql_query($query); 
                 $chatresult="Your proposal to $spammer is made!";     	     
              } else {
                 $chatresult="Your beloved doesn't have a wedding ring equipped.";
              }
            } else {
              $chatresult="$spammer is already married! WHAT ARE YOU DOING???";
            }		
          } else {
            $chatresult="You mistyped the name of your beloved.";
          }
        } else {
          $chatresult="You don't have a wedding ring equipped!";
        }
     } else {
     	 $chatresult="You don't have a wedding ring equipped!";
     }
  } else {
    $chatresult="You're already married! Shimlar doesn't condone polygamy.";
  }    
?>