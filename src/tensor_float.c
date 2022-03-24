#include "include/tensor_float.h"

#include <stdlib.h>
#include <string.h>
#include <time.h>



/*
** TODO: make it type safe, void* array must be always of type float, but it is not possible
** to insert multidimensional float array without specifiing the input dimension.
** For now it is only way how to dynamicly insert multidimensional array without specifiing the dimension. 
**
** TODO: how to insert the input array as tensor data? Make copy of input array or insert input pointer as
** tensor data value? Making copy of input array is save (input can be array allocated in stack), 
** but not everytime is it needed
*/
Tensor(float) *
tensor_float_new_from_array(
	size_t ndim
	, size_t * shape
	, void * array)
{
	size_t element_size = 
		sizeof(float)*tensor_count_elements(ndim, shape);

	Tensor * tensor = 
		tensor_new(
		    ndim
		    , shape
                    , sizeof(float)
	            , element_size);

	if(tensor != NULL)
	{
		memcpy(
			tensor+sizeof(size_t)*(ndim+1)
			, array
			, element_size);
	}

	return (Tensor(float)*) tensor;
}


Tensor(float) *
tensor_float_new_zeros(
    size_t ndim
    , size_t * shape)
{
	size_t element_size = 
		tensor_count_elements(ndim, shape);

	Tensor * tensor = 
		tensor_new(
			ndim
			, shape
            , sizeof(float)
			, sizeof(float) * element_size);

	if(tensor != NULL)
	{
		float * array = tensor_byte_data(tensor);

		/* TODO: accelerate it with cpu threads, gpu acceleration is not needed */ 
		for(size_t i = 0; i < element_size; i++)
		{
			array[i] = 0;
		}
	}

	return (Tensor(float)*) tensor;
}


Tensor(float) *
tensor_float_new_random(
	size_t ndim
	, size_t * shape)
{
	size_t element_size = 
		tensor_count_elements(ndim, shape);

	Tensor * tensor = 
		tensor_new(
			ndim
			, shape
            , sizeof(float)
			, sizeof(float) * element_size);

	if(tensor != NULL)
	{
		float * array = tensor_byte_data(tensor);

		/* TODO: accelerate it with cpu threads, gpu acceleration is not needed */ 
		for(size_t i = 0; i < element_size; i++)
		{
			array[i] = (float) rand() / (float) RAND_MAX;
		}
	}

	return (Tensor(float)*) tensor;
}




