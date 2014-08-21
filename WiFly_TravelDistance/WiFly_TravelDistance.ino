/*
  WiFly bsaed TravelDistance Measurement Test
  
  Author: Yicheng Bai from LCN lab    
  eMail: baiyicheng @gmail.com
  
  Established Date: 08/19/2013
  
  LGPL 3.0

 */
#include <SoftwareSerial.h>

SoftwareSerial WiFlySerial(5,4); //RX  TX
//SoftwareSerial WiFlySerial(5,6);

void setup() {

  Serial.begin(9600);
  Serial.println("SPI UART on WiFly Shield terminal tool");
  Serial.println("--------------------------------------");  
  Serial.println();
  Serial.println("This is a tool to help you troubleshoot problems with the WiFly shield.");
  Serial.println("For consistent results unplug & replug power to your Arduino and WiFly shield.");
  Serial.println("(Ensure the serial monitor is not open when you remove power.)");  
  Serial.println();
  
  WiFlySerial.begin(9600);
  
  Serial.println(" * Use $$$ (with no line ending) to enter WiFly command mode. (\"CMD\")");
  Serial.println(" * Then send each command followed by a carriage return.");
  Serial.println();
  
  Serial.println("Waiting for input.");
  Serial.println();    
  
  WiFlySerial.print("$$$");
  delay(4000);
  WiFlySerial.println("U,9600,N");
  //WiFlySerial.println("---");
  WiFlySerial.begin(9600);
}


void loop() {
  // Terminal routine

  // Always display a response uninterrupted by typing
  // but note that this makes the terminal unresponsive
  // while a response is being received.
  while(WiFlySerial.available() > 0) {
    Serial.print((char)WiFlySerial.read());
  }
  
  while(Serial.available() > 0) {
    WiFlySerial.write(Serial.read());
  }
}
