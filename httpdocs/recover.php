<?php

include '../incz/constvars.inc'; 

init_dbx();

print "<script src=\"updr.js\"></script>";
print "<script src=\"lnames2.js\"></script>";

$usepl = false;
$usecn = false;
$isSent	= false;

if (strlen($_POST["pl"])>3) 
	$usepl = true;
else if (strlen($_POST["cn"]) > 3) {
  $usecn = true;
}
if ($usepl) {
	if(tarkista($_POST["pl"])) {
  		$l=ucwords($_POST["pl"]);
  		$query="Select name as nimi, email, password, login from Players where login='$l'";
  		if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1) {
    			extract(mysql_fetch_array($result));
					$subject = "Shimlar recovery: $nimi";
					$message = "Your password for character named $nimi is : $password.\r\n" .
						"Your login is: $login.\r\n" .
						"Do NOT reply to this message.\r\n" .
						"\r\n" .
						"Lord A";
					$headers = "From: lorda@pandora.be\r\n" .
       			"X-Mailer: PHP/" . phpversion() . "\r\n" .
       			"MIME-Version: 1.0\r\n" .
       			"Content-Type: text/html; charset=utf-8\r\n" .
       			"Content-Transfer-Encoding: 8bit\r\n\r\n";
					$isSent = mail($email, $subject, $message, $headers); 
   				print "<script language='javascript'>";
   				if ($isSent) {
    				print "pr(\"$nimi\");";
    			} else {
    				print "mailError(\"$nimi\");";
    			}
    			print "</script>";
   		} else {
   			print "<script language='javascript'>";
    			ep2(2);
    			print "</script>";
  		}
	} else {
		print "<script language='javascript'>";
  		ep2(3);
  		print "</script>";
	}
} else if($usecn) {
	if(tarkista($_POST["cn"])) {
  		$l=ucwords($_POST["cn"]);
  		$query="Select name as nimi, email, password, login from Players where name='$l'";
  		if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1) {
    			extract(mysql_fetch_array($result));
					$subject = "Shimlar recovery: $nimi";
					$message = "Your password for character named $nimi is : $password.\r\n" .
						"Your login is: $login.\r\n" .
						"Do NOT reply to this message.\r\n" .
						"\r\n" .
						"Lord A";
					$headers = "From: lorda@pandora.be\r\n" .
       			"X-Mailer: PHP/" . phpversion() . "\r\n" .
       			"MIME-Version: 1.0\r\n" .
       			"Content-Type: text/html; charset=utf-8\r\n" .
       			"Content-Transfer-Encoding: 8bit\r\n\r\n";
					$isSent = mail($email, $subject, $message, $headers); 
   				print "<script language='javascript'>";
   				if ($isSent) {
    				print "pr(\"$nimi\");";
    			} else {
    				print "mailError(\"$nimi\");";
    			}
    			print "</script>";
   		} else {
   			print "<script language='javascript'>";
    			ep2(2);
    			print "</script>";
  		}
	} else {
		print "<script language='javascript'>";
  		ep2(3);
  		print "</script>";
	}
} else {
	print "<script language='javascript'>";
  ep2(4);
  print "</script>";
}

close_dbx();

?>