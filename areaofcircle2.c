#include <stdio.h>
#include <math.h>

// for testing only - do not change
int getTestInput(int argc, char* argv[], float* a, float* b)
{
  if (argc == 3)
  {
    if (sscanf(argv[1], "%f", a) == 0)
    {
      return 1;
    }
    if (sscanf(argv[2], "%f", b) == 0)
    {
      return 1;
    }
  }
  return 0;
}

// add your areaOfCircle function here - it must NOT printf, instead it must
// return the result to be printed in main
float areaOfCircle(float start)
{
	float area = start * start * M_PI;
	return area;
}

int main(int argc, char* argv[]) 
{
  // the two variables which control the number of times areaOfCircle is called
  float start = -1.0;
  float end = -1.0;

  if (argc == 3)
  {
    int returnCode = getTestInput(argc, argv, &start, &end);

    if (returnCode == 1)
    {
      printf("One or more inputs are not floats.\n");
    }
    else if (start < 0)
    {
      printf("The lower radius is not positive.\n");
    }
    else if (end < start)
    {
      printf("The upper radius is less than the lower radius.\n");
    }
  }

  char input[256];

  while (start < 0)
  {
    printf("Please input lowest radius: ");
    fgets(input, 256, stdin);
    sscanf(input, "%f", &start);
    if (start < 0)
    {
      printf("Please input a positive number.\n");
    }
  }

  while (end < start)
  {
    printf("Please input upper radius: ");
    fgets(input, 256, stdin);
    sscanf(input, "%f", &end);
    if(end < start)
  	printf("Please input a larger number than the lowest radius for the upper radius\n");
  }

  printf("calculating area of circle starting at %f, and ending at %f\n", start, end);

  // add your code below to call areaOfCircle function with values between
  // start and end
  while (start < end+0.000000000001)
  {
	float area;
	area = areaOfCircle(start);
	printf("for radius %f, area is %f\n", start, area);
	start += 1.0;
  }
}
