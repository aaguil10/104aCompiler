//symboltable.h
#ifndef __SYMBOLTABLE_H__
#define __SYMBOLTABLE_H__

#include <stdio.h>
#include <string.h>

#include <string>
#include <vector>
#include<bitset>
#include <unordered_map>
#include <iostream>
using namespace std;

enum { ATTR_void, ATTR_bool, ATTR_char, ATTR_int, ATTR_null,
ATTR_string, ATTR_struct, ATTR_array, ATTR_function,
ATTR_variable, ATTR_field, ATTR_typeid, ATTR_param, ATTR_lval,
ATTR_const, ATTR_vreg, ATTR_vaddr, ATTR_bitset_size,
};
using attr_bitset = bitset<ATTR_bitset_size>;

struct symbol;
using symbol_table = unordered_map<string*,symbol*>;
using symbol_entry = pair<string*,symbol*>;

extern FILE* sym_file;
extern symbol_table typenames_table;
extern symbol_table ident_table;
extern int next_block;

struct symbol {
   attr_bitset attr;
   symbol_table* fields;
   size_t filenr;
   size_t linenr;
   size_t offset;
   size_t block_nr;
   vector <symbol*>* parameters;
};

symbol* new_symbol (size_t filenr, size_t linenr, size_t offset,
 attr_bitset a, symbol_table* f);
void insert_struct(string* key, symbol* obj);
void insert_ident(string* key, symbol* obj);
void insert_field(symbol* stru, string* key, symbol* obj);
// lookup();
//void set_declid();
//void set_kw_int();


void print_table(string s, symbol_table mymap);

#endif
