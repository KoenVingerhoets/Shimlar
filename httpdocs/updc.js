<!--
top.pname="";top.lvl="";top.cpower="";top.cl1="";top.cl2="";top.cbonus="";top.cid="";
function c1(pname,lvl) {
  top.pname+=pname+",";
  top.lvl+=lvl+",";
  top.cmode=1;
}
function c2(pname,cpower,cl1,cl2,cbonus,cid) {
  top.pname+=pname+",";
  top.cpower+=cpower+",";
  top.cl1+=cl1+",";
  top.cl2+=cl2+",";
  top.cbonus+=cbonus+",";
  top.cid+=cid+",";
  top.cmode=2;
}
function tX() {
  top.upd_clans();
}
//-->
