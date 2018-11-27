/*
  Control a WTV020M01 module to play voices from an Arduino board.
  Created by Juliana S. Barreto, November 11th, 2018.
  Released into the public domain
*/
#define BOT1 8 //define a conttante BOT1

#include <Wtv020sd16p.h> 

int resetPin = 2;  //Pino Reset
int clockPin = 3;  //Pino clock
int dataPin = 4;   //Pino data (DI)
int busyPin = 5;   //Pino busy

char opt = '1';
boolean valida = true;

Wtv020sd16p wtv020sd16p(resetPin, clockPin, dataPin, busyPin);

void setup() {
  Serial.begin(9600);
  wtv020sd16p.reset();          //iniciar módulo
  pinMode(BOT1, INPUT_PULLUP);  //configura o pino 8 como entrada
  
}

void loop() {
  
    if (digitalRead(BOT1) == LOW) {        //Configura o BOT1 como acionado
      if (opt == '1')
      {
        //wtv020sd16p.playVoice(0);      //Reproduz o arquivo 1
        wtv020sd16p.asyncPlayVoice(0);
        //delay(15000);
        //wtv020sd16p.setVolume(8);
        //delay(2000);
        wtv020sd16p.stopVoice();
        delay(200);
        opt = '2';
        Serial.println(opt);
      } else {
        //wtv020sd16p.playVoice(1);      //Reproduz o arquivo 2
        wtv020sd16p.asyncPlayVoice(1);
        //delay(15000);
        //wtv020sd16p.setVolume(8);
        //delay(2000);
        wtv020sd16p.stopVoice();
        delay(200);
        opt = '1';
        Serial.println(opt);
      }

    }
    
}



