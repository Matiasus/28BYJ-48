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
#include <stdio.h>
#include <util/delay.h>
#include "lib/encoder.h"
#include "lib/ssd1306.h"
#include "lib/byj48.h"

// state value
volatile uint8_t state = 5;

// INT0 interrupt - encoder direction
ISR(INT0_vect) 
{
  // counterclockwise
  if (PIN & (1 << ENCODER_DT)) {
    // check min position
    if (state > MIN_POS) {
      // decrement
      state--;
    }
  // clockwise
  } else {
    // check max position
    if (state < MAX_POS) {
      // increment
      state++;
    }
  }
}

// INT1 interrupt - button push
ISR(INT1_vect) 
{
  // null
  state = MID_POS;
}

/**
 * @desc    Main function
 *
 * @param   void
 *
 * @return  int
 */
int main (void)
{
  char str[2];
  uint8_t tmp = state;
  uint8_t addr = SSD1306_ADDRESS;

  // ENCODER
  // ------------------------------
  // encode init
  Encoder_Init ();

  // OLED
  // ------------------------------
  // init ssd1306
  SSD1306_Init (addr);
  // clear screen
  SSD1306_ClearScreen ();
  // update
  SSD1306_UpdateScreen (addr);

  // MOTOR
  // ------------------------------
  // init
  BYJ48_Init ();

  // main loop
  while (1) {
    // catch changed state
    if (tmp != state) {
      // disable global interrupts 
      cli ();

      // null if number less than 10
      if (state == 0) {
        // set position
        SSD1306_SetPosition (55,2);
        // int to text
        SSD1306_DrawString ("===");
        // update
        SSD1306_UpdateScreen (addr);
        // turn off 
        BYJ48_TurnOff (); 
      // to right
      } else if (state > tmp) {
        // set position
        SSD1306_SetPosition (55,2);
        // int to text
        SSD1306_DrawString ("==>");
        // update
        SSD1306_UpdateScreen (addr);
        // 1 turn clockwise
        BYJ48_OneTurnClockwise ();
      // to left
      } else {
        // set position
        SSD1306_SetPosition (55,2);
        // int to text
        SSD1306_DrawString ("<==");
        // update
        SSD1306_UpdateScreen (addr);
        // 1 turn anticlockwise
        BYJ48_OneTurnAntiClockwise ();
      }
      // turn off 
      BYJ48_TurnOff ();
      // set tmp
      tmp = state;
      // enable global interrupts 
      sei ();
    }
  }

  // EXIT
  // ------------------------------------------------- 
  // return & exit
  return 0;
}
