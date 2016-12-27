function loginPlayer(a){
	if (document.all["icanread"].checked == false) {
		return;
	}
  document.all["btn_enter"].disabled = true;
  document.all["btn_pass"].disabled = true;
  document.all["btn_create"].disabled = true;
  secondrun = false;
  if (a==1) {
  	secondrun = true;
  }
  if(navigator.cookieEnabled == false) {
    alert ('Your Browser does not support Cookies, please enable and try again!');
    return;
  }
  var pName = document.enter.l.value;
  var fSize = document.enter.fonts[document.enter.fonts.selectedIndex].value;
  top.setCookie("fSize",fSize);
  var loggedPlayer = top.getCookie("loginName");
  var loggedTime = top.getCookie("loginTime");
  top.eraseLoginCookie(); 
  if ((loggedPlayer == null) && (loggedTime == null)){
    var curTime = new Date().getTime();
    var aDate = new Date();
    aDate.setTime(curTime + (1000 * 60 * 60 * 24 * 365));
    top.setCookie("loginName", pName, aDate.toGMTString());
    top.setCookie("loginTime", curTime, aDate.toGMTString());
    top.loginTime = curTime;
    top.loginName = pName;
    document.enter.submit();
  }
  else {
       	if(secondrun) {
       	  alert('loggedplayer: ' + loggedPlayer + ';loggedtime: ' + loggedTime + ';');
       	  alert('A problem regarding cookies has been detected.\nPlease clear your temp files and cookies.');
       	  top.location.href="http://www.msn.com";
       	} else {
		loginPlayer(1);
	}
  }
}

function enabler() {
	document.all["btn_enter"].disabled = false;
  	document.all["btn_pass"].disabled = false;
  	document.all["btn_create"].disabled = false;
}