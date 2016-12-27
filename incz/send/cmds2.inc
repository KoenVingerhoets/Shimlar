<?php

//  function chatCommand($cinput){
  $chatcmd=zsub($cinput);
  switch($chatcmd){
    case "e ": //emote
    require_once "emote.inc";
    break;
    case "r ": //race chat
    require_once "racechat.inc";
    break;
    case "w ": //mod chat
    require_once "modchat.inc";
    break;
    case "d ": //big white writing
    require_once "desc.inc";
    break;
    case "p ": //the priest
    require_once "priest.inc";
    break;
    case "dp ": // demon priest
    require_once "demon.inc";
    break;
    case "ps ": //the priestess
    require_once "priestess.inc";
    break;
    case "dps ": // demon priestess
    require_once "demoness.inc";
    break;
    case "warn ": //mod warning
    require_once "warn.inc";
    break;
    case "o ": //Official Announcement
    require_once "oa.inc";
    break;
    case "last ": //set last name
    require_once "lastname.inc";
    break;
    case "m ": //private message
    require_once "pm.inc";
    break;
    case "mc ": //clan message
    require_once "clanpm.inc";
    break;
    case "id ": //identify player
    require_once "id.inc";
    break;
    case "ignlvl ": //set ignore level
    require_once "ignlvl.inc";
    break;
    case "mute ": //mute + jail player
    require_once "mute.inc";
    break;
    case "perma ": //mute player permanently
    require_once "permamute.inc";
    break;
    case "curse ": // make player type backwards
    require_once "curse.inc";
    break;
    case "caps ": //lc-curse, make player type without caps
    require_once "caps.inc";
    break;
    case "voice ": //un-mute/un-curse player
    require_once "voice.inc";
    break;
    case "ban ":
    case "sban ": //bans a player from game
    require_once "ban.inc";
    break;	
    case "ip ": //checks ip of a player
    require_once "ip.inc";
    break;
    case "loc ": //locate a player
    require_once "locate.inc";
    break;
    case "zone ": //shows zone name, location and requested level
    require_once "zone.inc";
    break;
    case "time": //shows server time
              $chatresult=date("D j M G:i:s");
    break;
    case "helprp": //gives a link for manual rp guideline
              $chatresult="Click <a href='http://www.geocities.com/shimlarpguideline' target='_blank'>here</a> or/and <a href=\'http://shimrpguide.shadowwar.net\' target=\'_blank\'>here</a> for the Roleplay Guide</a>";
    break;
    case "help": //gives a link for manual
              $chatresult="<a href='http://www.freewebs.com/mystshimlarguide/' target='_blank'>click here for Masmune Myst site</a> -- <a href='http://www.shimlar.org/manual.htm' target='_blank'>click here for Shimlar Manual</a>";
    break;
    case "sisco":
    case "lorda":
    case "gilian":
    case "lobo":
    case "morph": //Contact the crew link
              $chatresult="<a href='http://www.sofia.be/galatai/contact.asp' target='_blank'>Click here to contact Shimlar Administration.</a>";
    break;
    case "newrp ": //sends rp guideline address to a player(modaction)
    require_once "newrp.inc";
    break;
    case "new ": //sends manual adresses to player(modaction)
    require_once "new.inc";
    break;
    case "rules ": 
    require_once "rules.inc";
    break;
    case "commands ": 
    require_once "commands.inc";
    break;
    case "page": //mod calls for an Arch
    require_once "page.inc";
    break;
    case "tele ": //Arch teleport
    require_once "teleport.inc";
    break;
    case "kill ": //kills a player (used to do macro checks)
    require_once "kill.inc";
    break;
    case "g_orb2":
    case "macro: ":
    require_once "orb2.inc";
    break;
    case "g_orb": //locate players near you
    require_once "orb.inc";
    break;
    case "onpeeps ":
    require_once "onpeeps.inc";
    break;
    case "pignore ":
    require_once "pignore.inc";
    break;
    case "pvoice ":
    require_once "pvoice.inc";
    break;
    case "quest":
    require_once "quest.inc";
    break;
    case "norace": //disable racechat
    require_once "norace.inc";
    break;
    case "racechat": //enable Race chat
    require_once "enableRace.inc";
    break;
    case "pm ": //player-a-like pm for mods and archies
    require_once "modpm.inc";
    break;
    case "check ": //stop a player from trading
    require_once "check.inc";
    break;
    case "uncheck ": //re-enables it
    require_once "uncheck.inc";
    break;
    case "clan": //kd info
    require_once "kingdom.inc";
    break;
    case "wed ":
    require_once "wed.inc";
    break;
    case "yesido":
    require_once "yesido.inc";
    break;
    case "dm ":
    require_once "detailedpm.inc";
    break;
    case "setign ":
    require_once "setign.inc";
    break;
    case "pk":
    require_once "nextpk.inc";
    break;
    case "jae":
    require_once "jae.inc";
    break;
    case "norp ":
    require_once "blockrp.inc";
    break;
    case "nosales ":
    require_once "blocksales.inc";
    break;   
    case "kills":
    require_once "kills.inc";
    break;   
    case "resign":
    require_once "resign.inc";
    break;
    case "clandonate ":
    require_once "clandonate.inc";
    break;
    case "slap":
    require_once "slap.inc";
    break;
    case "members":
    require_once "members.inc";
    break;
    case "buddy":
    require_once "buddys.inc";
    break;
    case "buddya ":
    require_once "buddya.inc";
    break;
    case "buddyc ":
    require_once "buddyc.inc";
    break;
    case "buddyr ":
    require_once "buddyr.inc";
    break;
    case "buddyq ":
    require_once "buddyq.inc";
    break;
    case "mbuddy ":
    require_once "pmbuddy.inc";
    break;
    case "pktag ":
    require_once "pktag.inc";
    break;
    case "wm ":
    require_once "modchatpm.inc";
    break;
    case "leaders ":
    require_once "pmleaders.inc";
    break;
    case "fame":
    require_once "fame.inc";
    break;
  }
//}
?>
