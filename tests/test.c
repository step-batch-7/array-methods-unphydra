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

void show_message(String msg, Status s)
{
  s?pass++:fail++;
  printf("%s => %s\n",msg,s?"pass":"fails");
}

void show_length_failure(int a, int b)
{
  printf("\nactual=> %d\nexpected=>%d\n",a,b);
}
