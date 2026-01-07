#include <stdio.h>
#include <string.h>

#define LEN 128

void reverse_name(char *name);

int main (void)
{
  char name[LEN], temp[LEN/2];

  printf("Enter a first and last name: ");
  scanf("%63s%64s", name, temp);

  strcat(name, " ");
  strcat(name, temp);
  reverse_name(name);
  printf("%s\n", name);

  return 0;
}

void reverse_name(char *name)
{
  char temp[LEN];
  char suffix[] = ", X.";
  char *p = name, *q = temp;

  while (*p++ != ' ')
    ;
  while ((*q++ = *p++))
    ;
  strcpy(name, temp);
  suffix[2] = name[0];
  strcat(name, suffix);
}
