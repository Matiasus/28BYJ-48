/** 
 * ---------------------------------------------------------------+ 
 * @desc        ENCODER
 * ---------------------------------------------------------------+ 
 *              Copyright (C) 2020 Marian Hrinko.
 *              Written by Marian Hrinko (mato.hrinko@gmail.com)
 *
 * @author      Marian Hrinko
 * @datum       06.10.2020
 * @update      05.08.2022
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

#ifndef __ENCODER_H__
#define __ENCODER_H__

  #include <avr/io.h>
  #include <avr/interrupt.h> 

  // Port definition
  #ifndef PORT
    #define PORT         PORTD
  #endif

  // Data direction definition
  #ifndef DDR
    #define DDR           DDRD
  #endif

  // Data direction definition
  #ifndef PIN
    #define PIN           PIND
  #endif

  /**
    @pin CLK or A / INT0

                         4k7
                        _____ 
     MIC CLK => ---+---|_____|--- => ENCODER CLK
                   |
                ___|___
                _______  100nF
                   |
                   |
                 __|__
   */
  #ifndef ENCODER_CLK
    #define ENCODER_CLK     2
  #endif
  /**
   * @pin DT or B
                        4k7
                       _____ 
     MIC DT => ---+---|_____|--- => ENCODER DT
                  |
               ___|___
               _______  100nF
                  |
                  |
                __|__
   */
  #ifndef ENCODER_DT
    #define ENCODER_DT      4
  #endif
  /**
   * @pin SW - button / INT1
   */
  #ifndef ENCODER_SW
    #define ENCODER_SW      3
  #endif

  #define MAX_POS          10
  #define MID_POS           5
  #define MIN_POS           0

  /**
   * @desc    Encoder Init
   *
   * @param   void
   *
   * @return  char
   */
  void Encoder_Init (void);

  /**
  * @desc    Encoder Read
  * @insp    https://chome.nerpa.tech/mcu/reading-rotary-encoder-on-arduino/
  *
  * @param   void
  *
  * @return  char
  */
  void Encoder_Read (void);

#endif
