#include <SPI.h>
#include <LoRa.h>

#define SS 5
#define RST 25
#define DI0 2
#define BAND 433E6
#define DEVICE_ID "friend_01"  // 每个设备设置不同的ID

void setup() {
  Serial.begin(9600);
  LoRa.setPins(SS, RST, DI0);
  if (!LoRa.begin(BAND)) {
    while (1);
  }
}

void loop() {
  LoRa.beginPacket();
  LoRa.print(DEVICE_ID);
  LoRa.print(":HIGH");
  LoRa.endPacket();
  Serial.print("OK");
  delay(2000);
}

