/** 
 * ---------------------------------------------------------------+ 
 * @desc        ENCODER
 * ---------------------------------------------------------------+ 
 *              Copyright (C) 2020 Marian Hrinko.
 *              Written by Marian Hrinko (mato.hrinko@gmail.com)
 *
 * @author      Marian Hrinko
 * @datum       06.10.2020
 * @update      04.10.2022
 * @file        encoder.c
 * @version     1.0
 * @tested      AVR Atmega328
 *
 * @depend      font.h, twi.h
 * ---------------------------------------------------------------+
 * @descr       Version 1.0 -> control stepper motor
 * ---------------------------------------------------------------+
 * @usage       
 */

/**
 * @includes
 */
#include "encoder.h"

/**
 * @desc    Encoder Init
 *
 * @param   void
 *
 * @return  char
 */
void Encoder_Init (void)
{ 
  // CLK/INT0, SW/INT1, DT/PD4 as input
  DDR &= ~((1 << ENCODER_CLK) | (1 << ENCODER_DT) | (1 << ENCODER_SW));
  // CLK/INT0, SW/INT1, DT/PD4 pull up enable
  PORT |= ((1 << ENCODER_CLK) | (1 << ENCODER_DT) | (1 << ENCODER_SW));
  // enable interrupt on INT0
  // NB: 
  // Atmega16 -> GICR
  // Atmega328p -> EIMSK
  EIMSK |= ((1 << INT0) | (1 << INT1));
  // INT0 - falling edge
  EICRA |= (1 << ISC01) | (1 << ISC00) | (1 << ISC11) | (1 << ISC10);
  // global interupts enable
  sei ();
}

/**
 * @desc    Encoder Read
 * @insp    https://chome.nerpa.tech/mcu/reading-rotary-encoder-on-arduino/
 *
 * @param   void
 *
 * @return  char
 */
void Encoder_Read (void)
{
  // allowable states 
  //  0 - error
  //  1 - clockwise
  // -1 - counterclockwise
  uint8_t states[] = {
   0, 1,-1, 0,
  -1, 0, 0, 1,
   1, 0, 0,-1,
   0,-1, 1, 0};

  // declare previous state with set to 0
  static uint8_t prev = 0;
  // read PINs value ENCODER_CLK & ENCODER_DT
  uint8_t pin_value = (1 << ((PIN & (1 << ENCODER_CLK)) >> ENCODER_CLK)) | ((PIN & (1 << ENCODER_DT)) >> (ENCODER_DT));
  prev <<= 2;
  prev |= pin_value & 0x0f;

  // return state
  return states[prev];
}