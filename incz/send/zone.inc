<?php
            $zname=strstr($cinput," ");
            $zname=ucwords(trim($zname));
            $query="Select Nnum from Names where Nname='$zname'";
            if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
              extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
              if ((int)$tgt_Nnum != 10) {
                $query="Select zlevel,zone_p,zone_x,zone_y from Zones where znum=$tgt_Nnum";
                $result=mysql_query($query);
                extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
                $query="Select Nname from Names where Nnum='$tgt_zone_p'";
                $result=mysql_query($query);
                extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
                $chatresult="$zname is found at $tgt_zone_x,$tgt_zone_y in $tgt_Nname and needs level $tgt_zlevel to enter.";
              } else {
              	$chatresult="The Wilderness is a vast area where you travel from zone to zone.";
              }
            } else {
              $chatresult="Zone $zname does not exist or is closed.";
            }
?>