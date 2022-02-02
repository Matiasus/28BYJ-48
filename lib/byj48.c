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

const uint8_t g_halfstep[] = {
   0b00000001
  ,0b00000011
  ,0b00000010
  ,0b00000110
  ,0b00000100
  ,0b00001100
  ,0b00001000
  ,0b00001001
};

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
 * @desc    
 *
 * @param   void
 *
 * @return  void
 */
void BYJ48_HalfStepClockwise (void)
{
  uint8_t i = 0;
  // one step = 1/8*64
  while (i<HALFSTEPCOUNT) {
    // send to INs
    BYJ48_PORT_IN = (BYJ48_PORT_IN & 0xF0) | g_halfstep[i++];
    // delay
    _delay_ms (2);
  }
}

/**
 * @desc    
 *
 * @param   void
 *
 * @return  void
 */
void BYJ48_HalfStepAntiClockwise (void)
{
  uint8_t i = HALFSTEPCOUNT;
  // one step = 1/8*64
  while (i--) {
    // send to INs
    BYJ48_PORT_IN = (BYJ48_PORT_IN & 0xF0) | g_halfstep[i];
    // delay
    _delay_ms (2);
  }
}

/**
 * @desc    
 *
 * @param   void
 *
 * @return  void
 */
void BYJ48_OneTurnClockwise (void)
{
  uint16_t j;
  // one turn
  for (j=0; j<512; j++) {
    // one step
    BYJ48_HalfStepClockwise ();
  }
}

/**
 * @desc    
 *
 * @param   void
 *
 * @return  void
 */
void BYJ48_OneTurnAntiClockwise (void)
{
  uint16_t j;
  // one turn
  for (j=0; j<512; j++) {
    // one step
    BYJ48_HalfStepAntiClockwise ();
  }
}

/**
 * @desc    
 *
 * @param   void
 *
 * @return  void
 */
void BYJ48_TurnOff (void)
{
  // send to INs
  BYJ48_PORT_IN &= TURNOFF;
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
