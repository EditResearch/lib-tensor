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


#define SHAPE(T)                    \
    _Generic(                       \
        (T)                         \
        , Tensor*: (Shape*) T)


/**
** Abstract Tensor class/structure for dynamic and generic 
** work with tensors instances
*/
typedef uint8_t Tensor;


typedef struct Shape
{
   uint8_t byte_size;
   uint32_t ndim;
   uint32_t shape[];
}Shape;


/**
**
*/
Tensor *
tensor_new(
	uint32_t ndim
	, uint32_t * shape
    , uint8_t byte_size
	, size_t data_byte_length);


/**
**
*/
size_t
tensor_count_length(
	uint32_t ndim
	, uint32_t * shape);


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
tensor_reshape(
    Tensor * t
    , uint32_t ndim
    , uint32_t * shape);


/**
**
*/
uint8_t
tensor_byte_size(Tensor * t);


/**
**
*/
uint32_t
tensor_ndim(Tensor * t);


/**
**
*/
uint32_t *
tensor_shape(Tensor * t);


/**
**
*/
void *
tensor_data(Tensor * t);


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
