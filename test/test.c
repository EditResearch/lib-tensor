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

int 
main(void)
{
	printf("%s\n", tensor_version());

	printf("%s\n", tensor_version());
	printf("%s\n", tensor_version());
	return EXIT_SUCCESS;
}




