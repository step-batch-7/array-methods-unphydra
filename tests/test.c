#include "test.h"

void show_message(String msg, Status s)
{
  printf("%s => %s\n",msg,s?"pass":"fails");
}

void show_length_failure(int a, int b)
{
  printf("\nactual=> %d\nexpected=>%d\n",a,b);
}

Status compare_array(Array actual,Array expected)
{
  if (actual.length != expected.length)
  {
    show_length_failure(actual.length,expected.length);
    return Failure;
  }
  Status s = Success;
  for (int i = 0; i < expected.length; i++)
  {
    s =s && actual.array[i] == expected.array[i];
  }
  return s;
}

Status compare_value(int a,int e)
{
  if (a != e)
  {
    show_length_failure(a,e);
    return Failure;
  }
  return Success;
}