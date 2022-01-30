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
 * @depend      
 * ---------------------------------------------------------------+
 */

#ifndef __BYJ48_H__
#define __BYJ48_H__

#include <avr/io.h>
#include <stdio.h>

  // Success
  // -----------------------------------
  #ifndef BYJ48_SUCCESS
    #define BYJ48_SUCCESS       0
  #endif

  // Error
  // -----------------------------------
  #ifndef BYJ48_ERROR
    #define BYJ48_ERROR         1
  #endif 

  // STEPPER MOTOR PINs
  // -----------------------------------
  #if defined(__AVR_ATmega328P__)

    // DATA port / pin
    #ifndef BYJ48_DDR_IN
      #define BYJ48_DDR_IN    DDRC
    #endif
    #ifndef BYJ48_PORT_IN
      #define BYJ48_PORT_IN   PORTC
    #endif
    #ifndef BYJ48_PIN_IN
      #define BYJ48_PIN_IN    PINC
    #endif

    #ifndef BYJ48_IN1    
      #define BYJ48_IN1       1
    #endif
    #ifndef BYJ48_IN2
      #define BYJ48_IN2       2
    #endif
    #ifndef BYJ48_IN3
      #define BYJ48_IN3       3
    #endif
    #ifndef BYJ48_IN4
      #define BYJ48_IN4       4
    #endif

  #endif
  
  // BIT OPERATIONs
  // -----------------------------------
  // set bit
  #define SETBIT(REG, BIT) { REG |= (1 << BIT); }
  // clear bit
  #define CLRBIT(REG, BIT) { REG &= ~(1 << BIT); }
  
  /**
   * @desc    Init 28BYJ-48
   *
   * @param   void
   *
   * @return  void
   */
  void BYJ48_Init (void);

  /**
   * @desc    Set DDR 28BYJ-48 INs
   *
   * @param   void
   *
   * @return  void
   */
  void BYJ48_SetDDR_INs (void);

  /**
   * @desc    Set PORT 28BYJ-48 INs
   *
   * @param   void
   *
   * @return  void
   */
  void BYJ48_SetPORT_INs (void);

#endif
