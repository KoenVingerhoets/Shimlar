<?php
          $query="Select cbonus,cint,cint2 from Clans where cid=$clan";
          $result=mysql_query($query);
          if($result==TRUE and mysql_num_rows($result)>0){
            extract(mysql_fetch_array($result));
            if($cint==$Id || $cint2==$Id){
              $clx=1.25;
            }else{
              $clx=1;
            }
            $query="Select kd_mine,kd_misc,kd_tax from Kingdoms where kd_clan=$clan";
            $result=mysql_query($query);
            if($result==TRUE and mysql_num_rows($result)>0){
              extract(mysql_fetch_array($result));
            }
          }else {
            $cbonus=0;$clx=1;
          }

?>