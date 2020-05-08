#ifndef __test_h
#define __test_h

#include "../array.h"

typedef char * String;
typedef enum
{
  Failure,
  Success
} Status;

int pass = 0;
int fail = 0;

Status compare_array(Array,Array);
void show_message(String,Status);
void show_length_failure(int, int);

#endif