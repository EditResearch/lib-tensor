#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>

#include "test_tensor_generic.h"

#include "../src/include/tensor.h"



int 
main(void)
{
    Tensor(int8_t) * t = 
        tensor_int8_new_from_array(
            2
            , (uint32_t[]){2,2}
            , (int8_t[2][2]) {{2,1}, {1,2}});

    tensor_show(t);

    Tensor(int8_t) * t2 = tensor_const_multiply(t, 2);

    tensor_show(t2);

    printf("%s\n", TENSOR_TYPE(t));

    tensor_delete(TENSOR(t2));
    tensor_delete(TENSOR(t));


    /*
    if (CU_initialize_registry() != CUE_SUCCESS)
       return CU_get_error();
    
    if(tensor_generic_test() == CUE_SUCCESS)
    {
        CU_basic_set_mode(CU_BRM_VERBOSE);
        CU_basic_run_tests();
    }
    
    CU_cleanup_registry();

   return CU_get_error();
    */

    return EXIT_SUCCESS;
}




