<?php
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
    // stop the pressing of new fight without repercussion
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
    
    if((($turns>0)&&($turns<5401))||($tstatus==0)){
    	if($exp<$nxlvl){
      	$lastmon=$k;$lastfight=0;
      	$query="Select zmonsters, zhunt from Zones where znum=$loc_zone";
	      $result=mysql_query($query);
  	    extract(mysql_fetch_array($result));
    	if($lastmon !=999||$zhunt=0){
      	if($lastmon>=$zmonsters){
        	$lastmon=$zmonsters-1;
	      }
  	    $mspec=rand(0,100);
  	    if (($mspec > 1) && ($mspec < 29) && ($mspec%2==0)) 
  	    {
  	    	$lastmon=$k+($mspec*10);
  	    }
    	}
      $e_health=-1;
      /*
      $bdelay=60;
      if($aika<2){
        $bdelay=100;
      }else{*/
        $fms="http://www.shimlar.org/";
        $fmx=$fms[$fmt];
        if($m==$fmx){
          $query="Update Stats set e_health=$e_health,fight_time=now() where Id = $Id";
          mysql_query($query);
          $query="Update Players set lastaction='$action',ax_time=now() where Id = $Id";
          mysql_query($query);
          $btlstr.="a";
        }else{
          ep2(25);
        }
      /* } */
      if ($tstatus==1) {
      	$turns=$turns--;
      	$query="update Stats set turns = turns-1 where Id = $Id";
      	mysql_query($query);
      }
    }else{
//      $query="update Players set banned=banned+10 where Id = $Id";
//      mysql_query($query);
//      $query="insert into Modactions values('A - lvl $lvl', '$pname', 'macroclick?', now())";
//      mysql_query($query);
      ep2(23);
    }
  }else{
  	if($turns<0){
  		ep2(76);
  	} else if ($turns > 5400) {
  		$query="update Players set banned=100 where Id = $Id";
      mysql_query($query);
      $query="insert into Modactions values('A - turns $turns', '$pname', '+5400 free fights', now())";
      mysql_query($query);
  		ep2(77);
  	}
  }
?>
