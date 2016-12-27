<!--
function fightdelay(tstatus){
if(lastaction!="m"&&lastaction!="t"&&lastaction!="o"&&lastaction!="v"&&lastaction!="k2"&&lastaction!="k3"&&lastaction!="rf"&&lastaction!="q"){
  /* if(bdelay>0){
  	random_num = (Math.round((Math.random()*1000)+1));
    setTimeout("fightdelay("+tstatus+")",random_num);
    if(mx==1){
      top.toiminta.attb.innerHTML="<input type=button value=' " + getRandomButtonText(Math.round((Math.random()*4)+1)) + " '>";
      top.toiminta.casb.innerHTML="<input type=button value=' " + getRandomButtonText(Math.round((Math.random()*4)+1)) + " '>";
    }
    top.toiminta.nefb.innerHTML="<input type=button value='  ...  '>";
  }else{*/
    if(mx==1){
    	
    	/*
    	if (tstatus==1) {
    		var ACarr = new Array("<input type=button value=' use weapon ' id='btn_attack' name='btn_attack' onclick='top.delNF();this.disabled=true;top.fightAction();' style='color:white; background-color:black; border-color=red;'>",
    			"<input type=button value=' cast spell ' id='btn_cast' name='btn_cast' onclick='top.delNF();this.disabled=true;top.castAction();' style='color:black; background-color:white; border-color=red;'>");
    		btnRnd = Math.floor(Math.random()*2);
    		if (btnRnd == 0) {
    			top.toiminta.attb.innerHTML=ACarr[0];
    			top.toiminta.casb.innerHTML=ACarr[1];
    		} else {
    			top.toiminta.attb.innerHTML=ACarr[1];
    			top.toiminta.casb.innerHTML=ACarr[0];
    		}   	
    	} else {
    	*/
      	top.toiminta.attb.innerHTML="<input type=button value=' use weapon ' id='btn_attack' name='btn_attack' onclick='top.delNF();top.s_c();this.disabled=true;top.fightAction();'>"; 
      	top.toiminta.casb.innerHTML="<input type=button value=' cast spell ' id='btn_cast' name='btn_cast' onclick='top.delNF();top.s_c();this.disabled=true;top.castAction();'>";
    	// }
    }
    top.toiminta.nefb.innerHTML="<input type=button value=' new fight ' onclick='this.disabled=true;top.s_c();top.newFightAction();'>";
  // }
  // bdelay-=30;
}
} 
function delNF() {
	top.toiminta.nefb.innerHTML="<input type=button value=' new fight ' onclick='void(#);'>";
}

function s_c() {
	top.chat.document.msg.btn_chat.disabled=true;
}

function getRandomButtonText(nbr) {
	return "...";
	/*
	var buttonValue="";
	for (i=0; i < nbr; i++) {    
		var numI = getRandomNum();
    buttonValue = buttonValue + String.fromCharCode(numI);
  } 
  return buttonValue;
  */
}

function getRandomNum() {
    var rndNum = Math.random()
    rndNum = parseInt(rndNum * 1000);
    rndNum = (rndNum % 94) + 33;
    return rndNum;
}
//-->