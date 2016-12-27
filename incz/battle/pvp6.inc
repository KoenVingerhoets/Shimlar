<?php
	if($tgt_acc_num==4){
  	$tgt_vit-=1000;
  }else if($tgt_acc_num==10){
  	$tgt_vit-=3000;
  }else if($tgt_acc_num==25){
  	$tgt_vit-=10000;
  }
  $e_health=min($tgt_vit,$e_health);
  $e_health=max(0,$e_health);
  $query="Update Stats set exp=$tgt_exp,health=$e_health,gold=$tgt_gold,opponent=$Id where Id=$opponent";
  mysql_query($query);
  if($e_health<=0){
  	$query="Insert into Messages values($opponent,'$pname',0,23,now())";
  	mysql_query($query);
  	$oppname=getName($opponent);
  	if($loc_zone !=40){
  		$pktag=getPKTag($Id);
   		if($pktag!=""){
   			$pktag=str_replace(":pk:","<font color=\'#CCCCCC\'>".$oppname."</font>",$pktag);
   			if (strlen($pktag) < 200) 
   			{
   				inschat("chat1","$pname","$pktag",27);
   			} 
   				else 
   			{
   				inschat("chat1","$oppname","was killed by $pname",27);
   				$query="Insert into Messages values($Id,'$pname','your pktag is too long  - remove some :pk:',26,now())";
    			mysql_query($query);
   			}
   		} else {	
   			inschat("chat1","$oppname","was killed by $pname",27);
  		}
  		$query="Update Stats set pk_time=now() where Id = $Id";
  		mysql_query($query);
  		if ($tstatus==1) {
  			$query="Insert into PKLog(PlayerId,KilledId,TS) values($Id,$opponent,now())";
  			mysql_query($query);
  		}
  	}else{
    	$query="Insert into Messages values($opponent,'$pname','defeated you in a friendly brawl',26,now())";
    	mysql_query($query);
  	}
  	include "duel.inc";
  	valmista_duel($Id,$tstatus);
  }else if($health<=0 && $loc_zone !=40){
  	$query="Insert into Messages values($opponent,'$pname',0,25,now())";
  	mysql_query($query);
  	debugText("Suicide from ".$pname." on ".$oppname." lost gold : ".$lostGold);
  }else if($loc_zone !=40){
  	$query="Insert into Messages values($opponent,'$pname',0,24,now())";
  	mysql_query($query);
  }
?>
