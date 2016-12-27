<!--

top.pname="";top.race="";top.banked="";top.lvl="";top.quest="";top.exp="";

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

function tstuff(pname,race,banked) {

  top.pname+=pname+",";

  top.race+=race+",";

  top.banked+=banked+",";

  top.rankmode=10;

}



function tX() {

  top.upd_ranks();

}

//-->

