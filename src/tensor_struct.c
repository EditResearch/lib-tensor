#include "include/tensor_struct.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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


size_t
tensor_w(
    Tensor * tensor
    , char * path)
{
    if(tensor != NULL)
    {
        FILE * f = fopen(path, "wb");
    
        if(f != NULL)
        {
            //TODO: count byte size of the tensor
            size_t out_size = fwrite(tensor, 1, 0, f);

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




