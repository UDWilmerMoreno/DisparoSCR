#include <Arduino.h>
#define dimmer 16
const byte PinDeInterrupcion = 13;
volatile int RetardoInicial;
volatile int RetardoFinal;
volatile int x = 0;
int i;

void ICACHE_RAM_ATTR CrucePorCero();

void CrucePorCero()
{
  x++;
  if (x>7200)
  {
    x=0;
  }
}

void setup()
{
  pinMode(dimmer, OUTPUT);
  pinMode(PinDeInterrupcion, INPUT);
  attachInterrupt(digitalPinToInterrupt(PinDeInterrupcion), CrucePorCero, RISING);
}

void loop()
{
  RetardoInicial = 550 + x;
  delayMicroseconds(RetardoInicial);
  digitalWrite(dimmer, HIGH);
  delayMicroseconds(10); // t2 estaba en 6
  digitalWrite(dimmer, LOW);
  RetardoFinal = 8300-(RetardoInicial+10);
  delayMicroseconds(RetardoFinal);
  /*
  for (i = 1300; i <= 7000; i++)
  {
    RetardoInicial = i;
    delay(10);
    if(i>6980){
      i=1300;
    }
  }
  */
}