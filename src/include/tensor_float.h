/**
** @file tensor_float.h
** @author Petr Horáček
**
** @brief Module with Tensor(float) data type declaration
*/


#ifndef _TENSOR_FLOAT_H_
#define _TENSOR_FLOAT_H_ 


#include "tensor_generic.h"


/**
**
*/
struct Tensor(float);
typedef struct Tensor(float) Tensor(float);


/**
**
*/
Tensor(float) *
tensor_float_new(
    uint32_t ndim
    , uint32_t * shape);


/**
**
*/
Tensor(float) *
tensor_float_new_from_array(
	uint32_t ndim
	, uint32_t * shape
	, void * array);


/**
**
*/
Tensor(float) *
tensor_float_new_zeros(
    uint32_t ndim
    , uint32_t * shape);


/*
** 
*/
Tensor(float) *
tensor_float_new_random(
	uint32_t ndim
	, uint32_t * shape);




/**
**
*/
void 
tensor_float_show(Tensor(float) * t);


/**
** Addition opration of two float tensors 
*/
Tensor(float) *
tensor_float_add(
	Tensor(float) * t1
	, Tensor(float) * t2);


/**
** Addition operation of tensor of float with float constant
*/
Tensor(float) *
tensor_float_const_add(
	Tensor(float) * t
	, float n);



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
Tensor(float) *
tensor_float_const_multiply(
    Tensor(float) * t
    , float n);



/**
**
*/
Tensor(float) *
tensor_float_transpose(Tensor(float) * tensor);


/**
**
*/
Tensor(float) *
tensor_float_inverse(Tensor(float) * tensor);

#endif
