//symboltable.cpp

#include "symboltable.h"

extern FILE* sym_file;

symbol* new_symbol (int _a, int _b){
   symbol* mySym = new symbol();
   mySym->a = _a;
   mySym->b = _b;
   fprintf(sym_file, "Made new symbol: a(%d) b(%d)\n", mySym->a, mySym->b); 
   return mySym;
}


