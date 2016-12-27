<?php
            if($channels==13 || $channels==11){
              $awardn=strstr($cinput," ");
              $awardn=trim($awardn);
              $award=strstr($awardn,":");
              $award=substr($award,2);
              $awardn=substr($awardn,0,(strlen($awardn)-strlen($award)-2));
              $awardn=ucwords($awardn);
              if($award<0){
                $award=0;
              }
              $query="Select fundexp from Funds where fundnimi='roleplay'";
              $result=mysql_query($query);
              extract(mysql_fetch_array($result));
              if($fundexp>=$award){
                $query="Select exp,gold from Stats where name='$awardn'";
                if(($result=mysql_query($query))==TRUE && mysql_num_rows($result)==1){
                  extract(mysql_fetch_array($result),EXTR_PREFIX_ALL,"tgt");
                  $tgt_exp=$tgt_exp+$award;
                  $query="Update Stats set exp=$tgt_exp where name='$awardn'";
                  mysql_query($query);
                  $query="Update Funds set fundexp=fundexp-$award where fundnimi='roleplay'";
                  mysql_query($query);
                  $query="Insert into Modactions values('$pname','$awardn','awarded $award exp',now())";
                  mysql_query($query);
                  $chatresult="You awarded $awardn with $award experience";
                }else {
                  $chatresult="Player $awardn does not exist";
                }
              }else {
                $chatresult="There is not enough exp left in the fund to award $award";
              }
            }else {
              $chatresult="You do not have this power!";
            }
?>