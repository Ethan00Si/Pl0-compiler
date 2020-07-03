/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
     INTEGER_VAL = 258,
     FLOAT_VAL = 259,
     CHAR_VAL = 260,
     STRING_VAL = 261,
     CMP = 262,
     IDENTIFIER = 263,
     PROCEDURE = 264,
     IF = 265,
     THEN = 266,
     WHILE = 267,
     DO = 268,
     READ = 269,
     WRITE = 270,
     CALL = 271,
     _BEGIN_ = 272,
     END = 273,
     CONST = 274,
     VAR = 275,
     ODD = 276,
     FOR = 277,
     TO = 278,
     REPEAT = 279,
     UNTIL = 280,
     ARRAY = 281,
     OF = 282,
     INT_ = 283,
     FLOAT = 284,
     CHAR = 285,
     STRING = 286,
     SL_PAREN = 287,
     SR_PAREN = 288,
     ML_PAREN = 289,
     MR_PAREN = 290,
     LL_PAREN = 291,
     LR_PAREN = 292,
     COMMA = 293,
     COLON = 294,
     SEMI = 295,
     DOTDOT = 296,
     DOT = 297,
     MINUS = 298,
     PLUS = 299,
     DIVIDE = 300,
     TIMES = 301,
     ASSIGN = 302,
     LOWERELSE = 303,
     ELSE = 304
   };
#endif
/* Tokens.  */
#define INTEGER_VAL 258
#define FLOAT_VAL 259
#define CHAR_VAL 260
#define STRING_VAL 261
#define CMP 262
#define IDENTIFIER 263
#define PROCEDURE 264
#define IF 265
#define THEN 266
#define WHILE 267
#define DO 268
#define READ 269
#define WRITE 270
#define CALL 271
#define _BEGIN_ 272
#define END 273
#define CONST 274
#define VAR 275
#define ODD 276
#define FOR 277
#define TO 278
#define REPEAT 279
#define UNTIL 280
#define ARRAY 281
#define OF 282
#define INT_ 283
#define FLOAT 284
#define CHAR 285
#define STRING 286
#define SL_PAREN 287
#define SR_PAREN 288
#define ML_PAREN 289
#define MR_PAREN 290
#define LL_PAREN 291
#define LR_PAREN 292
#define COMMA 293
#define COLON 294
#define SEMI 295
#define DOTDOT 296
#define DOT 297
#define MINUS 298
#define PLUS 299
#define DIVIDE 300
#define TIMES 301
#define ASSIGN 302
#define LOWERELSE 303
#define ELSE 304




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 10 "SyntaxPl0.y"
{
      struct {
        int i_val;
        float f_val;
        int type_; //int:0 float:1
      }count;

      struct {
        char* id;
        int offset;
        int type_;//int:0 float:1 char:2 string:3 aryint:4 aryfloat:5
      }Identi;
      
      struct {
	      int dimension;
	      int low[10];
	      int high[10];
        int search[10];
      }array__;

     
      int i_val;
      float f_val;
      char* str; 
}
/* Line 1529 of yacc.c.  */
#line 173 "SyntaxPl0.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

