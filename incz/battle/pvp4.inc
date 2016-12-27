<?php
  if($tgt_accx !=0){
    $tgt_acc_num=inumer($tgt_invlist[$tgt_accx-1]);
    switch($tgt_acc_num){
    case 0:
      $tgt_str+=2000;
    break;
    case 1:
      $tgt_ntl+=2000;
    break;
    case 2:
      $tgt_wis+=2000;
    break;
    case 3:
      $tgt_dex+=2000;
    break;
    case 4:
      $tgt_vit+=1000;$e_health+=1000;
    break;
    case 6:
      $chance_hit*=0.8;
      $chance_hit2*=0.8;
    break;
    case 7:
      if(($spell%10)==5)
  $chance_spell*=0.5;
      if(($spell2%10)==5)
  $chance_spell2*=0.5;
    break;
    case 8:
      if(($spell%10)==6)
  $chance_spell*=0.5;
      if(($spell2%10)==6)
  $chance_spell2*=0.5;
    break;
    case 9:
      if(($spell%10)==7)
  $chance_spell*=0.5;
      if(($spell2%10)==7)
  $chance_spell2*=0.5;
    break;
    case 10:
      $tgt_vit+=3000;$e_health+=3000;
    break;
    case 11:
      if(($tgt_spell%10)==8)
  $tgt_chance_spell*=2;
      if(($tgt_spell2%10)==8)
  $tgt_chance_spell2*=2;
    break;
    case 12:
  $tgt_chance_spell*=1.5;
  $tgt_chance_spell2*=1.5;
    break;
    case 13:
      $tgt_ntl+=6000;
    break;
    case 15:
  $tgt_chance_hit*=1.5;
  $tgt_chance_hit2*=1.5;
    break;
    case 16:
      $tgt_str+=6000;
    break;
    case 22:
      $tgt_death_gold=0.1;
    break;
    case 23:
      $tgt_death_exp=0.05;
    break;
    case 25:
      $tgt_str+=10000;$tgt_ntl+=10000;$tgt_dex+=10000;$tgt_wis+=10000;$tgt_vit+=10000;$e_health+=10000;
    break;
    }
  }
  if($tgt_dex>$tgt_wis){
    $tgt_action="f";
  }else{
    $tgt_action="c";
  }
?>