<?php
function wep_attack($who,$dt,$wp,$str,$wm,$wm_max,$chit,$ap,$hp,$am,$am_max){
  global $btlstr,$damage,$lastmon,$lvl,$spec_ma;
  $btlstr.="$who";$xm=0;
  $hit=rand(1,100);
  if($chit>$hit){
    $fdam_m=pow(1.2,($wp-round($ap+$am/5))); //round total AC
    $damage=round(rand($str/8,$str/1.7)*$fdam_m);
    if($who=='u' && $lastmon==999){
      $damage=round(2*$damage/$lvl)+10000;
    }
    $chance_crit=rand(1,20+$wm/10);
    if($chance_crit>19){
      $damage=$damage*5;
      $damage=max(1,min($hp,$damage));
      $btlstr.="fc$dt,$damage,";
    }else{
      $damage=max(1,min($hp,$damage));
      $btlstr.="f$dt,$damage,";
    }
    $masteryChance = 2;
    if ($damage == $hp){
      $masteryChance += $spec_ma;
    }
    if($who=='u' && $wm<$wm_max && $lastmon!=1000){
      if(rand(1,max(20+$wm*50,50))<($masteryChance)){
  ++$xm;
  print "mX(13);";
      }
    }else if($who=='e' && $am<$am_max && $lastmon!=1000){
      if(rand(1,max(20+$am*50,50))<($masteryChance)){
  ++$xm;
  print "mX(17);";
      }
    }
  }else{
    $btlstr.="m,";
  }
  return $xm;
}
function spell_attack($who,$dt,$sp,$ntl,$sm,$sm_max,$chit,$ap,$hp,$am,$am_max){
  global $btlstr,$damage,$lastmon,$lvl,$spec_ma;
  $btlstr.="$who";$xm=0;
  $hit=rand(1,100);
  if($chit>$hit){
    $cdam_m=pow(1.2,($sp-round($ap+$am/5))); //round total AC
    if($dt==8){
      $damage=round(rand($ntl/10,$ntl)*$cdam_m);
      $damage=min($ntl-$hp,max(1,$damage));
      if($damage>0){
  $btlstr.="h,$damage,";
      }else{
  $btlstr.="y,";
      }
    }else{
      $damage=round(rand($ntl/7,$ntl/1.4)*$cdam_m);
      if($who=='u' && $lastmon==999){
  $damage=round(2*$damage/$lvl)+15000;
      }
      $chance_crit=rand(1,20+$sm/10);
      if($chance_crit>19){
  $damage=round($damage*4.5);
  $damage=max(1,min($hp,$damage));
  $btlstr.="sc$dt,$damage,";
      }else{
  $damage=max(1,min($hp,$damage));
  $btlstr.="s$dt,$damage,";
      }
    }
    $masteryChance = 2;
    if ($damage == $hp){
      $masteryChance += $spec_ma;
    }
    if($who=='u' && $sm<$sm_max && $lastmon!=1000){
      if(rand(1,max(20+$sm*50,50))<($masteryChance)){
  ++$xm;
  print "mX(15);";
      }
    }else if($who=='e' && $am<$am_max && $lastmon!=1000){
      if(rand(1,max(20+$am*50,50))<($masteryChance)){
  ++$xm;
  print "mX(17);";
      }
    }
  }else{
    $btlstr.="t,";
  }
  return $xm;
}
function gemboost($c1){
  if($c1==1)
    return 1.05;
  if($c1==2)
    return 1.1;
  if($c1==3)
    return 1.2;
  if($c1==4)
    return 1.35;
  return 1;
}
function gemdrain($c1){
  if($c1==1)
    return 0.95;
  if($c1==2)
    return 0.9;
  if($c1==3)
    return 0.8;
  if($c1==4)
    return 0.65;
  return 1;
}
function gemsteal($c1){
  if($c1==1)
    return 0.04;
  if($c1==2)
    return 0.08;
  if($c1==3)
    return 0.16;
  if($c1==4)
    return 0.32;
  return 0;
}
function gemclass($c1){
  if($c1==1)
    return 1;
  if($c1==2)
    return 2;
  if($c1==3)
    return 4;
  if($c1==4)
    return 6;
  return 0;
}
function gemgold($c1){
  if($c1==1)
    return 0.01;
  if($c1==2)
    return 0.02;
  if($c1==3)
    return 0.05;
  if($c1==4)
    return 0.1;
  return 0;
}

function getRndSeq() {
	$macroSend=array("a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"," ","!","?","|","-","=");
  shuffle($macroSend);
  $rand_key1=array_rand($macroSend);
  $randNbr = rand(1,30000);
    
  return str_replace(rand(0,9), $macroSend[$rand_key1], $randNbr);    
}

  $query="Select channels,fire_m,cold_m,air_m,arcane_m,sword_m,axe_m,staff_m,mace_m,armor_m,double_m,qnum,qhd from Players where Id = $Id";
  $result=mysql_query($query);extract(mysql_fetch_array($result));
  $query="Select clan,race,gold,str,dex,vit,ntl,wis,health,align,opponent,e_health,tef,tfc,tstatus,lvl from Stats where Id = $Id";
  $result=mysql_query($query);extract(mysql_fetch_array($result));
  $race%=100;
  $query="Select * from Inventory where Id = $Id";
  $result=mysql_query($query);extract(mysql_fetch_array($result));
  $invlist=array($i1,$i2,$i3,$i4,$i5,$i6,$i7,$i8,$i9,$i10,$i11,$i12,$i13,$i14,$i15,$i16,$i17,$i18,$i19,$i20,$i21,$i22,$i23,$i24,$i25,$i26,$i27,$i28,$i29,$i30);
  if($qnum !=0){
    $query="Select * from Quests where qnum=$qnum";
    if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
      extract(mysql_fetch_array($result));
    }
  }
  // anti macro: send blank pm
  $macroRand = rand(1,1000);
  // to test
  // $macroRand = 26;
  
  if ($macroRand > 24 && $macroRand < 30) {
  $macroSend=array("a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"," ","!","?","|","+","=");
  shuffle($macroSend);
	$rand_key1=array_rand($macroSend);
	$rand_key2=array_rand($macroSend);
	$rand_key3=array_rand($macroSend);
	
	$pmsender = array($macroSend[$rand_key1],$macroSend[$rand_key3],rand(0,9),$macroSend[$rand_key2]);
	shuffle($pmsender);
	
	$rndSender=$pmsender[0].$pmsender[1].$pmsender[2].$pmsender[3];
	$rndSenderRnd = rand(0,20);
	switch($rndSenderRnd) {
		case 3:
			$rndSender = $pmsender[0].$pmsender[1].$pmsender[2];
			break;
		case 6:
		  $rndSender = $pmsender[0].$pmsender[1];
		  break;
		case 9:
		 $rndSender = $pmsender[0];
		 break;
		case 12:
			$rndSender = $pmsender[0].$pmsender[1].$pmsender[2].$macroSend[array_rand($macroSend)].$pmsender[3];
			break;
		case 15:
			$rndSender = $pmsender[0].$macroSend[array_rand($macroSend)].$pmsender[1].$pmsender[2].$macroSend[array_rand($macroSend)].$pmsender[3];
			break;
		case 18:
			$rndSender = $macroSend[array_rand($macroSend)].$pmsender[0].$macroSend[array_rand($macroSend)].$pmsender[1].$pmsender[2].$macroSend[array_rand($macroSend)].$pmsender[3];
			break;
	}

  switch($macroRand) {
  	case 25:
  		$query="Insert into Messages values($Id,'".$rndSender."','".mt_rand()."',5,now())";
    	mysql_query($query);
  		break;
  	case 26:
  		$query="Insert into Messages values($Id,'".$rndSender."','".getRndSeq()." ".getRndSeq()."',5,now())";
    	mysql_query($query);
  		break;
  	case 27:
  		$query="Insert into Messages values($Id,'".$rndSender."','".getRndSeq()." ".getRndSeq()." ".getRndSeq()."',5,now())";
    	mysql_query($query);
  		break;
  	case 28:
  		$query="Insert into Messages values($Id,'".$rndSender."','".getRndSeq()." ".getRndSeq()." ".getRndSeq()." ".getRndSeq()."',5,now())";
    	mysql_query($query);
  		break;
  	case 29:
  		$query="Insert into Messages values($Id,'".$rndSender."','".getRndSeq()." ".getRndSeq()." ".getRndSeq()." ".getRndSeq()." ".getRndSeq()."',5,now())";
    	mysql_query($query);
  		break;
  	}
  }
  		
  if($clan>1){
    include "clan1.inc";
  }
  $query="Select * from Zones where znum=$loc_zone";
  $result=mysql_query($query);
  extract(mysql_fetch_array($result));
  $stuff_here=0;
  include "tele.inc";
  if($lastmon==1000){
    include "pvp2.inc";
  }else if($lastmon==999){
    include "hunt1.inc";
  }
  $bdelay=60;$duel_error=0;
  $gems=array(0,0,0,0,0,0,0,0,0,0);
  if($aika<3){
    $bdelay=100;
  }else if($health<=0){
     $btlstr.="vd,";
     debugText("Ghosts cant fight : ".$pname);
  }else if($stuff_here>0){
     $btlstr.="vn,";
     $duel_error=1;
  }else if($lastmon<1000 && $e_health==0){
     $btlstr.="vx,";
  }else if($lastmon==1000 && ($channels!=20 && $channels!=12) && ($loc_zone<9|| $loc_zone==12|| $loc_zone==45|| $loc_zone==15|| $loc_zone==21|| $loc_zone==24|| $loc_zone==25|| $loc_zone==26|| $loc_zone==34)){
    $btlstr.="vm,";
    $duel_error=1;
  }else if($lastmon==1000 && $tgt_health<=0){
    $btlstr.="vz,";
    $duel_error=1;
  }else if($lastmon==1000 && $pkd<600 && $loc_zone!=40){
    $pkt=600-$pkd;
    $btlstr.="vp$pkt,";
    $duel_error=1;
  }else if($lastmon==1000 && ($loc_x !=$tgt_loc_x|| $loc_y !=$tgt_loc_y|| $loc_zone !=$tgt_loc_zone)){
    $btlstr.="vt,";
    $duel_error=1;
  }else{
    $query="Select fire_max,cold_max,air_max,arcane_max,sword_max,axe_max,staff_max,mace_max,armor_max from Races where rid=$race";
    $result=mysql_query($query);
    extract(mysql_fetch_array($result));
    $tgt_mastery1=0;$tgt_mastery2=0;$tgt_mastery3=0;$tgt_mastery4=0;$tgt_mastery5=0;
    $initb=0;$tgt_initb=0;
    if($lastmon<1000){
      include "pvm1.inc";
    }else{
      include "pvp3.inc";
    }
  $mastery1=0;$mastery2=0;$mastery3=0;$mastery4=0;$mastery5=0;
  $m_max1=0;$m_max2=0;$m_max3=0;$m_max4=0;
  $gold_bonus=0;$exp_bonus=0;$death_gold=1;$death_exp=0.2;
  $tgt_death_exp=0.2;$tgt_death_gold=1;$tgt_acc_num=0;
  if($armor !=0){
    $def=ityper($invlist[$armor-1]);
    $armor_num=inumer($invlist[$armor-1]);
    $mastery5=&$armor_m;$m_max5=$armor_max;
    if($def==29){
      $health=min($vit,$health+round($vit*(0.04+$armor_num/125)));
    }
  }else{
    $def=0;$armor_num=1;
  }
  if($rhand !=0 && $lhand !=0){
    $wep=ityper($invlist[$rhand-1]);         //WeaponType
    $wep_num=inumer($invlist[$rhand-1]);     //WeaponClass
    $wep2=ityper($invlist[$lhand-1]);
    $wep2_num=inumer($invlist[$lhand-1]);
  }else if($rhand !=0 && $lhand==0){
    $wep=ityper($invlist[$rhand-1]);
    $wep_num=inumer($invlist[$rhand-1])+6;
    $wep2=0;$wep2_num=1;
  }else if($rhand==0 && $lhand !=0){
    $wep=ityper($invlist[$lhand-1]);
    $wep_num=inumer($invlist[$lhand-1])+6;
    $wep2=0;$wep2_num=1;
  }else{
    $wep=9;$wep_num=1;
    $wep2=9;$wep2_num=1;
  }
  if(($wep%10)==1){
    $mastery1=&$sword_m;$m_max1=$sword_max;
    if($wep==21){
      $dex*=(1.04+$wep_num/125);
      $tgt_ntl/=(1.02+$wep_num/250);
    }
  }else if(($wep%10)==2){
    $mastery1=&$axe_m;$m_max1=$axe_max;
    if($wep==22){
      $dex*=(1.04+$wep_num/125);
      $str*=(1.02+$wep_num/250);
    }
  }else if(($wep%10)==3){
    $mastery1=&$staff_m;$m_max1=$staff_max;
    if($wep==23){
      $dex*=(1.04+$wep_num/125);
      $gold_bonus+=0.05*(($wep_num+5)/5);      //changed to Gold Bonus
//      $ntl*=(1.03+$wep_num/167);
    }
  }else if(($wep%10)==4){
    $mastery1=&$mace_m;$m_max1=$mace_max;
    if($wep==24){
      $dex*=(1.04+$wep_num/125);
      $tgt_dex/=(1.02+$wep_num/250);
    }
  }
  if(($wep2%10)==1){
    $mastery2=&$sword_m;$m_max2=$sword_max;
    if($wep2==21){
      $dex*=(1.04+$wep2_num/125);
      $tgt_ntl/=(1.02+$wep2_num/250);
    }
  }else if(($wep2%10)==2){
    $mastery2=&$axe_m;$m_max2=$axe_max;
    if($wep2==22){
      $dex*=(1.04+$wep2_num/125);
      $str*=(1.02+$wep2_num/250);
    }
  }else if(($wep2%10)==3){
    $mastery2=&$staff_m;$m_max2=$staff_max;
    if($wep2==23){
      $dex*=(1.04+$wep2_num/125);
      $gold_bonus+=0.05*(($wep_num+5)/5);      //changed to Gold Bonus
      //      $ntl*=(1.03+$wep2_num/167);
    }
  }else if(($wep2%10)==4){
    $mastery2=&$mace_m;$m_max2=$mace_max;
    if($wep2==24){
      $dex*=(1.04+$wep2_num/125);
      $tgt_dex/=(1.02+$wep2_num/250);
    }
  }
  if($spellone !=0 && $spelltwo !=0){
    $spell=ityper($invlist[$spellone-1]);
    $spell_num=inumer($invlist[$spellone-1]);
    $spell2=ityper($invlist[$spelltwo-1]);
    $spell2_num=inumer($invlist[$spelltwo-1]);
  }else if($spellone !=0 && $spelltwo==0){
    $spell=ityper($invlist[$spellone-1]);
    $spell_num=inumer($invlist[$spellone-1])+6;
    $spell2=0;$spell2_num=1;
  }else if($spellone==0 && $spelltwo !=0){
    $spell=ityper($invlist[$spelltwo-1]);
    $spell_num=inumer($invlist[$spelltwo-1])+6;
    $spell2=0;$spell2_num=1;
  }else{
    $spell=9;$spell_num=1;
    $spell2=9;$spell2_num=1;
  }
  if(($spell%10)==5){
    $mastery3=&$fire_m;$m_max3=$fire_max;
    if($spell==25){
      $wis*=(1.04+$spell_num/125);
      $tgt_wis/=(1.02+$tgt_spell_num/250);
    }
  }else if(($spell%10)==6){
    $mastery3=&$cold_m;$m_max3=$cold_max;
    if($spell==26){
      $wis*=(1.04+$spell_num/125);
      $ntl*=(1.02+$spell_num/250);
    }
  }else if(($spell%10)==7){
    $mastery3=&$air_m;$m_max3=$air_max;
    if($spell==27){
      $wis*=(1.04+$spell_num/125);
      $tgt_str/=(1.02+$spell_num/250);
    }
  }else if(($spell%10)==8){
    $mastery3=&$arcane_m;$m_max3=$arcane_max;
    if($spell==28){
      $wis*=(1.04+$spell_num/125);
      $armor_num+=round(($spell_num+5)/5);
    }
  }
  if(($spell2%10)==5){
    $mastery4=&$fire_m;$m_max4=$fire_max;
    if($spell2==25){
      $wis*=(1.04+$spell2_num/125);
      $tgt_wis/=(1.02+$tgt_spell_num/250);
    }
  }else if(($spell2%10)==6){
    $mastery4=&$cold_m;$m_max4=$cold_max;
    if($spell2==26){
      $wis*=(1.04+$spell2_num/125);
      $ntl*=(1.02+$spell2_num/250);
    }
  }else if(($spell2%10)==7){
    $mastery4=&$air_m;$m_max4=$air_max;
    if($spell2==27){
      $wis*=(1.04+$spell2_num/125);
      $tgt_str/=(1.02+$spell2_num/250);
    }
  }else if(($spell2%10)==8){
    $mastery4=&$arcane_m;$m_max4=$arcane_max;
    if($spell2==28){
      $wis*=(1.04+$spell2_num/125);
      $armor_num+=round(($spell2_num+5)/5);
    }
  }
  if($rhand !=0){
    $gems[0]=$invlist[$rhand-1]%100;
    $gems[5]=(($invlist[$rhand-1]%10000)-$gems[0])/100;
  }
  if($lhand !=0){
    $gems[1]=$invlist[$lhand-1]%100;
    $gems[6]=(($invlist[$lhand-1]%10000)-$gems[1])/100;
  }
  if($armor !=0){
    $gems[2]=$invlist[$armor-1]%100;
    $gems[7]=(($invlist[$armor-1]%10000)-$gems[2])/100;
  }
  if($spellone !=0){
    $gems[3]=$invlist[$spellone-1]%100;
    $gems[8]=(($invlist[$spellone-1]%10000)-$gems[3])/100;
  }
  if($spelltwo !=0){
    $gems[4]=$invlist[$spelltwo-1]%100;
    $gems[9]=(($invlist[$spelltwo-1]%10000)-$gems[4])/100;
  }
  for($i=0;$i<10;++$i){
    $gx=$gems[$i]%25;
    $gz=($gems[$i]-$gx)/25+1;
    switch($gx){
    case 1:
      $str=round($str*gemboost($gz));
    break;
    case 2:
      $dex=round($dex*gemboost($gz));
    break;
    case 3:
      $health=min($vit,$health+round($vit*(gemboost($gz)-1)));
    break;
    case 4:
      $ntl=round($ntl*gemboost($gz));
    break;
    case 5:
      $wis=round($wis*gemboost($gz));
    break;
    case 6:
      $tgt_str=round($tgt_str*gemdrain($gz));
    break;
    case 7:
      $tgt_dex=round($tgt_dex*gemdrain($gz));
    break;
    case 8:
      $drain=round(min($health,$e_health)*(1.1-gemdrain($gz)));
      $e_health-=$drain;
    break;
    case 9:
      $tgt_ntl=round($tgt_ntl*gemdrain($gz));
    break;
    case 10:
      $tgt_wis=round($tgt_wis*gemdrain($gz));
    break;
    case 11:
      $steal=min($str,$tgt_str)*gemsteal($gz);
      $str+=$steal;$tgt_str=max(1,$tgt_str-$steal);
    break;
    case 12:
      $steal=min($dex,$tgt_dex)*gemsteal($gz);
      $dex+=$steal;$tgt_dex=max(1,$tgt_dex-$steal);
    break;
    case 13:
      $steal=min($health,$e_health)*gemsteal($gz);
      $health=round(min($vit,$health+$steal));$e_health=round(max(1,$e_health-$steal));
    break;
    case 14:
      $steal=min($ntl,$tgt_ntl)*gemsteal($gz);
      $ntl+=$steal;$tgt_ntl=max(1,$tgt_ntl-$steal);
    break;
    case 15:
      $steal=min($wis,$tgt_wis)*gemsteal($gz);
      $wis+=$steal;$tgt_wis=max(1,$tgt_wis-$steal);
    break;
    case 16:
      $wep_num+=gemclass($gz);
      $wep2_num+=gemclass($gz);
    break;
    case 17:
      $spell_num+=gemclass($gz);
      $spell2_num+=gemclass($gz);
    break;
    case 18:
      $armor_num+=gemclass($gz);
    break;
    case 19:
      $gold_bonus+=gemgold($gz)*5;
    break;
    case 20:
      $exp_bonus+=gemgold($gz)*2;
    break;
    case 21:
      $initb+=gemgold(gz)*5;
    break;
    }
  }
  $tgt_chance_hit=0;             //init chance to hit to manipulate by shields and wis
  $tgt_chance_spell=0;
  $tgt_chance_hit2=0;
  $tgt_chance_spell2=0;
  $chance_hit=0;
  $chance_spell=0;
  $chance_hit2=0;
  $chance_spell2=0;

  if($wep==10|| $wep==20|| $wep==30){
    $armor_num+=$wep_num/10;           //round deleted
    $tgt_chance_hit-=$wep_num/6;
    $tgt_chance_hit2-=$wep_num/6;
    $tgt_chance_spell-=$wep_num/6;
    $tgt_chance_spell2-=$wep_num/6;
    if($wep==30){
      $armor_num += ($wep_num+5)/10;
      $wep_num-=5;
      $mastery1=&$armor_m;$m_max1=$armor_max;
    }else{
      $wep=0;$wep_num=0;
    }
  }
  if($wep2==10|| $wep2==20|| $wep2==30){
    $armor_num+=$wep2_num/10;          // round deleted
    $tgt_chance_hit-=$wep2_num/6;
    $tgt_chance_hit2-=$wep2_num/6;
    $tgt_chance_spell-=$wep2_num/6;
    $tgt_chance_spell2-=$wep2_num/6;
    if($wep2==30){
      $armor_num += ($wep2_num+5)/10;
      $wep2_num-=5;
      $mastery2=&$armor_m;$m_max2=$armor_max;
    }else{
      $wep2=0;$wep2_num=0;
    }
  }
  if($lastmon==1000 && $duel_error==0){
    if($tgt_wep==10|| $tgt_wep==20|| $tgt_wep==30){
      $tgt_armor_num+=$tgt_wep_num/10;        // round deleted
      $chance_hit-=$tgt_wep_num/6;
      $chance_hit2-=$tgt_wep_num/6;
      $chance_spell-=$tgt_wep_num/6;
      $chance_spell2-=$tgt_wep_num/6;
      if($tgt_wep==30){
        $tgt_armor_num += ($tgt_wep_num+5)/10;
        $tgt_wep_num-=5;
        $tgt_mastery1=&$armor_m;$tgt_m_max1=$armor_max;
      }else{
        $tgt_wep=0;$tgt_wep_num=0;
      }
    }
    if($tgt_wep2==10|| $tgt_wep2==20|| $tgt_wep2==30){
      $tgt_armor_num+=$tgt_wep2_num/10;       // round deleted
      $chance_hit-=$tgt_wep2_num/6;
      $chance_hit2-=$tgt_wep2_num/6;
      $chance_spell-=$tgt_wep2_num/6;
      $chance_spell2-=$tgt_wep2_num/6;
      if($tgt_wep2==30){
        $tgt_armor_num += ($tgt_wep2_num+5)/10;
        $tgt_wep2_num-=5;
        $tgt_mastery2=&$armor_m;$tgt_m_max2=$armor_max;
      }else{
        $tgt_wep2=0;$tgt_wep2_num=0;
      }
    }
  }
  $chance_hit+=$dex/$tgt_dex*55*(1+$mastery1/100);
  $chance_spell+=$wis/$tgt_wis*50*(1+$mastery3/100);
  $chance_hit2+=$dex/$tgt_dex*55*(1+$mastery2/100);
  $chance_spell2+=$wis/$tgt_wis*50*(1+$mastery4/100);
  if($lastmon<1000){
    $tgt_chance_spell+=$tgt_wis/$wis*50;$tgt_chance_hit=$tgt_dex/$dex*55;
    $tgt_chance_spell2+=$tgt_wis/$wis*50;$tgt_chance_hit2=$tgt_dex/$dex*55;
  }else{
    $tgt_chance_hit+=$tgt_dex/$dex*55*(1+$tgt_mastery1/100);
    $tgt_chance_spell+=$tgt_wis/$wis*50*(1+$tgt_mastery3/100);
    $tgt_chance_hit2+=$tgt_dex/$dex*55*(1+$tgt_mastery2/100);
    $tgt_chance_spell2+=$tgt_wis/$wis*50*(1+$tgt_mastery4/100);
  }
  if($accx !=0){
    $acc_num=inumer($invlist[$accx-1]);
    switch($acc_num){
    case 0:
      $str+=2000;
    break;
    case 1:
      $ntl+=2000;
    break;
    case 2:
      $wis+=2000;
    break;
    case 3:
      $dex+=2000;
    break;
    case 4:
      $vit+=1000;$health+=1000;
    break;
    case 6:
      $tgt_chance_hit*=0.8;
      $tgt_chance_hit2*=0.8;
    break;
    case 7:
      if(($tgt_spell%10)==5)
        $tgt_chance_spell*=0.5;
      if(($tgt_spell2%10)==5)
        $tgt_chance_spell2*=0.5;
    break;
    case 8:
      if(($tgt_spell%10)==6)
        $tgt_chance_spell*=0.5;
      if(($tgt_spell2%10)==6)
        $tgt_chance_spell2*=0.5;
    break;
    case 9:
      if(($tgt_spell%10)==7)
        $tgt_chance_spell*=0.5;
      if(($tgt_spell2%10)==7)
        $tgt_chance_spell2*=0.5;
    break;
    case 10:
      $vit+=3000;$health+=3000;
    break;
    case 11:
      if(($spell%10)==8)
        $chance_spell*=2;
      if(($spell2%10)==8)
        $chance_spell2*=2;
    break;
    case 12:
      $chance_spell*=1.5;
      $chance_spell*=1.5;
    break;
    case 13:
      $ntl+=6000;
    break;
    case 14:
      $m_max1+=10;$m_max2+=10;$m_max3+=10;$m_max4+=10;$m_max5+=10;
    break;
    case 15:
      $chance_hit*=1.5;
      $chance_hit2*=1.5;
    break;
    case 16:
      $str+=6000;
    break;
    case 19:
      $exp_bonus+=0.2;
    break;
    case 20:
      $drop_bonus+=2;
    break;
    case 22:
      $death_gold=0.1;
    break;
    case 23:
      $death_exp=0.05;
    break;
    case 25:
      $str+=10000;$ntl+=10000;$dex+=10000;$wis+=10000;$vit+=10000;$health+=10000;
      $m_max1+=20;$m_max2+=20;$m_max3+=20;$m_max4+=20;$m_max5+=20;
    break;
    }
  }
  if($lastmon<1000){
    include "pvm3.inc";
  }else{
    include "pvp4.inc";
  }
    if($action=="f" && $tgt_action=="f"){
      include "ff.inc";
    }else if($action=="c" && $tgt_action=="c"){
      include "cc.inc";
    }else if($action=="f" && $tgt_action=="c"){
      include "fc.inc";
    }else if($action=="c" && $tgt_action=="f"){
      include "cf.inc";
    }
  if($lastmon<1000){
    include "pvm4.inc";
  }else{
    include "pvp5.inc";
  }
  if($health<=0){
    if($loc_zone!=40){
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
    $exp=max($exp-round($nxlvl*$death_exp),0);
    if($lastmon==1000 && $duel_error==0){
      $tgt_gold+=($gold*$death_gold);
      $lostGold =($gold*$death_gold);
    }
    $gold-=($gold*$death_gold);
    }
    $btlstr.="r,";
  }
  if ($lvl >= 25) 
  {
  	$query="Update Players set sword_m=$sword_m,axe_m=$axe_m,staff_m=$staff_m,mace_m=$mace_m,armor_m=$armor_m,double_m=$double_m,fire_m=$fire_m,cold_m=$cold_m,air_m=$air_m,arcane_m=$arcane_m where Id = $Id";
  	mysql_query($query);
	}
  if($acc_num==4){
    $vit-=1000;
  }else if($acc_num==10){
    $vit-=3000;
  }else if($acc_num==25){
    $vit-=10000;
  }
  $health=min($vit,$health);
  $health=max(0,$health);
  $e_health=max($e_health,0);
  if($lastmon<1000){
    $query="Update Stats set exp=$exp,health=$health,e_health=$e_health,gold=$gold,fight_time=now() where Id = $Id";
    mysql_query($query);
    $query="Update Players set ax_time=now() where Id = $Id";
    mysql_query($query);
  }else{
   	$query="Update Stats set exp=$exp,health=$health,gold=$gold,fight_time=now(),e_health=0 where Id = $Id";
    mysql_query($query);
    $query="Update Players set ax_time=now() where Id = $Id";
    mysql_query($query);
  }
  if($lastmon==999){
    if($e_health>0){
      $btlstr.="b,$e_health,";
    }
    $query="Update Hunts set health=$e_health where bzone=$loc_zone";
    mysql_query($query);
  }
  if($lastmon==1000 && $duel_error==0){
    include "pvp6.inc";
  }
}
?>
