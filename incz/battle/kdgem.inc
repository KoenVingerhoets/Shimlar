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

      switch($kd_mine){

      	case 1:

      		if ($tstatus==0) {

        		$gem_num=rand(1,21)+(rand(0,1)*25); // drops all up to jade**

        	} else {

        		$gem_num=rand(1,21);

        	}

      		break;

      	case 2:

      		if ($tstatus==0) {

        		$gem_num=rand(1,21)+(rand(0,2)*25); // drops all up to jade***

        	} else {

        		$gem_num=rand(1,21)+(rand(0,1)*25);

        	}

      		break;

      	case 3: // drops fangs up to ***

      		if($tstatus==0) {

      			if(rand(1,4)==2){

        			$gem_num=rand(0,1)+16+(rand(1,2)*25);

        		} else {

        			$gem_num=rand(1,21)+(rand(0,2)*25);

        		}

        	} else {

        			$gem_num=rand(1,21)+(rand(0,2)*25);

        	}

      		break;

      	case 4: // drops tears 

      		if($tstatus==0) {

      			if(rand(1,4)==2) {

        			$gem_num=18 + (rand(1,2)*25);

        		} else {

        			$gem_num=rand(1,21)+(rand(0,2)*25);

        		}

        	} else {

        		$gem_num=rand(1,21)+(rand(0,3)*25);

        	}

      		break;

      	case 5: // diamonds

      		if($tstatus==0) {

        		$gem_num=rand(0,2)*25+19;

        	} else {

        		$gem_num=rand(1,21)+(rand(0,3)*25);

        		if(rand(1,10)==5) 

      			{

      				$turnUp = rand(1,540);

      				if(($turns+$turnUp)<5400){

      					$query="update Stats set turns = turns + $turnUp where Id = $Id";

      					mysql_query($query);

      				}

      			}

        	}

      		break;

      }

      $invlist[$x-1]=$gem_num;

      $special1=3;

      $sqlix="i$x";

      sqlI($sqlix,$gem_num,$Id);

      debugText("Mine-Drop by ".$pname." : gem ".$gem_num);

    }

    $btlstr.="sm,";

?>

