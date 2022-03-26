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
inline Tensor(float) *
tensor_float_new(
    size_t ndim
    , size_t * shape)   
{
    return (Tensor(float)*) tensor_new(                                                             
			                    ndim                                                             
			                    , shape                                                          
                                , sizeof(float)                                                  
			                    , sizeof(float) * tensor_count_elements(ndim, shape));
}


/**
**
*/
Tensor(float) *
tensor_float_new_from_array(
	size_t ndim
	, size_t * shape
	, void * array);


/**
**
*/
Tensor(float) *
tensor_float_new_zeros(
    size_t ndim
    , size_t * shape);


/*
** 
*/
Tensor(float) *
tensor_float_new_random(
	size_t ndim
	, size_t * shape);





#endif
