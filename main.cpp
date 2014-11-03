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
#include "astree.h"
#include "lyutils.h"


bool debug = false;
void  db(string m){ if(debug){ cerr << m << endl;} };
const string CPP = "/usr/bin/cpp";
const string cpp_name = "/usr/bin/cpp";
string yyin_cpp_command;
extern FILE* yyin;
FILE* tok_file;

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
   FILE* str_name = fopen(file_str, "a+");
   free(file_str);
   return str_name;
}

FILE* make_tok_file(char* filename, int first){
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

/*void print_tok(FILE* out, astree* val, char* cas){
   float num = (float)(val->offset)/1000 + (val->linenr);
   fprintf (out, "%d %.3f %d %s \t \(%s\) \n",
            (int)val->filenr, num, (int)val->symbol, cas, yytext);
}*/

void print_str(char* filename){
   yyin_cpp_pclose();
   FILE* str_name = make_str_file(filename);
   dump_stringset (str_name);
}

int main (int argc, char **argv) {
   int c;
   char* filename = argv[argc - 1];
   tok_file = make_tok_file(filename, 1);
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

   //extern FILE* tok_file = make_tok_file(filename);

   /*while(yylex() != YYEOF){
      cout << "S: " << yytext << endl;
   }*/
   int linenr = 0;


   for (;;) {
      int token = yylex();
      if (yy_flex_debug) fflush (NULL);
      switch (token) {
         case YYEOF:
            fprintf (tok_file, "END OF FILE\n");
            print_str(filename);
            return 0;
            //break;
         case VOID:
            print_tok(tok_file, yylval, (char*)"TOK_REV_VOID");
            break;
         case BOOL:
            print_tok(tok_file, yylval, (char*)"TOK_REV_BOOL");
            break;
         case CHAR:
            print_tok(tok_file, yylval, (char*)"TOK_REV_CHAR");
            break;
         /*case NOTCHAR:
            print_tok(stdout , yylval, (char*)"TOK_REV_notCHAR");
            break;*/
         case INT:
            print_tok(tok_file, yylval, (char*)"TOK_REV_INT");
            break;
         case STRING:
            print_tok(tok_file, yylval, (char*)"TOK_REV_STRING");
            break;
         case STRUCT:
            print_tok(tok_file, yylval, (char*)"TOK_REV_STRUCT");
            break;
         case IF:
            print_tok(tok_file, yylval, (char*)"TOK_REV_IF");
            break;
         case ELSE:
            print_tok(tok_file, yylval, (char*)"TOK_REV_ELSE");
            break;
         case WHILE:
            print_tok(tok_file, yylval, (char*)"TOK_REV_WHILE");
            break;
         case RETURN:
            print_tok(tok_file, yylval, (char*)"TOK_REV_RETURN");
            break;
         case FALSE:
            print_tok(tok_file, yylval, (char*)"TOK_REV_FALSE");
            break;
         case TRUE:
            print_tok(tok_file, yylval, (char*)"TOK_REV_TRUE");
            break;
         case TOK_NULL:
            print_tok(tok_file, yylval, (char*)"TOK_REV_NULL");
            break;
         case ORD:
            print_tok(tok_file, yylval, (char*)"TOK_REV_ORD");
            break;
         case CHR:
            print_tok(tok_file, yylval, (char*)"TOK_REV_CHR");
            break;
         case NEW:
            print_tok(tok_file, yylval, (char*)"TOK_REV_NEW");
            break;

         case '+':
            print_tok(tok_file, yylval, (char*)"'+' ");
            break;
         case '-':
            print_tok(tok_file, yylval, (char*)"'-'");
            break;
         case '*':
            print_tok(tok_file, yylval, (char*)"'*'");
            break;
         case '/':
            print_tok(tok_file, yylval, (char*)"'/'");
            break;
         case '=':
            print_tok(tok_file, yylval, (char*)"'=' ");
            break;
         case '}':
            print_tok(tok_file, yylval, (char*)"'}'");
            break;
         case '{':
            print_tok(tok_file, yylval, (char*)"'{'");
            break;
         case ',':
            print_tok(tok_file, yylval, (char*)"','");
            break;
         case '[':
            print_tok(tok_file, yylval, (char*)"'['");
            break;
         case ']':
            print_tok(tok_file, yylval, (char*)"']'");
            break;
         case '.':
            print_tok(tok_file, yylval, (char*)"'.'");
            break;
         case '>':
            print_tok(tok_file, yylval, (char*)"'>'");
            break;
         case '<':
            print_tok(tok_file, yylval, (char*)"'<'");
            break;
         case '%':
            print_tok(tok_file, yylval, (char*)"'%'");
            break;
         case '!':
            print_tok(tok_file, yylval, (char*)"'!'");
            break;
         case '(':
            print_tok(tok_file, yylval, (char*)"'(' ");
            break;
         case ')':
            print_tok(tok_file, yylval, (char*)"')' ");
            break;
         case ';':
            print_tok(tok_file, yylval, (char*)"';' ");
            break;
         case SQUBRACKETS:
            print_tok(tok_file, yylval, (char*)"'[]'");
            break;
         case EQUALS:
            print_tok(tok_file, yylval, (char*)"'=='");
            break;
         case NEQUAL:
            print_tok(tok_file, yylval, (char*)"'!='");
            break;
         case LESSEQU:
            print_tok(tok_file, yylval, (char*)"'<='");
            break;
         case GREAEQU:
            print_tok(tok_file, yylval, (char*)"'>='");
            break;

        case CHAR_CONST:
            print_tok(tok_file, yylval, (char*)"TOK_LIT_CHAR");
            break;
        case STRING_CONST:
            print_tok(tok_file, yylval, (char*)"TOK_LIT_STRING");
            break;
        case NUMBER:
            print_tok(tok_file, yylval, (char*)"TOK_LIT_INT");
            break;

         case IDENT:
            print_tok(tok_file, yylval, (char*)"IDENT");
            break;
         case NOTIDENT:
            print_tok(stderr, yylval, (char*)"NOTIDENT");
            break;

         case '\n':
            printf ("NEWLINE\n");
            ++linenr;
            break;
         default:
            printf ("ERROR \(%s\) \n", yytext);
      }
   }

printf("Of the wild ones!\n");
   yyin_cpp_pclose();

   FILE* str_name = make_str_file(filename);
   printf("BBAAAABBBBAAA!");
   dump_stringset (str_name);
   return EXIT_SUCCESS;
}


