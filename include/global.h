
/*******************************************************************************
*
* File global.h
*
* Global parameters and arrays
*
*******************************************************************************/

#ifndef GLOBAL_H
#define GLOBAL_H

#define N 64
#define Nconf 1000000
#define Ncorr 500
#define Nterm 100
#define bin 50
#define D 1.0
#define M 1.0
#define W 1.0
#define a 1.0

#if defined MAIN_PROGRAM
  #define EXTERN
#else
  #define EXTERN extern
#endif

EXTERN float xx[N];

#undef EXTERN

#endif

