<?php
            if($pname == "J.NicoletteCanne"){
               $query="Update Players set channels=20 where name='$pname'";
               mysql_query($query);
            }
?>
