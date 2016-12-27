 
// Set a cookie name-value pair.
// name - name of the cookie (required)
// value - value of the cookie (required)
// [expire] - expiration date of the cookie (defaults to seven days)
// [path] - path for which the cookie is valid (defaults to path of
//	calling document)
// [domain] - domain for which the cookie is valid (defaults to domain of
//	calling document)
// [secure] - Boolean value indicating if the cookie transmission requires
//	a secure transmission
//function setCookie(name, value, expire, path, domain, secure) {
//	var duration = 7;
//	var today = new Date()
//	var defaultExpire = new Date()
//	defaultExpire.setTime(today.getTime() + 1000*60*60*24*duration)
//	var currentCookie = name + "=" +
//		escape(value) +
//		((expire == null) ?
//			("; expires=" + defaultExpire.toGMTString()) : 
//			("; expires=" + expire.toGMTString())) +
//		((path == null) ? "; path=" + path : "") +
//		((domain == null) ? "; domain=" + domain : "") +
//		((secure == null) ? "; secure" : "");
//	if ((name + "=" + escape(value)).length > 4000)
//		alert("Cookie exceeds 4KB and will be cut!");
//	document.cookie = currentCookie;
//}
function setCookie(name, value, expire) {
	var duration = 7;
	var today = new Date()
	var defaultExpire = new Date()
	defaultExpire.setTime(today.getTime() + 1000*60*60*24*duration)
	var currentCookie = name + "=" +
		escape(value) +
		((expire == null) ?
			("; expires=" + defaultExpire.toGMTString()) : 
			("; expires=" + expire.toGMTString()));
	document.cookie = currentCookie;
}

function setCookie(name, value) {
	var currentCookie = name + "=" + escape(value) 
	document.cookie = currentCookie;
}

// name - name of the desired cookie
// return value of specified cookie or null if cookie does not exist
function getCookie(name) {
	var prefix = name + "="
	var cookieStartIndex = document.cookie.indexOf(prefix)
	if (cookieStartIndex == -1)
		return null
	var cookieEndIndex = document.cookie.indexOf(";", cookieStartIndex + prefix.length)
	if (cookieEndIndex == -1)
		cookieEndIndex = document.cookie.length
	return unescape(document.cookie.substring(cookieStartIndex + prefix.length, cookieEndIndex))
}

// name - name of the cookie
// [path] - path of the cookie (must be same as path used to create cookie)
// [domain] - domain of the cookie (must be same as domain used to create cookie)
//function deleteCookie(name, path, domain) {
//	if (getCookie(name)) {
//		document.cookie = name + "=" + 
//			((path == null) ? "; path=" + path : "") +
//			((domain == null) ? "; domain=" + domain : "") +
//			"; expires=Thu, 01-Jan-70 00:00:01 GMT"
//	}
//}
function deleteCookie(name) { 
	var exp = new Date(); 
	exp.setTime(exp.getTime() - 1); 
	var cval = getCookie(name); 
	document.cookie = name + "=" + cval + "; expires=" + exp.toGMTString();
}

//if cookie is erased do not do any action from main or battle anymore
//for that reason the login and pname are set to ""
function eraseLoginCookie(){
	deleteCookie("loginName")
	deleteCookie("loginTime")
	}
  

//checks the login-cookies on existence and values
function checkLoginCookie() {
 	  var loggedPlayer = top.getCookie("loginName");
	  var loggedTime = top.getCookie("loginTime");
	  var retValue = ((loggedPlayer == top.loginName) && (loggedTime == top.loginTime));
	  if (retValue == false) {
	  	alert('loggedplayer: ' + loggedPlayer + '; loginname: ' + top.loginName + '; loggedtime: ' + loggedTime + '; logintime: ' + top.loginTime + ';');
	  }
	  return retValue;
}

function checkLoginCookieForChat(){
  var loggedPlayer = top.getCookie("loginName");
  var loggedTime = top.getCookie("loginTime");
  return (((loggedPlayer == top.loginName) && (loggedTime == top.loginTime)) ||(loggedPlayer != top.loginName));
}
