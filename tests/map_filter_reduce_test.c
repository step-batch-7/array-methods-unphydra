#include "test.h"

int test_mapper(int a)
{
  return a+1;
}

void test_map(void)
{
  printf("test map\n");
  Array input;
  int ar[] = {1,2,3};
  input.array = ar;
  input.length = 3;
  Array_ptr actual = map(&input,test_mapper);
  Array expected;
  int exp_ar[] ={2,3,4};
  expected.array = exp_ar;
  expected.length = 3;
  Status s = compare_array(*actual,expected);
  show_message("should map increment each value in array",s);
}

int main(void)
{
  test_map();
  return 0;
}
