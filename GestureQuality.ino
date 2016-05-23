#include "pitches.h"
int pressurePin=A0;
int pressureValue=0;
int led = 9;


bool isTimed; //Set to true when timer has begun
int timeCount; //Tick Time
int tapAmount =0;//How many times it was pressed while timed


bool isPressured = false; //If it has felt any pressure
bool isPressedHard= false; //If it was pressed hard at any time

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
// put your main code here, to run repeatedly:
pressureValue = analogRead(pressurePin);
 //Serial.println(tapAmount);
 
if(pressureValue>0)
{
  isTimed=true;
  isPressured=true;
}
Timer();

//Serial.println(pressureValue);
}

void Timer()
{
  if(isTimed)
  {
      timeCount++;
      DetectGesture();//Function tracks how many taps were made and if any were hard taps
      if(timeCount>5000)//Timer lasts for 5000 ticks
     {
      
      timeCount=0;
      //Serial.println(tapAmount);
      DetermineGesture(); //Determines what kind of Gesture was made after Timer ends
     }
  }
}


void DetectGesture()
{
  if(pressureValue>250)
  {
    isPressedHard=true;
  }
 if(isPressured)
 {
  if(pressureValue==0)
  {
    isPressured = false;
    tapAmount++;
  }
 }
}


void DetermineGesture()
{
   if(tapAmount==0 && isPressedHard == false)
  {
    //You're Touching me
    Serial.println("Touching");
    song1();
   
  }

  else if(tapAmount==0 && isPressedHard == true)
  {
    //You're Pushing me
    Serial.println("Squeezing");
    song2();
  }
  
  else if(tapAmount==1 && isPressedHard == true)
  {
    //You Poked me
    Serial.println("Poke");
    song3();
  
  }

  else if(tapAmount==1 && isPressedHard == false)
  {
    //You Tapped me
    Serial.println("Tap");
    song4();
  
  }
  
  else if(tapAmount>1 && isPressedHard == false)
  {
    //You Tickled me
    Serial.println("Tickle");
    tapAmount=0;
   song5();
  }
  
  else if(tapAmount>1, isPressedHard == true)
  {
    //You're Hitting  me
    Serial.println("Hitting");
    song6();
  
  }



  else
  {
    tapAmount=0;
   isPressedHard=false;
   isTimed= false;
    //I don't understand
  }

   tapAmount=0;
   isPressedHard=false;
   isTimed= false;
   delay(300);
}

//song1-------------------------------------------------------------------------------------
int melody1[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4,
};
int noteDurations1[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};
void song1(){
    for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations1[thisNote];
    tone(8, melody1[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
    }
}
//song2-------------------------------------------------------------------------------------
int melody2[] = {
  NOTE_C4, NOTE_F2, NOTE_B2
};
int noteDurations2[] = {
  4, 4, 4
};
void song2(){
  for (int thisNote2 = 0; thisNote2 < 3; thisNote2++){
    
    int noteDuration = 1000 / noteDurations2[thisNote2];

    tone(8, melody2[thisNote2], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
  }
}

//song3-------------------------------------------------------------------------------------
int melody3[] = {
   NOTE_C4, NOTE_G3, NOTE_G3
};
int noteDurations3[] = {
  4, 6, 8
};
void song3(){
  for (int thisNote3 = 0; thisNote3 < 3; thisNote3++){
    int noteDuration = 1000 / noteDurations3[thisNote3];

    tone(8, melody3[thisNote3], noteDuration);
   
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
  }
}
//song4-------------------------------------------------------------------------------------
int melody4[] = {
  NOTE_C7, NOTE_E7, NOTE_D7, 0, NOTE_D7, 0, NOTE_D7
};
int noteDurations4[] = {
  4, 4, 8, 4, 8, 4, 8 
};
void song4(){
   for (int thisNote4 = 0; thisNote4 < 7; thisNote4++){
    int noteDuration = 1000 / noteDurations4[thisNote4];

    tone(8, melody4[thisNote4], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
  }
}
//song5 (mario)-------------------------------------------------------------------------------------
int melody5[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0
};
int noteDurations5[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};
void song5(){
  int size = sizeof(melody5) / sizeof(int);
  for (int thisNote5 = 0; thisNote5 < size; thisNote5++){
    int noteDuration = 1000 / noteDurations5[thisNote5];

    tone(8, melody5[thisNote5], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
    }
}
//song6-------------------------------------------------------------------------------------
int melody6[] = {
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0, NOTE_DS4, NOTE_CS4, NOTE_D4,
  NOTE_CS4, NOTE_DS4,
  NOTE_DS4, NOTE_GS3,
  NOTE_G3, NOTE_CS4,
  NOTE_C4, NOTE_FS4, NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
  NOTE_GS4, NOTE_DS4, NOTE_B3,
  NOTE_AS3, NOTE_A3, NOTE_GS3,
  0, 0, 0
};
int noteDurations6[] = {
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  6, 18, 18, 18,
  6, 6,
  6, 6,
  6, 6,
  18, 18, 18, 18, 18, 18,
  10, 10, 10,
  10, 10, 10,
  3, 3, 3
};
void song6(){
  int size = sizeof(melody6) / sizeof(int);
  for (int thisNote6 = 0; thisNote6 < size; thisNote6++){
    int noteDuration = 1000 / noteDurations6[thisNote6];

    tone(8, melody6[thisNote6], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
    }
}

