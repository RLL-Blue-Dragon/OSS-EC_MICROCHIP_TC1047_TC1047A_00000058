// License       : License.txt
// Specifications: Spec-TC1047_TC1047A.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : TC1047.h
// Reason for change: 01.00.00 : 13/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#ifndef __TC1047_H__
#define __TC1047_H__

#include "user_define.h"

// Components number
#define iTC1047                 117U                    // Microchip Technology TC1047, TC1047A

// MCP9700 System Parts definitions
#define iTC1047_xoff            0.5F                    // X offset [V]
#define iTC1047_yoff            0.0F                    // Y offset [degree celsius]
#define iTC1047_gain            0.01F                   // Gain [V/degree celsius]
#define iTC1047_max             125.0F                  // Temperature Max [degree celsius]
#define iTC1047_min             -40.0F                  // Temperature Min [degree celsius]

extern const tbl_adc_t tbl_TC1047;

#endif /*__TC1047_H__*/
