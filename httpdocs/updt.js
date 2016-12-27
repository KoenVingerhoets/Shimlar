<!--
top.pname="";top.race="";top.banked="";top.lvl="";top.channel="";top.quest="";top.exp="";top.alig="";
top.cpower="";top.cl1="";top.cl2="";top.cbonus="";
function t0(pname,race,lvl,exp) {
  top.pname+=pname+",";
  top.race+=race+",";
  top.lvl+=lvl+",";
  top.exp+=exp+",";
  top.rankmode=0;
}
function t1(pname,race,banked) {
  top.pname+=pname+",";
  top.race+=race+",";
  top.banked+=banked+",";
  top.rankmode=1;
}
function t2(pname,lvl) {
  top.pname+=pname+",";
  top.lvl+=lvl+",";
  top.rankmode=2;
}
function t3(pname,lvl) {
  top.pname+=pname+",";
  top.lvl+=lvl+",";
  top.rankmode=3;
}
function t4(pname,quest) {
  top.pname+=pname+",";
  top.quest+=quest+",";
  top.rankmode=4;
}
function t5(pname,lvl) {
  top.pname+=pname+",";
  top.lvl+=lvl+",";
  top.rankmode=5;
}
function t6(pname,cpower,cl1,cl2,cbonus) {
  top.pname+=pname+",";
  top.cpower+=cpower+",";
  top.cl1+=cl1+",";
  top.cl2+=cl2+",";
  top.cbonus+=cbonus+",";
  top.rankmode=6;
}
function t7(pname,race,alig) {
  top.pname+=pname+",";
  top.race+=race+",";
  top.alig+=alig+",";
  top.rankmode=7;
}
function t8(pname,race,alig) {
  top.pname+=pname+",";
  top.race+=race+",";
  top.alig+=alig+",";
  top.rankmode=8;
}
function t9(pname,quest) {
  top.pname+=pname+",";
  top.quest+=quest+",";
  top.rankmode=9;
}
function t10(pname,channel) {
  top.pname+=pname+",";
  top.channel+=channel+",";
  top.rankmode=10;
}
function tstuff(pname,race,banked) {
  top.pname+=pname+",";
  top.race+=race+",";
  top.banked+=banked+",";
  top.rankmode=10;
}
function t11(pname1,pname2) {
  top.pname+=pname1+",";
  top.race+=pname2+",";
  top.rankmode=11;
}
function t12(pname,pkill) {
  top.pname+=pname+",";
  top.race+=pkill+",";
  top.rankmode=12;
}
function t13(pname,pkill,plvl) {
  top.pname+=pname+",";
  top.race+=pkill+",";
  top.lvl+=plvl+",";
  top.rankmode=13;
}
function t14(pname,cpower,cl1,cl2,cbonus) {
  top.pname+=pname+",";
  top.cpower+=cpower+",";
  top.cl1+=cl1+",";
  top.cl2+=cl2+",";
  top.cbonus+=cbonus+",";
  top.rankmode=14;
}
function tX() {
  top.upd_ranks();
}
//-->
