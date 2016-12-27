<!--
function ctrln(vix){
  if(pname=="" || version !=vix){
    alert("New Interface, please Refresh the page with ctrl+F5.");
    top.location.href=gUrl+"/justchat.php";
    return 0;
  }else{
    return 2;
  }
}
function make_stats(){
}
function make_toiminta(){
}
function upd_stats(){
}
function upd_toiminta(){
}
function make_chat(){
var tc=top.chat.document;
tc.open("text/html");
tc.write(c());
tc.close();
top.chat.msg.target.style.backgroundColor=0;
top.chat.msg.target.style.color='fffffa';
getnewchat();
}
function upd_chat(){
cb="<input name=joku1 value='chat' type=button onclick='javascript:top.chatmod(0)'";
if(chatmode==0)
cb+=" class='c'";
cb+=">";
cb+="<input name=joku1 value='roleplay' type=button onclick='javascript:top.chatmod(1)'";
if(chatmode==1)
cb+=" class='c'";
cb+=">";
cb+="<input name=joku1 value='sales' type=button onclick='javascript:top.chatmod(2)'";
if(chatmode==2)
cb+=" class='c'";
cb+=">";
cb+="<input name=joku1 value='clan' type=button onclick='javascript:top.chatmod(3)'";
if(chatmode==3)
cb+=" class='c'";
cb+=">";
top.chat.chanbut.innerHTML=cb;
  oldchatx=0;oldrolex=0;oldsalex=0;oldclanx=0;
  if(chatmode!=0&&chatsize>0){
    chat1new=1;
  }else if(chatmode==0){
    chat1new=0;
  }
  if(chatmode!=1&&rolesize>0){
    chat2new=1;
  }else if(chatmode==1){
    chat2new=0;
  }
  if(chatmode!=2&&salesize>0){
    chat3new=1;
  }else if(chatmode==2){
    chat3new=0;
  }
  if(chatmode!=3&&clansize>0){
    chat4new=1;
  }else if(chatmode==3){
    chat4new=0;
  }
  if(chatsize>0||pmsize>0){
    for(i=80;i>=(pmsize+chatsize);i--){
      oldchatnames[i]=oldchatnames[i-(pmsize+chatsize)];
      oldchattxt[i]=oldchattxt[i-(pmsize+chatsize)];
      oldchattype[i]=oldchattype[i-(pmsize+chatsize)];
    }
  }
  if(rolesize>0||pmsize>0){
    for(i=80;i>=(pmsize+rolesize);i--){
      oldrolenames[i]=oldrolenames[i-(pmsize+rolesize)];
      oldroletxt[i]=oldroletxt[i-(pmsize+rolesize)];
      oldroletype[i]=oldroletype[i-(pmsize+rolesize)];
    }
  }
  if(salesize>0||pmsize>0){
    for(i=80;i>=(pmsize+salesize);i--){
      oldsalenames[i]=oldsalenames[i-(pmsize+salesize)];
      oldsaletxt[i]=oldsaletxt[i-(pmsize+salesize)];
      oldsaletype[i]=oldsaletype[i-(pmsize+salesize)];
    }
  }
  if(clansize>0||pmsize>0){
    for(i=80;i>=(pmsize+clansize);i--){
      oldclannames[i]=oldclannames[i-(pmsize+clansize)];
      oldclantxt[i]=oldclantxt[i-(pmsize+clansize)];
      oldclantype[i]=oldclantype[i-(pmsize+clansize)];
    }
  }
  if(pmsize>0){
    for(i=0;i<pmsize;++i){
      oldchatnames[oldchatx]=tellnames[i];oldchattxt[oldchatx]=tolds[i];oldchattype[oldchatx]=telltype[i];
      oldrolenames[oldrolex]=tellnames[i];oldroletxt[oldrolex]=tolds[i];oldroletype[oldrolex]=telltype[i];
      oldsalenames[oldsalex]=tellnames[i];oldsaletxt[oldsalex]=tolds[i];oldsaletype[oldsalex]=telltype[i];
      oldclannames[oldclanx]=tellnames[i];oldclantxt[oldclanx]=tolds[i];oldclantype[oldclanx]=telltype[i];
      oldchatx++;oldrolex++;oldsalex++;oldclanx++;
    }
    pmsize=0;
  }
  if(chatsize>0){
    for(i=0;i<chatsize;++i){
      if(!(oldchattxt[oldchatx-1]==chatgeneral[i]&&oldchatnames[oldchatx-1]==chatnames[i])){
        oldchatnames[oldchatx]=chatnames[i];oldchattxt[oldchatx]=chatgeneral[i];oldchattype[oldchatx]=chattype[i];
      }else{
        oldchatnames[oldchatx]="";oldchattxt[oldchatx]="";oldchattype[oldchatx]=7;
      }
      oldchatx++;
    }
    chatsize=0;
  }
  if(rolesize>0){
    for(i=0;i<rolesize;++i){
      if(!(oldrolenames[oldrolex-1]==rolenames[i]&&oldroletxt[oldrolex-1]==chatrole[i])){
        oldrolenames[oldrolex]=rolenames[i];oldroletxt[oldrolex]=chatrole[i];oldroletype[oldrolex]=roletype[i];
      }else{
        oldrolenames[oldrolex]="";oldroletxt[oldrolex]="";oldroletype[oldrolex]=7;
      }
      oldrolex++;
    }
    rolesize=0;
  }
  if(salesize>0){
    for(i=0;i<salesize;++i){
      if(!(oldsalenames[oldsalex-1]==salenames[i]&&oldsaletxt[oldsalex-1]==chatsale[i])){
        oldsalenames[oldsalex]=salenames[i];oldsaletxt[oldsalex]=chatsale[i];oldsaletype[oldsalex]=saletype[i];
      }else{
        oldsalenames[oldsalex]="";oldsaletxt[oldsalex]="";oldsaletype[oldsalex]=7;
      }
      oldsalex++;
    }
    salesize=0;
  }
  if(clansize>0){
    for(i=0;i<clansize;++i){
      if(!(oldclannames[oldclanx-1]==clannames[i]&&oldclantxt[oldclanx-1]==chatclan[i])){
        oldclannames[oldclanx]=clannames[i];oldclantxt[oldclanx]=chatclan[i];oldclantype[oldclanx]=clantype[i];
      }else{
        oldclannames[oldclanx]="";oldclantxt[oldclanx]="";oldclantype[oldclanx]=7;
      }
      oldclanx++;
    }
    clansize=0;
  }
  chatstuff="";
  for(i=0;i<80;++i){
    if(chatmode==0){
      xname=oldchatnames[i];xtxt=oldchattxt[i];xtype=oldchattype[i];
    }else if(chatmode==1){
      xname=oldrolenames[i];xtxt=oldroletxt[i];xtype=oldroletype[i];
    }else if(chatmode==2){
      xname=oldsalenames[i];xtxt=oldsaletxt[i];xtype=oldsaletype[i];
    }else if(chatmode==3){
      xname=oldclannames[i];xtxt=oldclantxt[i];xtype=oldclantype[i];
    }
    if(xname != null && xname !=""){
    	if (!(isNaN(Number(xtype)))){
       xtype = Number(xtype);
     }
     if (xtype<39 || xtype>141) {
      switch(xtype) {
        case 0:  //just speaking
          chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='00AAEE'>"+xname+"</font></a> says: <font color='fffffa'>"+xtxt+"</font><br>";
	  			break;
      	case 1: //emotes
          chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='fffffa'><i>"+xname+"</font></a> <font color='F4E0B8'>"+xtxt+"</i></font><br>";
	  			break;
      	case 2: // OA
     	    chatstuff+="<font color='00EE00'><b>OA: "+xtxt+"</b></font><br>"; 
      	  break;
      	case 3: // good
      	  chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='DDDD50'>"+xname+"</font></a> says: <font color='fffffa'>"+xtxt+"</font><br>";
     	  	break;
        case 4: // evil
      	  chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='D00000'>"+xname+"</font></a> says: <font color='fffffa'>"+xtxt+"</font><br>";          
	  			break;
				case 5: // pm
          chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='orange'><b>"+xname+"</a> says: "+xtxt+"</b></font><br>";
          break;
 				case 6: // white text
          chatstuff+="<font color='fffffa'><b><i>"+xtxt+"</i></b></font><br>";
          break;
        case 7: // demon
          chatstuff+="<b><i><font color='red'>The Demon</font> <font color='#999999'>"+xtxt+"</font></i></b><br>";
	  			break;
        case 8: // demoness
          chatstuff+="<b><i><font color='red'>The Demoness</font> <font color='#999999'>"+xtxt+"</font></i></b><br>";
	  			break;
        case 9: // priest
          chatstuff+="<b><i><font color='fffffa'>The Priest</font> <font color='FFD700'>"+xtxt+"</font></i></b><br>";
	  			break;
				case 10: // mod yellow
          chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='DDDD50'>"+xname+"</font></a> says: <font color='fffffa'>"+xtxt+"</font><br>";
	  			break;
        case 11: // mod red
          chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='D00000'>"+xname+"</font></a> says: <font color='fffffa'>"+xtxt+"</font><br>";
	  			break;
				case 12: //RP-Arch
          chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='00AAEE'><b>"+xname+"</b></font></a> says: <font color='fffffa'>"+xtxt+"</font><br>";
          break;
				case 13: // mod warning
          chatstuff+="<font color='FF6600'>Moderator Warning: "+xtxt+"</font><br>";
          break;
        case 14: //jester
          chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><b>"+rb(xname)+"</b></a> says: <font color='fffffa'><b>"+xtxt+"</b></font><br>";
	  			break;
				case 15: // pm from mod
          chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='orange'><b>"+xname+"</a> says: "+xtxt+"</b></font><br>";
	  			break;
				case 16: // pm from arch
	  			chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='orange'><b>"+xname+"</a> says: "+xtxt+"</b></font><br>";
	  			break;
				case 17: // mod align
          chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='00AAEE'>"+xname+"</font></a> says: <font color='fffffa'>"+xtxt+"</font><br>";
	  			break;
        case 18: // priestess
          chatstuff+="<b><i><font color='fffffa'>The Priestess</font> <font color='FFD700'>"+xtxt+"</font></i></b><br>";
	  			break;
        case 20: //arch speak
          chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='00AAEE'><b>"+xname+"</b></font></a> says: <font color='fffffa'>"+xtxt+"</font><br>";
          break;
        case 21: // give gold 
          chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='FEDC18'>"+xname+"</a> gives you "+pilpm(xtxt)+"</font><br>"; 
	  			break;
        case 22: // give stuff
	  			chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='FEDC18'>"+xname+"</a> gives you "+gdpm(xtxt)+"</font><br>"; 
	  			break;
        case 23: // kill
          chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='FF3737'>"+xname+"</a> killed you!</font><br>";
	  			break;
        case 24: // attack
          chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='FF3737'>"+xname+"</a> attacked you!</font><br>";
 	  			break;
        case 25: // suicide
          chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='FF3737'>"+xname+"</a> attacked you, but died.</font><br>";
	  			break;
				case 26: // special mod action results 
	   	 		chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='00CC00'>"+xname+"</a> "+xtxt+"</font><br>"; 
	  			break;
				case 27: // muted, pk messages
          chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='3F7EFF'>"+xname+"</a> "+xtxt+"</font><br>";
	  			break;
        case 28: // hunt winner 
          chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='C0FFFF'><b>"+xname+"</a> has slain the legendary creature known as '"+xtxt+"'!</b></font><br>";
          zhunt=0;lastmon=0;
          break;
        case 29: // quests
          chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='COFFFF'>"+xname+"</a>"+qd(xtxt)+"!</font><br>";
	  			break;
        case 30: // modchat
					chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='00EE00'>"+xname+"</font></a> (mod chat) <font color='FF3737'>"+xtxt+"</font><br>";
	  			break;
        case 31: //no clue
          chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='006633'>"+xname+"</a> "+xtxt+"</font><br>";
	  			break;
        case 32: //ban
          chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='3F7EFF'><b>"+xname+"</a> "+xtxt+"</b></font><br>";
	 	 			break;
        case 33: //jester-text
          chatstuff+="<b>"+rb(xtxt)+"</b><br>";
	  			break;
        default:
          chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='0099DD'>"+xname+"</font></a> <b>("+xtype+")</b> <font color='fffffa'>"+xtxt+"</font><br>";
          break;
        }
      } else {
       	if (xtype > 39 && xtype < 140){
           chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='00CC00'>"+xname+"</font></a> ("+rnamea[xtype-40]+") says: <font color='fffffa'>"+xtxt+"</font><br>";
        } else {
           chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='0099DD'>"+xname+"</font></a> ("+xtype+") says: <font color='fffffa'>"+xtxt+"</font><br>";
        }
      }
    }
  }
  top.chat.chatstr.innerHTML=chatstuff;
  chatsent=0;
}
function upd_fight(){
}
function mform(xa,xk,xm,xn){
  if(dx1==0){
    dx1=1;
    setTimeout("dsub1()",900);
    top.chat.xform.a.value=xa;
    top.chat.xform.k.value=xk;
    top.chat.xform.m.value=xm;
    top.chat.xform.n.value=xn;
    top.chat.xform.submit();
  }else{
    alert("Please wait for previous action to complete!");
  }
  top.chat.msg.target.focus();
}
function getnewchat(){
  if (top.checkLoginCookieForChat()){
    if(chatonly<100){
      if(chatsent==0){
        chatsent=1;
        chatonly++;
        top.chat.newchat.submit();
        setTimeout("cset0()",1000);
      }
      setTimeout("getnewchat()",cdel);
    }else{
        alert("You seem to be Away or not Playing. Please login again :)");
        top.location.href=gUrl+"/justchat.php";
    }
  } else {
      alert ('Abusing loophole, heh? \nOnce again and you will get banned!');	
  }
}
function chatsend(){
  top.chat.msg.btn_chat.disabled = true;
  if (top.checkLoginCookieForChat()){
    if(chatsent==0){
    chatsent=1;
    top.chat.msg.submit();
    setTimeout("cset0()",1000);
    }
  } else {
    alert ('Abusing loophole, heh? \nOnce again and you will get banned!');	
  }
}
function chatmod(x){
  chatmode=x;
  top.chat.msg.k.value=chatmode;
  upd_chat();
  if(x==1){
    top.chat.msg.target.value="/You are now in RolePlay chat";
  }else{
    top.chat.msg.target.value="";
  }
}
function upd_level(){
}
function tell(tname){
var tcm=top.chat.msg;
tcm.target.focus();
if(tname.charAt(0)=="#"){
tcm.target.value=tname.replace("#","/");
}else{
if(tcm.target.value==""){
tcm.target.value="/m "+tname+": ";
}else if(tcm.target.value=="/m "+tname+": "){
tcm.target.value="/id "+tname;
}else if(tcm.target.value=="/id "+tname){
tcm.target.value="/dm "+tname+": ";
}else if(tcm.target.value=="/dm "+tname+": "){
tcm.target.value="/pignore "+tname;
}else{
tcm.target.value="/m "+tname+": ";
}
}
tcm.target.focus();
}
function refdel(dx){
  cdel=dx*4000;
}
function cset0(){
  top.chat.msg.btn_chat.disabled = false;
  chatsent=0;
}
function dsub1(){
  dx1=0;
}
function idesc(itemcode,dxtype){
  i1=itemcode;
  iv=invlist[i1];
  if(iv != 0){
    iname=gd(iv);
    if(dxtype==2){
      if(rhand==(i1+1)){
        iname+=" (RH)";
      }else if(lhand==(i1+1)){
        iname+=" (LH)";
      }else if(spellone==(i1+1)){
        iname+=" (S1)";
      }else if(spelltwo==(i1+1)){
        iname+=" (S2)";
      }else if(armor==(i1+1)){
        iname+=" (EQ)";
      }else if(accx==(i1+1)){
        iname+=" (U)";
      }else if(tradex==(i1+1)){
        iname+=" (T)";
      }
    }
  }
  return iname;
}
function gd(xcode){
  xname="";x=xcode;
  x_type=Math.round((Math.round((x-5000)/10000)-50)/100);
  x_num=(Math.round((x-5000)/10000))-x_type*100;
  if(x_type==1){
    xname=wep_list1[x_num];
  }else if(x_type==2){
    xname=wep_list2[x_num];
  }else if(x_type==3){
    xname=wep_list3[x_num];
  }else if(x_type==4){
    xname=wep_list4[x_num];
  }else if(x_type==5){
    xname=spell_list1[x_num];
  }else if(x_type==6){
    xname=spell_list2[x_num];
  }else if(x_type==7){
    xname=spell_list3[x_num];
  }else if(x_type==8){
    xname=spell_list4[x_num];
  }else if(x_type==9){
    xname=armor_list1[x_num];
  }else if(x_type==10){
    xname=armor_list2[x_num];
  }else if(x_type==41){
    xname=acc_list[x_num];
  }else if(x_type==0){
    gem_num=x % 25;
    xname=gem_list[gem_num-1];
  }else if(x_type==11){
    xname="Phantom Sword "+ro_nums[Math.round((x_num-2)/5)];
  }else if(x_type==12){
    xname="Phantom Axe "+ro_nums[Math.round((x_num-2)/5)];
  }else if(x_type==13){
    xname="Phantom Staff "+ro_nums[Math.round((x_num-2)/5)];
  }else if(x_type==14){
    xname="Phantom Hammer "+ro_nums[Math.round((x_num-2)/5)];
  }else if(x_type==15){
    xname="Shadow Fire "+ro_nums[Math.round((x_num-2)/5)];
  }else if(x_type==16){
    xname="Shadow Freeze "+ro_nums[Math.round((x_num-2)/5)];
  }else if(x_type==17){
    xname="Shadow Shock "+ro_nums[Math.round((x_num-2)/5)];
  }else if(x_type==18){
    xname="Shadow Heal "+ro_nums[Math.round((x_num-2)/5)];
  }else if(x_type==19){
    xname="Ghost Armor "+ro_nums[Math.round((x_num-2)/5)];
  }else if(x_type==20){
    xname="Ghost Shield "+ro_nums[Math.round((x_num-2)/5)];
  }else if(x_type==21){
    xname="Mystic Blade "+ro_nums[Math.round((x_num-2)/5)];
  }else if(x_type==22){
    xname="Mystic Hatchet "+ro_nums[Math.round((x_num-2)/5)];
  }else if(x_type==23){
    xname="Mystic Wand "+ro_nums[Math.round((x_num-2)/5)];
  }else if(x_type==24){
    xname="Mystic Maul "+ro_nums[Math.round((x_num-2)/5)];
  }else if(x_type==25){
    xname="Mythic Flame "+ro_nums[Math.round((x_num-2)/5)];
  }else if(x_type==26){
    xname="Mythic Frost "+ro_nums[Math.round((x_num-2)/5)];
  }else if(x_type==27){
    xname="Mythic Storm "+ro_nums[Math.round((x_num-2)/5)];
  }else if(x_type==28){
    xname="Mythic Cure "+ro_nums[Math.round((x_num-2)/5)];
  }else if(x_type==29){
    xname="Saintly Plate "+ro_nums[Math.round((x_num-2)/5)];
  }else if(x_type==30){
    xname="Spiked Shield "+ro_nums[Math.round((x_num-2)/5)];
  }
  if(x_type>0){
    if((gemmed1=(x%100))>0){
      gs=Math.round((gemmed1+12)/25);
      xname+="["+gs+"]";
    }
    if((gemmed2=(((x%10000)-gemmed1)/100))>0){
      gs2=Math.round((gemmed2+12)/25);
      xname+="["+gs2+"]";
    }
  }else{
    if((gemmed=(x%100))>0){
      gs=Math.round((gemmed+12)/25);
      for(gsx=0;gsx<gs;gsx++){
        xname+="*";
      }
    }
  }
  return xname;
}
function gdpm(x){
 if (x!=0) {
 	xs=x.toString();
 	xsa=xs.split(" ");
 	xs=gd(xsa[0])+" "+xsa[1]+" "+xsa[2]+" "+xsa[3];
 	return xs;
 } else {
 	xs=" -- error -- no item was given ";
 }
}

function qd(qsx){
  qspec="";
  qx=qsx.split(",");
  qxz=zonelist[qx[0]];
  qxs=mdesc(qx[1]);
  qxm=qx[1]%20;
  if(qx[2]==1){qxl=mlist1;
  }else if(qx[2]==2){qxl=mlist2;
  }else if(qx[2]==3){qxl=mlist3;
  }else if(qx[2]==4){qxl=mlist4;
  }else if(qx[2]==5){qxl=mlist5;
  }else if(qx[2]==6){qxl=mlist6;
  }else if(qx[2]==7){qxl=mlist7;
  }else if(qx[2]==8){qxl=mlist8;
  }else if(qx[2]==9){qxl=mlist9;
  }else if(qx[2]==10){qxl=mlist10;
  }else if(qx[2]==11){qxl=mlist11;
  }else if(qx[2]==12){qxl=mlist12;
  }else if(qx[2]==13){qxl=mlist13;
  }else if(qx[2]==14){qxl=mlist14;
  }else if(qx[2]==15){qxl=mlist15;
  }else if(qx[2]==16){qxl=mlist16;
  }else if(qx[2]==17){qxl=mlist17;
  }else if(qx[2]==18){qxl=mlist18;
  }else if(qx[2]==19){qxl=mlist19;
  }else if(qx[2]==20){qxl=mlist20;
  }else if(qx[2]==25){qxl=mlist25;
  }else if(qx[2]==26){qxl=mlist26;
  }else if(qx[2]==27){qxl=mlist27;
  }else if(qx[2]==28){qxl=mlist28;
  }else if(qx[2]==29){qxl=mlist29;
  }else if(qx[2]==46){qxl=mlist46;
  }else if(qx[2]==47){qxl=mlist47;
  }else if(qx[2]==66){qxl=mlist66;}
  qspec=" has completed a quest to defeat a <font color='00FF00'>"+qxl[qxm]+"</font>"+qxs+" in <font color='FFFF00'>"+qxz+"</font>";
  return qspec;
}
function mdesc(msx){
  mspec="";
  if(msx>=20)
    mspec="<font color='03AF03'><b> Merchant</b></font>";
  if(msx>=40)
    mspec="<font color='FFDB31'><b> Veteran</b></font>";
  if(msx>=60)
    mspec="<font color='D098B0'><b> Fanatic</b></font>";
  if(msx>=80)
    mspec="<font color='FF3737'><b> King</b></font>";
  if(msx>=100)
    mspec="<font color='FF8965'><b> Fool</b></font>";
  if(msx>=120)
    mspec="<font color='0085EC'><b> Defender</b></font>";
  if(msx>=140)
    mspec="<font color='B5B3B3'><b> Assassin</b></font>";
  if(msx>=160)
    mspec="<font color='43F0FF'><b> Illusionist</b></font>";
  if(msx>=180)
    mspec="<font color='22AC53'><b> Elder</b></font>";
  if(msx>=200)
    mspec="<b>"+rb(' Enigma')+"</b></font>";
  return mspec;
}
function pil(x){
  xs=x.toString();
  xs2="";p1=xs.length;
  for(b1=0;b1<p1;b1++){
    xs2+=xs.charAt(b1);
    if(((p1-b1-1)%3)==0&&b1 !=(p1-1)){
      xs2+=",";
    }
  }
  return xs2;
}
function pilpm(x){
 xs=x.toString();
 xsa=xs.split(" ");
 xs=pil(xsa[0])+" gold "+xsa[1]+" "+xsa[2]+" "+xsa[3];
 return xs;
}
function rb(xn){
  xn=xn.toString();
  xs="";
  for(a1=0;a1<xn.length;a1++){
    xs+="<font color='"+htmca[a1%6]+"'>"+xn.charAt(a1)+"</font>";
  }
  return xs;
}
pname="",lastname="",lastaction="",mx=1,fmt=1,opname=""; //bdelay=0,
str=0,dex=0,vit=0,ntl=0,wis=0,health=0,gold=0,banked=0,masteries=0;
race=".",lvl=0,freelvl=0,exp=0,loc_x=0,loc_y=0,loc_zone=0,nxlvl=0,alignx=0;
zone_here=0,stuff_here=0,max_eq=0,max_wep=0,max_spells=0;
zkoko=0,zshop=0,zshrine=0,zmage=0,zbank=0,zexit=0,zhunt=0,zbname="";
titem=0,trader="",tprice=0,sb_here=0,tradex=0,questz=0,mname="";
invlist=0,lhand=0,rhand=0,spellone=0,spelltwo=0,armor=0,accx=0,statmode=0,chatmode=0;
lastmon=0,lastmonx=0,lastfight=0,battlestr=".",actionmsg="x",actionmsg2="z",mnum=1,mlist=0;
chatsize=0,chatr="x",rolesize=0,pmsize=0,salesize=0,clansize=0,chatsent=0;
duelnames=0,duelalign=0,duelid=0,chat1new=1,chat2new=1,chat3new=1,chat4new=1,chatonly=0;
cdel=24000,drop_s=0,dx1=0,turns=0,tstatus=0;
hslist=0,hsdesc="",hsname="",hsname2="",h_status=0,h_flag="";
clan="",cleader="",cleader2="",cpower=0,cbonus=0;
kdclan="",kddef=0,kdmine=0,kdmisc=0,kdbles=0,kdtax=0,kdgold=0,kddesc="",kdflag="",kdhealth=0;
loginTime="";loginName="";
//-->