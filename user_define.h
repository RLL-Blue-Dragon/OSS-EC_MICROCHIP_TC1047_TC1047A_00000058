// License       : License.txt
// Specifications: Spec-00000058.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : user_define.h
// BSL              : 00000058
/*-- File Header Comment End -------------------------------------------------*/

#ifndef __USER_DEFINE_H__
#define __USER_DEFINE_H__

#include "mbed.h"
#include "oss_ec_00000058.h"

#define iADC_bit                16U                             // MPU ADC bit
#define iADC_vdd                3.3F                            // MPU Vdd Configures the reference voltage [V]
#define iVref                   3.3F                            // Configures the reference voltage

#define iTC1047_pin             A0                              // ADC pin

// Moving average filter select
#define iMA                     iNonMA                          // Non-moving average filter
//#define iMA                     iSMA                            // Simple moving average filter
//#define iMA                     iEMA                            // Exponential moving average filter
//#define iMA                     iWMA                            // Weighted moving average filter

//#define iTC1047_SMA_num         4U                              // Simple moving average number & buf size
//#define iTC1047_EMA_K           0.75F                           // Exponential Smoothing Factor
//#define iTC1047_WMA_num         3U                              // Weighted moving average number & buf size

#define iTC1047_ma              iMA                             // Moving average select

#endif /*__USER_DEFINE_H__*/
