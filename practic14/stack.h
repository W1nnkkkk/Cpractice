#ifndef STACK_H
#define STACK_H

#include "students.h"

typedef struct node
{
  Students *data;
  struct node *next;

  void *(*push)(void *);
  void *(*pop)(void *);
} Stack;

struct args
{
  Stack *stack;
  struct students *stud;
};

void *stackInit(void *stack);

void *clone_students(void *data);

void *push(void *args);

void *pop(void *top);

#endif // STACK_H