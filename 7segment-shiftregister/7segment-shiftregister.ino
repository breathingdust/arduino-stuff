
#include <arduino-timer.h>

const int latchPin = 8;
const int clockPin = 12;
const int dataPin = 11;
const int dotPin = 6;
int count = 0;

auto timer = timer_create_default(); // create a timer with default settings

bool timer_tick(void *) {
  count++;  
    Serial.println("tick");
  return true; // keep timer active? true
}

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dotPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("reset");
  timer.every(1000, timer_tick);
}

  //registerWrite(7, HIGH);
  //  registerWrite(1, HIGH); top left
  //  registerWrite(2, HIGH); top
  //  registerWrite(3, HIGH); top right
  //  registerWrite(4, HIGH); bottom left
  //  registerWrite(5, HIGH); bottom
  //  registerWrite(6, HIGH); bottom right
  //  registerWrite(7, HIGH); dot
  //  digitalWrite(6, HIGH); middle

void zero(){
    registerWrite(1, HIGH); 
    registerWrite(2, HIGH); 
    registerWrite(3, HIGH); 
    registerWrite(4, HIGH); 
    registerWrite(5, HIGH); 
    registerWrite(6, HIGH);
    registerWrite(7, LOW);
    digitalWrite(6, LOW);
}

void one(){
  registerWrite(1, LOW); 
  registerWrite(2, LOW); 
  registerWrite(3, HIGH); 
  registerWrite(4, LOW); 
  registerWrite(5, LOW); 
  registerWrite(6, HIGH);
  registerWrite(7, LOW);
  digitalWrite(6, LOW);
}

void two(){
  registerWrite(1, LOW); 
  registerWrite(2, HIGH); 
  registerWrite(3, HIGH); 
  registerWrite(4, HIGH); 
  registerWrite(5, HIGH); 
  registerWrite(6, LOW);
  registerWrite(7, LOW);
  digitalWrite(6, HIGH);
}

void three(){
  registerWrite(1, LOW); 
  registerWrite(2, HIGH); 
  registerWrite(3, HIGH); 
  registerWrite(4, LOW); 
  registerWrite(5, HIGH); 
  registerWrite(6, HIGH);
  registerWrite(7, LOW);
  digitalWrite(6, HIGH);
}

void four(){
  registerWrite(1, HIGH); 
  registerWrite(2, LOW); 
  registerWrite(3, HIGH); 
  registerWrite(4, LOW); 
  registerWrite(5, LOW); 
  registerWrite(6, HIGH);
  registerWrite(7, LOW);
  digitalWrite(6, HIGH);
}

void five(){
  registerWrite(1, HIGH); 
  registerWrite(2, HIGH); 
  registerWrite(3, LOW); 
  registerWrite(4, LOW); 
  registerWrite(5, HIGH); 
  registerWrite(6, HIGH);
  registerWrite(7, LOW);
  digitalWrite(6, HIGH);
}

void six(){
  registerWrite(1, HIGH); 
  registerWrite(2, HIGH); 
  registerWrite(3, LOW); 
  registerWrite(4, HIGH); 
  registerWrite(5, HIGH); 
  registerWrite(6, HIGH);
  registerWrite(7, LOW);
  digitalWrite(6, HIGH);
}

void seven(){
  registerWrite(1, LOW); 
  registerWrite(2, HIGH); 
  registerWrite(3, HIGH); 
  registerWrite(4, LOW); 
  registerWrite(5, LOW); 
  registerWrite(6, HIGH);
  registerWrite(7, LOW);
  digitalWrite(6, LOW);
}

void eight(){
  registerWrite(1, HIGH); 
  registerWrite(2, HIGH); 
  registerWrite(3, HIGH); 
  registerWrite(4, HIGH); 
  registerWrite(5, HIGH); 
  registerWrite(6, HIGH);
  registerWrite(7, LOW);
  digitalWrite(6, HIGH);
}

void nine(){
  registerWrite(1, HIGH); 
  registerWrite(2, HIGH); 
  registerWrite(3, HIGH); 
  registerWrite(4, LOW); 
  registerWrite(5, LOW); 
  registerWrite(6, HIGH);
  registerWrite(7, LOW);
  digitalWrite(6, HIGH);
}

void loop() {
  timer.tick(); // tick the timer
  switch (count) {
    case 0:
      zero();
      break;
    case 1:
      one();
      break;
    case 2:
      two();
      break;
    case 3:
      three();
      break;
    case 4:
      four();
      break;
    case 5:
      five();
      break;
    case 6:
      six();
      break;
    case 7:
      seven();
      break;
    case 8:
      eight();
      break;
    case 9:
      nine();
      break;
    default:
      count = 0;
      break;
  }

}
// This method sends bits to the shift register:
void registerWrite(int whichPin, int whichState) {
  // the bits you want to send
  byte bitsToSend = 0;
  // turn off the output so the pins don't light up
  // while you're shifting bits:
  digitalWrite(latchPin, LOW);
  // turn on the next highest bit in bitsToSend:
  bitWrite(bitsToSend, whichPin, whichState);
  // shift the bits out:
  shiftOut(dataPin, clockPin, MSBFIRST, bitsToSend);
  // turn on the output so the LEDs can light up:
  digitalWrite(latchPin, HIGH);
}
