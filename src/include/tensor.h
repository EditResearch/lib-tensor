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


#include "tensor_float.h"

/* 
** TODO: build generic library api  
*/


#define TENSOR_VERSION_MAJOR 0
#define TENSOR_VERSION_MINOR 3
#define TENSOR_VERSION_PATCH 0


const char *
tensor_version(void);


/*
** Casting macro with list of allowed Tensor derived variations
** This enable type safety during compilation
*/
#define TENSOR(T)                       	\
    _Generic(                           	\
        (T)                             	\
        , Tensor*: T                    	\
        , Tensor(float)*: (Tensor*) T)



/**
** Dot operation on tensor of float type
*/
Tensor(float) * 
tensor_float_dot(
	Tensor(float) * t1
	, Tensor(float) * t2);



/**
** Generic macro for dynamic switching of called dot product function
** based on used tensor data type
*/
#define tensor_dot(T1, T2)						\
	_Generic(									\
		(T1)									\
		, Tensor(float*): tensor_float_dot)		\
			(T1, T2)


/**
** Addition opration of two float tensors 
*/
Tensor(float) *
tensor_float_add(
	Tensor(float) * t1
	, Tensor(float) * t2);


/**
** Generic macro for dynamic switching of called addition function
** based on used tensor data type
*/
#define tensor_add(T1, T2)						\
	_Generic(									\
		(T1)									\
		, Tensor(float)*: tensor_float_add) 	\
			(T1, T2)


/**
** Addition operation of tensor of float with float constant
*/
Tensor(float) *
tensor_float_add_constant(
	Tensor(float) * t
	, float n);


/**
** Generic macro for dynamic switching of called addition function
** based on used tensor data type
*/
#define tensor_add_constant(T, n)						\
	_Generic(											\
		(T)												\
		, Tensor(float)*: tensor_float_add_constant)	\
			(T, n)



#endif
