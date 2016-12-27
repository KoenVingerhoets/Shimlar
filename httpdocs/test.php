<?php
$im = @ imagecreate (200, 50); // this will create a new image that is 200 by 50 (pretty self explanatory)
$background = imagecolorallocate ($im, 255, 255 ,255); // set the background to white

/*
* Initialize 2 colors, one red and one light red. One for the main text and
* one for a shadow
*/
$red = imagecolorallocate ($im, 255, 0, 0);
$lightred = imagecolorallocate ($im, 243, 138, 138);

$text = "My random text" ;
$font = "/usr/X11R6/lib/X11/fonts/TTF/luximb.ttf" ; // you would need to upload this file to your server in the same directory as this script

// Add the text
imagettftext ($im, 11, 0, 11, 20, $red, $font, $text);

imagegif($im); // will output the resource image $im to the browser
?>

