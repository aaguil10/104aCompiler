//symboltable.h
#ifndef __SYMBOLTABLE_H__
#define __SYMBOLTABLE_H__

#include <stdio.h>

#include "astree.h"

#include <string>
#include <vector>
using namespace std;

extern FILE* sym_file;

struct symbol {
   int a;
   int b;
};

symbol* new_symbol (int _a, int _b);

#endif
