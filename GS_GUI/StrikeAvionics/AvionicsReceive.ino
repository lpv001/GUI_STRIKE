#include<SPI.h>
#include<nRF24L01.h>
#include<RF24.h>
#include "./AvionicsReceive.h"
RF24 radio(9, 10);
const byte address[6] = "00001";
struct Package{
  int roll_rate , pitch_rate , yaw_rate ;
  int roll , pitch , yaw;
  float accelerometerX , accelerometerY , accelerometerZ ;
  int T, P , H;
}data;

void imusetup() {
  //Serial.begin(115200);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.startListening();
}

void imuloop() {
  if (radio.available()>0)
  {
    radio.read(&data, sizeof(data));
//    //Serial.print("T: ");
//    Serial.println(data.T);
//    Serial.print("       ");
//    //Serial.print("P: ");
//    Serial.println(data.P);
//    Serial.print("       ");
//    //Serial.print("H: ");
//    Serial.println(data.H);
//    Serial.print("       ");
//    //Serial.print("dvX: ");
//    Serial.println(data.accelerometerX);
//    Serial.print("       ");
//    //Serial.print("dvY: ");
//    Serial.println(data.accelerometerY);
//    Serial.print("       ");
//    //Serial.print("dvZ: ");
//    Serial.println(data.accelerometerZ);
//    Serial.print("       ");
//    //Serial.print("roll: ");
//    Serial.println(data.roll);
//    Serial.print("       ");
//    //Serial.print("pitch: ");
//    Serial.println(data.pitch);
//    Serial.print("       ");
//    //Serial.print("yaw: ");
//    Serial.println(data.yaw);
//    Serial.print("       ");
//    //Serial.print("gyroX: ");
//    Serial.println(data.roll_rate);
//    Serial.print("       ");
//    //Serial.print("gyroY: ");
//    Serial.println(data.pitch_rate);
//    Serial.print("       ");
//    //Serial.print("gyroZ: ");
//    Serial.println(data.yaw_rate);

    
    //total 12 datA
  }
}
