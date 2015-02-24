void setup(){
  pinMode(A0,INPUT);
  pinMode(10,OUTPUT);
  Serial.begin(57600);
}

void loop(){
  int val = analogRead(A0);
  int mappedVal = map(val,0,1023,0,100);
  Serial.print("A0 = ");
  Serial.println(mappedVal);
  analogWrite(10,mappedVal);
  delay(100);
}                                                                    
