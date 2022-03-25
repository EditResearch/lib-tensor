/**
** @file tensor_struct.h
** 
*/

#ifndef _TENSOR_STRUCT_H_
#define _TENSOR_STRUCT_H_ 

/**
** In this file are defined base tensor structure for creation of 
** clean and dynamic library api.
*/


#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>


/**
** macro for dynamic type definition of tensor structure with given internal data type
*/ 
#define Tensor(T) Tensor##T


/**
** Abstract Tensor class/structure for dynamic and generic 
** work with tensors instances
*/
typedef uint8_t Tensor;


/**
**
*/
Tensor *
tensor_new(
	size_t ndim
	, size_t * shape
    , uint8_t element_size
	, size_t elements);


/**
**
*/
size_t
tensor_count_elements(
	size_t ndim
	, size_t * shape);


/**
**
*/
Tensor *
tensor_copy(Tensor * t);


/**
**
*/
bool
tensor_equal(
    Tensor * t1
    , Tensor * t2);


/**
**
*/
size_t 
tensor_elements(Tensor * t);


/**
**
*/
bool
tensor_reshape(Tensor * t);


/*
**
*/
size_t
tensor_byte_size(Tensor * t);


/**
**
*/
#define tensor_element_size(T)               \
    _Generic(                                \
        (T)                                  \
        , Tensor*: *((uint8_t*) T))


/**
**
*/
#define tensor_ndim(T)													\
	_Generic(															\
		(T)																\
		, Tensor*: *((size_t*) (T+1)))
	

/**
**
*/
#define tensor_shape(T)													\
	_Generic(															\
		(T)																\
		, Tensor*: (size_t*) (T+1+sizeof(size_t)))


/**
** TODO: make it cleaner
*/
#define tensor_byte_data(T)						    						\
	_Generic(								    							\
		(T)								    								\
		, Tensor*: (void*) (T + 1 + (sizeof(size_t) * (tensor_ndim(T)+1))))


/**
** Functon for saving content of the tensor structure into file. 
** Thanks to the Tensor data type is made up of consists area of memory, 
** the  writing and reading process from file is more easier then with 
** complex data structures.
*/
size_t
tensor_save(
    Tensor * t
    , char * path);


/**
** Function for reading Tensor data structure from file
*/
Tensor *
tensor_load(char * path);


/**
** 
*/
void
tensor_delete(Tensor * t);





#endif
