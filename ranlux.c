#include <stdlib.h>
// #include <stdio.h>
#include <math.h>
#include "ranlux-3.3/ranlxs.h"
// #include "ranlux-3.3/ranlxd.h"

// #define NXS 204
// #define NXD 99

// int get_randlux(int NXS){
void get_randlux(
   int NXS,
   float xs[NXS],
   int seed_int_
   ){

   int k,test1;
   int *state1;
   float sbase;
   // float ys[NXS],xsn[96]
   // float xs[NXS],ys[NXS],xsn[96];
   double base;

   sbase=(float)(ldexp(1.0,24));
   base=ldexp(1.0,48);
   state1=malloc(rlxs_size()*sizeof(int));
   
   rlxs_init(0,seed_int_);


/*******************************************************************************
*
* Check that the correct sequences of random numbers are obtained
*
*******************************************************************************/

   // for (k=0;k<20;k++)
   // {
   ranlxs(xs,NXS);
   // }

   // return *xs ;
}