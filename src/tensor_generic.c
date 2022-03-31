#include "include/tensor_generic.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* TODO: shape validation */

static bool 
tensor_shape_valid(
    uint32_t ndim
    , uint32_t * shape);



/*************************** public interface *********************************/



Tensor *
tensor_new(
	uint32_t ndim
	, uint32_t * shape
    , uint8_t byte_size
	, size_t data_byte_length)
{
    if(tensor_shape_valid(ndim, shape) == false
        || byte_size == 0
        || data_byte_length == 0)
        return NULL;

    Tensor * t = 
            malloc(
               sizeof(sizeof(Shape)) 
               + (sizeof(uint32_t) * ndim) 
               + data_byte_length);
    
    if(t != NULL)
    {
        SHAPE(t)->byte_size = byte_size;
        SHAPE(t)->ndim = ndim;
        memcpy(SHAPE(t)->shape, shape, sizeof(uint32_t) * ndim);
    }

	return t;
}


Tensor *
tensor_copy(Tensor * t)
{
    size_t byte_size = tensor_byte_length(t);

    Tensor * copy = malloc(byte_size);

    if(copy != NULL)
        memcpy(copy, t, byte_size);

    return copy;
}


bool
tensor_reshape(
    Tensor * t
    , uint32_t ndim
    , uint32_t * shape)
{
    if(tensor_count_length(ndim, shape) == tensor_length(t))
    {
        SHAPE(t)->ndim = ndim;
        memcpy(SHAPE(t)->shape, shape, sizeof(uint32_t) * ndim);

        return true;
    }

    return false;
}


bool
tensor_equal(
    Tensor * t1
    , Tensor * t2)
{
    size_t t1_ndim = tensor_ndim(t1);

    if(t1_ndim != tensor_ndim(t2)
       || tensor_byte_size(t1) != tensor_byte_size(t2))
        return false;

     if(memcmp(
         tensor_shape(t1)
         , tensor_shape(t2)
         , sizeof(size_t) * t1_ndim) == 0)
     {
         return !memcmp(
                   tensor_data(t1)
                   , tensor_data(t2)
                   , tensor_byte_size(t1) * tensor_length(t1));
     }

     return false;
}


size_t
tensor_count_length(
	uint32_t ndim
	, uint32_t * shape)
{
	size_t element_size = shape[0];

	for(uint32_t i = 1; i < ndim; i++)
		element_size *= shape[i];

	return element_size;
}


uint8_t
tensor_byte_size(Tensor * t)
{
    return SHAPE(t)->byte_size;   
}


uint32_t
tensor_ndim(Tensor * t)
{
    return SHAPE(t)->ndim;
}


uint32_t *
tensor_shape(Tensor * t)
{
    return SHAPE(t)->shape;
}


void *
tensor_data(Tensor * t)
{
    return (void*) (t + sizeof(Shape) + (sizeof(uint32_t) * SHAPE(t)->ndim));
}


size_t 
tensor_length(Tensor * t)
{
	return tensor_count_length(
				SHAPE(t)->ndim
				, SHAPE(t)->shape);
}


size_t
tensor_byte_length(Tensor * t)
{
    /* 
     * TODO: modify to count only byte size of tensor data,
     * dont forget modify code where is this function used
     * and if it is possible make it cleaner
     */
    return (tensor_length(t) 
        * tensor_byte_size(t))
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
                    , tensor_byte_length(t)
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


/********************** private interface *************************/


static bool 
tensor_shape_valid(
    uint32_t ndim
    , uint32_t * shape)
{
    if(ndim == 0)
        return false;
    
    for(size_t i = 0; i < ndim; i++)
    {
         if(shape[i] == 0)
            return false;
    }
        
    return true;
}



