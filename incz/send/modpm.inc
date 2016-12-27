<?php
	if(($channels==10)||($channels==11)||($channels==12)||($channels==20)) {
            $telln=strstr($cinput," ");
            $telln=trim($telln);
            $telltxt=strstr($telln,":");
            $telltxt=substr($telltxt,2);
            $telln=substr($telln,0,(strlen($telln)-strlen($telltxt)-2));
            $telln=ucwords($telln);
            $query="Select Id as spId from Players where name='$telln'";
            if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
            	extract(mysql_fetch_array($result));
                $query="Insert into Messages values($spId,'$pname','$telltxt',5,now())";
              	mysql_query($query);
              	$query="update Inventory set checked = 1 where Id = $spId";
              	mysql_query($query);
            	$chatresult="[player pm] You blocked trading and told $telln: $telltxt";
            }else {
              $chatresult="Player $telln does not exist";
            }
     	} else {
		$chatresult="Whateva!";
	}
?>

