//symboltable.cpp

#include "symboltable.h"

extern FILE* sym_file;


symbol* new_symbol (int _a, int _b){
   symbol* mySym = new symbol();
   mySym->attr = 0;
   mySym->fields = 0;
   mySym->filenr = 0;
   mySym->linenr = 0;
   mySym->offset = 0;
   mySym->block_nr = 0;
   mySym->parameters = NULL;
   //fprintf(sym_file, "Made new symbol: attr(%p) b(%p)\n", mySym->attr, mySym->fields); 
   return mySym;
}


