//symboltable.cpp

#include "symboltable.h"

extern FILE* sym_file;
//int next_block;

symbol* new_symbol (size_t filenr, size_t linenr,
                    size_t offset, size_t block_nr){
   symbol* mySym = new symbol();
   mySym->attr = 0;
   mySym->fields = 0;
   mySym->filenr = filenr;
   mySym->linenr = linenr;
   mySym->offset = offset;
   mySym->block_nr = block_nr;
   mySym->parameters = NULL;
   //fprintf(sym_file, "Made new symbol: attr(%p) b(%p)\n", mySym->attr, mySym->fields); 
   return mySym;
}


