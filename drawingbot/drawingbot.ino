int MB1 = 6; // motor b pin 1
int MB2 = 5; // motor b pin 2
int sensor1 = 2;  // change "0" to whatever pin to which you are hooking the sensor. Just this one change allows you to test operation on other pins.
int reflectance;
void setup() {
  pinMode(MB1, OUTPUT);
  pinMode(MB2, OUTPUT);
}
void loop() {
    reflectance = 1;                   //initialize value to 1 at the beginning of each loop
  pinMode(sensor1, OUTPUT);   //set pin as output
  digitalWrite(sensor1, HIGH);  //set pin HIGH (5V)
  delayMicroseconds(15);        //charge capacitor for 15 microseconds
   
  pinMode(sensor1, INPUT);                                          //set pin as input
     while((reflectance < 900) && (digitalRead(sensor1) != LOW)){   //timeout at 500
                                                                    // read the pin state, increment counter until state = LOW
          ++ reflectance;                                           // increment value to be displayed via serial port
            //  delayMicroseconds(4);                                 //Change value or comment out to adjust value range
      }
  
  if (reflectance < 500){
      Serial.println(reflectance);}   //Send reflectance value to serial display
      else {
        Serial.println("T.O.");       //if reflectance value is over 500 then it's a "timeout"
      }
       
  delay(0);
  Serial.begin(9600);
  doForward(MB1, MB2); // motor B forward
  delay(0);
  doStop(MB1, MB2);
  delay(0);
  
  if (reflectance > 200) {
  doBackward(MB1, MB2); //motor B backward
  delay(10);
  doStop(MB1, MB2);
  delay(0);
  
  }
}
void doForward(int pin1, int pin2) {
  digitalWrite(pin2, LOW);
  digitalWrite(pin1, HIGH);  
}
void doStop(int pin1, int pin2) {
  digitalWrite(pin2, LOW);
  digitalWrite(pin1, LOW);  
}
void doBackward(int pin1, int pin2) {
  digitalWrite(pin2, HIGH);
  digitalWrite(pin1, LOW);  
}
