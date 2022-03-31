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


#endif
