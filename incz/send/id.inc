<?php
            $tgt=strstr($cinput," ");
            $tgt=ucwords(trim($tgt));
 //           if(strtolower($tgt)=="toshax" && $channels!=20 && $channels!=12){
 //             $chatresult="Toshax is the Dark God that Made this game and is around when you least expect it.";
 //           }else 
 						if(strtolower($tgt)=="shimlar"){
              $chatresult="Shimlar is the game you are playing, a world of wonders and mystery.";
            }else if((strtolower($tgt)=="lord arpharazon") && $channels!=20 && $channels!=12){
              $chatresult="The flame of Udun burns in his piercing gaze.";
//            }else if(strtolower($tgt)=="sisco" && $channels!=20 && $channels!=12){
//              $chatresult="The Chosen Dark Lord of Yah d'Verin, spreads his grip over Shimlar.";
            }else if(strtolower($tgt)=="j.nicolettecanne" && $channels!=20 && $channels!=12){
              $chatresult="~Divine Assassin~ Look for me under a velvet cloak of Darkness.";
            }else if(strtolower($tgt)=="lord morpheus" && $channels!=20 && $channels!=12){
              $chatresult="The skies darken and bristle with electricity... feel the Lord of Chaos watching you!";
//            }else if(strtolower($tgt)=="gilian bluerose" && $channels!=20 && $channels!=12){
//              $chatresult="See the thorns? You'll better be nice! --,--´--@";
            }else if(strtolower($tgt)=="clerity" && $channels!=20 && $channels!=12){
              $chatresult="The Lady of the Shadows dwells in the Realms.";
//            }else if(strtolower($tgt)=="lobotomy" && $channels!=20 && $channels!=12){
//              $chatresult="Be happy for the rest of your life after a lobotomy.";						
            }else {
              $query="Select Id, name as nimi,surname,banned,(UNIX_TIMESTAMP( ) - UNIX_TIMESTAMP( ax_time )  ) as aika from Players where name='$tgt'";
              if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
                extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
                $query="Select S.clan,S.race,S.lvl,S.align,S.exp,S.health,S.tstatus, P.Name as partner from Stats S left outer join Wedding W on W.pId1 = S.Id and W.Status = 1 left outer join Players P on W.pId2 = P.Id where S.Id = $tgt_Id";
                $result=mysql_query($query);
                extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
                if($tgt_clan>1){
                  $query="Select cname from Clans where cid=$tgt_clan";
                  $result=mysql_query($query);
                  extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
                }
                $tgt_gender="Male";
                if($tgt_race>=100){
                  $tgt_race-=100;
                  $tgt_gender="Female";
                }
                if($tgt_align>99){
                  $tgt_alx="good";
                }else if($tgt_align<-99){
                  $tgt_alx="evil";
                }else{
                  $tgt_alx="neutral";
                }
                $tgt_tb=" normal ";
                if($tgt_tstatus==1) {
                	$tgt_tb=" turn based ";
                }
                $tgt_rnamea=array("Human","Dwarf","Elf","Dark Elf","Giant","Troll","Goblin","Angel","Gargoyle","Balrog","Kender","Half Elf","Dark Angel","Galatai","Flame Demon","Duergar","Sprite","Genie","Dragon","Vampire");
                $tgt_rname=$tgt_rnamea[$tgt_race];
                $chatresult="$tgt_nimi $tgt_surname is a $tgt_tb level $tgt_lvl $tgt_alx $tgt_gender $tgt_rname";
                if($tgt_clan>1){
                  $chatresult.=" of clan $tgt_cname";
                }
                $tgt_aika = abs($tgt_aika);
                $a_sec=$tgt_aika%60;
                $tgt_aika = $tgt_aika - $a_sec;
                $a_min=($tgt_aika%(60*60))/60;
                $tgt_aika = $tgt_aika - $a_min*60;
								$a_h=($tgt_aika%(60*60*24))/(60*60);
                $tgt_aika = $tgt_aika - $a_h*60*60;
                $a_day=($tgt_aika%(60*60*24*30))/(60*60*24);
                $tgt_aika = $tgt_aika - $a_day*60*60*24;
                $a_month=($tgt_aika)/(60*60*24*30);

                if ($tgt_banned != 100){
                if($a_mon>0)
                  $chatresult.=" and has been idle for $a_mon months $a_day days $a_h hours $a_min min $a_sec sec.";
                else if($a_day>0)
                  $chatresult.=" and has been idle for $a_day days $a_h hours $a_min min $a_sec sec.";
                else if($a_h>0)
                  $chatresult.=" and has been idle for $a_h hours $a_min min $a_sec sec.";
                else if($a_min>0)
                  $chatresult.=" and has been idle for $a_min minutes $a_sec seconds.";
                else
                  $chatresult.=" and has been idle for $a_sec seconds.";
                } else { 
                  $chatresult.=" and has been banned.";
                }
                if ($tgt_partner != null) {
                  $chatresult.=" This player is married with $tgt_partner.";
                }
                if (($channels==10)||($channels==20)||($channels==11)||($channels==12)) {
                  $chatresult.=" Free exp: $tgt_exp  Health: $tgt_health."; 
                }
              }else {
                $chatresult="Player $tgt does not exist";
              }
            }
?>
