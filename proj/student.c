//
// student.c
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "encrypt.h"

const char* STUFILE = "studentdata.txt";

// keeps track of the number of students in the students array
int numStudents = 0;

// holds the student pointer array
Student* students[100] = {0};


void createStudent(char* fname, char* lname, int age, int id)
{
  // createStudent dynamically creates a Student on the heap and adds that
  // student to the student array
  //  - the firstName and lastName strings should be dynamically created
  //    based on the size of the fname and lname args
  Student* st = (Student*)malloc(sizeof(Student));

  int count = strlen(fname) + 1;
  char* name = (char*)malloc(count * sizeof(char));
  strncpy(name, fname, count);
  st->firstName = name;

  count = strlen(lname) + 1;
  name = (char*)malloc(count * sizeof(char));
  strncpy(name, lname, count);
  st->lastName = name;

  st->age = age;
  st->id = id;

  students[numStudents] = st;

  numStudents++;
}


void deleteStudent(Student* student)
{
  // free the memory associated with a student including the strings
  free(student->firstName);
  free(student->lastName);
  free(student);
}


void deleteStudents()
{
  // iterate over the students array deleting every student and setting te pointer
  // values to 0 and adjusting the numStudents to 0
  for (int i = 0; i < numStudents; i++)
  {
    deleteStudent(students[i]);
    students[i] = 0;
  }
  numStudents = 0;
}


void saveStudents(int key)
{
  // save all students in the student array to a file 'studentdata.txt' overwriting
  // any existing file
  //   - the format of the file is one line per student as follows fname lname age id:
  //       tom thumb 15 1234
  //       james dean 21 2345
  //       katy jones 18 4532
  FILE* fp;

  fp = fopen(STUFILE, "w");
  if (fp)
  {
    char buffer[1024];
    for (int i = 0; i < numStudents; i++)
    {
      Student* st = students[i];
      sprintf(buffer, "%s %s %d %ld", st->firstName, st->lastName, st->age, st->id);
      caesarEncrypt(buffer, key);
      fprintf(fp, "%s\n", buffer);
      printf("saving %s\n", buffer);
    }
    printf("saved %d students\n", numStudents);
    fclose(fp);
  }
}


void loadStudents(int key)
{
  deleteStudents();

  // load the students from the data file overwriting all exisiting students in memory
  FILE* fp;

  fp = fopen(STUFILE, "r");
  if (fp)
  {
    char fbuffer[256];
    char lbuffer[256];
    char agebuffer[256];
    char idbuffer[256];
    int age;
    int id;
    while (1)
    {
      if (fscanf(fp, "%s %s %s %s\n", fbuffer, lbuffer, agebuffer, idbuffer) == 4)
      {
        caesarDecrypt(fbuffer, key);
        caesarDecrypt(lbuffer, key);
        caesarDecrypt(agebuffer, key);
        caesarDecrypt(idbuffer, key);
        age = atoi(agebuffer);
        id = atoi(idbuffer);
        createStudent(fbuffer, lbuffer, age, id);
      }
      else
        break;
    }
    fclose(fp);
  }

  printf("loaded %d students\n", numStudents);
}


void printStudent(Student* student)
{
  printf("  Student: %s %s\n", student->firstName, student->lastName);
  printf("    age: %d\n", student->age);
  printf("    id: %ld\n", student->id); 
}


void printStudents()
{
  for (int i = 0; i < numStudents; i++) {
    printf("\n----- student %d ------\n", i);
    printStudent(students[i]);
  }
}




