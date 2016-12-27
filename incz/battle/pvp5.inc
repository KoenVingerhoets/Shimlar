<?php
    if($e_health<=0){
      if($loc_zone!=40){
      	$pked=false;
        if($tgt_lvl<249){
          if($tgt_lvl>9){
            $tgt_j1=round(($tgt_lvl-5)/10);
            $tgt_j2=$tgt_lvl-($tgt_j1*10);
            $tgt_nxlvl=round(1000*(pow(1.35,$tgt_j1)-1)/(0.35))+round(100*$tgt_j2*(pow(1.35,$tgt_j1)));
          }else{
            $tgt_nxlvl=100*$tgt_lvl;
          }
        }else if($tgt_lvl<999){
          $tgt_nxlvl=5000000+($tgt_lvl-249)*200000;
        }else{
          $tgt_nxlvl=300000000+($tgt_lvl-999)*3700000;
        }
        $tgt_exp=max($tgt_exp-round($tgt_nxlvl*$tgt_death_exp),0);
        
        $Trandperc = 1;
        $fame=1000;
		  	if ($tstatus==1) {
  				// get's between 1 and 10 percent of gold:
  				$Trandperc = rand(1,10)/100;
  				// fame is based upon the level difference
  				$wonFame=($tgt_lvl - $lvl)*100;
  				$pkedFame=0;
  				if ($tgt_lvl > $lvl) {
  					$pkedFame=round(($wonFame/4)*3)*-1;
  					if ($tgt_tstatus==0) {
  						$wonFame=round($wonFame/2);
  					}
  				} else {
  					$pkedFame=abs($wonFame/10);
  					$wonFame=$pkedFame*-1;  					
  				}
  				$fame=$fame+$wonFame;
  				// update the pk'ed person
  				if ($tgt_tstatus==1) {
  					$query="update Stats set fame=fame+$pkedFame where Id = $tgt_Id";
  					mysql_query($query);
  				} 
  			}
        $gold+= round(($tgt_gold*$tgt_death_gold)*$Trandperc);
        debugText("PK from ".$Id." on ".$opponent." won Gold ".round(($tgt_gold*$tgt_death_gold)*$Trandperc));
      	$pked=true;
        $tgt_gold-=($tgt_gold*$tgt_death_gold);
        if($tgt_align<0 && $loc_zone!=47 ){
      	  if(($align-$tgt_align)> 100){
      	    $align=min(10000,$align+2);
      	  }else{
      	    $align=min(10000,$align+1);
      	  }
        }else{
          if(($tgt_align-$align)>100){
            $align=min(10000,$align-2);
          }else{
            $align=min(10000,$align-1);
          }
        }
        if($pked) {
          $query="update Stats set PKill=(PKill+1),align=$align,fame=fame+$fame where Id = $Id";
          mysql_query($query);          
        } else {
          sqlS(align,$align,$Id);
        }
      }
      $btlstr.="s,";
    }
?>
