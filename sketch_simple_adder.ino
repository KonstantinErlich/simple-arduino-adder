#define _OPEN_SYS_ITOA_EXT
#include <stdio.h>
#include <stdlib.h>

int analogPin = A5;
int buttonPin = 13;

int buttonState = 0; 
int state2 = 0;

int counter = 0;
int val = 0;
int d = 0;
int d_2 = 0;

int a = 0;
int b = 0;
int result = 0;
char res[2];

int out1 = 0;
int out2 = 0;

int state = 1;
//state 1 is first number to be added
//state 2 is the second
//state 3 is displaying result

void pins(){
  //controls LED depending on decimal value
  if (d < 5 or d > 6) {digitalWrite(6, HIGH);}
  else digitalWrite(6, LOW);

  if (d == 0 or d == 2 or d == 3 or d ==5 or d==6 or d==7 or d==8 or d==9 ) {digitalWrite(7, HIGH);}
    else digitalWrite(7, LOW);

  if (d == 0 or d == 1 or d == 3 or d ==4 or d==5 or d==6 or d==7 or d==8 or d==9 ) {digitalWrite(12, HIGH);}
    else digitalWrite(12, LOW);

  if (d == 0 or d == 2 or d == 3 or d ==5 or d==6 or d==8 or d==9 ) {digitalWrite(11, HIGH);}
    else digitalWrite(11, LOW);

  if (d == 0 or d == 2 or d==6 or d==8) {digitalWrite(10, HIGH);}
    else digitalWrite(10, LOW);
  
  if (d == 0 or d == 4 or d == 5 or d ==6 or d==8 or d==9 ) {digitalWrite(8, HIGH);}
    else digitalWrite(8, LOW);

  if (d == 2 or d == 3 or d==4 or d==5 or d==6 or d==8 or d==9 ) {digitalWrite(9, HIGH);}
    else digitalWrite(9, LOW);
}

void AllPinsLow(){
    for (int j = 12; j > 5; j--) {
    digitalWrite(j, LOW);
  }
}
void DisplayEqual() {
  AllPinsLow();
  digitalWrite(7, HIGH);
  digitalWrite(9, HIGH);

}
int ConvertToDec(int val){
  //convert pin value into a decimal from 0 to 9
  if (val < 103) { d_2 = 0;}
  if (val > 102 and val < 206) { d_2 = 1;}
  if (val > 205 and val < 308) { d_2 = 2;}
  if (val > 307 and val < 411) { d_2 = 3;}
  if (val > 410 and val < 513) { d_2 = 4;}
  if (val > 512 and val < 615) { d_2 = 5;}
  if (val > 614 and val < 718) { d_2 = 6;}
  if (val > 717 and val < 820) { d_2 = 7;}
  if (val > 819 and val < 922) { d_2 = 8;}
  if (val > 921) { d_2 = 9;}
  return d_2;
}

void CalculateResult(){
  result = a + b;
  itoa(result,res, 10);  
  out1 = res[0] - '0';
  out2 = res[1] - '0';
}

void setup() {
  Serial.begin(9600);
  for (int i = 12; i>5; i--){
    pinMode(i, OUTPUT);
  }
  pinMode(buttonPin, INPUT);
}



void loop() {
buttonState = digitalRead(buttonPin);
if (buttonState == HIGH) {
  state = state + 1;
  AllPinsLow();
  delay(200);
}
  Serial.println(state);

if (state < 3) {

  val = analogRead(analogPin); // read the input pin value
  d = ConvertToDec(val);  
  pins();
  if (state == 1) {a = d;}
  else b = d;
}

CalculateResult();

if (state ==3) {
  DisplayEqual();
  delay(500);

  if (result < 10) {
    d = out1;
    pins();
    delay(550);
  }
  else{
    d = out1;
    pins();
    delay(500);
    AllPinsLow();
    delay(70);
    d = out2;
    pins();
    delay(500);
    AllPinsLow();
    delay(70);
}
}

delay(10);
}




