/*
  WiFi LED Toggle

  Demonstrates using the WiFiS3 library to send SCPI commands to a Red Pitaya board.

  Network setup:
    * Set the SSID and password below to match your WiFi network.
    * Update the server IP address so it points to your Red Pitaya.
    * Ensure the Red Pitaya SCPI server is running and reachable on port 5000.
*/

#include <WiFiS3.h>
#include "SCPI_RP.h"
#include "tcp/tcp_scpi.h"

const char *ssid = "YOUR_SSID";
const char *pass = "YOUR_PASSWORD";
IPAddress server(192, 168, 1, 100);  // Red Pitaya IP

WiFiClient wifiClient;
scpi_rp::TCPInterface client;
scpi_rp::SCPIRedPitaya rp;

bool isInit = false;

void setup() {
  Serial.begin(115200);

  Serial.println("Connecting to WiFi");
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  Serial.println("Connecting to Red Pitaya");
  if (wifiClient.connect(server, 5000)) {
    Serial.println("Connected to Red Pitaya");
    client.init(&wifiClient);
    rp.initStream(&client);
    isInit = true;
  } else {
    Serial.println("Connection failed");
  }
}

void loop() {
  if (!isInit) return;

  rp.system_led.heartBeat(true);
  delay(500);
  rp.system_led.heartBeat(false);
  delay(500);
}

