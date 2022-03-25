#include "include/tensor.h"
#include <stdio.h>


const char * 
tensor_version(void)
{
    static char version[64] = {0};
	
    if(*version == 0)
    {
    	sprintf(
            version
            , "%d.%d.%d"
            , TENSOR_VERSION_MAJOR
            , TENSOR_VERSION_MINOR
            , TENSOR_VERSION_PATCH);
    }
    	
    return version;
}


Tensor(float) *
tensor_float_add_constant(
	Tensor(float) * t
	, float n)
{
	(void) t;
	(void) n;
	/* TODO: code here */
	return NULL;
}


Tensor(float) *
tensor_float_add(
	Tensor(float) * t1
	, Tensor(float) * t2)
{
	(void)t1;
	(void)t2;
	/* TODO: code here */
	return NULL;
}


Tensor(float) * 
tensor_float_dot(
	Tensor(float) * t1
	, Tensor(float) * t2)
{
	(void) t1;
	(void) t2;
	/* TODO: code here */
	return NULL;
}














