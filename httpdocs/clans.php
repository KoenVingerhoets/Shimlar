<?php

include '../incz/constvars.inc'; 
init_dbx();
if($cx=="") {
  $cx="all";
}
if($cx!="all") {
  if($cx!="a"){
    $query="Select cid from Clans where cname='$cx'";
    $result=mysql_query($query);
    extract(mysql_fetch_array($result));
    $query="Select name,lvl from Stats where clan=$cid order by lvl desc,exp desc limit 150";
  }else{
    $query="Select name,lvl from Stats where clan=1 order by lvl desc,exp desc limit 150";
  }
  $result=mysql_query($query);
  $a1=mysql_num_rows($result);
  for($i=0; $i<$a1; ++$i) {
    $row=mysql_fetch_row($result);
    $pname[$i]=$row[0];
    $plvl[$i]=$row[1];
  }
  close_dbx();
  print "<script src=\"updc.js\"></script><script>";
  for($i=0; $i<$a1; ++$i) {
    print "c1(\"$pname[$i]\",\"$plvl[$i]\");";
  }
  print "tX();";
  print "</script>";
}else{
  $query="Select cname,cpower,cleader,cleader2,cbonus,cid from Clans where cpower>0 order by cpower desc limit 150";
  $result=mysql_query($query);
  $a1=mysql_num_rows($result);
  for($i=0; $i<$a1; ++$i) {
    $row=mysql_fetch_row($result);
    $pname[$i]=$row[0];
    $cpower[$i]=$row[1];
    $cl1[$i]=$row[2];
    $cl2[$i]=$row[3];
    $cbonus[$i]=$row[4];
    $cid[$i]=$row[5];
    if(strlen($cl2[$i])<3){
      $cl2[$i]="-";
    }
  }
  close_dbx();
  print "<script src=\"updc.js\"></script><script>";
  for($i=0; $i<$a1; ++$i) {
    print "c2(\"$pname[$i]\",\"$cpower[$i]\",\"$cl1[$i]\",\"$cl2[$i]\",\"$cbonus[$i]\",\"$cid[$i]\");";
  }
  print "tX();";
  print "</script>";
}

?>
