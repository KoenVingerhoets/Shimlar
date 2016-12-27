<?php
            $newign=strstr($cinput," ");
            $newign=trim($newign);
            $newign=$newign-1;
            if($newign<=$lvl && $newign>=4){
              sqlP(ign,$newign,$Id);
              $chatresult="You are now ignoring PMs from players below lvl $newign.";
            }else {
              $chatresult="You can only ignore players below your lvl.";
            }
?>