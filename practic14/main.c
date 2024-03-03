#include "stack.h"

#define STUD struct students
#define CHECK(ag1, ag2)                                                                \
  ({                                                                                   \
    int result = (args.stack->data->age >= (ag1) && args.stack->data->age <= (ag2)); \
    result;                                                                            \
  })

int main(int argc, char const *argv[])
{
  printf("Напишите кол-во студентов которых хотите добавить: ");
  unsigned int n = 0;
  scanf("%d", &n);

  STUD *stud = (STUD*) malloc(sizeof(STUD));
  stud = stud_init(stud);
  stud = openForReading(stud);
  Stack *stack = (Stack*) malloc(sizeof(Stack));
  stack = stackInit(stack);


   struct args args;
   args.stack = stack;
   args.stud = stud;

   for (int i = 0; i < n; ++i)
   {
     args.stud = studReadFromFile(args.stud);
     args.stack = push(&args);
   }

   for (int i = 0; i < n; ++i)
   {
     if (CHECK(16, 18))
     {
       printf("%s %s %d\n", args.stack->data->family, args.stack->data->name, args.stack->data->age);
     }
     args.stack = pop(args.stack);
   }

  stud_destroy(stud);

  return 0;
};