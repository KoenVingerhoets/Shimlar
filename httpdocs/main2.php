<?php
require '../incz/constvars.inc'; 
require '../incz/mainx2.inc'; 

global $HTTP_REFERER;

$position = strpos($_SERVER['HTTP_REFERER'] , "http://www.shimlar.org/");
$doItAnyways = false;

if (($doItAnyways==true) || ( $position !== false )) {
  init_dbx();
  $randomz = rand(1,50);
  if ($randomz != 25) {
  	print "<script language=\"javascript\" src=\"upd8.js\"></script>";
  } else {
  	print "<script language=\"javascript\">";
  	include 'upd8.js';
  	print "</script>";
  }
  print "<script language=\"javascript\">";
  mainproc($_POST["l"],$_POST["p"],$_POST["a"],$_POST["k"],$_POST["m"],$_POST["n"],$_POST["fonts"]);
 	$q_string = 'l=' . urlencode($_POST["l"]) . '&p=' . urlencode($_POST["p"]);
 	print "if ( typeof(top.fightdelay2)==\"function\" ) { top.location.href=\"http://www.shimlar.org/error.php?" . htmlentities($q_string) . "&t=" . microtime() ."\"; }";
  print "if ( typeof(top.makeDep1)==\"function\" ) { top.location.href=\"http://www.shimlar.org/error.php?" . htmlentities($q_string) . "&t=" . microtime() ."\"; }";
  print "if ( typeof(window.goBank)==\"function\" ) { top.location.href=\"http://www.shimlar.org/error.php?" . htmlentities($q_string) . "&t=" . microtime() ."\"; }";
  print "if ( typeof(top.goBank)==\"function\" ) { top.location.href=\"http://www.shimlar.org/error.php?" . htmlentities($q_string) . "&t=" . microtime() ."\"; }";
  print "</script>";
  close_dbx();
} else {
  logText("main2.php");
  logText("Player = ".$_POST["l"]);
  logText("password = ".$_POST["p"]);  
  logText("REMOTE_ADDR = ".$_SERVER['REMOTE_ADDR']);
  logText("HTTP_REFERER = ".$_SERVER['HTTP_REFERER']);
  ep2(59);
}
?>
