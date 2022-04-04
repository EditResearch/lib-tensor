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


#define TENSOR_TYPE(T)                              \
    _Generic(                                       \
        (T)                                         \
        , Tensor*: "Tensor"                         \
        , Tensor(uint8_t)*: "Tensor(uint8_t)"       \
        , Tensor(int8_t)*: "Tensor(int8_t)"         \
        , Tensor(char)*: "Tensor(char)"             \
        , Tensor(bool)*: "Tensor(bool)"             \
        , Tensor(float)*: "Tensor(float)"           \
        , default: "Unknown")                       


#define tensor_show(T)                          \
    _Generic(                                   \
        (T)                                     \
        , Tensor(int8_t)*:  tensor_int8_show    \
        , Tensor(uint8_t)*: tensor_uint8_show   \
        , Tensor(char)*: tensor_char_show       \
        , Tensor(bool)*: tensor_bool_show       \
        , Tensor(float)*: tensor_float_show)    \
            (T)



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
#define tensor_const_multiply(T, n)                      \
    _Generic(                                            \
        (T)                                              \
        , Tensor(float)*   : tensor_float_const_multiply \
        , Tensor(int8_t)*  : tensor_int8_const_multiply  \
        , Tensor(uint8_t)* : tensor_uint8_const_multiply) \
            (T, n)




/**
**
*/
#define tensor_transpose(T)                             \
    _Generic(                                           \
        (T)                                             \
        , Tensor(float)*: tensor_float_transpose        \
        , Tensor(int8_t)*: tensor_int8_transpose        \
        , Tensor(uint8_t)*: tensor_uint8_transpose      \
        , Tensor(char)*: tensor_char_transpose          \
        , Tensor(bool)*: tensor_bool_transpose)         \
            (T)



/**
**
*/
#define tensor_inverse(T)                               \
    _Generic(                                           \
        (T)                                             \
        , Tensor(float)*: tensor_float_inverse          \
        , Tensor(int8_t)*: tensor_int8_inverse          \
        , Tensor(uint8_t)*: tensor_uint8_inverse        \
        , Tensor(char)*: tensor_char_inverse            \
        , Tensor(bool)*: tensor_bool_inverse)           \
            (T)


#endif
