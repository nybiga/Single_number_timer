#include <Arduino.h>

// Segments and corresponding pin
int A = 3, B = 2, C = 7, D = 8, E = 9, F = 4, G = 5, DP = 6;
// Array of pins
int numberPins[] = {A, B, C, D, E, F, G, DP}; 
// Segement to light up for each number
int zero [] = {A, B, C, D, F, E},
    one[] = {B, C},
    two[] = {A, B, D, E, G},
    three[] = {A, B, C, D, G},
    four [] = {B, C, F, G},
    five[] = {A, C, D, F, G},
    six[] = {A, C, D, E, F, G},
    seven[] = {A, B, C},
    eight[] = {A, B, C, D, E, F, G},
    nine[] = {A, B, C, D, F, G},
    dp[] = {DP};

int pos;
String order = "ascending";

void reset();
void changeOrder();

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 8; i++){
    pinMode(numberPins[i], OUTPUT);
  }
  
  reset();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (order == "ascending") pos++;
  else pos--;

  int* number; // Pointer to array
  int size; // Size of array

  switch (pos){
    case 0:
      number = zero;
      size = sizeof(zero);
      break;
    case 1:
      number = one;
      size = sizeof(one);
      break;
    case 2:
      number = two;
      size = sizeof(two);
      break;
    case 3:
      number = three;
      size = sizeof(three);
      break;
    case 4:
      number = four;
      size = sizeof(four);
      break;
    case 5:
      number = five;
      size = sizeof(five);
      break;
    case 6:
      number = six;
      size = sizeof(six);
      break;
    case 7:
      number = seven;
      size = sizeof(seven);
      break;
    case 8:
      number = eight;
      size = sizeof(eight);
      break;
    case 9:
      number = nine;
      size = sizeof(nine);
      break;
    default:
      number = dp;
      size = sizeof(dp);
      break;
  }

  size = size / sizeof(int);

  // Light up segments
  for (int i = 0; i < size; i++){
    digitalWrite(number[i], HIGH);
  }

  delay(1000);

  // Turns off segments
  for (int i = 0; i < size; i++){
    digitalWrite(number[i], LOW);
  }

  // Changes counting order after limit has been reached
  if (pos > 9 || pos < 0) {
    changeOrder();
    reset(); 
  }
}

void reset(){
  if (order == "ascending") pos = -1;
  else pos = 10;
}

void changeOrder(){
  if (order == "ascending") order = "descending";
  else order = "ascending";
}