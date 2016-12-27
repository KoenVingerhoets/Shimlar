<HTML>
<HEAD>
<META HTTP-EQUIV="Pragma" CONTENT="no-cache">
<META HTTP-EQUIV="cache-control" CONTENT="no-cache">
<META HTTP-EQUIV="Expires" CONTENT="-1">
  <TITLE> Shimlar </TITLE>
<script language="Javascript">
if (top.location.href != "http://www.shimlar.org/gamenobg.php") {
  top.location.href = "http://www.shimlar.org/gamenobg.php";
};
	var login="",pword="",fsize=12;
	function lp() 
	{
		if ((login=="")||(pword=="")) {
			alert("Login or pass are empty");
			top.location.href="http://www.shimlar.org/game.php";
		} else {
			return "<input type=hidden name=l value='"+login+"'><input type=hidden name=p value='"+pword+"'>";
		}
	};
	function cs() {
		return "<html><head><LINK href='/" + csInt() + ".css' rel='stylesheet' type='text/css'></head><body>"; 
	}
  function csInt() {
		ChSum = parseInt(top.getCookie("fSize"));
		if (isNaN(ChSum)) {
			fsize=12;
		} else {
			fsize = ChSum;
		}
		fsize = Math.max(fsize,12);
		fsize = Math.min(fsize,18);
		return fsize;
	}
	function randOrd(a, b){
		return (Math.round(Math.random())-0.5); 
	}
	function make_str(a,b)	{
			return "<a href='javascript:top.mform(\"v\","+a+",0,0)'>"+b+"</a>";
	} 
	function make_drop(a,b)
	{
		return "<option value=\""+a+"\">"+b+"</option>";
	}
		// browser detection
	var browserName=navigator.appName; 
	var browserVer=parseInt(navigator.appVersion); 
	if ((browserName!="Microsoft Internet Explorer") || (browserVer>=5)) 
	{
		alert("You need Internet Explorer 5 or higher to play this game.");
		top.location.href = "http://www.microsoft.com";
	}
</script>

<?php
  $randomz = rand(1,50);
  switch ($randomz) {
  	case 5:
  		print "<script language=\"javascript\" src=\"bg0.js\"></script>";
  		print "<script language=\"javascript\">";
  			include 'lnames2.js';
  		print "</script>";
  		print "<script language=\"javascript\">";
  			include 'cookies.js';
  		print "</script>";
  		break;
  	case 10:
  		print "<script language=\"javascript\" src=\"bg0.js\"></script>";
  		print "<script language=\"javascript\">";
  			include 'lnames2.js';
  		print "</script>";
  		print "<script language=\"javascript\" src=\"cookies.js\"></script>";
  		break;
  	case 15:
  		print "<script language=\"javascript\">";
  			include 'bg0.js';
  		print "</script>";
  		print "<script language=\"javascript\">";
  			include 'lnames2.js';
  		print "</script>";
  		print "<script language=\"javascript\">";
  			include 'cookies.js';
  		print "</script>";
  		break;
  	case 20:
  		print "<script language=\"javascript\">";
  			include 'bg0.js';
  		print "</script>";
  		print "<script language=\"javascript\">";
  			include 'lnames2.js';
  		print "</script>";
  		print "<script language=\"javascript\" src=\"cookies.js\"></script>";
  		break;
  	default:
  		print "<script language=\"javascript\" src=\"bg0.js\"></script>";
  		print "<script language=\"javascript\" src=\"lnames2.js\"></script>";
  		print "<script language=\"javascript\" src=\"cookies.js\"></script>";
  		break;
  }
  print "<script language=\"javascript\">";
  	include 'inter8.js';
 	print "</script>";
  print "<script language=\"javascript\">";
  	include 'fdelay2.js';
  print "</script>";
?>
<script language="javascript">
	var theDumbMods;
	var showMac = false;
	var version=29;
	var gUrl="http://www.shimlar.org";
	function strb() 
	{
		var strs_array = new Array(new Array("b","Deposit"), new Array("w","Withdraw"), new Array("b2","Deposit All"), new Array("w2","Withdraw All"));
		strs_array.sort(randOrd);
		var strb = "<select name=a>";
		for(i_str=0;i_str<4;i_str++) 
		{
			strb+=make_drop(strs_array[i_str][0],strs_array[i_str][1]);
		}
		return strb+"</select>";
	}
	var reinc="<select name=k><option value=0>Human</option><option value=1>Dwarf</option><option value=2>Elf</option><option value=3>Dark Elf</option><option value=4>Giant</option><option value=5>Troll</option><option value=6>Goblin</option><option value=7>Angel</option><option value=8>Gargoyle</option><option value=9>Balrog (lvl limit 300)</option><option value=10>Kender (lvl limit 300)</option><option value=11>Half Elf (lvl limit 300)</option><option value=12>Dark Angel (lvl limit 600)</option><option value=13>Galatai (lvl limit 600)</option><option value=14>Flame Demon (lvl limit 600)</option><option value=15>Duergar (lvl limit 600)</option><option value=16>Sprite (lvl limit 600)</option><option value=17>Genie (lvl limit 1000)</option><option value=18>Dragon (lvl limit 1000)</option><option value=19>Vampire (lvl limit 1000)</option></select>";
	var urls="<table><tr><td><center><a href='faq.htm' target='_blank'>FAQ</a></td><td><center><a href='manual.htm' target='_blank'>Manual</a></td><td><center><a href='map.htm' target='_blank'>Outworld Map</a></td><td><center><a href='rules.htm' target='_blank'>Chat Rules</a></td><td><center><a href='tops.htm' target='_blank'>Top Lists</a></td><td><center><a href='topmod.htm' target='_blank'>Mods</a></td></tr><tr><td><center><b><a href='/donate/index.shtml' target='_blank'>Support the Game</a></b></td><td><center><a href='javascript:top.refdel(6)'>Average chat</a></td><td><center><a href='javascript:top.refdel(9)'>Slow chat</a></td><td><center><a href='javascript:top.refdel(3)'>Fast chat</a></td><td><center><i><a href='related.htm' target='_blank'>Related sites</a></i></td>";
	var dirs="<td align='right'><a href='javascript:top.mform(\"m\",3,0,0)'><img name='mW' border='0'></a></td><td align='center'><a href='javascript:top.mform(\"m\",2,0,0)'><img name='mS' border='0'></a></td><td align='left'><a href='javascript:top.mform(\"m\",4,0,0)'><img name='mE' border='0'></a></td></form></tr></table>";
	function wm() {};
	function zz() {};
	function strs() 
	{
		var strs_array = new Array(new Array(1,"+STR+"), new Array(2,"+DEX+"), new Array(3,"+NTL+"), new Array(4,"+WIS+"), new Array(5,"+VIT+"), new Array(6,"+ALL+"));
		strs_array.sort(randOrd);
		var strs = "";
		for(i_str=0;i_str<6;i_str++) 
		{
			strs+=make_str(strs_array[i_str][0],strs_array[i_str][1]);
		};
		return strs;
	}
	function c() {
		return "<html><head><LINK href='/" + csInt() + ".css' rel='stylesheet' type='text/css'></head><body>" +
			"<center><font color='fffffa'><span id=chatres></span></font></center><table valign='center'><tr><td width='85%'><form method='POST' name=msg action='scx.php' target=arvot>"+
			"<input type=text SIZE=70 MAXLENGTH=190 name=target value=''>"+lp()+"<input type=hidden name=k value='0'><input type=button value='Send' id=btn_chat name=btn_chat onclick='this.disabled=true;top.chatsend();'></td></form>"+
			"<td><span id=chanbut></span></td></tr></table><table><tr><td class='chat'><span id=chatstr></span></td></tr></table>"+urls+"</tr></table><form method='POST' name=newchat action='cx.php' target=arvot2>"+lp()+"</form>"+
			"<form method='POST' name=xform action='main2.php' target=arvot>"+lp()+"<input type=hidden name=a value=''><input type=hidden name=k value=''><input type=hidden name=m value=''>"+
			"<input type=hidden name=n value=''></form><script>document.body.background=top.bgpic[top.zone_bg[top.loc_zone]].src;<\/script></body></html>";
	}
	function f() {
		return "<center><table CELLSPACING=0 CELLPADDING=0 width='300' cols=2><tr>"+
			"<form method=POST name=fightForm action=battle4.php target=arvot><td><center><input type=hidden name=a value='f'>"+lp()+"<span id=attb></span></td></form>"+
			"<form method=POST name=castForm action=battle4.php target=arvot><td><center><input type=hidden name=a value='c'>"+lp()+"<span id=casb></span></td></form></tr><tr><td colspan=2><center>";
	}
	function ob(txt) 
	{
		/*
		var tLh = txt.length;
		if (tLh == 0) {
			return "";
		}
		tLh--;
		var picker1 = Math.round(Math.random()*tLh);
		var picker2 = Math.round(Math.random()*tLh);
		if (picker1==picker2) {
			picker1 = Math.round(Math.random()*tLh);
		}
		var el1 = txt.charAt(picker1);
		var el2 = txt.charAt(picker2);
		var output = "";
		for(i_txt=0;i_txt<tLh;i_txt++) {
			switch(i_txt) {
				case picker1:
					output+=el2;
					break;
				case picker2:
					output+=el1;
					break;
				default:
					output+=txt.charAt(i_txt);
			}
		}
		return output;
		*/
		/* Don't forget to thank Clerity for this. */
		return txt;
	}
</script>

</HEAD>
<FRAMESET ROWS="260,0,0,*" framespacing="0" border="0" frameborder="0" >
<FRAMESET COLS="325,*" framespacing="0" border="0" frameborder="0">
  <FRAME SRC="welcome.htm" NAME="invent" NORESIZE>
  <FRAME SRC="help.htm" NAME="toiminta" NORESIZE>
</FRAMESET>
  <FRAME SRC="empty.htm" NAME="arvot" NORESIZE>
  <FRAME SRC="empty.htm" NAME="arvot2" NORESIZE>
  <FRAME SRC="logon.htm" NAME="chat" NORESIZE>
</FRAMESET>
<NOFRAMES>
<BODY>
<P>
</BODY>
</NOFRAMES>
</HTML>
