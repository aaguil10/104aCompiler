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
TOK_sNEWARRAY    \[\]
TOK_EQUALS      ==
TOK_NEQUAL      !=
TOK_LESSEQU     <=
TOK_GREAEQU     >=
TOK_KW_VOID     void
TOK_KW_BOOL     bool
TOK_KW_CHAR     char
TOK_KW_INT      int
TOK_KW_STRING   string
TOK_KW_STRUCT   struct
TOK_KW_IF       if
TOK_KW_ELSE     else
TOK_KW_WHILE    while
TOK_KW_RETURN   return
TOK_KW_FALSE    false
TOK_KW_TRUE     true
TOK_KW_NULL     null
TOK_KW_ORD      ord
TOK_KW_CHR      chr
TOK_KW_NEW      new
TOK_LIT_CHAR    ('([^\\'\n]|\\[\\'"0nt])')
NOTCHAR         '([^\\'\n]|\\[\\'"0nt])
TOK_LIT_STRING  (\"([^\\"\n]|\\[\\'"0nt])*\")
MANTISSA        ({DIGIT}+\.?{DIGIT}*|\.{DIGIT}+)
EXPONENT        ([Ee][+-]?{DIGIT}+)
TOK_LIT_INT     {DIGIT}+
NOTNUMBER       ({MANTISSA}[Ee][+-]?)
TOK_KW_IDENT    ({LETTER}({LETTER}|{DIGIT})*)
NOTIDENT        {DIGIT}+{TOK_KW_IDENT}

%%

"#".*           { scanner_include(); }
[ \t]+          { IGNORE (white space) }
\n              { scanner_newline(); }



{TOK_KW_VOID}        { return yylval_token (TOK_KW_VOID); }
{TOK_KW_BOOL}        { return yylval_token (TOK_KW_BOOL); }
{TOK_KW_CHAR}        { return yylval_token (TOK_KW_CHAR); }
{TOK_KW_INT}        { return yylval_token (TOK_KW_INT); }
{TOK_KW_STRING}        { return yylval_token (TOK_KW_STRING); }
{TOK_KW_STRUCT}        { return yylval_token (TOK_KW_STRUCT); }
{TOK_KW_IF}        { return yylval_token (TOK_KW_IF); }
{TOK_KW_ELSE}        { return yylval_token (TOK_KW_ELSE); }
{TOK_KW_WHILE}        { return yylval_token (TOK_KW_WHILE); }
{TOK_KW_RETURN}        { return yylval_token (TOK_KW_RETURN); }
{TOK_KW_FALSE}        { return yylval_token (TOK_KW_FALSE); }
{TOK_KW_TRUE}        { return yylval_token (TOK_KW_TRUE); }
{TOK_KW_NULL}        { return yylval_token (TOK_KW_NULL); }
{TOK_KW_ORD}        { return yylval_token (TOK_KW_ORD); }
{TOK_KW_CHR}        { return yylval_token (TOK_KW_CHR); }
{TOK_KW_NEW}        { return yylval_token (TOK_KW_NEW); }
{TOK_LIT_CHAR}      { return yylval_token (TOK_LIT_CHAR); }
{TOK_LIT_STRING}    { return yylval_token (TOK_LIT_STRING); }
{TOK_LIT_INT}        { return yylval_token (TOK_LIT_INT); }
{TOK_KW_IDENT}         { return yylval_token (TOK_KW_IDENT); }
{TOK_sNEWARRAY}   { return yylval_token (TOK_sNEWARRAY); }
{TOK_EQUALS}    { return yylval_token (TOK_EQUALS); }
{TOK_NEQUAL}    { return yylval_token (TOK_NEQUAL); }
{TOK_LESSEQU}   { return yylval_token (TOK_LESSEQU); }
{TOK_GREAEQU}   { return yylval_token (TOK_GREAEQU); }


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
                  return yylval_token (TOK_LIT_INT); }
{NOTCHAR}     { scanner_badtoken (yytext);
                  errprintf("ERROR: %s \n" ,yytext);
                  return yylval_token (NOTCHAR); }
{NOTIDENT}     { scanner_badtoken (yytext);
                  return yylval_token (NOTIDENT); }

.               { scanner_badchar (*yytext); }

%%

RCSC("$Id: scanner.l,v 1.4 2014-10-20 14:27:17-07 - - $")

