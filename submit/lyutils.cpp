
#include <vector>
#include <string>
using namespace std;

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lyutils.h"
#include "auxlib.h"

astree* yyparse_astree = NULL;
int scan_linenr = 1;
int scan_offset = 0;
bool scan_echo = false;
vector<string> included_filenames;
/*extern FILE* tok_file;*/
//FILE* tok_file = make_tok_file(filename);

const string* scanner_filename (int filenr) {
   return &included_filenames.at(filenr);
}

void scanner_newfilename (const char* filename) {
   included_filenames.push_back (filename);
}

void scanner_newline (void) {
   ++scan_linenr;
   scan_offset = 0;
}

void scanner_setecho (bool echoflag) {
   scan_echo = echoflag;
}


void scanner_useraction (void) {
   if (scan_echo) {
      if (scan_offset == 0) printf (";%5d: ", scan_linenr);
      printf ("%s", yytext);
   }
   scan_offset += yyleng;
}

void yyerror (const char* message) {
   assert (not included_filenames.empty());
   errprintf ("%:%s: %d: %s\n",
              included_filenames.back().c_str(), scan_linenr, message);
}

void scanner_badchar (unsigned char bad) {
   char char_rep[16];
   sprintf (char_rep, isgraph ((int) bad) ? "%c" : "\\%03o", bad);
   errprintf ("%:%s: %d: invalid source character (%s)\n",
              included_filenames.back().c_str(), scan_linenr, char_rep);
}

void scanner_badtoken (char* lexeme) {
   errprintf ("%:%s: %d: invalid token (%s)\n",
              included_filenames.back().c_str(), scan_linenr, lexeme);
}

int yylval_token (int symbol) {
   int offset = scan_offset - yyleng;
   yylval = new_astree (symbol, included_filenames.size() - 1,
                        scan_linenr, offset, yytext);
   return symbol;
}

void error_destructor (astree* tree) {
   if (tree == yyparse_astree) return;
   DEBUGSTMT ('a', dump_astree (stderr, tree); );
   free_ast (tree);
}

astree* new_parseroot (void) {
   yyparse_astree = new_astree (ROOT, 0, 0, 0, "<<ROOT>>");
   return yyparse_astree;
}

/*void print_tok(FILE* out, astree* val, char* cas){
   float num = (float)(val->offset)/1000 + (val->linenr);
   fprintf (out, "%d %.3f %d %s \t \(%s\) \n",
            (int)val->filenr, num, (int)val->symbol, cas, yytext);
}*/

FILE* mk_tk_fl(char* filename, int first){
   int len = strlen(filename);
   char* file_str = (char*)malloc(len + 2);
   strcpy(file_str, filename);
   file_str[len-2] = 't';
   file_str[len-1] = 'o';
   file_str[len] = 'k';
   file_str[len+1] = '\0';
   FILE* str_name;
   if(first == 1){
      str_name = fopen(file_str, "w+");
   }else{
      str_name = fopen(file_str, "a+");
   }
   free(file_str);
   return str_name;
}


void scanner_include (void) {
   scanner_newline();
   char filename[strlen (yytext) + 1];
   //FILE* tok_file = make_tok_file(filename);
   int linenr;
   int scan_rc = sscanf (yytext, "# %d \"%[^\"]\"", &linenr, filename);
   if (scan_rc != 2) {
      errprintf ("%: %d: [%s]: invalid directive, ignored\n",
                 scan_rc, yytext);
   }else {
      fflush(stdout);
      FILE* mytokfile = mk_tk_fl(filename, 1);
      fprintf (mytokfile, "# %d \"%s\"\n", linenr, filename);
      scanner_newfilename (filename);
      scan_linenr = linenr - 1;
      DEBUGF ('m', "filename=%s, scan_linenr=%d\n",
              included_filenames.back().c_str(), scan_linenr);
   }
}

RCSC("$Id: lyutils.cc,v 1.3 2013-10-10 18:17:45-07 - - $")

