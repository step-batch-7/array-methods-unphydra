#include "array.h"

Array_ptr map(Array_ptr src, Mapper mapper)
{
  Array_ptr result = malloc(sizeof(Array));
  result->array = malloc(src->length*sizeof(int));
  result->length = src->length ? src->length:0;
  for (int i = 0; i < src->length; i++)
  {
    result->array[i] = (*mapper)(src->array[i]);
  }
  return result;
}