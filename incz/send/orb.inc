<?php
            $accs=accn($Id);
            if($accs==41210000){
              $query="Select loc_zone,loc_x,loc_y from Players where Id= $Id";
              $result=mysql_query($query);extract(mysql_fetch_array($result));
              $query="Select name from Players where loc_zone=$loc_zone and loc_x-$loc_x<2 and loc_y-$loc_y<2 and (now()-ax_time)<7000000 limit 121";
              if(($result=mysql_query($query))==TRUE && ($c2=mysql_num_rows($result))<121){
                $chatresult="You sense the following people around: ";
                for($c1=0;$c1<$c2;$c1++){
                  $row=mysql_fetch_row($result); $tgt_name=$row[0];
                  $chatresult.="$tgt_name";
                  if($c1<($c2-1)){
                    $chatresult.=", ";
                  }
                }
              }else {
                $chatresult="There are over 120 players near you.";
              }
            }else {
              $chatresult="You do not have the item equipped.";
            }

?>
