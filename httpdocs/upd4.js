<!--
cx1=0,cx2=0,cx3=0,cx4=0,cx5=0,loc_msg="",qx1=0;
function x0(login,pword,race,lastname,pid,turns,tstatus){
  top.pname=login;
  top.login=pid;
  top.pword=pword;
  top.race=race;
  top.lastname=lastname;
  top.turns=turns;
  top.tstatus=tstatus;
}
function x1(exp,gold,health,alignx){
  top.health=health;top.exp=exp;top.gold=gold;top.alignx=alignx;
}
function x2(lastmon,lastfight,fmt,opname,btlstr){
  top.lastmon=lastmon;top.lastfight=lastfight;
  top.fmt=fmt;top.opname=opname;top.battlestr=btlstr;
}
function x3(invs){
  top.invlist=invs.split(",");
}
function x4(gold,banked){
  top.gold=gold;top.banked=banked;
}
function x5(lhand,rhand,spellone,spelltwo,armor,accx,tradex){
  top.lhand=lhand;top.rhand=rhand;top.spellone=spellone;top.spelltwo=spelltwo;
  top.armor=armor;top.accx=accx;top.tradex=tradex;
}
function x6(loc_x,loc_y,stuff_here,zone_here){
  top.loc_x=loc_x;top.loc_y=loc_y;
  top.zone_here=zone_here;top.stuff_here=stuff_here;
}
function x7(loc_zone,zkoko,zshop,zshrine,zmage,zbank,zexit,max_wep,max_eq,max_spells,mnum,mlist){
  top.loc_zone=loc_zone;top.zkoko=zkoko;
  top.zshop=zshop;top.zshrine=zshrine;top.zmage=zmage;top.zbank=zbank;top.zexit=zexit;
  top.max_eq=max_eq;top.max_wep=max_wep;top.max_spells=max_spells;
  top.mlist=mlist;top.mnum=mnum;top.lastmon=0;
  if(top.actionmsg2=="z"){
    top.ch_bg(loc_zone);
  }
}
function x8(lvl,freelvl,exp,str,dex,ntl,wis,vit,health){
  top.str=str;top.dex=dex;top.ntl=ntl;top.wis=wis;top.vit=vit;
  top.lvl=lvl;top.freelvl=freelvl;top.health=health;top.exp=exp;
}
function x9(m1,m2,m3,m4,m5,m6,m7,m8,m9,m10){
  masteries=new Array(m1,m2,m3,m4,m5,m6,m7,m8,m9,m10);
  top.masteries=masteries;
}
function x10(turns)
{
	top.turns=turns;
}
function h1(hsname,hsname2,hsdesc,h_status,h_flag){
  top.hsname=hsname;top.hsname2=hsname2;top.hsdesc=hsdesc;
  top.h_status=h_status;top.h_flag=h_flag;
}
function h2(invs){
  hslist=invs.split(",");
  top.hslist=hslist;
}
function xI(pname,px,py,pzone){
  loc_msg=pname+" was last seen at "+px+", "+py+" in "+top.zonelist[pzone]+".";
}
function xT(trader,titem,tprice){
  top.trader=trader;top.titem=titem;top.tprice=tprice;
}
function xB(zbname){
  top.zbname=zbname;top.zhunt=1;
}
function xD(ds){
  top.duelnames=ds.split(",");
}
function xQ(num,mons,mlist,zone,exp,gold,qitem,qstat,qlvl){
  top.qmon[qx1]=mons;top.qmlist[qx1]=mlist;top.qzone[qx1]=zone;
  top.qexp[qx1]=exp;top.qgold[qx1]=gold;top.qitem[qx1]=qitem;
  top.qstatus[qx1]=qstat;top.qnum[qx1]=num;top.qlvl[qx1]=qlvl;qx1++;
}
function xC(clan,cleader,cleader2,cpower){
  top.clan=clan;top.cleader=cleader;top.cleader2=cleader2;top.cpower=cpower;
}
function xK(kdclan,kddef,kdhealth,kdmine,kdmisc,kdtax,kdgold,kddesc,kdflag){
  top.kdclan=kdclan;top.kddef=kddef;top.kdmine=kdmine;top.kdmisc=kdmisc;top.kdhealth=kdhealth;
  top.kdtax=kdtax;top.kdgold=kdgold;top.kddesc=kddesc;top.kdflag=kdflag;
}

function xX (lastaction,statmode){
  top.questz=qx1;
  if(loc_msg != "")
    top.actionmsg=loc_msg;
  top.statmode=statmode;top.lastaction=lastaction;
  top.chatonly=0;
  if(top.ctrln(29)==2){
    if(lastaction=="o" || lastaction=="v" || lastaction=="nc"){
      top.upd_level();
    }
    if(lastaction=="o"){
      top.make_stats();
      top.make_chat();
    }
    top.upd_stats();
    top.upd_toiminta();
  }
}
function eX(errnum){
  if(errnum==1||errnum==26){
    top.location.href="http://www.shimlar.org";
  }
  alert(top.ob(top.va[errnum]));
}
function mX(msnum){
  atxt=top.msa[msnum];
  top.actionmsg=atxt;
}
function xA(chatr){
  top.chatr=chatr;
  top.chatonly=0;
  if(chatr !="x"){
    top.chat.chatres.innerHTML=chatr;
  }
 else {
    top.chat.chatres.innerHTML="";
  }
  top.lastaction="h";
  top.chat.msg.target.value="";
}
function c1(ms,nimi,tyyppi){
  top.chatgeneral[cx1]=ms;
  top.chatnames[cx1]=nimi;
  top.chattype[cx1]=tyyppi;
  cx1++;
}
function c2(ms,nimi,tyyppi){
  top.chatrole[cx2]=ms;
  top.rolenames[cx2]=nimi;
  top.roletype[cx2]=tyyppi;
  cx2++;
}
function c3(ms,nimi,tyyppi){
  top.chatsale[cx4]=ms;
  top.salenames[cx4]=nimi;
  top.saletype[cx4]=tyyppi;
  cx4++;
}
function c4(ms,nimi,tyyppi){
  top.chatclan[cx5]=ms;
  top.clannames[cx5]=nimi;
  top.clantype[cx5]=tyyppi;
  cx5++;
}
function Z(){
  top.chatsize=cx1;
  top.rolesize=cx2;
  top.salesize=cx4;
  top.clansize=cx5;
  top.pmsize=0;
  top.upd_chat();
}
//-->
