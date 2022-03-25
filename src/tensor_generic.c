#include "include/tensor_generic.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* TODO: shape validation */


/*************************** public interface *********************************/



Tensor *
tensor_new(
	size_t ndim
	, size_t * shape
    , uint8_t element_size
	, size_t elements)
{
	Tensor * t = 
		malloc(
		   elements + sizeof(uint8_t)
		   + (sizeof(size_t) * (ndim+1)));

	if(t != NULL)
	{
        *((uint8_t*) t) = element_size;
		*((size_t*) (t+1)) = ndim;
		memcpy(
			tensor_shape(t)
			, shape
			, sizeof(size_t)*ndim);
	}

	return t;
}


Tensor *
tensor_copy(Tensor * t)
{
    size_t byte_size = tensor_byte_size(t);

    Tensor * copy = malloc(byte_size);

    if(copy != NULL)
        memcpy(copy, t, byte_size);

    return copy;
}


bool
tensor_reshape(Tensor * t)
{
    (void)t;

    /* TODO: code here */
    return false;
}


bool
tensor_equal(
    Tensor * t1
    , Tensor * t2)
{
    size_t t1_ndim = tensor_ndim(t1);

    if(t1_ndim == tensor_ndim(t2)
       && tensor_element_size(t1) == tensor_element_size(t2))
    {
        if(memcmp(
             tensor_shape(t1)
             , tensor_shape(t2)
             , sizeof(size_t) * t1_ndim) == 0)
        {
            return !memcmp(
                      tensor_byte_data(t1)
                      , tensor_byte_data(t2)
                      , tensor_element_size(t1) * tensor_elements(t1));
        }
    }

    return false;
}


size_t
tensor_count_elements(
	size_t ndim
	, size_t * shape)
{
	size_t element_size = shape[0];

	for(size_t i = 1; i < ndim; i++)
		element_size *= shape[i];

	return element_size;
}


size_t 
tensor_elements(Tensor * t)
{
	return tensor_count_elements(
				tensor_ndim(t)
				, tensor_shape(t));
}


size_t
tensor_byte_size(Tensor * t)
{
    /* 
     * TODO: modify to count only byte size of tensor data,
     * dont forget modify code where is this function used
     * and if it is possible make it cleaner
     */
    return (tensor_elements(t) 
        * tensor_element_size(t))
        + ((tensor_ndim(t)+1)
        * sizeof(size_t)) 
        + 1;
}


size_t
tensor_save(
    Tensor * t
    , char * path)
{
    FILE * file = fopen(path, "wb");
    
    if(file != NULL)
    {
        size_t size_out = 
                fwrite(
                    t
                    , 1
                    , tensor_byte_size(t)
                    , file);

        fclose(file);

        return size_out;
    }

    return -1;
}


Tensor *
tensor_load(char * path)
{
    FILE * file = fopen(path, "rb");

    if(file != NULL)
    {
        fseek(file, 0, SEEK_END);
        size_t fsize = ftell(file);
        fseek(file, 0, SEEK_SET);

        Tensor * t = malloc(fsize);
        
        if(t != NULL)
           fread(t, fsize, 1, file);
        
        fclose(file);
        
        return t;
    }

    return NULL;    
}


void
tensor_delete(Tensor * t)
{
	if(t != NULL)
		free(t);
}









