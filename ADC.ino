#include<avr/io.h>
#include<util/delay.h>
void init()
{
  Serial.begin(2000000);
  ADMUX = 1<<REFS0 | (0b00000001); 
  ADCSRA =(1<<ADEN) | (1<<ADPS2) | (1<<ADPS0); // PRESCALE 64;; 16MHz/64 = 250KHz
}
uint16_t conv( uint8_t ch)
{
  ch &= 0x07;
  ADMUX |= ch;
  ADCSRA |= (1<<ADSC);
  while( ADCSRA & (1<<ADSC)) ;

  return ADC;
}
int main()
{
  init();
  uint16_t val;
  while(1)
  {
    val =conv(0x00);
    Serial.println(val);
  }
}
