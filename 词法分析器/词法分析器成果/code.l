%{
#include<stdio.h>
int col=1, line=1;
void print_out(char type);
%}


digit [0-9]
letter [a-zA-Z]
identifier {letter}({letter}|{digit})*
integer {digit}{digit}*
real -?{digit}+(\.{digit}+)([Ee][-+][0-9]+)?
whitespace [ ]
newline [\n]
return_ [\r]
col_8 [\t]
char (\'[^ \n\r\t]\')
string (\".{2,}\")
illegal ([^a-zA-Z1-9\t\n>=<:\'\(\)\;\[\]\.\!\+\-\/\*\"\,]+)

%%
if|then|while|do|read|write|call|begin|end|const|var|procedure|odd|for|to|repeat|until|Array|of   {print_out('K');col = col + yyleng;}

{whitespace} {
	print_out('T');
col = col + yyleng;
} /*空格*/
{newline} {line += 1; col = 1;} /*换行*/
{return_} {print_out('T');col = 1;} /*\r返回当前行第一列*/
{col_8} {print_out('T');col += 8;} /*制表符列加8*/

{integer}|{real} {
	/*检查长度*/
	if(yyleng > 14)
	{
		printf("Error! The length of this number is too long!\n");
		exit(0);
	}
	print_out('C');col = col + yyleng;
}
{char} {
	if(yyleng > 3){
		/*char类型  长度为3*/
		printf("The length of char must be 1.");
		exit(0);
	}
	print_out('K'); col = col + yyleng;
}

{identifier} {
	/*检查长度是否超出范围*/
	if(yyleng > 10){
		printf("Error! The length of this idetifier is too long!\n");
		exit(0);
	}
	print_out('I');col = col + yyleng;
}
{string} {
	print_out('K'); col = col + yyleng;
}
"+"|"-"|"*"|"/"|"#"|"<"|">"|"="|"<>"|"!="|">="|"<="|":="	{print_out('O');col = col + yyleng;} /*算符*/
"\["|"("|")"|","|":"|";"|"."|"\]"|".."		{print_out('D');col = col + yyleng;} /*界符*/
{illegal} {
	/*含有非法字符的字符串*/
	/*数字开头的identifier*/
	/*real里是错误类型*/
	printf("This word is incorrect! ");
	print_out('T');
}

%%

void print_out(char type)
{
     printf("%s : %c, (%d,%d)\n",yytext,type,line,col);
}

int main(int argc,char** argv)
{

    FILE * fIn;			
	switch(argc)
	{
	case 1: 			//打开缺省文件		
		fIn=fopen("test.frag","r");	
		if(fIn==NULL){
			printf("default file is not found\n");
			exit(1);
		}
		else	yyin = fIn;
		break;		
	case 2: 			//打开指定文件
		if ((fIn = fopen(argv[1],"r")) == NULL) {
	            printf("File %s is not found.\n",argv[1]);
	            exit(1);
	        }
	        else	yyin=fIn;
		break;
	default:
		printf("useage:flex [filename]\n");
		exit(1);
	}
    yylex();
  	
	
	fclose(fIn);
	return 0;

}