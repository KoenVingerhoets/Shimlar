<?php
include '../incz/constvars.inc'; 

function questproc($qdiff){
srand(make_seed());

for($lx=0;$lx<4;$lx++){
  $qdiff=rand(1,4);
  $qm_min=0; $qexp=0; $qgold=0; $qitem=0; $qlevel=0; $qr_bonus=1;
  if($qdiff==4){
    $qlevel=9999;
    $qzone=23+rand(0,5);
    $qtype=rand(1,3);
    if($qzone==26||$qzone==28){
      $qzone=19; $qm_min=10; $qr_bonus=5;
    }
  } else if($qdiff==3){
    $qzone=19+rand(0,3); $qtype=1+rand(0,1)*2; $qlevel=700;
  } else if($qdiff==2){
    $qzone=14+rand(0,3); $qtype=rand(2,3); $qlevel=400;
    if($qzone==16||$qzone==18){
      $qzone=17;
    }
  } else {
    $qzone=rand(0,13); $qtype=rand(1,2); $qlevel=200;
  }
  $query="Select zbase_stats, zbase_eq, zmonsters, mlist from Zones where znum=$qzone";
  $result=mysql_query($query);
  extract(mysql_fetch_array($result));
  $qmon=rand($qm_min,$zmonsters-1);
  $qprice=$zbase_stats*$zbase_eq*pow(1.3,$qmon)*4;
  if($qtype==1){
    $qt1=round($qprice*0.6);
    $qt2=round(($qprice-$qt1)*rand(10,90)/100);
    $qt3=round($qprice-$qt1-$qt2);
  } else if ($qtype==2){
    $qt2=round($qprice*0.6);
    $qt3=round(($qprice-$qt2)*rand(10,90)/100);
    $qt1=round($qprice-$qt3-$qt2);
  } else {
    $qt3=round($qprice*0.6);
    $qt1=round(($qprice-$qt3)*rand(10,90)/100);
    $qt2=round($qprice-$qt3-$qt1);
  }
  $qexp=$qt1*$qr_bonus; $qgold=$qt2*$qr_bonus/5;
  if($qdiff==1){
    $qexp*=10; $qgold*=10;
  }
  $qitype=rand(0,2);
  if($qitype==0){
    if($qt3>35000000){
      $qitem=75+rand(1,19);
    } else if($qt3>8000000){
      $qitem=50+rand(1,19);
    } else if($qt3>2500000){
      $qitem=25+rand(1,19); $qgold+=$qt3-2500000;
    } else {
      $qitem=0;
    }
  } else if($qitype==1){
    if($qt3>40000000){
      $qitem=(4100+20+rand(0,3))*10000;
      if($qitem==41210000) $qitem=41190000;
    } else if($qt3>20000000){
      $qitem=(4100+17+rand(0,2))*10000;
    } else if($qt3>8000000){
      $qitem=(4100+10+rand(0,6))*10000;
    } else if($qt3>2000000){
      $qitem=(4100+rand(0,9))*10000;
      if($qitem==41050000) $qitem=41040000;
    } else{
      $qitem=0;
    }
  } else if($qitype==2){
    for($a1=0;$a1<9;$a1++){
      if(pow(1.5,$a1)*1000000<$qt3){
        $qitem=((10+rand(1,10))*100+$a1*5)*10000;
      }
    }
  }
  $query="Select qnum from Quests order by qnum desc limit 1";
  $result=mysql_query($query);
  if($result==TRUE && mysql_num_rows($result)==1){
    extract(mysql_fetch_array($result)); $qnum++;
    $query="Select count(*) as qz from Quests";
    $result=mysql_query($query); extract(mysql_fetch_array($result));
  } else {
    $qnum=1;
  }
  $qmon+=(rand(1,7)*20);
  $query="Insert into Quests values($qmon,$mlist,$qzone,$qexp,$qgold,$qitem,'x',$qnum,$qlevel,0)";
  if($qz<10){
    mysql_query($query);
  }
}
$query="Select qnum from Quests where qlife>=4";
$result=mysql_query($query);
$c1=mysql_num_rows($result);
for($c2=0;$c2<$c1;$c2++){
  $row=mysql_fetch_row($result);
  $qnum=$row[0];
  $query="Update Players set qnum=0 where qnum=$qnum"; 
  mysql_query($query);
}

$query="Delete from Quests where qlife>=5"; 
mysql_query($query);
for($cx=1;$cx<5;$cx++){
  $query="select msgnum from chat$cx order by msgnum desc limit 1";
  $result=mysql_query($query); $row=mysql_fetch_row($result); $msgnum_max=$row[0];
  $query="delete from chat$cx where msgnum<$msgnum_max-40";
  mysql_query($query);
}
$query="Unlock tables";
mysql_query($query);
$query="Lock Tables Players WRITE,Inventory WRITE,Market WRITE,Quests WRITE";
mysql_query($query);

$query="Update Quests set qlife=qlife+1"; 
mysql_query($query);
$query="Update Players set qhd=qhd-1 where qhd>0";
mysql_query($query);
$query="Update Inventory set tradex=0"; 
mysql_query($query);
$query="Delete from Market where tto=tto"; 
mysql_query($query);
$query="Unlock tables";
mysql_query($query);
$query="Select count(Id) as pon from Players where (now()-ax_time)<200";
$result=mysql_query($query); 
extract(mysql_fetch_array($result));
inschat("chat1","Shimlar","has $pon players online!",27);
inschat("chat3","Shimlar","has $pon players online!",27);
}
function make_seed(){
  list($usec, $sec) = explode(' ', microtime());
  return (float) $sec + ((float) $usec * 100000);
}
init_dbx();

questproc($x);

close_dbx();
  
?>
