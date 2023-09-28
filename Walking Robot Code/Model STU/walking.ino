
#include <Servo.h>
Servo axis1;
Servo shoulder1;
Servo elbow1;
Servo shoulder2;
Servo elbow2;
Servo hip3;
Servo knee3;
Servo hip4;
Servo knee4;
int a1 = 90;// variable to store the servo position
int s1 = 90;
int s2 = 80;
int h3 = 84;
int h4 = 91;
int e1 = 107;
int e2 = 90;
int k3 = 86;
int k4 = 90;
int d1 = 500;
int d2 = 1000;
int d3 = 50;
int d4 = 75;
int d5 = 100;
int d6 = 3000;
int m = 0;

void setup() {
  axis1.write(a1);
  axis1.attach(1);//red
  delay(d1);
  hip3.write(h3);
  hip3.attach(6);//purple
  delay(d1);
  shoulder1.write(s1);
  shoulder1.attach(2);//orange
  delay(d1);
  hip4.write(h4);
  hip4.attach(8);//grey
  delay(d1);
  shoulder2.write(s2);
  shoulder2.attach(4);//green 
  delay(d2);
  knee3.write(k3);
  knee3.attach(7);//black
  delay(d2); 
  elbow1.write(e1);
  elbow1.attach(3);//yellow
  delay(d2);
  knee4.write(k4);
  knee4.attach(9);//white
  delay(d2);
  elbow2.write(e2);
  elbow2.attach(5);//blue
  delay(d6);
  elbow2.write(e2+60);
  delay(d5);
  shoulder2.write(s2-30);
  delay(d5);
  knee4.write(k4+60);
  delay(d5);
  hip4.write(h4-30);
  delay(d5);
  elbow1.write(e1-60);
  delay(d5);
  shoulder1.write(s1+30);
  delay(d5);
  knee3.write(k3-60);
  delay(d5);
  hip3.write(h3+30);
    delay(d6);
  }
void loop() {
walk3();
        }
void walk1(){
     knee3.write(k3-70);
     delay(0);
     elbow2.write(e2+70);
     delay(d5);
     shoulder2.write(s2);
     delay(0);
     hip3.write(h3);
     delay(d5);
     knee3.write(k3-20);
     delay(0);
     elbow2.write(e2+20);
     delay(d5);
     shoulder2.write(s2-30);
     delay(0);
     hip3.write(h3+30);
     delay(d5);
     knee3.write(k3-60);
     delay(0);
     elbow2.write(e2+60);
     delay(d5);
     knee4.write(k4+70);
     delay(0);
     elbow1.write(e1-70);
     delay(d5);
     shoulder1.write(s1);
     delay(0);
     hip4.write(h4);
     delay(d5);
     knee4.write(k4+20);
     delay(0);
     elbow1.write(e1-20);
     delay(d5);
     shoulder1.write(s1+30);
     delay(0);
     hip4.write(h4-30);
     delay(d5);
     knee4.write(k4+60);
     delay(0);
     elbow1.write(e1-60);
     delay(d5);}
void walk2() {
     shoulder1.write(s1-30);
     delay(d4);
     elbow1.write(e1);
     delay(d5);
     shoulder2.write(s2+30);
     delay(d4);
     elbow2.write(e2);
     delay(d5);
      hip3.write(h3+30);
     delay(d4);
     knee3.write(k3);
     delay(d5);
    hip4.write(h4-30);
     delay(d4);
     knee4.write(k4);
     delay(d5);
     shoulder1.write(s1+30);
     delay(d4);
     elbow1.write(e1-60);
     delay(d5);
     shoulder2.write(s2-30);
     delay(d4);
     elbow2.write(e2+60);
     delay(d5);
      hip3.write(h3+30);
     delay(d4);
     knee3.write(k3-60);
     delay(d5);
    hip4.write(h4-30);
     delay(d4);
     knee4.write(k4+60);
     }
void walk3(){
  for (m = 0; m <= 12; m += 1) { 
     knee3.write(k3-60-m);
     delay(0);
     elbow2.write(e2+60+m);
     delay(15);}
  for (m = 0; m <= 30; m += 1) {    
     shoulder2.write(s2-30+m);
     delay(0);
     hip3.write(h3+30-m);
     delay(15);}
  for (m = 0; m <= 24; m += 1) {   
     knee3.write(k3-72+m);
     delay(0);
     elbow2.write(e2+72-m);
     delay(15);}
  for (m = 0; m <= 30; m += 1) {      
     shoulder2.write(s2-m);
     delay(0);
     hip3.write(h3+m);
     delay(15);}
  for (m = 0; m <=12; m += 1){
    knee3.write(k3-48-m);
    delay(0);
    elbow2.write(e2+48+m);
    delay(15);}
  for (m = 0; m <= 12; m += 1) { 
     knee4.write(k4+60+m);
     delay(0);
     elbow1.write(e1-60-m);
     delay(15);}
  for (m = 0; m <= 30; m += 1) {    
     shoulder1.write(s1+30-m);
     delay(0);
     hip4.write(h4-30+m);
     delay(15);}
  for (m = 0; m <= 24; m += 1) {   
     knee4.write(k4+72-m);
     delay(0);
     elbow1.write(e1-72+m);
     delay(15);}
  for (m = 0; m <= 30; m += 1) {      
     shoulder1.write(s1+m);
     delay(0);
     hip4.write(h4-m);
     delay(15);}
  for (m = 0; m <=12; m+= 1){
    knee4.write(k3+48+m);
    delay(0);
    elbow1.write(e2-48-m);
    delay(15);}     
     }




    
    
