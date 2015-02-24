#include "pitches.h"
#define NO_SOUND 0

void setup() {
  pinMode(A0,INPUT);
  pinMode(11, OUTPUT);
  Serial.begin(57600);
}

void loop() {
  song();
}

void song(){
  int melody[] = {
    NOTE_D5,NOTE_F5,NOTE_D6,NO_SOUND,
    NOTE_D5,NOTE_F5,NOTE_D6,NO_SOUND,
    NOTE_E6,NOTE_F6,NOTE_E6,NOTE_F6,NOTE_E6,NOTE_C6,NOTE_A5,NO_SOUND,
    NOTE_A5,NOTE_D5,NOTE_F5,NOTE_G5,NOTE_A5,NO_SOUND,
    NOTE_A5,NOTE_D5,NOTE_F5,NOTE_G5,NOTE_E5,NO_SOUND,
    NOTE_D5,NOTE_F5,NOTE_D6,NO_SOUND,
    NOTE_D5,NOTE_F5,NOTE_D6,NO_SOUND,
    NOTE_E6,NOTE_F6,NOTE_E6,NOTE_F6,NOTE_E6,NOTE_C6,NOTE_A5,NO_SOUND,
    NOTE_A5,NOTE_D5,NOTE_F5,NOTE_G5,NOTE_A5,NO_SOUND,
    NOTE_A5,NOTE_D5,NOTE_F5,NOTE_G5,NOTE_E5,NO_SOUND,
  }
  
  int noteDurations[] = {
    8,8,4,8,
    8,8,4,8,
    4,8,8,8,8,8,8,8,
    4,4,8,8,8,4,
    4,4,8,8,8,4,
    8,8,4,8,
    8,8,4,8,
    4,8,8,8,8,8,8,8,
    4,4,8,8,8,4,
    4,4,8,8,8,1
  }
  
  for (int Note = 0; Note <56; Note++) {
    int val = analogRead(A0);
    int mappedVal = map(val,0,1023,500,2000);
    Serial.println(mappedVal);
    
    int duration = mappedVal/noteDurations[Note];
    tone(11, melody[Note],duration);

    delay(duration*1.2);
  }
  
}

/* I created this code by looking at two seperate examples on the internet and simplifying 
 it to my own code as well as implemented the analog speed. I mainly used the notes and 
 figured out the rests for each. Below i will provide and example of both of
 the codes I used as an example. -Austin */

 
 //Example 1
 
/*
#include "pitches.h"
#define NO_SOUND 0 // make the rests in music

int ledPin = 13; //For visual as well
int speakerPin = 11; //Speaker or Piezo buzzer on pin 11

void setup()    
{
  pinMode(ledPin, OUTPUT); // Setting both pins to outputs
  pinMode(speakerPin, OUTPUT);  
}        

void loop()
{
  song();
}        

void beep (unsigned char speakerPin, int frequencyInHertz, long timeInMilliseconds)  //code for working out the rate at which each note plays and the frequency.
{
  digitalWrite(ledPin, HIGH);
  int x;      
  long delayAmount = (long)(1000000/frequencyInHertz);
  long loopTime = (long)((timeInMilliseconds*1000)/(delayAmount*2));
  for (x=0;x<loopTime;x++)    
  {    
    digitalWrite(speakerPin,HIGH);
    delayMicroseconds(delayAmount);
    digitalWrite(speakerPin,LOW);
    delayMicroseconds(delayAmount);
  }    
  digitalWrite(ledPin, LOW);
  delay(20);
}        

void song()  //here is where all the notes for the song are played.
{        
  beep(speakerPin, NOTE_D5, 100);  //   beep( -PIN OF SPEAKER-, -THE NOTE WANTING TO BE PLAYED-, -DURATION OF THE NOTE IN MILISECONDS- )
  delay(80);
  beep(speakerPin, NOTE_F5, 100); 
  delay(80);
  beep(speakerPin, NOTE_D6, 200); 
  delay(250);
  
  beep(speakerPin, NOTE_D5, 100); 
  delay(80);
  beep(speakerPin, NOTE_F5, 100); 
  delay(80);
  beep(speakerPin, NOTE_D6, 200);
  delay(250);
  
  beep(speakerPin, NOTE_E6, 200); 
  delay(200);
  beep(speakerPin, NOTE_F6, 100); 
  delay(100);
  beep(speakerPin, NOTE_E6, 100); 
  delay(80);
  beep(speakerPin, NOTE_F6, 100); 
  delay(80);
  beep(speakerPin, NOTE_E6, 100); 
  delay(80);
  beep(speakerPin, NOTE_C6, 100); 
  delay(80);
  beep(speakerPin, NOTE_A5, 100); 
  delay(300);
  
  beep(speakerPin, NOTE_A5, 200); 
  delay(100);
  beep(speakerPin, NOTE_D5, 200); 
  delay(100);
  beep(speakerPin, NOTE_F5, 100); 
  delay(100);
  beep(speakerPin, NOTE_G5, 100); 
  delay(100);
  beep(speakerPin, NOTE_A5, 100); 
  delay(500);
  
  beep(speakerPin, NOTE_A5, 200); 
  delay(100);
  beep(speakerPin, NOTE_D5, 200); 
  delay(100);
  beep(speakerPin, NOTE_F5, 100); 
  delay(100);
  beep(speakerPin, NOTE_G5, 100); 
  delay(100);
  beep(speakerPin, NOTE_E5, 100); 
  delay(500);
  
  
  
  beep(speakerPin, NOTE_D5, 100); 
  delay(80);
  beep(speakerPin, NOTE_F5, 100); 
  delay(80);
  beep(speakerPin, NOTE_D6, 200); 
  delay(250);
  
  beep(speakerPin, NOTE_D5, 100); 
  delay(80);
  beep(speakerPin, NOTE_F5, 100); 
  delay(80);
  beep(speakerPin, NOTE_D6, 200);
  delay(250);
  
  beep(speakerPin, NOTE_E6, 200); 
  delay(200);
  beep(speakerPin, NOTE_F6, 100); 
  delay(100);
  beep(speakerPin, NOTE_E6, 100); 
  delay(80);
  beep(speakerPin, NOTE_F6, 100); 
  delay(80);
  beep(speakerPin, NOTE_E6, 100); 
  delay(80);
  beep(speakerPin, NOTE_C6, 100); 
  delay(80);
  beep(speakerPin, NOTE_A5, 100); 
  delay(300);
  
  beep(speakerPin, NOTE_A5, 200); 
  delay(100);
  beep(speakerPin, NOTE_D5, 200); 
  delay(100);
  beep(speakerPin, NOTE_F5, 100); 
  delay(100);
  beep(speakerPin, NOTE_G5, 100); 
  delay(100);
  beep(speakerPin, NOTE_A5, 300);
  delay(100);
  beep(speakerPin, NOTE_A5, 200);
  delay(100);
  beep(speakerPin, NOTE_D5, 300);
  delay(2000);
  
}

*/




// Example 2





/*
/*
  Melody
 
 Plays a melody 
 
 circuit:
 * 8-ohm speaker on digital pin 8
 
 created 21 Jan 2010
 modified 30 Aug 2011
 by Tom Igoe 

This example code is in the public domain.
 
 http://arduino.cc/en/Tutorial/Tone
 
 
 #include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4,4,4,4,4 };

void setup() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[thisNote];
    tone(8, melody[thisNote],noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}

void loop() {
  // no need to repeat the melody.
}
*/
