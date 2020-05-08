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
  printf("\ntest map\n");
  test_map_with_increment_mapper();
  test_map_with_zero_length_array();
}

Bool test_predicate(int a){
  return True;
}

void test_filter_with_zero_length_array(void)
{
  Array input;
  int ar[] = {};
  input.array = ar;
  input.length = 0;
  Array_ptr actual = filter(&input,test_predicate);
  Array expected;
  int exp_ar[] ={};
  expected.array = exp_ar;
  expected.length = 0;
  Status s = compare_array(*actual,expected);
  show_message("  should filter and return empty array for given empty array",s);
}

Bool is_even(int a)
{
  return a%2==0;
}

void test_filter_with_is_even_predicate(void)
{
  Array input;
  int ar[] = {1,2,3,4};
  input.array = ar;
  input.length = 4;
  Array_ptr actual = filter(&input,is_even);
  Array expected;
  int exp_ar[] ={2,4};
  expected.array = exp_ar;
  expected.length = 2;
  Status s = compare_array(*actual,expected);
  show_message("  should filter and return even array for given numbers array",s);
}


void test_filter(void)
{
  printf("\ntest map\n");
  test_filter_with_zero_length_array();
  test_filter_with_is_even_predicate();
}

int test_reducer(int a, int b)
{
  return a+b;
}

void test_reduce_with_zero_length_array(void)
{
  Array input;
  int ar[] = {};
  input.array = ar;
  input.length = 0;
  int actual = reduce(&input,0,test_reducer);
  int expected = 0; 
  Status s = compare_value(actual,expected);
  show_message("  should reduce and return initial value for given empty array",s);
}

void test_reduce(void)
{
  printf("\ntest reduce\n");
  test_reduce_with_zero_length_array();
}

int main(void)
{
  test_map();
  test_filter();
  test_reduce();
  return 0;
}
