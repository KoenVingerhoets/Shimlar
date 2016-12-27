<!--
cx1=0,cx2=0,cx3=0,cx4=0,cx5=0,cs=0;
function c1(ms,nimi,tyyppi){
if(tyyppi==26 && ms=="all shake"){
  top.shake();
}
else{
  top.chatgeneral[cx1]=ms;
  top.chatnames[cx1]=nimi;
  top.chattype[cx1]=tyyppi;
  cx1++;
}
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

function ct(ms,nimi,tyyppi){
if(tyyppi==26 && ms=="duck shake"){
  top.shake();
}
else{
  top.tolds[cx3]=ms;
  top.tellnames[cx3]=nimi;
  top.telltype[cx3]=tyyppi;
  cx3++;
}
}
function eX(errnum){
  alert(top.ob(top.va[errnum]));
}
function Z(){
  top.chatsize=cx1;
  top.rolesize=cx2;
  top.salesize=cx4;
  top.clansize=cx5;
  top.pmsize=cx3;
  top.upd_chat();
  if(cs==1){
    top.upd_stats();
  }
}
function x1(exp,gold,health){
  top.health=health;
 top.exp=exp;
 top.gold=gold;
 cs=1;
}
function x3(invs){
  invlist=invs.split(",");
  top.invlist=invlist;
 cs=1;
}
function x4(gold,banked){
  top.gold=gold;
  top.banked=banked;
 cs=1;
}
function x5(lhand,rhand,spellone,spelltwo,armor,accx,tradex){
 top.lhand=lhand;
 top.rhand=rhand;
 top.spellone=spellone;
 top.spelltwo=spelltwo;
 top.armor=armor;
 top.accx=accx;
 top.tradex=tradex;
}
function xC(clan,cleader,cleader2,cpower){
  top.clan=clan;top.cleader=cleader;top.cleader2=cleader2;top.cpower=cpower;
}
//-->
