%option noyywrap
%{

#include"SyntaxPl0.tab.h"
#include<iostream>
extern int yylex(void);
extern int yywarp(void);

int row=1,column=1;
void output(char type);
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
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

	if(!strcasecmp(yytext, "CONST")){

		return CONST;
	}
	if(!strcasecmp(yytext, "VAR")){

		return VAR;
	}
	if(!strcasecmp(yytext, "PROCEDURE")){

		return PROCEDURE;
	}
	if(!strcasecmp(yytext, "BEGIN")){

		return _BEGIN_;
	}
	if(!strcasecmp(yytext, "END")){

		return END;
	}
	if(!strcasecmp(yytext, "IF")){

		return IF;
	}
	if(!strcasecmp(yytext, "THEN")){

		return THEN;
	}
	if(!strcasecmp(yytext, "ELSE")){

		return ELSE;
	}
	if(!strcasecmp(yytext, "ODD")){

		return ODD;
	}
	if(!strcasecmp(yytext, "WHILE")){

		return WHILE;
	}
	if(!strcasecmp(yytext, "DO")){

		return DO;
	}
	if(!strcasecmp(yytext, "CALL")){

		return CALL;
	}
	if(!strcasecmp(yytext, "READ")){

		return READ;
	}
	if(!strcasecmp(yytext, "WRITE")){

		return WRITE;
	}
	if(!strcasecmp(yytext,"ARRAY")){

		return ARRAY;
	}
	if(!strcasecmp(yytext,"OF")){

		return OF;
	}
	if(!strcasecmp(yytext,"INT")){

		return INT_;
	}
	if(!strcasecmp(yytext,"FLOAT")){

		return FLOAT;
	}
    if(!strcasecmp(yytext,"FOR")){

        return FOR;
    }
    if(!strcasecmp(yytext,"TO")){

        return TO;
    }
    if(!strcasecmp(yytext,"REPEAT")){

        return REPEAT;
    }
    if(!strcasecmp(yytext,"UNTIL")){

        return UNTIL;
    }
    if(!strcasecmp(yytext,"CHAR")){

        return CHAR;
    }
    if(!strcasecmp(yytext,"STRING")){

        return STRING;
    }
	column += yyleng;
}



"+"|"-"|"*"|"/"|":="	{column+=yyleng;

    if(!strcasecmp(yytext, "+")){

		return PLUS;
	}
    if(!strcasecmp(yytext, "-")){

		return MINUS;
	}
    if(!strcasecmp(yytext, "*")){

		return TIMES;
	}
    if(!strcasecmp(yytext, "/")){

		return DIVIDE;
	}
   
    if(!strcasecmp(yytext, ":=")){

		return ASSIGN;
	}

}

"=="|"!="|"<"|">"|"<="|">=" {
    column+=yyleng;
    
    yylval.str=strdup(yytext);
    return CMP;
}


"("|")"|"["|"]"|"{"|"}"|","|":"|";"|".."|"."		{column+=yyleng;

    if(!strcasecmp(yytext, "(")){

		return SL_PAREN;
	}
    if(!strcasecmp(yytext, ")")){

		return SR_PAREN;
	}
    if(!strcasecmp(yytext, "[")){

		return ML_PAREN;
	}
    if(!strcasecmp(yytext, "]")){

		return MR_PAREN;
	}
    if(!strcasecmp(yytext, "{")){

		return LL_PAREN;
	}
    if(!strcasecmp(yytext, "}")){

		return LR_PAREN;
	}
    if(!strcasecmp(yytext, ",")){

		return COMMA;
	}
    if(!strcasecmp(yytext, ":")){

		return COLON;
	}
    if(!strcasecmp(yytext, ";")){

		return SEMI;
	}
    if(!strcasecmp(yytext, "..")){

		return DOTDOT;
	}
    if(!strcasecmp(yytext, ".")){

		return DOT;
	}
}

{Blank} { }
{Tab} { }

{Newline}   {row+=1;column=1;}
{Other}     {column+=yyleng;}
{Integer}|-{Integer} {


    if(yyleng>14)
    {
        
        std::cout<<BOLDRED<<"Lexical error! Word length is overproof!\n";
        exit(0);
    }
    column+=yyleng;
    yylval.i_val=atoi(yytext);
    return INTEGER_VAL;
}
{Float}|-{Float} {


    if(yyleng>14)
    {
        
        std::cout<<BOLDRED<<"row: "<<row<<" Lexical error! Word length is overproof!\n";
        exit(0);
    }
    column+=yyleng;
    yylval.f_val=atof(yytext);
    return FLOAT_VAL;
}
{Char} {


    column+=yyleng;
    yylval.str=strdup(yytext);
    return CHAR_VAL;
}
{String} {


    column+=yyleng;
     yylval.str=strdup(yytext);
    return STRING_VAL;
}
{Identifier} {

    column+=yyleng;
    yylval.str=strdup(yytext);
    return IDENTIFIER;
}
{illegal} {
    //column+=yyleng;
    std::cout<<BOLDRED<<"row :"<<row<<" Lexical error! Illegal input: row "<<row<<std::endl;
    exit(0);
}

%%
