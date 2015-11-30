
const int DATAPIN1 = 4;   // DS
const int LATCHPIN1 = 5;  // STCP
const int CLOCKPIN1 = 6;  // SHCP

int ledValue = 1;

void setup() {  
  pinMode(DATAPIN1, OUTPUT);
  pinMode(LATCHPIN1, OUTPUT);
  pinMode(CLOCKPIN1, OUTPUT);  
}

void loop() {
  
  digitalWrite(LATCHPIN1, LOW);
  
  shiftOut(DATAPIN1, CLOCKPIN1, MSBFIRST, ledValue);    
  digitalWrite(LATCHPIN1, HIGH);

  ledValue = ledValue * 2;

  if (ledValue > 128) {
    ledValue = 1;
  }

  delay(500);
}

