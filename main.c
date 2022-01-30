/** 
 * ---------------------------------------------------+ 
 * @desc        Main file
 * ---------------------------------------------------+ 
 * @copyright   Copyright (C) 2022 Marian Hrinko.
 * @author      Marian Hrinko
 * @email       mato.hrinko@gmail.com
 * @datum       30.01.2022
 * @update      30.01.2022
 * @file        main.c
 * @version     1.0
 * @tested      AVR Atmega328p
 * ---------------------------------------------------+
 */

// include libraries
#include <util/delay.h>
#include "lib/byj48.h"

/**
 * @desc    Main function
 *
 * @param   void
 *
 * @return  int
 */
int main (void)
{
  // init
  BYJ48_Init ();

  PORTC = 0b0000000;
  _delay_ms(1000);

  PORTC = 0b0000010;
  _delay_ms(1000);

  PORTC = 0b0000110;
  _delay_ms(1000);

  PORTC = 0b0000100;
  _delay_ms(1000);

  PORTC = 0b0001100;
  _delay_ms(1000);

  PORTC = 0b0001000;
  _delay_ms(1000);

  PORTC = 0b0011000;
  _delay_ms(1000);

  PORTC = 0b0010000;
  _delay_ms(1000);

  // EXIT
  // ------------------------------------------------- 
  // return & exit
  return 0;
}
