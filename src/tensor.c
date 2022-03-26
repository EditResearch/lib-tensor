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
tensor_float_const_add(
	Tensor(float) * t
	, float n)
{
	(void) t;
	(void) n;
	/* TODO: code here */
	return NULL;
}


Tensor(int8_t) *
tensor_int8_const_add(
	Tensor(int8_t) * t
	, int8_t n)
{
	(void) t;
	(void) n;
	/* TODO: code here */
	return NULL;
}


Tensor(uint8_t) *
tensor_uint8_const_add(
	Tensor(uint8_t) * t
	, uint8_t n)
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


Tensor(int8_t) *
tensor_int8_add(
	Tensor(int8_t) * t1
	, Tensor(int8_t) * t2)
{
	(void)t1;
	(void)t2;
	/* TODO: code here */
	return NULL;
}


Tensor(uint8_t) *
tensor_uint8_add(
	Tensor(uint8_t) * t1
	, Tensor(uint8_t) * t2)
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


Tensor(int8_t) * 
tensor_int8_dot(
	Tensor(int8_t) * t1
	, Tensor(int8_t) * t2)
{

    (void)t1;
    (void)t2;
    /*TODO: code here*/
    return NULL;
}


Tensor(uint8_t) * 
tensor_uint8_dot(
	Tensor(uint8_t) * t1
	, Tensor(uint8_t) * t2)
{
    (void)t1;
    (void)t2;
    /*TODO: code here*/
    return NULL;
}


Tensor(float) * 
tensor_float_multiply(
    Tensor(float) * t1
    , Tensor(float) * t2)
{
    (void)t1;
    (void)t2;

    /* TODO: code here */    
    return NULL;
}


Tensor(float) *
tensor_float_const_multiply(
    Tensor(float) * t
    , float n)
{
    (void) t;
    (void) n;

    /* TODO: code here */
    return NULL;        
}


Tensor(int8_t) *
tensor_int8_const_multiply(
    Tensor(int8_t) * t
    , int8_t n)
{
    (void) t;
    (void) n;

    /* TODO: code here */
    return NULL;        
}


Tensor(uint8_t) *
tensor_uint8_const_multiply(
    Tensor(uint8_t) * t
    , uint8_t n)
{
    (void) t;
    (void) n;

    /* TODO: code here */
    return NULL;        
}







