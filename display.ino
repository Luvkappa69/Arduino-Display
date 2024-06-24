/*
display - arduino
1 - saida potenciometro
2 - 5v
3 - meio potenciometro
4 - pino 12
5 - gnd
6 - pino 11 PWM
7 
8
9
10
11 - 5 PWM
12 - 4
13 - 3 PWM
14 - 2
15 - resistencia to 5v
16 - gnd
entrada do potenciometro 5v
*/

#include <LiquidCrystal.h>
LiquidCrystal lcd1 (12,11,5,4,3,2); //pinos de ligacao do display no arduino

int segundos=0;
int minutos=0;
int horas=0;

void setup() {
  lcd1.begin(16,2);   //numero de colunas , numero de linhas do dispositivo
              //0 0 : 0 0 : 0 0
              //0 1 2 3 4 5 6 7
  lcd1.setCursor(5, 0);  //posicionamento proxima mensagem :set coluna (0,1,2,...), set linha (0,1,...) BINARIO
  lcd1.print("Relogio");

}

void loop() {
   

  lcd1.setCursor(5,1);
  if(horas<10){
    lcd1.print("0");
    lcd1.print(horas);
  }
  else{
    lcd1.print(horas);
  }
  
  lcd1.setCursor(7,1);
  lcd1.print(":");

  lcd1.setCursor(8,1);
  if(minutos<10){  
    lcd1.print("0");
    lcd1.print(minutos);
  }
  else{
    lcd1.print(minutos);
  }

  lcd1.setCursor(10,1);
  lcd1.print(":");

  lcd1.setCursor(11, 1);
  if(segundos<10){  
    lcd1.print("0");
    lcd1.print(segundos);
  }
  else{
    lcd1.print(segundos);
  }
  
  segundos++;
  delay(1000);
  //lcd1.clear();

  if (segundos==60){
    segundos =0;
    minutos++;
  }
  if(minutos==60){
    minutos=0;
    horas++;
  }
  if(horas==24){
    horas=0;
  }

}




