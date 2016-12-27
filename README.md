# Shimlar
Source code of Shimlar.org as it was in 2007
This game was conceived when www.racewarkingdoms.com went to a pay to play model.
The two top players at the time, Toshax and Lord ArPharazon, recreated their world in a new and totally free online game, Shimlar.
It ran from 2000 to 2007 and resulted in a lot of copies/spin-offs.

The code is a complex interaction between code in the webserver (Apache - the httpdocs folder) and php code (in the /incz). 
A command resulted in a php file being executed with the result printed into a javascript function call. 
The jscripts are on the client side to draw the required lay-out on the screen.

HOW TO RESET / INSTALL
----------------------
* optional * If name reservation was used
Clean table Reservation.
Fill it with charnames from Players as follows
"insert into Reservation (select p.Name, p.Password, p.Login, p.Channels from Players p, Stats s where p.Id = s.Id and (s.Lvl>49 or s.banked > 999999))"

Other commands required to clean the database:
delete from Players;
delete from Stats;
delete from Inventory;
delete from Transfers;
delete from Buddy;
delete from Wedding;
delete from Clans;
delete from Housing;
delete from Kingdoms;
delete from Login;
delete from Market;
delete from Messages;
delete from PKLog;
delete from PKTag;
delete from Quests;
delete from Wedding;
delete from chat1;
delete from chat2;
delete from chat3;
delete from chat4;

Finally truncate the tables mentioned above to reset the auto_increment to 0
Create a fake clan with cid 200 and you're ready to go!
