<?php
    $query="Select health,eq,bname from Hunts where bzone=$loc_zone";
    if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
      extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
      $tgt_str=$tgt_ntl=$tgt_dex=$tgt_wis=2000;$tgt_vit=$e_health=$tgt_health;
      $tgt_armor_num=20;$tgt_wep_num=$tgt_wep2_num=$tgt_spell_num=$tgt_spell2_num=10;
      $tgt_wep=$tgt_wep2=$tgt_spell=$tgt_spell2=9;$tgt_armor=10;
    }else{
      $e_health=-1;$tgt_health=-1;$lastmon=0;
    }
?>