<?php
   $query="select (ifnull(c.cpower,0)*1000 + s.lvl*5000 + ((s.banked + s.gold)/100000) + s.Fame + (p.quests*1000) + ABS(s.align)*1000) as sumFame from Stats s left outer join Clans c on s.clan = c.cid inner join Players p on p.Id = s.Id where s.tstatus=1 and s.Id=$Id";
   if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
     extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"this");
     $chatresult="You currently have $this_sumFame fame!";
  } else {
    $chatresult="Omg... normal players are so infamous I can't find the words to express your fame.";
  }    
?>