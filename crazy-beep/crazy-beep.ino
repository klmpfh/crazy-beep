// define pins
const int analog_random_pin = A0;
const int beep_pin = 5;


// define livetime
// tbc // TODO


void setup() {
  // setup pins
  pinMode(analog_random_pin, INPUT);
  pinMode(beep_pin, OUTPUT);
  
  // setup random random()
  randomSeed(analogRead(analog_random_pin));

  Serial.begin(9600);

  analogWrite(beep_pin,2);
  delay(100);
  analogWrite(beep_pin,0);
  
  Serial.println("start");

  // init delay ...
  delay_minutes(10);
}

void beep_times(int times){
  for(int i = 0 ; i < times ; i++){
    beep();
    delay(200);
  }
}

void nerv(){
  beep_times(random(2,3));
}

void beep(){
  for( int i = 0 ; i < 200 ; i++){
    analogWrite(beep_pin,255);
    delayMicroseconds(222);
    analogWrite(beep_pin,0);
    delayMicroseconds(222);
  }
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
  delay_minutes(random(3,8));
  nerv();
}
