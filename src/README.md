# Hochzeitstelefoncode 

04.12.22

Der Code wirft in VScode fehler auf. mit plattformio lässt er sich allerdings bauen. 

Die Rufnummern können in numTold.ino bis 9999 geändert werden.

/////////////////////////////////////////////////////////////////////////////////////

How to add new tracks. 

Installiere die Programmierumgebung ( win und mac version im drive) 
�ffne den sketch: finalSketch.ino

Gehe in den tab:  numToId
kopiere : if(nums.equals("0000")) return 1;


Die 4 Zahlen sind die zuw�hlenden Nummern.
Die letzte Zahl ist die fortlaufende Mp3-nummerierung. 
0001.mp3 ist hier 1, 0072.mp3 ist hier 72. Und so weiter.

Nachdem die Tracks im Code zugewiesen worden sind, gehe zu dem Reiter Werkzeuge.
Stelle sicher das das Arduino mit dem computer �ber Usb verbunden ist. 

Stelle nun sicher ob unter dem Reiter ''Board:'' Arduino/Genuino Uno ausgew�hlt ist.
Stelle nun im Reiter Werkzeug unter dem Reiter Port das Com(#nummer) mit einem Hacken versehen ist.

Nun dr�cke den Pfeil zum Hochladen des Sketches. 


Mp3-Modul:

Stelle sicher das die neuen Tracks auf der SD-Karte unter dem Ordner /mp3 vorhanden 
und richtig nummeriert worden sind. 

Richtige Nummerierung: 0001.mp3 - 9999.mp3

Die Nummerierung muss fortlaufend sein.



Greetz Elko

Code: Johannes Eschner & Elko Braas
	(ccnc) Lasse Marburg / machinaex.de
Readme: Elko Braas





 