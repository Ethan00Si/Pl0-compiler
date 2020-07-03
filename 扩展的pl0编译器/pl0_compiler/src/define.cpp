#include "define.h"
using namespace std;

struct Symbol symtable[Symtable_size];
int sym_top = 0;
int display_stack[Display_size]; //display栈
int display_top = 0;			 //display的栈顶
int current_Level = 0;			 //当前的层数
int addr = 3;					 //记录每个变量在运行栈中相对本过程基地址的偏移量

struct Array ary_stack[20];
int array_stack_top_index = -1;

struct Pros pro_stack[Prostack_size];
int prostk_top = -1; //过程栈栈顶

struct instruction code[200];
int code_line = 0;
int backPatch_table[50];	   //记录回填的位置
int backPatch_table_top = -1; //回填栈顶
int whilepos[20];	   //记录循环的code_line
int whiletop = -1;

ostream &operator<<(ostream &out, all_type_val_value &v)
{
	out << "type:" << v.type_ << ' ';
	if (v.type_ == all_type_val_value::int_)
		out << "i_val:" << v.i_val;
	else if (v.type_ == all_type_val_value::float_)
		out << "f_val:" << v.f_val;
	else if (v.type_ == all_type_val_value::char_)
		out << "char:" << v.v_str;
	else if (v.type_ == all_type_val_value::string_)
		out << "string:" << v.v_str;
	return out;
}

void init()
{
	for (int i = 0; i < Symtable_size; i++)
	{
		// Symbol init
		symtable[i].name = NULL;
		symtable[i].symtype_ = Symbol::undefine;
		symtable[i].level = -1;
		symtable[i].addr = -1;
		symtable[i].next = -1;
		// all_type_val_value init
		symtable[i].var.i_val = 0;
		symtable[i].var.f_val = 0;
		symtable[i].var.v_str = NULL;
		symtable[i].var.type_ = all_type_val_value::undefine;
	}

	for (int i = 0; i < Display_size; i++)
		display_stack[i] = 0;
	display_stack[0] = 1;

	for (int i = 0; i < 20; i++)
	{
		ary_stack[i].id = NULL;
		ary_stack[i].dimension = 0;
		ary_stack[i].type_ = -1;
		ary_stack[i].size = 0;
		for (int j = 0; j < 10; j++)
		{
			ary_stack[i].low[j] = -1;
			ary_stack[i].high[j] = -1;
		}
	}

	for (int i = 0; i < Prostack_size; i++)
	{
		pro_stack[i].proname = NULL;
		pro_stack[i].level = -1;
		pro_stack[i].pos = -1;
	}

	for (int i = 0; i < 50; i++)
		backPatch_table[i] = 0;
	for (int i = 0; i < 20; i++)
		whilepos[i] = 0;

	return;
}

void init_for_gen_pcode(all_type_val_value &v)
{
	v.type_ = all_type_val_value::undefine;
	v.i_val = 0;
	v.f_val = 0;
	v.v_str = NULL;
	return;
}

int symtable_size()
{
	return sym_top;
}

Symbol top_symbol()
{
	return symtable[sym_top];
}

void symtable_push(char *name_, Symbol::define k, all_type_val_value &v) // name kind val
{

	int presymbol = sym_top;
	sym_top++;
	
	symtable[sym_top].name = strdup(name_);
	symtable[sym_top].symtype_ = k;
	symtable[sym_top].level = current_Level;
	symtable[sym_top].next = 0;
	symtable[sym_top].var.type_ = v.type_;
	
	if(k==Symbol::const_)
	{
		if (v.type_ == all_type_val_value::int_)
			symtable[sym_top].var.i_val = v.i_val;
		else if (v.type_ == all_type_val_value::float_)
			symtable[sym_top].var.f_val = v.f_val;
	}

	if (sym_top > 0 && symtable[presymbol].symtype_ != Symbol::proc)
		symtable[presymbol].next = sym_top;
	if (k == 2)
		symtable[sym_top].addr = addr++;
	if (k == 3)
	{
		prostk_top++;
		pro_stack[prostk_top].proname = strdup(name_);
		pro_stack[prostk_top].pos = code_line + 1;
		pro_stack[prostk_top].level = current_Level;
	}
	//cout<<"end push"<<endl;
}

void symtable_pop()
{
	if (sym_top == -1)
	{
		printf("Overflow symtable pop size.\n");
		exit(1);
	}
	int prostart = display_stack[display_top] - 1;
	for (int i = sym_top; i > prostart; i--)
	{
		symtable[i].name = NULL;
		symtable[i].symtype_ = Symbol::undefine;
		symtable[i].level = -1;
		symtable[i].addr = -1;
		symtable[i].next = -1;
		init_for_gen_pcode(symtable[i].var);
	}
	sym_top = prostart;
	symtable[sym_top].next = 0;
	display_stack[display_top] = 0;
	display_top--;
}

int if_declared(char *search)
{ // 标识符在当前层次是否定义过
	int current = display_stack[display_top];
	if (current == 0)
		return 0;
	while (current <= sym_top)
	{
		if (strcmp(symtable[current].name, search) == 0)
		{
			printf("Error! '%s' has been declared!\n", search);
			exit(1);
		}
		if (symtable[current].next == 0)
			break;
		current++;
	}
	//std::cout<<"hasnt been declared"<<std::endl;
	return 0;
}

int find_sign(char *search)
{ // 查找标识符在符号栈中的位置
	int distop = display_top;
	int pos;
	while (distop >= 0)
	{
		pos = display_stack[distop];
		while (pos <= sym_top)
		{
			if (strcmp(search, symtable[pos].name) == 0 && symtable[pos].symtype_ != Symbol::proc)
				return pos;
			if (symtable[pos].next == 0)
				break;
			pos++;
		}
		distop--;
	}
	printf("Assign Error! '%s' has not been declared!\n", search);
	exit(1);
}

int find_pro(char *search)
{
	for (int i = 0; i <= prostk_top; i++)
	{
		if (strcmp(search, pro_stack[i].proname) == 0)
			return i;
	}
	return -1;
}

int find_ary(char *search)
{
	if(array_stack_top_index==-1)
		return -1;
	for(int i=array_stack_top_index;i>=0;i--)
	{
		if(strcmp(ary_stack[i].id,search)==0)
			return i;
	}
	return -1;
}

void gen(enum instruction::f t, int l, int a,struct all_type_val_value& v)
{
	code[code_line].f = t;
	code[code_line].l = l;
	code[code_line].a = a;
	code[code_line].var.type_=v.type_;
	if(v.type_==0 || v.type_==4)
		code[code_line].var.i_val=v.i_val;
	if(v.type_==1 || v.type_==5)
		code[code_line].var.f_val=v.f_val;
	if(v.v_str!=NULL && (v.type_==2 || v.type_==3))
		code[code_line].var.v_str=strdup(v.v_str);
	code_line++;
	return;
}

void backpatch(int p, int l)
{				   //回填函数, 参数为回填位置和回填内容
	code[p].a = l; //将第p条code的a域改为l
}