#include <Servo.h>
#include <Wire.h> // Must include Wire library for I2C
#include <SparkFun_MMA8452Q.h> // Includes the SFE_MMA8452Q library
MMA8452Q accel;
Servo cintura,hombro;
float angcint=90;
float anghomb=0;
void setup()
{
  cintura.attach(9);
  hombro.attach(11);
  Serial.begin(9600);
  Serial.println("MMA8452Q Test Code!");
  accel.init();
}
void loop()
{
  if (accel.available())
  {
    accel.read();
    printOrientation();
    
  }
  hombro.write(anghomb);
  cintura.write(angcint);
   Serial.print(anghomb);
   Serial.print(angcint);
       Serial.println(); // Print new line every time.
   if(anghomb==180){
      anghomb=179;
    }
    if(anghomb==0){
      anghomb=1;
    }
    if(angcint==0){
      angcint=1;
    }
    if(angcint==180){
      angcint=179;
    }
}

void printOrientation()
{
  byte pl = accel.readPL();
  switch (pl)
  {
  case PORTRAIT_U:
    if(anghomb<180&&anghomb>0){
      anghomb=anghomb+1;
    }
    Serial.print("Landscape Up");
    break;
    
    
  case PORTRAIT_D:
    if(anghomb<180&&anghomb>0){
      anghomb=anghomb-1;
    }
    Serial.print("Landscape Down");
    break;
  case LANDSCAPE_R:
  if(angcint<180&&angcint>0){
      angcint=angcint+1;
    }
    Serial.print("Landscape Right");
    break;
  case LANDSCAPE_L:
  if(angcint<180&&angcint>0){
      angcint=angcint-1;
    }
    Serial.print("Landscape Left");
    break;
  case LOCKOUT:
    Serial.print("Flat");
    break;
  }
}
