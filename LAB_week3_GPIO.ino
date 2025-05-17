
// Pin configuration for each segment: A B C D E F G
const int segmentPins[7] = {2, 3, 4, 5, 6, 7, 8};

// Digit patterns for 0–9 (segments A-G, 0 = on, 1 = off for common cathode)
const byte digits[10][7] = {
  { 1, 1, 1, 1, 1, 1, 0 },  // 0
  { 0, 1, 1, 0, 0, 0, 0 },  // 1
  { 1, 1, 0, 1, 1, 0, 1 },  // 2
  { 1, 1, 1, 1, 0, 0, 1 },  // 3
  { 0, 1, 1, 0, 0, 1, 1 },  // 4
  { 1, 0, 1, 1, 0, 1, 1 },  // 5
  { 1, 0, 1, 1, 1, 1, 1 },  // 6
  { 1, 1, 1, 0, 0, 0, 0 },  // 7
  { 1, 1, 1, 1, 1, 1, 1 },  // 8
  { 1, 1, 1, 1, 0, 1, 1 }   // 9
};

const int buttonPin = 9;
int currentNumber = 0;
bool lastButtonState = HIGH;

unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
  pinMode(buttonPin, INPUT_PULLUP);
  
  //*for test*
  Serial.println("Start");
  
  displayDigit(currentNumber);
  
  //*for test*
  Serial.println("reading Setup");
  //Serial.println(currentNumber);
  
}

void loop() {
  
  //*for test*
  //Serial.println("reading loop");
  
  bool reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis(); 
    
            /////////////////////////////////////////// 
    if(lastButtonState == HIGH){
    currentNumber = currentNumber + 1;
    displayDigit(currentNumber);
    
    //*for test*
    Serial.println(currentNumber);
    
  }else {
    }
          ///////////////////////////////////////////
    
  }
  
  //*for test*
     //Serial.println(millis());
     //Serial.println(lastDebounceTime);
     //Serial.println(millis() - lastDebounceTime);
  
  /*
  //if ((millis() - lastDebounceTime) > debounceDelay && reading == LOW && lastButtonState == HIGH) {
  if(lastButtonState == HIGH){
    currentNumber = currentNumber + 1;
    displayDigit(currentNumber);
    
    //*for test
    Serial.println(currentNumber);
    
  }
 */
  
  lastButtonState = reading;
  
  //*for test*
  //Serial.println(currentNumber);
  
}

void displayDigit(int num) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], digits[num][i]);
    
    //*for test*
    //Serial.println("currentNumber num");
    
  }
}



/////////////////////////////////////////////////////////////////////////////////////////////

/*
// Pin configuration for each segment: A B C D E F G
const int segmentPins[7] = {2, 3, 4, 5, 6, 7, 8};

// Digit patterns for 0–9 (segments A-G, 0 = on, 1 = off for common cathode)
const byte digits[10][7] = {
  { 1, 1, 1, 1, 1, 1, 0 },  // 0
  { 0, 1, 1, 0, 0, 0, 0 },  // 1
  { 1, 1, 0, 1, 1, 0, 1 },  // 2
  { 1, 1, 1, 1, 0, 0, 1 },  // 3
  { 0, 1, 1, 0, 0, 1, 1 },  // 4
  { 1, 0, 1, 1, 0, 1, 1 },  // 5
  { 1, 0, 1, 1, 1, 1, 1 },  // 6
  { 1, 1, 1, 0, 0, 0, 0 },  // 7
  { 1, 1, 1, 1, 1, 1, 1 },  // 8
  { 1, 1, 1, 1, 0, 1, 1 }   // 9
};

const int buttonPin = 9;
int currentNumber = 0;
bool lastButtonState = HIGH;

unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
  pinMode(buttonPin, INPUT_PULLUP);
  displayDigit(currentNumber);
}

void loop() {
  bool reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay && reading == LOW && lastButtonState == HIGH) {
    currentNumber = (currentNumber + 1) % 10;
    //currentNumber = (currentNumber + 1);
    displayDigit(currentNumber);
  }

  lastButtonState = reading;
}

void displayDigit(int num) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], digits[num][i]);
  }
}

*/

///////////////////////////////////////////////////////////////////////////////////////////////

/*
int Value = 0;
const byte PIN[7] = {2,3,4,5,6,7,8}; 

int bits[10][7] = {{ 1, 1, 1, 1, 1, 1, 0 },  // 0
  { 0, 1, 1, 0, 0, 0, 0 },  // 1
  { 1, 1, 0, 1, 1, 0, 1 },  // 2
  { 1, 1, 1, 1, 0, 0, 1 },  // 3
  { 0, 1, 1, 0, 0, 1, 1 },  // 4
  { 1, 0, 1, 1, 0, 1, 1 },  // 5
  { 1, 0, 1, 1, 1, 1, 1 },  // 6
  { 1, 1, 1, 0, 0, 0, 0 },  // 7
  { 1, 1, 1, 1, 1, 1, 1 },  // 8
  { 1, 1, 1, 1, 0, 1, 1 }  // 9
};
void setup(){
  for (int i=0; i<7; i++) {
    pinMode (PIN[i], OUTPUT);
  }
}

void loop(){
  Value = analogRead(A0);
  for (int i=0; i<7; i++) {
    digitalWrite(PIN[i] , LOW);
  }
  int scale = map(Value, 0, 1020, 0, 8); // map function to get brihtness
    
  for (int j = 0; j < 7; j++) {
    digitalWrite(j+2, bits[scale][j]);
  }
  
  delay(100); // Wait for 100 millisecond(s)
}
*/