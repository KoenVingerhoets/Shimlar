<?php
      if(($wis*rand(80,100)*(1+$initb))>($tgt_wis*rand(70,90)*(1+$tgt_initb))){
  if($spell !=0){
    if($spell%10 !=8){
      $mastery3+=spell_attack("u",($spell%10),$spell_num,$ntl,$mastery3,$m_max3,$chance_spell,$tgt_armor_num,$e_health,$tgt_mastery5,1);
      $e_health-=$damage;$damage=0;
    }else{
      $mastery3+=spell_attack("u",($spell%10),$spell_num,$vit,$mastery3,$m_max3,$chance_spell,$tgt_armor_num,$health,$tgt_mastery5,1);
      $health+=$damage;$damage=0;
    }
  }
  if($spell !=0 && $e_health>0 && $double_m>=rand(1,100)){
    if($spell%10 !=8){
      $mastery3+=spell_attack("u",($spell%10),$spell_num,$ntl,$mastery3,$m_max3,$chance_spell,$tgt_armor_num,$e_health,$tgt_mastery5,1);
      $e_health-=$damage;$damage=0;
    }else{
      $mastery3+=spell_attack("u",($spell%10),$spell_num,$vit,$mastery3,$m_max3,$chance_spell,$tgt_armor_num,$health,$tgt_mastery5,1);
      $health+=$damage;$damage=0;
    }
    if(rand(1,$double_m*100)==11 && $double_m<100 && $lastmon!=1000){
      ++$double_m;
      print "mX(43);";
    }
  }
  if($spell2 !=0 && $e_health>0){
    if($spell2%10 !=8){
      $mastery4+=spell_attack("u",($spell2%10),$spell2_num,$ntl,$mastery4,$m_max4,$chance_spell2,$tgt_armor_num,$e_health,$tgt_mastery5,1);
      $e_health-=$damage;$damage=0;
    }else{
      $mastery4+=spell_attack("u",($spell2%10),$spell2_num,$vit,$mastery4,$m_max4,$chance_spell2,$tgt_armor_num,$health,$tgt_mastery5,1);
      $health+=$damage;$damage=0;
    }
  }
  if($spell2 !=0 && $e_health>0 && $double_m>=rand(1,100)){
    if($spell2%10 !=8){
      $mastery4+=spell_attack("u",($spell2%10),$spell2_num,$ntl,$mastery4,$m_max4,$chance_spell2,$tgt_armor_num,$e_health,$tgt_mastery5,1);
      $e_health-=$damage;$damage=0;
    }else{
      $mastery4+=spell_attack("u",($spell2%10),$spell2_num,$vit,$mastery4,$m_max4,$chance_spell2,$tgt_armor_num,$health,$tgt_mastery5,1);
      $health+=$damage;$damage=0;
    }
    if(rand(1,$double_m*100)==11 && $double_m<100 && $lastmon!=1000){
      ++$double_m;
      print "mX(43);";
    }
  }
  if($tgt_spell !=0 && $e_health>0){
    if($tgt_spell%10 !=8){
      $mastery5+=spell_attack("e",($tgt_spell%10),$tgt_spell_num,$tgt_ntl,1,1,$tgt_chance_spell,$armor_num,$health,$mastery5,$m_max5);
      $health-=$damage;$damage=0;
    }else{
      $mastery5+=spell_attack("e",($tgt_spell%10),$tgt_spell_num,$tgt_vit,1,1,$tgt_chance_spell,$armor_num,$e_health,$mastery5,$m_max5);
      $e_health+=$damage;$damage=0;
    }
  }
  if($tgt_spell !=0 && $e_health>0 && $tgt_double_m>=rand(1,100)){
    if($tgt_spell%10 !=8){
      $mastery5+=spell_attack("e",($tgt_spell%10),$tgt_spell_num,$tgt_ntl,1,1,$tgt_chance_spell,$armor_num,$health,$mastery5,$m_max5);
      $health-=$damage;$damage=0;
    }else{
      $mastery5+=spell_attack("e",($tgt_spell%10),$tgt_spell_num,$tgt_vit,1,1,$tgt_chance_spell,$armor_num,$e_health,$mastery5,$m_max5);
      $e_health+=$damage;$damage=0;
    }
  }
  if($tgt_spell2 !=0 && $e_health>0 && $health>0){
    if($tgt_spell2%10 !=8){
      $mastery5+=spell_attack("e",($tgt_spell2%10),$tgt_spell2_num,$tgt_ntl,1,1,$tgt_chance_spell2,$armor_num,$health,$mastery5,$m_max5);
      $health-=$damage;$damage=0;
    }else{
      $mastery5+=spell_attack("e",($tgt_spell2%10),$tgt_spell2_num,$tgt_vit,1,1,$tgt_chance_spell2,$armor_num,$e_health,$mastery5,$m_max5);
      $e_health+=$damage;$damage=0;
    }
  }
  if($tgt_spell2 !=0 && $e_health>0 && $health>0 && $tgt_double_m>=rand(1,100)){
    if($tgt_spell2%10 !=8){
      $mastery5+=spell_attack("e",($tgt_spell2%10),$tgt_spell2_num,$tgt_ntl,1,1,$tgt_chance_spell2,$armor_num,$health,$mastery5,$m_max5);
      $health-=$damage;$damage=0;
    }else{
      $mastery5+=spell_attack("e",($tgt_spell2%10),$tgt_spell2_num,$tgt_vit,1,1,$tgt_chance_spell2,$armor_num,$e_health,$mastery5,$m_max5);
      $e_health+=$damage;$damage=0;
    }
  }
      }else{
  if($tgt_spell !=0){
    if($tgt_spell%10 !=8){
      $mastery5+=spell_attack("e",($tgt_spell%10),$tgt_spell_num,$tgt_ntl,1,1,$tgt_chance_spell,$armor_num,$health,$mastery5,$m_max5);
      $health-=$damage;$damage=0;
    }else{
      $mastery5+=spell_attack("e",($tgt_spell%10),$tgt_spell_num,$tgt_vit,1,1,$tgt_chance_spell,$armor_num,$e_health,$mastery5,$m_max5);
      $e_health+=$damage;$damage=0;
    }
  }
  if($tgt_spell !=0 && $health>0 && $tgt_double_m>=rand(1,100)){
    if($tgt_spell%10 !=8){
      $mastery5+=spell_attack("e",($tgt_spell%10),$tgt_spell_num,$tgt_ntl,1,1,$tgt_chance_spell,$armor_num,$health,$mastery5,$m_max5);
      $health-=$damage;$damage=0;
    }else{
      $mastery5+=spell_attack("e",($tgt_spell%10),$tgt_spell_num,$tgt_vit,1,1,$tgt_chance_spell,$armor_num,$e_health,$mastery5,$m_max5);
      $e_health+=$damage;$damage=0;
    }
  }
  if($tgt_spell2 !=0 && $health>0){
    if($tgt_spell2%10 !=8){
      $mastery5+=spell_attack("e",($tgt_spell2%10),$tgt_spell2_num,$tgt_ntl,1,1,$tgt_chance_spell2,$armor_num,$health,$mastery5,$m_max5);
      $health-=$damage;$damage=0;
    }else{
      $mastery5+=spell_attack("e",($tgt_spell2%10),$tgt_spell2_num,$tgt_vit,1,1,$tgt_chance_spell2,$armor_num,$e_health,$mastery5,$m_max5);
      $e_health+=$damage;$damage=0;
    }
  }
  if($tgt_spell2 !=0 && $health>0 && $tgt_double_m>=rand(1,100)){
    if($tgt_spell2%10 !=8){
      $mastery5+=spell_attack("e",($tgt_spell2%10),$tgt_spell2_num,$tgt_ntl,1,1,$tgt_chance_spell2,$armor_num,$health,$mastery5,$m_max5);
      $health-=$damage;$damage=0;
    }else{
      $mastery5+=spell_attack("e",($tgt_spell2%10),$tgt_spell2_num,$tgt_vit,1,1,$tgt_chance_spell2,$armor_num,$e_health,$mastery5,$m_max5);
      $e_health+=$damage;$damage=0;
    }
  }
  if($spell !=0 && $health>0){
    if($spell%10 !=8){
      $mastery3+=spell_attack("u",($spell%10),$spell_num,$ntl,$mastery3,$m_max3,$chance_spell,$tgt_armor_num,$e_health,$tgt_mastery5,1);
      $e_health-=$damage;$damage=0;
    }else{
      $mastery3+=spell_attack("u",($spell%10),$spell_num,$vit,$mastery3,$m_max3,$chance_spell,$tgt_armor_num,$health,$tgt_mastery5,1);
      $health+=$damage;$damage=0;
    }
  }
  if($spell !=0 && $health>0 && $e_health>0 && $double_m>=rand(1,100)){
    if($spell%10 !=8){
      $mastery3+=spell_attack("u",($spell%10),$spell_num,$ntl,$mastery3,$m_max3,$chance_spell,$tgt_armor_num,$e_health,$tgt_mastery5,1);
      $e_health-=$damage;$damage=0;
    }else{
      $mastery3+=spell_attack("u",($spell%10),$spell_num,$vit,$mastery3,$m_max3,$chance_spell,$tgt_armor_num,$health,$tgt_mastery5,1);
      $health+=$damage;$damage=0;
    }
    if(rand(1,$double_m*100)==11 && $double_m<100 && $lastmon!=1000){
      ++$double_m;
      print "mX(43);";
    }
  }
  if($spell2 !=0 && $e_health>0 && $health>0){
    if($spell2%10 !=8){
      $mastery4+=spell_attack("u",($spell2%10),$spell2_num,$ntl,$mastery4,$m_max4,$chance_spell2,$tgt_armor_num,$e_health,$tgt_mastery5,1);
      $e_health-=$damage;$damage=0;
    }else{
      $mastery4+=spell_attack("u",($spell2%10),$spell2_num,$vit,$mastery4,$m_max4,$chance_spell2,$tgt_armor_num,$health,$tgt_mastery5,1);
      $health+=$damage;$damage=0;
    }
  }
  if($spell2 !=0 && $health>0 && $e_health>0 && $double_m>=rand(1,100)){
    if($spell2%10 !=8){
      $mastery4+=spell_attack("u",($spell2%10),$spell2_num,$ntl,$mastery4,$m_max4,$chance_spell2,$tgt_armor_num,$e_health,$tgt_mastery5,1);
      $e_health-=$damage;$damage=0;
    }else{
      $mastery4+=spell_attack("u",($spell2%10),$spell2_num,$vit,$mastery4,$m_max4,$chance_spell2,$tgt_armor_num,$health,$tgt_mastery5,1);
      $health+=$damage;$damage=0;
    }
    if(rand(1,$double_m*100)==11 && $double_m<100 && $lastmon!=1000){
      ++$double_m;
      print "mX(43);";
    }
  }
}
?>