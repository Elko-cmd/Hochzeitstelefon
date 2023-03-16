
/////////////////////////////////////////////////
////// Telefon Impulswahl Arduino 1.0 ///////////
//// (ccnc) Lasse Marburg / machinaex.de ////////
/////////////////////////////////////////////////

// Impulswahltelefon an Arduino anschlieÃŸen ////
// und Wahleingaben abhnehmen //////////////////


int dialPin = 0; // Analog 0 fÃ¼r Messung am Telefon
int dialVal = 0;
int dialValStat = 0;

int nummer = 0;
int taste = 10;

unsigned long int signalstart = 0;
unsigned long int signalstop = 0;

unsigned long int signalzeit = 0;
unsigned long int keinsignalzeit = 0;

unsigned long int auszeit = 250;
unsigned long int zwischenzeit = 125;

int midValue = 300; // der Schwellenwert um aufgelegt (LOW) von abgenommen (HIGH) zu unterscheiden

boolean dialing = false;
boolean aufgelegt = false;

int lastFour[] = { -3, -3, -3, -3};



void phoneSetup()
{
  // Serial Schnittstelle inititalisieren
  Serial.begin(9600);

  Serial.println("Arduino");
  Serial.println("Impulswahltelefon Version 1.0");
  Serial.println();

  pinMode(dialPin, INPUT);

  Serial.print("Analog 0 ");
  Serial.println(analogRead(0));
}

int seat = 0;
void addNumber(int number) {
  //Serial.println(number);

  lastFour[seat] = number;
  Serial.print(lastFour[0]);
  Serial.print(", ");
  Serial.print(lastFour[1]);
  Serial.print(", ");
  Serial.print(lastFour[2]);
  Serial.print(", ");
  Serial.print(lastFour[3]);
  Serial.println();

  seat ++;
  if (seat >= 4) {
    playTrack(numToId(lastFour));
    clearArray();
  }

}

void clearArray() {
  seat = 0;
  lastFour[0] = -3;
  lastFour[1] = -3;
  lastFour[2] = -3;
  lastFour[3] = -3;
}

void phoneLoop() {
  if (analogRead(dialPin) > midValue)
  {
    dialVal = 1;
  } else {
    dialVal = 0;
  }

  /*
     Wahlvorgang
  */

  if ( dialVal != dialValStat )
  {
    dialValStat = dialVal;

    // bei hochziehen der Waehlscheibe kommt einmalig ein Signal
    if (dialVal == HIGH)
    {
      dialing = true;
      if (aufgelegt)
      {
        //Serial.print("telefon ");
        Serial.print("abgehoben");
        Serial.println();

        aufgelegt = false;
        signalstop = millis();
      }
    }

    else if (dialVal == LOW)
    {
      signalstop = millis();

      //if (dialing)
      //{
      nummer++;
      //Serial.print("telefon ");
      //Serial.print("klackern");
      //Serial.println();

      //udp.sendStr("/Dial", "klacker");
      //}
    }
  }

  /*
      Abfrage ob waehlscheibe runtergelaufen
  */
  keinsignalzeit = millis() - signalstop;

  if ( dialing == true )
  {

    if ( keinsignalzeit > zwischenzeit )
    {
      if (nummer == 10)
      {
        taste = 0;
      }
      else if (nummer > 0) {
        taste = nummer;
      }
      if (taste < 10)
      {
        //Serial.print("telefon ");
        //Serial.print(taste);
        //Serial.println();
        addNumber(taste);
        //udp.sendInt("/Dial", taste);
      }

      dialing = false;
      nummer = 0;
      taste = 10;
    }
  }

  /*
      abfrage ob hoerer aufgelegt
  */
  if ( dialVal == LOW )
  {
    if ( keinsignalzeit > auszeit && aufgelegt == false)
    {
      //Serial.print("telefon ");
      Serial.print("aufgelegt");
      Serial.println();
      myDFPlayer.pause();
      clearArray();
      aufgelegt = true;
      dialing = false;
      nummer = 0;
      taste = 10;
    }
  }
}



