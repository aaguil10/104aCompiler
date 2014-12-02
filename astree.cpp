
#include <assert.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

/*void assign_attr(astree* node){
   char* tok = (char*)get_yytname (node->symbol);
   char* keyword = (char*)node->lexinfo->c_str();

   switch (node->symbol) {
     case TOK_INT:  .... break;
     case ...
   

   //printf("Found: %s\n", tok);
   if(strcmp(tok,(char*)"TOK_DECLID") == 0 |
      strcmp(tok,(char*)"TOK_FIELD") == 0 ){
      if(strcmp(keyword,(char*)"void") == 0){
         node->attr[ATTR_void] = 1;
      }
      if(strcmp(keyword,(char*)"bool") == 0){
         node->attr[ATTR_bool] = 1;
         node->attr[ATTR_const] = 1;
      }
      if(strcmp(keyword,(char*)"char") == 0){
         node->attr[ATTR_char] = 1;
         node->attr[ATTR_const] = 1;
      }
      if(strcmp(keyword,(char*)"int") == 0){
         node->attr[ATTR_int] = 1;
         node->attr[ATTR_const] = 1;
      }
      if(strcmp(keyword,(char*)"string") == 0){
         node->attr[ATTR_string] = 1;
         node->attr[ATTR_const] = 1;
      }
   }
   if(strcmp(tok,(char*)"TOK_KW_STRUCT") == 0){
      node->attr[ATTR_struct] = 1; 
      astree* tmp = find_sym(node, (char*)"TOK_TYPEID");
      printf("****%s****\n", (char*)tmp->lexinfo->c_str());
      symbol* curr = new_symbol (tmp->filenr, tmp->linenr,
                              tmp->offset, 5);
      std::string someString(tmp->lexinfo->c_str());
      make_struct(&someString, curr);
   }
   if(strcmp(tok,(char*)"TOK_KW_NULL") == 0){
      node->attr[ATTR_null] = 1;
      node->attr[ATTR_const] = 1;
   }
}*/
void set_declid(astree* node);
void set_field(astree* node);
void set_kw_void(astree* node);
void set_kw_bool(astree* node);
void set_kw_char(astree* node);
void set_kw_int(astree* node);
void set_kw_null(astree* node);
void set_kw_string(astree* node);
void set_kw_struct(astree* node);

void assign_attr(astree* node){
   //printf("Ahhhhh");
   switch (node->symbol){
      case TOK_DECLID:
         set_declid(node);
         break;
      case TOK_FIELD:
         set_field(node);
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
      case TOK_KW_STRUCT:
         set_kw_struct(node);
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
   if(attr[ATTR_typeid]){ fprintf(outfile, "typeid "); }
   if(attr[ATTR_param]){ fprintf(outfile, "param "); }
   if(attr[ATTR_lval]){ fprintf(outfile, "lval "); }
   if(attr[ATTR_const]){ fprintf(outfile, "const "); }
   if(attr[ATTR_vreg]){ fprintf(outfile, "vreg "); }
   if(attr[ATTR_vaddr]){ fprintf(outfile, "vaddr "); }
   if(attr[ATTR_vaddr]){ fprintf(outfile, "vaddr "); }
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
   assign_attr(root);
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

//*******************set fuctions in switch stament**********************
void set_declid(astree* node){
   //printf("seting declid\n");
}

void set_field(astree* node){
   //printf("seting field\n");
}

void set_kw_void(astree* node){
   node->attr[ATTR_void] = 1;
}

void set_kw_bool(astree* node){
   node->attr[ATTR_bool] = 1;
   node->attr[ATTR_const] = 1;
}

void set_kw_char(astree* node){
   node->attr[ATTR_char] = 1;
   node->attr[ATTR_const] = 1;
}

void set_kw_int(astree* node){
   node->attr[ATTR_int] = 1;
   node->attr[ATTR_const] = 1;
}

void set_kw_null(astree* node){
   node->attr[ATTR_null] = 1;
   node->attr[ATTR_const] = 1;
}

void set_kw_string(astree* node){
   node->attr[ATTR_string] = 1;
   node->attr[ATTR_const] = 1;
}

void set_kw_struct(astree* node){
   node->attr[ATTR_struct] = 1; 
   /*astree* tmp = find_sym(node, (char*)"TOK_TYPEID");
   printf("****%s****\n", (char*)tmp->lexinfo->c_str());
   symbol* curr = new_symbol (tmp->filenr, tmp->linenr,
                              tmp->offset, 5);
   std::string someString(tmp->lexinfo->c_str());
   make_struct(&someString, curr);*/
}



