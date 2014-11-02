%{
// $Id: scanner.l,v 1.4 2014-10-20 14:27:17-07 - - $

#include "auxlib.h"
#include "lyutils.h"

#define YY_USER_ACTION  { scanner_useraction (); }
#define IGNORE(THING)   { }

%}

%option 8bit
%option debug
%option nodefault
%option nounput
%option noyywrap
%option verbose
%option warn


LETTER          [A-Za-z_]
DIGIT           [0-9]
SQUBRACKETS	\[\]
EQUALS		==
NEQUAL		!=
LESSEQU		<=
GREAEQU		>=
VOID		void
BOOL		bool
CHAR		char
INT		int
STRING		string
STRUCT		sturct
IF		if
ELSE		else
WHILE		while
RETURN		return
FALSE		false
TRUE		true
TOK_NULL	null
ORD		ord
CHR		chr
NEW		new
CHAR_CONST	(’([^\\’\n]|\\[\\’"0nt])’)
STRING_CONST	(\"([^\\"\n]|\\[\\’"0nt])*\")
MANTISSA        ({DIGIT}+\.?{DIGIT}*|\.{DIGIT}+)
EXPONENT        ([Ee][+-]?{DIGIT}+)
NUMBER          ({MANTISSA}{EXPONENT}?)
NOTNUMBER       ({MANTISSA}[Ee][+-]?)
IDENT           ({LETTER}({LETTER}|{DIGIT})*)

%%

"#".*           { scanner_include(); }
[ \t]+          { IGNORE (white space) }
\n              { scanner_newline(); }



{VOID}        { return yylval_token (VOID); }
{BOOL}        { return yylval_token (BOOL); }
{CHAR}        { return yylval_token (CHAR); }
{INT}        { return yylval_token (INT); }
{STRING}        { return yylval_token (STRING); }
{STRUCT}        { return yylval_token (STRUCT); }
{IF}        { return yylval_token (IF); }
{ELSE}        { return yylval_token (ELSE); }
{WHILE}        { return yylval_token (WHILE); }
{RETURN}        { return yylval_token (RETURN); }
{FALSE}        { return yylval_token (FALSE); }
{TRUE}        { return yylval_token (TRUE); }
{TOK_NULL}        { return yylval_token (TOK_NULL); }
{ORD}        { return yylval_token (ORD); }
{CHR}        { return yylval_token (CHR); }
{NEW}        { return yylval_token (NEW); }
{CHAR_CONST}        { return yylval_token (CHAR_CONST); }
{STRING_CONST}        { return yylval_token (STRING_CONST); }
{NUMBER}        { return yylval_token (NUMBER); }
{IDENT}         { return yylval_token (IDENT); }
{SQUBRACKETS}   { return yylval_token (SQUBRACKETS); }
{EQUALS}   	{ return yylval_token (EQUALS); }
{NEQUAL}   	{ return yylval_token (NEQUAL); }
{LESSEQU}   	{ return yylval_token (LESSEQU); }
{GREAEQU}	{ return yylval_token (GREAEQU); }


"}"             { return yylval_token ('}'); }
"{"             { return yylval_token ('{'); }
","             { return yylval_token (','); }
"["             { return yylval_token ('['); }
"]"             { return yylval_token (']'); }
"."             { return yylval_token ('.'); }
"<"             { return yylval_token ('<'); }
">"             { return yylval_token ('>'); }
"="             { return yylval_token ('='); }
"+"             { return yylval_token ('+'); }
"-"             { return yylval_token ('-'); }
"*"             { return yylval_token ('*'); }
"/"             { return yylval_token ('/'); }
"%"             { return yylval_token ('%'); }
"!"             { return yylval_token ('!'); }
"("             { return yylval_token ('('); }
")"             { return yylval_token (')'); }
";"             { return yylval_token (';'); }

{NOTNUMBER}     { scanner_badtoken (yytext);
                  return yylval_token (NUMBER); }

.               { scanner_badchar (*yytext); }

%%

RCSC("$Id: scanner.l,v 1.4 2014-10-20 14:27:17-07 - - $")

