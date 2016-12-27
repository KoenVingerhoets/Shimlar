<?php
	if($e_health<=0){
  	if(rand(1,150)==11){
  		$fmt=rand(1,22);
  		sqlS(fmt,$fmt,$Id);
  		print "top.fmt=$fmt;";
    }
    if($max_gem>0 && $lastmon !=999){
    	$rndFactor=1+$spec_brutal;
    	if ($tstatus==1) 
    	{
    		$rndFactor = 2+max($spec_brutal,0.5);
    	}
    	if (rand(1,(5000/$rndFactor))==6) {
  			$btlstr.="sg,";
  			$rndGold = rand(500,1000)*$lvl;
  			$query="update Stats set banked=banked+$rndGold where Id = $Id";
  			mysql_query($query);
  		} else {
 				$gem_chance=rand(1,Round(1500/$rndFactor));
  			if($gem_chance<(3+$drop_bonus)){
    			include "gem.inc";
  			}else{
    			$drop_chance=rand(1,Round(15000/$rndFactor));
    			if($max_gem==7){
	      		$drop_chance=rand(1,Round(10000/$rndFactor));
  	  		}
    			if($drop_chance<(3+$drop_bonus) && $max_gem>2){
      			include "shadow.inc";
    			}else{
      			if($kd_tax>4){
        			$gem_chance=rand(1,Round(2500/$rndFactor));
	        		if($gem_chance==111 && $kd_mine>0){
  	        		include "kdgem.inc";
    	    		}else{
      	    		$btlstr.="s,";
        			}
      			}else{
      				if ($tstatus==1) {
      					// must be able to divide by three as spec!
      					if(rand(1,(2400/max($spec_brutal,1)))==5) 
	      				{
  	    					$turnUp = rand(1,540);
      						if(($turns+$turnUp)<5400){
    	  						$query="update Stats set turns = turns + $turnUp where Id = $Id";
      							mysql_query($query);
      							$btlstr.="st,";
      						} else {
      							$btlstr.="s,";
      						} 
	      				} else {
  	    					$btlstr.="s,";
    	  				}
      				} else {
        				$btlstr.="s,";
        			}
	      		}	
  	  		}
  			}
  		}
   	}else{
 			$btlstr.="s,";
		}        
  	
  	if($qnum>0 && $qmon==$lastmon && $qzone==$loc_zone && $qstatus==0){
  		$query="Update Quests set qstatus=$Id where qnum=$qnum"; 
  		mysql_query($query);
  		$query="Update Players set qnum=0 where Id!=$Id and qnum=$qnum";
  		mysql_query($query);
  		if (($turns+270)<5400) {
  			$query="update Stats set turns=turns+270 where Id = $Id";
  			mysql_query($query);
  		}
  		$qhd+=8;
  		if($cbonus==6){
    		$qhd-=(1*$clx);
  		}
  		$query="update Players set qhd = $qhd, qnum = $qnum where Id = $Id";
  		mysql_query($query);
  		inschat("chat1",$pname,"$qzone,$qmon,$qmlist",29);
  		inschat("chat4",$pname,"$qzone,$qmon,$qmlist",29);
  		print "mX(19);";
    }
      if($tef>0){
  --$tfc;sqlS(tfc,$tfc,$Id);
  if($tfc==0){
    $tef=0;sqlS(tef,0,$Id);
  }
      }
    if($lastmon !=999){
    	$align=$align+$spec_align;
      if($loc_zone==15 || $loc_zone==19 || $loc_zone==21 || $loc_zone==46){
      	if(rand(1,333)==111 && $align<10000){
      		++$align;
      		sqlS(align,$align,$Id);
      	}
      }else if($loc_zone==17 || $loc_zone==22 || $loc_zone==23 || $loc_zone==47){
      	if(rand(1,333)==222 && $align>-10000){
      		--$align;
      		sqlS(align,$align,$Id);
      	}
      }
      // } else if ($spec_align!=0) {
      	sqlS(align,$align,$Id);
      // }
      $exp=$exp+round($zbase_exp*pow(1.5,(int)$lastmonx)*(1+$exp_bonus))*$spec_exp;
      if($tstatus==1) {
      	$zbase_gold=$zbase_gold*$tbfactor;
      }
      if($kd_tax>0){
      // if($kd_tax>0 && $cint!=$Id && $cint2!=$Id){
  			$kd_goldx=round($zbase_gold*($lastmonx+1)*(1+$gold_bonus)*$spec_gold*$kd_tax/100);
  			$gold=$gold+round($zbase_gold*($lastmonx+1)*(1+$gold_bonus)*$spec_gold)-$kd_goldx;
  			$query="Update Kingdoms set kd_gold=kd_gold+$kd_goldx where kd_clan=$clan";
 				mysql_query($query);
      }else{
  			$gold=$gold+round($zbase_gold*($lastmonx+1)*(1+$gold_bonus)*$spec_gold);
      }
      if($lastmon>=160 && $lastmon <180 && $loc_zone !=32 && $loc_zone !=26 && $loc_zone !=18){
  $tx=rand(0,1);
  if($tx==0){
    $loc_y=$zbank%10;$loc_x=($zbank-($zbank%10))/10;
  }else{
    $loc_x=rand(0,$zkoko);$loc_y=rand(0,$zkoko);
  }
  $query="Update Players set loc_x=$loc_x,loc_y=$loc_y where Id=$Id";
  mysql_query($query);
  $query="Update Stats set e_health = 0 where Id = $Id";
  mysql_query($query);
  include "tele.inc";
  print "x6($loc_x,$loc_y,$stuff_here,0);";
  print "mX(0);";
      }
    }else{
      include "hunt2.inc";
    }
    }
?>
