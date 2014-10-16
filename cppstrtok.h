#ifndef __CPPSTRTOK__
#define __CPPSTRTOK__

#include <string>
#include <errno.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wait.h>
using namespace std;

#include "auxlib.h"

void chomp (char* string, char delim);

void cpplines (FILE* pipe, char* filename);

#endif

