#ifndef __test_h
#define __test_h

#include "../array_void.h"

typedef char * String;
typedef enum
{
  Failure,
  Success
} Status;

typedef Status (*validator_ptr)(Object,Object);

Status compare_array(Array,Array);
void show_message(String,Status);
void show_length_failure(int, int);
Status compare_value(int,int);
Status compare_void_array(ArrayVoid,ArrayVoid,validator_ptr);

#endif