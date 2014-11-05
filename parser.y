%{
// $Id: parser.y,v 1.5 2013-10-10 18:48:18-07 - - $

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "lyutils.h"
#include "astree.h"

#define YYDEBUG 1
#define YYERROR_VERBOSE 1
#define YYPRINT yyprint
#define YYMALLOC yycalloc

static void* yycalloc (size_t size);

%}

%debug
%defines
%error-verbose
%token-table
%verbose

%destructor { error_destructor ($$); } <>

%token  TOK_ROOT TOK_KW_IDENT NOTIDENT
%token  TOK_KW_VOID TOK_KW_BOOL TOK_KW_CHAR TOK_KW_INT TOK_KW_STRING
%token  TOK_KW_ELSE TOK_KW_WHILE TOK_KW_RETURN TOK_KW_FALSE TOK_KW_TRUE
%token  TOK_KW_ORD TOK_KW_CHR TOK_KW_NEW TOK_KW_IF TOK_KW_STRUCT
%token  TOK_KW_NULL TOK_LIT_INT TOK_LIT_CHAR TOK_LIT_STRING
%token  TOK_NEQUAL TOK_EQUALS TOK_GREAEQU TOK_LESSEQU TOK_NEWARRAY

%right  '=' '%' '!'
%left   '+' '-'
%left   '*' '/'
%right  '^' ';' ',' '.'
%left   '}' ']' ')' '>'
%right  '{' '[' '(' '<'
%right  POS "u+" NEG "u-"

%start  program


%%

program : stmtseq               { $$ = $1; }
        ;

stmtseq : stmtseq expr ';'      { free_ast ($3); $$ = adopt1 ($1, $2); }
        | stmtseq error ';'     { free_ast ($3); $$ = $1; }
        | stmtseq ';'           { free_ast ($2); $$ = $1; }
        |                       { $$ = new_parseroot("myfile"); }
        ;

expr    : expr '=' expr         { $$ = adopt2 ($2, $1, $3); }
        | expr '+' expr         { $$ = adopt2 ($2, $1, $3); }
        | expr '-' expr         { $$ = adopt2 ($2, $1, $3); }
        | expr '*' expr         { $$ = adopt2 ($2, $1, $3); }
        | expr '/' expr         { $$ = adopt2 ($2, $1, $3); }
        | expr '^' expr         { $$ = adopt2 ($2, $1, $3); }
        | '+' expr %prec POS    { $$ = adopt1sym ($1, $2, POS); }
        | '-' expr %prec NEG    { $$ = adopt1sym ($1, $2, NEG); }
        | '(' expr ')'          { free_ast2 ($1, $3); $$ = $2; }
        | TOK_KW_IDENT          { $$ = $1; }
        | TOK_LIT_INT           { $$ = $1; }
        ;

%%

const char* get_yytname (int symbol) {
   return yytname [YYTRANSLATE (symbol)];
}

bool is_defined_token (int symbol) {
   return YYTRANSLATE (symbol) > YYUNDEFTOK;
}

static void* yycalloc (size_t size) {
   void* result = calloc (1, size);
   assert (result != NULL);
   return result;
}

RCSC("$Id: parser.y,v 1.5 2013-10-10 18:48:18-07 - - $")

