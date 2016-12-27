<?php
 if($channels==10 || $channels==11 || $channels==12 || $channels==20){
            $telln=strstr($cinput," ");
            $telln=trim($telln);
            $telltxt=strstr($telln,":");
            $telltxt=substr($telltxt,2);
            $telln=substr($telln,0,(strlen($telln)-strlen($telltxt)-2));
            $telln=ucwords($telln);
            $query="Select Id from Players where name='$telln'";
            if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
              extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
              if (ctype_digit($telltxt)) {
              	$telltxt = intval($telltxt);
              	$query="update Players set ign = $telltxt where Id = $tgt_Id";
              	if (mysql_query($query)) {
              	  $query = "update Inventory set checked = 1 where Id = $tgt_Id";
              	  mysql_query($query);
              	  $chatresult = "$telln ignore level set to $telltxt.";
              	} else {
              	  $chatresult = "Couldn't set ignore level to $telltxt for $telln.";
              	}
              } else {
              	$chatresult = "Ignore level $telltxt is not valid.";
              }
            }else {
              $chatresult="Player $telln does not exist";
            }
  }else {
    $chatresult="You do not have this power!";
  }
?>
