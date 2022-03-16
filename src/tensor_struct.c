#include "include/tensor_struct.h"
#include <stdlib.h>


struct Tensor
{
	void * array; 		/** generic pointer to tensor data*/
		
	size_t ndim;	 	/** rank of the tensor, metadata for using tensor shape as flexible array */
	size_t shape[];		/** shape of the tensor, which is used for dynamic working with tensor data */
};


size_t
tensor_count_element_size(
	size_t ndim
	, size_t * shape)
{
	size_t element_size = shape[0];

	for(size_t i = 1; i < ndim; i++)
	{
		element_size *= shape[i];
	}

	return element_size;
}


size_t 
tensor_element_size(Tensor * tensor)
{
	return tensor_count_element_size(
				tensor->ndim
				, tensor->shape);
}


size_t
tensor_ndim(Tensor * tensor)
{
	return tensor->ndim;
}


size_t *
tensor_shape(Tensor * tensor)
{
	return tensor->shape;
}



void
tensor_finalize(Tensor * tensor)
{
	if(tensor != NULL)
	{
		if(tensor->array != NULL)
			free(tensor->array);

		free(tensor);
	}
}




