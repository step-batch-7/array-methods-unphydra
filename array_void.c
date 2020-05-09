#include "array_void.h"

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper)
{
  ArrayVoid_ptr result = malloc(sizeof(ArrayVoid));
  result->length = src->length;
  result->array = malloc(sizeof(Object)*result->length);
  for (int i = 0; i < src->length; i++)
  {
    result->array[i] = (*mapper)(src->array[i]);
  }
  return result;
}