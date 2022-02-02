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
  // 1 turn clockwise
  BYJ48_TurnClockwise ();
  // turn off 
  BYJ48_TurnOff ();

  _delay_ms(1000);

  // 1 turn anticlockwise
  BYJ48_TurnAntiClockwise ();
  // turn off 
  BYJ48_TurnOff ();

  // EXIT
  // ------------------------------------------------- 
  // return & exit
  return 0;
}
