<?php
      $spec_exp=1;$spec_stat=1;$spec_gold=1;$spec_wc=0;$spec_ac=0;$spec_align=0;$spec_brutal=0;$spec_axx=1;
    if($lastmon !=999){
      if($lastmon>200 && $lastmon<220){
        $lastmone=($lastmon%20)+rand(1,14)*20;
      }else{
        $lastmone=$lastmon;
      }
      $lastmonx=$lastmone % 20;
      //$lastmone=max(0,round(($lastmone-10)/20));
      $lastmone = ($lastmone - $lastmonx)/20;
      switch($lastmone){
      case 0:
      break;
      case 1:
        $spec_gold=4;
      break;
      case 2:
        $spec_stat=2;$spec_exp=4;$spec_gold=2;$spec_ac=1;$spec_wc=1;$spec_brutal=2;
      break;
      case 3:
        $spec_stat=3;$spec_exp=2;$spec_wc=1;
      break;
      case 4:
        $spec_exp=2;$spec_gold=3;$drop_bonus+=16;$spec_brutal=2;
      break;
      case 5:
        $spec_exp=2;$spec_gold=0;$spec_wc=-1;$spec_ac=-1;$spec_axx=2;
      break;
      case 6:
        $spec_exp=3;$spec_gold=2;$spec_ac=3;
      break;
      case 7:
        $spec_exp=2;$spec_gold=3;$spec_wc=3;
      break;
      case 8:
        $spec_exp=2;$spec_gold=2;
      break;
      case 9:
        $spec_gold=2;$spec_ma=8;$spec_brutal=2;
      break;
      case 10:
      	$spec_stat=3;$spec_wc=3;$spec_ac=3;
      	break;
      case 11:
      	$spec_axx=2;$spec_gold=3;$drop_bonus+=5;$spec_stat=3;
      	break;
      case 12: 
      	$spec_brutal=3;$spec_exp=2;$spec_stat=2;
      	break;
      case 13:
      	$spec_align=-1; $spec_exp=2;
      	break;
      case 14:
      	$spec_align=1; $spec_gold=2;      	
      	break;
      default:
        $lastmonx=0;
      break;
      }
      $tgt_vit=round($zbase_stats*pow(1.5,(int)$lastmonx)*$spec_stat*(rand(950,1050)/1000));
      $tgt_str=$tgt_vit;$tgt_dex=$tgt_vit;$tgt_ntl=$tgt_vit;$tgt_wis=$tgt_vit;
      $tgt_wep_num=$zbase_eq+$lastmonx+$spec_wc;$tgt_armor_num=$zbase_eq+$lastmonx+$spec_ac;
      $tgt_spell_num=$tgt_wep_num;$tgt_wep2_num=$tgt_wep_num;$tgt_spell2_num=$tgt_spell_num;
      $tgt_wep=(($loc_zone+$lastmon)%4)+1;$tgt_wep2=(($loc_zone+$lastmon+2)%4)+1;$tgt_armor=10;
      $tgt_spell=(($loc_zone+$lastmon)%4)+5;$tgt_spell2=(($loc_zone+$lastmon+2)%4)+5;
      if($e_health==-1){
        $e_health=$tgt_vit;
      }
    }
  switch($tef){
  case 1:
    $dex*=1.2;
  break;
  case 2:
    $str*=1.2;
  break;
  case 3:
    $wis*=1.2;
  break;
  case 4:
    $ntl*=1.2;
  break;
  case 5:
    $health=min($vit,round($health*1.2));
  break;
  case 6:
    $str*=1.2;$dex*=1.2;
    $wis*=1.2;$ntl*=1.2;
    $health=min($vit,$health*1.2);
  break;
  }
?>