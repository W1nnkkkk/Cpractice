#include "stack.h"

#define STUD struct students
#define CHECK(ag1, ag2) _args.stack->data->age >= ag1 && _args.stack->data->age <= ag2

int main(int argc, char const *argv[])
{
  printf("Напишите кол-во студентов которых хотите добавить: ");
  unsigned int n = 0;
  scanf("%d", &n);

  STUD *stud = NULL;
  Students(stud);
  OBJ *stack = NULL;

  struct args _args;
  _args.stack = stack;
  _args.stud = stud;

  for (int i = 0; i < n; ++i)
  {
    _args.stud = stud_input(_args.stud);
    _args.stack = push(&_args);
  }

  for (int i = 0; i < n; ++i)
  {
    if (CHECK(16, 18))
    {
      printf("%s %s %d\n", _args.stack->data->family, _args.stack->data->name, _args.stack->data->age);
    }
    _args.stack = pop(_args.stack);
  }

  return 0;
};