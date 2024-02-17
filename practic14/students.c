#include "students.h"

void *stud_input(void *stud)
{
  struct students *tmp = (struct students *)malloc(sizeof(struct students));
  struct students *original = stud;

  printf("Для начала введите анкетную информацию о студенте: ");
  printf("Фамилия, Имя: ");
  scanf("%s %s", tmp->family, tmp->name);
  printf("Пол, группа: ");
  scanf("%s %s", tmp->gender, tmp->group);
  printf("Возраст и оценки по математике, химии и физике: ");
  scanf("%d %d %d %d", &tmp->age, &tmp->mathMark, &tmp->chemistryMark, &tmp->physicsMark);

  *original = *tmp;
  free(tmp);

  return original;
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

  tmp->f = fopen(PATH, "r");
  tmp->input = stud_input;
  tmp->print = stud_print;

  return tmp;
}

void *studReadFromFile(void *stud)
{
  struct students *tmp = stud;

  fscanf(tmp->f, "%s", tmp->family);
  fscanf(tmp->f, "%s", tmp->name);
  fscanf(tmp->f, "%s", tmp->gender);
  fscanf(tmp->f, "%s", tmp->group);
  fscanf(tmp->f, "%d", &tmp->age);
  fscanf(tmp->f, "%d", &tmp->mathMark);
  fscanf(tmp->f, "%d", &tmp->chemistryMark);
  fscanf(tmp->f, "%d", &tmp->physicsMark);

  return tmp;
}

void *stud_destroy(void *stud)
{
  struct students *tmp = stud;
  fclose(tmp->f);
  return tmp;
}
