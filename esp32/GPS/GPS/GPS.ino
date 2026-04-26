/*
输出解析后的坐标：121.417381287,31.028057098
*/

#include <TinyGPS++.h>
#include <SoftwareSerial.h>


//GPS接入串口2（16，17）
TinyGPSPlus gps;
// 软串口，用于NB模块的通信
SoftwareSerial mySerial(36, 33); // RX, TX

float latitude;
float longitude;
float last_latitude;
float last_longitude;
//设备ID
String name = "001";

//处理NB模块通过串口发来的信息
String get_msg(){
  String str;
  while(mySerial.available())
    {
      str += char(mySerial.read());
      delayMicroseconds(1100);;
    }   

  if(str.length()!=0){
      Serial.println("Get msg: \n" + str); 
  }           
  return str;
}

void clear_serial(){
  while(mySerial.read()>= 0);
  while(Serial.read()>= 0);
}



void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);


  
}


//===============================================


void loop() {
  get_msg();
  delay(1000);

  }