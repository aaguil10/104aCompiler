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

astree* structdef1(astree* one, astree* two, astree* three,
		   astree* four, astree* five){
   free_ast2 (three, five);
   adoptsym (two, TOK_TYPEID);
   return adopt2 (one, two, four);
}

astree* call1(astree* one, astree* two, astree* three, astree* four){
   free_ast(four); 
   adoptsym (two, TOK_CALL);
   return adopt2 (two, one, three);  
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
%token  TOK_KW_WHILE TOK_KW_RETURN TOK_KW_FALSE TOK_KW_TRUE
%token  TOK_KW_NEW TOK_KW_STRUCT
%token  TOK_KW_NULL TOK_LIT_INT TOK_LIT_CHAR TOK_LIT_STRING
%token  TOK_NEWARRAY TOK_FIELD TOK_DECLID TOK_TYPEID TOK_CALL

%right  '^' ';' ','
%left   '}' ']' ')'
%right  '{' '('

%right TOK_KW_IF TOK_KW_ELSE
%right '='
%left  TOK_EQUALS TOK_NEQUAL '<' TOK_GREAEQU '>' TOK_LESSEQU
%left  '+' '-'
%left  '*' '/' '%'
%right POS NEG '!' TOK_KW_ORD TOK_KW_CHR
%left  '[' '.' 

%start  start


%%
start	: program 				{ yyparse_astree = $1; }
	;

program : program structdef    			{ $$ = adopt1 ($1, $2); }
	| program expr    			{ $$ = adopt1 ($1, $2); }
	|                     			{ $$ = new_parseroot(""); }
        ;

structdef: TOK_KW_STRUCT TOK_KW_IDENT '{' mfielddecl '}'  { $$ = structdef1($1,$2,$3,$4,$5); 
                                                            delRoots ($1); }
	;

mfielddecl: mfielddecl fielddecl ';'		{ free_ast($3); $$ = adopt1 ($1, $2); }
	| 					{ $$ = new_parseroot(""); }
	;

fielddecl: basetype TOK_KW_IDENT		{ adoptsym ($1, TOK_FIELD);
						 $$ = adopt1 ($1, $2); }
	| basetype TOK_NEWARRAY TOK_FIELD 	{ $$ = adopt2 ($1, $2, $3); }
	;

basetype: TOK_KW_VOID | TOK_KW_BOOL | TOK_KW_INT 
	| TOK_KW_CHAR | TOK_KW_STRING | TOK_TYPEID
	;

identdecl: basetype TOK_KW_IDENT		{ adoptsym ($1, TOK_DECLID);
						  $$ = adopt1 ($1, $2); }
	| basetype TOK_NEWARRAY TOK_DECLID 	{ $$ = adopt2 ($1, $2, $3); }
	;

expr	: call 					{ $$ = $1 }
	| variable				{ $$ = $1 }
	;

args	: args ',' expr				{ $$ = adopt1 ($1, $3); }
	| expr					{ $$ = adopt1 (new_parseroot(""), $1);}
	|					{ $$ = new_parseroot(""); }
	;

call	: TOK_KW_IDENT '(' args ')'		{ $$ = call1($1,$2,$3,$4); delRoots ($2); }
	;

variable: TOK_KW_IDENT				{ $$ = $1 }
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

