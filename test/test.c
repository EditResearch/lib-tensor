#include <stdio.h>
#include <stdlib.h>

#include "../src/include/tensor.h"


void
show_tensor(Tensor(float) *tensor)
{
	float * array = tensor_byte_data(TENSOR(tensor));

	printf("Tensor {");

	for(size_t i = 0; i < tensor_elements(TENSOR(tensor)); i ++)
	{
		if(i == 0)
			printf("%f", array[i]);
		else
			printf(", %f", array[i]);
	}

	printf("}\n");
}


void test_01()
{
	printf("Allocating tensor...\n");
	fflush(stdout);

	Tensor(float) * tensor = 
		tensor_float_new_random(3, (size_t[]) {1,2,2});
 
	if(tensor != NULL)
	{
		printf("Tensor successfully allocated.\n");
		fflush(stdout);

		show_tensor(tensor);

		printf("Releasing tensor\n");
		fflush(stdout);

		tensor_delete(TENSOR(tensor));

		printf("Program exit successfully.\n");
		fflush(stdout);
	}
	else
	{
		printf("Tensor was not allocated!\n");
		fflush(stdout);
	}
}


void
test_02()
{
	printf("lib-tensor version %s\n", tensor_version());

	Tensor(float) * tensor = 
		tensor_float_new_zeros(3, (size_t[]){1,2,2});

	if(tensor != NULL)
	{
		size_t ndim = tensor_ndim(TENSOR(tensor));
		printf("ndim = %lld\n", ndim);

		size_t * shape = tensor_shape(TENSOR(tensor));

		printf("Shape {");
		for(size_t i = 0; i < ndim; i++)
		{
			if(i == 0)
				printf("%lld", shape[i]);
			else
				printf(", %lld", shape[i]);
		}	
		printf("}\n");

		show_tensor(tensor);

	}
	else
	{
		printf("Creation tensor error!\n");
	}
}


int 
main(void)
{
	test_02();
	return EXIT_SUCCESS;
}




