<?php
include '../incz/constvars.inc'; 
include '../incz/chatx.inc'; 
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
?>
