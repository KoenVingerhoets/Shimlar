<?php
            $telln=strstr($cinput," ");
            $telln=trim($telln);
            $telltxt=strstr($telln,":");
            $telltxt=substr($telltxt,2);
            $telln=substr($telln,0,(strlen($telln)-strlen($telltxt)-2));
            $telln=ucwords($telln);
            $query="Select p.Id,p.ign,p.channels,s.lvl from Players p, Stats s where p.name='$telln' and s.Id=p.Id";
            if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
              extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
              $isBuddy = false;
              $query="select * from Buddy where ((Id = $tgt_Id) and (BuddyId = $Id) and (Status = 1)) or ((BuddyId = $tgt_Id) and (Id = $Id) and (Status = 1))";
             	if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==2){
             		$isBuddy = true;
             	} 
              switch ($channels) {
              	case 12:
              	case 20:
              	case 10:
              	case 11:
              	  $query="Insert into Messages values($tgt_Id,'$pname','$telltxt',5,now())";
              	  mysql_query($query);
              	  $chatresult="You tell $telln: $telltxt";
              	  break;	
                default:
              	  if((($tgt_channels==10)||($tgt_channels==11)||($tgt_channels==12)||($tgt_channels==20))||(($isBuddy)||(($tgt_ign<=$lvl) && ($tgt_lvl>=$ign)))){
                    if($channels==19){ $telltxt=strtolower($telltxt); }
                    $query="Insert into Messages values($tgt_Id,'$pname','$telltxt',5,now())";
                    mysql_query($query);
                    $chatresult="You tell $telln: $telltxt";
                  } else {
                    $chatresult="$telln ignores below $tgt_ign, you ignore below $ign.";
                  }
                  break;  
              }
            }else {
              $chatresult="Player $telln does not exist";
            }
?>

