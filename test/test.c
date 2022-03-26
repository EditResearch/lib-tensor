#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>

#include "test_tensor_generic.h"


int 
main(void)
{
    if (CU_initialize_registry() != CUE_SUCCESS)
       return CU_get_error();
    
    if(tensor_generic_test() == CUE_SUCCESS)
    {
        CU_basic_set_mode(CU_BRM_VERBOSE);
        CU_basic_run_tests();
    }
    
    CU_cleanup_registry();

   return CU_get_error();
}




