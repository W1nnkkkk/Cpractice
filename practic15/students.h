#ifndef STUDENTS_H
#define STUDENTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PATH "test.txt"
#define Students(stud) stud = stud_init(stud)
#define SIZE sizeof(char[20]) + sizeof(char[20]) + sizeof(char[1]) + sizeof(char[7]) + sizeof(int) + sizeof(int) + sizeof(int) + sizeof(int)

typedef struct students
{
  char family[20], name[20], gender[2], group[7];
  int age, mathMark, physicsMark, chemistryMark;

  void *(*input)(void *);
  void *(*print)(void *);
} Students;

void *stud_input(void *stud);

void *stud_print(void *stud);

void *stud_init(void *stud);

void *studReadFromFile(void *stud);

#endif // STUDENTS_H