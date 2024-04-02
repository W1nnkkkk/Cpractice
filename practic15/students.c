#include "students.h"

static int size = 0;

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

  file = fopen(PATH, "a");

  fwrite(tmp->family, sizeof(char[20]), 1, file);
  fwrite(tmp->name, sizeof(char[20]), 1, file);
  fwrite(tmp->gender, sizeof(char[1]), 1, file);
  fwrite(tmp->group, sizeof(char[7]), 1, file);
  fwrite(&tmp->age, sizeof(int), 1, file);
  fwrite(&tmp->mathMark, sizeof(int), 1, file);
  fwrite(&tmp->chemistryMark, sizeof(int), 1, file);
  fwrite(&tmp->physicsMark, sizeof(int), 1, file);

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

  f = fopen(PATH, "r");

  fseek(f, SIZE * size, SEEK_SET);
  fread(&tmp->family, sizeof(char[20]), 1, f);
  fread(&tmp->name, sizeof(char[20]), 1, f);
  fread(&tmp->gender, sizeof(char[1]), 1, f);
  fread(&tmp->group, sizeof(char[7]), 1, f);
  fread(&tmp->age, sizeof(int), 1, f);
  fread(&tmp->mathMark, sizeof(int), 1, f);
  fread(&tmp->chemistryMark, sizeof(int), 1, f);
  fread(&tmp->physicsMark, sizeof(int), 1, f);

  size++;

  fclose(f);

  return tmp;
}
