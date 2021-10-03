#include <SPI.h>
#include <MFRC522.h>
#define RST_PIN 9
#define SS_PIN 10

MFRC522 mfrc522(SS_PIN, RST_PIN);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(! mfrc522.PICC_IsNewCardPresent())
  {
    Serial.println("OK");
    return;
  }
  //Serial.println("OK");
  if(! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }
  mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
}
