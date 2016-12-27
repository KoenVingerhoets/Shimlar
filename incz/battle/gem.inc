<?php
    $x=0;
    for($i=0;$i<30;++$i){
      if($x==0 && $invlist[$i]==0){
        $x=$i+1;
      }
    }
    if($x==0){
      ep2(24);
    }else{
    	if($tstatus==0) {
      	$gem_num=rand(1,21);
      	switch($max_gem){
      		case 2:
        		if(rand(1,4)==2){
    					$gem_num+=25;
	        	}
  	    		break;
    	  	case 3:
      	  	if(rand(1,4)==2){
    					$gem_num+=25;
	        	}
  	      	if(rand(1,4)==2){
    					$gem_num+=25;
      	 	 	}
      			break;
      		case 4:
        		$gem_num+=25;
	        	if(rand(1,5)==2){
  	  				$gem_num+=25;
    	    	}
      			break;
      		case 5:
        		$gem_num+=50;
	        	if(rand(1,5)==2){
  	  				$gem_num-=25;
    	    	}
      			break;
      		case 6:
        		$gem_num+=25;
	        	if(rand(1,15)==2){
  	  				$gem_num+=50;
    	    	}
      			break;
      	}
			} else {
				// for turn based chars, make an array of all the equipped gems, take 1 and add a star
				// if non is found after 2 times, make a random and add +25
				$gemsEquipped = array();
				if($rhand==0) {
					$gemsEquipped[0]=0;
					$gemsEquipped[1]=0;
				} else {
					$gemsEquipped[0]=firstGem($invlist[$rhand-1]);
					$gemsEquipped[1]=secondGem($invlist[$rhand-1]);
				}
				if($lhand==0) {
					$gemsEquipped[2]=0;
					$gemsEquipped[3]=0;
				} else {
					$gemsEquipped[2]=firstGem($invlist[$lhand-1]);
					$gemsEquipped[3]=secondGem($invlist[$rhand-1]);
				}
				if ($spellone == 0) {
					$gemsEquipped[4]=0;
					$gemsEquipped[5]=0;
				} else {
					$gemsEquipped[4]=firstGem($invlist[$spellone-1]);
					$gemsEquipped[5]=secondGem($invlist[$spellone-1]);
				}
				if ($spelltwo == 0) {
					$gemsEquipped[6]=0;
					$gemsEquipped[7]=0;
				} else {
					$gemsEquipped[6]=firstGem($invlist[$spelltwo-1]);
					$gemsEquipped[7]=secondGem($invlist[$spelltwo-1]);
				}
				if ($armor == 0) {
					$gemsEquipped[8]=0;
					$gemsEquipped[9]=0;
				} else {
					$gemsEquipped[8]=firstGem($invlist[$armor-1]);
					$gemsEquipped[9]=secondGem($invlist[$armor-1]);
				}
				$foundOne=false;
				for($i=0;$i<2;$i++) {
					if ($foundOne == false) {
						$gemPos = rand(0,9);					
						$gem_num = $gemsEquipped[$gemPos];
						if ($gem_num!=0) {
							if ($gem_num < 75) {
								$gem_num+=25;
							}
							$foundOne=true;
						}
					}
				}
				if($foundOne == false) {
					$gem_num = rand(1,21);
				}
			}
		}
    $invlist[$x-1]=$gem_num;
    $special1=3;
    $sqlix="i$x";
    sqlI($sqlix,$gem_num,$Id);
    
    debugText("Gem-Find by ".$pname." : gem ".$gem_num);
      $btlstr.="sd,";
?>
