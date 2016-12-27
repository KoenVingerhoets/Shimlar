<?php
            if($channels==20 || $channels==12){
              $loc_x=strstr($cinput," ");
              $loc_y=split(":",$loc_x);
              $zname=ereg_replace( "'", "\'", ucwords(trim($loc_y[0])));
              if(($loc_y[1]==null)||strlen($loc_y[1]<3)) {
                $loc_y[1]="1,1";
              }
              $loc_z=split(",",$loc_y[1]);
              $loc_x=trim($loc_z[0]);
              $loc_y=trim($loc_z[1]);
              $query="Select Nnum as loc_zone from Names where Nname='$zname'";
              if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
                extract(mysql_fetch_array($result));
                $loc_zone=min($loc_zone,47);$loc_zone=max($loc_zone,0);
              }else{
                $loc_zone=15;
              }
              $loc_x=max($loc_x,0);$loc_y=max($loc_y,0);
              $query="Select * from Zones where znum=$loc_zone";
              $result=mysql_query($query);
              extract(mysql_fetch_array($result));
              $query="Update Players set loc_x=$loc_x,loc_y=$loc_y,loc_zone=$loc_zone where Id = $Id";
              mysql_query($query);
              print "x6($loc_x,$loc_y,0,0);";
              print "x7($loc_zone,$zkoko,$zshop,$zshrine,$zmage,$zbank,$zexit,$max_wep,$max_eq,$max_spells,$zmonsters,top.mlist$mlist);";
              $chatresult="Arch teleport successful, please move once for update!";
            }else {
              $chatresult="You do not have this power!";
            }
?>