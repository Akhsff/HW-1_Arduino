volatile boolean intFlag = false;
volatile boolean previntFlag = true;

void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(0, buttonTick, FALLING);
  digitalWrite(8, HIGH);
}

void buttonTick(){
  intFlag = true;
}

void loop() {
  if (intFlag){
    intFlag = false;
    if (previntFlag){
      digitalWrite(8, LOW);
      Serial.println("LED: off");
    }
    else {
      digitalWrite(8, HIGH);
      Serial.println("LED: on");
    }
    previntFlag = !previntFlag;
  }
}
