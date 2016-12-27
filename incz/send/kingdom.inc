<?php
                 $query="Select clan from Stats where Id = $Id";
                 if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
                   extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"this");
                   if ($this_clan != 0) {
                   	$query ="select c.cname,c.cleader,count(s.Id) as clannies, k.kd_gold, k.kd_tax, k.kd_loc from Stats s, Clans c, Kingdoms k where c.cid = $this_clan and s.clan = $this_clan and k.kd_clan =c.cid group by c.cid";
                   	$result=mysql_query($query);
                   	$kd = true;
                   	if (mysql_num_rows($result)==0) {
                   		$kd = false;
                   		$query="select c.cname,c.cleader,count(s.Id) as clannies from Stats s, Clans c where c.cid = $this_clan and s.clan = $this_clan group by c.cid";
                   		$result=mysql_query($query);
                   	}
                   	extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"this");
                   	if ($kd) {
                   		$this_kd_loc = $this_kd_loc/10;
                   		$this_kd_gold = number_format($this_kd_gold);
                   		$kdmessage = "The Kingdom's vault located at $this_kd_loc holds $this_kd_gold gold, gained with a $this_kd_tax % tax.";
                   	} else {
                   		$kdmessage = "The Clan has no Kingdom yet.";
                   	}	
                   	$chatresult="Clan $this_cname has $this_clannies members under the leadership of $this_cleader. $kdmessage";
                   		
                   } else {
                   	$chatresult="You're no part of a Clan.";
                   }
                 }else {
                  $chatresult="Invalid data.";
                 } 
?>