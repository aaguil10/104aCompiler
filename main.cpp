// $Id: main.cpp,v 1.1 2014-10-03 18:45:23-07 - - $
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "stringset.h"
#include "auxlib.h"
//#include "cppstrtok.h"
#include "astree.h"
#include "lyutils.h"


bool debug = false;
void  db(string m){ if(debug){ cerr << m << endl;} };
const string CPP = "/usr/bin/cpp";
const string cpp_name = "/usr/bin/cpp";
string yyin_cpp_command;
extern FILE* yyin;

bool want_echo () {
   return not (isatty (fileno (stdin)) and isatty (fileno (stdout)));
}

void yyin_cpp_popen (const char* filename) {
   yyin_cpp_command = cpp_name;
   yyin_cpp_command += " ";
   yyin_cpp_command += filename;
   yyin = popen (yyin_cpp_command.c_str(), "r");
   if (yyin == NULL) {
      syserrprintf (yyin_cpp_command.c_str());
      exit (get_exitstatus());
   }
}

void yyin_cpp_pclose (void) {
   int pclose_rc = pclose (yyin);
   eprint_status (yyin_cpp_command.c_str(), pclose_rc);
   if (pclose_rc != 0) set_exitstatus (EXIT_FAILURE);
}

FILE* make_str_file(char* filename){
   int len = strlen(filename);
   char* file_str = (char*)malloc(len + 2); 
   strcpy(file_str, filename);
   file_str[len-2] = 's';
   file_str[len-1] = 't';
   file_str[len] = 'r';
   file_str[len+1] = '\0';
   FILE* str_name = fopen(file_str, "w+");
   free(file_str);
   return str_name;
}

FILE* make_tok_file(char* filename){
   int len = strlen(filename);
   char* file_str = (char*)malloc(len + 2); 
   strcpy(file_str, filename);
   file_str[len-2] = 't';
   file_str[len-1] = 'o';
   file_str[len] = 'k';
   file_str[len+1] = '\0';
   FILE* str_name = fopen(file_str, "w+");
   free(file_str);
   return str_name;
}

int main (int argc, char **argv) {
   int c;
   char* filename = argv[argc - 1];
   while ((c = getopt (argc, argv, "ly@:D:")) != -1){
      switch (c){
         case 'l':
            db( "Set 'l' flag!");
            yy_flex_debug = 1;
            continue;
         case 'y':
            db("Set 'y' flag!");
            yydebug = 1;
            continue;
         case '@':
            db("Set @ flag!");
            set_debugflags (optarg);
            debug = true;
            continue;
         case 'D':
            db("Set '-D' flag!");
            continue;
      }
   }

   set_execname (argv[0]);
   yyin_cpp_popen (filename);

   FILE* tok_file = make_tok_file(filename);

   /*while(yylex() != YYEOF){
      cout << "S: " << yytext << endl;
   }*/
   int linenr = 0;


   for (;;) {
      int token = yylex();
      float num = 0;
      if (yy_flex_debug) fflush (NULL);
      switch (token) {
         case YYEOF:
            printf ("END OF FILE\n");
            return 0;
         case IDENT:
            num = (float)(yylval->offset)/1000 + (yylval->linenr);
            fprintf (tok_file, "%d %.3f %d IDENT \(%s\) \n",
                    (int)yylval->filenr, num, (int)yylval->symbol, yytext);
            break;
         case NUMBER:
            num = (float)(yylval->offset)/1000 + (yylval->linenr);
            fprintf (tok_file, "%d %.3f %d NUMBER \(%s\) \n",
                    (int)yylval->filenr, num, (int)yylval->symbol, yytext);
            break;
         case '+':
         case '-':
         case '*':
         case '/':
         case '=':
         case ';':
            num = (float)(yylval->offset)/1000 + (yylval->linenr);
            fprintf (tok_file, "%d %.3f %d OPERATOR \(%s\) \n",
                    (int)yylval->filenr, num, (int)yylval->symbol, yytext);
            break;
         case '\n':
            printf ("NEWLINE\n");
            ++linenr;
            break;
         default:
            printf ("ERROR \(%s\) \n", yytext);
      }
   }


   yyin_cpp_pclose();

   FILE* str_name = make_str_file(filename);

   dump_stringset (str_name);
   return EXIT_SUCCESS;
}


