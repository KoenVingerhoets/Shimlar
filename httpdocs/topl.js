<!--
function upd_ranks(){
  rankdesc="<table border=1 width='600'>";
  pname_x=pname.split(",");
  if(rankmode==0){
    race_x=race.split(",");
    lvl_x=lvl.split(",");
    exp_x=exp.split(",");
    rankdesc+="<tr><td colspan='2' align='center'><i><b>Player</b></i></td><td><center><b>Race</b></td><td><center><b>Level</b></td><td><center><b>Free Exp</b></td></tr>";
    for(i=0;i<pname_x.length-1;++i){
    x=i+1;
    if(i==0){
      rankdesc+="<tr><td align='center' colspan='2'><font color='0099FF' size=5><b><i>"+pname_x[i]+"</i></b></font></td>";
      rankdesc+="<td><center><b><i>"+rd(race_x[i])+"</i></b></td>";
      rankdesc+="<td><center><font color='00EE00' size=5><b>"+lvl_x[i]+"</b></font></td>";
      rankdesc+="<td><center><font color='00EE00' size=5><i>"+pil(exp_x[i])+"</i></font></td></tr>";
    }else if(i<10){
      rankdesc+="<tr><td width='30' align='right'><font color='00AAEE'><b>"+x+"</b></font></td><td align='center'><font color='00AAEE'><b>"+pname_x[i]+"</b></font></td>";
      rankdesc+="<td><center><b><i>"+rd(race_x[i])+"</i></b></td>";
      rankdesc+="<td><center><font color='00EE00'><b>"+lvl_x[i]+"</b></font></td>";
      rankdesc+="<td><center><font color='00EE00'>"+pil(exp_x[i])+"</font></td></tr>";
    }else{
      rankdesc+="<tr><td width='30' align='right'><font color='fffffa'>"+x+"</font></td><td align='center'><font color='fffffa'>"+pname_x[i]+"</font></td>";
      rankdesc+="<td><center><i>"+rd(race_x[i])+"</i></td>";
      rankdesc+="<td><center><font color='fffffa'>"+lvl_x[i]+"</font></td>";
      rankdesc+="<td><center><font color='fffffa'>"+pil(exp_x[i])+"</font></td></tr>";
    }
    }
  }else if(rankmode==13){
    pname2_x=race.split(",");
    lvl_x=lvl.split(",");
    rankdesc+="<tr><td colspan='4'><center><b>Fame top list</b></center></td></tr>";
    rankdesc+="<tr><th>#</th><th>Name</th><th>Fame</th><th>Level</th></tr>";
    for(i=0;i<pname_x.length-1;++i){
			x=i+1;
    	if(i==0){
      	rankdesc+="<tr><td align='center' colspan='2'><font color='0099FF' size=5><b><i>"+pname_x[i]+"</i></b></font></td>";
      	rankdesc+="<td align='center'><b><i>"+pil(pname2_x[i])+"</i></b></td>";
      	rankdesc+="<td align='center'><b><i>"+lvl_x[i]+"</i></b></td></tr>";
    	}else if(i<10){
      	rankdesc+="<tr><td width='30' align='right'><font color='00AAEE'><b>"+x+"</b></font></td><td align='center'><font color='00AAEE'><b>"+pname_x[i]+"</b></font></td>";
      	rankdesc+="<td align='center'><b><i>"+pil(pname2_x[i])+"</i></b></td>";
      	rankdesc+="<td align='center'><b><i>"+lvl_x[i]+"</i></b></td></tr>";
    	}else{
      	rankdesc+="<tr><td width='30' align='right'><font color='fffffa'>"+x+"</font></td><td align='center'><font color='fffffa'>"+pname_x[i]+"</font></td>";
      	rankdesc+="<td align='center'><b><i>"+pil(pname2_x[i])+"</i></b></td>";
      	rankdesc+="<td align='center'><b><i>"+lvl_x[i]+"</i></b></td></tr>";
    	}
    }
  }else if(rankmode==1){
    banked_x=banked.split(",");
    race_x=race.split(",");
    rankdesc+="<tr><td><center><i><b>Player</b></i></td><td><center><b>Race</b></td><td><center><b>Banked Gold</b></td></tr>";
    for(i=0;i<pname_x.length-1;++i){
    x=i+1;
    if(i==0){
      rankdesc+="<tr><td><center><font color='00EE00' size=5><b><i>"+pname_x[i]+"</i></b></font></td>";
      rankdesc+="<td><center><b><i>"+rd(race_x[i])+"</i></b></td>";
      rankdesc+="<td><center><font color='FFFF00' size=5><b>"+pil(banked_x[i])+"</b></font></td></tr>";
    }else if(i<10){
      rankdesc+="<tr><td><center><font color='00EE00'>"+x+". <b>"+pname_x[i]+"</b></font></td>";
      rankdesc+="<td><center><b><i>"+rd(race_x[i])+"</i></b></td>";
      rankdesc+="<td><center><font color='FFFF00'><b>"+pil(banked_x[i])+"</b></font></td></tr>";
    }else{
      rankdesc+="<tr><td><center><font color='fffffa'>"+x+". "+pname_x[i]+"</font></td>";
      rankdesc+="<td><center><i>"+rd(race_x[i])+"</i></td>";
      rankdesc+="<td><center><font color='fffffa'>"+pil(banked_x[i])+"</font></td></tr>";
    }
    }
  }else if(rankmode==7 || rankmode==8){
    align_x=alig.split(",");
    race_x=race.split(",");
    rankdesc+="<tr><td><center><i><b>Player</b></i></td><td><center><b>Race</b></td><td><center><b>Alignment</b></td></tr>";
    for(i=0;i<pname_x.length-1;++i){
    x=i+1;
    if(i==0){
      rankdesc+="<tr><td><center><font color='00EE00' size=5><b><i>"+pname_x[i]+"</i></b></font></td>";
      rankdesc+="<td><center><b><i>"+rd(race_x[i])+"</i></b></td>";
      if(rankmode==7){
        rankdesc+="<td><center><font color='43F4FF' size=5><b>"+pil(align_x[i])+"</b></font></td></tr>";
      }else{
        rankdesc+="<td><center><font color='FF017F' size=5><b>"+pil(align_x[i])+"</b></font></td></tr>";
      }
    }else if(i<10){
      rankdesc+="<tr><td><center><font color='00EE00'>"+x+". <b>"+pname_x[i]+"</b></font></td>";
      rankdesc+="<td><center><b><i>"+rd(race_x[i])+"</i></b></td>";
      if(rankmode==7){
        rankdesc+="<td><center><font color='43F4FF'><b>"+pil(align_x[i])+"</b></font></td></tr>";
      }else{
        rankdesc+="<td><center><font color='FF017F'><b>"+pil(align_x[i])+"</b></font></td></tr>";
      }
    }else{
      rankdesc+="<tr><td><center><font color='fffffa'>"+x+". "+pname_x[i]+"</font></td>";
      rankdesc+="<td><center><i>"+rd(race_x[i])+"</i></td>";
      rankdesc+="<td><center><font color='fffffa'>"+pil(align_x[i])+"</font></td></tr>";
    }
    }
  }else if((rankmode==2)||(rankmode==3)||(rankmode==5)){
    lvl_x=lvl.split(",");
    rankdesc+="<tr><td><center><i><b>";
    if (rankmode==2){
      rankdesc+="Muted Players"      +"</b></i></td><td><center><b>Hours left</b></td></tr>";
    }else if (rankmode==3){
     rankdesc+="Mods Online"     +"</b></i></td><td><center><b>Level</b></td></tr>";
    }else if (rankmode==5){
      rankdesc+="Jailed Players"      +"</b></i></td><td><center><b>Hours left</b></td></tr>";
    }
    for(i=0;i<pname_x.length-1;++i){
      rankdesc+="<tr><td><center><font color='fffffa'>"+pname_x[i]+"</font></td>";
      if((rankmode==2 || rankmode==5) && lvl_x[i]==0){
        rankdesc+="<td><center><font color='fffffa'><b>Permanently</b></font></td></tr>";
      }else{
        rankdesc+="<td><center><font color='fffffa'>"+lvl_x[i]+"</font></td></tr>";
      }
    }
  }else if(rankmode==4){
    quest_x=quest.split(",");
    rankdesc+="<tr><td><center><i><b>Player</b></i></td><td><center><b>Hours till the Prophet will let you in again:</b></td></tr>";
    for(i=0;i<pname_x.length-1;++i){
      rankdesc+="<tr><td><center><font color='fffffa'>"+pname_x[i]+"</font></td>";
      if(quest_x[i]=="e"){
        rankdesc+="<td><center><font color='fffffa'>...waiting for new quests...</font></td></tr>";
      }else{
        rankdesc+="<td><center><font color='fffffa'>"+quest_x[i]+" hours</font></td></tr>";
      }
    }
  }else if(rankmode==9){
    quest_x=quest.split(",");
    rankdesc+="<tr><td><center><i><b>Player</b></i></td><td><center><b>Most Quests Completed:</b></td></tr>";
    for(i=0;i<pname_x.length-1;++i){
      rankdesc+="<tr><td><center><font color='fffffa'>"+pname_x[i]+"</font></td>";
      rankdesc+="<td><center><font color='fffffa'>"+quest_x[i]+"</font></td></tr>";
    }
  }else if(rankmode==10){
    channel_x=channel.split(",");
    rankdesc+="<tr><td><center><i><b>Moderator</b></i></td><td><center><b>Moderator Type</b></td></tr>";
    for(i=0;i<pname_x.length-1;++i){
      switch (channel_x[i]){
      	case "10":
	  rankdesc+="<tr><td><center><font color='fffffa'>"+pname_x[i]+"</font></td>";
      	  rankdesc+="<td><center><font color='fffffa'>Mod</font></td></tr>";
      	break;
      	case "11":
	  rankdesc+="<tr><td><center><font color='fffffa'>"+pname_x[i]+"</font></td>";
      	  rankdesc+="<td><center><font color='fffffa'>RP-Mod</font></td></tr>";
      	break; 
        default:
        break;
      }
    }
  }else if(rankmode==11){
    pname2_x=race.split(",");
    rankdesc+="<tr><td colspan='2'><center><b>... is married with ...</b></td></tr>";
    for(i=0;i<pname_x.length-1;++i){
      rankdesc+="<tr><td><center><font color='fffffa'>"+pname_x[i]+"</font></td>";
      rankdesc+="<td><center><font color='fffffa'>"+pname2_x[i]+"</font></td></tr>";
    }
  }else if(rankmode==12){
    pname2_x=race.split(",");
    rankdesc+="<tr><td colspan='3'><center><b>PK top list</b></td></tr>";
    for(i=0;i<pname_x.length-1;++i){
      if (i==0)
      	rankdesc+="<tr><td><center><font size=+1 color='red'>"+pname_x[i]+"</font></td>";
      else
      	rankdesc+="<tr><td><center><font color='#fffffa'>"+pname_x[i]+"</font></td>";
      rankdesc+="<td><center> killed <center></td>";
      rankdesc+="<td><center><font color='#fffffa'>"+pname2_x[i]+" players</font></td></tr>";
    }
  }else if((rankmode==6)||(rankmode==14)){
    cpower_x=cpower.split(",");
    cl1_x=cl1.split(",");
    cl2_x=cl2.split(",");
    cbonus_x=cbonus.split(",");
    rankdesc+="<tr><td><center><i><b>Clan</b></i></td><td><center><b>Power</b></td><td><center><b>Leader</b></td><td><center><b>Second Leader</b></td><td><center><b>Bonus</b></td></tr>";
    for(i=0;i<pname_x.length-1;++i){
    x=i+1;
    if(cbonus_x[i]==0){
      cb_x="-";
    }else{
      cb_x=c_bonus[cbonus_x[i]-1];
    }
    if(i==0){
      rankdesc+="<tr><td><center><font color='C603F7' size=5><b><i>"+pname_x[i]+"</i></b></font></td>";
      rankdesc+="<td><center><font color='FFAF31' size=5><b><i>"+cpower_x[i]+"</i></b></td>";
      rankdesc+="<td><center><font color='43CCFF' size=5><b>"+cl1_x[i]+"</b></font></td>";
      rankdesc+="<td><center><font color='43CCFF' size=5><b>"+cl2_x[i]+"</b></font></td>";
      rankdesc+="<td><center><font color='FFAF31' size=5><b><i>"+cb_x+"</i></b></td></tr>";
    }else if(i<10){
      rankdesc+="<tr><td><center><font color='C603F7'>"+x+". <b>"+pname_x[i]+"</b></font></td>";
      rankdesc+="<td><center><font color='FFAF31'><i>"+cpower_x[i]+"</i></td>";
      rankdesc+="<td><center><font color='43CCFF'>"+cl1_x[i]+"</font></td>";
      rankdesc+="<td><center><font color='43CCFF'>"+cl2_x[i]+"</font></td>";
      rankdesc+="<td><center><font color='FFAF31'><i>"+cb_x+"</i></td></tr>";
    }else{
      rankdesc+="<tr><td><center><font color='fffffa'>"+x+". <b>"+pname_x[i]+"</b></font></td>";
      rankdesc+="<td><center><font color='fffffa'><i>"+cpower_x[i]+"</i></b></td>";
      rankdesc+="<td><center><font color='fffffa'>"+cl1_x[i]+"</font></td>";
      rankdesc+="<td><center><font color='fffffa'>"+cl2_x[i]+"</font></td>";
      rankdesc+="<td><center><font color='fffffa'>"+cb_x+"</td></tr>";
    }
    }
  }
  rankdesc+="</table>";
  top.main.rankpage.innerHTML=rankdesc;
}
function rd(rcode){
  rcode%=100;
  rname=rnamea[rcode];
  return rname;
}
function pil(x){
  signx="";
  if(x<0) {
    signx="-";
    x=x*-1;
  }
  xs=x.toString();
  xs2=signx; p1=xs.length;
  for(b1=0;b1<p1;b1++){
    xs2+=xs.charAt(b1);
    if(((p1-b1-1)%3)==0 && b1 !=(p1-1)){
      xs2+=",";
    }
  }
  return xs2;
}
pname="",race="",lvl="",exp="",banked="",quest="",cpower="",cbonus="",cl1="",cl2="",rankmode=0,rankdesc="",alig="",pk="";
rnamea=new Array("Human","Dwarf","Elf","Dark Elf","Giant","Troll","Goblin","Angel","Gargoyle","Balrog","Kender","Half Elf","Dark Angel","Galatai","Flame Demon","Duergar","Sprite","Genie","Dragon","Vampire");
c_bonus=new Array("+3 Armor Class","+5% exp a kill","+10% gold a kill","+50% drop chance","1.5x damage","non locatable","+10% temple luck");
//-->
