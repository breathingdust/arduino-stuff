//www.elegoo.com
//2016.12.09

// Arduino pin numbers
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output
const int blue_pin = 5;
const int green_pin = 3;
const int yellow_pin = 9;
const int red_pin = 10;
const int middle = 508;
const float incval = 0.50;

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
}

void loop() {
  float redValue =  (middle - analogRead(Y_pin)) * incval;
  float blueValue = (analogRead(Y_pin) - middle) * incval;
  float yellowValue = (middle - analogRead(X_pin)) * incval;
  float greenValue = (analogRead(X_pin) - middle) * incval;

  
  analogWrite(red_pin,truncate(redValue));
  analogWrite(yellow_pin,truncate(yellowValue));
  analogWrite(blue_pin,truncate(blueValue));
  analogWrite(green_pin,truncate(greenValue));

}

int truncate(int value) {
  if (value < 5){
    return 0;
  } else if (value > 255) {
    return 255;
  } else {
    return value;
  }
}
