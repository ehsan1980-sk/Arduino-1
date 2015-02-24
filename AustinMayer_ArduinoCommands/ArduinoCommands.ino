/*
  Board	          int.0	  int.1	  int.2	  int.3	  int.4	  int.5
 Uno, Ethernet	  2	  3
 Mega2560	  2	  3	  21	  20	  19	  18
 Leonardo	  3	  2	  0	  1
 Due	          (any pin, more info http://arduino.cc/en/Reference/AttachInterrupt)
 
 This example, as difference to the other, make use of the new method acquireAndWait()
 */

#include <idDHT11.h>

int idDHT11pin = 2; //Digital pin for comunications
int idDHT11intNumber = 0; //interrupt number (must be the one that use the previus defined pin (see table above)
int seconds = 0;
int led = 9;
//declaration
void dht11_wrapper(); // must be declared before the lib initialization

// Lib instantiate
idDHT11 DHT11(idDHT11pin,idDHT11intNumber,dht11_wrapper);

void setup()
{
  Serial.begin(9600);
  Serial.print("LIB version: ");
  Serial.println(IDDHT11LIB_VERSION);
  Serial.println("---Input Commands---");
  pinMode(led, OUTPUT);
}
// This wrapper is in charge of calling 
// mus be defined like this for the lib work
void dht11_wrapper() {
  DHT11.isrCallback();
}
void loop()
{
  //delay(100);
  
  int result = DHT11.acquireAndWait();
  switch (result)
  {
  case IDDHTLIB_OK: 
    break;
  case IDDHTLIB_ERROR_CHECKSUM: 
    Serial.println("Error\n\r\tChecksum error"); 
    break;
  case IDDHTLIB_ERROR_ISR_TIMEOUT: 
    Serial.println("Error\n\r\tISR time out error"); 
    break;
  case IDDHTLIB_ERROR_RESPONSE_TIMEOUT: 
    Serial.println("Error\n\r\tResponse time out error"); 
    break;
  case IDDHTLIB_ERROR_DATA_TIMEOUT: 
    Serial.println("Error\n\r\tData time out error"); 
    break;
  case IDDHTLIB_ERROR_ACQUIRING: 
    Serial.println("Error\n\r\tAcquiring"); 
    break;
  case IDDHTLIB_ERROR_DELTA: 
    Serial.println("Error\n\r\tDelta time to small"); 
    break;
  case IDDHTLIB_ERROR_NOTSTARTED: 
    Serial.println("Error\n\r\tNot started"); 
    break;
  default: 
    Serial.println("Unknown error"); 
    break;
  }
  
  String input;
  
  while(Serial.available()>0){
    char command = Serial.read();
    input += command;
    if(input == "/h"){
      Serial.print("Humidity (%): ");
      Serial.println(DHT11.getHumidity(), 2);
      input = "";
    }else if(input == "/t"){
      Serial.print("Temperature (oF): ");
      Serial.println(DHT11.getFahrenheit(), 2);
      input = "";
    }else if(input == "/s"){
      Serial.print("Milliseconds: ");
      Serial.println(seconds);
      input = "";
    }else if(input == "/lon"){
      digitalWrite(led, HIGH);
      Serial.println("on");
    }
    else if (input == "/loff"){
      digitalWrite(led, LOW);
      Serial.println("off");
    }
  }  
  delay(500);
  seconds += 2000;
}

