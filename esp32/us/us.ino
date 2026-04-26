#include <SoftwareSerial.h>

SoftwareSerial mySerial(16, 17);
void clear_serial(){
  while(mySerial.read()>= 0);
  while(Serial.read()>= 0);
}
void setup()
  {
    Serial.begin(9600); //set the baud rate of serial port to 9600;
    mySerial.begin(9600); //set the GPS baud rate to 9600;

  }
//处理NB模块通过串口发来的信息
String get_msg(){
  String str;
  while(mySerial.available())
    {
      str += char(mySerial.read());
      delayMicroseconds(1100);
    }   

  if(str.length()!=0){
      Serial.println("Get msg: \n" + str); 
  }           
  return str;
}

String send_msg(){
  String str;
  while(Serial.available())
    {
      str += char(Serial.read());
      delay(2);
    }   

  if(str.length()!=0){
      mySerial.println(str); 

       
  }           
  return str;
}

void loop()
  {
    send_msg();
  get_msg();

  }
 