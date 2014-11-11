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

void structdef1(astree* $$, astree* one, astree* two, astree* three, 
                astree* four, astree* five){
   free_ast2 (three, five);
   //free_ast(six);
   $$ = adopt2 (one, two, four);
   stealGrand (one);
}

%}

%debug
%defines
%error-verbose
%token-table
%verbose

%destructor { error_destructor ($$); } <>

%token  TOK_ROOT TOK_KW_IDENT NOTIDENT NOTCHAR
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
%right  POS NEG

%start  start


%%
start	: program 				{ yyparse_astree = $1; }
	;

program : program structdef    			{ $$ = adopt1 ($1, $2); }
	|                     			{ $$ = new_parseroot("\"\""); }
        ;

basetype: TOK_KW_VOID | TOK_KW_BOOL | TOK_KW_INT 
	| TOK_KW_CHAR | TOK_KW_STRING
	;

identdecl: basetype TOK_KW_IDENT 		{ $$ = adopt1 ($1, $2); }
	| basetype TOK_NEWARRAY TOK_KW_IDENT 	{ $$ = adopt2 ($1, $2, $3); }
	;

fielddecl: basetype TOK_KW_IDENT 		{ $$ = adopt1 ($1, $2); }
	| basetype TOK_NEWARRAY TOK_KW_IDENT 	{ $$ = adopt2 ($1, $2, $3); }
	;

mfielddecl: mfielddecl fielddecl ';'		{ $$ = adopt1 ($1, $2); }
	| fielddecl ';'				{}
	;

structdef: TOK_KW_STRUCT TOK_KW_IDENT '{''}'		{  free_ast2 ($3, $4); $$ = adopt1 ($1, $2); }
	|  TOK_KW_STRUCT TOK_KW_IDENT'{'mfielddecl'}'	{ structdef1($$,$1,$2,$3,$4,$5); }
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

