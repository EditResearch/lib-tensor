/**
** @file tensor.h
** @author Petr Horáček
** 
** @brief
** This file makes access point to the tensor library. In this file are declared
** all mathematical operation with tensors with generic api
**
*/ 


#ifndef _TENSOR_H_
#define _TENSOR_H_



#include "tensor_float.h"
#include "tensor_int8.h"

/* 
** TODO: build generic library api  
** TODO: use for char tensor the same functions as for uint8_t or int8_t tensor
** TODO: unite flow point tensor type and type with the same byte width and signification to one module
    for reduce amount of code
*/


#define TENSOR_VERSION_MAJOR 0
#define TENSOR_VERSION_MINOR 5
#define TENSOR_VERSION_PATCH 0


const char *
tensor_version(void);


/*
** Casting macro with list of allowed Tensor derived variations
** This enable type safety during compilation
*/
#define TENSOR(T)                       	\
    _Generic(                           	\
        (T)                             	\
        , Tensor*: T                    	\
        , Tensor(float)*:   (Tensor*) T     \
        , Tensor(int8_t)*:  (Tensor*) T     \
        , Tensor(uint8_t)*: (Tensor*) T     \
        , Tensor(char)*:    (Tensor*) T     \
        , Tensor(bool)*:    (Tensor*) T)     



/**
** Dot operation on tensor of float type
*/
Tensor(float) * 
tensor_float_dot(
	Tensor(float) * t1
	, Tensor(float) * t2);


/**
** Dot operation on tensor of int8_t type
*/
Tensor(int8_t) * 
tensor_int8_dot(
	Tensor(int8_t) * t1
	, Tensor(int8_t) * t2);


/**
** Dot operation on tensor of uint8_t type
*/
Tensor(uint8_t) * 
tensor_uint8_dot(
	Tensor(uint8_t) * t1
	, Tensor(uint8_t) * t2);



/**
** TODO: treat type check for second input parameter
*/
#define tensor_char_dot(t1, t2)                             \
    _Generic(                                               \
        (t1)                                                \
        , Tensor(char)*: tensor_int8_dot)                   \
            ((Tensor(int8_t)*) t1, (Tensor(int8_t)*) t2


/**
** Generic macro for dynamic switching of called dot product function
** based on used tensor data type
*/
#define tensor_dot(T1, T2)						\
	_Generic(									\
		(T1)									\
		, Tensor(float)*: tensor_float_dot      \
        , Tensor(int8_t)*: tensor_int8_dot      \
        , Tensor(uint8_t)*: tensor_uint8_dot    \
        , Tensor(char)*   : tensor_char_dot)	\
			(T1, T2)


/**
** Addition opration of two float tensors 
*/
Tensor(float) *
tensor_float_add(
	Tensor(float) * t1
	, Tensor(float) * t2);


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
** TODO: treat type check for second input parameter
*/
#define tensor_char_add(t1, t2)                             \
    _Generic(                                               \
        (t1)                                                \
        , Tensor(char)*: tensor_int8_add)                   \
            ((Tensor(int8_t)*) t1, (Tensor(int8_t)*) t2)
    

/**
** Generic macro for dynamic switching of called addition function
** based on used tensor data type
*/
#define tensor_add(T1, T2)						\
	_Generic(									\
		(T1)									\
		, Tensor(float)*: tensor_float_add      \
        , Tensor(int8_t)*: tensor_int8_add      \
        , Tensor(uint8_t)*: tensor_uint8_add    \
        , Tensor(char)*:    tensor_char_add)    \
			(T1, T2)


/**
** Addition operation of tensor of float with float constant
*/
Tensor(float) *
tensor_float_const_add(
	Tensor(float) * t
	, float n);


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
** TODO: treat type check for second input parameter
*/
#define tensor_char_const_add(t, n)                 \
    _Generic(                                       \
        (t)                                         \
        , Tensor(char)*: tensor_int8_const_add)     \
            ((Tensor(int8_t)*) t, (int8_t) n)
        


/**
** Generic macro for dynamic switching of called addition function
** based on used tensor data type
*/
#define tensor_const_add(T, n)   						\
	_Generic(											\
		(T)												\
		, Tensor(float)*: tensor_float_const_add        \
        , Tensor(int8_t)*: tensor_int8_const_add        \
        , Tensor(uint8_t)*: tensor_uint8_const_add      \
        , Tensor(char)*: tensor_char_const_add) 	    \
			(T, n)


/**
**
*/
Tensor(float) * 
tensor_float_multiply(
    Tensor(float) * t1
    , Tensor(float) * t2);


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
** TODO: treat type check for second input parameter
*/
#define tensor_char_multiply(t1, t2)                    \
    _Generic(                                           \
        (t1)                                            \
        , Tensor(char)*: tensor_int8_multiply)          \
            ((Tensor(int8_t)*) t1, (Tensor(int8_t)*) t2)


/**
**
*/
#define tensor_multiply(T1, T2)                         \
    _Generic(                                           \
        (T1)                                            \
        , Tensor(float)*: tensor_float_multiply         \
        , Tensor(int8_t)*: tensor_int8_multipy          \
        , Tensor(uint8_t)*: tensor_uint8_multiply       \
        , Tensor(char)*: tensor_char_multiply)          \
            (T1, T2)


/**
**
*/
Tensor(float) *
tensor_float_const_multiply(
    Tensor(float) * t
    , float n);


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
** TODO: treat type check for second input parameter
*/
#define tensor_char_const_multiply(t, n)                \
    _Generic(                                           \
        (t)                                             \
        , Tensor(char)*: tensor_int8_const_multiply)    \
            ((Tensor(int8_t) t), (int8_t) n)

/**
**
*/
#define tensor_const_multiply(T, n)                     \
    _Generic(                                           \
        (T)                                             \
        , Tensor(float)*: tensor_float_const_multiply   \
        , Tensor(int8_t)*: tensor_int8_const_multiply   \
        , Tensor(uint8_t)*: tensor_uint8_const_multiply \
        , Tensor(char)*: tensor_char_const_multiply)    \
            (T, n)









#endif
