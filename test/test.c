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


void test_01(void)
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
test_02(void)
{
	printf("lib-tensor version %s\n", tensor_version());

	Tensor(float) * tensor = 
		tensor_float_new_zeros(3, (size_t[]){1,2,2});

	if(tensor != NULL)
	{
		size_t ndim = tensor_ndim(TENSOR(tensor));
		printf("ndim = %ld\n", ndim);

		size_t * shape = tensor_shape(TENSOR(tensor));

		printf("Shape {");
		for(size_t i = 0; i < ndim; i++)
		{
			if(i == 0)
				printf("%ld", shape[i]);
			else
				printf(", %ld", shape[i]);
		}	
		printf("}\n");
        

		show_tensor(tensor);

        tensor_delete(TENSOR(tensor));

	}
	else
	{
		printf("Creation tensor error!\n");
	}
}


void
test_03(void)
{
    Tensor(float) * tensor1 = tensor_float_new_zeros(3, (size_t[]){1,2,2});
    Tensor(float) * tensor2 = tensor_float_new_zeros(3, (size_t[]){2,2,2});
    Tensor(float) * tensor3 = tensor_float_new_zeros(3, (size_t[]){1,2,2});



    if(tensor_equal(TENSOR(tensor2), TENSOR(tensor1)) == true)
        printf("Tensors are equal\n");
    else
        printf("Tensors are not equal!\n");


    tensor_delete(TENSOR(tensor1));
    tensor_delete(TENSOR(tensor2));
}


int 
main(void)
{
	test_03();
	return EXIT_SUCCESS;
}




