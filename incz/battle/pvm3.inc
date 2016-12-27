<?php
    switch($cbonus){
      case 1:
  	$armor_num+=3*$clx;
      break;
      case 2:
  	$exp_bonus+=0.05*$clx;
      break;
      case 3:
  	$gold_bonus+=0.1*$clx;
      break;
      case 4:
  	$drop_bonus+=1*$clx;
      break;
      case 5:
  	$wep_num+=2*$clx;
  	$wep_num2+=2*$clx;
  	$spell_num+=2*$clx;
  	$spell_num2+=2*$clx;
      break;
    }
    if($kd_misc>0 && $kd_tax>-1){
      switch($kd_misc){
      case 1:
  	$tgt_chance_spell-=15;$tgt_chance_spell2-=15;
      break;
      case 2:
  	$wep_num++;$wep_num2++;
  	$chance_hit*=1.2;$chance_hit2*=1.2;
      break;
      case 3:
  	$spell_num++;$spell_num2++;
  	$chance_spell*=1.3;$chance_spell2*=1.3;
      break;
      case 4:
        $wep_num++;$wep_num2++;
  	$chance_hit*=1.2;$chance_hit2*=1.2;
  	$spell_num++;$spell_num2++;
  	$chance_spell*=1.3;$chance_spell2*=1.3;
      break;
      }
    }
    if($dex>$wis){$tgt_ax=rand(0,70);}
    else{$tgt_ax=rand(30,100);}
    if($tgt_ax>50){$tgt_action="f";}  // i think it should be vice versa J.
    else{$tgt_action="c";}
?>