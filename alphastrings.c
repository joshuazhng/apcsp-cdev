#include <stdio.h>
#include <string.h>

int main()
{
  char string1[27];
  for(int i = 0; i < 26; i++)
  {
  	string1[i] = i+97;
  }
  string1[26] = '\0';

  char string2[] = "abcdefghijklmnopqrstuvwxyz";

  if (strcmp(string1, string2) == 0)
  	printf("the strings are the same\n");
  else
  	printf("the strings are different\n");

  for(int i = 0; i < 26; i++)
  {
  	string1[i] -= 32;
  }

  if (strcmp(string1, string2) == 0)
        printf("the strings are the same\n");
  else
        printf("the strings are different\n");

  char string3[52];
  strcat(string3, string1);
  strcat(string3, string2);

  printf("String 1: %s\nString 2: %s\nString3: %s\n", string1, string2, 
  string3); 
}

