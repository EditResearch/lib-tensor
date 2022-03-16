#include "include/tensor_float.h"
#include "include/tensor_struct.h"

#include <stdlib.h>
#include <string.h>
#include <time.h>



/*
** TODO: find the way how to have flexible tensor data array without fragmenting memory with 
** another pointer. I want to have the tensor structure as one monolitic memory segment.
*/
struct Tensor(float)
{
	float * array;

	size_t ndim;
	size_t shape[];
};


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
	Tensor(float) * tensor = malloc(sizeof(float*) + sizeof(size_t)*(ndim+1));

	if(tensor != NULL)
	{
		size_t element_size = tensor_count_element_size(ndim, shape);

		tensor->array = malloc(sizeof(float)*element_size);

		if(tensor != NULL)
		{
			tensor->ndim = ndim;
			memcpy(tensor->array, array, sizeof(float) * element_size);
			memcpy(tensor->shape, shape, sizeof(size_t) * ndim);
		}
		else
		{
			/* TODO: make it cleaner */
			free(tensor);
			return NULL;
		}
	}

	return tensor;
}


Tensor(float) *
tensor_float_new_random(
	size_t ndim
	, size_t * shape)
{
	Tensor(float) * tensor = 
		malloc(sizeof(float*) + sizeof(size_t)*(ndim+1));

	if(tensor != NULL)
	{
		size_t element_size = tensor_count_element_size(ndim, shape);

		tensor->array = malloc(sizeof(float)*element_size);

		if(tensor->array != NULL)
		{
			tensor->ndim = ndim;
			memcpy(tensor->shape, shape, sizeof(size_t)*ndim);

			/* TODO: accelerate it with cpu threads, gpu acceleration is not needed */ 
			for(size_t i = 0; i < element_size; i++)
			{
				tensor->array[i] = (float)rand() / (float)RAND_MAX;
			}
		}
		else
		{
			/* TODO: make it cleaner */
			free(tensor);
			return NULL;
		}
	}

	return tensor;
}




