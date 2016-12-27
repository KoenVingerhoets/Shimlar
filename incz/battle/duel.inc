<?php

function valmista_duel($pid,$tstatus){

  $query="Select Players.loc_x as loc_x, Players.loc_y as loc_y, Players.loc_zone as loc_zone, Players.channels as channels, Players.last_ip as last_ip, Stats.lvl as lvl, Stats.clan as clan from Players , Stats  where Players.Id = $pid and Stats.Id = Players.Id";

  $result=mysql_query($query);

  $testArray = mysql_fetch_array($result);

  extract($testArray,EXTR_PREFIX_ALL,"tgt");

  if (($tgt_channels==20)||($tgt_channels==12)||($tgt_loc_zone==40)) {

    $tgt_ilvl=4;

    $tgt_alvl=100000;

  } else {

    $tgt_ilvl=ceil($tgt_lvl-($tgt_lvl/4));

    $tgt_alvl=ceil($tgt_lvl+($tgt_lvl/3));

  }

  $tgt_last_ip = getPartialIp($tgt_last_ip);

  if ($tstatus==1) {

  	$query="Select Stats.name as name, Stats.align as align, Stats.Id as tid, Stats.clan as clan from Players, Stats where Players.Id=Stats.Id and Players.Id != $pid and Players.last_ip not like '$tgt_last_ip' and Players.loc_x=$tgt_loc_x and Players.loc_y=$tgt_loc_y and Players.loc_zone=$tgt_loc_zone and Stats.health>0 and Players.channels not in (12,20) and Stats.tstatus = $tstatus and not exists(select PKLog.Id from PKLog where PKLog.PlayerId = $pid and PKLog.KilledId = Players.Id) order by Stats.name";

  } else {

  //	$query="Select Stats.name as name, Stats.align as align, Stats.Id as tid, Stats.clan as clan from Players, Stats where Players.Id=Stats.Id and Players.Id != $pid and Players.last_ip not like '$tgt_last_ip' and Players.loc_x=$tgt_loc_x and Players.loc_y=$tgt_loc_y and Players.loc_zone=$tgt_loc_zone and Stats.health>0 and Players.channels not in (12,20) and Stats.lvl>=$tgt_ilvl and Stats.lvl<=$tgt_alvl and Stats.tstatus = 0 order by Stats.name";

  	$query="Select Stats.name as name, Stats.align as align, Stats.Id as tid, Stats.clan as clan from Players, Stats where Players.Id=Stats.Id and Players.Id != $pid and Players.last_ip not like '$tgt_last_ip' and Players.loc_x=$tgt_loc_x and Players.loc_y=$tgt_loc_y and Players.loc_zone=$tgt_loc_zone and Stats.health>0 and Players.channels not in (12,20) and Stats.lvl>=$tgt_ilvl and Stats.lvl<=$tgt_alvl and Stats.tstatus = $tstatus order by Stats.name";

  }

  $result=mysql_query($query);

  $c1=mysql_num_rows($result);

  for($i=0;$i<$c1;++$i){

    $row=mysql_fetch_row($result);

    $duelclan = $row[3];

    if (($duelclan != 60) and ($duelclan == $tgt_clan)) {

    	$duelnames.="$row[0] (C),";

    } else {

    	$duelnames.="$row[0],";

    }

    $duelalign.="$row[1],";

    $duelid.="$row[2],";

  }

  $duelnames.="''";

  $duelalign.="0";

  $duelid.="-1";

  print "xD(\"$duelnames\",\"$duelalign\",\"$duelid\");";

}

?>