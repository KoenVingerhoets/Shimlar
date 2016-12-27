<?php
    $lastfight=1;
    $oppname="";
    $query="Select name,lvl,exp,gold,str,dex,vit,ntl,wis,health,align from Stats where Id=$opponent";
    if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
      extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
      $query="Select loc_zone,loc_x,loc_y,fire_m,cold_m,air_m,arcane_m,sword_m,axe_m,staff_m,mace_m,armor_m,double_m from Players where Id=$opponent";
      $result=mysql_query($query);
      extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");   
      $query="Select * from Inventory where Id=$opponent";
      $result=mysql_query($query);
      extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
      $oppname=$tgt_name;
      $tgt_invlist=array($tgt_i1,$tgt_i2,$tgt_i3,$tgt_i4,$tgt_i5,$tgt_i6,$tgt_i7,$tgt_i8,$tgt_i9,$tgt_i10,$tgt_i11,$tgt_i12,$tgt_i13,$tgt_i14,$tgt_i15,$tgt_i16,$tgt_i17,$tgt_i18,$tgt_i19,$tgt_i20,$tgt_i21,$tgt_i22,$tgt_i23,$tgt_i24,$tgt_i25,$tgt_i26,$tgt_i27,$tgt_i28,$tgt_i29,$tgt_i30);
      $tgt_gems=array(0,0,0,0,0,0,0,0,0,0);
      $e_health=$tgt_health;
    }else{
      $e_health=0;$tgt_health=0;
    }
?>