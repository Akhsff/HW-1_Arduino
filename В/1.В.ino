#include "RotaryEncoder.h"          // библиотека для энкодера
RotaryEncoder encoder(A2, A3);  // пины подключение энкодера (DT, CLK)

// задаем шаг энкодера и макс./мин. значение
#define STEPS  5
#define POSMIN 0
#define POSMAX 255

int lastPos, newPos;

void setup() {
   pinMode(9, OUTPUT);      
   Serial.begin(9600);
   encoder.setPosition(10 / STEPS);
}

void loop() {
   // проверяем положение ручки энкодера
   encoder.tick();
   newPos = encoder.getPosition() * STEPS;

   if (newPos < POSMIN) { 
   encoder.setPosition(POSMIN / STEPS); 
   newPos = POSMIN;
   }
   else if (newPos > POSMAX) { 
   encoder.setPosition(POSMAX / STEPS); 
   newPos = POSMAX; 
   }
   // если положение изменилось - выводим на монитор
   if (lastPos != newPos) {
      Serial.println(newPos);
      lastPos = newPos;
   }

   // включаем светодиод с установленной яркостью
   analogWrite(9, lastPos);}