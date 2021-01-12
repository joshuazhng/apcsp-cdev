#include <stdio.h>
#include <string.h>


// student structure
struct Student {
  char firstName[100];
  char lastName[100];
  int age;
  int studentId;
};

void printStudent(struct Student* student)
{
  printf("  Name: %s %s", student->firstName, student->lastName);
  printf("  Age: %d\n", student->age);
  printf("  Student ID: %d\n", student->studentId);
}


void printAllStudents(struct Student students[], int num)
{
  // call printStudent for each student in students
  if (num == 0)
  {
    printf("There are no students in the system yet.\n");
  }

  for (int i = 0; i < num; i++)
  {
    printf("----- Student %d Information -----\n", i);
    printStudent(students+i);
  }
}


int main()
{

  // an array of students
  //xxx students;
  struct Student students[1000];

  int numStudents = 0;
  char input[256];

  while (1)
  {
    char c;
    printf("\nEnter a to add, p to print, q to quit: ");
    fgets(input, 256, stdin);
    if (sscanf(input, "%c", &c) != 1) continue;
    if (c == 'q') 
    {
      break;
    }
    else if (c == 'p')
    {
      // print all students
      printAllStudents(students, numStudents);
      continue;
    }
    else if (c == 'a')
    {
      // enter a new student
      printf("Input student's first name: ");
      fgets(input, 256, stdin);
      int count = strlen(input) - 1;
      strncpy(students[numStudents].firstName, input, count);

      printf("Input student's last name: ");
      fgets(input, 256, stdin);
      strcpy(students[numStudents].lastName, input);

      int age = -1;
      while (age < 1)
      {
        printf("Input student's age: ");
        fgets(input, 256, stdin);
        sscanf(input, "%d", &age);
        if (age < 1)
        {
          printf("Age cannot be less than 1.\n");
        }
        else
          students[numStudents].age = age;
      }

      int studentId = -1;
      while (studentId < 1)
      {
        printf("Input student's student ID: ");
        fgets(input, 256, stdin);
        sscanf(input, "%d", &studentId);
        if (studentId < 1)
        {
          printf("Student ID cannot be less than 1.\n");
        }
        else
          students[numStudents].studentId = studentId;
      }

      numStudents++;
    }
  }
  
  printf("\nGoodbye!\n");
}
