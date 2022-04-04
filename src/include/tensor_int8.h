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
Tensor(int8_t) *
tensor_int8_new(
    uint32_t ndim
    , uint32_t * shape);


/**
**
*/
Tensor(uint8_t) *
tensor_uint8_new(
    uint32_t ndim
    , uint32_t * shape);


/**
**
*/
Tensor(char) *
tensor_char_new(
    uint32_t ndim
    , uint32_t * shape);

/**
**
*/
Tensor(bool) *
tensor_bool_new(
    uint32_t ndim
    , uint32_t * shape);


/**
**
*/
Tensor(int8_t) *
tensor_int8_new_from_array(
	uint32_t ndim
	, uint32_t * shape
	, void * array);


/**
**
*/
Tensor(char)*
tensor_char_new_from_array(
    uint32_t ndim
    , uint32_t * shape
    , void * array);


/*
**
*/
Tensor(uint8_t) *
tensor_uint8_new_from_array(
    uint32_t ndim
    , uint32_t * shape
    , void * array);


/**
**
*/
Tensor(bool) *
tensor_bool_new_from_array(
    uint32_t ndim
    , uint32_t * shape
    , void * array);


/**
**
*/
Tensor(int8_t) *
tensor_int8_new_zeros(
    uint32_t ndim
    , uint32_t * shape);


/**
**
*/
Tensor(uint8_t) *
tensor_uint8_new_zeros(
    uint32_t ndim
    , uint32_t * shape);


/**
**
*/
Tensor(char) *
tensor_char_new_zeros(
    uint32_t ndim
    , uint32_t * shape);


/**
**
*/
Tensor(bool) *
tensor_bool_new_false(
    uint32_t ndim
    , uint32_t * shape);


/*
** 
*/
Tensor(int8_t) *
tensor_int8_new_random(
	uint32_t ndim
	, uint32_t * shape);


/**
**
*/
Tensor(uint8_t) *
tensor_uint8_new_random(
    uint32_t ndim
    , uint32_t * shape);


/**
**
*/
Tensor(char) *
tensor_char_new_random(
    uint32_t ndim
    , uint32_t * shape);


/**
**
*/
Tensor(bool) * 
tensor_bool_new_random(
    uint32_t ndim
    , uint32_t * shape);



/**
**
*/
void
tensor_int8_show(Tensor(int8_t) * t);


/**
**
*/
void
tensor_uint8_show(Tensor(uint8_t) * t);


/**
**
*/
void
tensor_char_show(Tensor(char) * t);


/**
**
*/
void 
tensor_bool_show(Tensor(bool) * t);



/**
**
*/
Tensor(int8_t) *
tensor_int8_add(
    Tensor(int8_t) * t1
    , Tensor(int8_t) * t2);


/**
**
*/
Tensor(uint8_t) * 
tensor_uint8_add(
    Tensor(uint8_t) * t1
    , Tensor(uint8_t) * t2);


/**
** Addition operation of tensor of int8_t with int8_t constant
*/
Tensor(int8_t) *
tensor_int8_const_add(
	Tensor(int8_t) * t
	, int8_t n);


/**
** Addition operation of tensor of float with float constant
*/
Tensor(uint8_t) *
tensor_uint8_const_add(
	Tensor(uint8_t) * t
	, uint8_t n);


/**
**
*/
Tensor(int8_t) * 
tensor_int8_multiply(
    Tensor(int8_t) * t1
    , Tensor(int8_t) * t2);


/**
**
*/
Tensor(uint8_t) * 
tensor_uint8_multiply(
    Tensor(uint8_t) * t1
    , Tensor(uint8_t) * t2);



/**
**
*/
Tensor(int8_t) *
tensor_int8_const_multiply(
    Tensor(int8_t) * t
    , int8_t n);


/**
**
*/
Tensor(uint8_t) *
tensor_uint8_const_multiply(
    Tensor(uint8_t) * t
    , uint8_t n);


/**
**
*/
Tensor(int8_t) *
tensor_int8_transpose(Tensor(int8_t) * tensor);


/**
**
*/
Tensor(uint8_t) *
tensor_uint8_transpose(Tensor(uint8_t) * tensor);


/**
**
*/
Tensor(char) *
tensor_char_transpose(Tensor(char) * tensor);


/**
**
*/
Tensor(bool) *
tensor_bool_transpose(Tensor(bool) * tensor);


/*
**
*/
Tensor(int8_t) *
tensor_int8_inverse(Tensor(int8_t) * tensor);


/**
**
*/
Tensor(uint8_t) *
tensor_uint8_inverse(Tensor(uint8_t) * tensor);


/**
**
*/
Tensor(char) *
tensor_char_inverse(Tensor(char) * tensor);


/**
**
*/
Tensor(bool) *
tensor_bool_inverse(Tensor(bool) * tensor);


#endif
