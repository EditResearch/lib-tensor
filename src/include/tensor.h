#ifndef _TENSOR_H_
#define _TENSOR_H_

/**
** Main header file for include lib-tensor library
** This file containe mainly include of other source files and 
** generic macros for cleaner library api
**
** Tensor is mathematical structure for manipulation with multidimensional 
** number arrays. This has wide use in machine learning a physics modeling.
** Every tensor operations is possible divide into sequence of base algebraic 
** operations. This operations are computationally intensive and therefore 
** they must be accelerated with parallel threads on cpu or even better on gpu.
**
** No every computer has external graphics card for acceleration of computations, so
** this api is divided into parts one thread only, parallel threads on cpu or parallel
** thread on gpu throw cuda api. 
*/ 


#include "tensor_struct.h"

/* 
** TODO: build generic library api  
*/






#endif
