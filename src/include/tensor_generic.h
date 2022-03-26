/**
** @file tensor_struct.h
** 
*/

#ifndef _TENSOR_GENERIC_H_
#define _TENSOR_GENERIC_H_ 

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
tensor_length(Tensor * t);


/**
**
*/
bool
tensor_reshape(Tensor * t);



inline uint8_t
tensor_byte_size(Tensor * t)
{
    return *((uint8_t*) t);   
}


inline size_t
tensor_ndim(Tensor * t)
{
    return *((size_t*)(t + sizeof(uint8_t)));
}


inline size_t *
tensor_shape(Tensor * t)
{
    return (size_t*)(t + sizeof(uint8_t) + sizeof(size_t));
}



inline void *
tensor_data(Tensor * t)
{
    return (void*) (t + tensor_ndim(t) + sizeof(uint8_t) + sizeof(size_t));
}




/**
**
*/
size_t
tensor_byte_length(Tensor * t);


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
