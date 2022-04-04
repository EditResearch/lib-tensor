#include "include/tensor_int8.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


Tensor(int8_t) *
tensor_int8_new_from_array(
	uint32_t ndim
	, uint32_t * shape
	, void * array)
{
	size_t element_size = 
		sizeof(int8_t)*tensor_count_length(ndim, shape);

	Tensor * t = 
		tensor_new(
		    ndim
		    , shape
            , sizeof(int8_t)
	        , element_size);

	if(t != NULL)
	{
		memcpy(
			tensor_data(t)
			, array
			, element_size);
	}

	return (Tensor(int8_t)*) t;
}


Tensor(int8_t) *
tensor_int8_new_zeros(
    uint32_t ndim
    , uint32_t * shape)
{
	size_t element_size = 
		tensor_count_length(ndim, shape);

	Tensor * t = 
		tensor_new(
			ndim
			, shape
            , sizeof(int8_t)
			, sizeof(int8_t) * element_size);

	if(t != NULL)
	{
		float * array = tensor_data(t);

		/* TODO: accelerate it with cpu threads, gpu acceleration is not needed */ 
		for(size_t i = 0; i < element_size; i++)
			array[i] = 0;
	}

	return (Tensor(int8_t)*) t;
}


Tensor(int8_t) *
tensor_int8_new_random(
	uint32_t ndim
	, uint32_t * shape)
{
	size_t element_size = 
		tensor_count_length(ndim, shape);

	Tensor * t = 
		tensor_new(
			ndim
			, shape
            , sizeof(int8_t)
			, sizeof(int8_t) * element_size);

	if(t != NULL)
	{
		float * array = tensor_data(t);

		/* TODO: accelerate it with cpu threads, gpu acceleration is not needed */ 
		for(size_t i = 0; i < element_size; i++)
			array[i] = rand() % sizeof(int8_t);
	}

	return (Tensor(int8_t)*) t;
}



Tensor(int8_t) *
tensor_int8_new(
    uint32_t ndim
    , uint32_t * shape)
{                                                            
    return (Tensor(int8_t)*) tensor_new(                                                           
			                    ndim                                                            
			                    , shape                                                         
                                , sizeof(int8_t)                                                
			                    , tensor_count_length(ndim, shape));
}


Tensor(uint8_t) *
tensor_uint8_new(
    uint32_t ndim
    , uint32_t * shape)
{                                                            
    return (Tensor(uint8_t)*) tensor_new(                                                           
			                    ndim                                                             
			                    , shape                                                          
                                , sizeof(uint8_t)                                                
			                    , tensor_count_length(ndim, shape));
}


Tensor(char) *
tensor_char_new(
    uint32_t ndim
    , uint32_t * shape)                                                            
{
	return (Tensor(char)*) tensor_new(                                                             
			                    ndim                                                            
			                    , shape                                                         
                                , sizeof(char)                                                  
			                    , tensor_count_length(ndim, shape));
}

Tensor(bool) *
tensor_bool_new(
    uint32_t ndim
    , uint32_t * shape)
{                                                            
    return (Tensor(bool)*) tensor_new(                                                             
			                    ndim                                                            
			                    , shape                                                         
                                , sizeof(bool)                                                  
			                    , tensor_count_length(ndim, shape));
}


Tensor(char)*
tensor_char_new_from_array(
    uint32_t ndim
    , uint32_t * shape
    , void * array)
{
    return (Tensor(char)*) tensor_int8_new_from_array(ndim, shape, array);
}


Tensor(uint8_t) *
tensor_uint8_new_from_array(
    uint32_t ndim
    , uint32_t * shape
    , void * array)
{
    return (Tensor(uint8_t)*) tensor_int8_new_from_array(ndim, shape, array);
}


Tensor(bool) *
tensor_bool_new_from_array(
    uint32_t ndim
    , uint32_t * shape
    , void * array)
{
    return (Tensor(bool)*) tensor_int8_new_from_array(ndim, shape, array);
}


Tensor(uint8_t) *
tensor_uint8_new_zeros(
    uint32_t ndim
    , uint32_t * shape)
{
    return (Tensor(uint8_t)*) tensor_int8_new_zeros(ndim, shape);
}


Tensor(char) *
tensor_char_new_zeros(
    uint32_t ndim
    , uint32_t * shape)
{
    return (Tensor(char)*) tensor_int8_new_zeros(ndim, shape);
}


Tensor(bool) *
tensor_bool_new_false(
    uint32_t ndim
    , uint32_t * shape)
{
    return (Tensor(bool)*) tensor_int8_new_zeros(ndim, shape);
}



Tensor(uint8_t) *
tensor_uint8_new_random(
    uint32_t ndim
    , uint32_t * shape)
{
    return (Tensor(uint8_t)*) tensor_int8_new_random(ndim, shape);
}


Tensor(char) *
tensor_char_new_random(
    uint32_t ndim
    , uint32_t * shape)
{
    return (Tensor(char)*) tensor_int8_new_random(ndim, shape);
}


Tensor(bool) * 
tensor_bool_new_random(
    uint32_t ndim
    , uint32_t * shape)
{
    return (Tensor(bool)*) tensor_int8_new_random(ndim, shape);
}


/*
** TODO: think about how to do it better, there is a lot of almost the same code
** this is place where is possible to do mistake 
*/
void
tensor_int8_show(Tensor(int8_t) * t)
{
    /* TODO: make line break based on tensor shape */
    printf("Tensor {");
    
    int8_t * t_data = tensor_data((Tensor *) t);
    size_t t_length = tensor_length((Tensor *) t);

    for(size_t i = 0; i < t_length; i++)
    {
        if(i == 0)
            printf("%hd", t_data[i]);
        else
            printf(", %hd", t_data[i]);
    }
    
    printf("}\n");
}


void
tensor_uint8_show(Tensor(uint8_t) * t)
{
    (void)t;
}


void
tensor_char_show(Tensor(char) * t)
{

    (void)t;
}


void 
tensor_bool_show(Tensor(bool) * t)
{

    (void)t;
}


Tensor(int8_t) *
tensor_int8_const_add(
	Tensor(int8_t) * t
	, int8_t n)
{
	(void) t;
	(void) n;
	/* TODO: code here */
	return NULL;
}


Tensor(uint8_t) *
tensor_uint8_const_add(
	Tensor(uint8_t) * t
	, uint8_t n)
{
	(void) t;
	(void) n;
	/* TODO: code here */
	return NULL;
}


Tensor(int8_t) *
tensor_int8_add(
	Tensor(int8_t) * t1
	, Tensor(int8_t) * t2)
{
	(void)t1;
	(void)t2;
	/* TODO: code here */
	return NULL;
}


Tensor(uint8_t) *
tensor_uint8_add(
	Tensor(uint8_t) * t1
	, Tensor(uint8_t) * t2)
{
	(void)t1;
	(void)t2;
	/* TODO: code here */
	return NULL;
}


/*
** TODO: make it better, there is a lot of almost the same code
** this is the place where is possible to do a mistake 
*/
Tensor(int8_t) *
tensor_int8_const_multiply(
    Tensor(int8_t) * t
    , int8_t n)
{
    Tensor(int8_t) * t_copy = 
        (Tensor(int8_t)*) tensor_copy((Tensor *)t);

    int8_t * t_data = tensor_data((Tensor *) t_copy);
    size_t t_length = tensor_length((Tensor*) t_copy);

    for(size_t i = 0; i < t_length; i++)
        t_data[i] *= n;

    return t_copy;        
}


Tensor(uint8_t) *
tensor_uint8_const_multiply(
    Tensor(uint8_t) * t
    , uint8_t n)
{
    (void) t;
    (void) n;

    /* TODO: code here */
    return NULL;        
}


Tensor(int8_t) *
tensor_int8_transpose(Tensor(int8_t) * t)
{
    (void) t;
    /* TODO: code here */
    return NULL;
}


Tensor(uint8_t) *
tensor_uint8_transpose(Tensor(uint8_t) * t)
{
    (void) t;
    /* TODO: code here */
    return NULL;
}


Tensor(char) *
tensor_char_transpose(Tensor(char) * t)
{
    (void) t;
    /* TODO: code here */
    return NULL;
}


Tensor(bool) *
tensor_bool_transpose(Tensor(bool) * t)
{
    (void) t;
    /* TODO: code here */
    return NULL;
}


Tensor(int8_t) *
tensor_int8_inverse(Tensor(int8_t) * t)
{
    (void) t;
    /* TODO: code here */
    return NULL;
}


Tensor(uint8_t) *
tensor_uint8_inverse(Tensor(uint8_t) * t)
{
    (void) t;
    /* TODO: code here */
    return NULL;
}


Tensor(char) *
tensor_char_inverse(Tensor(char) * t)
{
    (void) t;
    /* TODO: code here */
    return NULL;
}


Tensor(bool) *
tensor_bool_inverse(Tensor(bool) * t)
{
    (void) t;
    /* TODO: code here */
    return NULL;
}
