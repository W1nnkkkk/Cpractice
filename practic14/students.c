#include "students.h"

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

  studWriteToFile(tmp);

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
  struct students *tmp = stud;

  tmp->input = stud_input;
  tmp->print = stud_print;

  return tmp;
}

void *studWriteToFile(void *stud)
{
  struct students *tmp = stud;

  FILE *file = fopen(PATH, "a");

  fprintf(file, "%s", tmp->family);
    fprintf(file, "%c", ' ');
  fprintf(file, "%s", tmp->name);
    fprintf(file, "%c", ' ');
  fprintf(file, "%s", tmp->gender);
    fprintf(file, "%c", ' ');
  fprintf(file, "%s", tmp->group);
    fprintf(file, "%c", ' ');
  fprintf(file, "%d", tmp->age);
    fprintf(file, "%c", ' ');
  fprintf(file, "%d", tmp->mathMark);
    fprintf(file, "%c", ' ');
  fprintf(file, "%d", tmp->chemistryMark);
    fprintf(file, "%c", ' ');
  fprintf(file, "%d", tmp->physicsMark);
    fprintf(file, "%s", "\n");

  fclose(file);

  return tmp;
}

void *openForReading(void* stud)
{
    struct students *tmp = stud;

    tmp->f = fopen(PATH, "r");

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
