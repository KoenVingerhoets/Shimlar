<!--
function crp(nimi,login){
  top.toiminta.document.open("text/html");
  top.toiminta.document.writeln('<html><head><title>Main</title></head>');
  top.toiminta.document.writeln('<body bgcolor="#000000" text="#DDDDDD">');
  top.toiminta.document.writeln('<center>Character <strong>',nimi,'</strong> created successfully!<br>');
  top.toiminta.document.writeln('You received an email with a link you have to click before you can access your character.');  
  top.toiminta.document.writeln('</center></body></html>');
  top.toiminta.document.close();
  top.chat.enter.l.value=login;
  top.chat.enter.p.value="";
  top.chat.crpl.newpl.value="";
  top.chat.crpl.newpw.value="";
  top.chat.crpl.newpw2.value="";
  top.chat.crpl.maili.value="";
}
function eX(errnum){
  alert(top.ob(top.va[errnum]));
}

function pr(nimi) {
  top.toiminta.document.open("text/html");
  top.toiminta.document.writeln('<html><head><title>Password recovered for ',nimi,'</title></head>');
  top.toiminta.document.writeln('<body bgcolor="#000000" text="#DDDDDD">');
  top.toiminta.document.writeln('You received an email with the data to access your character.');  
  top.toiminta.document.writeln('</center></body></html>');
  top.toiminta.document.close();
}

//-->
