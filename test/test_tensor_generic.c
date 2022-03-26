#include "test_tensor_generic.h"
#include <stdbool.h>

/***************************** test cases ***********************/
static void
tensor_new_test(void)
{
    CU_FAIL();
}


static void
tensor_count_elements_test(void)
{
    CU_FAIL();
}


static void
tensor_copy_test(void)
{
    CU_FAIL();
}


static void
tensor_equal_test(void)
{
    CU_FAIL();
}


static void
tensor_length_test(void)
{
    CU_FAIL();
}


static void
tensor_reshape_test(void)
{
    CU_FAIL();
}


static void
tensor_byte_size_test(void)
{
    CU_FAIL();
}


static void
tensor_ndim_test(void)
{
    CU_FAIL();
}


static void
tensor_shape_test(void)
{
    CU_FAIL();
}


static void
tensor_data_test(void)
{
    CU_FAIL();
}


static void
tensor_byte_length_test(void)
{
    CU_FAIL();
}


static void
tensor_delete_test(void)
{
    CU_FAIL();
}

/******************* test suit preparing ******************/
static int
init(void)
{
    return 0;
}


static int
clean_up(void)
{
    return 0;
}


CU_ErrorCode 
tensor_generic_test(void)
{
    CU_pSuite pSuite = 
        CU_add_suite("Tensor generic", init, clean_up);

    if(pSuite == NULL)
      return CU_get_error();

    if ((CU_add_test(pSuite, "tensor_new", tensor_new_test) == NULL) 
        || (CU_add_test(pSuite, "tensor_count_elements", tensor_count_elements_test) == NULL)
        || (CU_add_test(pSuite, "tensor_copy", tensor_copy_test) == NULL)
        || (CU_add_test(pSuite, "tensor_equal", tensor_equal_test) == NULL)
        || (CU_add_test(pSuite, "tensor_length", tensor_length_test) == NULL)
        || (CU_add_test(pSuite, "tensor_reshape", tensor_reshape_test) == NULL)
        || (CU_add_test(pSuite, "tensor_byte_size", tensor_byte_size_test) == NULL)
        || (CU_add_test(pSuite, "tensor_ndim", tensor_ndim_test) == NULL)
        || (CU_add_test(pSuite, "tensor_shape", tensor_shape_test) == NULL)
        || (CU_add_test(pSuite, "tensor_data", tensor_data_test) == NULL)
        || (CU_add_test(pSuite, "tensor_byte_length", tensor_byte_length_test) == NULL)
        || (CU_add_test(pSuite, "tesnsor_delete", tensor_delete_test) == NULL))
   {
      return CU_get_error();
   }

    return CUE_SUCCESS;
}





