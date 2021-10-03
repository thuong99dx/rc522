#include <SPI.h>
#include <MFRC522.h>
#define RST_PIN 9
#define SS_PIN 10

MFRC522 mfrc522(SS_PIN, RST_PIN);       
unsigned long uidDec, uidDecTemp; 
byte bCounter, readBit;
unsigned long ticketNumber;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("await card, please insert card....");
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
  
  uidDec = 0;
  Serial.println("==> Dang cho quyet the <===");
  Serial.println("================================================");
  
  Serial.println("This is UID Card : ");
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    uidDecTemp = mfrc522.uid.uidByte[i];
    uidDec = uidDec*256+uidDecTemp;
  } 
  Serial.print("            [");
  Serial.print(uidDec);
  Serial.println("]");
  Serial.println("================================================");

  
  
  mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
}
