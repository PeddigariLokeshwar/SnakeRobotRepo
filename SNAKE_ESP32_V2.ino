//#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
int fd_vcc = 22;
int fd_gnd = 23;
int left_vcc = 19;
int left_gnd = 21;
int right_vcc = 5;
int right_gnd = 18;
int lift_vcc = 4;
int lift_gnd = 2;
char auth[] = "WbWuOSreWOibd6aftvP92_l2kRSjTH0h";
char ssid[] = "TDG_HYD";
char pass[] = "9848023755";
int jigjak1_vcc = 12;
int jigjak1_gnd = 14;
int jigjak2_vcc = 26;
int jigjak2_gnd = 27; 
int jigjak3_vcc = 25;
int jigjak3_gnd = 33;
int jigjak4_vcc = 32;// io
int jigjak4_gnd = 13;
int jigjak5_vcc = 16;
int jigjak5_gnd = 17;
int jigjak6_vcc = 1;// Tx 0 pin
int jigjak6_gnd = 15;
int irs = 34;
int irl = 39;
int irr = 36;
const int freq = 1000;//1k
const int ledChannel = 0;
const int resolution = 8;
int t=0,h=0,x,y,z;
void setup()
{
Serial.begin(9600);
ledcSetup(ledChannel, freq, resolution);
MotorInit();
Blynk.begin(auth, ssid, pass);
//Serial.print("*Explore Robo Mode Computer: Controlled*\n\r");
//Serial.println("Commands:\n W->Forward \n S->Backwards \n A->Left \n D->Right");
}
 
void loop()
{
  
 Blynk.run();
 if(t>0)
 {
 delay(100);
   digitalWrite(jigjak1_vcc,HIGH);
   digitalWrite(jigjak1_gnd,LOW); 
   digitalWrite(jigjak2_vcc,HIGH);
   digitalWrite(jigjak2_gnd,LOW); 
   digitalWrite(jigjak3_vcc,HIGH);
   digitalWrite(jigjak3_gnd,LOW); 
   digitalWrite(jigjak4_vcc,HIGH);
   digitalWrite(jigjak4_gnd,LOW); 
   digitalWrite(jigjak5_vcc,HIGH);
   digitalWrite(jigjak5_gnd,LOW); 
   digitalWrite(jigjak6_vcc,HIGH);
   digitalWrite(jigjak6_gnd,LOW); 
   delay(70);
   digitalWrite(jigjak1_vcc,LOW);
   digitalWrite(jigjak2_vcc,LOW);
   digitalWrite(jigjak3_vcc,LOW);
   digitalWrite(jigjak4_vcc,LOW);
   digitalWrite(jigjak5_vcc,LOW);
   digitalWrite(jigjak6_vcc,LOW); 
   delay(3000);
   digitalWrite(jigjak1_vcc,LOW);
   digitalWrite(jigjak1_gnd,HIGH); 
   digitalWrite(jigjak2_vcc,LOW);
   digitalWrite(jigjak2_gnd,HIGH); 
   digitalWrite(jigjak3_vcc,LOW);
   digitalWrite(jigjak3_gnd,HIGH); 
   digitalWrite(jigjak4_vcc,LOW);
   digitalWrite(jigjak4_gnd,HIGH); 
   digitalWrite(jigjak5_vcc,LOW);
   digitalWrite(jigjak5_gnd,HIGH); 
   digitalWrite(jigjak6_vcc,LOW);
   digitalWrite(jigjak6_gnd,HIGH); 
   delay(70);
   digitalWrite(jigjak1_gnd,LOW);
   digitalWrite(jigjak2_gnd,LOW);
   digitalWrite(jigjak3_gnd,LOW);
   digitalWrite(jigjak4_gnd,LOW);
   digitalWrite(jigjak5_gnd,LOW);
   digitalWrite(jigjak6_gnd,LOW);
    x = digitalRead(irs);
    y = digitalRead(irl);
    z = digitalRead(irr);
    if(x == LOW)//center
    {
    Robot_Stop();
    }
    if(y == LOW)//left
    {
     Robot_Right(); 
    }
    if(z == LOW)//Right
    {
     Robot_Left(); 
    }
 } 
}
//Intialize the motor
void MotorInit()
{
  ledcAttachPin(fd_vcc, 0);
  ledcAttachPin(fd_gnd, 1);
  ledcAttachPin(left_vcc, 2);
  ledcAttachPin(left_gnd, 3);
  ledcAttachPin(right_vcc, 4);
  ledcAttachPin(right_gnd, 5);
  ledcAttachPin(lift_vcc, 6);
  ledcAttachPin(lift_gnd, 7);
  pinMode(jigjak1_vcc, OUTPUT);
  pinMode(jigjak1_gnd, OUTPUT);
  pinMode(jigjak2_vcc, OUTPUT);
  pinMode(jigjak2_gnd, OUTPUT);
  pinMode(jigjak3_vcc, OUTPUT);
  pinMode(jigjak3_gnd, OUTPUT);
  pinMode(jigjak4_vcc, OUTPUT);
  pinMode(jigjak4_gnd, OUTPUT);
  pinMode(jigjak5_vcc, OUTPUT);
  pinMode(jigjak5_gnd, OUTPUT);
  pinMode(jigjak6_vcc, OUTPUT);
  pinMode(jigjak6_gnd, OUTPUT);
  pinMode(irs, INPUT);
  pinMode(irl, INPUT);
  pinMode(irr, INPUT);
  digitalWrite(jigjak1_vcc,LOW); 
  digitalWrite(jigjak1_gnd,LOW);
  digitalWrite(jigjak2_vcc,LOW); 
  digitalWrite(jigjak2_gnd,LOW);
  digitalWrite(jigjak3_vcc,LOW); 
  digitalWrite(jigjak3_gnd,LOW);
  digitalWrite(jigjak4_vcc,LOW); 
  digitalWrite(jigjak4_gnd,LOW);
  digitalWrite(jigjak5_vcc,LOW); 
  digitalWrite(jigjak5_gnd,LOW);
  digitalWrite(jigjak6_vcc,LOW); 
  digitalWrite(jigjak6_gnd,LOW);
}
void Robot_Forward()
{
   ledcWrite(0, 127);
   ledcWrite(1, 0);
   ledcWrite(2, 127);
   ledcWrite(3, 0);
   ledcWrite(4, 127);
   ledcWrite(5, 0);
   t=2;
   if(h>0)
   {
    ledcWrite(6, 0);
   ledcWrite(7, 127);
   delay(200);  
   ledcWrite(6, 0);
   ledcWrite(7, 0);
   h=0;
   }
   delay(100);
   digitalWrite(jigjak1_vcc,HIGH);
   digitalWrite(jigjak1_gnd,LOW); 
   digitalWrite(jigjak2_vcc,HIGH);
   digitalWrite(jigjak2_gnd,LOW); 
   digitalWrite(jigjak3_vcc,HIGH);
   digitalWrite(jigjak3_gnd,LOW); 
   digitalWrite(jigjak4_vcc,HIGH);
   digitalWrite(jigjak4_gnd,LOW); 
   digitalWrite(jigjak5_vcc,HIGH);
   digitalWrite(jigjak5_gnd,LOW); 
   digitalWrite(jigjak6_vcc,HIGH);
   digitalWrite(jigjak6_gnd,LOW); 
   delay(70);
   digitalWrite(jigjak1_vcc,LOW);
   digitalWrite(jigjak2_vcc,LOW);
   digitalWrite(jigjak3_vcc,LOW);
   digitalWrite(jigjak4_vcc,LOW);
   digitalWrite(jigjak5_vcc,LOW);
   digitalWrite(jigjak6_vcc,LOW); 
   delay(3000);
   digitalWrite(jigjak1_vcc,LOW);
   digitalWrite(jigjak1_gnd,HIGH); 
   digitalWrite(jigjak2_vcc,LOW);
   digitalWrite(jigjak2_gnd,HIGH); 
   digitalWrite(jigjak3_vcc,LOW);
   digitalWrite(jigjak3_gnd,HIGH); 
   digitalWrite(jigjak4_vcc,LOW);
   digitalWrite(jigjak4_gnd,HIGH); 
   digitalWrite(jigjak5_vcc,LOW);
   digitalWrite(jigjak5_gnd,HIGH); 
   digitalWrite(jigjak6_vcc,LOW);
   digitalWrite(jigjak6_gnd,HIGH); 
   delay(50);
   digitalWrite(jigjak1_gnd,LOW);
   digitalWrite(jigjak2_gnd,LOW);
   digitalWrite(jigjak3_gnd,LOW);
   digitalWrite(jigjak4_gnd,LOW);
   digitalWrite(jigjak5_gnd,LOW);
   digitalWrite(jigjak6_gnd,LOW);
}
void head_lift()
{
   ledcWrite(6, 127);
   ledcWrite(7, 0);
   ledcWrite(0, 127);
   delay(100);
   ledcWrite(1, 0);
   ledcWrite(2, 127);
   ledcWrite(3, 0);
   ledcWrite(4, 127);
   ledcWrite(5, 0);
   delay(300);  
   ledcWrite(6, 0);
   ledcWrite(7, 0);
   delay(2000);
   h=2;
}
void Robot_Left()
{
   ledcWrite(0, 127);
   ledcWrite(1, 0);
   ledcWrite(2, 0);
   ledcWrite(3, 127);
   ledcWrite(4, 160);
   ledcWrite(5, 0);   
}
void Robot_Right()
{
   ledcWrite(0, 127);
   ledcWrite(1, 0);
   ledcWrite(2, 160);
   ledcWrite(3, 0);
   ledcWrite(4, 0);
   ledcWrite(5, 127);    
}
void Robot_Stop()
{
   ledcWrite(0, 0);
   ledcWrite(1, 0);
   ledcWrite(2, 0);
   ledcWrite(3, 0);
   ledcWrite(4, 0);
   ledcWrite(5, 0);      
}
BLYNK_WRITE(V1)
{   
  int value = param.asInt(); // Get value as integer
  Serial.println("Forward");
  if(value)
  {
    Robot_Forward();

  }
}

BLYNK_WRITE(V4)
{   
  int value = param.asInt(); // Get value as integer
  Serial.println("Moving Right");
  if(value)
  {
    Robot_Right();
    delay(200);
    //Robot_Stop();
  }
}


BLYNK_WRITE(V2)
{   
  int value = param.asInt(); // Get value as integer
 Serial.println("HEAD LIFT");
  if(value)
  {
    head_lift();

  }
}


BLYNK_WRITE(V3)
{   
  int value = param.asInt(); // Get value as integer
  Serial.println("Taking Left");
  if(value)
  {
    Robot_Left();
    delay(200);
    //Robot_Stop();

  }
}
BLYNK_WRITE(V5)
{   
  int value = param.asInt(); // Get value as integer
 Serial.println("STOP..");
  if(value)
  {
    Robot_Stop();
    t=0;
  }
}
