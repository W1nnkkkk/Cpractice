#ifndef STACK_H
#define STACK_H

#include "students.h"

typedef struct node
{
  Students *data;
  struct node *next;
} OBJ;

struct args
{
    OBJ* stack;
    struct students* stud;
};

void *clone_students(void *data);

void *push(void* args);

void *pop(void *top);

#endif // STACK_H