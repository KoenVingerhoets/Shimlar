<?php
  $e_health=$tgt_health;
  if($tgt_armor !=0){
    $tgt_def=ityper($tgt_invlist[$tgt_armor-1]);
    $tgt_armor_num=inumer($tgt_invlist[$tgt_armor-1]);
    $tgt_mastery5=&$tgt_armor_m;
    if($tgt_def==29){
      $e_health=min($tgt_vit,$e_health+round($tgt_vit*(0.04+$tgt_armor_num/125)));
    }
  }else{
    $tgt_def=0;$tgt_armor_num=0;
  }
  if($tgt_rhand !=0 && $tgt_lhand !=0){
    $tgt_wep=ityper($tgt_invlist[$tgt_rhand-1]);
    $tgt_wep_num=inumer($tgt_invlist[$tgt_rhand-1]);
    $tgt_wep2=ityper($tgt_invlist[$tgt_lhand-1]);
    $tgt_wep2_num=inumer($tgt_invlist[$tgt_lhand-1]);
  }else if($tgt_rhand !=0 && $tgt_lhand==0){
    $tgt_wep=ityper($tgt_invlist[$tgt_rhand-1]);
    $tgt_wep_num=inumer($tgt_invlist[$tgt_rhand-1])+6;
    $tgt_wep2=0;$tgt_wep2_num=1;
  }else if($tgt_rhand==0 && $tgt_lhand !=0){
    $tgt_wep=ityper($tgt_invlist[$tgt_lhand-1]);
    $tgt_wep_num=inumer($tgt_invlist[$tgt_lhand-1])+6;
    $tgt_wep2=0;$tgt_wep2_num=1;
  }else{
    $tgt_wep=9;$tgt_wep_num=1;
    $tgt_wep2=9;$tgt_wep2_num=1;
  }
  if(($tgt_wep%10)==1){
    $tgt_mastery1=&$tgt_sword_m;
    if($tgt_wep==21){
      $tgt_dex*=(1.04+$tgt_wep_num/125);
      $ntl/=(1.02+$tgt_wep_num/250);
    }
  }else if(($tgt_wep%10)==2){
    $tgt_mastery1=&$tgt_axe_m;
    if($tgt_wep==22){
      $tgt_dex*=(1.04+$tgt_wep_num/125);
      $tgt_str*=(1.02+$tgt_wep_num/250);
    }
  }else if(($tgt_wep%10)==3){
    $tgt_mastery1=&$tgt_staff_m;
    if($tgt_wep==23){
      $tgt_dex*=(1.04+$tgt_wep_num/125);
    }
  }else if(($tgt_wep%10)==4){
    $tgt_mastery1=&$tgt_mace_m;
    if($tgt_wep==24){
      $tgt_dex*=(1.04+$tgt_wep_num/125);
      $dex/=(1.02+$tgt_wep_num/250);
    }
  }
  if(($tgt_wep2%10)==1){
    $tgt_mastery2=&$tgt_sword_m;
    if($tgt_wep2==21){
      $tgt_dex*=(1.04+$tgt_wep2_num/125);
      $ntl/=(1.02+$tgt_wep2_num/250);
    }
  }else if(($tgt_wep2%10)==2){
    $tgt_mastery2=&$tgt_axe_m;
    if($tgt_wep2==22){
      $tgt_dex*=(1.04+$tgt_wep2_num/125);
      $tgt_str*=(1.02+$tgt_wep2_num/250);
    }
  }else if(($tgt_wep2%10)==3){
    $tgt_mastery2=&$tgt_staff_m;
    if($tgt_wep2==23){
      $tgt_dex*=(1.04+$tgt_wep2_num/125);
    }
  }else if(($tgt_wep2%10)==4){
    $tgt_mastery2=&$tgt_mace_m;
    if($tgt_wep2==24){
      $tgt_dex*=(1.04+$tgt_wep2_num/125);
      $dex/=(1.02+$tgt_wep2_num/250);
    }
  }
  if($tgt_spellone !=0 && $tgt_spelltwo !=0){
    $tgt_spell=ityper($tgt_invlist[$tgt_spellone-1]);
    $tgt_spell_num=inumer($tgt_invlist[$tgt_spellone-1]);
    $tgt_spell2=ityper($tgt_invlist[$tgt_spelltwo-1]);
    $tgt_spell2_num=inumer($tgt_invlist[$tgt_spelltwo-1]);
  }else if($tgt_spellone !=0 && $tgt_spelltwo==0){
    $tgt_spell=ityper($tgt_invlist[$tgt_spellone-1]);
    $tgt_spell_num=inumer($tgt_invlist[$tgt_spellone-1])+6;
    $tgt_spell2=0;$tgt_spell2_num=1;
  }else if($tgt_spellone==0 && $tgt_spelltwo !=0){
    $tgt_spell=ityper($tgt_invlist[$tgt_spelltwo-1]);
    $tgt_spell_num=inumer($tgt_invlist[$tgt_spelltwo-1])+6;
    $tgt_spell2=0;$tgt_spell2_num=1;
  }else{
    $tgt_spell=9;$tgt_spell_num=1;
    $tgt_spell2=9;$tgt_spell2_num=1;
  }
  if(($tgt_spell%10)==5){
    $tgt_mastery3=&$tgt_fire_m;
    if($tgt_spell==25){
      $tgt_wis*=(1.04+$tgt_spell_num/125);
      $wis/=(1.02+$tgt_spell_num/250);
    }
  }else if(($tgt_spell%10)==6){
    $tgt_mastery3=&$tgt_cold_m;
    if($tgt_spell==26){
      $tgt_wis*=(1.04+$tgt_spell_num/125);
      $tgt_ntl*=(1.02+$tgt_spell_num/250);
    }
  }else if(($tgt_spell%10)==7){
    $tgt_mastery3=&$tgt_air_m;
    if($tgt_spell==27){
      $tgt_wis*=(1.04+$tgt_spell_num/125);
      $str/=(1.02+$tgt_spell_num/250);
    }
  }else if(($tgt_spell%10)==8){
    $tgt_mastery3=&$tgt_arcane_m;
    if($tgt_spell==28){
      $tgt_wis*=(1.04+$tgt_spell_num/125);
      $tgt_armor_num+=round(($tgt_spell_num+5)/5);
    }
  }
  if(($tgt_spell2%10)==5){
    $tgt_mastery4=&$tgt_fire_m;
    if($tgt_spell2==25){
      $tgt_wis*=(1.04+$tgt_spell2_num/125);
      $wis/=(1.02+$tgt_spell_num/250);
    }
  }else if(($tgt_spell2%10)==6){
    $tgt_mastery4=&$tgt_cold_m;
    if($tgt_spell2==26){
      $tgt_wis*=(1.04+$tgt_spell2_num/125);
      $tgt_ntl*=(1.02+$tgt_spell2_num/250);
    }
  }else if(($tgt_spell2%10)==7){
    $tgt_mastery4=&$tgt_air_m;
    if($tgt_spell2==27){
      $tgt_wis*=(1.04+$tgt_spell2_num/125);
      $str/=(1.02+$tgt_spell2_num/250);
    }
  }else if(($tgt_spell2%10)==8){
    $tgt_mastery4=&$tgt_arcane_m;
    if($tgt_spell2==28){
      $tgt_wis*=(1.04+$tgt_spell2_num/125);
      $tgt_armor_num+=round(($tgt_spell2_num+5)/5);
    }
  }
  if($tgt_rhand !=0){
    $tgt_gems[0]=$tgt_invlist[$tgt_rhand-1]%100;
    $tgt_gems[5]=(($tgt_invlist[$tgt_rhand-1]%10000)-$tgt_gems[0])/100;
  }
  if($tgt_lhand !=0){
    $tgt_gems[1]=$tgt_invlist[$tgt_lhand-1]%100;
    $tgt_gems[6]=(($tgt_invlist[$tgt_lhand-1]%10000)-$tgt_gems[1])/100;
  }
  if($tgt_armor !=0){
    $tgt_gems[2]=$tgt_invlist[$tgt_armor-1]%100;
    $tgt_gems[7]=(($tgt_invlist[$tgt_armor-1]%10000)-$tgt_gems[2])/100;
  }
  if($tgt_spellone !=0){
    $tgt_gems[3]=$tgt_invlist[$tgt_spellone-1]%100;
    $tgt_gems[8]=(($tgt_invlist[$tgt_spellone-1]%10000)-$tgt_gems[3])/100;
  }
  if($tgt_spelltwo !=0){
    $tgt_gems[4]=$tgt_invlist[$tgt_spelltwo-1]%100;
    $tgt_gems[9]=(($tgt_invlist[$tgt_spelltwo-1]%10000)-$tgt_gems[4])/100;
  }
  for($tgt_i=0;$tgt_i<10;++$tgt_i){
    $tgt_gx=$tgt_gems[$tgt_i]%25;
    $tgt_gz=($tgt_gems[$tgt_i]-$tgt_gx)/25+1;
    switch($tgt_gx){
    case 1:
      $tgt_str=round($tgt_str*gemboost($tgt_gz));
    break;
    case 2:
      $tgt_dex=round($tgt_dex*gemboost($tgt_gz));
    break;
    case 3:
      $e_health=min($tgt_vit,$e_health+round($tgt_vit*(gemboost($tgt_gz)-1)));
    break;
    case 4:
      $tgt_ntl=round($tgt_ntl*gemboost($tgt_gz));
    break;
    case 5:
      $tgt_wis=round($tgt_wis*gemboost($tgt_gz));
    break;
    case 6:
      $str=round($str*gemdrain($tgt_gz));
    break;
    case 7:
      $dex=round($dex*gemdrain($tgt_gz));
    break;
    case 8:
      $drain=round(min($health,$e_health)*(1.1-gemdrain($tgt_gz)));
      $health-=$drain;
    break;
    case 9:
      $ntl=round($ntl*gemdrain($tgt_gz));
    break;
    case 10:
      $wis=round($wis*gemdrain($tgt_gz));
    break;
    case 11:
      $tgt_steal=min($tgt_str,$str)*gemsteal($tgt_gz);
      $tgt_str+=$tgt_steal;$str=max(1,$str-$tgt_steal);
    break;
    case 12:
      $tgt_steal=min($tgt_dex,$dex)*gemsteal($tgt_gz);
      $tgt_dex+=$tgt_steal;$dex=max(1,$dex-$tgt_steal);
    break;
    case 13:
      $tgt_steal=min($e_health,$health)*gemsteal($tgt_gz);
      $e_health=round(min($tgt_vit,$e_health+$tgt_steal));$health=round(max(1,$health-$tgt_steal));
    break;
    case 14:
      $tgt_steal=min($tgt_ntl,$ntl)*gemsteal($tgt_gz);
      $tgt_ntl+=$tgt_steal;$ntl=max(1,$ntl-$tgt_steal);
    break;
    case 15:
      $tgt_steal=min($tgt_wis,$wis)*gemsteal($tgt_gz);
      $tgt_wis+=$tgt_steal;$wis=max(1,$wis-$tgt_steal);
    break;
    case 16:
      $tgt_wep_num+=gemclass($tgt_gz);
      $tgt_wep2_num+=gemclass($tgt_gz);
    break;
    case 17:
      $tgt_spell_num+=gemclass($tgt_gz);
      $tgt_spell2_num+=gemclass($tgt_gz);
    break;
    case 18:
      $tgt_armor_num+=gemclass($tgt_gz);
    break;
    case 21:
      $tgt_initb+=gemgold($tgt_gz)*5;
    break;
    }
  }
?>