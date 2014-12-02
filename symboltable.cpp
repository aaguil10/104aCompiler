//symboltable.cpp

#include "symboltable.h"

extern FILE* sym_file;
symbol_table typenames_table;
symbol_table ident_table;
int next_block;

symbol* new_symbol (size_t filenr, size_t linenr, size_t offset, 
                    attr_bitset a, symbol_table* f){
   symbol* mySym = new symbol();
   mySym->attr = a;
   mySym->fields = f;
   mySym->filenr = filenr;
   mySym->linenr = linenr;
   mySym->offset = offset;
   mySym->block_nr = next_block;
   mySym->parameters = NULL;
   //fprintf(sym_file, "Made new symbol: attr(%p) b(%p)\n", mySym->attr, mySym->fields); 
   return mySym;
}

void insert_struct(string* key, symbol* obj){
   //typenames_table[key] = obj;
}

void insert_ident(string* key, symbol* obj){
   printf("OHHHHH\n");
   //ident_table[key] = obj;
   symbol_entry e = {key, obj};
   ident_table.insert(e);
   std::cout << "mymap.size() is " << ident_table.size() << std::endl;
}

void print_table(string s, symbol_table mymap){
  std::cout << s << " contains:";
  for ( auto it = mymap.begin(); it != mymap.end(); ++it )
    std::cout << " " << *(it->first) << ":" << (it->second);
  std::cout << std::endl;

  std::cout << s <<"'s buckets contain:\n";
  for ( unsigned i = 0; i < mymap.bucket_count(); ++i) {
    std::cout << "bucket #" << i << " contains:";
    for ( auto local_it = mymap.begin(i); local_it!= mymap.end(i); ++local_it )
      std::cout << " " << *(local_it->first) << ":" << (local_it->second);
    std::cout << std::endl;
  }

}
