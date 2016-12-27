<?php
include '../incz/constvars.inc'; 
include '../incz/chatx.inc'; 
global $HTTP_REFERER;
$position = strpos($_SERVER['HTTP_REFERER'] , "http://www.shimlar.org/");
if ( $position !== false ) {
  init_dbx();
  $randomz = rand(1,50);
  if ($randomz != 25) {
  	print "<script language=\"javascript\" src=\"upd5.js\"></script>";
  } else {
  	print "<script language=\"javascript\">";
  	include 'upd5.js';
  	print "</script>";
  }
  print "<script language=\"javascript\">";
  chatproc($_POST["l"],$_POST["p"]);
  print "</script>";
  close_dbx();
} else {
  logText("cx.php");
  logText("Player = ".$_POST["l"]);
  logText("password = ".$_POST["p"]);  
  logText("REMOTE_ADDR = ".$_SERVER['REMOTE_ADDR']);
  logText("HTTP_REFERER = ".$_SERVER['HTTP_REFERER']);
  ep2(59);
}?>
