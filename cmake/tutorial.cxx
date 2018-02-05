/**
 * @brief A simple program that computes the square root of a number
 * @param argc bumber of parameters
 * @param argv parameter
 * @return 0 ture 1 false
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TutorialConfig.h"

int main(int argc, char* argv[])
{
  if (argc < 2)
  {
    fprintf(stdout, "%s Version %d.%d\n",
            argv[0],
            Tutorial_VERSION_MAJOR,
            Tutorial_VERSION_MINOR);
    fprintf(stdout, "Usage: %s number\n", argv[0]);
    return 1;
  }
  double inputValue = atof(argv[1]);
  double outputValue = sqrt(intputValue);
  fprintf(stdout, "The square root of %g is %g\n", inputValue, outputValue);
  return 0;
}
