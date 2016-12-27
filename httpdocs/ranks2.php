<?php

include '../incz/constvars.inc'; 
init_dbx();

$toplist = $_POST["toplist"];
$rt = $_POST["rt"];

if($toplist=="") {
	$toplist=$_GET["toplist"];
}
if($toplist=="") {	
  $toplist="fame";
}

if($rt<-1 || $rt>19){
  $rt=-1;
}

if($toplist=="exp") {
  if($rt==-1){
   $query="Select Players.name,Stats.race,Stats.lvl,Stats.exp from Players, Stats where Players.name=Stats.name and (Players.channels !=20 and Players.channels !=12 and Players.banned!=100) and Stats.tstatus = 0 order by Stats.lvl desc,Stats.exp desc limit 50";
 }else{
   $query="Select Players.name,Stats.race,Stats.lvl,Stats.exp from Players, Stats where Players.name=Stats.name and (Players.channels !=20 and Players.channels !=12 and Players.banned!=100 and (Stats.race=$rt or Stats.race=$rt+100)) and Stats.tstatus = 0 order by Stats.lvl desc,Stats.exp desc limit 50";
 }
  $result=mysql_query($query);
  $a1=mysql_num_rows($result);
  for($i=0; $i<$a1; ++$i) {
    $row=mysql_fetch_row($result);
    $pname[$i]=$row[0];
    $prace[$i]=$row[1];
    $plvl[$i]=$row[2];
    $pexp[$i]=$row[3];
 }
  print "<script src=\"updt.js\"></script><script>";
  for($i=0; $i<$a1; ++$i) {
    print "t0(\"$pname[$i]\",\"$prace[$i]\",\"$plvl[$i]\",\"$pexp[$i]\");";
  }
  print "tX();";
  print "</script>";
} else if($toplist=="gold") {
  if($rt==-1){
   $query="Select Players.name,Stats.race,Stats.banked from Players,Stats where Players.name=Stats.name and Players.channels !=20 and Players.channels !=12 and Players.banned!=100 and Stats.tstatus = 0 order by Stats.banked desc limit 50";
 }else{
   $query="Select Players.name,Stats.race,Stats.banked from Players,Stats where Players.name=Stats.name and Players.channels !=20 and Players.channels !=12 and Players.banned!=100 and (Stats.race=$rt or Stats.race=$rt+100) and Stats.tstatus = 0 order by Stats.banked desc limit 50";
 }
  $result=mysql_query($query);
  $a1=mysql_num_rows($result);
  for($i=0; $i<$a1; ++$i) {
    $row=mysql_fetch_row($result);
    $pname[$i]=$row[0];
    $prace[$i]=$row[1];
    $pbanked[$i]=$row[2];
  }
  print "<script src=\"updt.js\"></script><script>";
  for($i=0; $i<$a1; ++$i) {
    print "t1(\"$pname[$i]\",\"$prace[$i]\",\"$pbanked[$i]\");";
  }
  print "tX();";
  print "</script>";
} else if($toplist=="good") {
  $query="Select Players.name,Stats.race,Stats.align from Players,Stats where Players.name=Stats.name and Players.channels !=20 and Players.channels !=12 and Players.banned!=100 and Stats.lvl > 99 order by Stats.align desc limit 50";
  $result=mysql_query($query);
  $a1=mysql_num_rows($result);
  for($i=0; $i<$a1; ++$i) {
    $row=mysql_fetch_row($result);
    $pname[$i]=$row[0];
    $prace[$i]=$row[1];
    $palign[$i]=$row[2];
  }
  print "<script src=\"updt.js\"></script><script>";
  for($i=0; $i<$a1; ++$i) {
    print "t7(\"$pname[$i]\",\"$prace[$i]\",\"$palign[$i]\");";
  }
  print "tX();";
  print "</script>";
} else if($toplist=="evil") {
  $query="Select Players.name,Stats.race,Stats.align from Players,Stats where Players.name=Stats.name and Players.channels !=20 and Players.channels !=12 and Players.banned!=100 and Stats.lvl > 99 order by Stats.align asc limit 50";
  $result=mysql_query($query);
  $a1=mysql_num_rows($result);
  for($i=0; $i<$a1; ++$i) {
    $row=mysql_fetch_row($result);
    $pname[$i]=$row[0];
    $prace[$i]=$row[1];
    $palign[$i]=$row[2];
  }
  print "<script src=\"updt.js\"></script><script>";
  for($i=0; $i<$a1; ++$i) {
    print "t8(\"$pname[$i]\",\"$prace[$i]\",\"$palign[$i]\");";
  }
  print "tX();";
  print "</script>";
} else if($toplist=="quest") {
  $query="Select name,quests from Players where quests>0 and banned!=100 order by quests desc limit 50";
  $result=mysql_query($query);
  $a1=mysql_num_rows($result);
  for($i=0; $i<$a1; ++$i) {
    $row=mysql_fetch_row($result);
    $pname[$i]=$row[0];
    $pquest[$i]=$row[1];
  }
  print "<script src=\"updt.js\"></script><script>";
  for($i=0; $i<$a1; ++$i) {
    print "t9(\"$pname[$i]\",\"$pquest[$i]\");";
  }
  print "tX();";
  print "</script>";
} else if($toplist=="muted") {
  $query="Select Players.name,Players.mhd,Stats.lvl from Players,Stats where Players.name=Stats.name and Players.channels=66 and Players.banned!=100 order by Players.mhd desc,Stats.exp asc limit 50";
  $result=mysql_query($query);
  $a1=mysql_num_rows($result);
  for($i=0; $i<$a1; ++$i) {
    $row=mysql_fetch_row($result);
    $pname[$i]=$row[0];
    $plvl[$i]=$row[1];
  }
  print "<script src=\"updt.js\"></script><script>";
  for($i=0; $i<$a1; ++$i) {
    print "t2(\"$pname[$i]\",\"$plvl[$i]\");";
  }
  print "tX();";
  print "</script>";
} else if($toplist=="mods") {
  $query="Select name,channels from Players where (channels = 10 OR  channels = 11) and ((now()-Players.ax_time)<500) order by name asc limit 50";
  $result=mysql_query($query);
  $a1=mysql_num_rows($result);
  for($i=0; $i<$a1; ++$i) {
    $row=mysql_fetch_row($result);
    $pname[$i]=$row[0];
    $pchannel[$i]=$row[1];
  }
  print "<script src=\"updt.js\"></script><script>";
  for($i=0; $i<$a1; ++$i) {
    print "t10(\"$pname[$i]\",\"$pchannel[$i]\");";
  }
  print "tX();";
  print "</script>";
} else if($toplist=="qdelay") {
  $query="Select name,qhd from Players where qhd>0 and banned!=100 order by qhd asc limit 50";
  $result=mysql_query($query);
  $a1=mysql_num_rows($result);
  for($i=0; $i<$a1; ++$i) {
    $row=mysql_fetch_row($result);
    $pname[$i]=$row[0];
    $pquest[$i]=$row[1];
    if ($pquest[$i]=="0") {
	  $pquest[$i]="e";
    }
  }
  print "<script src=\"updt.js\"></script><script>";
  for($i=0; $i<$a1; ++$i) {
    print "t4(\"$pname[$i]\",\"$pquest[$i]\");";
  }
  print "tX();";
  print "</script>";
} else if($toplist=="jail") {
  $query="Select name,jhd from Players where loc_zone=18 and banned!=100 order by name desc limit 50";
  $result=mysql_query($query);
  $a1=mysql_num_rows($result);
  for($i=0; $i<$a1; ++$i) {
    $row=mysql_fetch_row($result);
    $pname[$i]=$row[0];
    $plvl[$i]=$row[1];
  }
  print "<script src=\"updt.js\"></script><script>";
  for($i=0; $i<$a1; ++$i) {
    print "t5(\"$pname[$i]\",\"$plvl[$i]\");";
  }
  print "tX();";
  print "</script>";
}else if($toplist=="clan") {
  $query="Select cname,cpower,cleader,cleader2,cbonus from Clans where cpower>0 and cturn = 0 order by cpower desc limit 50";
  $result=mysql_query($query);
  $a1=mysql_num_rows($result);
  for($i=0; $i<$a1; ++$i) {
    $row=mysql_fetch_row($result);
    $pname[$i]=$row[0];
    $cpower[$i]=$row[1];
    $cl1[$i]=$row[2];
    $cl2[$i]=$row[3];
    $cbonus[$i]=$row[4];
    if(strlen($cl2[$i])<3){
      $cl2[$i]="-";
    }
  }
  print "<script src=\"updt.js\"></script><script>";
  for($i=0; $i<$a1; ++$i) {
    print "t6(\"$pname[$i]\",\"$cpower[$i]\",\"$cl1[$i]\",\"$cl2[$i]\",\"$cbonus[$i]\");";
  }
  print "tX();";
  print "</script>";
}else if($toplist=="clant") {
  $query="Select cname,cpower,cleader,cleader2,cbonus from Clans where cpower>0 and cturn = 1 order by cpower desc limit 50";
  $result=mysql_query($query);
  $a1=mysql_num_rows($result);
  for($i=0; $i<$a1; ++$i) {
    $row=mysql_fetch_row($result);
    $pname[$i]=$row[0];
    $cpower[$i]=$row[1];
    $cl1[$i]=$row[2];
    $cl2[$i]=$row[3];
    $cbonus[$i]=$row[4];
    if(strlen($cl2[$i])<3){
      $cl2[$i]="-";
    }
  }
  print "<script src=\"updt.js\"></script><script>";
  for($i=0; $i<$a1; ++$i) {
    print "t14(\"$pname[$i]\",\"$cpower[$i]\",\"$cl1[$i]\",\"$cl2[$i]\",\"$cbonus[$i]\");";
  }
  print "tX();";
  print "</script>";
} else if($toplist=="married") {
  $query="select P1.Name,P2.Name from Players P1, Players P2, Wedding W where W.Status=1 and W.pId1 = P1.Id and W.pId2 = P2.Id order by W.Ts desc";
  $result=mysql_query($query);
  $a1=mysql_num_rows($result);
  for($i=0; $i<$a1; ++$i) {
    $row=mysql_fetch_row($result);
    $pname[$i]=$row[0];
    $race[$i]=$row[1];
  }
  print "<script src=\"updt.js\"></script><script>";
  for($i=0; $i<$a1; ++$i) {
    print "t11(\"$pname[$i]\",\"$race[$i]\");";
  }
  print "tX();";
  print "</script>";
} else if($toplist=="pk") {
  $query="select S.name,S.PKill from Stats S,Players P where P.banned!=100 and P.Id = S.Id order by PKill desc limit 50";
  $result=mysql_query($query);
  $a1=mysql_num_rows($result);
  for($i=0; $i<$a1; ++$i) {
    $row=mysql_fetch_row($result);
    $pname[$i]=$row[0];
    $race[$i]=$row[1];
  }
  print "<script src=\"updt.js\"></script><script>";
  for($i=0; $i<$a1; ++$i) {
    print "t12(\"$pname[$i]\",\"$race[$i]\");";
  }
  print "tX();";
  print "</script>";
} else if ($toplist=="fame") {
	if($rt==-1){
		$query="select f.Name,f.Fame,f.Lvl from Fame f inner join Players p on p.Id = f.Id where p.banned <> 100 order by f.Fame desc limit 50";
	} else {
		$query="select f.Name,f.Fame,f.Lvl from Fame f inner join Players p on p.Id = f.Id inner join Stats s on s.Id = f.Id where p.banned <> 100 and (s.race=$rt or s.race=$rt+100) order by f.Fame desc limit 50";
	}
	$result=mysql_query($query);
  $a1=mysql_num_rows($result);
  for($i=0; $i<$a1; ++$i) {
    $row=mysql_fetch_row($result);
    $pname[$i]=$row[0];
    $race[$i]=$row[1];
    $lvl[$i]=$row[2];
  }
  print "<script src=\"updt.js\"></script><script>";
  for($i=0; $i<$a1; ++$i) {
    print "t13(\"$pname[$i]\",\"$race[$i]\",\"$lvl[$i]\");";
  }
  print "tX();";
  print "</script>";
}
close_dbx();

?>
