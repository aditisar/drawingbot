int MB1 = 6; // motor b pin 1
int MB2 = 5; // motor b pin 2
void setup() {
  pinMode(MB1, OUTPUT);
  pinMode(MB2, OUTPUT);
}
void loop() {
  doForward(MB1, MB2); // motor B forward
  delay(200);
  doStop(MB1, MB2);
  delay(400);
  
  doBackward(MB1, MB2); //motor B backward
  delay(200);
  doStop(MB1, MB2);
  delay(400);
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
