#include "stack.h"


#define STUD struct students
#define CHECK(ag1, ag2)                                                                \
  ({                                                                                   \
    typeof(ag1) _ag1 = ag1;                                                             \
    typeof(ag2) _ag2 = ag2;                                                              \
    int result = (args.stack->data->age >= (_ag1) && args.stack->data->age <= (_ag2)); \
    result;                                                                            \
  })

int main(int argc, char const *argv[])
{
    printf("Напишите кол-во студентов которых хотите добавить: ");
    unsigned int n = 0;
    scanf("%d", &n);

    STUD *stud = NULL;
    Students(stud);
    Stack *stack = NULL;


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

    return 0;
};