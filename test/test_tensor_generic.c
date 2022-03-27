#include "test_tensor_generic.h"
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

/***************************** helper functions ****************/

static bool
is_elem(
    size_t value
    , size_t size
    , const size_t * array)
{
    for(size_t i = 0; i < size; i++)
    {
        if(array[i] == value)
            return true;
    }

    return false;
}

static void
show_ndim(Tensor * t);


/***************************** test cases ***********************/


static void
tensor_constructor_and_destructor_test(void)
{
    for(int i = 0; i < TEST_CYCLES; i ++)
    {
        size_t ndim = rand() % (NDIM_MAX-NDIM_MIN) + NDIM_MIN;
        size_t * shape = malloc(sizeof(size_t)*ndim);
        
        if(shape == NULL)
        {
            CU_ASSERT_PTR_NULL_FATAL("Malloc allocation error in shape preparing");  
            return;
        }

        size_t length = 1;    

        for(size_t j = 0; j < ndim; j ++)
        {
            shape[j] = rand() % DIMENSION_MAX;
            length *= shape[j];
        }

        Tensor * tensor = tensor_new(ndim, shape, sizeof(char), length);      

        if(tensor != NULL)
        {
            tensor_delete(tensor);
            CU_PASS("Tensor successfuly released without crash.\n");
        }
        else
        {
            CU_ASSERT_PTR_NULL(tensor);
        }    
        
        free(shape);
    }    
}



static void
tensor_count_length_test(void)
{
    for(int i = 0; i < TEST_CYCLES; i ++)
    {
        size_t ndim = rand() % (NDIM_MAX-NDIM_MIN) + NDIM_MIN;
        size_t * shape = malloc(sizeof(size_t)*ndim);
        
        if(shape == NULL)
        {
            CU_ASSERT_PTR_NULL_FATAL("Malloc allocation error in shape preparing");  
            return;
        }

        for(size_t j = 0; j < ndim; j ++)
        {
            shape[j] = rand() % (DIMENSION_MAX - DIMENSION_MIN) + DIMENSION_MIN;
        }

        size_t elements = tensor_count_length(ndim, shape);

        /* non-zero test */
        if(ndim != 0
            && is_elem(0, ndim, shape) == false
            && elements == 0)
        {
            CU_ASSERT_NOT_EQUAL(elements, 0);
            return;
        }
        else
        {
            /* divisibility test */
            for(size_t j = 0; j < ndim; j++)
            {
                CU_ASSERT_EQUAL(elements % shape[j], 0);
            }
        }
        
        CU_PASS("Tensor elements counting success.\n");
        free(shape);
    }    
}


static void
tensor_copy_test(void)
{
    for(size_t i = 0; i < TEST_CYCLES; i++)
    {      
        size_t ndim = rand() % (NDIM_MAX-NDIM_MIN) + NDIM_MIN;
        size_t * shape = malloc(sizeof(size_t)*ndim);
        
        if(shape == NULL)
        {
            CU_ASSERT_PTR_NULL_FATAL("Malloc allocation error in shape preparing");  
            return;
        }

        size_t length = 1;
        for(size_t j = 0; j < ndim; j ++)
        {
            shape[j] = rand() % (DIMENSION_MAX-DIMENSION_MIN) + DIMENSION_MIN;
            length *= shape[j];
        }

        Tensor * t1 = tensor_new(ndim, shape, sizeof(char), length);      
        
        if(t1 != NULL)
        {
            Tensor * t2 = tensor_copy(t1);
            
            /* NULL test */
            if(t2 != NULL)
            {
                /* byte comparation test */
                if(memcmp(t1, t2, 1+length+(sizeof(size_t)*(ndim+1))) == 0)
                {
                    CU_PASS("Tensors are the same.");
                }
                else
                {
                    CU_FAIL("Tensors are different!\n");
                }   
                
                tensor_delete(t2);
            }
            else
            {
                CU_ASSERT_PTR_NOT_NULL(t2);
            }

            tensor_delete(t1);
        }
        else
        {
           CU_FAIL("Tensor t1 constructor error!");
        }

        free(shape);
    }
}


static void
tensor_equal_test(void)
{
    for(size_t i = 0; i < TEST_CYCLES; i++)
    {      
        size_t ndim_1 = rand() % (NDIM_MAX-NDIM_MIN) + NDIM_MIN;
        size_t * shape_1 = malloc(sizeof(size_t)*ndim_1);

        size_t ndim_2 = rand() % (NDIM_MAX-NDIM_MIN) + NDIM_MIN;
        size_t * shape_2 = malloc(sizeof(size_t)*ndim_2);
        
        if(shape_1 == NULL 
            && shape_2 != NULL)
        {
            CU_ASSERT_PTR_NULL_FATAL("Malloc allocation error in shape preparing");  
            return;
        }

        size_t length_1 = 1;
        size_t length_2 = 1;

        for(size_t j = 0; j < ndim_1; j ++)
        {
            shape_1[j] = rand() % (DIMENSION_MAX-DIMENSION_MIN) + DIMENSION_MIN ;
            length_1 *= shape_1[j];
        }

        for(size_t j = 0; j < ndim_2; j ++)
        {
            shape_2[j] = rand() % (DIMENSION_MAX - DIMENSION_MIN) + DIMENSION_MIN;
            length_2 *= shape_2[j];
        }

        Tensor * t1 = tensor_new(ndim_1, shape_1, sizeof(char), length_1);     
        Tensor * t2 = tensor_new(ndim_2, shape_2, sizeof(char), length_2);      

        if(t1 != NULL 
            && t2 != NULL)
        {
            CU_ASSERT_TRUE(
                (tensor_equal(t1, t1) == true)
                && (tensor_equal(t2,t2) == true));
             
            CU_ASSERT_TRUE(
                ((tensor_equal(t1, t2) == false)
                && (tensor_equal(t2, t1) == false))
             || ((tensor_equal(t1, t2) == true)
                && (tensor_equal(t2, t1)== true))); 
            
            tensor_delete(t2);
            tensor_delete(t1);
        }
        else
        {
           CU_FAIL("Tensor constructor error!");
        }

        free(shape_1);
        free(shape_2);
    }
}


static void
tensor_length_test(void)
{
    for(int i = 0; i < TEST_CYCLES; i ++)
    {
        size_t ndim = rand() % (NDIM_MAX-NDIM_MIN) + NDIM_MIN;
        size_t * shape = malloc(sizeof(size_t)*ndim);
        
        if(shape == NULL)
        {
            CU_ASSERT_PTR_NULL_FATAL("Malloc allocation error in shape preparing");  
            return;
        }

        size_t length = 1;

        for(size_t j = 0; j < ndim; j ++)
        {
            shape[j] = rand() % (DIMENSION_MAX - DIMENSION_MIN) + DIMENSION_MIN;
            length *= shape[j];
        }

        Tensor * tensor = tensor_new(ndim, shape, 1, length);
        
        if(tensor != NULL)
        {
            size_t t_length = tensor_length(tensor);

            /* non-zero test */
            if(ndim != 0
                && is_elem(0, ndim, shape) == false
                && t_length == 0)
            {
                CU_ASSERT_NOT_EQUAL(t_length, 0);
                return;
            }
            else
            {
                /* divisibility test */
                for(size_t j = 0; j < ndim; j++)
                {   
                    CU_ASSERT_EQUAL(t_length % shape[j], 0);
                }
            }
        }
        else
        {
           CU_FAIL("Tensor constructor error!");
        }
        
        free(shape);
    }    
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
    for(size_t i = 0; i < TEST_CYCLES; i++)
    {      
        size_t ndim = 1+(rand() % (NDIM_MAX-1));
        size_t * shape = malloc(sizeof(size_t)*ndim);
        
        if(shape == NULL)
        {
            CU_ASSERT_PTR_NULL_FATAL("Malloc allocation error in shape preparing");  
            return;
        }

        size_t length = 1;
        for(size_t j = 0; j < ndim; j ++)
        {
            shape[j] = 1 + (rand() % (DIMENSION_MAX-1));
            length *= shape[j];
        }

        Tensor * tensor = tensor_new(ndim, shape, sizeof(char), length);      
        
        if(tensor != NULL)
        {
            CU_ASSERT_EQUAL(tensor_ndim(tensor), ndim);
            
            tensor_delete(tensor);
        }
        else
        {
           CU_FAIL("Tensor constructor error!");
        }

        free(shape);
    }       
}


static void
tensor_shape_test(void)
{
    for(size_t i = 0; i < TEST_CYCLES; i++)
    {      
        size_t ndim = 1+(rand() % (NDIM_MAX-1));
        size_t * shape = malloc(sizeof(size_t)*ndim);
        
        if(shape == NULL)
        {
            CU_ASSERT_PTR_NULL_FATAL("Malloc allocation error in shape preparing");  
            return;
        }

        size_t length = 1;
        for(size_t j = 0; j < ndim; j ++)
        {
            shape[j] = 1 + (rand() % (DIMENSION_MAX-1));
            length *= shape[j];
        }

        Tensor * tensor = tensor_new(ndim, shape, sizeof(char), length);      
        
        if(tensor != NULL)
        {
            for(size_t j = 0; j < ndim; j++)
            {
                CU_ASSERT_EQUAL(tensor_shape(tensor)[j], shape[j]);
            }

            tensor_delete(tensor);
        }
        else
        {
           CU_FAIL("Tensor constructor error!");
        }

        free(shape);
    }       
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


/******************* test suit preparing ******************/
static int
init(void)
{
    srand(time(NULL));
    return 0;
}


static int
clean_up(void)
{
    return 0;
}

static void
show_ndim(Tensor * t)
{
    size_t * shape = tensor_shape(t);
    size_t ndim = tensor_ndim(t);

    printf("Ndim = %ld, ", ndim);
    printf("Shape {");

    for(size_t i = 0; i < ndim; i++)
    {
        if(i == 0)
            printf("%ld", shape[i]);
        else
            printf(", %ld", shape[i]);
    }
    printf("}\n");
}



CU_ErrorCode 
tensor_generic_test(void)
{
    CU_pSuite pSuite = 
        CU_add_suite("Tensor generic", init, clean_up);

    if(pSuite == NULL)
      return CU_get_error();

    if ((CU_add_test(pSuite, "tensor constructor and destructor", tensor_constructor_and_destructor_test) == NULL) 
        || (CU_add_test(pSuite, "tensor_count_length", tensor_count_length_test) == NULL)
        || (CU_add_test(pSuite, "tensor_copy", tensor_copy_test) == NULL)
        || (CU_add_test(pSuite, "tensor_equal", tensor_equal_test) == NULL)
        || (CU_add_test(pSuite, "tensor_length", tensor_length_test) == NULL)
        || (CU_add_test(pSuite, "tensor_reshape", tensor_reshape_test) == NULL)
        || (CU_add_test(pSuite, "tensor_byte_size", tensor_byte_size_test) == NULL)
        || (CU_add_test(pSuite, "tensor_ndim", tensor_ndim_test) == NULL)
        || (CU_add_test(pSuite, "tensor_shape", tensor_shape_test) == NULL)
        || (CU_add_test(pSuite, "tensor_data", tensor_data_test) == NULL)
        || (CU_add_test(pSuite, "tensor_byte_length", tensor_byte_length_test) == NULL))
   {
      return CU_get_error();
   }

    return CUE_SUCCESS;
}




