//symboltable.cpp

#include "symboltable.h"

extern FILE* sym_file;
symbol_table typenames_table;
int next_block;

symbol* new_symbol (size_t filenr, size_t linenr,
                    size_t offset, size_t block_nr){
   symbol* mySym = new symbol();
   mySym->attr = 0;
   mySym->fields = 0;
   mySym->filenr = filenr;
   mySym->linenr = linenr;
   mySym->offset = offset;
   mySym->block_nr = next_block;
   mySym->parameters = NULL;
   //fprintf(sym_file, "Made new symbol: attr(%p) b(%p)\n", mySym->attr, mySym->fields); 
   return mySym;
}

void make_struct(string* key, symbol* obj){
   typenames_table[key] = obj;
}
