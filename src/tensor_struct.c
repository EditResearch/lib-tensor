#include "include/tensor_struct.h"
#include <stdlib.h>
#include <string.h>

/* TODO: shape validation */


Tensor *
tensor_new(
	size_t ndim
	, size_t * shape
	, size_t element_size)
{
	Tensor * tensor = 
		malloc(
			element_size 
			+ (sizeof(size_t) * (ndim+1)));

	if(tensor != NULL)
	{
		*((size_t*) tensor) = ndim;
		memcpy(
			tensor+sizeof(size_t)
			, shape
			, sizeof(size_t)*ndim);
	}

	return tensor;
}


size_t
tensor_count_elements(
	size_t ndim
	, size_t * shape)
{
	size_t element_size = shape[0];

	for(size_t i = 1; i < ndim; i++)
	{
		element_size *= shape[i];
	}

	return element_size;
}


size_t 
tensor_elements(Tensor * tensor)
{
	return tensor_count_elements(
				tensor_ndim(tensor)
				, tensor_shape(tensor));
}


void
tensor_finalize(Tensor * tensor)
{
	if(tensor != NULL)
		free(tensor);
}




