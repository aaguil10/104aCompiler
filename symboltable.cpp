//symboltable.cpp

#include "symboltable.h"

extern FILE* sym_file;
symbol_table typenames_table;
symbol_table ident_table;
vector<symbol_table*> symbol_stack;
int next_block;



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

void insert_struct(string* key, symbol* obj){
   if(obj == NULL){ 
      fprintf(stderr,"ERROR: obj == NULL on insert_struct()");
   }
   symbol_entry e = {key, obj};
   typenames_table.insert(e);
}

void insert_ident(string* key, symbol* obj){
   if(obj == NULL){ 
      fprintf(stderr,"ERROR: obj == NULL on insert_ident()");
   }
   symbol_entry e = {key, obj};
   symbol_table* curr = symbol_stack[symbol_stack.size()-1];
   if(curr == NULL){
      printf("Cross the delta\n");
      symbol_table tmp;
      tmp.insert(e);
      symbol_stack[symbol_stack.size()-1] = &tmp;
   }else{
      (*curr).insert(e);
   }
   cout << "Bu Size: " << symbol_stack.size() << endl;
   //ident_table.insert(e);
}

void insert_field(symbol* stru, string* key, symbol* obj){
   if(obj == NULL || stru == NULL){ 
      fprintf(stderr,"ERROR: obj == NULL on insert_field()");
   }
   symbol_entry e = {key, obj};
   if(stru->fields == NULL){
      //printf("Stru: %p\n",stru->fields);
      stru->fields = new symbol_table;
   }
   (*((stru)->fields)).insert(e);
   //std::cout << "*****field_table.size() is " << (*(stru->fields)).size() << std::endl;
}


void add_symbol_stack(){
  symbol_stack.push_back(NULL);
  cout << "Pu Size: " << symbol_stack.size() << endl;
}

void pop_symbol_stack(){
  symbol_stack.pop_back();
  cout << "Pan Size: " << symbol_stack.size() << endl;
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
