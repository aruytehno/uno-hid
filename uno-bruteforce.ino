#include "TrinketHidCombo.h"
void setup(){
pinMode(4,INPUT); //USB d- (белый) PORT D4 задан в usbconfig.h
pinMode(2,INPUT);// USB d+ (зелёный) PORT D2 задан в usbconfig.h
pinMode (5,OUTPUT);  //программное включение юсб порта PORT D5  задан в usbconfig.h
TrinketHidCombo.begin(); // start the USB device engine and enumerate

pinMode(12, INPUT_PULLUP); // кнопки с подтяжкой
pinMode(11, INPUT_PULLUP);
pinMode(10, INPUT_PULLUP);
pinMode(9, INPUT_PULLUP);
pinMode(8, INPUT_PULLUP);
}

void loop(){
TrinketHidCombo.poll(); // функция должна выполняется не реже 1 раза в 10мс !!!

// пример работы мультимедиа клавиш
if (digitalRead(12) == LOW) { while (digitalRead(12) == LOW); // подождать пока кнопку отпустят
TrinketHidCombo.pressMultimediaKey(MMKEY_VOL_UP); // увеличить громкость
}

//пример эмуляции мыши
if (digitalRead(11) == LOW) { while (digitalRead(11) == LOW);// подождать пока кнопку отпустят
  TrinketHidCombo.mouseMove(5,5,0); // сдвинуть мышку вниз и вправо на 5 пикселей
  }

// пример эмуляции обычной клавиатуры -нажатие нескольких клавиш (для печати не использовать)
if (digitalRead(10) == LOW) { while (digitalRead(10) == LOW);// подождать пока кнопку отпустят
TrinketHidCombo.pressKey(0, KEYCODE_H,KEYCODE_E,KEYCODE_L,KEYCODE_O); // нажать "h+e+l+o"
TrinketHidCombo.pressKey(0, 0); // отпустить все кнопки программно
}  

// пример эмуляции обычной клавиатуры - печать одного символа
if (digitalRead(9) == LOW) { while (digitalRead(9) == LOW);// подождать пока кнопку отпустят
TrinketHidCombo.typeChar(0x41); // напечатать букву А (код клавиши в аски)
}  

// пример эмуляции обычной клавиатуры - обычная функция принт (для печати)
if (digitalRead(8) == LOW) { while (digitalRead(8) == LOW);// подождать пока кнопку отпустят
TrinketHidCombo.print("Hello, World!"); // напечатать Hello, World!
}  

// коды всех клавиш можно найти в файле  TrinketHidCombo.h
  delay(1); //паузу можно убрать
}
