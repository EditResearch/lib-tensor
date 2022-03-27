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
		sizeof(int8_t)*tensor_count_length(ndim, shape);

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
		tensor_count_length(ndim, shape);

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
		tensor_count_length(ndim, shape);

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



Tensor(int8_t) *
tensor_int8_new(
    size_t ndim
    , size_t * shape)
{                                                            
    return (Tensor(int8_t)*) tensor_new(                                                           
			                    ndim                                                            
			                    , shape                                                         
                                , sizeof(int8_t)                                                
			                    , tensor_count_length(ndim, shape));
}


Tensor(uint8_t) *
tensor_uint8_new(
    size_t ndim
    , size_t * shape)
{                                                            
    return (Tensor(uint8_t)*) tensor_new(                                                           
			                    ndim                                                             
			                    , shape                                                          
                                , sizeof(uint8_t)                                                
			                    , tensor_count_length(ndim, shape));
}


Tensor(char) *
tensor_char_new(
    size_t ndim
    , size_t * shape)                                                            
{
	return (Tensor(char)*) tensor_new(                                                             
			                    ndim                                                            
			                    , shape                                                         
                                , sizeof(char)                                                  
			                    , tensor_count_length(ndim, shape));
}

Tensor(bool) *
tensor_bool_new(
    size_t ndim
    , size_t * shape)
{                                                            
    return (Tensor(bool)*) tensor_new(                                                             
			                    ndim                                                            
			                    , shape                                                         
                                , sizeof(bool)                                                  
			                    , tensor_count_length(ndim, shape));
}


Tensor(char)*
tensor_char_new_from_array(
    size_t ndim
    , size_t * shape
    , void * array)
{
    return (Tensor(char)*) tensor_int8_new_from_array(ndim, shape, array);
}


Tensor(uint8_t) *
tensor_uint8_new_from_array(
    size_t ndim
    , size_t * shape
    , void * array)
{
    return (Tensor(uint8_t)*) tensor_int8_new_from_array(ndim, shape, array);
}


Tensor(bool) *
tensor_bool_new_from_array(
    size_t ndim
    , size_t * shape
    , void * array)
{
    return (Tensor(bool)*) tensor_int8_new_from_array(ndim, shape, array);
}


Tensor(uint8_t) *
tensor_uint8_new_zeros(
    size_t ndim
    , size_t * shape)
{
    return (Tensor(uint8_t)*) tensor_int8_new_zeros(ndim, shape);
}


Tensor(char) *
tensor_char_new_zeros(
    size_t ndim
    , size_t * shape)
{
    return (Tensor(char)*) tensor_int8_new_zeros(ndim, shape);
}


Tensor(bool) *
tensor_bool_new_false(
    size_t ndim
    , size_t * shape)
{
    return (Tensor(bool)*) tensor_int8_new_zeros(ndim, shape);
}



Tensor(uint8_t) *
tensor_uint8_new_random(
    size_t ndim
    , size_t * shape)
{
    return (Tensor(uint8_t)*) tensor_int8_new_random(ndim, shape);
}


Tensor(char) *
tensor_char_new_random(
    size_t ndim
    , size_t * shape)
{
    return (Tensor(char)*) tensor_int8_new_random(ndim, shape);
}


Tensor(bool) * 
tensor_bool_new_random(
    size_t ndim
    , size_t * shape)
{
    return (Tensor(bool)*) tensor_int8_new_random(ndim, shape);
}
