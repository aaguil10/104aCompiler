
#include <assert.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <utility>
#include<string>                                                                                           
#include "astree.h"
#include "stringset.h"
#include "lyutils.h"

//extern int next_block;

astree* new_astree (int symbol, int filenr, int linenr, int offset,
                    const char* lexinfo) {
   astree* tree = new astree();
   tree->symbol = symbol;
   tree->filenr = filenr;
   tree->linenr = linenr;
   tree->offset = offset;
   tree->lexinfo = intern_stringset (lexinfo);
   tree->attr = 0;
   tree->block_nr = 0;
   tree->fields = NULL;
   DEBUGF ('f', "astree %p->{%d:%d.%d: %s: \"%s\"}\n",
           tree, tree->filenr, tree->linenr, tree->offset,
           get_yytname (tree->symbol), tree->lexinfo->c_str());
   return tree;
}

astree* adopt1 (astree* root, astree* child) {
   root->children.push_back (child);
   DEBUGF ('a', "%p (%s) adopting %p (%s)\n",
           root, root->lexinfo->c_str(),
           child, child->lexinfo->c_str());
   //char* tok = (char*)get_yytname (child->symbol);
   /*if(strcmp(tok,(char*)"TOK_KW_IDENT") == 0){
      make_symboltable(root, child);
   }*/
   return root;
}

astree* adopt2 (astree* root, astree* left, astree* right) {
   adopt1 (root, left);
   adopt1 (root, right);
   return root;
}

astree* adopt3 (astree* root, astree* one, astree* two, astree* three) {
   adopt1 (root, one);
   adopt1 (root, two);
   adopt1 (root, three);
   return root;
}

astree* delRoots (astree* root) {
   for(int i = 1; i < (int)root->children.size(); i++){
      astree* tmp = root->children[i];
      char* tname = (char*)get_yytname (tmp->symbol);
      if(strcmp(tname, (char*)"TOK_ROOT") == 0 ){
        delmiddle(root, i);
      }
   }
   fflush(NULL);
   return root;
}


astree* delmiddle(astree* root, int victim){
   astree* tmp = root->children[victim];
   root->children.erase(root->children.begin() + victim);
   for(int j = 0; j < (int)tmp->children.size(); j++){
      astree* curr = tmp->children[j];
      root->children.push_back (curr);
   }
   return root;
}

astree* adopt1sym (astree* root, astree* child, int symbol) {
   root = adopt1 (root, child);
   root->symbol = symbol;
   return root;
}

astree* adoptsym (astree* root, int symbol) {
   root->symbol = symbol;
   return root;
}
void set_kw_ident(astree* node);
void set_kw_while(astree* node);
void set_kw_return(astree* node);
void set_kw_new(astree* node);
void set_kw_newstring(astree* node);
void set_field(astree* node);
void set_declid(astree* node);
void set_call(astree* node);
void set_newarray(astree* node);
void set_snewarray(astree* node);
void set_kw_if(astree* node);
void set_ifelse(astree* node);
void set_vardecl(astree* node);
void set_exclamation(astree* node);
void set_kw_ord(astree* node);
void set_kw_chr(astree* node);

void set_kw_void(astree* node);
void set_kw_bool(astree* node);
void set_kw_char(astree* node);
void set_kw_int(astree* node);
void set_kw_null(astree* node);
void set_kw_string(astree* node);
void set_kw_struct(astree* node);
void set_stringcon(astree* node);
void set_charcon(astree* node);
void set_intcon(astree* node);
void set_kw_false(astree* node);
void set_kw_true(astree* node);
void set_typeid(astree* node);
void set_paramlist(astree* node);
void set_block(astree* node);

void set_unary_arithmetic(astree* node);
void set_binary_arithmetic(astree* node);
void set_binary_comparison(astree* node);
void set_binary_equality(astree* node);

void set_assignment(astree* node);

/*void assign_attr(astree* node){
   switch (node->symbol){
      case '+':
      case '-':
         break;
      case '*':
      case '/':
      case '%':
         break;
   }
}*/

void make_tables(astree* node){
   char* tok = (char*)get_yytname (node->symbol);
   printf("%s(%s)\n",tok,node->lexinfo->c_str());
   switch (node->symbol){
      case TOK_KW_IDENT:
         set_kw_ident(node);
         break;
      case TOK_KW_WHILE:
         set_kw_while(node);
         break;
      case TOK_KW_RETURN:
         set_kw_return(node);
         break;
      case TOK_KW_NEW:
         set_kw_new(node);
         break;
      case TOK_NEWSTRING:
         set_kw_newstring(node);
         break;
      case TOK_FIELD:
         set_field(node);
         break;
      case TOK_DECLID:
         set_declid(node);
         break;
      case TOK_CALL:
         set_call(node);
         break;
      case TOK_NEWARRAY:
         set_newarray(node);
         break;
      case  TOK_sNEWARRAY:
         set_snewarray(node);
         break;
      case TOK_KW_IF:
         set_kw_if(node);
         break;
      case TOK_IFELSE:
         set_ifelse(node);
         break;
      case TOK_VARDECL:
         set_vardecl(node);
         break;
      case '!':
         set_exclamation(node);
         break;
      case TOK_KW_ORD:
         set_kw_ord(node);
         break;
      case TOK_KW_CHR:
         set_kw_chr(node);
         break;
      case TOK_KW_VOID:
         set_kw_void(node);
         break;
      case TOK_KW_BOOL:
         set_kw_bool(node);
         break;
      case TOK_KW_CHAR:
         set_kw_char(node);
         break;
      case TOK_KW_INT:
         set_kw_int(node);
         break;
      case TOK_KW_NULL:
         set_kw_null(node);
         break;
      case TOK_KW_STRING:
         set_kw_string(node);
         break;
      case TOK_STRINGCON:
         set_stringcon(node);
         break;
      case TOK_CHARCON:
         set_charcon(node);
         break;
      case TOK_INTCON:
         set_intcon(node);
         break;
      case TOK_KW_FALSE:
         set_kw_false(node);
         break;
      case TOK_KW_TRUE:
         set_kw_true(node);
         break;
      case TOK_KW_STRUCT:
         set_kw_struct(node);
         break;
      case TOK_ROOT:
         set_function(node);
         break;
      case TOK_TYPEID:
         set_typeid(node);
         break;
      case TOK_PARAMLIST:
         set_paramlist(node);
         break;
      case TOK_BLOCK:
         next_block++;
         set_block(node);
         break;
      case '+':
      case '-':
      case '*':
      case '/':
      case '%':
         set_binary_arithmetic(node);
         break;
      case TOK_NEG:
      case TOK_POS:
         set_unary_arithmetic(node);
         break;
      case '<':
      case '>':
      case TOK_GREAEQU:
      case TOK_LESSEQU:
         set_binary_comparison(node);
         break;
      case TOK_EQUALS:
      case TOK_NEQUAL:
         set_binary_equality(node);
         break;
      case '=':
         set_assignment(node);
         break;
   }
}



/*void make_symboltable(astree* p, astree* c){
   //printf("Making bacon...\n");
   symbol* curr = new_symbol (c->filenr, c->linenr,
                              c->offset, 5);
}*/

static void dump_node (FILE* outfile, astree* node) {
   char* tname = (char*)get_yytname (node->symbol);
   if (strstr (tname, "TOK_") == tname) tname += 4;
   fprintf (outfile, "%s \"%s\" (%ld.%ld.%ld) {%d} " ,tname , node->lexinfo->c_str(), 
             node->filenr, node->linenr, node->offset, (int)node->block_nr);
   attr_bitset attr = node->attr;

   print_attributes(outfile, attr);
   if(attr[ATTR_lval]){ 
      fprintf(outfile, "lval "); 
      string s ( (string)node->lexinfo->c_str() );
      symbol* c = get_symbol((string*)node->lexinfo, &ident_table);
      if(c != NULL){
      fprintf (outfile, " (%ld.%ld.%ld) " , c->filenr, c->linenr, c->offset);
      }
   }
}

static void dump_astree_rec (FILE* outfile, astree* root, int depth) {
   if (root == NULL) return;
   for(int i = 0; i < depth; i++){
      fprintf (outfile, "   "); 
   }
   fflush(NULL);
   dump_node (outfile, root);

   fprintf (outfile, "\n");
   for (size_t child = 0; child < root->children.size(); ++child) {
      dump_astree_rec (outfile, root->children[child], depth + 1);
   }
}

void dump_astree (FILE* outfile, astree* root) {
   dump_astree_rec (outfile, root, 0);
   fflush (NULL);
}

void traverseAST(astree* root, int depth){
   for (size_t child = 0; child < root->children.size(); ++child) {
      traverseAST(root->children[child], depth + 1);
   }
   for(int i = 0; i < depth; i++){
      printf("   ");
   }
   char* tok = (char*)get_yytname (root->symbol);
   printf("%s(%s)\n",tok,root->lexinfo->c_str());
   //assign_attr(root);
}

void traverseASTForward(astree* root, int depth){
   make_tables(root);
   for (size_t child = 0; child < root->children.size(); ++child) {
      traverseASTForward(root->children[child], depth + 1);
   }
}


void yyprint (FILE* outfile, unsigned short toknum, astree* yyvaluep) {
   DEBUGF ('f', "toknum = %d, yyvaluep = %p\n", toknum, yyvaluep);
   if (is_defined_token (toknum)) {
      dump_node (outfile, yyvaluep);
   }else {
      fprintf (outfile, "%s(%d)\n", get_yytname (toknum), toknum);
   }
   fflush (NULL);
}


void free_ast (astree* root) {
   while (not root->children.empty()) {
      astree* child = root->children.back();
      root->children.pop_back();
      free_ast (child);
   }
   DEBUGF ('f', "free [%X]-> %d:%d.%d: %s: \"%s\")\n",
           (uintptr_t) root, root->filenr, root->linenr, root->offset,
           get_yytname (root->symbol), root->lexinfo->c_str());
   delete root;
}

void free_ast2 (astree* tree1, astree* tree2) {
   free_ast (tree1);
   free_ast (tree2);
}

astree* find_sym(astree* root, char* symbol){
   char* tok = (char*)get_yytname (root->symbol);
   if(strcmp(tok,symbol) == 0){
     return root;
   }else{
      if(root->children.size() > 0){
         for (size_t child = 0; child < root->children.size(); ++child) {
            return find_sym(root->children[child], symbol);
         }
      }else{
         return NULL;
      }
   }
   return NULL;
}

// prototypes of helper functions for set functions (see end of file)

bool is_primitive_type(const attr_bitset& attr);
bool are_types_compatible(const attr_bitset& attrA,
                          const attr_bitset& attrB);
void write_type(astree* node, attr_bitset& outAttr);

//*******************set fuctions in switch stament**********************

void set_kw_ident(astree* node){
   int iter;
   const string* key = node->lexinfo;
   symbol_table::const_iterator got;

   for (iter = symbol_stack.size() - 1; iter >= 0; iter--) {
      got = symbol_stack[iter]->find(key);
      if ( got != symbol_stack[iter]->end() ) break;
   }

   if (iter == -1) {
      fprintf(stderr,"ERROR: undeclared variable found, "
                     "cannot determine type: %ld:%ld:%ld\n",
                     node->filenr, node->linenr, node->offset);
   } else {
      node->attr = got->second->attr;
   }
}

void set_kw_while(astree* node){

}

void set_kw_return(astree* node){

}

void set_kw_new(astree* node){

}

void set_kw_newstring(astree* node){

}


void set_field(astree* node){

}

void set_declid(astree* node){

}

void set_call(astree* node){
   int iter;
   const string* key = node->children[0]->lexinfo;
   symbol_table::const_iterator got;

   for (iter = symbol_stack.size() - 1; iter >= 0; iter--) {
      got = symbol_stack[iter]->find(key);
      if ( got != symbol_stack[iter]->end() ) break;
   }

   if (iter == -1) {
      fprintf(stderr,"ERROR: undeclared function found, "
                     "cannot determine type: %ld:%ld:%ld\n",
                     node->filenr, node->linenr, node->offset);
   } else {
      symbol* found = got->second;

      if (found->parameters == NULL) {
         fprintf(stderr,"ERROR: identifier is not a function, "
                        "cannot call non-functions: %ld:%ld:%ld\n",
                        node->filenr, node->linenr, node->offset);
      }

      if (found->parameters->size() != node->children.size() - 1) {
         fprintf(stderr,"ERROR: incorrect number of parameters, "
                        "cannot call function: %ld:%ld:%ld\n",
                        node->filenr, node->linenr, node->offset);
      }

      for (unsigned i = 1; i < node->children.size(); i++) {
         attr_bitset& callAttr = node->children[i]->attr;
         attr_bitset& paramAttr = (*(found->parameters))[i-1]->attr;

         if (!are_types_compatible(callAttr, paramAttr)) {
            fprintf(stderr,"ERROR: incompatible parameter %d, "
                           "cannot call function: %ld:%ld:%ld\n",
                          i, node->filenr, node->linenr, node->offset);
         }
      }

      node->attr = got->second->attr;
   }
}

void set_newarray(astree* node){

}

void set_snewarray(astree* node){

}

void set_kw_if(astree* node){
   for(int i = 0; i < (int)node->children.size(); i++){
      make_tables(node->children[i]);
   }
}

void set_ifelse(astree* node){
   for(int i = 0; i < (int)node->children.size(); i++){
      make_tables(node->children[i]);
   }
}

void set_vardecl(astree* node){
   astree* left_param = node->children[0];
   astree* right_param = node->children[1];

   make_tables(left_param);
   make_tables(right_param);

   if (!are_types_compatible(left_param->attr, right_param->attr)) {
      fprintf(stderr,"ERROR: unable to perform assignment on "
                     "non-compatible types: %ld:%ld:%ld\n",
                     node->filenr, node->linenr, node->offset);
   }

   if (left_param->children[0]->attr[ATTR_lval] == false) {
      fprintf(stderr,"ERROR: unable to assign to "
                     "non-lvalue type: %ld:%ld:%ld\n",
                     node->filenr, node->linenr, node->offset);
   }
}

void set_exclamation(astree* node){

}

void set_kw_ord(astree* node){

}

void set_kw_chr(astree* node){

}

symbol* insert_symbol(astree* node){
  if(node == NULL){
     fprintf(stderr, "ERROR: In astree.pp function instert_symbol()\n");
     return NULL;
  }
  //printf("inserting %s\n", node->lexinfo->c_str());

  symbol* curr;
  string* key;

  if (!node->attr[ATTR_function]) {
    curr = new_symbol(node->filenr,node->linenr,node->offset,
                      node->block_nr, node->attr, node->fields);
    key = (string*)node->lexinfo;
  }
  else { // handle function node: chilren are name and params
    astree* func = node->children[0]->children[0];
    astree* params = node->children[1];

    curr = new_symbol(func->filenr,func->linenr,func->offset,
                      func->block_nr, func->attr, func->fields);
    key = (string*)func->lexinfo;
    //std::cout << *key << std::endl;
    //std::cout << func->attr[ATTR_int] << std::endl;

    curr->parameters = new std::vector<symbol*>(params->children.size());
    for (unsigned i = 0; i < params->children.size(); i++) {
      astree* param = params->children[i]->children[0];
      //std::cout << *(param->lexinfo) << std::endl;
      //std::cout << param->attr[ATTR_int] << std::endl;

      (*(curr->parameters))[i] = new_symbol(param->filenr, param->linenr,
           param->offset, param->block_nr, param->attr, param->fields);
    }
  }


  if(node->attr[ATTR_variable] || node->attr[ATTR_function]){
     insert_ident(key,curr);
  }

  if(node->attr[ATTR_struct]){
     insert_struct(key,curr);
     return curr;
  }
  return NULL;
}

void set_kw_void(astree* node){
   node->attr[ATTR_void] = 1;
   if(node->children.size() == 1){
      astree* tmp = node->children[0];
      tmp->attr[ATTR_void] = 1;
   }
}

void set_kw_bool(astree* node){
   node->attr[ATTR_bool] = 1;
   astree* tmp = NULL;
   if(node->children.size() == 1){
      tmp = node->children[0];
      tmp->attr[ATTR_bool] = 1;
      tmp->attr[ATTR_variable] = 1;
      tmp->attr[ATTR_lval] = 1;
   }else if(node->children.size() == 2){
      tmp = node->children[1];
      tmp->attr[ATTR_bool] = 1;
      tmp->attr[ATTR_array] = 1;
      tmp->attr[ATTR_variable] = 1;
      tmp->attr[ATTR_lval] = 1;
   }else{
     fprintf(stderr,"ERROR:on astree.cpp function:set_kw_bool(astree* node)\n");
   }
   insert_symbol(tmp);
}

void set_kw_char(astree* node){
   node->attr[ATTR_char] = 1;
   astree* tmp = NULL;
   if(node->children.size() == 1){
      tmp = node->children[0];
      tmp->attr[ATTR_char] = 1;
      tmp->attr[ATTR_variable] = 1;
      tmp->attr[ATTR_lval] = 1;
   }else if(node->children.size() == 2){
      tmp = node->children[1];
      tmp->attr[ATTR_char] = 1;
      tmp->attr[ATTR_array] = 1;
      tmp->attr[ATTR_variable] = 1;
      tmp->attr[ATTR_lval] = 1;
   }else{
     fprintf(stderr,"ERROR: on astree.cpp function:set_kw_char(astree* node)\n");
   }
   insert_symbol(tmp);
}

void set_kw_int(astree* node){
   node->attr[ATTR_int] = 1;
   astree* tmp = NULL;
   if(node->children.size() == 1){
      tmp = node->children[0];
      tmp->attr[ATTR_int] = 1;
      tmp->attr[ATTR_variable] = 1;
      tmp->attr[ATTR_lval] = 1;
   }else if(node->children.size() == 2){
      tmp = node->children[1];
      tmp->attr[ATTR_int] = 1;
      tmp->attr[ATTR_array] = 1;
      tmp->attr[ATTR_variable] = 1;
      tmp->attr[ATTR_lval] = 1;
   }else{
     fprintf(stderr,"ERROR: on astree.cpp function:set_kw_int(astree* node)\n");
     return;
   }
   insert_symbol(tmp);
}

void set_kw_null(astree* node){
   node->attr[ATTR_null] = 1;
   node->attr[ATTR_const] = 1;
}

void set_kw_string(astree* node){
   node->attr[ATTR_string] = 1;
   astree* tmp = NULL;
   if(node->children.size() == 1){
      tmp = node->children[0];
      tmp->attr[ATTR_string] = 1;
      tmp->attr[ATTR_variable] = 1;
      tmp->attr[ATTR_lval] = 1;
   }else if(node->children.size() == 2){
      tmp = node->children[1];
      tmp->attr[ATTR_string] = 1;
      tmp->attr[ATTR_array] = 1;
      tmp->attr[ATTR_variable] = 1;
      tmp->attr[ATTR_lval] = 1;
   }else{
     fprintf(stderr,"ERROR: on astree.cpp function:set_kw_string(astree* node)\n");
   }
   insert_symbol(tmp);
}

void set_kw_struct(astree* node){
   node->attr[ATTR_struct] = 1; 
   astree* tmp = node->children[0];
   tmp->attr[ATTR_struct] = 1;
   tmp->attr[ATTR_void] = 0;
   tmp->attr[ATTR_typeid] = 1;
   symbol* curr = insert_symbol(tmp);
   for(int i = 1; i < (int)node->children.size(); i++){
      astree* tmp = node->children[i]->children[0];
      tmp->attr[ATTR_variable] = 0;
      tmp->attr[ATTR_field] = 1;
      symbol* tmp_sym = new_symbol(tmp->filenr,tmp->linenr,tmp->offset,
                                   tmp->block_nr, tmp->attr, tmp->fields);
      string* tmp_key = new string(tmp->lexinfo->c_str());
      insert_field(curr, tmp_key, tmp_sym);
   }
}

void set_stringcon(astree* node){
   node->attr[ATTR_string] = 1;
   node->attr[ATTR_const] = 1;
}
void set_charcon(astree* node){
   node->attr[ATTR_char] = 1;
   node->attr[ATTR_const] = 1;
}
void set_intcon(astree* node){
   node->attr[ATTR_int] = 1;
   node->attr[ATTR_const] = 1;
}

void set_kw_false(astree* node){
   node->attr[ATTR_bool] = 1;
   node->attr[ATTR_const] = 1;
}

void set_kw_true(astree* node){
   node->attr[ATTR_bool] = 1;
   node->attr[ATTR_const] = 1;
}

void set_function(astree* node){
   if( strcmp((char*)node->lexinfo->c_str(),"TOK_FUNCTION") ){
      for(int i = 0; i < (int)node->children.size(); i++){
         make_tables(node->children[i]);
      }
      return;
   }
   node->attr[ATTR_function] = 1;

   astree* type = node->children[0];
   astree* id = type->children[0];

   write_type(type, id->attr);

   //make_tables(node->children[0]);
   make_tables(node->children[1]);

   id->attr[ATTR_function] = 1;
   //insert_symbol(tmp);
   insert_symbol(node);

   make_tables(node->children[2]);
}

void set_typeid(astree* node){
   if( strcmp((char*)node->lexinfo->c_str(),"function") == 0 ){
      return;
   }
   astree* tmp = NULL;
   node->attr[ATTR_typeid] = 1;
   if(node->children.size() == 0){
        return;
   }else if(node->children.size() == 1){
      tmp = node->children[0];
      tmp->attr[ATTR_variable] = 1;
      tmp->attr[ATTR_lval] = 1;
   }else if(node->children.size() == 2){
      tmp = node->children[1];
      tmp->attr[ATTR_array] = 1;
      tmp->attr[ATTR_variable] = 1;
      tmp->attr[ATTR_lval] = 1;
   }else{
     fprintf(stderr,"ERROR: on astree.cpp function:set_typeid(astree* node)\n");
   }
   insert_symbol(tmp);
}

void set_paramlist(astree* node){ std::cout << "called" << std::endl;
   for(int i = 0; i < (int)node->children.size(); i++){
      astree* type = node->children[i];
      astree* id = type->children[0];
      write_type(type, id->attr);
      id->attr[ATTR_param] = 1;
   }
}

/*void set_block_rec(astree* node){
   if(node == NULL){ return; }
   if(node->symbol == TOK_BLOCK){
      return;
   }
   node->block_nr = next_block;
   if(node->symbol == TOK_KW_IDENT){
      symbol* curr = lookup( (string*)node->lexinfo );
      if(curr == NULL){
         fprintf(stderr, "ERROR: %s is not decalred!\n", (node->lexinfo->c_str()));
      }else{
         node->attr = curr->attr;
         node->attr[ATTR_param] = 0;
         node->attr[ATTR_void] = 0;
         node->attr[ATTR_variable] = 0;
         node->attr[ATTR_lval] = 0;
      }
   }
   for (int child = 0; child < (int)node->children.size(); ++child) { 
      //assign_attr(node->children[child]);
      set_block_rec(node->children[child]);
   }
}*/

void set_block(astree* node){
    //fprintf(stderr,"Crawling\n");
   if(node == NULL){ return; }
   node->block_nr = next_block;
   add_symbol_stack();
   for (int child = 0; child < (int)node->children.size(); ++child) {
         make_tables(node->children[child]);
   }
   pop_symbol_stack();
}



void check_parameters(astree* node, unsigned desired_number) {
   std::string oper_type = "___";
   if (desired_number == 1) oper_type = "unary";
   if (desired_number == 2) oper_type = "binary";

   if (node->children.size() != desired_number) {
      fprintf(stderr,"ERROR: incorrect number of parameters for "
                     "%s operation: %ld:%ld:%ld\n", oper_type.c_str(),
                     node->filenr, node->linenr, node->offset);
   }
}

bool is_primitive_type(const attr_bitset& attr) {
   if (attr[ATTR_bool]) return true;
   if (attr[ATTR_char]) return true;
   if (attr[ATTR_int]) return true;
   return false;
}

bool are_types_compatible(const attr_bitset& attrA,
                          const attr_bitset& attrB) {

   if (attrA[ATTR_bool] != attrB[ATTR_bool]) return false;
   if (attrA[ATTR_char] != attrB[ATTR_char]) return false;
   if (attrA[ATTR_int] != attrB[ATTR_int]) return false;
   if (attrA[ATTR_string] != attrB[ATTR_string]) return false;
   if (attrA[ATTR_struct] != attrB[ATTR_struct]) return false;
   if (attrA[ATTR_array] != attrB[ATTR_array]) return false;

   return true;
}

void write_type(astree* node, attr_bitset& outAttr) {
   if (node->symbol == TOK_KW_BOOL) outAttr[ATTR_bool] = true;
   if (node->symbol == TOK_KW_CHAR) outAttr[ATTR_char] = true;
   if (node->symbol == TOK_KW_INT) outAttr[ATTR_int] = true;
   if (node->symbol == TOK_KW_STRING) outAttr[ATTR_string] = true;
}

void set_binary_arithmetic(astree* node){
   check_parameters(node, 2);

   astree* left_param = node->children[0];
   astree* right_param = node->children[1];

   make_tables(left_param);
   make_tables(right_param);

   if (left_param->attr[ATTR_int] != 1 ||
       right_param->attr[ATTR_int] != 1) {
      fprintf(stderr,"ERROR: unable to perform binary arithmetic on "
                     "non-integer types: %ld:%ld:%ld\n", node->filenr,
                     node->linenr, node->offset);
   }

   node->attr[ATTR_int] = 1;
   node->attr[ATTR_vreg] = 1;
}

void set_unary_arithmetic(astree* node){
   check_parameters(node, 1);

   astree* param = node->children[0];

   make_tables(param);

   if (param->attr[ATTR_int] != 1) {
      fprintf(stderr,"ERROR: unable to perform unary arithmetic on "
                     "non-integer types: %ld:%ld:%ld\n", node->filenr,
                     node->linenr, node->offset);
   }

   node->attr[ATTR_int] = 1;
   node->attr[ATTR_vreg] = 1;
}

void set_binary_comparison(astree* node) {
   check_parameters(node, 2);

   astree* left_param = node->children[0];
   astree* right_param = node->children[1];

   make_tables(left_param);
   make_tables(right_param);

   if ( !is_primitive_type(left_param->attr) ||
        !is_primitive_type(right_param->attr) ) {
      fprintf(stderr,"ERROR: unable to perform binary comparison on "
                     "non-primitive types: %ld:%ld:%ld\n",
                     node->filenr, node->linenr, node->offset);
   }

   node->attr[ATTR_bool] = 1;
   node->attr[ATTR_vreg] = 1;
}

void set_binary_equality(astree* node) {
   check_parameters(node, 2);

   node->attr[ATTR_bool] = 1;
   node->attr[ATTR_vreg] = 1;
}

void set_assignment(astree* node) {
   check_parameters(node, 2);

   astree* left_param = node->children[0];
   astree* right_param = node->children[1];

   make_tables(left_param);
   make_tables(right_param);

   if (!are_types_compatible(left_param->attr, right_param->attr)) {
      fprintf(stderr,"ERROR: unable to perform assignment on "
                     "non-compatible types: %ld:%ld:%ld\n",
                     node->filenr, node->linenr, node->offset);
   }

   if (left_param->attr[ATTR_lval] == false) {
      fprintf(stderr,"ERROR: unable to assign to "
                     "non-lvalue type: %ld:%ld:%ld\n",
                     node->filenr, node->linenr, node->offset);
   }

   node->attr = left_param->attr;
   node->attr[ATTR_vreg] = true;
}


