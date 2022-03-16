#ifndef _TENSOR_STRUCT_H_
#define _TENSOR_STRUCT_H_ 

/**
** In this file are defined base tensor structure for creation of 
** clean and dynamic library api.
*/


#include <stddef.h>


/**
** macro for dynamic type definition of tensor structure with given internal data type
*/ 
#define Tensor(T) Tensor##T



/**
** Abstract Tensor class/structure for dynamic and generic work with tensors instances
*/
struct Tensor;
typedef struct Tensor Tensor;



/**
**
*/
size_t
tensor_count_element_size(
	size_t ndim
	, size_t * shape);


/**
**
*/
size_t 
tensor_element_size(Tensor * tensor);


/**
**
*/
size_t
tensor_ndim(Tensor * tensor);


/**
**
*/
size_t *
tensor_shape(Tensor * tensor);


/**
**
*/
void
tensor_finalize(Tensor * tensor);





#endif
