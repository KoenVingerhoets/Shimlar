<?php
      if(($dex*rand(80,100)*(1+$initb))>($tgt_dex*rand(70,90)*(1+$tgt_initb))){
  if($wep !=0){
    $mastery1+=wep_attack("u",($wep%10),$wep_num,$str,$mastery1,$m_max1,$chance_hit,$tgt_armor_num,$e_health,$tgt_mastery5,1);
    $e_health-=$damage;$damage=0;
  }
  if($wep !=0 && $e_health>0 && $double_m>=rand(1,100)){
    $mastery1+=wep_attack("u",($wep%10),$wep_num,$str,$mastery1,$m_max1,$chance_hit,$tgt_armor_num,$e_health,$tgt_mastery5,1);
    $e_health-=$damage;$damage=0;
    if(rand(1,$double_m*100)==11 && $double_m<100 && $lastmon!=1000){
      ++$double_m;
      print "mX(43);";
    }
  }
  if($wep2 !=0 && $e_health>0){
    $mastery2+=wep_attack("u",($wep2%10),$wep2_num,$str,$mastery2,$m_max2,$chance_hit2,$tgt_armor_num,$e_health,$tgt_mastery5,1);
    $e_health-=$damage;$damage=0;
  }
  if($wep2 !=0 && $e_health>0 && $double_m>=rand(1,100)){
    $mastery2+=wep_attack("u",($wep2%10),$wep2_num,$str,$mastery2,$m_max2,$chance_hit2,$tgt_armor_num,$e_health,$tgt_mastery5,1);
    $e_health-=$damage;$damage=0;
    if(rand(1,$double_m*100)==11 && $double_m<100 && $lastmon!=1000){
      ++$double_m;
      print "mX(43);";
    }
  }
  if($tgt_wep !=0 && $e_health>0){
    $mastery5+=wep_attack('e',($tgt_wep%10),$tgt_wep_num,$tgt_str,1,1,$tgt_chance_hit,$armor_num,$health,$mastery5,$m_max5);
    $health-=$damage;$damage=0;
  }
  if($tgt_wep !=0 && $e_health>0 && $health>0 && $tgt_double_m>=rand(1,100)){
    $mastery5+=wep_attack('e',($tgt_wep%10),$tgt_wep_num,$tgt_str,1,1,$tgt_chance_hit,$armor_num,$health,$mastery5,$m_max5);
    $health-=$damage;$damage=0;
  }
  if($tgt_wep2 !=0 && $e_health>0 && $health>0){
    $mastery5+=wep_attack('e',($tgt_wep2%10),$tgt_wep2_num,$tgt_str,1,1,$tgt_chance_hit2,$armor_num,$health,$mastery5,$m_max5);
    $health-=$damage;$damage=0;
  }
  if($tgt_wep2 !=0 && $e_health>0 && $health>0 && $tgt_double_m>=rand(1,100)){
    $mastery5+=wep_attack('e',($tgt_wep2%10),$tgt_wep2_num,$tgt_str,1,1,$tgt_chance_hit2,$armor_num,$health,$mastery5,$m_max5);
    $health-=$damage;$damage=0;
  }
      }else{
  if($tgt_wep !=0){
    $mastery5+=wep_attack('e',($tgt_wep%10),$tgt_wep_num,$tgt_str,1,1,$tgt_chance_hit,$armor_num,$health,$mastery5,$m_max5);
    $health-=$damage;$damage=0;
  }
  if($tgt_wep !=0 && $health>0 && $tgt_double_m>=rand(1,100)){
    $mastery5+=wep_attack('e',($tgt_wep%10),$tgt_wep_num,$tgt_str,1,1,$tgt_chance_hit,$armor_num,$health,$mastery5,$m_max5);
    $health-=$damage;$damage=0;
  }
  if($tgt_wep2 !=0 && $health>0){
    $mastery5+=wep_attack('e',($tgt_wep2%10),$tgt_wep2_num,$tgt_str,1,1,$tgt_chance_hit2,$armor_num,$health,$mastery5,$m_max5);
    $health-=$damage;$damage=0;
  }
  if($tgt_wep2 !=0 && $health>0 && $tgt_double_m>=rand(1,100)){
    $mastery5+=wep_attack('e',($tgt_wep2%10),$tgt_wep2_num,$tgt_str,1,1,$tgt_chance_hit2,$armor_num,$health,$mastery5,$m_max5);
    $health-=$damage;$damage=0;
  }
  if($wep !=0 && $health>0){
    $mastery1+=wep_attack("u",($wep%10),$wep_num,$str,$mastery1,$m_max1,$chance_hit,$tgt_armor_num,$e_health,$tgt_mastery5,1);
    $e_health-=$damage;$damage=0;
  }
  if($wep !=0 && $health>0 && $e_health>0 && $double_m>=rand(1,100)){
    $mastery1+=wep_attack("u",($wep%10),$wep_num,$str,$mastery1,$m_max1,$chance_hit,$tgt_armor_num,$e_health,$tgt_mastery5,1);
    $e_health-=$damage;$damage=0;
    if(rand(1,$double_m*100)==11 && $double_m<100 && $lastmon!=1000){
      ++$double_m;
      print "mX(43);";
    }
  }
  if($wep2 !=0 && $e_health>0 && $health>0){
    $mastery2+=wep_attack("u",($wep2%10),$wep2_num,$str,$mastery2,$m_max2,$chance_hit2,$tgt_armor_num,$e_health,$tgt_mastery5,1);
    $e_health-=$damage;$damage=0;
  }
  if($wep2 !=0 && $health>0 && $e_health>0 && $double_m>=rand(1,100)){
    $mastery2+=wep_attack("u",($wep2%10),$wep2_num,$str,$mastery2,$m_max2,$chance_hit2,$tgt_armor_num,$e_health,$tgt_mastery5,1);
    $e_health-=$damage;$damage=0;
    if(rand(1,$double_m*100)==11 && $double_m<100 && $lastmon!=1000){
      ++$double_m;
      print "mX(43);";
    }
  }
}
?>
