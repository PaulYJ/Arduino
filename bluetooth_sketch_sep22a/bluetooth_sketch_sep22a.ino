#include <SoftwareSerial.h>
double A;
int D;
int SG=0;
int bluetoothTx = 3;  // TX-O pin of bluetooth mate, Arduino D2
int bluetoothRx = 2;  // RX-I pin of bluetooth mate, Arduino D3
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);


void setup() {
  Serial.begin(9600);
  bluetooth.begin(115200);  // The Bluetooth Mate defaults to 115200bps
  bluetooth.print("$");  // Print three times individually
  bluetooth.print("$");
  bluetooth.print("$");  // Enter command mode
  delay(100);  // Short delay, wait for the Mate to send back CMD
  bluetooth.println("U,9600,N");  // Temporarily Change the baudrate to 9600, no parity
  // 115200 can be too fast at times for NewSoft
//  Serial to relay the data reliably
  bluetooth.begin(9600);  // Start bluetooth serial at 9600
}

void loop() {
//  A=analogRead(SG);
  delay(100);
//  if (A>0)
//  {
    digitalWrite(bluetoothRx,HIGH);
    bluetooth.print(bluetoothRx,1);
    delay(100);
//  }
//  else
//  {
    digitalWrite(bluetoothRx,LOW);
    bluetooth.print(bluetoothRx,0);
//
//}
//  digitalWrite(bluetoothRx,A);
//  if(bluetooth.available())  // If the bluetooth sent any characters
//  {
    // Send any characters the bluetooth prints to the serial monitor
//    Serial.print((char)bluetooth.read());  
//  }
//  if(Serial.available())  // If stuff was typed in the serial monitor
//  {
    // Send any characters the Serial monitor prints to the bluetooth
//    bluetooth.print(A);
//  }
  // and loop forever and ever!
}
 
