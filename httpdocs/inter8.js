<!--

function ctrln(vx){

if(pname==""||version!=vx){

alert("New Interface, Refresh.");

top.location.href=gUrl+"/game.php";

return 0;

}else{

return 2;

}

}

function make_stats(){

var ti=top.invent.document;

ti.open("text/html");

ti.writeln(cs());

ti.writeln("<span id=stat_page></span>");

ti.writeln("</body></html>");

ti.body.background=bgpic[zone_bg[loc_zone]].src;

ti.close();

}

function make_toiminta(){

var tt=top.toiminta.document;

tt.open("text/html");

tt.writeln(cs());

tt.writeln("<span id=act_up></span>");

tt.writeln("<span id=act_bstuff></span>");

tt.writeln("<span id=act_down></span>");

tt.writeln("</body></html>");

tt.body.background=bgpic[zone_bg[loc_zone]].src;

tt.close();

}

function upd_stats(){

sd="";drop_s=0;

if(statmode==0){

sd+="<center><h4>"+pname+" "+lastname+"</h4>";

if(clan!=""&&clan!="a"){

sd+="("+clan+" clan)";

}

sd+="</center><table><tr><td>"+race;

if(tstatus==1){

sd+=" (lvl "+lvl+")</td><td>Turns "+turns+"</td>";

}else{

sd+="</td><td>Level "+lvl+"</td>";

}

sd+="</tr><tr><td>Str: "+pil(str)+"</td><td>Dex: "+pil(dex)+"</td></tr><tr><td>Ntl: "+pil(ntl)+"</td><td>Wis: "+pil(wis)+"</td></tr><tr><td>Vit: "+pil(vit)+"</td><td>";

if(health>=vit){

sd+="<font color=43F4FF>";

}else if(health<vit&&health>=(vit*0.6)){

sd+="<font color=00CA18>";

}else if(health<(vit*0.6)&&health>=(vit*0.2)){

sd+="<font color=E5FF39>";

}else if(health<(vit*0.2)&&health>0){

sd+="<font color=FF017F>";

}else{

sd+="<font color=D2D0D0>";

}

sd+="Life: <b>"+pil(health)+" ("+pil(vit)+")</b></font></td></tr><tr><td>Gold: "+pil(gold)+"</td><td>(Bank: "+pil(banked)+")</td></tr><tr><td>Free Exp: </td><td>"+pil(exp)+"</td></tr>";

if(freelvl>0){

sd+="<tr><td>Free: </td><td>"+freelvl+"</td></tr>";

}else{

sd+="<tr><td>Next: </td><td>"+pil(nxlvl)+"</td></tr>";

}

sd+="<tr><td>Alignment: </td><td><b>";

if(alignx>100){

sd+="<font color=43F4FF>";

}else if(alignx<-100){

sd+="<font color=FF017F>";

}else{

sd+="<font color=D2D0D0>";

}

sd+=pil(alignx)+"</b></td></tr></table>";

sd+="<a href='javascript:top.statmod(1)'>Items</a>";

if(loc_zone!=10&&loc_zone!=21&&loc_zone!=22){

sd+=" <a href='javascript:top.statmod(3)'>Zone Map</a>";

}

}else if(statmode==1){

sd+="<center><h4>"+pname+" "+lastname+"</h4></center>";

if(rhand!=0){

rhandeq=idesc(rhand-1,1);

}else{

rhandeq="Hand";

}

if(lhand!=0){

lhandeq=idesc(lhand-1,1);

}else{

lhandeq="Hand";

}

if(spellone!=0){

spelloneeq=idesc(spellone-1,1);

}else{

spelloneeq="None";

}

if(spelltwo!=0){

spelltwoeq=idesc(spelltwo-1,1);

}else{

spelltwoeq="None";

}

if(armor!=0){

armoreq=idesc(armor-1,1);

}else{

armoreq="Rags";

}

if(accx!=0){

acceq=idesc(accx-1,1);

}else{

acceq="Nothing";

}

ax1=0;sd+="<table><tr><td>Right Hand:</td><td>"+rhandeq+"</td></tr><tr><td>Left Hand:</td><td>"+lhandeq+"</td></tr><tr><td>Armor:</td><td>"+armoreq+"</td></tr><tr><td>Spell One:</td><td>"+spelloneeq+"</td></tr><tr><td>Spell Two:</td><td>"+spelltwoeq+"</td></tr><tr><td>Accessory:</td><td>"+acceq+"</td></tr></table>"

+"<form name='inventoryDisplay' method=POST action=main2.php target=arvot>"

+"<table><tr><td><select name=k>";

for(i=0;i<30;++i){

if(invlist[i]!=0){

iname=idesc(i,2);ax1++;

sd+="<option value="+i+">"+iname;

}

}

sd+="</select></td></tr>"

+"<tr><td><input type=hidden name=a value='q'>"+lp()+"<input type=button value='Equip' onclick='this.disabled=true;top.equipAction();'>&nbsp;&nbsp;<a href='javascript:top.actmod(6)'>TRADE On/Off</a>"

+"&nbsp;&nbsp;<a href='javascript:top.statmod(0)'>Stats</a></td></tr><tr><td colspan=2>"+ax1+"/30 slots used</td></tr></table></form>";

}else if(statmode==2){

sd+="<center><h4>"+pname+" "+lastname+"</h4></center><br><table><tr><td>Skills:</td></tr><tr><td>Sword: "+masteries[0]+"%</td><td>Axe: "+masteries[1]+"%</td></tr><tr><td>Staff: "+masteries[2]+"%</td><td>Mace: "+masteries[3]+"%</td></tr><tr><td>Armor: "+masteries[8]+"%</td><td>Doublehit: "+masteries[9]+"%</td></tr><tr><td>Fire: "+masteries[4]+"%</td><td>Cold: "+masteries[5]+"%</td></tr><tr><td>Air: "+masteries[6]+"%</td><td>Arcane: "+masteries[7]+"%</td></tr></table><a href='javascript:top.statmod(0)'>Stats</a>";

}else if(statmode==3){

zone=zonelist[loc_zone];

if(loc_zone!=10){

sd+="<center>"+zone+"<br><br><table border='1'>";

for(a1=zkoko;a1>=0;a1--){

sd+="<tr>";

for(a2=0;a2<=zkoko;a2++){

if(a1==loc_y&&a2==loc_x){

sd+="<td align='center' width='16' bgcolor='009900'>";

}else{

sd+="<td align='center' width='16'>";

}

if((zexit%10)==a1&&(zexit-(zexit%10))/10==a2){

sd+="<b>E</b>";

}else if((zshop%10)==a1&&(zshop-(zshop%10))/10==a2){

sd+="<b>S</b>";

}else if((zshrine%10)==a1&&(zshrine-(zshrine%10))/10==a2){

sd+="<b>R</b>";

}else if((zmage%10)==a1&&(zmage-(zmage%10))/10==a2){

sd+="<b>M</b>";

}else if((zbank%10)==a1&&(zbank-(zbank%10))/10==a2){

sd+="<b>B</b>";

}else if(a1==1&&a2==1&&loc_zone==26){

sd+="<b>Q</b>";

}else if(a1==0&&a2==1&&loc_zone==16){

sd+="<b>A</b>";

}else if(a1==2&&a2==2&&loc_zone==37){

sd+="<b>A</b>";

}else if(a1==1&&a2==2&&loc_zone==16){

sd+="<b>N</b>";

}else if(a1<10&&a2<10&&loc_zone==32){

sd+="<b>H</b>";

}else if(a1==3&&a2==2&&loc_zone==24){

sd+="<b>G</b>";

}else if(a1==3&&a2==2&&loc_zone==31){

sd+="<b>G</b>";

}else if(a1==2&&a2==2&&loc_zone==33){

sd+="<b>G</b>";

}else if(a1==2&&a2==2&&loc_zone==16){

sd+="<b>C</b>";

}else if(a1<10&&a2<18&&loc_zone==41){

sd+="<b>K</b>";

}else{

sd+="=";

}

sd+="</td>";

}

sd+="</tr>";

}

sd+="</table></center>";

}

sd+="<br><a href='javascript:top.statmod(0)'>Stats</a>";

}

top.invent.stat_page.innerHTML=sd;

}

function upd_toiminta(){

al="";

zone=zonelist[loc_zone];

ad="<table><tr><form><td width='300'>You are at "+loc_x+", "+loc_y+" in <strong>"+zone+"</strong></td><td></td><td align='center'><a href='javascript:top.mform(\"m\",1,0,0)'><img name='mN' border='0'></a></td><td></td></tr><tr>";

if(zone_here==10){

ad+="<td><center><a href='javascript:top.mform(\"m\",5,0,0)'>Wilderness</a>";

}else if(zone_here==15&&(loc_zone==21||loc_zone==46)){

ad+="<td><center><a href='javascript:top.mform(\"m\",5,0,0)'>Ta'lorn</a>";

}else if(zone_here==19&&(loc_zone==22||loc_zone==34||loc_zone==47)){

ad+="<td><center><a href='javascript:top.mform(\"m\",5,0,0)'>Demon Gate</a>";

}else if(zone_here==21){

if(loc_zone==15){

ad+="<td><center><a href='javascript:top.mform(\"m\",6,0,0)'>DoL</a>";

}else{

ad+="<td><center><a href='javascript:top.mform(\"m\",5,0,0)'>DoL</a>";

}

}else if(zone_here==22){

if(loc_zone==19){

ad+="<td><center><a href='javascript:top.mform(\"m\",6,0,0)'>DoC</a>";

}else{

ad+="<td><center><a href='javascript:top.mform(\"m\",5,0,0)'>DoC</a>";

}

}else if(zone_here>34&&zone_here<40){

if(loc_zone<zone_here){

ad+="<td><center><a href='javascript:top.mform(\"m\",6,0,0)'>"+top.zonelist[zone_here]+"</a>";

}else{

ad+="<td><center><a href='javascript:top.mform(\"m\",5,0,0)'>"+top.zonelist[zone_here]+"</a>";

}

}else if(zone_here>0||(zone_here==0&&loc_zone==10&&loc_x==14&&loc_y==14)){

ad+="<td><center><a href='javascript:top.mform(\"m\",6,0,0)'>Enter "+top.zonelist[zone_here]+"</a>";

}else{

ad+="<td><center>";

}

if(stuff_here==0||stuff_here==7){

ad+="&nbsp; <form><input type=button value='Refresh' onclick='this.disabled=true;top.mform(\"rf\",0,0,0);'></td></form>";

}else{

ad+="</td>";

}

ad+=dirs;

if(stuff_here==0){

ad+="<center><table><tr><form method=POST name=stuph action=battle4.php target=arvot><td><center><select name=a onchange='top.tlist()'><option value='n'>Fight Creatures";

if(loc_zone>8&&loc_zone!=12&&loc_zone!=15&&loc_zone!=21&&loc_zone!=24&&loc_zone!=25&&loc_zone!=26&&loc_zone!=34&&loc_zone!=45&&loc_zone!=46&&loc_zone!=37){

ad+="<option value='d'>Players";

}

ad+="</select><select name=k>";

for(i=0;i<mnum;++i){

ad+="<option value="+i+">"+mlist[i];

}

if(zhunt>0){

ad+="<option value=999>"+zbname;

}

fmc=top.location.href.charAt(fmt);

ad+="</select>"+lp()+"<input type=hidden name=m value='"+fmc+"'>"

+"<span id=nefb><input type=button value='New Fight' onclick='this.disabled=true;top.newFightAction();'></span></td></form></tr></table></center>";

make_toiminta();

top.toiminta.act_up.innerHTML=ad;

top.toiminta.stuph.a.options.selectedIndex=lastfight;

tlist();

upd_fight();

}else if(stuff_here==4){

ad+="<table valign='top'><tr><td>Bank.</td></tr><tr><td><form method=POST target=arvot onsubmit='top.chat.msg.target.focus();'>"

+"<input type=text SIZE=15 MAXLENGTH=20 name=k value=''>&nbsp;"+strb()+"&nbsp;"+lp()+"<input type=button value='OK' onclick='this.disabled=true;top.mform(this.form.a.value,this.form.k.value,0,0);'></form></td></tr>"

+"<tr><form><td>Transfer <input type=text SIZE=10 MAXLENGTH=10 name=k value=''> Gold to <input type=text SIZE=16 MAXLENGTH=20 name=m value=''>"

+"<input type=button value='Transfer' onclick='this.disabled=true;top.mform(\"x\",this.form.k.value,this.form.m.value,0);'></td></form></tr></table>";

}else if(stuff_here==1){

ad+="Shrine";

if(health==0){

ad+="<form><input type=button value='Rise!' onclick='this.disabled=true;top.mform(\"r\",0,0,0);'></form>";

}

ad+="<form>"

+"<select name=k>";

for(i=0;i<21;++i){

if(i!=10)

ad+="<option value="+i+">"+zonelist[i];

}

ad+="<option value=26>"+zonelist[26]+"<option value=21>"+zonelist[21]+"<option value=22>"+zonelist[22]+"<option value=32>"+zonelist[32]+"<option value=40>"+zonelist[40]+"<option value=41>"+zonelist[41];

if(accx>0&&invlist[accx-1]==41180000){

cost=0;

}else{

cost=20000;

}

ad+="<input type=button value='Teleport ("+cost+")' onclick='this.disabled=true;top.mform(\"t\",this.form.k.value,0,0);'></form>";

}else if(stuff_here==2){

ad+="Welcome to the Shop.<form name=buyitems>Buy Items: <select name=k onchange='top.shop()'><option value=1>Swords<option value=2>Axes<option value=3>Staves<option value=4>Maces<option value=9>Body Armor<option value=10>Shields";

if(loc_zone==17||loc_zone==24){

ad+="<option value=41>Accessories";

}

ad+="</select><select name=m>";

for(i=0;i<max_wep;++i){

ad+="<option value="+i+">"+top.wep_list1[i]+" ("+pil(Math.round(50*Math.pow(1.7,i)))+")";

}

ad+="</select>"

+"<input type=button value='Buy' onclick='this.disabled=true;top.mform(\"u\",this.form.k.value,this.form.m.value,0);'>"

+"&nbsp;&nbsp;<input type=button value='Examine' onclick='javascript:top.examine(4)'></form><form name=sellitems>Sell Items: <select name=k>";

for(i=0;i<30;++i){

if(invlist[i]>0){

iname=idesc(i,1);

if(rhand==(i+1)||lhand==(i+1)||spellone==(i+1)||spelltwo==(i+1)||armor==(i+1)||accx==(i+1)){

}else{

ad+="<option value="+i+">"+iname;

}

}

}

ad+="</select>"

+"<input type=button value='Sell' onclick='this.disabled=true;top.sellScript(this.form.k.options[this.form.k.selectedIndex].value,escape(this.form.k.options[this.form.k.selectedIndex].text));'>"

+"&nbsp;&nbsp;<input type=button value='Examine' onclick='javascript:top.examine(1)'></form>";

}else if(stuff_here==3){

ad+="You enter the Magic Tower.<form name=buyspells>Buy Items: <select name=k onchange='top.mage()'><option value=5>Fire<option value=6>Cold<option value=7>Air<option value=8>Arcane</select><select name=m>";

for(i=0;i<max_spells;++i){

ad+="<option value="+i+">"+top.spell_list1[i]+" ("+pil(Math.round(50*Math.pow(1.7,i)))+")";

}

ad+="</select>"

+"<input type=button value='Buy Spell' onclick='this.disabled=true;top.mform(\"u\",this.form.k.value,this.form.m.value,0);'>"

+"&nbsp;&nbsp;<input type=button value='Examine' onclick='javascript:top.examine(5)'></form><form method=POST>Enchant Items: <select name=k>";

for(i=0;i<30;++i){

if(invlist[i]>9999&&invlist[i]<41000000&&(invlist[i]%10000==0||(invlist[i]%10000<100&&(invlist[i]>10990000||invlist[i]%1000000>=150000)))){

iname=idesc(i,1);

if(rhand==(i+1)||lhand==(i+1)||spellone==(i+1)||spelltwo==(i+1)||armor==(i+1)){

}else{

ad+="<option value="+i+">"+iname;

}

}

}

ad+="</select> with <select name=m>";

for(i=0;i<30;++i){

if(invlist[i]>0&&invlist[i]<100){

iname=idesc(i,1);

ad+="<option value="+i+">"+iname;

}

}

ad+="</select>"

+"<input type=button value='Enchant' onclick='this.disabled=true;top.enchantScript(this.form.k.options[this.form.k.selectedIndex].value,this.form.m.options[this.form.m.selectedIndex].value,escape(this.form.k.options[this.form.k.selectedIndex].text),escape(this.form.m.options[this.form.m.selectedIndex].text));'></form>"

+"<form method=POST target=arvot onsubmit='top.chat.msg.target.focus();'>Locate Player: <input type=text SIZE=16 MAXLENGTH=20 name=k value=''>&nbsp;";

if(accx>0&&invlist[accx-1]==41180000){

cost=0;

}else{

cost=20000;

}

ad+=lp()+"<input type=hidden name=a value='i'>";

ad+="<input type=button value='Find ("+cost+")' onclick='this.disabled=true;top.mform(\"i\",this.form.k.value,0,0);'></form>";

}else if(stuff_here==5){

cost=lvl*100;

ad+="Royal Academy.<form><input type=button value='View Masteries ("+cost+")' onclick='this.disabled=true;top.mform(\"a\",0,0,0);'></form>";

}else if(stuff_here==6){

ad+="<table valign='top'><tr><td>Trade.</td><form><td><input type=button value='Check Items' onclick='this.disabled=true;top.mform(\"k1\",0,0,0);'></td></form></tr><tr><form name=market1><td colspan=2>Offer <select name=k>";

for(i=0;i<30;++i){

if(invlist[i]!=0){

iname=idesc(i,2);

if(rhand==(i+1)||lhand==(i+1)||spellone==(i+1)||spelltwo==(i+1)||armor==(i+1)||accx==(i+1)){

}else{

ad+="<option value="+i+">"+iname;

}

}

}

ad+="</select>"

+" to <input type=text SIZE=16 MAXLENGTH=20 name=m value=''></td></tr><tr><td colspan=2> for <input type=text SIZE=10 MAXLENGTH=10 name=n value=''> Gold <input type=button value='Examine' onclick='javascript:top.examine(2)'>&nbsp;&nbsp;<input type=button value='OK' onclick='this.disabled=true;top.tradeScript(this.form.k.options[this.form.k.selectedIndex].value,escape(this.form.k.options[this.form.k.selectedIndex].text),escape(this.form.m.value),escape(this.form.n.value));'></td></form></tr>";

tradenbr=tid.length-1;

if(tradenbr>0){

ad+="<tr><form name=market2><td colspan=2>Accept <select name=k>";

for(i=0;i<tradenbr;++i){

ad+="<option value="+tid[i]+">"+trader[i]+" offers you a "+gd(titem[i])+" for "+pil(tprice[i])+" gold.";

}

ad+="</select><br><input type=button value='Examine' onclick='javascript:top.examine(3)'>&nbsp;&nbsp;"

+"<input type=button value='OK' onclick='this.disabled=true;top.mform(\"k3\",this.form.k.value,0,0);'></td></form></tr></table>";

}else{

ad+="<tr><td colspan=2>No items offered.</td></tr></table>";

}

}else if(stuff_here==7){

ad+="<table><tr><td colspan=7><center><b>Bounty Board</b></td></tr>"

+"<tr><td><center>Defeat:</td><td><center>Reward:</td><td><center>Status</td><td><center>Time left</td><td colspan=2><center>Limits</td><td>&nbsp;</td></tr>";

if(questz>0){

for(a1=0;a1<questz;a1++){

qlist=qmlist[a1];

ad+="<tr><td><center>A certain "+qlist[(qmon[a1]%20)]+"<br>in "

+zonelist[qzone[a1]]+"</td><td><center>";

if(qgold[a1]>0){

ad+=" "+pil(qgold[a1])+" gold";

}

if(qexp[a1]>0){

ad+="<br>"+pil(qexp[a1])+" exp";

}

if(qitem[a1]>0){

ad+="<br>"+gd(qitem[a1]);

}

ad+=".</td><td><center>";

if(qstatus[a1]==""){

ad+="Active";

}else if(qstatus[a1]=="y"){

ad+="You signed up.";

}else{

ad+="Completed by:<br>"+qstatus[a1];

}

ad+="</td><td><center>"+(3-qlife[a1])+" h.</td><td><center>Min level:<br>"+qminlvl[a1]+"</td></td><td><center>Max level:<br>"+qlvl[a1]+"</td>";

if(qstatus[a1]==pname){

ad+="<form><td><center><input type=button value='Get Reward' onclick='this.disabled=true;top.mform(\"q2\",0,0,0);'></td></form>";

}else if(qstatus[a1]==""){

su_qn=qnum[a1];

ad+="<form><td><center><input type=button value='Sign Up' onclick='this.disabled=true;top.mform(\"q1\",Math.round(\""+su_qn+"\"),0,0);'></td></form>";

}else{

ad+="<td>&nbsp;</td>";

}

ad+="</tr>";

}

}

ad+="</table>";

}else if(stuff_here==8){

ad+="<table><tr><td colspan=2><center>";

if(hsname==""){

ad+="For Sale</td></tr><tr><form><td colspan=2><center><input type=button value='Purchase Land' onclick='this.disabled=true;top.mform(\"h1\",0,0,0);'></td></form></tr>";

}else{

ad+="Welcome to the Estate of "+hsname;

if(hsname2!=""){

ad+=" and "+hsname2;

}

ad+="</td></tr><tr><td colspan=2><center>"+hsdesc+"</td></tr>";

if(h_flag!=""){

ad+="<tr><td colspan=2><center><img src='"+h_flag+"' width=300 height=80></td></tr>";

}

}

if(hsname==pname||hsname2==pname){

ad+="<tr><form><td><center>"

+"Inventory: <select name=k>";ax1=0;

for(i=0;i<30;++i){

if(invlist[i]>0){

iname=idesc(i,1);ax1++;

if(rhand==(i+1)||lhand==(i+1)||spellone==(i+1)||spelltwo==(i+1)||armor==(i+1)||accx==(i+1)){

}else{

ad+="<option value="+i+">"+iname;

}

}

}

ad+="</select>"

+"<input type=button value='Store' onclick='this.disabled=true;top.mform(\"h2\",this.form.k.value,0,0);'></td></form><td width=120>"+ax1+" of 30 slots used.</td></tr>";

ad+="<tr><form><td><center>Stash: <select name=k>";ax1=0;

if((h_status%2)==1){

hi_max=30;

}else if((h_status%4)==2){

hi_max=50;

}else{

hi_max=10;

}

for(i=0;i<hi_max;++i){

if(hslist[i]>0){

iname=gd(hslist[i]);ax1++;

ad+="<option value="+i+">"+iname;

}

}

ad+="</select><input type=button value='Take' onclick='this.disabled=true;top.mform(\"h3\",this.form.k.value,0,0);'></td></form><td width=120>"+ax1+" of "+hi_max+" slots used.</td></tr><tr><form><td><center><select name=k>";

if((h_status%2)==1){h_cost=new Array(0,20,12,12,4);}

else{h_cost=new Array(20,35,12,12,4);}

for(i=(h_status%4);i<5;++i){

if(!((h_status>>i)&1)){

ad+="<option value="+i+">"+h_up[i]+" ("+h_cost[i]+"M)";

}

}

if(h_status==30){

ad+="<option value=0>No upgrades left";

}

ad+="</select><input type=button value='Upgrade' onclick='this.disabled=true;top.mform(\"h5\",this.form.k.value,0,0);'></td></form>";

ad+="<tr><form><td><center><input type=button value='Total Healing' onclick='this.disabled=true;top.mform(\"he\",0,0,0);'></td></form></tr>";

if(hsname==pname){

if(((h_status>>2)&1)){

ad+="<tr><form method=POST target=arvot onsubmit='javascript:top.chat.msg.target.focus();'><td colspan=2><center>"+lp()+"<input type=hidden name=a value='h6'><input type=text SIZE=30 MAXLENGTH=100 name=k value=''>"

+"<input type=button value='Set Description' onclick='this.disabled=true;top.mform(\"h6\",this.form.k.value,0,0);'></td></form></tr>";

}

if(((h_status>>3)&1)){

ad+="<tr><form method=POST target=arvot onsubmit='this.disabled=true;top.chat.msg.target.focus();'><td colspan=2><center>"+lp()+"<input type=hidden name=a value='h7'><input type=text SIZE=30 MAXLENGTH=100 name=k value=''>"

+"<input type=button value='Change Flag' onclick='this.disabled=true;top.mform(\"h7\",this.form.k.value,0,0);'></td></form></tr>";

}

if(((h_status>>4)&1)){

ad+="<tr><form method=POST target=arvot onsubmit='this.disabled=true;top.chat.msg.target.focus();'><td colspan=2><center>"

+lp()+"<input type=hidden name=a value='h8'><input type=text SIZE=25 MAXLENGTH=20 name=k value=''>"

+"<input type=button value='Set Shared Owner' onclick='this.disabled=true;top.mform(\"h8\",this.form.k.value,0,0);'></td></form></tr>";

}

}

}

ad+="</table>";

}else if(stuff_here==9){

ad+="<table valign='top'><tr><form><td>"+reinc

+"<input type=button value='Reincarnation' onclick='this.disabled=true;top.mform(\"nc\",this.form.k.value,0,0)'></td></form></tr>"

+"<tr><td><a href='reinc.htm' target='_blank'>Help</a></td></tr></table>";

}else if(stuff_here==10){

ad+="<form>Disenchant Items: <select name=k>";

for(i=0;i<30;++i){

if(invlist[i]>0){

iname=idesc(i,1);

if(rhand==(i+1)||lhand==(i+1)||spellone==(i+1)||spelltwo==(i+1)||armor==(i+1)||accx==(i+1)){

}else if((invlist[i]%100)>0&&invlist[i]>99&&invlist[i]<41000000){

ad+="<option value="+i+">"+iname;

}

}

}

ad+="</select><input type=button value='Disenchant (100k)' onclick='this.disabled=true;top.disenchantScript(this.form.k.options[this.form.k.selectedIndex].value,escape(this.form.k.options[this.form.k.selectedIndex].text));'></form>"

+"You can get a blessing for your sacrifices.<form>";

if(loc_zone==31){

cost=200000+Math.max((lvl+freelvl)*100+alignx,0)*10;

}else if(loc_zone==33){

cost=400000+(lvl+freelvl)*1000;

}else{

cost=200000+Math.max((lvl+freelvl)*100-alignx,0)*10;

}

ad+="<input type=button value='Sacrifice Gold ("+pil(cost)+")' onclick='this.disabled=true;top.mform(\"pr\",0,0,0);'></form>";

if(loc_zone==33){

ad+="<form>Upgrade Shadow to Mystic: <select name=k>";

for(i=0;i<30;++i){

if(invlist[i]>10990000&&invlist[i]<21000000){

iname=idesc(i,1);

if(rhand==(i+1)||lhand==(i+1)||spellone==(i+1)||spelltwo==(i+1)||armor==(i+1)||accx==(i+1)){

}else{

i_num=((invlist[i]%1000000)-(invlist[i]%10000))/10000;

if(i_num<20){

cost=(i_num+5)*4;

}else{

cost=(i_num+5)*8;

}

ad+="<option value="+i+">"+iname+" ("+cost+"M)";

}

}

}

ad+="</select><input type=button value='Upgrade' onclick='this.disabled=true;top.mform(\"my\",this.form.k.value,0,0);'></form>";

}

}else if(stuff_here==11){

ad+="<table><tr><td>The Rusty Butterknife Inn.</td></tr><tr><td><form><select name=k><option value=1>Dwarven Ale (+dex) 1k<option value=2>Beer (+str) 1k<option value=3>Elven Wine (+wis) 1k<option value=4>Ambrosia (+ntl) 1k<option value=5>Red Bull (+life) 1k<option value=6>Sobe (+all stats) 10k<option value=7>Hair of the Dog (sober up) 100k</select></td></tr><tr><td>"

+"<input type=button value='Drink' onclick='this.disabled=true;top.mform(\"ta\",this.form.k.value,0,0);'></form></td></tr>";

}else if(stuff_here==12){

ad+="<table><tr><td><center>Clan Hall</td></tr>";

if(clan==""||clan=="a"){

ad+="<tr><form method=POST target=arvot onsubmit='javascript:top.chat.msg.target.focus();'><td><center>"+lp()+"<input type=hidden name=a value='c1'>"

+"Name: <input type=text SIZE=25 MAXLENGTH=30 name=k value=''> <input type=button value='Create Clan (10 Million)' onclick='this.disabled=true;top.mform(\"c1\",this.form.k.value,0,0);'></td></form></tr>";

if(clan!="a"){

ad+="<tr><td><center><input type=button value='Apply to Clan (1 Million)' onclick='this.disabled=true;top.mform(\"c7\",0,0,0);'></td></form></tr></table>";

}else{

ad+="</table>";

}

}else{

ad+="<tr><form><td><center>Clan: <b>"+clan+"</b> ruled by <b>"+cleader;

if(cleader2!=""){

ad+="</b> and <b>"+cleader2;

}

ad+="</b></td></tr>";

if(pname==cleader){

ad+="<tr><form method=POST target=arvot onsubmit='javascript:top.chat.msg.target.focus();'><td><center>"

+lp()+"<input type=hidden name=a value='c2'>co leader <input type=text SIZE=20 MAXLENGTH=20 name=k value=''>"

+"&nbsp;<input type=button value='Select' onclick='this.disabled=true;top.mform(\"c2\",this.form.k.value,0,0);'></td></form></tr>";

}

if(pname==cleader||pname==cleader2){

ad+="<tr><form method=POST target=arvot onsubmit='javascript:top.chat.msg.target.focus();'><td><center>"

+lp()+"<input type=hidden name=a value='c3'>Accept player: <input type=text SIZE=20 MAXLENGTH=20 name=k value=''>"

+"&nbsp;<input type=button value='Accept (1M)' onclick='this.disabled=true;top.mform(\"c3\",this.form.k.value,0,0);'></td></form></tr>"

+"<tr><form method=POST target=arvot onsubmit='javascript:top.chat.msg.target.focus();'><td><center>"

+lp()+"<input type=hidden name=a value='c4'>Remove players: <input type=text SIZE=20 MAXLENGTH=20 name=k value=''>"

+"&nbsp;<input type=button value='Remove' onclick='this.disabled=true;top.mform(\"c4\",this.form.k.value,0,0);'></td></form></tr>"

+"<tr><form><td><center>Bonus: <select name=k>";

for(i=1;i<8;++i){

if((15*i)<=cpower){ad+="<option value="+i+">"+c_bonus[i-1];

}

}

ad+="</select>&nbsp;<input type=button value='Select' onclick='this.disabled=true;top.mform(\"c5\",this.form.k.value,0,0);'></td></form></tr>";

}

ad+="<tr><td><center><input type=button value='Leave' onclick='this.disabled=true;top.leaveClanScript();'></td></form></tr></table>";

}

}else if(stuff_here==13){

if(kdclan==""){

if(clan!=""&&clan!="a"&&(pname==cleader||pname==cleader2)){

ad+="<center>Available"

+"<br><form><input type=button value='Settle Land' onclick='this.disabled=true;top.mform(\"d1\",0,0,0);'></form></center>";

}else{

ad+="<center>0nly clan leaders can settle.";

}

}else{

ad+="<center><b>"+kddesc+"</b><br><i>The kingdom of "+kdclan+"</i><br>"

+"<table><tr><td>Defence: "

+kd_dlist[kddef]+"</td><td>HP: "+pil(kdhealth)+"</td></tr>"

+"<tr><td>Mine: "+kd_mlist[kdmine]+"</td><td>Misc: "+kd_xlist[kdmisc]+"</td></tr>"

+"<tr><td>Tax: "+kdtax+"%</td><td>Treasury: "+kdgold+"</td></tr></table>";

if(kdclan==clan&&(pname==cleader||pname==cleader2)){

ad+="<table><tr><form method=POST target=arvot onsubmit='javascript:top.chat.msg.target.focus();'><td>"

+"<input type=text SIZE=15 MAXLENGTH=10 name=k value=''>&nbsp;"

+"<select name=a><option value='d2'>Set Tax<option value='d3'>Withdraw Gold</select>&nbsp;"+lp()

+"<input type=button value='OK' onclick='this.disabled=true;top.mform(this.form.a.value,this.form.k.value,0,0);'></form></td></tr>"

+"<tr><form name=buykd><td>Upgrade: <select name=k onchange='top.kdup()'><option value=1>Defence<option value=2>Mine<option value=3>Misc</select><select name=m>";

for(i=1;i<=Math.min(cpower/15,11);++i){

ad+="<option value="+i+">"+top.kd_dlist[i]+" ("+Math.pow(2,i)+"M)";

}

ad+="</select>"

+"<input type=button value='OK' onclick='this.disabled=true;top.mform(\"d6\",this.form.k.value,this.form.m.value,0);'></form></td></tr>"

+"<tr><form method=POST target=arvot onsubmit='javascript:top.chat.msg.target.focus();'><td><center>"+lp()

+"<input type=hidden name=a value='d5'><input type=text SIZE=30 MAXLENGTH=100 name=k value=''>"

+"<input type=button value='Change Flag' onclick='this.disabled=true;top.mform(\"d5\",this.form.k.value,0,0);'></td></form></tr>"

+"<tr><form method=POST target=arvot onsubmit='javascript:top.chat.msg.target.focus();'><td><center>"+lp()+"<input type=hidden name=a value='d4'>"

+"<input type=text SIZE=30 MAXLENGTH=100 name=k value=''><input type=button value='Change Description' onclick='this.disabled=true;top.mform(\"d4\",this.form.k.value,0,0);'></td></form></tr></table>";

}else if(kdclan!=clan){

ad+="<form><input type=button value='Overthrow Kingdom' onclick='this.disabled=true;top.mform(\"d7\",0,0,0);'></form></center>";

}

ad+="<center><img src='"+kdflag+"' width=300 height=80>";

}

}

if(nxlvl<=exp||freelvl>0){

al+="<form><table><tr><td>select a stat</td><td>"+strs()+"</td></tr></table></form>";

}

if(actionmsg!="x"){

al+="<center><font color='fffffa'><b>"+actionmsg+"</b></font><br></center>";

actionmsg="x";

}

if(stuff_here!=0){

make_toiminta();

top.toiminta.act_up.innerHTML=ad;

}

var tt=top.toiminta.document;

tt.mN.src=mpic[0].src;

tt.mW.src=mpic[1].src;

tt.mS.src=mpic[2].src;

tt.mE.src=mpic[3].src;

top.toiminta.act_down.innerHTML=al;

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

cb="<input name=joku1 value='chat' type=button onclick='top.chatmod(0);'";

if(chatmode==0)

cb+=" class='c'";

cb+=">";

cb+="<input name=joku1 value='roleplay' type=button onclick='top.chatmod(1);'";

if(chatmode==1)

cb+=" class='c'";

cb+=">";

cb+="<input name=joku1 value='sales' type=button onclick='top.chatmod(2);'";

if(chatmode==2)

cb+=" class='c'";

cb+=">";

cb+="<input name=joku1 value='clan' type=button onclick='top.chatmod(3);'";

if(chatmode==3)

cb+=" class='c'";

cb+=">";

top.chat.chanbut.innerHTML=cb;

oldchatx=0;oldrolex=0;oldsalex=0;oldclanx=0;

if(chatsize>0||pmsize>0){

for(i=40;i>=(pmsize+chatsize);i--){

oldchatnames[i]=oldchatnames[i-(pmsize+chatsize)];

oldchattxt[i]=oldchattxt[i-(pmsize+chatsize)];

oldchattype[i]=oldchattype[i-(pmsize+chatsize)];

}

}

if(rolesize>0||pmsize>0){

for(i=40;i>=(pmsize+rolesize);i--){

oldrolenames[i]=oldrolenames[i-(pmsize+rolesize)];

oldroletxt[i]=oldroletxt[i-(pmsize+rolesize)];

oldroletype[i]=oldroletype[i-(pmsize+rolesize)];

}

}

if(salesize>0||pmsize>0){

for(i=40;i>=(pmsize+salesize);i--){

oldsalenames[i]=oldsalenames[i-(pmsize+salesize)];

oldsaletxt[i]=oldsaletxt[i-(pmsize+salesize)];

oldsaletype[i]=oldsaletype[i-(pmsize+salesize)];

}

}

if(clansize>0||pmsize>0){

for(i=40;i>=(pmsize+clansize);i--){

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

for(i=0;i<40;++i){

if(chatmode==0){

xname=oldchatnames[i];xtxt=oldchattxt[i];xtype=oldchattype[i];

}else if(chatmode==1){

xname=oldrolenames[i];xtxt=oldroletxt[i];xtype=oldroletype[i];

}else if(chatmode==2){

xname=oldsalenames[i];xtxt=oldsaletxt[i];xtype=oldsaletype[i];

}else if(chatmode==3){

xname=oldclannames[i];xtxt=oldclantxt[i];xtype=oldclantype[i];

}

if(xname!=null&&xname!=""){

if(!(isNaN(Number(xtype)))){

xtype=Number(xtype);

}

if(xtype<39||xtype>61){

switch(xtype){

case 0:

chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='00AAEE'>"+xname+"</font></a> says: <font color='fffffa'>"+xtxt+"</font><br>";

break;

case 1:

chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='fffffa'><i>"+xname+"</font></a> <font color='F4E0B8'>"+xtxt+"</i></font><br>";

break;

case 2:

chatstuff+="<font color='00EE00'><b>"+xtxt+"</b></font><br>";

break;

case 3:

chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='DDDD50'>"+xname+"</font></a> says: <font color='fffffa'>"+xtxt+"</font><br>";

break;

case 4:

chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='D00000'>"+xname+"</font></a> says: <font color='fffffa'>"+xtxt+"</font><br>";

break;

case 5:

chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='orange'>"+xname+"</a> says: "+xtxt+"</font><br>";

break;

case 6:

chatstuff+="<font color='fffffa'><b><i>"+xtxt+"</i></b></font><br>";

break;

case 7:

chatstuff+="<b><i><font color='red'>The Demon</font> <font color='#999999'>"+xtxt+"</font></i></b><br>";

break;

case 8:

chatstuff+="<b><i><font color='red'>The Demoness</font> <font color='#999999'>"+xtxt+"</font></i></b><br>";

break;

case 9:

chatstuff+="<b><i><font color='fffffa'>The Priest</font> <font color='FFD700'>"+xtxt+"</font></i></b><br>";

break;

case 10:

chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='DDDD50'>"+xname+"</font></a> says: <font color='fffffa'>"+xtxt+"</font><br>";

break;

case 11:

chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='D00000'>"+xname+"</font></a> says: <font color='fffffa'>"+xtxt+"</font><br>";

break;

case 12:

chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='00AAEE'><b>"+xname+"</b></font></a> says: <font color='fffffa'>"+xtxt+"</font><br>";

break;

case 13:

chatstuff+="<font color='FF6600'>Mod Warning: "+xtxt+"</font><br>";

break;

case 14:

chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><b>"+rb(xname)+"</b></a> says: <font color='fffffa'><b>"+xtxt+"</b></font><br>";

break;

case 15:

chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='orange'><b>"+xname+"</a> says: "+xtxt+"</b></font><br>";

break;

case 16:

chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='orange'><b>"+xname+"</a> says: "+xtxt+"</b></font><br>";

break;

case 17:

chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='00AAEE'>"+xname+"</font></a> says: <font color='fffffa'>"+xtxt+"</font><br>";

break;

case 18:

chatstuff+="<b><i><font color='fffffa'>The Priestess</font> <font color='FFD700'>"+xtxt+"</font></i></b><br>";

break;

case 20:

chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='00AAEE'><b>"+xname+"</b></font></a> says: <font color='fffffa'>"+xtxt+"</font><br>";

break;

case 21:

chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='FEDC18'>"+xname+"</a> gives you "+pilpm(xtxt)+"</font><br>";

break;

case 22:

chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='FEDC18'>"+xname+"</a> gives you "+gdpm(xtxt)+"</font><br>";

break;

case 23:

chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='FF3737'>"+xname+"</a> killed you!</font><br>";

break;

case 24:

chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='FF3737'>"+xname+"</a> attacked you!</font><br>";

break;

case 25:

chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='FF3737'>"+xname+"</a> attacked you, but died.</font><br>";

break;

case 26:

chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='00EE00'>"+xname+"</a> "+xtxt+"</font><br>";

break;

case 27:

chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='3F7EFF'>"+xname+"</a> "+xtxt+"</font><br>";

break;

case 28:

chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='C0FFFF'><b>"+xname+"</a> has slain '"+xtxt+"'!</b></font><br>";

zhunt=0;lastmon=0;

break;

case 29:

chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='COFFFF'>"+xname+"</a>"+qd(xtxt)+"!</font><br>";

break;

case 30:

chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='00EE00'>"+xname+"</font></a> (mod chat) <font color='FF3737'>"+xtxt+"</font><br>";

break;

case 31:

chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='006633'>"+xname+"</a> "+xtxt+"</font><br>";

break;

case 32:

chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='3F7EFF'><b>"+xname+"</a> "+xtxt+"</b></font><br>";

break;

case 33:

chatstuff+="<b>"+rb(xtxt)+"</b><br>";

break;

default:

chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='0099DD'>"+xname+"</font></a> <b>("+xtype+")</b> <font color='fffffa'>"+xtxt+"</font><br>";

break;

}

}else{

if(xtype>39&&xtype<140){

chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='00CC00'>"+xname+"</font></a> ("+rnamea[xtype-40]+") says: <font color='fffffa'>"+xtxt+"</font><br>";

}else{

chatstuff+="<a href='javascript:top.tell(\""+xname+"\")'><font color='0099DD'>"+xname+"</font></a> ("+xtype+") says: <font color='fffffa'>"+xtxt+"</font><br>";

}

}

}

}

top.chat.chatstr.innerHTML=chatstuff;

chatsent=0;

}

function upd_fight(){

ab=f();

if(lastmon<1000){

if(lastmon==999){

mname="<b>"+zbname+"</b>";lastmonx=mnum;

}else{

mspec=mdesc(lastmon);lastmonx=lastmon%20;

mname=mlist[lastmonx]+mspec;

}

if(mname.charAt(0)=="A"||mname.charAt(0)=="O"||mname.charAt(0)=="E"||mname.charAt(0)=="U"||mname.charAt(0)=="I"){

mname="An "+mname;

}else{

mname="A "+mname;

}

if(lastaction=="n"){

ab+="<font color='fffffa'>You aim for "+mname+"</font><br>";

}else if(battlestr!="."){

ab+="<font color='fffffa'>You attack "+mname+"</font><br>";

}

}else{

if(lastaction=="d"){

ab+="<font color='fffffa'>You assault "+opname+".</font><br>";

}else if(battlestr!="."){

ab+="<font color='fffffa'>You attack "+opname+".</font><br>";

}

mname=opname;

}

if(battlestr!="."&&battlestr!="a."){

bm=battlestr.split(",");

a0=battlestr.charAt(battlestr.length-4);

a1=battlestr.charAt(battlestr.length-3);

if(a0=="v"||a1=="s"||a1=="r"||a0=="d"||a0=="s"){

mx=0;

}else{

mx=1;

}

for(i=0;i<bm.length;++i){

if(bm[i].charAt(0)=="r"){

ab+="<font color='FD5411'><b>";

if(loc_zone!=40||lastmon<1000){

ab+="You have been killed, R.I.P.";

}else{

ab+="You have been defeated.";

}

ab+="</b></font>";

}

else if(bm[i].charAt(0)=="s"){

ab+="<font color='FD5411'><b>";

if(loc_zone!=40||lastmon<1000){

ab+="Enemy is dead, R.I.P.";

}else{

ab+="Enemy has been defeated";

}

ab+="</b></font>";

if(lastmon==999){

zhunt=0;lastmon=0;tlist();

}

if(bm[i].charAt(1)=="d"){

ab+="<font color='0088EE'><i>You find a gem!</i></font>";

drop_s=1;

}

if(bm[i].charAt(1)=="g"){

ab+="<font color='0088EE'><i>You find the enemies purse!</i></font>";

drop_s=1;

}

if(bm[i].charAt(1)=="m"){

ab+="<font color='0088EE'><i>You mined a gem!</i></font>";

drop_s=1;

}

if(bm[i].charAt(1)=="i"){

ab+="<br><font color='0088EE'><b>You find a Shadow Item!</b></font>";

drop_s=1;

}

if(bm[i].charAt(1)=="t"){

ab+="<br><font color='0088EE'><b>The Gods awarded your brutal fight!</b></font>";

drop_s=1;

}

if(bm[i].charAt(1)=="a"){

ab+="<br><font color='0088EE'><b>You won Shimlar!</b></font>";

drop_s=1;

}

if(bm[i].charAt(1)=="u"){

ab+="<br><font color='0088EE'><b>You find an item just like one you have!</b></font>";

drop_s=1;

}

if(bm[i].charAt(1)=="r"){

ab+="<br><font color='0088EE'><b>You find a random item!</b></font>";

drop_s=1;

}

if(bm[i].charAt(1)=="p"){

ab+="<br><font color='0088EE'><b>A piece of your equipment became better!</b></font>";

drop_s=1;

}

}

else if(bm[i].charAt(0)=="v"){

ab+="<font color='00DDDD'><b>";

if(bm[i].charAt(1)=="d"){

ab+="<br>All life has fled out of you!";

}else if(bm[i].charAt(1)=="x"){

ab+="<br>Enemy is already dead!";

if(lastmon==999){

zhunt=0;lastmon=0;tlist();

}

}else if(bm[i].charAt(1)=="z"){

ab+="<br>Player dead or does not exist.";

}else if(bm[i].charAt(1)=="n"){

ab+="<br>No fighting allowed here!";

}else if(bm[i].charAt(1)=="m"){

ab+="<br>No duels allowed.";

}else if(bm[i].charAt(1)=="t"){

ab+="<br>Player is not here.";

}else if(bm[i].charAt(1)=="p"){

pkd=bm[i].split("p");

ab+="<br>You can kill in "+pkd[1]+" seconds.";

}

ab+="</b></font>";

}

else if(bm[i].charAt(0)=="b"){

ab+="<br><font color='C0FFFF'><b>Beast life left: </b>";

}

else if((bm[i].charAt(0)=="u")||(bm[i].charAt(0)=="e")){

if(bm[i].charAt(0)=="u"){

ye="You ";

ey=" the enemy for ";

}else{

ye="Enemy ";

ey=" you for ";

}

if((bm[i].charAt(1)=="f")||(bm[i].charAt(1)=="s")){

if(bm[i].charAt(2)=="c"){

ab+="<font color='FD5411'>"+ye;

switch(bm[i].charAt(3)){

case "1":ab+="SLICED";break;

case "2":ab+="SCRAGGED";break;

case "3":ab+="WHACKED";break;

case "4":ab+="CRUSHED";break;

case "5":ab+="INCINERATED";break;

case "6":ab+="FROSTED";break;

case "7":ab+="BLASTED";break;

case "9":ab+="DAMAGED";break;

case "0":ab+="SPIKED";break;

}

}else{

ab+="<font color='0088EE'>"+ye;	

switch(bm[i].charAt(2)){

case "1":ab+="slashed";break;

case "2":ab+="chopped";break;

case "3":ab+="thwapped";break;

case "4":ab+="bashed";break;

case "5":ab+="burned";break;

case "6":ab+="chilled";break;

case "7":ab+="shocked";break;

case "9":ab+="hurt";break;

case "0":ab+="smited ";break;

}

}

ab+=ey;

}else{

ab+="<font color='00CC00'>";

switch(bm[i].charAt(1)){

case "h":ab+=ye+"healed for ";break;

case "m":ab+=ye+"missed</font><br>";break;

case "t":ab+=ye+"fizzled</font><br>";break;

case "y":ab+="Full Health</font><br>";break;

}

}

}else if(bm[i]!=""&&bm[i]!="."){

ab+=pil(bm[i])+"!</font><br>";

}

}

battlestr=".";

ab+="</td></tr></table></center>";

}else if(battlestr=="a."){

mx=1;

/* }else if(bdelay==100){

mx=1; */

}else{

mx=0;

}

top.toiminta.act_bstuff.innerHTML=ab;

fightdelay(tstatus);

}

function sellScript(sa1,sa2){

doSell=confirm("Sell "+unescape(sa2)+" ?");

if(doSell){mform("s",sa1,0,0);}

}

function leaveClanScript(){

doLeave=confirm("Leave the clan?");

if(doLeave){mform("c6",0,0,0);}

}

function enchantScript(ea1,ea2,ea3,ea4){

doEnchant=confirm("Enchant "+unescape(ea3)+" with "+unescape(ea4)+"?");

if(doEnchant){mform("e",ea1,ea2,0);}

}

function disenchantScript(da1,da2){

doEnchant=confirm("Disenchant "+unescape(da2)+"?");

if(doEnchant){mform("gp",da1,0,0);}

}

function tradeScript(ta1,ta2,ta3,ta4){

doTrade=confirm("Offer a "+unescape(ta2)+" to "+unescape(ta3)+" for "+unescape(ta4)+" gold?");

if(doTrade){mform("k2",ta1,unescape(ta3),unescape(ta4));}

}

function mform(xa,xk,xm,xn){

if(top.checkLoginCookie()){

if(dx1==0){

dx1=1;

setTimeout("dsub1()",900);

top.chat.xform.a.value=xa;

top.chat.xform.k.value=xk;

top.chat.xform.m.value=xm;

top.chat.xform.n.value=xn;

top.chat.xform.submit();

}else{

alert("Please wait!");

}

top.chat.msg.target.focus();

}else{

alert('Logged out!');

top.location.href=gUrl;

}

}

function shop(){

var tdb=top.toiminta.buyitems;

a1=tdb.k.options.selectedIndex+1;

if(a1==1){

wep_list=wep_list1;

}else if(a1==2){

wep_list=wep_list2;

}else if(a1==3){

wep_list=wep_list3;

}else if(a1==4){

wep_list=wep_list4;

}else if(a1==5){

armor_list=armor_list1;

}else if(a1==6){

armor_list=armor_list2;

}else if(a1==7){

ax_list=acc_list;

}

if(a1>=1&&a1<=4){

tdb.m.length=max_wep;

for(i=0;i<max_wep;++i){

tdb.m.options[i].text=wep_list[i]+" ("+pil(Math.round(50*Math.pow(1.7,i)))+")";

tdb.m.options[i].value=i;

}

}else if(a1>=5&&a1<=6){

tdb.m.length=max_eq;

for(i=0;i<max_eq;++i){

tdb.m.options[i].text=armor_list[i]+" ("+pil(Math.round(50*Math.pow(1.7,i)))+")";

tdb.m.options[i].value=i;

}

}else{

tdb.m.length=25;

for(i=0;i<25;++i){

price=0;

if(i<5){

price=25000000;

}else if(i<10){

price=50000000;

}else if(i<17){

price=100000000;

}else if(i<20){

price=250000000;

}else if(i<24){

price=500000000;

}else if(i<25){

price=10000000;

}

tdb.m.options[i].text=ax_list[i]+" ("+pil(price)+")";

tdb.m.options[i].value=i;

}

}

}

function mage(){

var tdb=top.toiminta.buyspells;

a1=tdb.k.options.selectedIndex+5;

if(a1==5){

spell_list=spell_list1;

}else if(a1==6){

spell_list=spell_list2;

}else if(a1==7){

spell_list=spell_list3;

}else if(a1==8){

spell_list=spell_list4;

}else if(a1==8){

spell_list=spell_list4;

}else if(a1==9){

spell_list=mi_list;

}

if(a1>=5&&a1<=8){

tdb.m.length=max_spells;

for(i=0;i<max_spells;++i){

tdb.m.options[i].text=spell_list[i]+" ("+pil(Math.round(50*Math.pow(1.7,i)))+")";

tdb.m.options[i].value=i;

}

}else{

tdb.m.length=5;

for(i=0;i<10;++i){

tdb.m.options[i].text=spell_list[i]+" ("+pil(10000)+")";

tdb.m.options[i].value=i;

}

}

}

function kdup(){

var tdb=top.toiminta.buykd;

a1=tdb.k.options.selectedIndex+1;

if(a1==1){

kd_list=kd_dlist;

}else if(a1==2){

kd_list=kd_mlist;

}else if(a1==3){

kd_list=kd_xlist;

}

if(a1>1&&a1<=3){

tdb.m.length=6;

for(i=0;i<6;++i){

tdb.m.options[i].text=kd_list[i+1]+" ("+(20*Math.pow(2,i-1))+"M)";

tdb.m.options[i].value=i+1;

}

}else{

tdb.m.length=Math.min(((cpower-7)/15),12);

for(i=1;i<Math.min(((cpower-7)/15),12);++i){

tdb.m.options[i-1].text=kd_list[i]+" ("+Math.pow(2,i-1)+"M)";

tdb.m.options[i-1].value=i;

}

}

}

function tlist(){

var tts=top.toiminta.stuph;

a1=tts.a.selectedIndex;

if(a1==1){

a2=duelnames.length-1;

if(a2>0){

tts.k.length=a2;

for(i=0;i<a2;++i){

tts.k.options[i].text=duelnames[i]+" ("+duelalign[i]+")";

tts.k.options[i].value=duelid[i];

}

}else{

tts.k.length=1;

tts.k.options[0].text="-=Nobody Here=-";

tts.k.options[0].value="0";

tts.k.options[0].style.color="000000";

}

}else{

tts.k.length=mnum+zhunt;

for(i=0;i<mnum;++i){

tts.k.options[i].text=mlist[i];

tts.k.options[i].value=i;

tts.k.options[i].style.color="000000";

}

if(zhunt>0){

tts.k.options[mnum].text=zbname;

tts.k.options[mnum].value=999;

}

lastmonx=lastmon%20;

if(lastmon==999){

lastmonx=mnum;

}

tts.k.options.selectedIndex=lastmonx;

}

}

function getnewchat(){

if(top.checkLoginCookieForChat()){

if(chatonly<50){

if(chatsent==0){

chatsent=1;

chatonly++;

top.chat.newchat.submit();

setTimeout("cset0()",1000);

}

setTimeout("getnewchat()",cdel);

}else{

top.location.href=gUrl+"/game.php";

alert("Please login again :)");

}

}else{

alert('Logged out!');

top.location.href=gUrl;}

}

function chatsend(){

if(top.checkLoginCookieForChat()){

if(chatsent==0){

chatsent=1;
top.chat.msg.k.value=chatmode;
top.chat.msg.submit();

setTimeout("cset0()",1000);

}

}else{

alert('Logged out!');

top.location.href=gUrl;}

}

function statmod(x){

if(x==3&&loc_zone!=10&&loc_zone!=21&&loc_zone!=22){

statmode=x;

}else if(x!=3){

statmode=x;

}

upd_stats();

}

function actmod(x){

if(x==stuff_here){

stuff_here=sb_here;sb_here=0;

}else{

sb_here=stuff_here;stuff_here=x;

}

upd_toiminta();

}

function chatmod(x){

chatmode=x;

top.chat.msg.k.value=chatmode;

upd_chat();

if(x==1){

top.chat.msg.target.value="/RolePlay";

top.chat.chatres.innerHTML="See related links for guides.";

}else if(x==2){

top.chat.msg.target.value="";

top.chat.chatres.innerHTML="";

}else if(x==0){

top.chat.msg.target.value="";

top.chat.chatres.innerHTML="<b><a href='"+gUrl+"/rules.htm' target='_blank'>Chat Rules</a></b>";

}else{

top.chat.msg.target.value="";

top.chat.chatres.innerHTML="";

}

}

function upd_level(){

if(lvl<249){

if(lvl>9){

j1=Math.round((lvl-5)/10);

j2=lvl-(j1*10);

nxlvl=Math.round(1000*(Math.pow(1.35,j1)-1)/(0.35))

+Math.round(100*j2*(Math.pow(1.35,j1)));

}else{

nxlvl=100*lvl;

}

}else if(lvl<999){

nxlvl=5000000+(lvl-249)*200000;

}else{

nxlvl=300000000+(lvl-999)*3700000;

}

}

function examine(exv){

if(exv==1){

ix=top.toiminta.sellitems.k.options.value;

exi=invlist[ix];

}else if(exv==2){

ix=top.toiminta.market1.k.options.value;

exi=invlist[ix];

}else if(exv==3){

ix=top.toiminta.market2.k.options.selectedIndex;

exi=titem[ix];

}else if(exv==4){

exi=(top.toiminta.buyitems.k.value*100+itemClassFromPosition(top.toiminta.buyitems.m.value*1))*10000;

}else if(exv==5){

exi=(top.toiminta.buyspells.k.value*100+itemClassFromPosition(top.toiminta.buyspells.m.value*1))*10000;

}

if(exi>9999&&exi<41000000){

i_type=Math.round((Math.round((exi-5000)/10000)-50)/100);

i_num=(Math.round((exi-5000)/10000))-i_type*100;

if(i_type==1||i_type==11||i_type==21){

iname="sword";

}else if(i_type==2||i_type==12||i_type==22){

iname="axe";

}else if(i_type==3||i_type==13||i_type==23){

iname="staff";

}else if(i_type==4||i_type==14||i_type==24){

iname="mace";

}else if(i_type==5||i_type==15||i_type==25){

iname="fire";

}else if(i_type==6||i_type==16||i_type==26){

iname="cold";

}else if(i_type==7||i_type==17||i_type==27){

iname="air";

}else if(i_type==8||i_type==18||i_type==28){

iname="arcane";

}else if(i_type==9||i_type==19||i_type==29){

iname="armor";

}else if(i_type==10||i_type==20||i_type==30){

iname="shield";

}

if(i_type>10||i_num>14){

if((gemmed1=(exi%100))>0){

gs=Math.round((gemmed1+12)/25);

gem_num=(gemmed1%25);

gem_name=gem_list[gem_num-1];

gm="This "+iname+" has a "+gs+" "+gem_name+" and 1 empty socket. ";

}

if((gemmed2=(((exi%10000)-gemmed1)/100))>0){

gs2=Math.round((gemmed2+12)/25);

gem_num2=(gemmed2%25);

gem_name2=gem_list[gem_num2-1];

gm="This "+iname+" has a "+gs+" "+gem_name+" and a "+gs2+" "+gem_name2;

}

if(gemmed1==0&&gemmed2==0){

gm="This "+iname+" has 2 empty sockets.<br>";

}

}else{

if((gemmed1=(exi%100))>0){

gs=Math.round((gemmed1+12)/25);

gem_num=(gemmed1%25);

gem_name=gem_list[gem_num-1];

gm="This "+iname+" has a "+gs+" "+gem_name;

}else{

gm="This "+iname+" has 1 empty socket.<br>";

}

}

if(i_type>20){

gm+="Shop pays "+pil(50000*(i_num+1))+". IC: "+i_num+".<br>";

}else if(i_type>10){

gm+="Shop pays "+pil(5000*(i_num+1))+". IC: "+i_num+".<br>";

}else{

gm+="Shop pays "+pil(Math.round(25*Math.pow(1.7,positionFromItemClass(i_num))))+". IC: "+i_num+".<br>";

}

if(i_type>20&&i_num>4){

if((i_type==28)||(i_type==30)){

gm+="<b>Needs lvl "+(20*i_num)+"</b>";

}else{

gm+="<b>Needs lvl "+(20*(i_num-5))+"</b>";

}

}else if(i_type>10&&i_num>9){

gm+="<b>Needs lvl "+(20*(i_num-10))+"</b>";

}else if(i_type<11&&i_num>9){

gm+="<b>Needs lvl "+(20*(i_num-10))+"</b>";

}else{

gm+="No level requirements";

}

if(i_type%10==0){

if(i_type>20){

stat_req=20*i_num;

}else if(i_type>10){

stat_req=70*i_num;

}else{

stat_req=120*i_num;

}

gm+=" <i>STR needed: "+stat_req+"</i><br>";

}else if(i_type%10<5){

if(i_type>20){

stat_req=100*i_num;

}else if(i_type>10){

stat_req=150*i_num;

}else{

stat_req=200*i_num;

}

gm+=" <i>STR needed: "+stat_req+"</i><br>";

}else if(i_type%10<8){

if(i_type>20){

stat_req=100*i_num;

}else if(i_type>10){

stat_req=150*i_num;

}else{

stat_req=200*i_num;

}

gm+=" <i>NTL needed: "+stat_req+"</i><br>";

}else if(i_type%10==8){

if(i_type>20){

stat_req=30*i_num;

}else if(i_type>10){

stat_req=80*i_num;

}else{

stat_req=130*i_num;

}

gm+=" <i>NTL needed: "+stat_req+"</i><br>";

}else if(i_type%10==9){

if(i_type>20){

stat_req=50*i_num;

}else if(i_type>10){

stat_req=100*i_num;

}else{

stat_req=150*i_num;

}

gm+=" <i>VIT needed: "+stat_req+"</i><br>";

}

top.toiminta.act_bstuff.innerHTML=gm;

}else if(exi>0&&exi<41000000){

if((gemmed=(exi%100))>0){

gem_num=(exi%25);

gem_name=gem_list[gem_num-1];

gs=Math.round((gemmed+12)/25);

gm="Grade "+gs+" "+gem_name+".<br>Shop pays "+pil(10000*gs)+".<br>";

top.toiminta.act_bstuff.innerHTML=gm;

}

}else if(exi>0&&exi>=42000000){

gm="Gift<br>Shop pays 1<br>";

top.toiminta.act_bstuff.innerHTML=gm;

}else if(exi>0&&exi>=41000000){

gm="Accessory<br>Shop pays 5 million<br>";

top.toiminta.act_bstuff.innerHTML=gm;

}

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

top.chat.msg.btn_chat.disabled=false;

chatsent=0;

}

function dsub1(){

dx1=0;

}

function idesc(itemcode,dxtype){

i1=itemcode;

iv=invlist[i1];

if(iv!=0){

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

xn="";x=xcode;

x_type=Math.round((Math.round((x-5000)/10000)-50)/100);

x_num=(Math.round((x-5000)/10000))-x_type*100;

x_num=positionFromItemClass(x_num);

if(x_type==1){

xn=wep_list1[x_num];

}else if(x_type==2){

xn=wep_list2[x_num];

}else if(x_type==3){

xn=wep_list3[x_num];

}else if(x_type==4){

xn=wep_list4[x_num];

}else if(x_type==5){

xn=spell_list1[x_num];

}else if(x_type==6){

xn=spell_list2[x_num];

}else if(x_type==7){

xn=spell_list3[x_num];

}else if(x_type==8){

xn=spell_list4[x_num];

}else if(x_type==9){

xn=armor_list1[x_num];

}else if(x_type==10){

xn=armor_list2[x_num];

}else if(x_type==41){

xn=acc_list[x_num];

}else if(x_type==42){

xn=mi_list[x_num];

}else if(x_type==0){

gem_num=x%25;

xn=gem_list[gem_num-1];

}else if(x_type==11){

xn="Phantom Sword "+ro_nums[Math.round((x_num-2)/5)];

}else if(x_type==12){

xn="Phantom Axe "+ro_nums[Math.round((x_num-2)/5)];

}else if(x_type==13){

xn="Phantom Staff "+ro_nums[Math.round((x_num-2)/5)];

}else if(x_type==14){

xn="Phantom Hammer "+ro_nums[Math.round((x_num-2)/5)];

}else if(x_type==15){

xn="Shadow Fire "+ro_nums[Math.round((x_num-2)/5)];

}else if(x_type==16){

xn="Shadow Freeze "+ro_nums[Math.round((x_num-2)/5)];

}else if(x_type==17){

xn="Shadow Shock "+ro_nums[Math.round((x_num-2)/5)];

}else if(x_type==18){

xn="Shadow Heal "+ro_nums[Math.round((x_num-2)/5)];

}else if(x_type==19){

xn="Ghost Armor "+ro_nums[Math.round((x_num-2)/5)];

}else if(x_type==20){

xn="Ghost Shield "+ro_nums[Math.round((x_num-2)/5)];

}else if(x_type==21){

xn="Mystic Blade "+ro_nums[Math.round((x_num-2)/5)];

}else if(x_type==22){

xn="Mystic Hatchet "+ro_nums[Math.round((x_num-2)/5)];

}else if(x_type==23){

xn="Mystic Wand "+ro_nums[Math.round((x_num-2)/5)];

}else if(x_type==24){

xn="Mystic Maul "+ro_nums[Math.round((x_num-2)/5)];

}else if(x_type==25){

xn="Mythic Flame "+ro_nums[Math.round((x_num-2)/5)];

}else if(x_type==26){

xn="Mythic Frost "+ro_nums[Math.round((x_num-2)/5)];

}else if(x_type==27){

xn="Mythic Storm "+ro_nums[Math.round((x_num-2)/5)];

}else if(x_type==28){

xn="Mythic Cure "+ro_nums[Math.round((x_num-2)/5)];

}else if(x_type==29){

xn="Saintly Plate "+ro_nums[Math.round((x_num-2)/5)];

}else if(x_type==30){

xn="Spiked Shield "+ro_nums[Math.round((x_num-2)/5)];

}

if(x_type>0){

if((gemmed1=(x%100))>0){

gs=Math.round((gemmed1+12)/25);

xn+="["+gs+"]";

}

if((gemmed2=(((x%10000)-gemmed1)/100))>0){

gs2=Math.round((gemmed2+12)/25);

xn+="["+gs2+"]";

}

}else{

if((gemmed=(x%100))>0){

gs=Math.round((gemmed+12)/25);

for(gsx=0;gsx<gs;gsx++){

xn+="*";

}

}

}

return xn;

}

function gdpm(x){

if(x!=0){

xs=x.toString();

xsa=xs.split(" ");

xs=gd(xsa[0])+" "+xsa[1]+" "+xsa[2]+" "+xsa[3];

return xs;

}else{

xs="No item was given";

}

}

function qd(qsx){

qspec="";

qx=qsx.split(",");

qxz=zonelist[qx[0]];

qxs=mdesc(qx[1]);

qxm=qx[1]%20;

switch(qx[2]) 
{
case "1":
qxl=mlist1;
break;
case "2":
qxl=mlist2;
break;
case "3":
qxl=mlist3;
break;
case "4":
qxl=mlist4;
break;
case "5":
qxl=mlist5;
break;
case "6":
qxl=mlist6;
break;
case "7":
qxl=mlist7;
break;
case "8":
qxl=mlist8;
break;
case "9":
qxl=mlist9;
break;
case "10":
qxl=mlist10;
break;
case "11":
qxl=mlist11;
break;
case "12":
qxl=mlist12;
break;
case "13":
qxl=mlist13;
break;
case "14":
qxl=mlist14;
break;
case "15":
qxl=mlist15;
break;
case "16":
qxl=mlist16;
break;
case "17":
qxl=mlist17;
break;
case "18":
qxl=mlist18;
break;
case "19":
qxl=mlist19;
break;
case "20":
qxl=mlist20;
break;
case "25":
qxl=mlist25;
break;
case "26":
qxl=mlist26;
break;
case "27":
qxl=mlist27;
break;
case "28":
qxl=mlist28;
break;
case "29":
qxl=mlist29;
break;
case "46":
qxl=mlist46;
break;
case "47":
qxl=mlist47;
break;
case "66":
qxl=mlist66;
break;
}

qspec=" defeated <font color='00FF00'>"+qxl[qxm]+"</font>"+qxs+" in <font color='FFFF00'>"+qxz+"</font>";

return qspec;

}

function mdesc(msx){
if(msx<20){return "";}
msxi=(msx-(msx%20))/10;
switch(msxi) {
case 2:
return"<font color='03AF03'><b> Merchant</b></font>";
case 4:
return"<font color='FFDB31'><b> Veteran</b></font>";
case 6:
return"<font color='FFAEC9'><b> Fanatic</b></font>";
case 8:
return"<font color='FF3737'><b> King</b></font>";
case 10:
return"<font color='FF8965'><b> Fool</b></font>";
case 12:
return"<font color='0085EC'><b> Defender</b></font>";
case 14:
return"<font color='B5B3B3'><b> Assassin</b></font>";
case 16:
return"<font color='43F0FF'><b> Illusionist</b></font>";
case 18:
return"<font color='22AC53'><b> Elder</b></font>";
case 20:
return"<b>"+rb(' Enigma')+"</b></font>";
case 22:
return"<font color='FF9900'><b> Mimic</b></font>";
case 24:
return"<font color='FF00FF'><b> Trainer</b></font>";
case 26:
return"<font color='00CC33'><b> Saint</b></font>";
// case 28:
default:
return"<font color='999999'><b> Undead</b></font>";
}
return"";
}

function pil(x){

signx="";

if(x<0){

signx="-";

x=x*(-1);

}

xs=x.toString();

xs2=signx;p1=xs.length;

for(b1=0;b1<p1;b1++){

xs2+=xs.charAt(b1);

if(((p1-b1-1)%3)==0&&b1!=(p1-1)){

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

function equipAction(){

if(top.checkLoginCookie()){

top.invent.inventoryDisplay.submit();

}

else{

alert('Logged out!');

top.location.href=gUrl;

}

}

function newFightAction(){

if(top.checkLoginCookie()){

top.toiminta.stuph.submit();

}

else{

alert('Logged out!');

top.location.href=gUrl;

}

}

function fightAction(){

if(top.checkLoginCookie()){

top.toiminta.fightForm.submit();

}

else{

alert('Logged out!');

top.location.href=gUrl;

}

}

function castAction(){

if(top.checkLoginCookie()){

top.toiminta.castForm.submit();

}

else{

alert('Logged out!');

top.location.href=gUrl;

}

}

function itemClassFromPosition(pc){

switch(pc){

case 33:

return 36;

case 34:

return 37;

case 35:

return 38;

case 36:

return 41;

default:

return pc;

}

}

function positionFromItemClass(ic){

switch(ic){

case 36:

return 33;

case 37:

return 34;

case 38:

return 35;

case 41:

return 36;

default:

return ic;

}

}

lastname="",pname="",lastaction="",mx=0,fmt=1,fmc=0,opname=""; //bdelay=0,

str=0,dex=0,vit=0,ntl=0,wis=0,health=0,gold=0,banked=0,masteries=0;

race=".",lvl=0,freelvl=0,exp=0,loc_x=0,loc_y=0,loc_zone=0,nxlvl=0,alignx=0;

zone_here=0,stuff_here=0,max_eq=0,max_wep=0,max_spells=0;

zkoko=0,zshop=0,zshrine=0,zmage=0,zbank=0,zexit=0,zhunt=0,zbname="";

titem=0,trader=0,tprice=0,tid=0;sb_here=0,tradex=0,questz=0,mname="";

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