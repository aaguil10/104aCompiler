#ifndef __ASTREE_H__
#define __ASTREE_H__

#include <string>
#include <vector>
#include <bitset>
using namespace std;


#include "auxlib.h"
#include "symboltable.h"

/*enum { ATTR_void, ATTR_bool, ATTR_char, ATTR_int, ATTR_null,
ATTR_string, ATTR_struct, ATTR_array, ATTR_function,
ATTR_variable, ATTR_field, ATTR_typeid, ATTR_param, ATTR_lval,
ATTR_const, ATTR_vreg, ATTR_vaddr, ATTR_bitset_size,
};*/
//using attr_bitset = bitset<ATTR_bitset_size>;


struct astree {
   int symbol;               // token code
   size_t filenr;            // index into filename stack
   size_t linenr;            // line number from source code
   size_t offset;            // offset of token with current line
   const string* lexinfo;    // pointer to lexical information
   attr_bitset attr;
   size_t block_nr;
   symbol_table* fields;
   vector<astree*> children; // children of this n-way node
};


astree* new_astree (int symbol, int filenr, int linenr, int offset,
                    const char* lexinfo);
void changeSymbol(astree* tree, int myStr);
astree* adopt1 (astree* root, astree* child);
astree* adopt2 (astree* root, astree* left, astree* right);
astree* adopt3 (astree* root, astree* one, astree* two, astree* three);
astree* stealGrand (astree* root, int start);
astree* delRoots (astree* root);
astree* delmiddle(astree* root, int victim);
astree* adopt1sym (astree* root, astree* child, int symbol);
astree* adoptsym (astree* root, int symbol);
void dump_astree (FILE* outfile, astree* root);
void yyprint (FILE* outfile, unsigned short toknum, astree* yyvaluep);
void free_ast (astree* tree);
void free_ast2 (astree* tree1, astree* tree2);

RCSH("$Id: astree.h,v 1.3 2013-09-20 12:23:31-07 - - $")
#endif
