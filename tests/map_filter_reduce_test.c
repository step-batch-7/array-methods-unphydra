#include "test.h"

int test_mapper(int a)
{
  return a+1;
}

void test_map_with_increment_mapper(void)
{
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
  show_message("  should map increment each value in array",s);
}

void test_map_with_zero_length_array(void)
{
  Array input;
  int ar[] = {};
  input.array = ar;
  input.length = 0;
  Array_ptr actual = map(&input,test_mapper);
  Array expected;
  int exp_ar[] ={};
  expected.array = exp_ar;
  expected.length = 0;
  Status s = compare_array(*actual,expected);
  show_message("  should map and return empty array for given empty array",s);
}
void test_map(void)
{
  printf("test map\n");
  test_map_with_increment_mapper();
  test_map_with_zero_length_array();
}

int main(void)
{
  test_map();
  return 0;
}
