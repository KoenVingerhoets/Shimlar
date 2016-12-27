<!--
function upd_clans(){
  clandesc="<table border=1 width='600'>";
  pname_x=pname.split(",");
  if(cmode==1){
    lvl_x=lvl.split(",");
    clandesc+="<tr><td><center><i><b>Player</b></i></td><td><center><b>Level</b></td></tr>";
    for(i=0;i<pname_x.length-1;++i){
      clandesc+="<tr><td><center><font color='fffffa'>"+pname_x[i]+"</font></td>";
      clandesc+="<td><center><font color='fffffa'>"+lvl_x[i]+"</font></td></tr>";
    }
  }else if(cmode==2){
    cpower_x=cpower.split(",");
    cl1_x=cl1.split(",");
    cl2_x=cl2.split(",");
    cbonus_x=cbonus.split(",");
    cid_x=cid.split(",");
    clandesc+="<tr><td><center><i><b>Clan</b></i></td><td><center><b>Power</b></td><td><center><b>Leader</b></td><td><center><b>Second Leader</b></td><td><center><b>Bonus</b></td><td><center><b>Link</b></td></tr>";
    for(i=0;i<pname_x.length-1;++i){
      if(cbonus_x[i]==0){
        cb_x="-";
      }else{
        cb_x=c_bonus[cbonus_x[i]-1];
      }
      clandesc+="<tr><td><center><font color='fffffa'><b>"+pname_x[i]+"</b></font></td>";
      clandesc+="<td><center><font color='fffffa'><i>"+cpower_x[i]+"</i></b></td>";
      clandesc+="<td><center><font color='fffffa'>"+cl1_x[i]+"</font></td>";
      clandesc+="<td><center><font color='fffffa'>"+cl2_x[i]+"</font></td>";
      clandesc+="<td><center><font color='fffffa'>"+cb_x+"</td>";
      clandesc+="<td><center><font color='fffffa'><a href='claninfo.php?id="+cid_x[i]+"' target='_blank'>clan info</a></font></td></tr>";
    }
  }
  clandesc+="</table>";
  top.main.clanpage.innerHTML=clandesc;
}
pname="",lvl="",cpower="",cbonus="",cl1="",cl2="",rankmode=0,clandesc="",cid="";
c_bonus=new Array("+3 Armor Class","+5% exp a kill","+10% gold a kill","+50% drop chance","1.5x damage","non locatable","+10% temple luck");
//-->
