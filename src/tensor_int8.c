#include "include/tensor_int8.h"
#include <string.h>
#include <stdlib.h>


Tensor(int8_t) *
tensor_int8_new_from_array(
	size_t ndim
	, size_t * shape
	, void * array)
{
	size_t element_size = 
		sizeof(int8_t)*tensor_count_elements(ndim, shape);

	Tensor * tensor = 
		tensor_new(
		    ndim
		    , shape
            , sizeof(int8_t)
	        , element_size);

	if(tensor != NULL)
	{
		memcpy(
			tensor+sizeof(size_t)*(ndim+1)
			, array
			, element_size);
	}

	return (Tensor(int8_t)*) tensor;
}


Tensor(int8_t) *
tensor_int8_new_zeros(
    size_t ndim
    , size_t * shape)
{
	size_t element_size = 
		tensor_count_elements(ndim, shape);

	Tensor * tensor = 
		tensor_new(
			ndim
			, shape
            , sizeof(int8_t)
			, sizeof(int8_t) * element_size);

	if(tensor != NULL)
	{
		float * array = tensor_data(tensor);

		/* TODO: accelerate it with cpu threads, gpu acceleration is not needed */ 
		for(size_t i = 0; i < element_size; i++)
			array[i] = 0;
	}

	return (Tensor(int8_t)*) tensor;
}


Tensor(int8_t) *
tensor_int8_new_random(
	size_t ndim
	, size_t * shape)
{
	size_t element_size = 
		tensor_count_elements(ndim, shape);

	Tensor * tensor = 
		tensor_new(
			ndim
			, shape
            , sizeof(int8_t)
			, sizeof(int8_t) * element_size);

	if(tensor != NULL)
	{
		float * array = tensor_data(tensor);

		/* TODO: accelerate it with cpu threads, gpu acceleration is not needed */ 
		for(size_t i = 0; i < element_size; i++)
			array[i] = rand() % sizeof(int8_t);
	}

	return (Tensor(int8_t)*) tensor;
}

