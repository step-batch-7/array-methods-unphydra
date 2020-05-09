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

ArrayVoid_ptr filter_void(ArrayVoid_ptr src, PredicateVoid predicate)
{
  ArrayVoid_ptr result = malloc(sizeof(ArrayVoid));
  result->array = malloc(sizeof(Object)*src->length);
  int count = 0;
  for (int i = 0; i < src->length; i++)
  {
    if ((*predicate)(src->array[i]))
    {
    result->array[count++] = src->array[i];
    }
  }
  result->length = count;
  return result;
}

Object reduce_void(ArrayVoid_ptr src, Object init, ReducerVoid reducer)
{
  Object result = init;
  for (int i = 0; i < src->length; i++)
  {
    result = (*reducer)(result,src->array[i]);
  }
  return result;
}
