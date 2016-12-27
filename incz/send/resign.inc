<?php
  if ($clan > 59) {
  	$query="select s.Id, s.name, s.lvl, c.cturn from Stats s inner join Clans c where s.Id = c.cint2 and c.cid = $clan and c.cint = $Id"; 
  	$result=mysql_query($query);  	
  	if ($result) {
  		extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"this");
  		if ($cturn==1) {
  			$chatresult="Nope, nice attempt anyways.";
  		} else {
  			if ($this_lvl > 300) {
  				$query="update Clans set cint=$this_Id,cleader='$this_name',cint2=null,cleader2='' where cid = $clan";
  				$result = mysql_query($query);
  				if ($result) {
  					$chatresult="You have resigned and made $this_name the new clan leader!";
  				} else {
  					$chatresult="Woopsie?";
  				}
  			} else {
  				$chatresult="The level of your second leader is only $this_lvl!";
  			}
  		}
  	} else {
  			$chatresult="You are not in a clan or it has no second leader or you are not the clan leader.";
  	}
  } else {
  	$chatresult="You are not in a clan.";
  }
?>