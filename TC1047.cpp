// License       : License.txt
// Specifications: Spec-TC1047_TC1047A.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : TC1047.cpp
// Reason for change: 01.00.00 : 13/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include        "TC1047.h"

#if     iTC1047_ma == iSMA                              // Simple moving average filter
static float32 TC1047_sma_buf[iTC1047_SMA_num];
static sma_f32_t TC1047_Phy_SMA =
{
        iInitial ,                                      // Initial state
        iTC1047_SMA_num ,                               // Simple moving average number & buf size
        0U ,                                            // buffer position
        0.0F ,                                          // sum
        &TC1047_sma_buf[0]                              // buffer
};

#elif   iTC1047_ma == iEMA                              // Exponential moving average filter
static ema_f32_t TC1047_Phy_EMA =
{
        iInitial ,                                      // Initial state
        0.0F ,                                          // Xn-1
        iTC1047_EMA_K                                   // Exponential smoothing factor
};

#elif   iTC1047_ma == iWMA                              // Weighted moving average filter
static float32 TC1047_wma_buf[iTC1047_WMA_num];
static wma_f32_t TC1047_Phy_WMA =
{
        iInitial ,                                      // Initial state
        iTC1047_WMA_num ,                               // Weighted moving average number & buf size
        0U ,                                            // buffer poition
        iTC1047_WMA_num * (iTC1047_WMA_num + 1)/2 ,     // kn sum
        &TC1047_wma_buf[0]                              // Xn buffer
};

#else                                                   // Non-moving average filter
#endif

#define iDummy_adr       0xffffffff                     // Dummy address

const tbl_adc_t tbl_TC1047 =
{
        iTC1047                 ,
        iTC1047_pin             ,
        iTC1047_xoff            ,
        iTC1047_yoff            ,
        iTC1047_gain            ,
        iTC1047_max             ,
        iTC1047_min             ,
        iTC1047_ma              ,
        
#if     iTC1047_ma == iSMA                              // Simple moving average filter
        &TC1047_Phy_SMA         ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#elif   iTC1047_ma == iEMA                              // Exponential moving average filter
        (sma_f32_t*)iDummy_adr  ,
        &TC1047_Phy_EMA         ,
        (wma_f32_t*)iDummy_adr
#elif   iTC1047_ma == iWMA                              // Weighted moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        &TC1047_Phy_WMA
#else                                                   // Non-moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#endif

};
