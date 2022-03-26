#ifndef _TENSOR_INT8_H_
#define _TENSOR_INT8_H_

#include "tensor_generic.h"
#include <stdint.h>
#include <stdbool.h>


struct Tensor(char);
typedef struct Tensor(char) Tensor(char);

struct Tensor(int8_t);
typedef struct Tensor(int8_t) Tensor(int8_t);

struct Tensor(uint8_t);
typedef struct Tensor(uint8_t) Tensor(uint8_t);

struct Tensor(bool);
typedef struct Tensor(bool) Tensor(bool);


/**
**
*/
inline Tensor(int8_t) *
tensor_int8_new(
    size_t ndim
    , size_t * shape)
{                                                            
    return (Tensor(int8_t)*) tensor_new(                                                           
			                    ndim                                                            
			                    , shape                                                         
                                , sizeof(int8_t)                                                
			                    , tensor_count_elements(ndim, shape));
}


/**
**
*/
inline Tensor(uint8_t) *
tensor_uint8_new(
    size_t ndim
    , size_t * shape)
{                                                            
    return (Tensor(uint8_t)*) tensor_new(                                                           
			                    ndim                                                             
			                    , shape                                                          
                                , sizeof(uint8_t)                                                
			                    , tensor_count_elements(ndim, shape));
}


/**
**
*/
inline Tensor(char) *
tensor_char_new(
    size_t ndim
    , size_t * shape)                                                            
{
	return (Tensor(char)*) tensor_new(                                                             
			                    ndim                                                            
			                    , shape                                                         
                                , sizeof(char)                                                  
			                    , tensor_count_elements(ndim, shape));
}

/**
**
*/
inline Tensor(bool) *
tensor_bool_new(
    size_t ndim
    , size_t * shape)
{                                                            
    return (Tensor(bool)*) tensor_new(                                                             
			                    ndim                                                            
			                    , shape                                                         
                                , sizeof(bool)                                                  
			                    , tensor_count_elements(ndim, shape));
}


/**
**
*/
Tensor(int8_t) *
tensor_int8_new_from_array(
	size_t ndim
	, size_t * shape
	, void * array);


/**
**
*/
inline Tensor(char)*
tensor_char_new_from_array(
    size_t ndim
    , size_t * shape
    , void * array)
{
    return (Tensor(char)*) tensor_int8_new_from_array(ndim, shape, array);
}

/**
**
*/
inline Tensor(uint8_t) *
tensor_uint8_new_from_array(
    size_t ndim
    , size_t * shape
    , void * array)
{
    return (Tensor(uint8_t)*) tensor_int8_new_from_array(ndim, shape, array);
}


/**
**
*/
inline Tensor(bool) *
tensor_bool_new_from_array(
    size_t ndim
    , size_t * shape
    , void * array)
{
    return (Tensor(bool)*) tensor_int8_new_from_array(ndim, shape, array);
}


/**
**
*/
Tensor(int8_t) *
tensor_int8_new_zeros(
    size_t ndim
    , size_t * shape);


/**
**
*/
inline Tensor(uint8_t) *
tensor_uint8_new_zeros(
    size_t ndim
    , size_t * shape)
{
    return (Tensor(uint8_t)*) tensor_int8_new_zeros(ndim, shape);
}


/**
**
*/
inline Tensor(char) *
tensor_char_new_zeros(
    size_t ndim
    , size_t * shape)
{
    return (Tensor(char)*) tensor_int8_new_zeros(ndim, shape);
}


/**
**
*/
inline Tensor(bool) *
tensor_bool_new_false(
    size_t ndim
    , size_t * shape)
{
    return (Tensor(bool)*) tensor_int8_new_zeros(ndim, shape);
}


/*
** 
*/
Tensor(int8_t) *
tensor_int8_new_random(
	size_t ndim
	, size_t * shape);


/**
**
*/
inline Tensor(uint8_t) *
tensor_uint8_new_random(
    size_t ndim
    , size_t * shape)
{
    return (Tensor(uint8_t)*) tensor_int8_new_random(ndim, shape);
}


/**
**
*/
inline Tensor(char) *
tensor_char_new_random(
    size_t ndim
    , size_t * shape)
{
    (Tensor(char)*) tensor_int8_new_random(ndim, shape);
}


/**
**
*/
inline Tensor(bool) * 
tensor_bool_new_random(
    size_t ndim
    , size_t * shape)
{
    return (Tensor(bool)*) tensor_int8_new_random(ndim, shape);
}


#endif
