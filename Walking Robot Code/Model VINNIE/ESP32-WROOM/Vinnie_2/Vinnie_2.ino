//All my code was uploaded to my repository at https://github.com/bsverdin/Walking-Robot.
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
//Starting postition based on how servos are installed
int s1 = 90;
int s2 = 80;
int h3 = 84;
int h4 = 91;
int e1 = 107;
int e2 = 90;
int k3 = 86;
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
// WiFi Password
const char* ssid1 = "VinnieWiFi";
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
  if (myData.b == 1) {
    Serial.println("Forward");
    walk_fwd();
  } else if (myData.b == 2) {
    Serial.println("Left");
    walk_left();
  } else if (myData.b == 3) {
    Serial.println("Right");
    walk_right();
  } else if (myData.b == 4) {
    Serial.println("Backward");
    walk_back();
  } else if (myData.b == 5) {
    Serial.println("Stop");
    walk_stop();
  }
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
  esp_now_register_recv_cb(OnDataRecv);

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
}
void walk_fwd() {
  for (m = 0; m <= 12; m += 1) {
    knee3.write(k3 - 60 - m);
    delay(0);
    elbow2.write(e2 + 60 + m);
    delay(15);
  }
  for (m = 0; m <= 30; m += 1) {
    shoulder2.write(s2 - 30 + m);
    delay(0);
    hip3.write(h3 + 30 - m);
    delay(15);
  }
  for (m = 0; m <= 24; m += 1) {
    knee3.write(k3 - 72 + m);
    delay(0);
    elbow2.write(e2 + 72 - m);
    delay(15);
  }
  for (m = 0; m <= 30; m += 1) {
    shoulder2.write(s2 - m);
    delay(0);
    hip3.write(h3 + m);
    delay(15);
  }
  for (m = 0; m <= 12; m += 1) {
    knee3.write(k3 - 48 - m);
    delay(0);
    elbow2.write(e2 + 48 + m);
    delay(15);
  }
  for (m = 0; m <= 12; m += 1) {
    knee4.write(k4 + 60 + m);
    delay(0);
    elbow1.write(e1 - 60 - m);
    delay(15);
  }
  for (m = 0; m <= 30; m += 1) {
    shoulder1.write(s1 + 30 - m);
    delay(0);
    hip4.write(h4 - 30 + m);
    delay(15);
  }
  for (m = 0; m <= 24; m += 1) {
    knee4.write(k4 + 72 - m);
    delay(0);
    elbow1.write(e1 - 72 + m);
    delay(15);
  }
  for (m = 0; m <= 30; m += 1) {
    shoulder1.write(s1 + m);
    delay(0);
    hip4.write(h4 - m);
    delay(15);
  }
  for (m = 0; m <= 12; m += 1) {
    knee4.write(k3 + 48 + m);
    delay(0);
    elbow1.write(e2 - 48 - m);
    delay(15);
  }
}
void walk_left() {
  for (m = 0; m <= 12; m += 1) {
    knee3.write(k3 - 60 - m);
    delay(0);
    elbow2.write(e2 + 60 + m);
    delay(15);
  }
  for (m = 0; m <= 30; m += 1) {
    shoulder2.write(s2 - 30 + m);
    delay(0);
    hip3.write(h3 + 30 - m);
    delay(15);
  }
  for (m = 0; m <= 24; m += 1) {
    knee3.write(k3 - 72 + m);
    delay(0);
    elbow2.write(e2 + 72 - m);
    delay(15);
  }
  for (m = 0; m <= 30; m += 1) {
    shoulder2.write(s2 - m);
    delay(0);
    hip3.write(h3 + m);
    delay(15);
  }
  for (m = 0; m <= 12; m += 1) {
    knee3.write(k3 - 48 - m);
    delay(0);
    elbow2.write(e2 + 48 + m);
    delay(15);
  }
  for (m = 0; m <= 12; m += 1) {
    knee4.write(k4 + 60 + m);
    delay(0);
    elbow1.write(e1 - 60 - m);
    delay(15);
  }
  for (m = 0; m <= 30; m += 1) {
    shoulder1.write(s1 + 30 - m);
    delay(0);
    hip4.write(h4 - 30 + m);
    delay(15);
  }
  for (m = 0; m <= 24; m += 1) {
    knee4.write(k4 + 72 - m);
    delay(0);
    elbow1.write(e1 - 72 + m);
    delay(15);
  }
  for (m = 0; m <= 30; m += 1) {
    shoulder1.write(s1 + m);
    delay(0);
    hip4.write(h4 - m);
    delay(15);
  }
  for (m = 0; m <= 12; m += 1) {
    knee4.write(k3 + 48 + m);
    delay(0);
    elbow1.write(e2 - 48 - m);
    delay(15);
  }
}
void walk_right() {
  for (m = 0; m <= 12; m += 1) {
    knee3.write(k3 - 60 - m);
    delay(0);
    elbow2.write(e2 + 60 + m);
    delay(15);
  }
  for (m = 0; m <= 30; m += 1) {
    shoulder2.write(s2 - 30 + m);
    delay(0);
    hip3.write(h3 + 30 - m);
    delay(15);
  }
  for (m = 0; m <= 24; m += 1) {
    knee3.write(k3 - 72 + m);
    delay(0);
    elbow2.write(e2 + 72 - m);
    delay(15);
  }
  for (m = 0; m <= 30; m += 1) {
    shoulder2.write(s2 - m);
    delay(0);
    hip3.write(h3 + m);
    delay(15);
  }
  for (m = 0; m <= 12; m += 1) {
    knee3.write(k3 - 48 - m);
    delay(0);
    elbow2.write(e2 + 48 + m);
    delay(15);
  }
  for (m = 0; m <= 12; m += 1) {
    knee4.write(k4 + 60 + m);
    delay(0);
    elbow1.write(e1 - 60 - m);
    delay(15);
  }
  for (m = 0; m <= 30; m += 1) {
    shoulder1.write(s1 + 30 - m);
    delay(0);
    hip4.write(h4 - 30 + m);
    delay(15);
  }
  for (m = 0; m <= 24; m += 1) {
    knee4.write(k4 + 72 - m);
    delay(0);
    elbow1.write(e1 - 72 + m);
    delay(15);
  }
  for (m = 0; m <= 30; m += 1) {
    shoulder1.write(s1 + m);
    delay(0);
    hip4.write(h4 - m);
    delay(15);
  }
  for (m = 0; m <= 12; m += 1) {
    knee4.write(k3 + 48 + m);
    delay(0);
    elbow1.write(e2 - 48 - m);
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
