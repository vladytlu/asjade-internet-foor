/**
   BasicHTTPSClient.ino

    Created on: 20.08.2018

*/

#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <ESP8266HTTPClient.h>

#include <WiFiClientSecureBearSSL.h>
// Fingerprint for demo URL, expires on June 2, 2021, needs to be updated well before this date
//36 AB B5 84 1E F1 AA C2 8E 4B 50 24 B2 A3 70 55 FB 96 F2 43
//const uint8_t fingerprint[20] = {0x36, 0xAB, 0xB5, 0x84, 0x1E, 0xF1, 0xAA, 0xC2, 0x8E, 0x4B, 0x50, 0x24, 0xB2, 0xA3, 0x70, 0x55, 0xFB, 0x96, 0xF2, 0x43};
const uint8_t fingerprint[20] = {0x5A, 0x12, 0xCA, 0xB5, 0x35, 0x69, 0x04, 0x81, 0xE6, 0x1F, 0x8A, 0x3D, 0xBA, 0xF1, 0x87, 0x1A, 0x24, 0xA5, 0x40, 0x64};
ESP8266WiFiMulti WiFiMulti;

void setup() {
  
  Serial.begin(115200);
  // Serial.setDebugOutput(true);
  Serial.begin(115200); //setup
  pinMode(D0, OUTPUT); //mainRed
  pinMode(D1, OUTPUT); //mainYel
  pinMode(D2, OUTPUT); //mainGr
  pinMode(D3, OUTPUT); //secRed
  pinMode(D4, OUTPUT); //secGr
  Serial.println();
  Serial.println();
  Serial.println();

  for (uint8_t t = 4; t > 0; t--) {
    Serial.printf("[SETUP] WAIT %d...\n", t);
    Serial.flush();
    delay(1000);
  }

  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP("TLU", "");
}

void loop() {
  // wait for WiFi connection
  
  if ((WiFiMulti.run() == WL_CONNECTED)) {

    std::unique_ptr<BearSSL::WiFiClientSecure>client(new BearSSL::WiFiClientSecure);

    client->setFingerprint(fingerprint);
    // Or, if you happy to ignore the SSL certificate, then use the following line instead:
    // client->setInsecure();

    HTTPClient https;
     
    Serial.print("[HTTPS] begin...\n");
    
    if (https.begin(*client, 
       "https://asjadeinternet-67555-default-rtdb.europe-west1.firebasedatabase.app/1008.json")) {  // HTTPS
      https.addHeader("Content-Type", "application/json");
    int httpCode = https.GET();
    String httpCode2 = https.getString();
    Serial.println(httpCode2);
    if (httpCode2 == "{\"valgus1\":\"roheline\"}"){
        digitalWrite(D0,LOW);
        digitalWrite(D1,LOW);
        digitalWrite(D2,HIGH);
        digitalWrite(D3,HIGH);
        digitalWrite(D4,LOW);
        //pinMode(D0 //mainRed
        //pinMode(D1 //mainYel
        //pinMode(D2 /mainGr
        //pinMode(D3 //secRed
        //pinMode(D4 //secGr        
     } else if (httpCode2 == "{\"valgus1\":\"kollane\"}"){
        digitalWrite(D0,LOW);
        digitalWrite(D1,HIGH);
        digitalWrite(D2,LOW);
        digitalWrite(D3,HIGH);
        digitalWrite(D4,LOW);
      } else if (httpCode2 == "{\"valgus1\":\"punane\"}"){
        digitalWrite(D0,HIGH);
        digitalWrite(D1,LOW);
        digitalWrite(D2,LOW);
        digitalWrite(D3,HIGH);
        digitalWrite(D4,LOW);        
      } else if (httpCode2 == "{\"valgus2\":\"roheline\"}"){
        digitalWrite(D0,HIGH);
        digitalWrite(D1,LOW);
        digitalWrite(D2,LOW);
        digitalWrite(D3,LOW);
        digitalWrite(D4,HIGH);            
      } else if (httpCode2 == "{\"valgus2\":\"kollane1\"}"){
        digitalWrite(D0,LOW);
        digitalWrite(D1,LOW);
        digitalWrite(D2,LOW);
        digitalWrite(D3,LOW);
        digitalWrite(D4,LOW); 
      } else if (httpCode2 == "{\"valgus2\":\"kollane2\"}"){
        digitalWrite(D0,LOW);
        digitalWrite(D1,HIGH);
        digitalWrite(D2,LOW);
        digitalWrite(D3,LOW);
        digitalWrite(D4,LOW); 
      }

      https.end();
      
    } else {
      Serial.printf("[HTTPS] Unable to connect\n");
    }
    


  Serial.println("Wait 10s before next round...");
  //Serial.println(digitalRead(D3));
  //Serial.println(digitalRead(D2));
  delay(100);
}
}
