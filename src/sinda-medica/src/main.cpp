#define ENCODER_PIN_1 2
#define ENCODER_PIN_2 3
#define BUTTON_PIN 4

#include <Arduino.h>
#include <ArduinoJson.h>

long int encoderCounter = 0;
/**
 * Function to be called wnen interrupt on pin 1 was detected
 * Increase or decreasse encoder count based on pins   values
 * @param - none
 * @return - none
 */
void risingEdgeOnPin1(){
  int pin_2_value = digitalRead(ENCODER_PIN_2);
    if(pin_2_value){
      //pin 2 ==1
      encoderCounter ++;
    }else{
      //pin 2 ==0
      encoderCounter --;
    } 
}

/**
 * Function to be called wnen interrupt on pin 2 was detected
 * Increase or decreasse encoder count based on pins   values
 * @param - none
 * @return - none
 * 
 */
void risingEdgeOnPin2(){
  int pin_2_value = digitalRead(ENCODER_PIN_2);
    if(pin_2_value){
      //pin 2 ==1
      encoderCounter --;
    }else{
      //pin 2 ==0
      encoderCounter ++;
    }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(ENCODER_PIN_1, INPUT);
  pinMode(ENCODER_PIN_2, INPUT);
  pinMode(BUTTON_PIN, INPUT);

  attachInterrupt(digitalPinToInterrupt(ENCODER_PIN_1), risingEdgeOnPin1, RISING);
  attachInterrupt(digitalPinToInterrupt(ENCODER_PIN_2), risingEdgeOnPin2, RISING);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  StaticJsonDocument<100> doc;
  doc["button state"] = digitalRead(BUTTON_PIN);
  doc["encoder read"] = encoderCounter;
  serializeJson(doc, Serial);
  delay(1000);
}


