// define pins
const int analog_random_pin = A0;
const int beep_pin = 13;


// define livetime
// tbc // TODO


void setup() {
  // setup pins
  pinMode(analog_random_pin, INPUT);
  pinMode(beep_pin, OUTPUT);
  
  digitalWrite(beep_pin,LOW);

  // setup random random()
  randomSeed(analogRead(analog_random_pin));

  // delay 1 minute to flash ... u can't flash on deep sleep
  // delay(1000 * 60);
}

void beep_times(int times){
  for(int i = 0 ; i < times ; i++){
    beep();
  }
}

void beep(){

  const int us = random(110,150);
  
  for(int i = 0 ; i < 250 ; i++){
    digitalWrite(beep_pin,HIGH);
    delayMicroseconds(us);
    digitalWrite(beep_pin,LOW);
    delayMicroseconds(us);
  }

}

int minuten(int mi){
  return 1000 * 60 * mi;
}

void loop() {
  delay(random(minuten(30),minuten(50)));
  beep_times(random(1,4));
}
