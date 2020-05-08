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

Array_ptr filter(Array_ptr src, Predicate predicate)
{
  Array_ptr result = malloc(sizeof(Array_ptr));
  result->array = malloc(src->length *sizeof(int));
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

int reduce(Array_ptr src, int init, Reducer reducer)
{
  int result = init;
  for (int i = 0; i < src->length; i++)
  {
    result = (*reducer)(result,src->array[i]);
  }
  return result;
}
