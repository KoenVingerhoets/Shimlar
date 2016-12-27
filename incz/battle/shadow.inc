<?php

    $drop_type=rand(1,5);
    // determine where it comes from
    switch($drop_type){
      case 1:
      	$i_original=$invlist[$rhand-1];
        $i_type=ityper($invlist[$rhand-1]);
        $i_num=inumer($invlist[$rhand-1]);
        $i_gemOne=firstGem($invlist[$rhand-1]);
        $i_gemTwo=secondGem($invlist[$rhand-1]);
        $i_origPosition=$rhand;
        break;
      case 2:
      	$i_original=$invlist[$lhand-1];
        $i_type=ityper($invlist[$lhand-1]);
        $i_num=inumer($invlist[$lhand-1]);   
        $i_gemOne=firstGem($invlist[$lhand-1]);
        $i_gemTwo=secondGem($invlist[$lhand-1]);
        $i_origPosition=$lhand;
        break;
      case 3:
      	$i_original=$invlist[$spellone-1];
        $i_type=ityper($invlist[$spellone-1]);
        $i_num=inumer($invlist[$spellone-1]);
        $i_gemOne=firstGem($invlist[$spellone-1]);
        $i_gemTwo=secondGem($invlist[$spellone-1]);
        $i_origPosition=$spellone;
        break;
      case 4:
      	$i_original=$invlist[$spelltwo-1];
        $i_type=ityper($invlist[$spelltwo-1]);
        $i_num=inumer($invlist[$spelltwo-1]);
        $i_gemOne=firstGem($invlist[$spelltwo-1]);
        $i_gemTwo=secondGem($invlist[$spelltwo-1]);
        $i_origPosition=$spelltwo;
        break;
      case 5:
      	$i_original=$invlist[$armor-1];
        $i_type=ityper($invlist[$armor-1]);
        $i_num=inumer($invlist[$armor-1]);  
        $i_gemOne=firstGem($invlist[$armor-1]);
        $i_gemTwo=secondGem($invlist[$armor-1]);
        $i_origPosition=$armor;
        break;
    }
    // maybe it's an accessory!
  $isAxx = false;
  $isDupli = false;
  $isRandom = false;
  $isShadow	=	false;
  $isUpdate = false;
  if (rand(1,(100000/$spec_axx))==666) {
  	$drop_num=41000000+(rand(0,24)*10000);
  	$isAxx=true;
  } else {
    	if($tstatus==0) {
    		$isShadow=true;
    		if($i_type<11) 
  	  	{
	    		// basic item drops random shadow item
    			// shadow item class = IC-(IC%5)
    			$i_numdrop=inumdrop(max($i_num-1,1));
    			$drop_num=((rand(1,10)+10)*1000000)+($i_numdrop*10000);
  	  	} else {
	    		// other items drop shadow versions of equip you wear
    			// shadow item class = random but up to your current IC-1
    			$i_numdrop=inumdropRandom(max($i_num-1,1));
    			if (($i_type%10)==0) {
  	  			// shields!
	    			$drop_num=(((20)*100)+$i_numdrop)*10000;
    			} else {
    				$drop_num=(((($i_type%10)+10)*100)+$i_numdrop)*10000;
    			}
				}
			}	else	{
				// turn based
				// do item +1 unless empty
				// have 1/5 chance to have a shadow item dropped
				if($i_num > 0) {
					// drop the original one
					$drop_num=$i_original;
					if ($i_type<11) {
						// recreate the new item
						$i_numdrop = $i_num+1;
						if(rand(0,5)==3) {
							// make shadow
							$isShadow=true;
							$i_numdrop = inumdrop($i_num);
							$new_i_type = ($i_type%10)+10;
							if ($new_i_type==10){
								$new_i_type=$new_i_type+10;
							}								
							$newItem = $i_gemOne + ($i_gemTwo*100) + ((($new_i_type*100)+$i_numdrop)*10000);
						} else {
							// paste new item over previous one, that one will be dropped
							$newItem = $i_gemOne + ($i_gemTwo*100) + ($i_numdrop*10000) + ($i_type*1000000);
							$isUpdate=true;
						}
						$sqlix="i$i_origPosition";
						sqlI($sqlix,$newItem,$Id);
					} else {
						$isDupli=true;
					}
				}	else {
					$drop_num=(rand(1,10)*1000000)+(rand(1,5)*10000)+(rand(1,21));
					$isRandom=true;
				}			
			}
	}
		
/*      
      switch($drop_type){
      case 1:
        $i_type=ityper($invlist[$rhand-1]);
        $i_num=inumer($invlist[$rhand-1]);      
        $i_numdrop=inumdrop(max($i_num-1,1));
        if($i_type<1){
          $drop_num=(20*100)*10000;
        }else if($i_type==10|| $i_type==20|| $i_type==30){
          $drop_num=((20*100)+$i_numdrop)*10000;
        }else{
          $drop_num=(((($i_type%10)+10)*100)+$i_numdrop)*10000;
        }
        break;
        case 2:
        $i_type=ityper($invlist[$lhand-1]);
        $i_num=inumer($invlist[$lhand-1]);
        // max($i_num-1,1)
        $i_numdrop=inumdrop(max($i_num-1,1));
        if($i_type<1){
          $drop_num=(20*100)*10000;
        }else if($i_type==10|| $i_type==20|| $i_type==30){
        	$drop_num=((20*100)+$i_numdrop)*10000;
          // $drop_num=(20*100+$i_num-($i_num%5)))*10000;
        }else{
          // $drop_num=((($i_type%10)+10)*100+($i_num-($i_num%5)))*10000;
          $drop_num=(((($i_type%10)+10)*100)+$i_numdrop)*10000;
        }
        break;
        case 3:
        $i_type=ityper($invlist[$spellone-1]);
        $i_num=inumer($invlist[$spellone-1]);
        $i_numdrop=inumdrop(max($i_num-1,1));      
        if($i_type<5){
          $drop_num=(18*100)*10000;
        }else{
          $drop_num=(((($i_type%10)+10)*100)+$i_numdrop)*10000;
        }
        break;
        case 4:
        $i_type=ityper($invlist[$spelltwo-1]);
        $i_num=inumer($invlist[$spelltwo-1]);      
        $i_numdrop=inumdrop(max($i_num-1,1));
        if($i_type<5){
          $drop_num=(18*100)*10000;
        }else{
          $drop_num=(((($i_type%10)+10)*100)+$i_numdrop)*10000;
        }
        break;
        case 5:
        $i_type=ityper($invlist[$armor-1]);
        $i_num=inumer($invlist[$armor-1]);      
        $i_numdrop=inumdrop(max($i_num-1,1));
        if($i_type<9){
          $drop_num=(19*100)*10000;
        }else{
        	$drop_num=((19*100)+$i_numdrop)*10000;
          // $drop_num=(19*100+($i_num-($i_num%5)))*10000;
        }
        break;
      }
*/

      $x=0;
      for($i=0;$i<30;++$i){
        if($x==0 && $invlist[$i]==0){
          $x=$i+1;
        }
      }
      if($x==0){
      	$btlstr.="s,"; 
        ep2(24);   	
      }else{
      	// don't drop this item if it's updated
      	if (!$isUpdate) 
      	{
        	$invlist[$x-1]=$drop_num;
        	$sqlix="i$x";
        	sqlI($sqlix,$drop_num,$Id);
      	}
        $special1=3;
        debugText("Shadow by ".$pname." : item ".$drop_num);
        if ($isAxx) {
        	$btlstr.="sa,";
        } elseif ($isDupli) {
        	$btlstr.="su,";
        } elseif ($isRandom) {
        	$btlstr.="sr,";
        } elseif ($isShadow) {
        	$btlstr.="si,";
        } elseif ($isUpdate) {
        	$btlstr.="sp,";
        } else {
        	$btlstr.="s,";    		
      	}
      }
?>
