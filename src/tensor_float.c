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
	uint32_t ndim
	, uint32_t * shape
	, void * array)
{
	size_t element_size = 
		sizeof(float) * tensor_count_length(ndim, shape);

	Tensor * t = 
		tensor_new(
		    ndim
		    , shape
            , sizeof(float)
	        , element_size);

	if(t != NULL)
	{
		memcpy(
			tensor_data(t)
			, array
			, element_size);
	}

	return (Tensor(float)*) t;
}


Tensor(float) *
tensor_float_new_zeros(
    uint32_t ndim
    , uint32_t * shape)
{
	size_t element_size = 
		tensor_count_length(ndim, shape);

	Tensor * t = 
		tensor_new(
			ndim
			, shape
            , sizeof(float)
			, sizeof(float) * element_size);

	if(t != NULL)
	{
		float * array = tensor_data(t);

		/* TODO: accelerate it with cpu threads, gpu acceleration is not needed */ 
		for(size_t i = 0; i < element_size; i++)
		{
			array[i] = 0;
		}
	}

	return (Tensor(float)*) t;
}


Tensor(float) *
tensor_float_new_random(
	uint32_t ndim
	, uint32_t * shape)
{
	size_t element_size = 
		tensor_count_length(ndim, shape);

	Tensor * t = 
		tensor_new(
			ndim
			, shape
            , sizeof(float)
			, sizeof(float) * element_size);

	if(t != NULL)
	{
		float * array = tensor_data(t);

		/* TODO: accelerate it with cpu threads, gpu acceleration is not needed */ 
		for(size_t i = 0; i < element_size; i++)
		{
			array[i] = (float) rand() / (float) RAND_MAX;
		}
	}

	return (Tensor(float)*) t;
}



Tensor(float) *
tensor_float_new(
    uint32_t ndim
    , uint32_t * shape)   
{
    return (Tensor(float)*) tensor_new(                                                             
			                    ndim                                                             
			                    , shape                                                          
                                , sizeof(float)                                                  
			                    , sizeof(float) * tensor_count_length(ndim, shape));
}


void 
tensor_float_show(Tensor(float) * t)
{
    
    (void)t;
}



Tensor(float) *
tensor_float_add(
	Tensor(float) * t1
	, Tensor(float) * t2)
{
	(void)t1;
	(void)t2;
	/* TODO: code here */
	return NULL;
}


Tensor(float) *
tensor_float_const_add(
	Tensor(float) * t
	, float n)
{
	(void) t;
	(void) n;
	/* TODO: code here */
	return NULL;
}


Tensor(float) * 
tensor_float_multiply(
    Tensor(float) * t1
    , Tensor(float) * t2)
{
    (void)t1;
    (void)t2;

    /* TODO: code here */    
    return NULL;
}


Tensor(float) *
tensor_float_const_multiply(
    Tensor(float) * t
    , float n)
{
    (void) t;
    (void) n;

    /* TODO: code here */
    return NULL;        
}


Tensor(float) *
tensor_float_transpose(Tensor(float) * t)
{
    (void) t;
    /* TODO: code here */
    return NULL;
}


Tensor(float) *
tensor_float_inverse(Tensor(float) * t)
{
    (void) t;
    /* TODO: code here */
    return NULL;
}
