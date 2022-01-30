/** 
 * ---------------------------------------------------------------+ 
 * @desc        28BYJ-48 Stepper Motor Driver 
 * ---------------------------------------------------------------+ 
 *              Copyright (C) 2022 Marian Hrinko.
 *              Written by Marian Hrinko (mato.hrinko@gmail.com)
 *
 * @author      Marian Hrinko
 * @datum       30.01.2022
 * @file        byj.c
 * @tested      AVR Atmega328p
 *
 * @depend      byj48.h
 * ---------------------------------------------------------------+
 */

// include libraries
#include "byj48.h"

/**
 * @desc    Init 28BYJ-48
 *
 * @param   void
 *
 * @return  void
 */
void BYJ48_Init (void)
{
  // set IN1-4 as output
  BYJ48_SetDDR_INs ();
  // set IN1-4 high
  BYJ48_SetPORT_INs ();
}

/**
 * @desc    Set DDR INs
 *
 * @param   void
 *
 * @return  void
 */
void BYJ48_SetDDR_INs (void)
{
  // set DB7-DB4 as output
  SETBIT(BYJ48_DDR_IN, BYJ48_IN1);
  SETBIT(BYJ48_DDR_IN, BYJ48_IN2);
  SETBIT(BYJ48_DDR_IN, BYJ48_IN3);
  SETBIT(BYJ48_DDR_IN, BYJ48_IN4);
}

/**
 * @desc    Set PORT INs
 *
 * @param   void
 *
 * @return  void
 */
void BYJ48_SetPORT_INs (void)
{
  // set DB4-DB7  
  SETBIT(BYJ48_PORT_IN, BYJ48_IN1);
  SETBIT(BYJ48_PORT_IN, BYJ48_IN2);
  SETBIT(BYJ48_PORT_IN, BYJ48_IN3);
  SETBIT(BYJ48_PORT_IN, BYJ48_IN4);
}
