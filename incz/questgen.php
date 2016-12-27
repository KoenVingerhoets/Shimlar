<?php
include 'constvars.inc'; 

//generates a quest
function questproc($qdiff){

for($lx=0;$lx<6;$lx++){
  srand(make_seed());
  $query="select max(isqzone)as maximum from Zones";
  $result=mysql_query($query);
  $row = mysql_fetch_array($result, MYSQL_ASSOC);
 
  $layerArray = array();
  
  for ($layNum=1;$layNum<=$row["maximum"]; $layNum++) {
    $layerArray[$layNum] = generateLayer($layNum);
  }
  $baseLayerCount = count($layerArray[1]);
  $countOfLayers = count($layerArray);
  $questZone = rand(0, ($baseLayerCount-1) + ($countOfLayers-1));
  if ($questZone < $baseLayerCount){
    $zoneID = $layerArray[1][$questZone];
//    print ("baseLayer in $zoneID<br>");
  } else  {
  
    $layer = $layerArray[$questZone-$baseLayerCount+2];
    //$text = $questZone-$baseLayerCount+2;
    $questZone = rand(0, count($layer)-1);
    $zoneID = $layer[$questZone];
    //print ("extended Layer No. $text in $zoneID<br>");
  }
  $query="Select zbase_stats, zbase_eq, zmonsters, mlist, minqlvl, qincrement, qrange, expFactor, goldFactor from Zones where znum=$zoneID";
  $result=mysql_query($query);
  extract(mysql_fetch_array($result));
  $qmon=rand(0,$zmonsters-1);
  $minlvl = $minqlvl + $qmon*$qincrement;
  $maxlvl = $minlvl + $qrange;
  //todo qtype definieren
  //test//
  $qtype = rand(1,100);
  //schaun mer mal
  // hier wird der allgemeine preis berechnet (Achtung nichtlinear)
  $qprice=$zbase_stats*$zbase_eq*pow(1.3,$qmon)*4;
  //abhängig vom qtype wird der allgemeine preis aufgeteilt in 3 kategorien
  // wobei $qt1 immer der anteil der exp und $qt2 immer der Goldanteil ist
  // und $qt3 immer der anteil für Item oder gem drop der quest ist.
  // $qt1+$qt2+$qt3 = $qprice
  switch (TRUE)
  {
    case($qtype<60):
    $qt1=round($qprice*0.6);
    $qt2=round($qprice*rand(4,36)/100);
    $qt3=round($qprice-$qt1-$qt2);
    $qitem=0;
    break;
  case ($qtype<90) :
    $qt2=round($qprice*0.6);
    $qt3=round($qprice*rand(4,30)/100);
    $qt1=round($qprice-$qt3-$qt2);
    $qitem=0;
    break;
  default :
    $qt3=round($qprice*0.6);
    $qt1=round($qprice*rand(10,36)/100);
    $qt2=round($qprice-$qt3-$qt1);
    switch (TRUE)
    {
      case ($qt3>35000000):
        $qitem=75+rand(1,19);
        break;
      case ($qt3>8000000):
        $qitem=50+rand(1,19);
        break;
      case ($qt3>2500000):
        $qitem=25+rand(1,19);
        $qgold+=$qt3-2500000;
        break;
      default :
        $qitem=0;
    }
  }

  $qexp=$qt1*$expFactor;
  $qgold=$qt2*$goldFactor;
  if ($qgold > 200000000) {
    $qgold = 200000000;
  }
  

  //hier wird der special ermittelt
  $qmon+=(rand(1,14)*20);
//  $query="Insert into Quests values($qmon,$mlist,$zoneID,$qexp+10000,$qgold+5000,$qitem,'x',$qnum,$maxlvl,,$minlvl)";
//  echo ($query);
//  mysql_query($query);

  $query="Select qnum from Quests order by qnum desc limit 1";
  $result=mysql_query($query);
  if($result==TRUE && mysql_num_rows($result)==1){
    extract(mysql_fetch_array($result)); $qnum++;
    $query="Select count(*) as qz from Quests";
    $result=mysql_query($query); extract(mysql_fetch_array($result));
  } else {
    $qnum=1;
  }
//  $qmon+=(rand(1,10)*20);
  $query="Insert into Quests values($qmon,$mlist,$zoneID,$qexp+10000,$qgold+5000,$qitem,'x',$qnum,$maxlvl,0,$minlvl)";
  if($qz<15){
    mysql_query($query);
    
  }
}

  resetPlayers();
  HandOutTurns();
  deleteQuests();
  increasequestLife();
  // onlinePlayers();
  }

// displays the number of currently online players in general and sales chat
function onlinePlayers() {
    $query="Select count(Id) as pon from Players where (now()-ax_time)<200";
    $result=mysql_query($query);
    extract(mysql_fetch_array($result));
    inschat("chat1","Shimlar","has $pon players online!",32);
    inschat("chat3","Shimlar","has $pon players online!",32);
  }
  

//increases quest life
function increaseQuestLife() {
    $query="Update Quests set qlife=qlife+1";
    mysql_query($query);
    $query="Update Players set qhd=qhd-1 where qhd>0";
    mysql_query($query);
    $query="Update Inventory set tradex=0";
    mysql_query($query);
    $query="update Inventory set checked = 0 where checked = 1";
    mysql_query($query);
    $query="Delete from Market where tto=tto";
    mysql_query($query);
    $query="Unlock tables";
    mysql_query($query);
}

//deletes quests after a certain time is over  (3 hours)
function deleteQuests() {
    $query="Delete from Quests where qlife>=3";
    mysql_query($query);
    for($cx=1;$cx<5;$cx++){
      $query="select msgnum from chat$cx order by msgnum desc limit 1";
      $result=mysql_query($query); $row=mysql_fetch_row($result); $msgnum_max=$row[0];
      $query="delete from chat$cx where msgnum<$msgnum_max-40";
      mysql_query($query);
    }
    $query="Unlock tables";
    mysql_query($query);
    $query="Lock Tables Players WRITE,Inventory WRITE,Market WRITE,Quests WRITE,Stats WRITE";
    mysql_query($query);
}


//reset players from expired quests
function resetPlayers() {
    $query="Select qnum from Quests where qlife>=3";
    $result=mysql_query($query);
    $c1=mysql_num_rows($result);
    for($c2=0;$c2<$c1;$c2++){
          $row=mysql_fetch_row($result);
          $qnum=$row[0];
          $query="Update Players set qnum=0 where qnum=$qnum";
          mysql_query($query);
    }
}

//for the random function
function make_seed(){
  list($usec, $sec) = explode(' ', microtime());
  return (float) $sec + ((float) $usec * 100000);
}

//generate numbered array of znum

function generateLayer($layerNum){
  $query="Select znum from Zones where isqzone = $layerNum";
  $result=mysql_query($query);
  $zCount = 0;
  $idArray = array();
  while ($row = mysql_fetch_array($result, MYSQL_ASSOC)) {
      $idArray[$zCount] = $row["znum"];
      $zCount++;
  }
  return $idArray;
} 

function HandOutTurns() {
	$query="select s.Id, s.turns from Players p, Stats s where p.channels <> 66 and p.banned < 100 and p.Id = s.Id and s.tstatus = 1 and s.turns <> 5400";
	// select id of needed chars
	$result=mysql_query($query);
  $c1=mysql_num_rows($result);
  for($c2=0;$c2<$c1;$c2++){
 		$row=mysql_fetch_row($result);
    $playerId=$row[0];
    $playerTurns=$row[1];
    if ($playerTurns < 5356) 
    {
    	$query="Update Stats set turns=turns+45 where Id = $playerId";
    	mysql_query($query);
    } 
    else 
    {
    	$query="Update Stats set turns=5400 where Id = $playerId";
     	mysql_query($query);
    }           
  }
}


init_dbx();

questproc($x);
inschat("chat1","Shimlar","has new quests! Please <a href=\'http://www.shimlar.org/donate/\' target=\'_blank\'>donate</a> to keep the game alive!",32);
inschat("chat3","Shimlar","has new quests! Please <a href=\'http://www.shimlar.org/donate/\' target=\'_blank\'>donate</a> to keep the game alive!",32);
inschat("chat4","Shimlar","has new quests! Please <a href=\'http://www.shimlar.org/donate/\' target=\'_blank\'>donate</a> to keep the game alive!",32);
close_dbx();
  
?>