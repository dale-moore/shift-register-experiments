
const int DATAPIN1 = 4;   // DS
const int LATCHPIN1 = 5;  // STCP
const int CLOCKPIN1 = 6;  // SHCP

unsigned int ledValue = 1;

void setup() {  
  pinMode(DATAPIN1, OUTPUT);
  pinMode(LATCHPIN1, OUTPUT);
  pinMode(CLOCKPIN1, OUTPUT);  
}

void loop() {
  
  // Using two shift registers and 16 LEDs, light
  // each LED individually.
  if (ledValue <= 128) {
    digitalWrite(LATCHPIN1, LOW);  
    // Push an empty byte in the first shift register
    shiftOut(DATAPIN1, CLOCKPIN1, MSBFIRST, 0);    
    // Then push the value byte into the shift register
    // which will be the display byte
    shiftOut(DATAPIN1, CLOCKPIN1, MSBFIRST, ledValue);    
    digitalWrite(LATCHPIN1, HIGH);
  }
  else {       
    // Push the value byte into the 1st shift register    
    digitalWrite(LATCHPIN1, LOW);          
    // The ledValue>>8 is a simple bit shift.  
    shiftOut(DATAPIN1, CLOCKPIN1, MSBFIRST, ledValue>>8);        
    // Push another byte into first shift register which
    // pushes the first byte into the second shift register.        
    shiftOut(DATAPIN1, CLOCKPIN1, MSBFIRST, 0);    
    digitalWrite(LATCHPIN1, HIGH);
  }
  
  ledValue = ledValue * 2;
  
  if (ledValue == 0) {
    ledValue = 1;
  }

  delay(500);
}

