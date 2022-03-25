/**
** @file tensor.h
** @author Petr Horáček
** 
** @brief
** This file makes access point to the tensor library. In this file are declared
** all mathematical operation with tensors with generic api
**
*/ 


#ifndef _TENSOR_H_
#define _TENSOR_H_



#include "tensor_float.h"

/* 
** TODO: build generic library api  
*/


#define TENSOR_VERSION_MAJOR 0
#define TENSOR_VERSION_MINOR 4
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
		, Tensor(float)*: tensor_float_dot)		\
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
tensor_float_const_add(
	Tensor(float) * t
	, float n);


/**
** Generic macro for dynamic switching of called addition function
** based on used tensor data type
*/
#define tensor_const_add(T, n)   						\
	_Generic(											\
		(T)												\
		, Tensor(float)*: tensor_float_add_constant)	\
			(T, n)


/**
**
*/
Tensor(float) * 
tensor_float_multiply(
    Tensor(float) * t1
    , Tensor(float) * t2);


/**
**
*/
#define tensor_multiply(T1, T2)                         \
    _Generic(                                           \
        (T1)                                            \
        , Tensor(float)*: tensor_float_multiply)        \
            (T1, T2)


/**
**
*/
Tensor(float) *
tensor_float_const_multiply(
    Tensor(float) * t
    , float n);


/**
**
*/
#define tensor_const_multiply(T, n)                     \
    _Generic(                                           \
        (T)                                             \
        , Tensor(float)*: tensor_float_const_multiply)  \
            (T, n)




#endif
