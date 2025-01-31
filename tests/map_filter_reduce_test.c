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

void test_reduce_with_summation_of_number_reducer(void)
{
  Array input;
  int ar[] = {1,2,3,4,5};
  input.array = ar;
  input.length = 5;
  int actual = reduce(&input,0,test_reducer);
  int expected = 15; 
  Status s = compare_value(actual,expected);
  show_message("  should reduce and return total of given numbers in array",s);
}

void test_reduce(void)
{
  printf("\ntest reduce\n");
  test_reduce_with_zero_length_array();
  test_reduce_with_summation_of_number_reducer();
}

Object test_void_mapper(Object a)
{
  int * r = malloc(sizeof(int));
  *r = *(int*)a + 1;
  return r;
}

void test_map_void_with_zero_length_ArrayVoid(void)
{
  Object_ptr ar;
  ArrayVoid input;
  input.array = ar;
  input.length = 0;
  ArrayVoid_ptr actual = map_void(&input,test_void_mapper);
  Status s = compare_value(actual->length,0);
  show_message("  should give ArrayVoid of zero length if given ArrayVoid of zero length",s);
}

Status integers_validator(Object a, Object b)
{
  return *(int*)a == *(int*)b;
}

void test_map_void_with_integer_array(void)
{
  int ar[] = {1,2,3};
  Object ar_ptr[] = {&ar[0],&ar[1],&ar[2]};
  ArrayVoid input;
  input.array = ar_ptr;
  input.length = 3;
  ArrayVoid_ptr actual = map_void(&input,test_void_mapper);
  ar[0]++;
  ar[1]++;
  ar[2]++;
  Status s = compare_void_array(*actual,input,integers_validator);
  show_message("  should give ArrayVoid of integers array with maped if given ArrayVoid of integers",s);
}

Object test_void_mapper_char(Object a)
{
  char * r = malloc(sizeof(char));
  *r = *(char*)a - 32;
  return r;
}

Status char_validator(Object a,Object b)
{
  return *(char*)a == *(char*)b;
}

void test_map_void_with_charater_array(void)
{
  char ar[] = {'a','b','c'};
  Object ar_ptr[] = {&ar[0],&ar[1],&ar[2]};
  ArrayVoid input;
  input.array = ar_ptr;
  input.length = 3;
  ArrayVoid_ptr actual = map_void(&input,test_void_mapper_char);
  ar[0] = 'A';
  ar[1] = 'B';
  ar[2] = 'C';
  Status s = compare_void_array(*actual,input,char_validator);
  show_message("  should give ArrayVoid of characters array with maped if given ArrayVoid of characters",s);
}

void test_map_void(void)
{
  printf("\ntest map void\n");
  test_map_void_with_zero_length_ArrayVoid();
  test_map_void_with_integer_array();
  test_map_void_with_charater_array();
}

Bool test_void_filter(Object a)
{
  return *(int*)a >2;
}

void test_filter_void_with_zero_length_ArrayVoid(void)
{
  Object_ptr ar;
  ArrayVoid input;
  input.array = ar;
  input.length = 0;
  ArrayVoid_ptr actual = filter_void(&input,test_void_filter);
  Status s = compare_value(actual->length,0);
  show_message("  should give ArrayVoid of zero length if given ArrayVoid of zero length",s);
}

void test_filter_void_with_integer_array(void)
{
  int ar[] = {3,2,5};
  Object ar_ptr[] = {&ar[0],&ar[1],&ar[2]};
  ArrayVoid input;
  input.array = ar_ptr;
  input.length = 3;
  ArrayVoid_ptr actual = filter_void(&input,test_void_filter);
  int exp_ar[] = {3,5};
  Object exp_ar_ptr[] = {&exp_ar[0],&exp_ar[1]};
  ArrayVoid expected;
  expected.array = exp_ar_ptr;
  expected.length = 2;
  Status s = compare_void_array(*actual,expected,integers_validator);
  show_message("  should give ArrayVoid of integers array with filtered if given ArrayVoid of integers",s);
}

Bool test_void_filter_char(Object a)
{
  return *(char*)a > 96;
}

void test_filter_void_with_charater_array(void)
{
  char ar[] = {'a','B','c'};
  Object ar_ptr[] = {&ar[0],&ar[1],&ar[2]};
  ArrayVoid input;
  input.array = ar_ptr;
  input.length = 3;
  ArrayVoid_ptr actual = filter_void(&input,test_void_filter_char);
  ar[0] = 'a';
  ar[1] = 'c';
  input.length = 2;
  Status s = compare_void_array(*actual,input,char_validator);
  show_message("  should give ArrayVoid of characters array with filtered with lowercase if given ArrayVoid of characters",s);
}

void test_filter_void(void)
{
  printf("\ntest filter void\n");
  test_filter_void_with_zero_length_ArrayVoid();
  test_filter_void_with_integer_array();
  test_filter_void_with_charater_array();
}

Object test_void_reducer(Object a, Object b)
{
  int * r = malloc(sizeof(int));
  *r = *(int*)a + *(int*)b;
  return r;
}

void test_reduce_void_with_zero_length_ArrayVoid(void)
{
  Object_ptr ar;
  ArrayVoid input;
  input.array = ar;
  input.length = 0;
  int result = 0;
  Object actual = reduce_void(&input,&result,test_void_reducer);
  Status s = compare_value(*(int*)actual,0);
  show_message("  should give object of zero if given ArrayVoid of zero length and initial value is zero",s);
}

void  test_reduce_void_with_integers_ArrayVoid_to_get_sum(void)
{
  int ar[] = {3,2,5};
  Object ar_ptr[] = {&ar[0],&ar[1],&ar[2]};
  ArrayVoid input;
  input.array = ar_ptr;
  input.length = 3;
  int initial_value = 0;
  Object actual = reduce_void(&input,&initial_value, test_void_reducer);
  Status s = compare_value(*(int*)actual,10);
  show_message("  should give object of integer with reduced to sum of integers if given ArrayVoid of integers",s);
}

void test_reduce_void(void)
{
  printf("\ntest reduce void\n");
  test_reduce_void_with_zero_length_ArrayVoid();
  test_reduce_void_with_integers_ArrayVoid_to_get_sum();
}

int main(void)
{
  test_map();
  test_filter();
  test_reduce();
  test_map_void();
  test_filter_void();
  test_reduce_void();
  return 0;
}
