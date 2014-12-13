//symboltable.cpp

#include "symboltable.h"

extern FILE* sym_file;
symbol_table typenames_table;
symbol_table ident_table;
vector<symbol_table*> symbol_stack;
int next_block;



void print_attributes(FILE* outfile, const attr_bitset& attr, char* type) {
   if(attr[ATTR_void]){ fprintf(outfile, "void "); }
   if(attr[ATTR_bool]){ fprintf(outfile, "bool "); }
   if(attr[ATTR_char]){ fprintf(outfile, "char "); }
   if(attr[ATTR_int]){ fprintf(outfile, "int "); }
   if(attr[ATTR_null]){ fprintf(outfile, "NULL "); }
   if(attr[ATTR_string]){ fprintf(outfile, "string "); }
   if(attr[ATTR_struct]){ fprintf(outfile, "struct "); }
   if(attr[ATTR_array]){ fprintf(outfile, "array "); }
   if(attr[ATTR_function]){ fprintf(outfile, "function "); }
   if(attr[ATTR_variable]){ fprintf(outfile, "variable "); }
   if(attr[ATTR_field]){ fprintf(outfile, "field "); }
   if(attr[ATTR_typeid]){
      //fprintf(outfile, "typeid ");
      fprintf(outfile, "%s ", type); 
   }
   if(attr[ATTR_param]){ fprintf(outfile, "param "); }
   if(attr[ATTR_const]){ fprintf(outfile, "const "); }
   if(attr[ATTR_vreg]){ fprintf(outfile, "vreg "); }
   if(attr[ATTR_lval]){ fprintf(outfile, "lval "); }
   if(attr[ATTR_vaddr]){ fprintf(outfile, "vaddr "); }
}


symbol* new_symbol (size_t filenr, size_t linenr, size_t offset, 
                    size_t block_nr, attr_bitset a, symbol_table* f){
   symbol* mySym = new symbol();
   mySym->attr = a;
   mySym->fields = f;
   mySym->filenr = filenr;
   mySym->linenr = linenr;
   mySym->offset = offset;
   mySym->block_nr = block_nr;
   mySym->parameters = NULL;
   //fprintf(sym_file, "Made new symbol: attr(%p) b(%p)\n", mySym->attr, mySym->fields); 
   return mySym;
}

void print_symbol(string* key, symbol* obj) {//std::cout << "PRINT CALLED" << std::endl;
   for ( unsigned i = 1; i < symbol_stack.size(); ++i){
      fprintf(sym_file, "   ");
   }
   fprintf(sym_file, "%s (%ld.%ld.%ld) {%ld} ", key->c_str(),
           obj->filenr, obj->linenr, obj->offset, obj->block_nr);
   print_attributes(sym_file, obj->attr, (char*)key);
   fprintf(sym_file, "\n");

   if (obj->parameters != NULL) {
      for (unsigned i = 0; i < obj->parameters->size(); i++) {
         for ( unsigned j = 0; j < symbol_stack.size(); ++j){
            fprintf(sym_file, "   ");
         }

         symbol* param = (*(obj->parameters))[i];
         fprintf(sym_file, "%s (%ld.%ld.%ld) {%ld} ", key->c_str(),
                 param->filenr, param->linenr, param->offset,
                 param->block_nr);
         print_attributes(sym_file, param->attr);
         fprintf(sym_file, "\n");
      }
   }
}

void insert_struct(string* key, symbol* obj){
   if(obj == NULL){ 
      fprintf(stderr,"ERROR: obj == NULL on insert_struct()");
   }
   print_symbol(key, obj);
   symbol_entry e = {key, obj};
   typenames_table.insert(e);
}

void insert_ident(string* key, symbol* obj){
   if(obj == NULL){ 
      fprintf(stderr,"ERROR: obj == NULL on insert_ident()");
   }
   print_symbol(key, obj);
   symbol_entry e = {key, obj};
   symbol_table* curr = symbol_stack[symbol_stack.size()-1];
   if(curr == NULL){
      //printf("   Making New Symbol table.\n");
      symbol_table* tmp = new symbol_table;
      tmp->insert(e);
      symbol_stack[symbol_stack.size()-1] = tmp;
   }else{
      (*curr).insert(e);
      //printf("   inserting to curr symbol table.\n");
   }
}

void insert_field(symbol* stru, string* key, symbol* obj){
   if(obj == NULL || stru == NULL){ 
      fprintf(stderr,"ERROR: obj == NULL on insert_field()");
   }
   fprintf(sym_file, "   %s (%ld.%ld.%ld) ", key->c_str(),
           obj->filenr, obj->linenr, obj->offset);
   print_attributes(sym_file, obj->attr);
   fprintf(sym_file, "\n");
   symbol_entry e = {key, obj};
   if(stru->fields == NULL){
      //printf("Stru: %p\n",stru->fields);
      stru->fields = new symbol_table;
   }
   (*((stru)->fields)).insert(e);
   //std::cout << "*****field_table.size() is " << (*(stru->fields)).size() << std::endl;
}


void add_symbol_stack(){//std::cout << "ADD CALLED" << std::endl;
  symbol_stack.push_back(NULL);
}

void pop_symbol_stack(){//std::cout << "POP CALLED" << std::endl;
  symbol_stack.pop_back();
}

symbol* lookup(string* key){
  for(int i = symbol_stack.size()-1; i >= 0; i--){
     symbol_table* curr = symbol_stack[i];
     if(curr != NULL){
        symbol* tmp = get_symbol(key, curr);
        if(tmp != NULL){
           return tmp;
        }
     }  
  }
  return NULL;
}

symbol* get_symbol(string* key, symbol_table* st){
   auto curr = (*st).find(key);
   if(curr != (*st).end() ){
      symbol* c = curr->second;
      return c;
   }
   return NULL;
}

void print_table(string s, symbol_table mymap){
  std::cout << s << " contains:" << std::endl;
  for ( auto it = mymap.begin(); it != mymap.end(); ++it ) {
    std::cout << " " << *(it->first) << ":" << (it->second) << std::endl;
    std::cout << " -block number " << (it->second)->block_nr << std::endl;
    std::cout << " -int attr " << (it->second)->attr[ATTR_int] << std::endl;
    std::cout << std::endl;
  }
  std::cout << std::endl;
/*
  std::cout << s <<"'s buckets contain:\n";
  for ( unsigned i = 0; i < mymap.bucket_count(); ++i) {
    std::cout << "bucket #" << i << " contains:";
    for ( auto local_it = mymap.begin(i); local_it!= mymap.end(i); ++local_it )
      std::cout << " " << *(local_it->first) << ":" << (local_it->second);
    std::cout << std::endl;
  }
*/
}
