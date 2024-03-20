#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Students(stud) stud = stud_init(stud);

typedef struct students
{
  char family[20], name[20];
  char gender[2], group[7];
  int age, mathMark, physicsMark, chemistryMark;

  void *(*input)(void *);
  void *(*print)(void *);
} Students;

void *stud_input(void *stud);

void *stud_print(void *stud);

void *stud_init(void *stud);