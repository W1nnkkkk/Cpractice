#ifndef STUDENTS_H
#define STUDENTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PATH "test.txt"

typedef struct students
{
  char family[20], name[20], gender[2], group[7];
  int age, mathMark, physicsMark, chemistryMark;
  FILE *f;

  void *(*input)(void *);
  void *(*print)(void *);
} Students;

void *stud_input(void *stud);

void *stud_print(void *stud);

void *stud_init(void *stud);

void *studWriteToFile(void *stud);

void *openForReading(void* stud);

void *studReadFromFile(void *stud);

void *stud_destroy(void *stud);

#endif // STUDENTS_H