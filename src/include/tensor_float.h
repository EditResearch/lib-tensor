
#ifndef _TENSOR_FLOAT_H_
#define _TENSOR_FLOAT_H_ 

#include "tensor_struct.h"


/**
**
*/
struct Tensor(float);
typedef struct Tensor(float) Tensor(float);


/**
**
*/
Tensor(float) *
tensor_float_new_from_array(
	size_t ndim
	, size_t * shape
	, void * array);


/*
** 
*/
Tensor(float) *
tensor_float_new_random(
	size_t ndim
	, size_t * shape);





#endif
