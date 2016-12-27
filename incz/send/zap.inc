<?php
            if($channels==20 || $channels==12){
              $spammer=strstr($cinput," ");
              $spammer=ucwords(trim($spammer));
              $query="Select Id,channels,banned from Players where name='$spammer'";
              if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
                extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
                $query="Select lvl from Stats where name='$spammer'";
                $result=mysql_query($query);
                extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
                if($tgt_channels !=20 && $tgt_channels !=12){
                  if($tgt_lvl>20){
                    if($tgt_banned !=100){
                      $tgt_banned+=10;
                      if ($tgt_banned==100){
                        $query="Insert into Modactions values('MODBAN','$spammer','mod action ban',now())";
                        mysql_query($query);
                        }
                      }
                    $query="Update Stats set health=0,exp=0,gold=0,lvl=lvl-5,str=str-100,dex=dex-100,vit=vit-100,ntl=ntl-100,wis=wis-100,status=0 where Id = $tgt_Id";
                  }else {
                    $query="Update Stats set health=0,exp=0,gold=0,banked=0,status=0 where Id = $tgt_Id";
                  }
                  mysql_query($query);
                  $query="Update Players set banned=$tgt_banned,ign=1 where Id = $tgt_Id";
                  mysql_query($query);
                  $query="Update Players set qhd=48,sword_m=sword_m-20,axe_m=axe_m-20,staff_m=staff_m-20,mace_m=mace_m-20,fire_m=fire_m-20,cold_m=cold_m-20,air_m=air_m-20,arcane_m=arcane_m-20,armor_m=armor_m-20 where Id = $tgt_Id";
                  mysql_query($query);
                  $query="Insert into Modactions values('$pname','$spammer','zapped',now())";
                  mysql_query($query);
                  $query="Insert into Messages values('$spammer','$pname','zapped you and it hurts.',26,now())";
                  mysql_query($query);
                  $chatresult="$spammer zapped!";
                }else {
                  $chatresult="Cannot Zap other ArchWizards";
                }
              }else {
                $chatresult="Player $spammer does not exist";
              }
            }else {
              $chatresult="You do not have this power!";
            }
?>