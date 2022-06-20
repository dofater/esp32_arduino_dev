/*
  To upload through terminal you can use: curl -F "image=@firmware.bin" esp32-webupdate.local/update
*/

#include <WiFi.h>
#include <WiFiClient.h>

#ifndef STASSID
#define STASSID "ssid"
#define STAPSK  "password"
#endif

#define RETRY_CONNECT 10

const char* ssid = STASSID;
const char* password = STAPSK;

int RetryCount = 0;

void setup(void) {

  Serial.begin(115200);
  Serial.println();
  Serial.println("Booting...");
  
  WiFi.mode(WIFI_AP_STA);
  WiFi.disconnect(true, true);
  
  Serial.println("scan start");

  // WiFi.scanNetworks will return the number of networks found
  int n = WiFi.scanNetworks();
  Serial.println("scan done");
  if (n == 0) {
      Serial.println("no networks found");
  } else {
      Serial.print(n);
      Serial.println(" networks found");
      for (int i = 0; i < n; ++i) {
          // Print SSID and RSSI for each network found
          Serial.print(i + 1);
          Serial.print(": ");
          Serial.print(WiFi.SSID(i));
          Serial.print(" (");
          Serial.print(WiFi.RSSI(i));
          Serial.print(")");
          Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
          delay(10);
      }
  }
  Serial.println("");
  
  WiFi.begin(ssid, password);
  Serial.print("WiFi connecting...");
}

void loop(void) {
  
  if (WiFi.waitForConnectResult() == WL_CONNECTED){
    Serial.println("OK");
    delay(1000);
    return;
  }
  else{
    Serial.println("Fail");
    Serial.print("WiFi reconnecting...");
    WiFi.reconnect();
    RetryCount = 0;
  }

  // Wait for connection
  while (RetryCount < RETRY_CONNECT) {
    
    if (WiFi.status() != WL_CONNECTED)
    { 
      Serial.print(".");
    }
    else
    {
      Serial.println("OK");
      Serial.print("Connected to ");
      Serial.println(ssid);
      Serial.print("IP address: ");
      Serial.println(WiFi.localIP());

      break;
    }
    
    RetryCount++;
    if (RetryCount == RETRY_CONNECT){
      Serial.println("timeout");
      Serial.print("WiFi reconnecting...");
      //WiFi.disconnect(true, true);
      //WiFi.begin(ssid, password);

      WiFi.reconnect();

      break;
    }

    delay(1000);
  }

  delay(1000);
}
