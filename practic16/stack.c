#include "stack.h"

void *clone_students(void *data)
{
  struct students *original = (struct students *)data;
  struct students *clone = (struct students *)malloc(sizeof(struct students));

  strcpy(clone->family, original->family);
  strcpy(clone->name, original->name);
  strcpy(clone->gender, original->gender);
  strcpy(clone->group, original->group);
  clone->age = original->age;
  clone->mathMark = original->mathMark;
  clone->physicsMark = original->physicsMark;
  clone->chemistryMark = original->chemistryMark;

  return clone;
}

void *push(void* args)
{
  Stack *new = (Stack *)malloc(sizeof(Stack));

  if (!new) {
      fprintf(stderr, "Ошибка в выделении памяти (22 строка stack.c): %s\n", strerror(errno));
  }

  struct args* _arg = args;

  new->data = clone_students(_arg->stud);
  new->next = _arg->stack;

  return new;
}

void *pop(void *top)
{
    Stack *tmp = top;
  if (tmp == NULL)
    return tmp;

  Stack *next = tmp->next;
  free(top);
  return next;
}