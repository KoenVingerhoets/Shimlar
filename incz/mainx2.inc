<?php
function mainproc($l,$p,$a,$k,$m,$n,$fontsize){
  global $on_limit,$REMOTEADDR,$REQUESTURI;
  $REMOTEADDR = $_SERVER['REMOTE_ADDR'];
  $REQUESTURI = $_SERVER['REQUEST_URI'];
  if($REMOTEADDR==""){
    $REMOTEADDR="0";
  }
  if($REQUESTURI=="/main2.php"){
    if(tarkista($l) && tarkista($p) && tarkista($a) && tarkista($k) && tarkista($m) && tarkista($n)){
      $loginok = true;
      if($a=="o"){
        $loginok = false;
        $query="Select banned_ip from Ipban where banned_ip='$REMOTEADDR' limit 1";
        $result=mysql_query($query);
        if($result==TRUE and mysql_num_rows($result)==0){
          $pid = getIdByLogin($l);
          if ($pid != -1) {
            $l = (int)$pid;
            $loginok = true;            
          }          
        }
      }
      
      if(($loginok) && (is_numeric($l))){
        $query="Select p.name as nimi,p.password,p.channels,p.banned,p.wrong_pw,i.checked,p.Id,p.pstatus from Players p, Inventory i where p.Id=$l and p.Id=i.Id";
        if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
          extract(mysql_fetch_array($result));
          if($p==$password && $banned !=100 && $pstatus !=0){
            srand(make_seed());
            valmista_stats($Id,$nimi,$a,$k,$m,$n);
          }else if($p !=$password){
            ++$wrong_pw;
            sqlP(wrong_pw,$wrong_pw,$Id);
            if($wrong_pw>9){
              $ip=$REMOTEADDR;
              if($ip !=''){
                $query="Insert into Ipban values('$ip',now(),'$nimi')";
                mysql_query($query);
                sqlP(wrong_pw,0,$Id);
              }else {
                myPrint("alert(\"Stop guessing passwords,your IP will be banned.\");\n");
              }
            }
            ep2(0);
          }else if($banned==100){
            ep2(1);
          }else if($pstatus==0){
            ep2(68);
          }
        }else {
          ep2(2);
        }
      }else {
      	if ($loginok) {
        	ep2(26);
        } else {
        	ep2(69);
        }
      }
    }else {
      ep2(3);
    }
  }else if(! (is_numeric($l))){
    ep2(4);
  }else if($REQUESTURI!="/main2.php"){
    ep2(38);
  }
}

function valmista_stats ($pid,$pname,$action,$c1,$c2,$c3){
  global $REMOTEADDR;
  $REMOTEADDR=$_SERVER['REMOTE_ADDR'];
  $query="Lock Tables Players WRITE,Modactions WRITE,Stats WRITE,Inventory WRITE,Zones WRITE,Housing WRITE,Messages WRITE,Transfers WRITE,Market WRITE,Quests WRITE,Races WRITE,Hunts WRITE,Clans WRITE,Kingdoms WRITE,chat4 WRITE, PKLog READ";
  mysql_query($query);
  $query="Select channels,qnum,loc_x,loc_y,loc_zone,qhd from Players where Id = $pid";
  $result=mysql_query($query); extract(mysql_fetch_array($result));
  $query="Select clan,tef,tfc,gold,banked,exp,health,e_health,lvl,align,status,turns,tstatus from Stats where Id = $pid";
  $result=mysql_query($query); extract(mysql_fetch_array($result));
if($action=="o"||$action=="r"||$action=="he"||$action=="v"||$action=="nc"||$action=="pr"||$action=="q"){
  $query="Select race,str,dex,vit,wis,ntl,freelvl from Stats where Id = $pid";
  $result=mysql_query($query);extract(mysql_fetch_array($result));
  $race%=100;
  $rnamea=array("Human","Dwarf","Elf","Dark Elf","Giant","Troll","Goblin","Angel","Gargoyle","Balrog","Kender","Half Elf","Dark Angel","Galatai","Flame Demon","Duergar","Sprite","Genie","Dragon","Vampire");
  $rname=$rnamea[$race];
}
if($action=="o"||$action=="a"||$action=="nc"||$action=="pr"){
  $query="Select password,surname,fire_m,cold_m,air_m,arcane_m,sword_m,axe_m,staff_m,mace_m,armor_m,double_m from Players where Id = $pid";
  $result=mysql_query($query);extract(mysql_fetch_array($result));
}
if($action=="o"||$action=="h2"||$action=="h3"||$action=="u"||$action=="s"||$action=="k3"||$action=="k2"||$action=="e"||$action=="q2"||$action=="q"||$action=="gp"||$action=="my"||$action=="nc"){
  $query="Select * from Inventory where Id = $pid";
  $result=mysql_query($query);
  extract(mysql_fetch_array($result));
  $invlist=array($i1,$i2,$i3,$i4,$i5,$i6,$i7,$i8,$i9,$i10,$i11,$i12,$i13,$i14,$i15,$i16,$i17,$i18,$i19,$i20,$i21,$i22,$i23,$i24,$i25,$i26,$i27,$i28,$i29,$i30);
}
  $query="Select * from Zones where znum=$loc_zone";
  $result=mysql_query($query); extract(mysql_fetch_array($result));
  
if($action=="b"||$action=="b2"||$action=="x"||$action=="k3"||$action=="k2"||$action=="k1") {
  $query="select checked from Inventory where Id = $pid";
  $result=mysql_query($query);
  extract(mysql_fetch_array($result));
}
if($qnum !=0&&($action=="o"||$action=="m"||$action=="q1"||$action=="q2")){
  $query="Select * from Quests where qnum=$qnum";
  if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
    extract(mysql_fetch_array($result));
  }
}
if($action=="o"||$action[0]=="c"||$action[0]=="d"||$action=="pr"){
  if($clan>1){
    $query="Select * from Clans where cid=$clan";
    $result=mysql_query($query);
    if($result==TRUE and mysql_num_rows($result)>0){
      extract(mysql_fetch_array($result));
    }else {
      $cpower=0;
    }
  }else{
    if($clan==1){
      $cname="a";
    }
    $cpower=0;
  }
}

$statmode=0;$lastfight=0;$x=0;$y=0;$tspecial=0;$blessx=0;$eq_req=0; //$bdelay=0;
  $query="Update Players set lastaction='$action',ax_time=now() where Id = $pid";
  mysql_query($query);
  if($action=="o" && $c1 !=""){
    if(strlen($c1)<4){
      ep2(5);
    }else if(strlen($c1)>10){
      ep2(6);
    }else {
      myPrint("mX(12);");
      $password=$c1;
      sqlP(password,$c1,$pid);
    }
  }else if($action=="m"){
  	if($e_health==0 || $health==0)
  	{
    	if($c1==1){
      	if($loc_y<$zkoko)
        	++$loc_y;
      	else
        	$loc_y=0;
    	}else if($c1==2){
      	if($loc_y>0)
        	--$loc_y;
      	else
        	$loc_y=$zkoko;
    	}else if($c1==3){
      	if($loc_x>0)
        	--$loc_x;
      	else
        	$loc_x=$zkoko;
    	}else if($c1==4){
      	if($loc_x<$zkoko)
        	++$loc_x;
      	else
        	$loc_x=0;
    	}else if($c1==5){
      	if($zexit%10==$loc_y && ($zexit-($zexit%10))/10==$loc_x && $lvl>= $zlevel){
        	$query="Select znum from Zones where znum=$zone_p";
        	$result=mysql_query($query);
        	if(mysql_num_rows($result)==1){
          	extract(mysql_fetch_array($result));
          	if($align>500 && ($znum==20 || $znum==22 || $znum==31 || $znum==34)){
            	ep2(58);
          	}else if($align<-500 && ($znum==12 || $znum==15 || $znum==21 || $znum==24|| $znum==45)){
            	ep2(57);
          	}else{
	            $loc_x=$zone_x;$loc_y=$zone_y;$loc_zone=$znum;
  	          $query="Select * from Zones where znum=$znum";
    	        $result=mysql_query($query);
      	      extract(mysql_fetch_array($result));
        	    $lastmon=0;$lastfight=0;$e_health=0;
          	}
        	}
      	}else if($lvl<$zlevel){
        	ep2(7);
      	}
    	}else if($c1==6){
      	$query="Select znum,zlevel from Zones where zone_x=$loc_x and zone_y=$loc_y and zone_p=$loc_zone";
	      $result=mysql_query($query);
  	    if(mysql_num_rows($result)==1){
    	    extract(mysql_fetch_array($result));
      	  if(($align>500 && ($znum==20 || $znum==22 || $znum==31 || $znum==34)) || ($align>-50 && $znum==47)){
        	  ep2(58);
	        }else if(($align<-500 && ($znum==12 || $znum==15 || $znum==21 || $znum==24|| $znum==45)) || ($align<50 && $znum==46)){
  	        ep2(57);
    	    }else if($lvl>=$zlevel){
      	    $query="Select * from Zones where znum=$znum";
        	  $result=mysql_query($query);
          	extract(mysql_fetch_array($result));
	          $loc_zone=$znum;
  	        $loc_y=$zexit%10;$loc_x=($zexit-($zexit%10))/10;
    	      $lastmon=0;$lastfight=0;$e_health=0;
      	  }else if($lvl<$zlevel){
        	  ep2(7);
	        }	
  	    }
    	}
    	$query="Update Players set loc_x=$loc_x,loc_y=$loc_y,loc_zone=$loc_zone where Id = $pid";
    	mysql_query($query);
  	} else {
  		ep2(91);
  	}
  }
  
  $stuff_here=0;$zone_here=0;
  $query="Select znum from Zones where zone_x=$loc_x and zone_y=$loc_y and zone_p=$loc_zone";
  $result=mysql_query($query);
  if(mysql_num_rows($result)==1){
    extract(mysql_fetch_array($result));
    $zone_here=$znum;
  }else if($zexit%10==$loc_y && ($zexit-($zexit%10))/10==$loc_x && $loc_zone !=10){
    $query="Select znum from Zones where znum=$zone_p";
    if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
      extract(mysql_fetch_array($result));
      $zone_here=$znum;
    }
  }
  if($loc_zone==10){
    if($zshrine%10==$loc_y && ($zshrine-($zshrine%10))/10==$loc_x){
      $stuff_here=1;
    }
  }else if($loc_x<10 && $loc_y<10 && $loc_zone==32 && ($loc_x+$loc_y)>0){
    $stuff_here=8;
    $query="Select hint,hint2,pname as hname,pname2 as hname2,h_desc,h_status,h_flag from Housing where h_loc=($loc_x*10+$loc_y)";
    if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
      extract(mysql_fetch_array($result));$howned=2;
      if(($hint==$pid||$hint2==$pid) && ($action=="o"||$action=="m"||$action=="h2"||$action=="h3")){
        if(($h_status%4)==0){
          $hi_max=10;$query="Select h1,h2,h3,h4,h5,h6,h7,h8,h9,h10 from Housing where h_loc=($loc_x*10+$loc_y)";
        }else if(($h_status%4)==1){
          $hi_max=30;$query="Select h1,h2,h3,h4,h5,h6,h7,h8,h9,h10,h11,h12,h13,h14,h15,h16,h17,h18,h19,h20,h21,h22,h23,h24,h25,h26,h27,h28,h29,h30 from Housing where h_loc=($loc_x*10+$loc_y)";
        }else if(($h_status%4)==2){
          $hi_max=50;$query="Select h1,h2,h3,h4,h5,h6,h7,h8,h9,h10,h11,h12,h13,h14,h15,h16,h17,h18,h19,h20,h21,h22,h23,h24,h25,h26,h27,h28,h29,h30,h31,h32,h33,h34,h35,h36,h37,h38,h39,h40,h41,h42,h43,h44,h45,h46,h47,h48,h49,h50 from Housing where h_loc=($loc_x*10+$loc_y)";
        }
        $result=mysql_query($query);
        $hslist=mysql_fetch_row($result);
      }
    }else {
      $howned=1;
    }
  }else if($loc_x<18 && $loc_y<10 && $loc_zone==41 && ($loc_x+$loc_y)>0){
    $stuff_here=13;
    $query="Select * from Kingdoms where kd_loc=($loc_x*10+$loc_y)";
    if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
      extract(mysql_fetch_array($result));
      $query="Select cname as kdclan from Clans where cid=$kd_clan";
      $result=mysql_query($query);
      extract(mysql_fetch_array($result));
      if($kd_clan!=$clan){
        $kd_gold="???";
      }
    }else{
      $kd_clan=0;
    }
  }else if($loc_x==2 && $loc_y==2 && $loc_zone==16){
    $stuff_here=12;
  }else if($loc_x==1 && $loc_y==1 && $loc_zone==40){
    $stuff_here=11;
  }else if($loc_x==2 && $loc_y==3 && $loc_zone==24){
    $stuff_here=10;
  }else if($loc_x==3 && $loc_y==2 && $loc_zone==31){
    $stuff_here=10;
  }else if($loc_x==2 && $loc_y==2 && $loc_zone==33){
    $stuff_here=10;
  }else if($loc_x==1 && $loc_y==1 && $loc_zone==26){
    $stuff_here=7;
  }else if($loc_x==2 && $loc_y==1 && $loc_zone==16){
    $stuff_here=9;
  }else if($loc_x==1 && $loc_y==0 && $loc_zone==16){
    $stuff_here=5;
  }else if($loc_x==2 && $loc_y==2 && $loc_zone==37){
    $stuff_here=5;
  }else if(!($loc_x==0 && $loc_y==0)){
    if($zshrine%10==$loc_y && ($zshrine-($zshrine%10))/10==$loc_x){
      $stuff_here=1;
    }else if($zshop%10==$loc_y && ($zshop-($zshop%10))/10==$loc_x){
      $stuff_here=2;
    }else if($zmage%10==$loc_y && ($zmage-($zmage%10))/10==$loc_x){
      $stuff_here=3;
    }else if($zbank%10==$loc_y && ($zbank-($zbank%10))/10==$loc_x){
      $stuff_here=4;
    }
  }
  
  if ($stuff_here!=0) {
  	$e_health=0;
  	$query="update Stats set e_health = 0 where Id = $pid";
  	mysql_query($query);
  }
  
  if($action=="t"){
    if((($c1>=0 && $c1<23 && $c1 !=10)||$c1==26||$c1==32||$c1==40||$c1==41) && $stuff_here==1){
      $query="Select * from Zones where znum=$c1";
      $result=mysql_query($query);
      extract(mysql_fetch_array($result));
      $accs=accn($pid);
      if($accs==41180000 ){
        $cost=0;
      }else {
        $cost=20000;
      }
      if($zlevel<=$lvl && $gold>=$cost){
        if($align>500 && ($c1==20 || $c1==22 || $c1==31 || $c1==34)){
          $query="Select * from Zones where znum=$loc_zone";
          $result=mysql_query($query);
          extract(mysql_fetch_array($result));
          ep2(58);
        }else if($align<-500 && ($c1==12 || $c1==15 || $c1==21 || $c1==24|| $c1==45)){
          $query="Select * from Zones where znum=$loc_zone";
          $result=mysql_query($query);
          extract(mysql_fetch_array($result));
          ep2(57);
        }else{
          $loc_x=($zexit-($zexit%10))/10;$loc_y=($zexit%10);$loc_zone=$c1;$gold=$gold-$cost;$stuff_here=0;$e_health=0;$lastmon=0;$lastfight=0;
          $query="Update Players set loc_x=$loc_x,loc_y=$loc_y,loc_zone=$loc_zone where Id = $pid";
          mysql_query($query);
          $query="Update Stats set gold=$gold,e_health=0 where Id = $pid";
          mysql_query($query);
          $query="Select znum from Zones where znum=$zone_p";
          if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
            extract(mysql_fetch_array($result));
            $zone_here=$znum;
          }
          myPrint("mX(0);");
         }
       }else if($zlevel>$lvl){
        $query="Select * from Zones where znum=$loc_zone";
        $result=mysql_query($query);
        extract(mysql_fetch_array($result));
        ep2(8);
      }else if($gold<$cost){
        $query="Select * from Zones where znum=$loc_zone";
        $result=mysql_query($query);
        extract(mysql_fetch_array($result));
        ep2(16);
      }
    }else if($stuff_here !=1){
      ep2(9);
    }else if($c1<0||$c1>22||$c1==10){
      ep2(10);
    }
  }else if($action=="h1"){
    if($stuff_here==8){
    	$query="select * from Housing where hint = $pid";
    	$result = mysql_query($query);
    	if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==0)
    	{
      	if($howned==1 && $gold>=20000000){
        	$gold-=20000000;
        	sqlS(gold,$gold,$pid);
        	$query="Insert into Housing values($pid,null,'$pname','',$loc_x*10+$loc_y,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'','')";
        	mysql_query($query);
        	$hslist=array(0,0,0,0,0,0,0,0,0,0);$hi_max=10;
        	$h_status=0;$howned=2;$h_desc="";$h_flag="";$hname=$pname;
        	myPrint("mX(21);");
      	}else if($gold<20000000){
        	ep2(16);
      	}else if($howned==2){
        	ep2(32);
      	}
      } else {
      	ep2(87);
      }
    }else {
      ep2(35);
    }
  }else if($action=="h2"){
    if($c1>=0 && $c1<30 && $stuff_here==8 && $howned==2 && ($hint==$pid||$hint2==$pid)){
      for($i=0;$i<$hi_max;++$i){
        if($x==0 && $hslist[$i]==0){
          $x=$i+1;$y=$c1+1;
        }
      }
      if($x==0){
        if(($h_status%4)==2){
          ep2(34);
        }else {
          ep2(33);
        }
      }else {
        $hslist[$x-1]=$invlist[$c1];
        $invlist[$c1]=0;
        $sqlix="h$x";sqlH($sqlix,$hslist[$x-1],$loc_x*10+$loc_y);
        $sqliy="i$y";sqlI($sqliy,0,$pid);
        myPrint("mX(22);");
      }
    }
  }else if($action=="h3"){
    if($c1>=0 && $c1<$hi_max && $stuff_here==8 && $howned==2 && ($hint==$pid||$hint2==$pid)){
      for($i=0;$i<30;++$i){
        if($x==0 && $invlist[$i]==0){
          $x=$i+1;$y=$c1+1;
        }
      }
      if($x==0){
        ep2(17);
      }else {
        $invlist[$x-1]=$hslist[$c1];
        $hslist[$c1]=0;
        $sqlix="i$x";sqlI($sqlix,$invlist[$x-1],$pid);
        $sqliy="h$y";sqlH($sqliy,0,$loc_x*10+$loc_y);
      }
    }
  }else if($action=="h6"){
    if($stuff_here==8 && $howned==2 && $hint==$pid && ($h_status%8)>=4){
      $h_desc=$c1;
      if (cr_tarkista($h_desc,1,false)) {
        sqlH(h_desc,$h_desc,$loc_x*10+$loc_y);
      } else {
      	ep2(65);
      }
    }
  }else if($action=="h7"){
    if($stuff_here==8 && $howned==2 && $hint==$pid && ($h_status%16)>=8){
      $h_flag=$c1;
      if (is_url($h_flag))
      	sqlH(h_flag,$h_flag,$loc_x*10+$loc_y);
    }
  }else if($action=="h8"){
    if($stuff_here==8 && $howned==2 && $hint==$pid && ($h_status%32)>=16){
    	if(($hname2!="" || $gold<20000000) && $tstatus == 1 ) {
    		if ($gold<20000000) {
    			ep2(85);
    		} else {
    			ep2(84);    		  	  				
    		}
    	} else {
      	if($c1=="" && $tstatus==0) {
       	 	$hname2=$c1;
        	if (cr_tarkista($hname2,1,true)) {
          	$query="update Housing set pname2='', hint2=null where h_loc=($loc_x*10+$loc_y)";
  	  			mysql_query($query);
        	} else {
          	ep2(65);
        	}
      	} else {
        	$query="Select name,Id,tstatus,lvl from Stats where name='$c1'";
        	if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
          	extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
          	$query="select * from Housing where hint2 = $tgt_Id";
          	if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==0){
          		if($tgt_tstatus == $tstatus) {
          			if($tgt_Id!=$pid){
          				if ($tstatus==1 && $tgt_lvl < 300) {
          					ep2(86);
          				} else {
            				$query="update Housing set pname2='$tgt_name', hint2=$tgt_Id where h_loc=($loc_x*10+$loc_y)";
  	    						mysql_query($query);
  	    						if ($tstatus==1) {
        							$gold-=20000000;
        							sqlS(gold,$gold,$pid);
        						}
        					}
        				}
          		} else {
          			ep2(83);
          		}
          	} else {
          		ep2(88);
          	}
        	}else {
         		ep2(2);
        	}
      	}	
    	}
    }
  }else if($action=="h5"){
    if($c1>=0 && $c1<5 && $stuff_here==8 && $howned==2 && ($hint==$pid||$hint2==$pid)){
      if($c1==0){
        if(($h_status%4)!=2 && ($h_status%2)==0){
          if($gold>=20000000){
            $h_status+=1;$gold-=20000000;
            sqlH(h_status,$h_status,$loc_x*10+$loc_y);
            sqlS(gold,$gold,$pid);
          }else {
            ep2(16);
          }
        }else {
          ep2(37);
        }
      }else if($c1==1){
        if(($h_status%4)<2){
          if(($h_status%2)==0){
            $cost=35000000;
          }else {
            $cost=20000000;
          }
          if($gold>=$cost){
            $h_status+=2-($h_status%2);$gold-=$cost;
            sqlH(h_status,$h_status,$loc_x*10+$loc_y);
            sqlS(gold,$gold,$pid);
          }else {
            ep2(16);
          }
        }else {
          ep2(37);
        }
      }else if($c1==2){
        if(($h_status%8)<4){
          if($gold>=12000000){
            $h_status+=4;$gold-=12000000;
            sqlH(h_status,$h_status,$loc_x*10+$loc_y);
            sqlS(gold,$gold,$pid);
          }else {
            ep2(16);
          }
        }else {
          ep2(37);
        }
      }else if($c1==3){
        if(($h_status%16)<8){
          if($gold>=12000000){
            $h_status+=8;$gold-=12000000;
            sqlH(h_status,$h_status,$loc_x*10+$loc_y);
            sqlS(gold,$gold,$pid);
          }else {
            ep2(16);
          }
        }else {
          ep2(37);
        }
      }else if($c1==4){
        if(($h_status%32)<16){
          if($gold>=4000000){
            $h_status+=16;$gold-=4000000;
            sqlH(h_status,$h_status,$loc_x*10+$loc_y);
            sqlS(gold,$gold,$pid);
          }else {
            ep2(16);
          }
        }else {
          ep2(37);
        }
      }
    }
  }else if(($action=="b") && ($checked==0)){
    $c1=bankfix($c1);
    if($c1>0 && $c1<=$gold && $health>0 && $stuff_here==4){
      $banked=$banked+$c1;
      $gold=$gold-$c1;
      $query="Update Stats set gold=$gold,banked=$banked,e_health=0 where Id = $pid";
      mysql_query($query);
      myPrint("mX(1);");
    }else if($c1>$gold){
      ep2(11);
    }else if($health==0){
      ep2(12);
    }
  }else if(($action=="b2") && ($checked==0)){
    if($health>0 && $stuff_here==4){
      $banked=$banked+$gold;
      debugText("Deposit All ".$pname." amount ".$gold);
      // checkCookie($pid); really needed?
      $gold=0;
      $query="Update Stats set gold=0,banked=$banked,e_health=0 where Id = $pid";
      mysql_query($query);
      myPrint("mX(1);");
    }else if($health==0){
      ep2(12);
    }
  }else if($action=="w"){
    $c1=bankfix($c1);
    if($c1>0 && $c1<=$banked && $health>0 && $stuff_here==4){
      $banked=$banked-$c1;
      $gold=$gold+$c1;
      $query="Update Stats set gold=$gold,banked=$banked,e_health=0 where Id = $pid";
      mysql_query($query);
      myPrint("mX(2);");
    }else if($c1>$banked){
      ep2(13);
    }else if($health==0){
      ep2(12);
    }
  }else if($action=="w2"){
    if($health>0 && $stuff_here==4){
      $gold=$gold+$banked;
      $banked=0;
      $query="Update Stats set gold=$gold,banked=$banked,e_health=0 where Id = $pid";
      mysql_query($query);
      myPrint("mX(2);");
    }else if($health==0){
      ep2(12);
    }
  }else if(($action=="x") && ($checked==0)){
    $c1=bankfix($c1);
    if ($channels != 66) {
    	if ($lvl > 24) {
    		if ($tstatus==0) {
    			if($c1>0 && $c1<=$banked && $health>0 && $stuff_here==4){
      			$c2=trim(ucwords($c2));
      			$query="Select banked,Id,tstatus from Stats where name='$c2'";
      			if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
      				extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
        			if($tgt_Id==$pid){
          			ep2(14);
          		} else if (($tgt_tstatus==1)&&($pname!="J.NicoletteCanne")) {
          			ep2(81);
        			}else {
          			$banked=$banked-$c1;
          			$tgt_banked=$tgt_banked+$c1;
          			sqlS(banked,$banked,$pid);
          			sqlS(banked,$tgt_banked,$tgt_Id);
          			$query="Insert into Messages values($tgt_Id,'$pname',$c1,21,now())";
          			mysql_query($query);
          			$query="update Stats set e_health=0 where e_health = -1 and Id = $pid";
      					mysql_query($query);
          			debugText("Transfer from ".$pname." to ".$c2." amount ".$c1);
          			myPrint("mX(3);");
        			}
      			}else {
        			ep2(2);
      			}
    			}else if($c1>$banked){
      			ep2(13);
    			}else if($health==0){
      			ep2(12);
    			}
    		} else {
    			ep2(79);
    		}
  		}else {
    		ep2(62);
  		}
  	} else {
    	ep2(63);
  	}
  }else if($action=="i"){
    if($stuff_here==3){
      $c1=trim(ucwords($c1));
      $query="Select name,loc_x,loc_y,loc_zone,Id from Players where name='$c1' and channels!=20 and channels!=12";
      if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
        $accs=accn($pid);
        if($accs==41180000 ){
          $cost=0;
        }else {
          $cost=20000;
        }
        if($gold>=$cost){
          extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
          $gold=$gold-$cost;$spec_find=1;
          $tgt_accs=accn($tgt_Id);
          if($tgt_accs==41170000){
            $tgt_loc_x="?";$tgt_loc_y="?";$tgt_loc_zone=30;
          }
          if($tgt_loc_zone==29){
            $tgt_loc_x="?";$tgt_loc_y="?";
          }
          sqlS(gold,$gold,$pid);
        }else {
          ep2(16);$spec_find=0;
        }
      }else {
        ep2(2);
      }
    }
  }else if($action=="r"){
    if($health==0 && $stuff_here==1){
      $health=$vit;
      $query="update Stats set health=$health, e_health=0 where Id = $pid";
      mysql_query($query);
      myPrint("mX(4);");
    }
  }else if($action=="a"){
    $cost=$lvl*100;
    if($cost<=$gold && $stuff_here==5){
      $gold=$gold-$cost;
      sqlS(gold,$gold,$pid);
      myPrint("mX(5);");
      $statmode=2;
      myPrint("x9($sword_m,$axe_m,$staff_m,$mace_m,$fire_m,$cold_m,$air_m,$arcane_m,$armor_m,$double_m);");
    }else if($cost>$gold){
      ep2(16);
    }
  }else if($action=="v"){
  	if($freelvl>0){
      $nxlvl=0;
    }else {
      if($lvl<249){
        if($lvl>9){
          $j1=round(($lvl-5)/10);
          $j2=$lvl-($j1*10);
          $nxlvl=round(1000*(pow(1.35,$j1)-1)/(0.35))+round(100*$j2*(pow(1.35,$j1)));
        }else {
          $nxlvl=100*$lvl;
        }
      }else if($lvl<999){
        $nxlvl=5000000+($lvl-249)*200000;
      }else {
        $nxlvl= 300000000+($lvl-999)*3700000;
      }
    }
    if($exp>=$nxlvl){
      $query="Select r_str,r_dex,r_vit,r_ntl,r_wis from Races where rid=$race";
      $result=mysql_query($query);
      extract(mysql_fetch_array($result));
      $str=$str+$r_str*0.5;$dex=$dex+$r_dex*0.5;
      $ntl=$ntl+$r_ntl*0.5;$wis=$wis+$r_wis*0.5;
      $vit=$vit+$r_vit*0.5;
      if($c1==1){
        $str=$str+50;
      }else if($c1==2){
        $dex=$dex+50;
      }else if($c1==5){
        $vit=$vit+50;
      }else if($c1==3){
        $ntl=$ntl+50;
      }else if($c1==4){
        $wis=$wis+50;
      }else {
        $str=$str+$r_str*0.5;$dex=$dex+$r_dex*0.5;
        $ntl=$ntl+$r_ntl*0.5;$wis=$wis+$r_wis*0.5;
        $vit=$vit+$r_vit*0.5;
      }
      $health=$vit;$exp=$exp-$nxlvl;
      $lvl=($str+$dex+$vit+$ntl+$wis)/100;
      if($lvl%10==0 && $clan>1){
        $cpowerx=clanp($lvl)-clanp($lvl-1);
        $query="Select cpower from Clans where cid=$clan";
        $result=mysql_query($query);
        extract(mysql_fetch_array($result));
        sqlC(cpower,$cpower+$cpowerx,$clan);
      }
    }
    if($freelvl>0){
      --$freelvl;
    }
    $query="Update Stats set str=$str,dex=$dex,vit=$vit,ntl=$ntl,wis=$wis,health=$health,exp=$exp,lvl=$lvl,freelvl=$freelvl where Id = $pid";
    mysql_query($query);
  }else if($action=="u"){
    $price=round(50*pow(1.7,(int)$c2));
    if (($c2-floor($c2)>0)||($c1-floor($c1)>0)||(!(($c1>0&&$c1<11)||$c1==41))||(!($c2>=0&&$c2<37))){
        debugText("SHOPBAN ".$pname." c1=$c1 c2=$c2 ");
        $query="Insert into Modactions values('SHOPBAN','$pname','autoban IC $c2',now())";
        mysql_query($query);
        $query="Update Players set banned=100 where name='$pname'";
        mysql_query($query);
        ep2(1);
    }
    switch ($c2){
      case 33:
      	$iclass = 36;
      	break;
      case 34:
      	$iclass = 37;
      	break;
      case 35:
      	$iclass = 38;
      	break;
      case 36:
      	$iclass = 41;
      	break;
      default :
        $iclass = floor($c2);
        break;
    }

    for($i=0;$i<30;++$i){
      if($x==0 && $invlist[$i]==0){
        $x=$i+1;
      }
    }
    if($x==0){
      ep2(17);
    }
    $c1 = floor($c1);
    if($c1>=1 && $c1<=4 && $c2<$max_wep){
      if($gold>=$price && $x !=0){
        $iy=($c1*100+$iclass)*10000;
        $invlist[$x-1]=$iy;
        $gold=$gold-$price;
        sqlS(gold,$gold,$pid);
        $sqlix="i$x";sqlI($sqlix,$iy,$pid);
        $statmode=1;
        debugText("Shop-buy from $pname item :$iy Price :$price :c1=$c1:c2=$c2");
        myPrint("mX(6);");
      }else if($gold<$price){
        ep2(16);
      }
    }else if($c1>=5 && $c1<=8 && $c2<$max_spells){
      if($gold>=$price && $x !=0){
        $iy=($c1*100+$iclass)*10000;
        $invlist[$x-1]=$iy;
        $gold=$gold-$price;
        sqlS(gold,$gold,$pid);
        $sqlix="i$x";sqlI($sqlix,$iy,$pid);
        $statmode=1;
        debugText("Shop-buy from $pname item :$iy Price :$price :c1=$c1:c2=$c2");
        myPrint("mX(7);");
      }else if($gold<$price){
        ep2(16);
      }
    }else if($c1>=9 && $c1<=10 && $c2<$max_eq){
      if($gold>=$price && $x !=0){
        $iy=($c1*100+$iclass)*10000;
        $invlist[$x-1]=$iy;
        $gold=$gold-$price;
        sqlS(gold,$gold,$pid);
        $sqlix="i$x";sqlI($sqlix,$iy,$pid);
        $statmode=1;
        debugText("Shop-buy from $pname item :$iy Price :$price :c1=$c1:c2=$c2");
        myPrint("mX(8);");
      }else if($gold<$price){
        ep2(16);
      }
    }else if($c1==41 && $c2<25 && ($loc_zone==17||$loc_zone==24)){
      if($c2<24) $price=500000000;
      if($c2<20) $price=250000000;
      if($c2<17) $price=100000000;
      if($c2<10) $price=50000000;
      if($c2<5) $price=25000000;
      if(($c2==24)||($c2==5)) $price=10000000;
      if($gold>=$price && $x !=0){
        $iy=($c1*100+$c2)*10000;
        $invlist[$x-1]=$iy;
        $gold=$gold-$price;
        sqlS(gold,$gold,$pid);
        $sqlix="i$x";sqlI($sqlix,$iy,$pid);
        $statmode=1;
        debugText("Shop-buy from $pname item :$iy Price :$price :c1=$c1:c2=$c2");
        myPrint("mX(8);");
      }else if($gold<$price){
        ep2(16);
      }
    }
  }else if($action=="s"){
    if($c1>=0 && $c1<30){
      $query="Select kd_misc from Kingdoms where kd_clan=$clan";
      $result=mysql_query($query);
      if($result==TRUE and mysql_num_rows($result)>0){
        extract(mysql_fetch_array($result));
      }else{
        $kd_misc=0;
      }
      if($kd_misc==5){
        $sellpx=1.5;
      }else{
        $sellpx=1;
      }
      $debugItem = $invlist[$c1];
      $i_type=ityper($invlist[$c1]);
      $i_num=inumer($invlist[$c1]);
      $i_num=max($i_num,0);
      if($invlist[$c1]>9999){
        if($i_type<=10){
          switch ($i_num) {
            case 41:
              $i_num = 36;
              break;
            case 38:
              $i_num = 35;
              break;
            case 37:
              $i_num = 34;
              break;
            case 36:
              $i_num = 33;
              break;             
          }
          $i_num=min($i_num,36);          
          $price=round(25*pow(1.7,$i_num));
        }else if($i_type==41){
        	if (($tstatus==1)&&($invlist[$c1]!=41050000)&&($invlist[$c1]!=41240000)) {
      			$price=15000000;
      		}else{
      			$price=5000000;
      		}
      	}else if($i_type==42){
      		$price=5000000;
        }else if($i_type>20){
          $price=50000*($i_num+1);
        }else if($i_type>10){
          $price=5000*($i_num+1);
        }
      }else if($invlist[$c1]<=99 && $invlist[$c1]>0){
        $price=round((($invlist[$c1] % 100)+12)/25) * 10000;
        if ($tstatus==1) {
      		$price=$price*3;
      	}
        $i_type=0;$i_num=0;
      }
      $price=round($price*$sellpx);
      if($i_type>=0 && $i_num<=40){
        $x=$c1+1;
        if($rhand !=$x && $lhand !=$x && $spellone !=$x && $spelltwo !=$x && $armor !=$x && $accx !=$x){
          $invlist[$c1]=0;
          $gold=$gold+$price;
          sqlS(gold,$gold,$pid);
          $sqlix="i$x";sqlI($sqlix,0,$pid);
          debugText("Shop-sale from ".$pname." item : ".$debugItem." Price : ".$price);
          myPrint("mX(9);");
        }
      }
    }
  }else if($action=="k3") {
    if(($c2==0 && $c3==0) && ((int)$channels!=66) && ($checked==0) && ($tstatus==0)) {
      $query="select * from Market where tid = $c1";
      $result=mysql_query($query);
      $x=0; $itsforme=true;
      if(($result==TRUE) && (mysql_num_rows($result)==1)){
        extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
        if ($pid!=$tgt_tto) {
          $itsforme = false;
          $query="update Players set banned = 100 where Id = $pid";
          mysql_query($query);
          $query="insert into Modactions values('Lord A','$pname','sales jip!', now())";
          mysql_query($query);
        }
      	for($i=0;$i<30;++$i){
          if($x==0 && $invlist[$i]==0){
            $x=$i+1;
            break;
          }
        }
        if($x==0){
          ep2(17);
        }
      	if(($banked>=$tgt_tprice) && ($x>0) && ($itsforme)){
          $banked=$banked-$tgt_tprice; // bank player
          sqlS(banked,$banked,$pid);                                                                        
          $invlist[$x-1]=$tgt_titem;   // give item                                                                        
          $sqlix="i$x";sqlI($sqlix,$tgt_titem,$pid);                                                           
          $query="Select pname, tradex from Inventory where Id = $tgt_tfrom";                                         
          $result=mysql_query($query);                                                                     
          extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");                                       
          $y=$tgt_tradex;                                                                                  
          $query="Update Inventory set i$y=0,tradex=0 where Id = $tgt_tfrom";      // take item                           
          mysql_query($query);                                                                             
          $query="Update Stats set banked=banked+$tgt_tprice where Id = $tgt_tfrom";   // give gold                           
          mysql_query($query);                                                                                                                                                   
          $query="delete from Market where tid=$c1";                                                      
          mysql_query($query);$tspecial=1;                                                                 
          $query="Insert into Messages values($tgt_tfrom,'$pname','accepted your trade',26,now())";           
          mysql_query($query);                                                                             
          $query="Insert into Transfers values('$tgt_pname','$pname',$tgt_titem,now(),3)";                     
          mysql_query($query);                                                                             
          writeLogFile("Item-Sale from:$tgt_pname to:$pname item:$tgt_titem price:$tgt_tprice", "transferlog.txt");
          $statmode=1;                                                                                     
          myPrint("mX(14);");                                                                              
        }else if($banked<$tgt_tprice){
          ep2(13);
        }
      } else {
      	ep2(27);
      }
    }else {
      if ((int)$channels == 66) {
      	ep2(61);
      } else if ($checked != 0) {
      	ep2(67);
      } else if ($tstatus == 1) {
      	ep2(80);
      } else {
      	ep2(66);
      }
    }    
  }else if($action=="k2"){
    if (($lvl > 24) && ($checked==0) && ($tstatus==0)){
      if((int)$channels!=66){
        $c3=bankfix($c3);
        if($c1>=0 && $c1<30){
          $x=$c1+1; $y=0;
          $c2=trim(ucwords($c2));
          if($c3==0){
            $query="Select Inventory.*,Players.banned,Stats.tstatus from Inventory, Players, Stats where Inventory.pname='$c2' and Inventory.Id = Players.Id and Players.Id = Stats.Id";
            if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
              extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
              $tgt_invlist=array($tgt_i1,$tgt_i2,$tgt_i3,$tgt_i4,$tgt_i5,$tgt_i6,$tgt_i7,$tgt_i8,$tgt_i9,$tgt_i10,$tgt_i11,$tgt_i12,$tgt_i13,$tgt_i14,$tgt_i15,$tgt_i16,$tgt_i17,$tgt_i18,$tgt_i19,$tgt_i20,$tgt_i21,$tgt_i22,$tgt_i23,$tgt_i24,$tgt_i25,$tgt_i26,$tgt_i27,$tgt_i28,$tgt_i29,$tgt_i30);
              for($i=0;$i<30;++$i){
                if($y==0 && $tgt_invlist[$i]==0){
                  $y=$i+1;
                }
              }
              if($y==0){
               ep2(18);
              }else if($tgt_tstatus==1) {
              	ep2(80);
              }else if($tgt_Id==$pid){
                ep2(14);
              }else if((int)$tgt_banned==100){
              	ep2(72);
              }else {
                if($rhand !=$x && $lhand !=$x && $spellone !=$x && $spelltwo !=$x && $armor !=$x && $accx !=$x){
                  $iy=$invlist[$c1];$invlist[$c1]=0;
                  $sqlix="i$x";sqlI($sqlix,0,$pid);
                  $sqliy="i$y";sqlI($sqliy,$iy,$tgt_Id);
                  $query="Insert into Messages values($tgt_Id,'$pname',$iy,22,now())";
                  mysql_query($query);
                  $query="Insert into Transfers values('$pname','$c2',$iy,now(),2)";
                  mysql_query($query);
                  writeLogFile("Item-Give from:$pname to:$c2 item:$iy", "transferlog.txt");
                  if($tradex==$x){
                    $query="delete from Market where tfrom=$pid";
                    mysql_query($query);
                    sqlI(tradex,0,$pid);$tspecial=1;
                  }
                	myPrint("mX(10);");
                }
              }
            }else {
               ep2(2);
            }
          }else{
            $query="Select Inventory.pname,Inventory.Id,Players.banned,Stats.tstatus from Inventory, Players, Stats where Inventory.pname='$c2' and Players.Id = Inventory.Id and Stats.Id = Players.Id";
            if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
              extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
              if($tgt_Id==$pid){
                ep2(14);
              }else if((int)$tgt_banned==100){
              	ep2(72);
             	}else if($tgt_tstatus==1){
             		ep2(80);
              }else {
                $iy=$invlist[$c1];
                if($rhand !=$x && $lhand !=$x && $spellone !=$x && $spelltwo !=$x && $armor !=$x && $accx !=$x && $iy>0){
                  $query="delete from Market where tfrom=$pid";
                  mysql_query($query);
                  sqlI(tradex,$x,$pid);$tradex=$x;$tspecial=1;
                  $query="Insert into Market values(null,$tgt_Id,$pid,$iy,$c3)";
                  mysql_query($query);
                  $query="Insert into Messages values($tgt_Id,'$pname','offers you a trade',26,now())";
                  mysql_query($query);
                  myPrint("mX(16);");
                }
              }
            }else {
              ep2(2);
            }
          }
        }
      } else {
        ep2(61);
      }
    } else if ($checked != 0) {
      ep2(67);
    } else if ($tstatus != 0) {
    	ep2(80);
    } else {
      ep2(60);
    }
  }else if($action=="e"){
    if($c1>=0 && $c1<30){
      if($c2>=0 && $c2<30){
        if($invlist[$c1]>9999 && $invlist[$c1]<41000000 && $invlist[$c2]<100 && $invlist[$c2]>0){
          $i_type=ityper($invlist[$c1]);
          $i_num=inumer($invlist[$c1]);
          if($i_type>0 && $i_type<11 && $i_num<15){
            if(($invlist[$c1]%100)==0){
              $x=$c1+1;$y=$c2+1;
              $invlist[$c1]=$invlist[$c1]+$invlist[$c2];
              $invlist[$c2]=0;
              $i_num=$invlist[$c1];
              $query="Update Inventory set i$x=$i_num,i$y=0 where Id = $pid";
              mysql_query($query);
              myPrint("mX(11);");
            }
          }else if($i_type>10 || $i_num>14){
            if(($invlist[$c1]%10000)==0){
              $x=$c1+1;$y=$c2+1;
              $invlist[$c1]=$invlist[$c1]+$invlist[$c2];
              $invlist[$c2]=0;
              $i_num=$invlist[$c1];
              $query="Update Inventory set i$x=$i_num,i$y=0 where Id = $pid";
              mysql_query($query);
              myPrint("mX(11);");
            }else if(($invlist[$c1]%10000)<100){
              $x=$c1+1;$y=$c2+1;
              $invlist[$c1]=$invlist[$c1]+$invlist[$c2]*100;
              $invlist[$c2]=0;
              $i_num=$invlist[$c1];
              $query="Update Inventory set i$x=$i_num,i$y=0 where Id = $pid";
              mysql_query($query);
              myPrint("mX(11);");
            }
          }
        }
      }
    }
  }else if($action=="q1"){
    if($qnum==0||$qstatus==0){
      $query="Select * from Quests where qnum=$c1";
      $result=mysql_query($query);
      if($result==TRUE && mysql_num_rows($result)==1){
        extract(mysql_fetch_array($result));
        if($qstatus==0 && $qlevel>=$lvl && $qhd==0 && $qminlvl<=$lvl){
          $qnum=$c1;
          sqlP(qnum,$qnum,$pid);
          myPrint("mX(18);");
        }else if($qlevel<$lvl){
          ep2(41);$qnum=0;
        }else if($qhd>0){
          ep2(40);$qnum=0;
        }else if($qminlvl>$lvl){
          ep2(64);$qnum=0;
        }else {
          ep2(31);
        }
      }else {
        ep2(29);$qnum=0;
      }
    }else if($qstatus==$pid){
      ep2(30);
    }
  }else if($action=="q2"){
    if($qnum>0 && $qstatus==$pid){
      $gold+=$qgold;$exp+=$qexp;
      for($i=0;$i<30;++$i){
        if($x==0 && $invlist[$i]==0){
          $x=$i+1;
        }
      }
      if($x==0){
        ep2(24);
      }else {
        $invlist[$x-1]=$qitem;
        $sqlix="i$x";sqlI($sqlix,$qitem,$pid);
      }
      $query="Update Stats set gold=$gold,exp=$exp where Id = $pid";
      mysql_query($query);
      $query="Update Players set quests=quests+1,qnum=0 where Id = $pid";
      mysql_query($query);
      $query="Delete from Quests where qnum=$qnum";
      mysql_query($query);
      myPrint("mX(20);");
      $qnum=0;
    }else if($qstatus!=0){
      ep2(31);
    }else if($qstatus==0){
      ep2(28);
    }else if($qnum==0){
      ep2(29);
    }
  }else if($action=="q"){                                  //action equip
    if($c1>=0 && $c1<30){
      $ipl=$c1+1;
      $i_type=ityper($invlist[$c1]);
      $i_num=inumer($invlist[$c1]);
      if($i_type>0) {
        if($i_type<11) {
          if($lvl< (max(20*$i_num-200,0))){                 //lvlreq normal eq
            ep2(47); $eq_req=1;
          }
        }else if($i_type<21) {
          if($lvl<(20*($i_num-10))&& $i_num>9){            //lvlreq shadow eq
            ep2(47); $eq_req=1;
          }
        }else if (($i_type == 30) || ($i_type ==  28)){	   //lvlreq spiked shield and mythic cure
    	  if($lvl<(20*$i_num)&& $i_num>4){
            ep2(47); $eq_req=1;
          }
        }else if($i_type<41) {                             //lvlreq mystic eq
          if($lvl<(20*($i_num-5))&& $i_num>4){
            ep2(47); $eq_req=1;
          }
        }
        $stqx=($i_type>10)+($i_type>20);                   //$i_type>10 -> Att-req lowered 50 per IC
                                                           //$i_type>20 -> Att-req lowered 100 per IC

        if(($i_type%10)==0){
          if($str<((120-$stqx*50)*$i_num)){                //str req Shield
            ep2(44); $eq_req=1;
          }
        }else if(($i_type%10)<5 && $i_type<41){
          if($str<((200-$stqx*50)*$i_num)){                //str req weapon
            ep2(44); $eq_req=1;
          }
        }else if(($i_type%10)<8 && $i_type<41){            //ntl req spell
          if($ntl<((200-$stqx*50)*$i_num)){
            ep2(46); $eq_req=1;
          }
        }else if(($i_type%10)==8){                         //ntl req heal
          if($ntl<((130-$stqx*50)*$i_num)){
            ep2(46); $eq_req=1;
          }
        }else if(($i_type%10)==9){                         //vit req armor
          if($vit<((150-$stqx*50)*$i_num)){
            ep2(45); $eq_req=1;
          }
        }
        if(($i_type%10)<5 && $i_type<41){
          if($eq_req==0){
            if($rhand==0 && $lhand !=$ipl){
              sqlI(rhand,$ipl,$pid);$rhand=$ipl;
            }else if($rhand==$ipl){
              sqlI(rhand,0,$pid);$rhand=0;
            }else if($lhand==0){
              sqlI(lhand,$ipl,$pid);$lhand=$ipl;
            }else if($lhand==$ipl){
              sqlI(lhand,0,$pid);$lhand=0;
            }
          }
        }else if(($i_type%10)<9 && $i_type<41){
          if($eq_req==0){
            if($spellone==0 && $spelltwo !=$ipl){
              sqlI(spellone,$ipl,$pid);$spellone=$ipl;
            }else if($spellone==$ipl){
              sqlI(spellone,0,$pid);$spellone=0;
            }else if($spelltwo==0){
              sqlI(spelltwo,$ipl,$pid);$spelltwo=$ipl;
            }else if($spelltwo==$ipl){
              sqlI(spelltwo,0,$pid);$spelltwo=0;
            }
          }
        }else if(($i_type%10)==9){
          if($eq_req==0){
            if($armor==0){
              sqlI(armor,$ipl,$pid);$armor=$ipl;
            }else if($armor==$ipl){
              sqlI(armor,0,$pid);$armor=0;
            }
          }
        }else if($i_type==41){
          if($accx==0){
            sqlI(accx,$ipl,$pid);$accx=$ipl;
          }else if($accx==$ipl){
            sqlI(accx,0,$pid);$accx=0;
          }
        }
      }
      $statmode=1;
    }
  }else if($action=="he"){             //action house healing
    if($stuff_here==8 && $howned==2 && ($hint==$pid||$hint2==$pid)){
      $health=$vit;
      sqlS(health,$health,$pid);
      myPrint("mX(24);");
    }else {
      ep2(36);
    }
  }else if($action=="nc"){
    if($stuff_here==9 && $gold>=100000){
      $c1=min($c1,19);$c1=max($c1,0);
      if($c1<9){
        $lmin=100;
      }else if($c1<12){
        $lmin=300;
      }else if($c1<17){
        $lmin=600;
      }else {
        $lmin=1000;
      }
      if($lvl>=$lmin){
        $cpowerx=clanp($lvl);
        $query="Select cpower from Clans where cid=$clan";
        $result=mysql_query($query);
        extract(mysql_fetch_array($result));
        sqlC(cpower,$cpower-$cpowerx,$clan);
        $freelvl=$freelvl+$lvl-5;$exp=0;$gold-=100000;$lvl=1;
        $query="Select race from Stats where Id = $pid";
        $result=mysql_query($query);
        extract(mysql_fetch_array($result));
        // check on gender before giving new race
        if($race>=100){
          $newrace=$c1+100;
        }else {
          $newrace=$c1;
        }
        $race=$newrace;$rname=$rnamea[$c1];
        $query="Select * from Races where rid=$c1";
        $stats=mysql_query($query);
        extract(mysql_fetch_array($stats));
        $armor_m=max($armor_bonus,min($armor_m-20,$armor_max));
        $sword_m=max($sword_bonus,min($sword_m-20,$sword_max));
        $axe_m=max($axe_bonus,min($axe_m-20,$axe_max));
        $staff_m=max($staff_bonus,min($staff_m-20,$staff_max));
        $mace_m=max($mace_bonus,min($mace_m-20,$mace_max));
        $fire_m=max($fire_bonus,min($fire_m-20,$fire_max));
        $cold_m=max($cold_bonus,min($cold_m-20,$cold_max));
        $air_m=max($air_bonus,min($air_m-20,$air_max));
        $arcane_m=max($arcane_bonus,min($arcane_m-20,$arcane_max));
        $str=$r_str;$dex=$r_dex;$ntl=$r_ntl;$wis=$r_wis;$vit=$r_vit;$health=$vit;
        $lhand=0;$rhand=0;$armor=0;$spellone=0;$spelltwo=0;$accx=0;$tradex=0;
        $query="Update Stats set str=$str,dex=$dex,ntl=$ntl,wis=$wis,vit=$vit,health=$health,race=$race,lvl=1,freelvl=$freelvl,exp=0,gold=$gold where Id = $pid";
        mysql_query($query);
        $query="Update Players set sword_m=$sword_m,axe_m=$axe_m,staff_m=$staff_m,mace_m=$mace_m,fire_m=$fire_m,cold_m=$cold_m,air_m=$air_m,arcane_m=$arcane_m,armor_m=$armor_m where Id = $pid";
        mysql_query($query);
        $query="Update Inventory set lhand=0,rhand=0,spellone=0,spelltwo=0,armor=0,accx=0,tradex=0 where Id = $pid";
        mysql_query($query);
        $lhand=0;$rhand=0;$spellone=0;$spelltwo=0;$armor=0;$accx=0;
        myPrint("mX(25);");
      }else {
        ep2(39);
      }
    }else {
      ep2(16);
    }
  }else if($action=="gp"){
    if($c1>=0 && $c1<30 && $invlist[$c1]>99 && $invlist[$c1]<41000000 && ($gold>=100000 || ($tstatus==1 && $gold>=10000)) && $stuff_here==10){
      $x=$c1+1;$y=0;
      for($i=0;$i<30;++$i){
        if($y==0 && $invlist[$i]==0){
          $y=$i+1;
        }
      }
      if($rhand !=$x && $lhand !=$x && $spellone !=$x && $spelltwo !=$x && $armor !=$x && $accx !=$x && $y>0){
        $g1=$invlist[$c1]%100;
        $g2=($invlist[$c1]%10000-$g1)/100;
        $gemeff=rand(1,100);
        $tbasefactor=0;
        if ($tstatus==1) {
        	$tbasefactor=10;
        }
        if($g2>0){
          if($gemeff>(60+$tbasefactor)){
            $invlist[$y-1]=$g2;
            $invlist[$x-1]-=($g2*100);
          }else if($gemeff>(30+$tbasefactor)){
            $invlist[$x-1]-=($g2*100);
          }else {
            $invlist[$y-1]=$g2;
            $invlist[$x-1]=$g1;
          }
        }else if($g1>0){
          if($gemeff>(60+$tbasefactor)){
            $invlist[$y-1]=$g1;
            $invlist[$x-1]-=$g1;
          }else if($gemeff>(30+$tbasefactor)){
            $invlist[$x-1]=$g1;
          }else {
            $invlist[$x-1]-=$g1;
          }
        }
        if ($tstatus==1) {
        	$gold-=10000;
      	} else {
        	$gold-=100000;
      	}
        sqlS(gold,$gold,$pid);
        $sqlix="i$x";sqlI($sqlix,$invlist[$x-1],$pid);
        $sqliy="i$y";sqlI($sqliy,$invlist[$y-1],$pid);
        myPrint("mX(26);");
      }else if($y==0){
        ep2(17);
      }
    }else if($gold<100000 || ($gold<10000 && $tstatus==1)){
      ep2(16);
    }
  }else if($action=="pr"){
  	$price=0;
    if(($loc_zone==31) || ($loc_zone==24)){
      $price=200000+max(($lvl+$freelvl)*100+abs($align),0)*10;
  //  }else if($loc_zone==33){
  //    $price=400000+($lvl+$freelvl)*1000;
    } else { 
    	$price=400000+($lvl+$freelvl)*1000;
    }
    if($stuff_here==10 && $gold>=$price && freelvl==0){
      if(($loc_zone==31) && ($align >= 0)){
        $align = round($align - min(abs($align)*10/100,50));
        sqlS(align,$align,$pid);
     // }else if($loc_zone==33){
     //   $align= round($align-($align/abs($align))*min((abs($align)*10/100),50));
      }else if (($loc_zone==24)&&($align <= 0)) {
        $align = round($align + min(abs($align)*10/100,50));
        sqlS(align,$align,$pid);
      }
      $prayeff=rand(1,15);
      if($cbonus==7){
        $prayeff=rand(1,13);
      }
      if($prayeff==7){
        $blessx=(rand(0,18)%10)+1;
        $doLvl=false;
        if($blessx==1){
          if($sword_m<150){ ++$sword_m;
          sqlP(sword_m,$sword_m,$pid);
          myPrint("mX(13);");
          }else{
          	$doLvl=true;
          }
        }else if($blessx==2){
          if($axe_m<150){ ++$axe_m;
          sqlP(axe_m,$axe_m,$pid);
          myPrint("mX(13);");
          }else{
            $doLvl=true;
          }
        }else if($blessx==3){
          if($staff_m<150){ ++$staff_m;
          sqlP(staff_m,$staff_m,$pid);
          myPrint("mX(13);");
          }else{
            $doLvl=true;
          }
        }else if($blessx==4){
          if($mace_m<150){ ++$mace_m;
          sqlP(mace_m,$mace_m,$pid);
          myPrint("mX(13);");
          }else{
           	$doLvl=true;
          }
        }else if($blessx==5){
          if($fire_m<150){ ++$fire_m;
          sqlP(fire_m,$fire_m,$pid);
          myPrint("mX(15);");
          }else{
            $doLvl=true;
          }
        }else if($blessx==6){
          if($cold_m<150){ ++$cold_m;
          sqlP(cold_m,$cold_m,$pid);
          myPrint("mX(15);");
          }else{
            $doLvl=true;
          }
        }else if($blessx==7){
          if($air_m<150){ ++$air_m;
          sqlP(air_m,$air_m,$pid);
          myPrint("mX(15);");
          }else{
            $doLvl=true;
          }
        }else if($blessx==8){
          if($arcane_m<150){ ++$arcane_m;
          sqlP(arcane_m,$arcane_m,$pid);
          myPrint("mX(15);");
          }else{
            $doLvl=true;
          }
        }else if($blessx==9){
          if($armor_m<150){ ++$armor_m;
          sqlP(armor_m,$armor_m,$pid);
          myPrint("mX(17);");
          }else{
            $doLvl=true;
          }
        }
        if ($doLvl && (rand(0,10)==5))
        { 
            myPrint("mX(29);");
            sqlS(freelvl,1,$pid);
        }
      }else if($prayeff==9){
        myPrint("mX(28);");
      }else if($prayeff==10){
      	if (($tstatus==1) && ($turns<5354)) {
      		$query="update Stats set turns=turns+45 where Id = $pid";
      		mysql_query($query);
      		myPrint("mX(44);");
      	} else {
      		myPrint("mX(27);");
      	}
      }else {
        myPrint("mX(27);");
      }
      $gold-=$price;
      sqlS(gold,$gold,$pid);
    }else if($gold<$price){
      ep2(16);
    }
  }else if($action=="my"){
    if($c1>=0 && $c1<30 && $loc_zone==33 && $stuff_here==10){
      $i_type=ityper($invlist[$c1]);
      $i_num=inumer($invlist[$c1]);
      if($i_type>10 && $i_type<21){
        if($i_num<20){
          $price=($i_num+5)*4000000;
        }else{
          $price=($i_num+5)*8000000;
        }
        if($gold>=$price){
          $invlist[$c1]+=10000000;
          $x=$c1+1;$gold-=$price;
          $sqlix="i$x";sqlI($sqlix,$invlist[$c1],$pid);
          sqlS(gold,$gold,$pid);
          myPrint("mX(30);");
        }else{
          ep2(16);
        }
      }
    }
  }else if($action=="ta"){
    if($stuff_here==11){
      if($c1==7){
        $price=100000;
      }else if($c1==6){
        $price=10000;
      }else{
        $price=1000;
      }
      if($gold>=$price){
        $gold-=$price;
        if($tef==$c1){
          ++$tfc;
        }else{
          $tfc=1;$tef=$c1;
        }
        if($tfc>10 && $c1<7){
          $tfc=10;
          if($channels<10){
            sqlP(channels,8,$pid);
          }
        }else if($c1==7){
          if($channels==8){
            sqlP(channels,0,$pid);
          }
        }
        $query="Update Stats set tef=$tef,tfc=$tfc,gold=$gold where Id = $pid";
        mysql_query($query);
        myPrint("mX(31);");
      }else if($gold<$price){
        ep2(16);
      }
    }
  }else if($action=="c1"){
    if($stuff_here==12){
      $c1=ucwords(trim($c1));
      if (cr_tarkista($c1,1,false)) {
      if($cpower==0 && strlen($c1)>3 && strlen($c1)<31){
        if($gold>=10000000 && $lvl>299){
          $query="Select cname from Clans where cname='$c1'";
          $result=mysql_query($query);
          if($result==TRUE and mysql_num_rows($result)==0){
            $cname=$c1;$gold-=10000000;$cpower=clanp($lvl);
            $query="Insert into Clans (cname,cint,cint2,cleader,cleader2,cpower,cbonus,cduels,cturn) values('$cname',$pid,null,'$pname','',$cpower,0,0,$tstatus)";
            mysql_query($query);$cleader=$pname;$cleader2="";
            $query="Select cid from Clans where cname='$cname'";
            $result=mysql_query($query);
            extract(mysql_fetch_array($result));
            $query="Update Stats set clan=$cid,gold=$gold where Id = $pid";
            mysql_query($query);
            myPrint("mX(32);");
          }else{
            ep2(51);
          }
        }else if($gold<10000000){
          ep2(16);
        }else if($lvl<300){
          ep2(49);
        }
      }else if($cpower !=0){
        ep2(48);
      }else{
        ep2(4);
      }
      } else {
      	ep2(65);
      }
    }
  }else if($action=="c2"){
    if($stuff_here==12){
      if($cpower>0 && $cint==$pid){
        $query="Select Id,name,clan,lvl,tstatus from Stats where name='$c1'";
        if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
          extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
          if ($tgt_lvl > 299) {
          	if($tgt_Id!=$pid && $tgt_clan==$clan){
            	$cleader2=$tgt_name;
            	$query="update Clans set cint2 = $tgt_Id, cleader2 = '$tgt_name' where cid = $clan and cturn=$tgt_tstatus";
            	if (mysql_query($query)) {
            		$query="Insert into Messages values($tgt_Id,'$pname','has made you the second leader of clan $name',26,now())";
            		mysql_query($query);
            		myPrint("mX(35);");
            	} else {
            		ep2(78);
            	}
            }
          } else {
          	ep2(71);
          }
        }else{
          ep2(2);
        }
      }else{
        ep2(52);
      }
    }
  }else if($action=="c3"){
    if($stuff_here==12){
      $c1 = trim($c1);
      if (cr_tarkista($c1,1,false)) {
      if($cpower>0 && ($cint==$pid || $cint2==$pid) && $gold>=1000000){
        $query="Select Id,name,lvl,clan,tstatus from Stats where name='$c1'";
        if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
          extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
          if($tgt_clan==1 && $tgt_lvl>99){
          	if ($tgt_tstatus==$tstatus) {
            	$gold-=1000000;
            	sqlS(gold,$gold,$pid);
            	$cpower+=clanp($tgt_lvl);
            	sqlS(clan,$clan,$tgt_Id);
            	sqlC(cpower,$cpower,$clan);
            	$query="Insert into Messages values($tgt_Id,'$pname','accepted you into clan $cname',26,now())";
            	mysql_query($query);
            	myPrint("mX(33);");
            } else {
            	ep2(78);
            }
          }else if($tgt_clan !=1){
            if($tgt_clan==0){
              ep2(53);
            }else{
              ep2(48);
            }
          }else{
            ep2(49);
          }
        }else{
          ep2(2);
        }
      }else if($gold<1000000){
        ep2(16);
      }else{
        ep2(52);
      }
      } else {
      	ep2(65);
      }
    }
  }else if($action=="c4"){
    if($stuff_here==12){
      if($cpower>0 && ($cint==$pid || $cint2==$pid)){
        $query="Select Id,name,lvl,clan from Stats where name='$c1'";
        if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
          extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
          if($tgt_clan==$clan && $tgt_Id !=$pid && $tgt_Id !=$cint && $tgt_Id != $cint2){
            $cpower-=clanp($tgt_lvl);
            sqlS(clan,0,$tgt_Id);
            sqlC(cpower,$cpower,$clan);
            if($tgt_Id==$cint2){
              $query="update Clans set cint2 = null, cleader2 = '' where cid = $clan";
              mysql_query($query);
            }
            if((15*$cbonus)>$cpower){
              $cbonus=0;
              sqlC(cbonus,$cbonus,$clan);
            }
            $query="Insert into Messages values($tgt_Id,'$pname','removed you from clan $cname',26,now())";
            mysql_query($query);
            myPrint("mX(34);");
          }else if($tgt_clan !=$clan){
            ep2(48);
          }else if($tgt_lvl <100){
            ep2(49);
          }
        }else{
          ep2(2);
        }
      }else{
        ep2(52);
      }
    }
  }else if($action=="c5"){
    if($stuff_here==12){
      $c1=min($c1,7);$c1=max($c1,1);
      if($cpower>0 && ($cint==$pid || $cint2==$pid) && $gold>=1000000){
        if((15*$c1)<=$cpower){
          $gold-=1000000;$cbonus=$c1;
          sqlS(gold,$gold,$pid);
          sqlC(cbonus,$cbonus,$clan);
          myPrint("mX(36);");
        }else{
          ep2(50);
        }
      }else if($gold<1000000){
        ep2(16);
      }else{
        ep2(52);
      }
    }
  }else if($action=="c6"){
    if($stuff_here==12){
      if($cpower>0){
      	$clan_old=$clan;
        if($pid==$cint){
        	if ($tstatus==0) {
          	if($cleader2 !=""){
            	$query="update Clans set cint=$cint2, cleader = '$cleader2', cint2 = null, cleader2 = '' where cid = $clan";
            	mysql_query($query);
            	$cpower-=clanp($lvl);$cleader=$cleader2;$cleader2="";
            	sqlS(clan,0,$pid);
            	sqlC(cpower,$cpower,$clan);
            	$query="Insert into Messages values($cint2,'$pname','has left the clan $cname, making you the leader',26,now())";
            	mysql_query($query);
            	myPrint("mX(38);");
          	}else{
            	$cleader="";$cpower=-1;
            	$query="Update Stats set banked=banked+500000 where clan=$clan";
            	mysql_query($query);
            	$query="Delete from Clans where cid=$clan";
            	mysql_query($query);
            	$query="Delete from Kingdoms where kd_clan=$clan";
            	mysql_query($query);
            	$query="Update Stats set clan=0 where clan='$clan'";
            	mysql_query($query);
            	myPrint("mX(42);");
          	}
          	$clan=0;
        	} else {
        		myPrint("mX(45);");
        	}
        }else{
          if($pid==$cint2){
          	if ($tstatus==0) {
            	$query="update Clans set cint2 = null, cleader2 = '' where cid = $clan";
            	mysql_query($query);
            	$cpower-=clanp($lvl);$cleader2="";
            	sqlS(clan,"",$pid);
            	sqlC(cpower,$cpower,$clan);
            	myPrint("mX(38);");
            	$clan=0;
            } else {
            	myPrint("mX(46);");
            }
          }else{
            $cpower-=clanp($lvl);
            sqlS(clan,0,$pid);
            sqlC(cpower,$cpower,$clan);
            myPrint("mX(38);");
            $clan=0;
          }
          if ($clan==0) {
         	 	$query="Insert into Messages values($cint,'$pname','has left the clan $cname',26,now())";
          	mysql_query($query);
          	$query="Insert into Messages values($cint2,'$pname','has left the clan $cname',26,now())";
          	mysql_query($query);
        	}
        }
        if ($clan==0) {
        	if((15*$cbonus)>$cpower){
          	$cbonus=0;
          	sqlC(cbonus,$cbonus,$clan_old);
        	}
        }
      }
    }
  }else if($action=="c7"){
    if($stuff_here==12){
      if($cpower==0 && $gold>=1000000 && $lvl>99){
        $gold-=1000000;$clan=1;
        sqlS(gold,$gold,$pid);
        sqlS(clan,1,$pid);
        myPrint("mX(37);");
      }else if($gold<1000000){
        ep2(16);
      }else if($lvl<100){
        ep2(49);
      }else{
        ep2(48);
      }
    }
  }else if($action=="d1"){
    if($stuff_here==13){
      if($kd_clan==0 && $gold>=1000000 && $cpower>0 && ($pid==$cint || $pid==$cint2)){
        $query="Select kd_def from Kingdoms where kd_clan=$clan";
        $result=mysql_query($query);
        if($result==TRUE and mysql_num_rows($result)==0){
          $gold-=1000000;
          sqlS(gold,$gold,$pid);
          $query="Insert into Kingdoms values($loc_x*10+$loc_y,$clan,'','',0,0,0,0,1,0,10000000)";
          mysql_query($query);
          $kdclan=$cname;$kd_def=0;$kd_mine=0;$kd_tax=0;$kd_gold=0;$kd_desc="";$kd_flag="";
          myPrint("mX(39);");
        }else{
          ep2(55);
        }
      }else if($gold<1000000){
        ep2(16);
      }else if($cpower==0 || ($pid!=$cint && $pid!=$cint2)){
        ep2(52);
      }else if($kd_clan>0){
        ep2(54);
      }
    }else {
      ep2(35);
    }
  }else if($action=="d2"){
    if($stuff_here==13 && $kd_clan==$clan && ($pid==$cint || $pid==$cint2)){
      $c1=str_replace("-","",$c1);
      $c1=round($c1);
      $c1=min($c1,49);
      $c1=max($c1,0);
      $kd_tax=$c1;
      sqlK(kd_tax,$kd_tax,$loc_x*10+$loc_y);
      inschat("chat4","<b>-=Kingdom=-</b>","<b><i>new tax is $kd_tax %</i></b>",$clan);
      myPrint("mX(41);");
    }
  }else if($action=="d3"){
    if($stuff_here==13 && $kd_clan==$clan && ($pid==$cint || $pid==$cint2)){
      $c1=str_replace("-","",$c1);
      $c1=round($c1);
      $c1=min($c1,4294967295);
      $c1=max($c1,0);
      if($c1>0 && $c1<=$kd_gold && $health>0){
        $kd_gold=$kd_gold-$c1;
        $gold=$gold+$c1;
        sqlK(kd_gold,$kd_gold,$loc_x*10+$loc_y);
        sqlS(gold,$gold,$pid);
        myPrint("mX(2);");
      }else if($c1>$kd_gold){
        ep2(56);
      }else if($health==0){
        ep2(12);
      }
    }
  }else if($action=="d4"){
    if($stuff_here==13 && $kd_clan==$clan && ($pid==$cint || $pid==$cint2)){
      $kd_desc=trim($c1);
      if (cr_tarkista($kd_desc,1,false)) {
        sqlK(kd_desc,$kd_desc,$loc_x*10+$loc_y);
      } else {
      	ep2(65);
      }
    }
  }else if($action=="d5"){
    if($stuff_here==13 && $kd_clan==$clan && ($pid==$cint || $pid==$cint2)){
      $kd_flag=trim($c1);
      if ((cr_tarkista($kd_flag,1,true)) && (is_url($kd_flag))) {
        sqlK(kd_flag,$kd_flag,$loc_x*10+$loc_y);
      } else {
      	ep2(65);
      }
    }
  }else if($action=="d6"){
    if($stuff_here==13 && $kd_clan==$clan && ($pid==$cint || $pid==$cint2)){
      if($c1==1){
        $c2=min($c2,12);$c2=max($c2,1);
        $price=pow(2,(int)$c2)*1000000;
      }else{
        $c2=min($c2,6);$c2=max($c2,1);
        $price=pow(2,(int)$c2)*5000000;
      }
      if($gold>=$price){
        if($c1==1){
          if($c2<(($cpower-7)/15)){
            $kd_def=$c2;$kd_health=($c2+1)*5000000;
            $gold-=$price;
            sqlK(kd_def,$kd_def,$loc_x*10+$loc_y);
            sqlK(kd_health,$kd_health,$loc_x*10+$loc_y);
            sqlS(gold,$gold,$pid);
            myPrint("mX(40);");
          }else{
            ep2(50);
          }
        }else if($c1==2){
          $kd_mine=$c2;
          $gold-=$price;
          sqlK(kd_mine,$kd_mine,$loc_x*10+$loc_y);
          sqlS(gold,$gold,$pid);
          myPrint("mX(40);");
      }else if($c1==3){
          $kd_misc=$c2;
          $gold-=$price;
          sqlK(kd_misc,$kd_misc,$loc_x*10+$loc_y);
          sqlS(gold,$gold,$pid);
          myPrint("mX(40);");
        }
      }else{
        ep2(16);
      }
    }
  }
  $REMOTEADDR=$_SERVER['REMOTE_ADDR'];
  $query="Update Players set wrong_pw=0,last_ip='$REMOTEADDR' where Id = $pid";
  mysql_query($query);
  $query="Update Stats set status=$lastmon where Id = $pid";
  mysql_query($query);
  if(($action=="e"||$action=="s"||$action=="q"||$action=="h2"||$action=="gp"||$action=="my") && $c1==($tradex-1)){
    $query="delete from Market where tfrom=$pid";
    mysql_query($query);$tspecial=1;$tradex=0;
    sqlI(tradex,0,$pid);
  }
  if($action=="e" && $c2==($tradex-1)){
    $query="delete from Market where tfrom=$pid";
    mysql_query($query);$tspecial=1;$tradex=0;
    sqlI(tradex,0,$pid);
  }
  $query="Unlock Tables";
  mysql_query($query);
  if($action=="o"||$action=="nc"){
    myPrint("x0(\"$pname\",\"$password\",\"$rname\",\"$surname\",\"$pid\",$turns,$tstatus);");
    sqlS(fmt,1,$pid);
  }
  if($action=="o"||$action=="r"||$action=="q2"||$action=="he"||$action=="nc"||$action=="pr"){
    myPrint("x1($exp,$gold,$health,$align);");
  }
  if($action=="o"||($action=="m" && $c1>4)||$action=="t"){
    $lastmon=$status;
    if($action=="o"){
      $query="Select status,opponent from Stats where Id = $pid";
      $result=mysql_query($query);
      extract(mysql_fetch_array($result));
    }
    if($lastmon<1000){
      $opponent=0;
    }
    $oppname=getName($opponent);
    myPrint("x2($lastmon,$lastfight,\"$oppname\",\".\");"); //$bdelay,
  }
  if($action=="o"||$action=="u"||$action=="s"||$action=="e"||$action=="k3"||$action=="q2"||$action=="h2"||$action=="h3"||$action=="gp"||$action=="k2"||$action=="k3"||$action=="my"){
    $imsg="";
    $query="Select * from Inventory where Id = $pid";
    $result=mysql_query($query);
    extract(mysql_fetch_array($result));
    $invlist=array($i1,$i2,$i3,$i4,$i5,$i6,$i7,$i8,$i9,$i10,$i11,$i12,$i13,$i14,$i15,$i16,$i17,$i18,$i19,$i20,$i21,$i22,$i23,$i24,$i25,$i26,$i27,$i28,$i29,$i30);
    for($i=0;$i<30;++$i){
      $ix=$invlist[$i];
      $imsg.="$ix,";
    }
    $imsg.="0";
    myPrint("x3(\"$imsg\");");
  }
  if($action=="o"||$action=="b"||$action=="b2"||$action=="w"||$action=="w2"||$action=="x"||$action=="u"||$action=="s"||$action=="a"||$action=="t"||$action=="i"||$action=="k3"||$action=="h1"||$action=="nc"||$action=="gp"||$action=="pr"||$action=="my"||$action=="ta"||$action=="c1"||$action=="c3"||$action=="c5"||$action=="c7"||$action=="d1"||$action=="d3"||$action=="d6"){
    myPrint("x4($gold,$banked);");
  }
  if($action=="o"||$action=="q"||$tspecial==1||$action=="k2"||$action=="k3"||$action=="nc"){
    $query="select lhand,rhand,spellone,spelltwo,armor,accx,tradex from Inventory where Id = $pid";
    $result=mysql_query($query);
    extract(mysql_fetch_array($result));
    myPrint("x5($lhand,$rhand,$spellone,$spelltwo,$armor,$accx,$tradex);");
  }
  if($action=="o"||$action=="m"||$action=="t"||$action=="rf"){
    myPrint("x6($loc_x,$loc_y,$stuff_here,$zone_here);");
    if($channels != 20 && $channels != 12) {
      if($loc_zone>8 && $loc_zone !=12 && $loc_zone !=15 && $loc_zone !=21 && $loc_zone !=24 && $loc_zone !=25 && $loc_zone !=26 && $loc_zone !=34 && $loc_zone !=45 && $stuff_here==0){
        valmista_duel($pid,$tstatus);
      }
    }else if($stuff_here==0){
      valmista_duel($pid,$tstatus);
    }
    if($zhunt>0 && $stuff_here==0){
      $query="Select bname from Hunts where bzone=$loc_zone";
      $result=mysql_query($query); extract(mysql_fetch_array($result));
      myPrint("xB(\"$bname\");");
    }
  }
  if($action=="o"||($action=="m" && $c1>4)||$action=="t"){
    myPrint("x7($loc_zone,$zkoko,$zshop,$zshrine,$zmage,$zbank,$zexit,$max_wep,$max_eq,$max_spells,$zmonsters,top.mlist$mlist);");
  }
  if($action=="o"||$action=="v"||$action=="nc"||$blessx==10){
    myPrint("x8($lvl,$freelvl,$exp,$str,$dex,$ntl,$wis,$vit,$health);");
  }
  if($action=="i" && $spec_find==1){
    myPrint("xI(\"$tgt_name\",\"$tgt_loc_x\",\"$tgt_loc_y\",$tgt_loc_zone);");
  }
  if(($action=="c1"||$action=="c2"||$action=="c3"||$action=="c4"||$action=="c6")&& $cpower!=0 ||$action=="o"||$action=="c7"){
    myPrint("xC(\"$cname\",\"$cleader\",\"$cleader2\",$cpower);");
  }
  if($stuff_here==7){
    valmista_quest($qnum);
  }
  if($stuff_here==8){
    if($howned==1){
      myPrint("h1('','','',0,'');");
    }else {
      myPrint("h1(\"$hname\",\"$hname2\",\"$h_desc\",$h_status,\"$h_flag\");");
      if(($hint==$pid||$hint2==$pid) && ($action=="o"||$action=="m"||$action=="h1"||$action=="h2"||$action=="h3")){
          $imsg="";
          for($i=0;$i<$hi_max;++$i){
            $ix=$hslist[$i];
            $imsg.="$ix,";
          }
          $imsg.="0";
          myPrint("h2(\"$imsg\");");
      }
    }
  }
  if($stuff_here==13){
    if($kd_clan>0){
      myPrint("xK(\"$kdclan\",$kd_def,$kd_health,$kd_mine,$kd_misc,$kd_tax,\"$kd_gold\",\"$kd_desc\",\"$kd_flag\");");
    }else{
      myPrint("xK('',0,0,0,0,0,'','','');");
    }
  }
  if($action=="k1"||$action=="k2"||$action=="k3"){
    $stuff_here=6;$statmode=1;
    $query="select m.tid, m.titem, m.tprice, p.name from Market m, Players p where m.tto = $pid and p.Id = m.tfrom";
    $result=mysql_query($query);
    $c1=mysql_num_rows($result);
    for($i=0;$i<$c1;++$i){
      $row=mysql_fetch_row($result);
      $tradeids.="$row[0],";
      $tradeitem.="$row[1],";
      $tradeprice.="$row[2],";
      $tradenames.="$row[3],";
    }
    $tradeids.="0";
    $tradenames.="''";
    $tradeitem.="0";
    $tradeprice.="0";
    myPrint("xT(\"$tradenames\",\"$tradeitem\",\"$tradeprice\",\"$tradeids\");");
  }
  myPrint("xX(\"$action\",$statmode);");
}
function valmista_duel($pid,$tstatus){
 	$query="Select p.loc_x,p.loc_y,p.loc_zone,p.channels,p.last_ip,s.lvl,s.clan from Players p, Stats s where p.Id = $pid and s.Id = p.Id";
 	$result=mysql_query($query);
  extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
  if (($tgt_channels==20)||($tgt_channels==12)||($tgt_loc_zone==40)) {
    $tgt_ilvl=4;
    $tgt_alvl=100000;
  } else {
    $tgt_ilvl=ceil($tgt_lvl-($tgt_lvl/4));
    $tgt_alvl=ceil($tgt_lvl+($tgt_lvl/3));
  }
  $tgt_lastip = getPartialIp($tgt_last_ip);
  if ($tstatus==1) { // turn based can attack all
  	$query="Select s.name, s.align, s.Id, s.clan from Players p,Stats s where p.Id=s.Id and p.Id != $pid and p.last_ip not like '$tgt_last_ip' and p.loc_x=$tgt_loc_x and p.loc_y=$tgt_loc_y and p.loc_zone=$tgt_loc_zone and s.health>0 and p.channels <> 20 and s.tstatus = $tstatus and not exists(select PKLog.Id from PKLog where PKLog.PlayerId = $pid and PKLog.KilledId = p.Id) order by s.name";
  } else {
  //	$query="Select s.name, s.align, s.Id, s.clan from Players p,Stats s where p.Id=s.Id and p.Id != $pid and p.last_ip not like '$tgt_last_ip' and p.loc_x=$tgt_loc_x and p.loc_y=$tgt_loc_y and p.loc_zone=$tgt_loc_zone and s.health>0 and p.channels <> 20 and s.lvl>=$tgt_ilvl and s.lvl<=$tgt_alvl and s.tstatus = 0 order by s.name";
  	$query="Select s.name, s.align, s.Id, s.clan from Players p,Stats s where p.Id=s.Id and p.Id != $pid and p.last_ip not like '$tgt_last_ip' and p.loc_x=$tgt_loc_x and p.loc_y=$tgt_loc_y and p.loc_zone=$tgt_loc_zone and s.health>0 and p.channels <> 20 and s.lvl>=$tgt_ilvl and s.lvl<=$tgt_alvl and s.tstatus = $tstatus order by s.name";
  }
  $result=mysql_query($query);
  $c1=mysql_num_rows($result);
  for($i=0;$i<$c1;++$i){
    $row=mysql_fetch_row($result);
    $duelclan = $row[3];
    if (($duelclan != 60) && ($duelclan == $tgt_clan)) {
    	$duelnames.="$row[0] (C),";
    } else {
    	$duelnames.="$row[0],";
    }
    $duelalign.="$row[1],";
    $duelid.="$row[2],";
  }
  $duelnames.="''";
  $duelalign.="0";
  $duelid.="0";
  myPrint("xD(\"$duelnames\",\"$duelalign\",\"$duelid\");");
}
function valmista_quest($signedQuest){
  global $REMOTEADDR;
  $REMOTEADDR=$_SERVER['REMOTE_ADDR'];
  $query="Select * from Quests order by qnum";
  $result=mysql_query($query);
  $c1=mysql_num_rows($result);
  if($c1>0){
    for($i=0;$i<$c1;++$i){
      $qname="";
      $row=mysql_fetch_row($result);
      if($row[7]==$signedQuest && $row[6]==0){
        $qname="y";
      } else if ($row[6] > 0) {
      	$qname=getName($row[6]);
      }
      $row[0]%=20;
      myPrint("xQ($row[7],$row[0],top.mlist$row[1],$row[2],$row[3],$row[4],$row[5],\"$qname\",$row[10] ,$row[8],$row[9]);");
    }
  }
}
function make_seed(){
  list($usec,$sec)=explode(' ',microtime());
  return (float) $sec + ((float) $usec * 100000);
}
function bankfix($jono){
  $jono=str_replace(" ","",$jono);
  $jono=str_replace("-","",$jono);
  $jono=str_replace(",","",$jono);
  $jono=str_replace(".","",$jono);
  $jono=str_replace("k","000",$jono);
  $jono=str_replace("K","000",$jono);
  $jono=str_replace("m","000000",$jono);
  $jono=str_replace("M","000000",$jono);
  $jono=str_replace("b","000000000",$jono);
  $jono=str_replace("B","000000000",$jono);
  $jono=round($jono);
  //$jono=min($jono,4294967295);
  $jono=max($jono,0);
  return $jono;
}

function myPrint($aText)
{
    print($aText);
    print("\r\n");
}

function myAlert($text) {
	print("alert('$text');");
	print("\r\n");
}

function cr_tarkista($jono,$x,$http) {
  $jono=strtolower($jono);
  if(strstr($jono,"\""))
    return 0;
  if(strstr($jono,"\'"))
    return 0;
  if(strstr($jono,"\\"))
    return 0;
  if(strstr($jono,"<"))
    return 0;
  if(strstr($jono,">"))
    return 0;
  if(strstr($jono,"&"))
    return 0;
  if((strstr($jono,"/")) && ($http))
    return 0;
  if(strstr($jono,"%"))
    return 0;
  if(strstr($jono,"`"))
    return 0;
  if(strstr($jono,"´"))
    return 0;
  for($i=123;$i<256;$i++) {
    if(strstr($jono,$i))
      return 0;
  }
  for($i=0;$i<32;$i++) {
    if(strstr($jono,$i))
      return 0;
  }
  for($i=33;$i<46+$x*2;$i++) {
    if(strstr($jono,$i))
      return 0;
  }
  for($i=58;$i<64;$i++) {
    if(strstr($jono,$i))
      return 0;
  }
  for($i=91;$i<95;$i++) {
    if(strstr($jono,$i))
      return 0;
  }

  if(strstr($jono,"fuck") || strstr($jono,"shit") || strstr($jono,"bitch") || 
strstr($jono,"vittu") || strstr($jono,"  ")){
    return 0;
  }
return 1;
}
?>