
#include <AFMotor.h>
 
AF_DCMotor motor1(1);
AF_DCMotor motor2(2); 
 
void setup() {
  Serial.begin(57600);           
  Serial.println("Motor test!");
   
}
 
void loop() {
  Serial.print("tick");
  
  motor1.setSpeed(255);  
  motor2.setSpeed(255);
  
  motor1.run(FORWARD);    
  motor2.run(FORWARD);    
  delay(10000);
 
  Serial.print("tock");
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  delay(1000);
  
  Serial.print("tack");
  motor1.run(RELEASE);  
  motor2.run(RELEASE);
  delay(1000);
}
