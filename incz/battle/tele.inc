<?php
  if($loc_zone !=10){
  if($loc_x==1 && $loc_y==0 && $loc_zone==16){
    $stuff_here=5;
  }else if($loc_x==1 && $loc_y==1 && $loc_zone==26){
    $stuff_here=7;
  }else if($loc_x<10 && $loc_y<10 && $loc_zone==32 &&($loc_x+$loc_y)>0){
    $stuff_here=8;
  }else if($loc_x==2 && $loc_y==1 && $loc_zone==16){
    $stuff_here=9;
  }else if($loc_x==2 && $loc_y==3 && $loc_zone==24){
    $stuff_here=10;
  }else if($loc_x==3 && $loc_y==2 && $loc_zone==31){
    $stuff_here=10;
  }else if($loc_x==2 && $loc_y==2 && $loc_zone==33){
    $stuff_here=10;
  }else if($loc_x==1 && $loc_y==1 && $loc_zone==40){
    $stuff_here=11;
  }else if($loc_x==2 && $loc_y==2 && $loc_zone==16){
    $stuff_here=12;
  }else if(!($loc_x==0 && $loc_y==0)){
    if($zshrine%10==$loc_y &&($zshrine-($zshrine%10))/10==$loc_x){
      $stuff_here=1;
    }else if($zshop%10==$loc_y &&($zshop-($zshop%10))/10==$loc_x){
      $stuff_here=2;
    }else if($zmage%10==$loc_y &&($zmage-($zmage%10))/10==$loc_x){
      $stuff_here=3;
    }else if($zbank%10==$loc_y &&($zbank-($zbank%10))/10==$loc_x){
      $stuff_here=4;
    }
  }
  }else{
  if($zshrine%10==$loc_y && ($zshrine-($zshrine%10))/10==$loc_x){
    $stuff_here=1;
  }
  }
?>