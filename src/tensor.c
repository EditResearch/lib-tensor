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


