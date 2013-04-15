/*
Based on SerialEvent
 */
 #define ledpin 13

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

void setup() {
  //init. de ledpin
  pinMode(ledpin, OUTPUT);
  digitalWrite(ledpin, LOW);
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
}

void loop() {
  // print the string when a newline arrives:
  if (stringComplete) {
    if (inputString == "hello\n"){
      Serial.println("hello received");
    }else if (inputString == "switchled\n"){
      boolean state = digitalRead(ledpin);
      digitalWrite(ledpin, !state);
      if(!state)
        Serial.println("on");
      else
        Serial.println("off");
    }else{
      Serial.println("Unknown command");
    }
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}

/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    } 
  }
}
