<?php

	if($clan>60){

		$text=strstr($cinput," ");

		$text=ucwords(trim($text));

    $query="Select coalesce(cint,0) as cint,coalesce(cint2,0) as cint2 from Clans where cid = $clan";

		if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){

    	extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");

    	if ($tgt_cint!=0) 

    	{

    		$query="Insert into Messages values($tgt_cint,'$pname','$text',5,now())";

        mysql_query($query);

    	}

    	if ($tgt_cint2!=0) 

    	{

    		$query="Insert into Messages values($tgt_cint2,'$pname','$text',5,now())";

        mysql_query($query);

    	}

		  $chatresult="You say to your leaders: $cinput";

	} else {

		$chatresult="You're not really in a clan?";

	}

?>

