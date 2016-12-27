<?php
    $lastmon=1000;$lastfight=1;
    $opponent=$k;
    // $bdelay=60;
    if ($k==$Id){ 
      $query="Update Players set banned=100 where Id = $Id"; 
      mysql_query($query); 
      $query="Insert into Modactions values('SELFDUELBAN','$pname','autoban for selfdueling',now())"; 
      mysql_query($query);  
      ep2(1); 
    } 
    /*
    if($aika<2){
      $bdelay=100;
    } */
    if($freelvl>0){
      $nxlvl=0;
    }else{
      if($lvl<249){
        if($lvl>9){
          $j1=round(($lvl-5)/10);
          $j2=$lvl-($j1*10);
          $nxlvl=round(1000*(pow(1.35,$j1)-1)/(0.35))+round(100*$j2*(pow(1.35,$j1)));
        }else{
          $nxlvl=100*$lvl;
        }
      }else if($lvl<999){
        $nxlvl=5000000+($lvl-249)*200000;
      }else{
        $nxlvl=300000000+($lvl-999)*3700000;
      }
    }
    
    if ($e_health==-1) 
    {
    	// new fight has just been pressed - looses gold in hand
    	$query="update Stats set gold = 0 where Id = $Id";
    	mysql_query($query);
    	$gold = 0;
    } else if ($e_health > 0 && $health > 0) {
    	// in the middle of a fight...
    	$rateLoss = max($e_health,$health)/min($e_health,$health);
			$gold = $gold - min(intval($gold/$rateLoss),$gold);
			$query = "update Stats set gold = $gold where Id = $Id";
			mysql_query($query);
    }
    
    if($exp<$nxlvl){
      $query="Update Stats set opponent=$opponent,e_health=0,status=$lastmon,fight_time=now() where Id = $Id";
      mysql_query($query);
      $query="Update Players set lastaction='$action',ax_time=now() where Id = $Id";
      mysql_query($query);
      $btlstr.="a";
    }else{
      $query="update Players set banned=banned+10 where Id = $Id";
      mysql_query($query);
      $query="insert into Modactions values('D - lvl $lvl', '$pname', 'macroclick?', now())";
      mysql_query($query);
      ep2(23);
    }
?>
