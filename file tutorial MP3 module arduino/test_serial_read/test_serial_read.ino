#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(2, 3); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

void setup() {
  mySoftwareSerial.begin(9600);
  Serial.begin(9600);

  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true){
      delay(0); // Code to compatible with ESP8266 watch dog.
    }
  }
  Serial.println(F("DFPlayer Mini online."));

  myDFPlayer.volume(10);  //Set volume value. From 0 to 30
}

void loop() {
  if(Serial.available()){
    char x = Serial.read();
    Serial.println(x);
    if(x == '1'){myDFPlayer.play(1);}
    else if(x == '2'){myDFPlayer.play(2);}
    else if(x == '3'){myDFPlayer.play(3);}
    else if(x == '4'){myDFPlayer.play(4);}
    else if(x == '5'){myDFPlayer.play(5);}
    delay(1000);
  }
}
