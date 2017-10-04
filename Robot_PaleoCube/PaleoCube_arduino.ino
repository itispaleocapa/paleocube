
#include <SoftwareSerial.h>//Belometti, Novetti
#include <Stepper.h>
#include<Servo.h>


char comando='n'; //comando da eseguire

SoftwareSerial BT(2, 3); // RX verde, TX giallo, da scaambiare durante il collegamento
Servo servodx;
Servo servosx;
void setup() {

  servosx.attach(4);
  servodx.attach(5);  
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  BT.begin(9600);
  BT.println("Hello, world?");
}

void loop() { // run over and over
  if (BT.available()) {
    comando = BT.read();
    if(comando == 'A'){
      Serial.write(comando);
      servosx.write(150);// a tutta velocità in avanti
      servodx.write(0);//negativo perchè speculari
      delay(1500); 
      servodx.write(90);//ferma i motori
      servosx.write(90); 
      delay(100);
    }
    else if(comando == 'D'){
      Serial.write(comando);
      servosx.write(180);//ruota su se stesso
      servodx.write(180);
       delay(740); 
       servodx.write(90);//ferma i motori
       servosx.write(90); 
       delay(200);
    }
    else if(comando == 'S'){
      Serial.write(comando);
      servodx.write(0);
      servosx.write(0);
      delay(740); 
      servodx.write(90);//ferma i motori
      servosx.write(90);
     delay(200);  
    }
  }
}
