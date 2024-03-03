#include "students.h"

static int i = 0;

void *stud_input(void *stud)
{
  struct students *tmp = stud;

  printf("Для начала введите анкетную информацию о студенте: ");
  printf("Фамилия, Имя: ");
  scanf("%s %s", tmp->family, tmp->name);
  printf("Пол, группа: ");
  scanf("%s %s", tmp->gender, tmp->group);
  printf("Возраст и оценки по математике, химии и физике: ");
  scanf("%d %d %d %d", &tmp->age, &tmp->mathMark, &tmp->chemistryMark, &tmp->physicsMark);

  FILE *file;

  file = fopen("test.txt", "a");

  fwrite(tmp, 1, sizeof(*tmp), file);

  fclose(file);

  return tmp;
}

void *stud_print(void *stud)
{
  struct students *tmp = stud;
  printf("Анкетные данные студента: ");
  printf(" Фамилия, Имя: ");
  printf("%s %s", tmp->family, tmp->name);
  printf(" Пол, группа: ");
  printf("%s %s", tmp->gender, tmp->group);
  printf(" Возраст и оценки по математике, химии и физике: ");
  printf("%d %d %d %d", tmp->age, tmp->mathMark, tmp->chemistryMark, tmp->physicsMark);
  printf("\n");
  return NULL;
}

void *stud_init(void *stud)
{
  stud = (struct students *)malloc(sizeof(struct students));
  struct students *tmp = stud;

  tmp->input = stud_input;
  tmp->print = stud_print;

  return tmp;
}

void *studReadFromFile(void *stud)
{
  struct students *tmp = stud;

  FILE *f;

  f = fopen("test.txt", "r");

  fseek(f, sizeof(*tmp) * i, SEEK_SET);
  fread(tmp, sizeof(*tmp), 1, f);

  ++i;

  fclose(f);

  return tmp;
}
