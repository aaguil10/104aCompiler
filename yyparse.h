
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOK_ROOT = 258,
     TOK_KW_IDENT = 259,
     NOTIDENT = 260,
     NOTCHAR = 261,
     TOK_KW_VOID = 262,
     TOK_KW_BOOL = 263,
     TOK_KW_CHAR = 264,
     TOK_KW_INT = 265,
     TOK_KW_STRING = 266,
     TOK_KW_WHILE = 267,
     TOK_KW_RETURN = 268,
     TOK_KW_FALSE = 269,
     TOK_KW_TRUE = 270,
     TOK_KW_NEW = 271,
     TOK_KW_STRUCT = 272,
     TOK_NEWSTRING = 273,
     TOK_KW_NULL = 274,
     TOK_LIT_INT = 275,
     TOK_LIT_CHAR = 276,
     TOK_LIT_STRING = 277,
     TOK_FIELD = 278,
     TOK_DECLID = 279,
     TOK_TYPEID = 280,
     TOK_CALL = 281,
     TOK_STRINGCON = 282,
     TOK_CHARCON = 283,
     TOK_INTCON = 284,
     TOK_NEWARRAY = 285,
     TOK_sNEWARRAY = 286,
     TOK_KW_ELSE = 287,
     TOK_KW_IF = 288,
     TOK_PARAMLIST = 289,
     TOK_BLOCK = 290,
     TOK_VARDECL = 291,
     TOK_IFELSE = 292,
     TOK_LESSEQU = 293,
     TOK_GREAEQU = 294,
     TOK_NEQUAL = 295,
     TOK_EQUALS = 296,
     TOK_KW_CHR = 297,
     TOK_KW_ORD = 298,
     TOK_NEG = 299,
     TOK_POS = 300
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


