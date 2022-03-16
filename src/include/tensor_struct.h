#ifndef _TENSOR_STRUCT_H_
#define _TENSOR_STRUCT_H_ 

/**
** In this file are defined base tensor structure for creation of 
** clean and dynamic library api.
*/


#include <stddef.h>
#include <stdint.h>

/**
** macro for dynamic type definition of tensor structure with given internal data type
*/ 
#define Tensor(T) Tensor##T


/**
** Abstract Tensor class/structure for dynamic and generic work with tensors instances
*/
typedef uint8_t Tensor;


/**
**
*/
Tensor *
tensor_new(
	size_t ndim
	, size_t * shape
	, size_t scalar_size);



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
size_t 
tensor_elements(Tensor * tensor);


/**
**
*/
#define tensor_ndim(T)													\
	_Generic(															\
		(T)																\
		, Tensor*: *((size_t*) T))
	

/**
**
*/
#define tensor_shape(T)													\
	_Generic(															\
		(T)																\
		, Tensor*: (size_t*) (T+sizeof(size_t)))


/**
**
*/
#define tensor_byte_data(T)												\
	_Generic(															\
		(T)																\
		, Tensor*: (void*) (T + (sizeof(size_t) * (tensor_ndim(T)+1))))


/**
**
*/
void
tensor_finalize(Tensor * tensor);





#endif
