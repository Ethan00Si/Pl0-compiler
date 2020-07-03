#ifndef DEFINE_H
#define DEFINE_H

#define Symtable_size 100
#define Display_size 20
#define Prostack_size 20
#define RED     "\033[31m"      /* Red */

#include <stdio.h>//printf和FILE要用的
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cassert>


struct all_type_val_value //变量值
{
	int i_val;
    float f_val;
    char* v_str;
	enum define{int_=0,float_=1,char_=2,string_=3,aryint=4,aryfloat=5,undefine=-1};
    define type_; // int:0,float:1,str:2,array:3,pro:4,-1:未确定
    friend std::ostream& operator<<(std::ostream &out,all_type_val_value& v);
};
struct Symbol //符号表单层
{ 
    char* name;
	enum define{const_=1,var_=2,proc=3,undefine=-1};
    define symtype_;         //const=1, var=2, proc=3
    struct all_type_val_value var;
    int level;        //所在层次
    int addr;         //变量的偏移地址
    int next;         //指向的下一个地址
}; 

extern struct Symbol symtable[Symtable_size];
extern int sym_top;

extern int display_stack[Display_size];             //display栈        count start 0
extern int display_top;                   //display的栈顶    top is current
extern int current_Level;                 //当前的层数
extern int addr;                          //记录每个变量在运行栈中相对本过程基地址的偏移量

struct Array
{
	char* id;
    int dimension;
	int low[10];
	int high[10];
	int type_; // int:4,float:5
    int size;
};
extern struct Array ary_stack[20];
extern int array_stack_top_index;

// 过程栈，便于之后 call 调用
struct Pros
{
    char *proname;
    int level;  // 层差
    int pos;    // position in pcode stack
};

extern struct Pros pro_stack[Prostack_size];   // count start 0
extern int prostk_top;  //过程栈栈顶          // top is current

struct instruction
{
    enum f{LIT, LOD, STO, CAL, INI, JMP, JPC, OPR} f;
    int l;
    int a;
    struct all_type_val_value var;
}; 

extern struct instruction code[200];
extern int code_line;
//char *fname[]={"LIT","LOD","STO","CAL","INT","JMP","JPC","OPR"};

extern int backPatch_table[50];  //存储回填记录
extern int backPatch_table_top;  //回填栈顶

extern int whilepos[20];  //记录循环的code_line
extern int whiletop;


std::ostream& operator<<(std::ostream& out,all_type_val_value& v);
void init(); // init symtable, display_stack, pro_stack
void init_for_gen_pcode(all_type_val_value& v);

void symtable_push(char* name_,Symbol::define k,all_type_val_value &v);
void symtable_pop();
int symtable_size();
Symbol symtable_top();

int if_declared(char* search);
int find_sign(char* search);
int find_pro(char* search);
int find_ary(char* search);

int search_ary(int* search[10],all_type_val_value& v);

void gen(enum instruction::f t,int l,int a,struct all_type_val_value& v);
void backpatch(int p,int l);

int base(int level, int *s, int b);
void interpret();
#endif