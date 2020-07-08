
#define ENCODER_PIN_1 2
#define ENCODER_PIN_2 3
#define BUTTON_PIN_1 4



/**
* Function to call when rise edge detected on pin 2
*
*
*/
void interruptOnPin1(){
  int pin1status = digitalRead(ENCODER_PIN_1);
  int pin2Status = digitalRead(ENCODER_PIN_2);

  
}
/**
*Function to call when rise edge detected on pin 2
*
*/
void interruptOnPin2(){
  int pin1status = digitalRead(ENCODER_PIN_1);
  int pin2Status = digitalRead(ENCODER_PIN_2);

  
}

/**
* Set up all encoders and button pins
* Start Serial with 9600 baud rate
* 
*/
void setup() {
  pinMode(ENCODER_PIN_1, INPUT_PULLUP);
  pinMode(ENCODER_PIN_2, INPUT_PULLUP);
  pinMode(BUTTON_PIN_1, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {

    int val = digitalRead(ENCODER_PIN_1);
    Serial.println(val);

}
