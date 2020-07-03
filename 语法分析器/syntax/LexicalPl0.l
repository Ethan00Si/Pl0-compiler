%option noyywrap
%{
#include"main.h"
#include"SyntaxPl0.tab.h"

extern int yylex(void);
extern int yywarp(void);
extern FILE* fh;
int row=1,column=1;
void output(char type);
%}

/*辅助定义*/
Digit   [0-9]
Letter    [a-zA-Z]
KeyWord [iI][fF]|[tT][hH][eE][nN]|[eE][lL][sS][eE]|[wW][hH][iI][lL][eE]|[dD][oO]|[rR][eE][aA][dD]|[wW][rR][iI][tT][eE]|[cC][aA][lL][lL]|[bB][eE][gG][iI][nN]|[eE][nN][dD]|[cC][oO][nN][sS][tT]|[vV][aA][rR]|[pP][rR][oO][cC][eE][dD][uU][rR][eE]|[oO][dD][dD]|[oO][fF]|[aA][rR][rR][aA][yY]|[iI][nN][tT]|[fF][lL][oO][aA][tT]|[fF][oO][rR]|[tT][oO]|[rR][eE][pP][eE][aA][tT]|[uU][nN][tT][iI][lL]|[cC][hH][aA][rR]|[sS][tT][rR][iI][nN][gG]
Identifier  ({Letter}({Letter}|{Digit})*)
Integer {Digit}+
Float (-?{Digit}+(\.{Digit}+)?([Ee][-+][0-9]+)?)
Char (\'.{1}\')
String (\".{1,}\")
Other [\r]

Newline [\n]
Blank [ ]
Tab [\t]

illegal (\'.{2,}\')

/*识别规则*/
%%

{KeyWord} {
	fprintf(fh, "%s\n", yytext);
	if(!strcasecmp(yytext, "CONST")){
		fprintf(fh, "CONST -> %s\n", yytext);
		return CONST;
	}
	if(!strcasecmp(yytext, "VAR")){
		fprintf(fh, "VAR -> %s\n", yytext);
		return VAR;
	}
	if(!strcasecmp(yytext, "PROCEDURE")){
		fprintf(fh, "PROCEDURE -> %s\n", yytext);
		return PROCEDURE;
	}
	if(!strcasecmp(yytext, "BEGIN")){
		fprintf(fh, "_BEGIN_ -> %s\n", yytext);
		return _BEGIN_;
	}
	if(!strcasecmp(yytext, "END")){
		fprintf(fh, "END -> %s\n", yytext);
		return END;
	}
	if(!strcasecmp(yytext, "IF")){
		fprintf(fh, "IF -> %s\n", yytext);
		return IF;
	}
	if(!strcasecmp(yytext, "THEN")){
		fprintf(fh, "THEN -> %s\n", yytext);
		return THEN;
	}
	if(!strcasecmp(yytext, "ELSE")){
		fprintf(fh, "ELSE -> %s\n", yytext);
		return ELSE;
	}
	if(!strcasecmp(yytext, "ODD")){
		fprintf(fh, "ODD -> %s\n", yytext);
		return ODD;
	}
	if(!strcasecmp(yytext, "WHILE")){
		fprintf(fh, "WHILE -> %s\n", yytext);
		return WHILE;
	}
	if(!strcasecmp(yytext, "DO")){
		fprintf(fh, "DO -> %s\n", yytext);
		return DO;
	}
	if(!strcasecmp(yytext, "CALL")){
		fprintf(fh, "CALL -> %s\n", yytext);
		return CALL;
	}
	if(!strcasecmp(yytext, "READ")){
		fprintf(fh, "READ -> %s\n", yytext);
		return READ;
	}
	if(!strcasecmp(yytext, "WRITE")){
		fprintf(fh, "WRITE -> %s\n", yytext);
		return WRITE;
	}
	if(!strcasecmp(yytext,"ARRAY")){
		fprintf(fh, "ARRAY -> %s\n", yytext);
		return ARRAY;
	}
	if(!strcasecmp(yytext,"OF")){
		fprintf(fh, "OF -> %s\n", yytext);
		return OF;
	}
	if(!strcasecmp(yytext,"INT")){
		fprintf(fh, "INT -> %s\n", yytext);
		return INT;
	}
	if(!strcasecmp(yytext,"FLOAT")){
		fprintf(fh, "FLOAT -> %s\n", yytext);
		return FLOAT;
	}
    if(!strcasecmp(yytext,"FOR")){
		fprintf(fh, "FOR -> %s\n", yytext);
        return FOR;
    }
    if(!strcasecmp(yytext,"TO")){
		fprintf(fh, "TO -> %s\n", yytext);
        return TO;
    }
    if(!strcasecmp(yytext,"REPEAT")){
		fprintf(fh, "REPEAT -> %s\n", yytext);
        return REPEAT;
    }
    if(!strcasecmp(yytext,"UNTIL")){
		fprintf(fh, "UNTIL -> %s\n", yytext);
        return UNTIL;
    }
    if(!strcasecmp(yytext,"CHAR")){
		fprintf(fh, "CHAR -> %s\n", yytext);
        return CHAR;
    }
    if(!strcasecmp(yytext,"STRING")){
		fprintf(fh, "STRING -> %s\n", yytext);
        return STRING;
    }
	column += yyleng;
}



"+"|"-"|"*"|"/"|"<"|">"|"="|"!="|">="|"<="|":="	{column+=yyleng;
	fprintf(fh, "%s\n", yytext);
    if(!strcasecmp(yytext, "+")){
		fprintf(fh, "PLUS -> %s\n", yytext);
		return PLUS;
	}
    if(!strcasecmp(yytext, "-")){
		fprintf(fh, "MINUS -> %s\n", yytext);
		return MINUS;
	}
    if(!strcasecmp(yytext, "*")){
		fprintf(fh, "TIMES -> %s\n", yytext);
		return TIMES;
	}
    if(!strcasecmp(yytext, "/")){
		fprintf(fh, "DIVIDE -> %s\n", yytext);
		return DIVIDE;
	}
    if(!strcasecmp(yytext, "<")){
		fprintf(fh, "LESS -> %s\n", yytext);
		return LESS;
	}
    if(!strcasecmp(yytext, ">")){
		fprintf(fh, "GREATER -> %s\n", yytext);
		return GREATER;
	}
    if(!strcasecmp(yytext, "=")){
		fprintf(fh, "EQUAL -> %s\n", yytext);
		return EQUAL;
	}
    if(!strcasecmp(yytext, "!=")){
		fprintf(fh, "NOTEQUAL -> %s\n", yytext);
		return NOTEQUAL;
	}
    if(!strcasecmp(yytext, ">=")){
		fprintf(fh, "GREATER_EQUAL -> %s\n", yytext);
		return GREATER_EQUAL;
	}
    if(!strcasecmp(yytext, "<=")){
		fprintf(fh, "LESS_EQUAL -> %s\n", yytext);
		return LESS_EQUAL;
	}
    if(!strcasecmp(yytext, ":=")){
		fprintf(fh, "ASSIGN -> %s\n", yytext);
		return ASSIGN;
	}

}

"("|")"|"["|"]"|"{"|"}"|","|":"|";"|".."|"."		{column+=yyleng;
	fprintf(fh, "%s\n", yytext);
    if(!strcasecmp(yytext, "(")){
		fprintf(fh, "SL_PAREN -> %s\n", yytext);
		return SL_PAREN;
	}
    if(!strcasecmp(yytext, ")")){
		fprintf(fh, "SR_PAREN -> %s\n", yytext);
		return SR_PAREN;
	}
    if(!strcasecmp(yytext, "[")){
		fprintf(fh, "LEFTBRAC -> %s\n", yytext);
		return LEFTBRAC;
	}
    if(!strcasecmp(yytext, "]")){
		fprintf(fh, "RIGHTBRAC -> %s\n", yytext);
		return RIGHTBRAC;
	}
    if(!strcasecmp(yytext, "{")){
		fprintf(fh, "LL_PAREN -> %s\n", yytext);
		return LL_PAREN;
	}
    if(!strcasecmp(yytext, "}")){
		fprintf(fh, "LR_PAREN -> %s\n", yytext);
		return LR_PAREN;
	}
    if(!strcasecmp(yytext, ",")){
		fprintf(fh, "COMMA -> %s\n", yytext);
		return COMMA;
	}
    if(!strcasecmp(yytext, ":")){
		fprintf(fh, "COLON -> %s\n", yytext);
		return COLON;
	}
    if(!strcasecmp(yytext, ";")){
		fprintf(fh, "SEMI -> %s\n", yytext);
		return SEMI;
	}
    if(!strcasecmp(yytext, "..")){
		fprintf(fh, "OMIT -> %s\n", yytext);
		return OMIT;
	}
    if(!strcasecmp(yytext, ".")){
		fprintf(fh, "DOT -> %s\n", yytext);
		return DOT;
	}
}

{Blank} { }
{Tab} { }

{Newline}   {row+=1;column=1;}
{Other}     {column+=yyleng;}
{Integer}|-{Integer} {
	fprintf(fh, "%s\n", yytext);
	fprintf(fh, "INTEGER_VAL -> %s\n", yytext);
    if(yyleng>14)
    {
        printf("Error! Word length is overproof!\n");
        exit(0);
    }
    column+=yyleng;
    yylval.m_int=atoi(yytext);
    return INTEGER_VAL;
}
{Float}|-{Float} {
	fprintf(fh, "%s\n", yytext);
	fprintf(fh, "FLOAT_VAL -> %s\n", yytext);
    if(yyleng>14)
    {
        printf("Error! Word length is overproof!\n");
        exit(0);
    }
    column+=yyleng;
    yylval.m_float=atof(yytext);
    return FLOAT_VAL;
}
{Char} {
	fprintf(fh, "%s\n", yytext);
	fprintf(fh, "CHAR_VAL -> %s\n", yytext);
    column+=yyleng;
    yylval.m_char=yytext[0];
    return CHAR_VAL;
}
{String} {
	fprintf(fh, "%s\n", yytext);
	fprintf(fh, "STRING_VAL -> %s\n", yytext);
    column+=yyleng;
    yylval.m_string=yytext;
    return STRING_VAL;
}
{Identifier} {
	fprintf(fh, "%s\n", yytext);
	fprintf(fh, "IDENTIFIER -> %s\n", yytext);
    column+=yyleng;
    yylval.m_ID=yytext;
    return IDENTIFIER;
}
{illegal} {
    printf("Error! Illegal input!\n");
    exit(0);
}

%%
