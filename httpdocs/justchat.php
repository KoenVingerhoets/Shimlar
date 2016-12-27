<HTML>
<HEAD>
<META HTTP-EQUIV="Pragma" CONTENT="no-cache">
<META HTTP-EQUIV="cache-control" CONTENT="no-cache">
<META HTTP-EQUIV="Expires" CONTENT="-1">
  <TITLE>Shimlar (chat only)</TITLE>
<script language="Javascript">
if (top.location.href != "http://www.shimlar.org/justchat.php") {
  top.location.href = "http://www.shimlar.org/justchat.php";
};
var login="", pword="", fsize=12;
	function lp() 
	{
		if ((login=="")||(pword=="")) {
			alert("Login or pass are empty");
			top.location.href="http://www.shimlar.org/game.php";
		} else {
			return "<input type=hidden name=l value='"+login+"'><input type=hidden name=p value='"+pword+"'>";
		}
	}
	function cs() {
		return "<html><head><LINK href='/" + csInt() + ".css' rel='stylesheet' type='text/css'></head><body>"; 
	}

	// browser detection
	var browserName=navigator.appName; 
	var browserVer=parseInt(navigator.appVersion); 
	if ((browserName!="Microsoft Internet Explorer") || (browserVer>=5)) 
	{
		alert("You need Internet Explorer 5 or higher to play this game.");
		top.location.href = "http://www.microsoft.com";
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
</script>
<?php
  $randomz = rand(1,50);
  switch ($randomz) {
  	case 5:
  		print "<script language=\"javascript\" src=\"bg0.js\"></script>";
  		print "<script language=\"javascript\">";
  			include 'lnamesc.js';
  		print "</script>";
  		print "<script language=\"javascript\" src=\"interc.js\"></script>";
  		print "<script language=\"javascript\">";
  			include 'cookies.js';
  		print "</script>";
  		break;
  	case 10:
  		print "<script language=\"javascript\" src=\"bg0.js\"></script>";
  		print "<script language=\"javascript\">";
  			include 'lnamesc.js';
  		print "</script>";
  		print "<script language=\"javascript\">";
  			include 'interc.js';
  		print "</script>";
  		print "<script language=\"javascript\" src=\"cookies.js\"></script>";
  		break;
  	case 15:
  		print "<script language=\"javascript\">";
  			include 'bg0.js';
  		print "</script>";
  		print "<script language=\"javascript\">";
  			include 'lnamesc.js';
  		print "</script>";
  		print "<script language=\"javascript\">";
  			include 'interc.js';
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
  			include 'lnamesc.js';
  		print "</script>";
  		print "<script language=\"javascript\" src=\"interc.js\"></script>";
  		print "<script language=\"javascript\" src=\"cookies.js\"></script>";
  		break;
  	default:
  		print "<script language=\"javascript\" src=\"bg0.js\"></script>";
  		print "<script language=\"javascript\" src=\"lnamesc.js\"></script>";
  		print "<script language=\"javascript\" src=\"interc.js\"></script>";
  		print "<script language=\"javascript\" src=\"cookies.js\"></script>";
  		break;
  }
?>
<script language="javascript">
	var theDumbMods;
	var showMac = false;
	var version=29;
	var gUrl="http://www.shimlar.org";
	var urls="<table><tr><td><center><a href='faq.htm' target='_blank'>FAQ</a></td><td><center><a href='manual.htm' target='_blank'>Manual</a></td><td><center><a href='map.htm' target='_blank'>Outworld Map</a></td><td><center><a href='rules.htm' target='_blank'>Chat Rules</a></td><td><center><a href='tops.htm' target='_blank'>Top Lists</a></td><td><center><a href='topmod.htm' target='_blank'>Mods</a></td></tr><tr><td><center><b><a href='/donate/index.shtml' target='_blank'>Support the Game</a></b></td><td><center><a href='javascript:top.refdel(6)'>Average chat</a></td><td><center><a href='javascript:top.refdel(9)'>Slow chat</a></td><td><center><a href='javascript:top.refdel(3)'>Fast chat</a></td><td><center><i><a href='related.htm' target='_blank'>Related sites</a></i></td>";
	var deletedCode = "<script language='javascript'>function keyWhat(e){ if(event.keyCode == 17){ alert('Not allowed.'); event.returnValue=false; } }; document.onkeydown=keyWhat;<\/script>";
	function c() {
			return "<html><head><LINK href='/" + csInt() + ".css' rel='stylesheet' type='text/css'></head><body>" +
			"<center><font color='fffffa'><span id=chatres></span></font></center>" +
 			"<table CELLSPACING=0 CELLPADDING=0 border=0 width='100%' valign='center'><tr>" +
 			"<td width='85%'><form method=POST name=msg id=msg action=scx.php target=arvot onsubmit='return false;'>" +
  		"<input type=text SIZE=70 MAXLENGTH=190 name=target value=''>" + lp() + "<input type=hidden name=k value=0><input type=button value='Speak as " + pname + "' id='btn_chat' name='btn_chat' onclick='top.chatsend();'></td></form>" +
  		"<td><span id=chanbut></span>" +
  		"</td></tr></table>" +
  		"<table border=1 bgcolor='000000' width='100%'>" +
  		"<tr><td class='chat'>" +
  		"<span id=chatstr></span>" +
  		"</td></tr></table>" + urls +
  		"<form method=POST name=newchat action=cx.php target=arvot2>" + lp() + "</form>" +
  		"<form method=POST name=xform action=main2.php target=arvot>" + lp() + "<input type=hidden name=a value=''>" +
  		"<input type=hidden name=k value=''>" +
  		"<input type=hidden name=m value=''>" +
  		"<input type=hidden name=n value=''>" +
  		"</form>" +
  		"<script>document.body.background=top.bgpic[0].src;<\/script>" +
  		"</body></html>";
  	}  	
</script>
</HEAD>
<FRAMESET ROWS="0,0,*" framespacing="0" border="0" frameborder="0">
  <FRAME SRC="empty.htm" NAME="arvot" NORESIZE>
  <FRAME SRC="empty.htm" NAME="arvot2" NORESIZE>
  <FRAME SRC="logonc.htm" NAME="chat" NORESIZE>
</FRAMESET>
<NOFRAMES>
<BODY>
<P>
</BODY>
</NOFRAMES>
</HTML>