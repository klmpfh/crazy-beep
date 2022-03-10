// define pins
const int analog_random_pin = A0;
const int beep_pin = 5;


// define livetime
// tbc // TODO


void setup() {
  // setup pins
  pinMode(analog_random_pin, INPUT);
  pinMode(beep_pin, OUTPUT);

  Serial.begin(9600);
  

  // setup random random()
  randomSeed(analogRead(analog_random_pin));

  // delay 1 minute to flash ... u can't flash on deep sleep
  // delay(1000 * 60);

  // delay init, if u activate multiple beeps at the same time
  delay_minutes(random(0,20));
  analogWrite(beep_pin,1);
  delay(200);
  analogWrite(beep_pin,0);
  
    Serial.println("start");
}

void beep_times(int times){
  for(int i = 0 ; i < times ; i++){
    beep();
  }
}

void beep(){

  analogWrite(beep_pin,random(1,254));
  delay(random(20,250));
  analogWrite(beep_pin,0);
  delay(30);

}

void delay_minutes(int mi){
    Serial.println(mi);
  while(mi-- > 0){
    delay(60000);
    Serial.println(mi);
  }

  // delay random secound
  delay(random(0,60000));
}

void loop() {
  delay_minutes(random(1,5));
  beep_times(random(1,4));
}
