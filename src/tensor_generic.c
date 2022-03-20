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
	Tensor * tensor = 
		malloc(
			elements + sizeof(uint8_t)
			+ (sizeof(size_t) * (ndim+1)));

	if(tensor != NULL)
	{
        *((uint8_t*) tensor) = element_size;
		*((size_t*) (tensor+1)) = ndim;
		memcpy(
			tensor_shape(tensor)
			, shape
			, sizeof(size_t)*ndim);
        
	}

	return tensor;
}


Tensor *
tensor_copy(Tensor * tensor)
{
    size_t byte_size = tensor_byte_size(tensor);

    Tensor * copy = malloc(byte_size);

    if(copy != NULL)
        memcpy(copy, tensor, byte_size);

    return copy;
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


size_t
tensor_byte_size(Tensor * tensor)
{
    return (tensor_elements(tensor) 
        * tensor_element_size(tensor))
        + ((tensor_ndim(tensor)+1)
        * sizeof(size_t)) 
        + 1;
}


size_t
tensor_save(
    Tensor * tensor
    , char * path)
{
    if(tensor != NULL)
    {
        FILE * f = fopen(path, "wb");
    
        if(f != NULL)
        {
            size_t out_size = 
                fwrite(
                    tensor
                    , 1
                    , tensor_byte_size(tensor)
                    , f);

            fclose(f);

            return out_size;
        }
    }

    return -1;
}


Tensor *
tensor_load(char * path)
{
    FILE * f = fopen(path, "rb");

    if(f != NULL)
    {
        fseek(f, 0, SEEK_END);
        size_t fsize = ftell(f);
        fseek(f, 0, SEEK_SET);

        Tensor * tensor = malloc(fsize);
        
        if(tensor != NULL)
           fread(tensor, fsize, 1, f);
        
        fclose(f);
        
        return tensor;
    }

    return NULL;    
}


void
tensor_delete(Tensor * tensor)
{
	if(tensor != NULL)
		free(tensor);
}









