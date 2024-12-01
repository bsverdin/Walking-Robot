//Libraries
#include <esp_now.h>
#include <ESP32Servo.h>
#include <WiFi.h>
#include "esp_wifi.h"
//Chanel
#define CHANNEL 1
//Servos
Servo shoulder1;
Servo elbow1;
Servo shoulder2;
Servo elbow2;
Servo hip3;
Servo knee3;
Servo hip4;
Servo knee4;
//Starting position based on how servos are installed
int s1 = 90;
int s2 = 90;
int h3 = 90;
int h4 = 90;
int e1 = 90;
int e2 = 90;
int k3 = 90;
int k4 = 90;
//Delays
int d1 = 500;
int d2 = 1000;
int d3 = 50;
int d4 = 75;
int d5 = 100;
int d6 = 3000;
int m = 0;
//servo GPIO pins
int s1Pin = 19;
int e1Pin = 18;
int s2Pin = 5;
int e2Pin = 17;
int h3Pin = 16;
int k3Pin = 4;
int h4Pin = 2;
int k4Pin = 15;
//Variable to control the robot
int control = 0;
//Methods
void walk_fwd() {
  for (m = 0; m <= 12; m += 1) {
    knee3.write(k3 - 50 - m);
    delay(0);
    elbow2.write(e2 + 50 + m);
    delay(15);
  }
  for (m = 0; m <= 30; m += 1) {
    shoulder2.write(s2 - 20 + m);
    delay(0);
    hip3.write(h3 + 20 - m);
    delay(15);
  }
  for (m = 0; m <= 24; m += 1) {
    knee3.write(k3 - 62 + m);
    delay(0);
    elbow2.write(e2 + 62 - m);
    delay(15);
  }
  for (m = 0; m <= 30; m += 1) {
    shoulder2.write(s2 - m);
    delay(0);
    hip3.write(h3 + m);
    delay(15);
  }
  for (m = 0; m <= 12; m += 1) {
    knee3.write(k3 - 38 - m);
    delay(0);
    elbow2.write(e2 + 38 + m);
    delay(15);
  }
  for (m = 0; m <= 12; m += 1) {
    knee4.write(k4 + 50 + m);
    delay(0);
    elbow1.write(e1 - 50 - m);
    delay(15);
  }
  for (m = 0; m <= 30; m += 1) {
    shoulder1.write(s1 + 20 - m);
    delay(0);
    hip4.write(h4 - 20 + m);
    delay(15);
  }
  for (m = 0; m <= 24; m += 1) {
    knee4.write(k4 + 62 - m);
    delay(0);
    elbow1.write(e1 - 62 + m);
    delay(15);
  }
  for (m = 0; m <= 30; m += 1) {
    shoulder1.write(s1 + m);
    delay(0);
    hip4.write(h4 - m);
    delay(15);
  }
  for (m = 0; m <= 12; m += 1) {
    knee4.write(k3 + 38 + m);
    delay(0);
    elbow1.write(e2 - 38 - m);
    delay(15);
  }
}
void walk_left() {
  for (m = 0; m <= 12; m += 1) {
    knee3.write(k3 - 40 - m);
    delay(0);
    elbow2.write(e2 + 80 + m);
    delay(15);
  }
  for (m = 0; m <= 30; m += 1) {
    shoulder2.write(s2 - 50 + m);
    delay(0);
    hip3.write(h3 + 10 - m);
    delay(15);
  }
  for (m = 0; m <= 24; m += 1) {
    knee3.write(k3 - 52 + m);
    delay(0);
    elbow2.write(e2 + 92 - m);
    delay(15);
  }
  for (m = 0; m <= 30; m += 1) {
    shoulder2.write(s2 - m);
    delay(0);
    hip3.write(h3 + m);
    delay(15);
  }
  for (m = 0; m <= 12; m += 1) {
    knee3.write(k3 - 28 - m);
    delay(0);
    elbow2.write(e2 + 68 + m);
    delay(15);
  }
  for (m = 0; m <= 12; m += 1) {
    knee4.write(k4 + 80 + m);
    delay(0);
    elbow1.write(e1 - 40 - m);
    delay(15);
  }
  for (m = 0; m <= 30; m += 1) {
    shoulder1.write(s1 + 10 - m);
    delay(0);
    hip4.write(h4 - 50 + m);
    delay(15);
  }
  for (m = 0; m <= 24; m += 1) {
    knee4.write(k4 + 92 - m);
    delay(0);
    elbow1.write(e1 - 52 + m);
    delay(15);
  }
  for (m = 0; m <= 30; m += 1) {
    shoulder1.write(s1 + m);
    delay(0);
    hip4.write(h4 - m);
    delay(15);
  }
  for (m = 0; m <= 12; m += 1) {
    knee4.write(k3 + 68 + m);
    delay(0);
    elbow1.write(e2 - 28 - m);
    delay(15);
  }
}
void walk_right() {
  for (m = 0; m <= 12; m += 1) {
    knee3.write(k3 - 80 - m);
    delay(0);
    elbow2.write(e2 + 40 + m);
    delay(15);
  }
  for (m = 0; m <= 30; m += 1) {
    shoulder2.write(s2 - 10 + m);
    delay(0);
    hip3.write(h3 + 50 - m);
    delay(15);
  }
  for (m = 0; m <= 24; m += 1) {
    knee3.write(k3 - 92 + m);
    delay(0);
    elbow2.write(e2 + 52 - m);
    delay(15);
  }
  for (m = 0; m <= 30; m += 1) {
    shoulder2.write(s2 - m);
    delay(0);
    hip3.write(h3 + m);
    delay(15);
  }
  for (m = 0; m <= 12; m += 1) {
    knee3.write(k3 - 68 - m);
    delay(0);
    elbow2.write(e2 + 28 + m);
    delay(15);
  }
  for (m = 0; m <= 12; m += 1) {
    knee4.write(k4 + 40 + m);
    delay(0);
    elbow1.write(e1 - 80 - m);
    delay(15);
  }
  for (m = 0; m <= 30; m += 1) {
    shoulder1.write(s1 + 50 - m);
    delay(0);
    hip4.write(h4 - 10 + m);
    delay(15);
  }
  for (m = 0; m <= 24; m += 1) {
    knee4.write(k4 + 52 - m);
    delay(0);
    elbow1.write(e1 - 92 + m);
    delay(15);
  }
  for (m = 0; m <= 30; m += 1) {
    shoulder1.write(s1 + m);
    delay(0);
    hip4.write(h4 - m);
    delay(15);
  }
  for (m = 0; m <= 12; m += 1) {
    knee4.write(k3 + 28 + m);
    delay(0);
    elbow1.write(e2 - 68 - m);
    delay(15);
  }
}
void walk_back() {
  for (m = 0; m <= 12; m += 1) {
    knee4.write(k3 - 48 - m);
    delay(0);
    elbow1.write(e2 + 48 + m);
    delay(15);
  }
  for (m = 0; m <= 30; m += 1) {
    shoulder1.write(s1 - m);
    delay(0);
    hip4.write(h4 + m);
    delay(15);
  }
  for (m = 0; m <= 24; m += 1) {
    knee4.write(k4 - 72 + m);
    delay(0);
    elbow1.write(e1 + 72 - m);
    delay(15);
  }
  for (m = 0; m <= 30; m += 1) {
    shoulder1.write(s1 - 30 + m);
    delay(0);
    hip4.write(h4 + 30 - m);
    delay(15);
  }
  for (m = 0; m <= 12; m += 1) {
    knee4.write(k4 - 60 - m);
    delay(0);
    elbow1.write(e1 + 60 + m);
    delay(15);
  }
  for (m = 0; m <= 12; m += 1) {
    knee3.write(k3 + 48 + m);
    delay(0);
    elbow2.write(e2 - 48 - m);
    delay(15);
  }
  for (m = 0; m <= 30; m += 1) {
    shoulder2.write(s2 + m);
    delay(0);
    hip3.write(h3 - m);
    delay(15);
  }
  for (m = 0; m <= 24; m += 1) {
    knee3.write(k3 + 72 - m);
    delay(0);
    elbow2.write(e2 - 72 + m);
    delay(15);
  }
  for (m = 0; m <= 30; m += 1) {
    shoulder2.write(s2 + 30 - m);
    delay(0);
    hip3.write(h3 - 30 + m);
    delay(15);
  }
  for (m = 0; m <= 12; m += 1) {
    knee3.write(k3 + 60 + m);
    delay(0);
    elbow2.write(e2 - 60 - m);
    delay(15);
  }
}
void walk_stop() {
  elbow2.write(e2 + 60);
  delay(d5);
  shoulder2.write(s2 - 30);
  delay(d5);
  knee4.write(k4 + 60);
  delay(d5);
  hip4.write(h4 - 30);
  delay(d5);
  elbow1.write(e1 - 60);
  delay(d5);
  shoulder1.write(s1 + 30);
  delay(d5);
  knee3.write(k3 - 60);
  delay(d5);
  hip3.write(h3 + 30);
  delay(d6);
}
// WiFi Password
const char* ssid1 = "TerraWiFi";
const char* password1 = "Qwerty123!";
// Receive data
typedef struct struct_message {
  int b;
} struct_message;
struct_message myData;
// callback function that will be executed when data is received
void OnDataRecv(const uint8_t* mac, const uint8_t* incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));
  Serial.println("Data Recieved");
  control = myData.b;
}
void setup() {
  Serial.begin(115200);
  // Wi-Fi connection
  WiFi.mode(WIFI_AP_STA);
  WiFi.softAP(ssid1, password1, CHANNEL, 1);
  IPAddress myIP = WiFi.softAPIP();
  WiFi.begin(ssid1, password1);
  Serial.println("Connected");
  // Init ESP-NOW
  esp_now_init();
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  esp_now_register_recv_cb(esp_now_recv_cb_t(OnDataRecv));

  hip3.attach(h3Pin);  //purple
  hip3.write(h3);
  delay(d1);
  shoulder1.attach(s1Pin);  //orange
  shoulder1.write(s1);
  delay(d1);
  hip4.attach(h4Pin);  //grey
  hip4.write(h4);
  delay(d1);
  shoulder2.attach(s2Pin);  //green
  shoulder2.write(s2);
  delay(d1);
  knee3.attach(k3Pin);  //black
  knee3.write(k3);
  delay(d1);
  elbow1.attach(e1Pin);  //yellow
  elbow1.write(e1);
  delay(d1);
  knee4.attach(k4Pin);  //white
  knee4.write(k4);
  delay(d1);
  elbow2.attach(e2Pin);  //blue
  elbow2.write(e2);
  delay(d5);
  elbow2.write(e2 + 60);
  delay(d5);
  shoulder2.write(s2 - 30);
  delay(d5);
  knee4.write(k4 + 60);
  delay(d5);
  hip4.write(h4 - 30);
  delay(d5);
  elbow1.write(e1 - 60);
  delay(d5);
  shoulder1.write(s1 + 30);
  delay(d5);
  knee3.write(k3 - 60);
  delay(d5);
  hip3.write(h3 + 30);
  delay(d5);
}

void loop() {
  while (myData.b == 1) {
    walk_fwd();
  }
  while (myData.b == 2) {
    walk_left();
  } 
  while (myData.b == 3) {
    walk_right();
  } 
  while (myData.b == 4) {
    walk_back();
  } 
  while (myData.b == 5) {
    walk_stop();
  }
}

