#include"define.h"
#include<cstring>
#define STACKSIZE 500
using namespace std;

struct stack_table_element
{
    int var_int;
    float var_float;
    char* var_string;
    enum ele_type{int_=0,float_=1,char_=2,string_=3,undefine=-1};
    ele_type type_;
};

int base(int level, stack_table_element *s, int b)
{
    int tempb = b;
    while(level > 0){
        tempb = s[tempb].var_int;
        level --;
    }
    return tempb;
}

void interpret() 
{
    int p, b, t,element; //t是数据站站定 b是base
    instruction i;  //instruction （指令）的类型定义（包括三个域f,l,a），请自行加入到头文件中，供其他文件共享
    struct stack_table_element s[STACKSIZE];//stacksize：数据栈大小，需自己定义
    for(int j=0;j<STACKSIZE;j++)
    {
        s[j].var_int=0;
        s[j].var_float=0;
        s[j].var_string=NULL;
        s[j].type_=stack_table_element::undefine;
    }

    
    t=0; b=1;  //t：数据栈顶指针；b：基地址；
    p=0;	// 指令指针
    s[1].var_int=0; s[2].var_int=0; s[3].var_int=0;
    do {
        i=code[p++];//code为指令存放数组，其定义请自行加入到头文件中，供其他文件共享
        switch (i.f) 
        {
        case instruction::LIT: 
            t=t+1;
            if(i.var.type_==all_type_val_value::int_)
            {
                s[t].var_int=i.var.i_val;
                s[t].type_=stack_table_element::int_;
            }
            if(i.var.type_==all_type_val_value::float_)
            {
                s[t].var_float=i.var.f_val;
                s[t].type_=stack_table_element::float_;
            }
            if(i.var.type_==all_type_val_value::char_)
            {
                s[t].var_string=strdup(i.var.v_str);
                s[t].type_=stack_table_element::char_;
            }
            if(i.var.type_==all_type_val_value::string_)
            {
                s[t].var_string=strdup(i.var.v_str);
                s[t].type_=stack_table_element::string_;
            }
            
            break;
        case instruction::OPR: 
            switch(i.a) 
            {
                case 0:
                    t=b-1;
                    p=s[t+3].var_int;
                    b=s[t+2].var_int;
                    break;
                case 1: 
                    if(s[t].type_==stack_table_element::int_)
                        s[t].var_int=-s[t].var_int;
                    if(s[t].type_==stack_table_element::float_)
                        s[t].var_float=-s[t].var_float;
                    
                    break;
                case 2: 
                    t=t-1;
                    if(s[t].type_==stack_table_element::int_ && s[t+1].type_==stack_table_element::int_)
                        s[t].var_int=s[t].var_int+s[t+1].var_int;
                    else if(s[t].type_==stack_table_element::float_ && s[t+1].type_==stack_table_element::float_)
                        s[t].var_float=s[t].var_float+s[t+1].var_float;
                    else if(s[t].type_==stack_table_element::int_ && s[t+1].type_==stack_table_element::float_)
                    {
                        s[t].type_=stack_table_element::float_;
                        s[t].var_float=float(s[t].var_int)+s[t+1].var_float;
                    }
                    else if(s[t].type_==stack_table_element::float_ && s[t+1].type_==stack_table_element::int_)
                    {
                        s[t].type_=stack_table_element::float_;
                        s[t].var_float=s[t].var_float+float(s[t+1].var_int);
                    }
                    
                    break;
                case 3:
                    t=t-1;
                    if(s[t].type_==stack_table_element::int_ && s[t+1].type_==stack_table_element::int_)
                        s[t].var_int=s[t].var_int-s[t+1].var_int;
                    else if(s[t].type_==stack_table_element::float_ && s[t+1].type_==stack_table_element::float_)
                        s[t].var_float=s[t].var_float-s[t+1].var_float;
                    else if(s[t].type_==stack_table_element::int_ && s[t+1].type_==stack_table_element::float_)
                    {
                        s[t].type_=stack_table_element::float_;
                        s[t].var_float=float(s[t].var_int)-s[t+1].var_float;
                    }
                    else if(s[t].type_==stack_table_element::float_ && s[t+1].type_==stack_table_element::int_)
                    {
                        s[t].type_=stack_table_element::float_;
                        s[t].var_float=s[t].var_float-float(s[t+1].var_int);
                    }
                    
                    break;
                case 4: 
                    t=t-1;
                    if(s[t].type_==stack_table_element::int_ && s[t+1].type_==stack_table_element::int_)
                        s[t].var_int=s[t].var_int*s[t+1].var_int;
                    else if(s[t].type_==stack_table_element::float_ && s[t+1].type_==stack_table_element::float_)
                        s[t].var_float=s[t].var_float*s[t+1].var_float;
                    else if(s[t].type_==stack_table_element::int_ && s[t+1].type_==stack_table_element::float_)
                    {
                        s[t].type_=stack_table_element::float_;
                        s[t].var_float=float(s[t].var_int)*s[t+1].var_float;
                    }
                    else if(s[t].type_==stack_table_element::float_ && s[t+1].type_==stack_table_element::int_)
                    {
                        s[t].type_=stack_table_element::float_;
                        s[t].var_float=s[t].var_float*float(s[t+1].var_int);
                    }
                    
                    break;
                case 5: 
                    t=t-1;
                    if(s[t].type_==stack_table_element::int_ && s[t+1].type_==stack_table_element::int_)
                        s[t].var_int=s[t].var_int/s[t+1].var_int;
                    else if(s[t].type_==stack_table_element::float_ && s[t+1].type_==stack_table_element::float_)
                        s[t].var_float=s[t].var_float/s[t+1].var_float;
                    else if(s[t].type_==stack_table_element::int_ && s[t+1].type_==stack_table_element::float_)
                    {
                        s[t].type_=stack_table_element::float_;
                        s[t].var_float=float(s[t].var_int)/s[t+1].var_float;
                    }
                    else if(s[t].type_==stack_table_element::float_ && s[t+1].type_==stack_table_element::int_)
                    {
                        s[t].type_=stack_table_element::float_;
                        s[t].var_float=s[t].var_float/float(s[t+1].var_int);
                    }
                    
                    break;
                case 6: 
                    if(i.var.type_==all_type_val_value::int_)
                        s[t].var_int=(s[t].var_int%2 ==1);
                    
                    break;
                case 8: 
                    t=t-1;
					if(s[t].type_==stack_table_element::int_ && s[t+1].type_==stack_table_element::int_)
                        s[t].var_int=(s[t].var_int==s[t+1].var_int);
                    else if(s[t].type_==stack_table_element::float_ && s[t+1].type_==stack_table_element::float_)
                    {
                        s[t].type_=stack_table_element::int_;
                        s[t].var_int=(s[t].var_float==s[t+1].var_float);
                    }
                    else if(s[t].type_==stack_table_element::int_ && s[t+1].type_==stack_table_element::float_)
                    {
                        s[t].type_=stack_table_element::int_;
                        s[t].var_int=(s[t].var_int==s[t+1].var_float);
                    }
                    else if(s[t].type_==stack_table_element::float_ && s[t+1].type_==stack_table_element::int_)
                    {
                        s[t].type_=stack_table_element::int_;
                        s[t].var_int=(s[t].var_float==s[t+1].var_int);
                    }                       
                    
                    break;
                case 9:
                    t=t-1;
                    if(s[t].type_==stack_table_element::int_ && s[t+1].type_==stack_table_element::int_)
                        s[t].var_int=(s[t].var_int!=s[t+1].var_int);
                    else if(s[t].type_==stack_table_element::float_ && s[t+1].type_==stack_table_element::float_)
                    {
                        s[t].type_=stack_table_element::int_;
                        s[t].var_int=(s[t].var_float!=s[t+1].var_float);
                    }
                    else if(s[t].type_==stack_table_element::int_ && s[t+1].type_==stack_table_element::float_)
                    {
                        s[t].type_=stack_table_element::int_;
                        s[t].var_int=(s[t].var_int!=s[t+1].var_float);
                    }
                    else if(s[t].type_==stack_table_element::float_ && s[t+1].type_==stack_table_element::int_)
                    {
                        s[t].type_=stack_table_element::int_;
                        s[t].var_int=(s[t].var_float!=s[t+1].var_int);
                    } 
                    
                    break;
                case 10:
                    t=t-1;
                    if(s[t].type_==stack_table_element::int_ && s[t+1].type_==stack_table_element::int_)
                        s[t].var_int=(s[t].var_int<s[t+1].var_int);
                    else if(s[t].type_==stack_table_element::float_ && s[t+1].type_==stack_table_element::float_)
                    {
                        s[t].type_=stack_table_element::int_;
                        s[t].var_int=(s[t].var_float<s[t+1].var_float);
                    }
                    else if(s[t].type_==stack_table_element::int_ && s[t+1].type_==stack_table_element::float_)
                    {
                        s[t].type_=stack_table_element::int_;
                        s[t].var_int=(s[t].var_int<s[t+1].var_float);
                    }
                    else if(s[t].type_==stack_table_element::float_ && s[t+1].type_==stack_table_element::int_)
                    {
                        s[t].type_=stack_table_element::int_;
                        s[t].var_int=(s[t].var_float<s[t+1].var_int);
                    } 
                    
                    break;
                case 11: 
                    t=t-1;
                    if(s[t].type_==stack_table_element::int_ && s[t+1].type_==stack_table_element::int_)
                        s[t].var_int=(s[t].var_int>=s[t+1].var_int);
                    else if(s[t].type_==stack_table_element::float_ && s[t+1].type_==stack_table_element::float_)
                    {
                        s[t].type_=stack_table_element::int_;
                        s[t].var_int=(s[t].var_float>=s[t+1].var_float);
                    }
                    else if(s[t].type_==stack_table_element::int_ && s[t+1].type_==stack_table_element::float_)
                    {
                        s[t].type_=stack_table_element::int_;
                        s[t].var_int=(s[t].var_int>=s[t+1].var_float);
                    }
                    else if(s[t].type_==stack_table_element::float_ && s[t+1].type_==stack_table_element::int_)
                    {
                        s[t].type_=stack_table_element::int_;
                        s[t].var_int=(s[t].var_float>=s[t+1].var_int);
                    } 
                    
                    break;
                case 12: 
                    t=t-1;
                    if(s[t].type_==stack_table_element::int_ && s[t+1].type_==stack_table_element::int_)
                        s[t].var_int=(s[t].var_int>s[t+1].var_int);
                    else if(s[t].type_==stack_table_element::float_ && s[t+1].type_==stack_table_element::float_)
                    {
                        s[t].type_=stack_table_element::int_;
                        s[t].var_int=(s[t].var_float>s[t+1].var_float);
                    }
                    else if(s[t].type_==stack_table_element::int_ && s[t+1].type_==stack_table_element::float_)
                    {
                        s[t].type_=stack_table_element::int_;
                        s[t].var_int=(s[t].var_int>s[t+1].var_float);
                    }
                    else if(s[t].type_==stack_table_element::float_ && s[t+1].type_==stack_table_element::int_)
                    {
                        s[t].type_=stack_table_element::int_;
                        s[t].var_int=(s[t].var_float>s[t+1].var_int);
                    } 
                    
                    break;
                case 13: 
                    t=t-1;
                    if(s[t].type_==stack_table_element::int_ && s[t+1].type_==stack_table_element::int_)
                        s[t].var_int=(s[t].var_int<=s[t+1].var_int);
                    else if(s[t].type_==stack_table_element::float_ && s[t+1].type_==stack_table_element::float_)
                    {
                        s[t].type_=stack_table_element::int_;
                        s[t].var_int=(s[t].var_float<=s[t+1].var_float);
                    }
                    else if(s[t].type_==stack_table_element::int_ && s[t+1].type_==stack_table_element::float_)
                    {
                        s[t].type_=stack_table_element::int_;
                        s[t].var_int=(s[t].var_int<=s[t+1].var_float);
                    }
                    else if(s[t].type_==stack_table_element::float_ && s[t+1].type_==stack_table_element::int_)
                    {
                        s[t].type_=stack_table_element::int_;
                        s[t].var_int=(s[t].var_float<=s[t+1].var_int);
                    } 
                    
                    break;
                case 14: 
                    if(s[t].type_==stack_table_element::int_)
                        cout<<s[t].var_int;
                    if(s[t].type_==stack_table_element::float_)
                        cout<<s[t].var_float;
                    if(s[t].type_==stack_table_element::char_ || s[t].type_==stack_table_element::string_)
                        cout<<s[t].var_string;
                    
                    t=t-1;
                    break;
                case 15: 
                    printf("\n");
                    break;
                case 16: 
                    t=t+1;
                    if(i.var.type_==all_type_val_value::int_)
                    {
                        
                        s[t].type_=stack_table_element::int_;
                        cin>>s[t].var_int;
                    }
                    if(i.var.type_==all_type_val_value::float_)
                    {
                        
                        s[t].type_=stack_table_element::float_;
                        cin>>s[t].var_float;
                    }
                    if(i.var.type_==all_type_val_value::char_)
                    {
                        
                        s[t].type_=stack_table_element::char_;
                        string temp;
                        cin>>temp;
                        s[t].var_string=(char*)malloc(2*sizeof(char));
                        *s[t].var_string=temp[0];
                        *(s[t].var_string+1)='\0';
                    }
                    if(i.var.type_==all_type_val_value::string_)
                    {
                        
                        s[t].type_=stack_table_element::string_;
                        string temp;
                        cin>>temp;
                        s[t].var_string=strdup(temp.c_str());
                    }
                    
                    
                    
                    break;
            }
		    break;
        case instruction::LOD: 
            
            t=t+1;
            element=base(i.l,s,b)+i.a;
            if(s[element].type_==stack_table_element::int_)
            {
                s[t].type_=stack_table_element::int_;
                s[t].var_int=s[element].var_int;
            }
            if(s[element].type_==stack_table_element::float_)
            {
                s[t].type_=stack_table_element::float_;
                s[t].var_float=s[element].var_float;
            }
            if(s[element].type_==stack_table_element::char_)
            {
                s[t].type_=stack_table_element::char_;
                s[t].var_string=strdup(s[element].var_string);
            }
            if(s[element].type_==stack_table_element::string_)
            {
                s[t].type_=stack_table_element::string_;
                s[t].var_string=strdup(s[element].var_string);
            }
            
            break;
        case instruction::STO: 
            element=base(i.l,s,b)+i.a;
            if(s[t].type_==stack_table_element::int_)
            {
                s[element].type_=stack_table_element::int_;
                s[element].var_int=s[t].var_int;
            }
            if(s[t].type_==stack_table_element::float_)
            {
                s[element].type_=stack_table_element::float_;
                s[element].var_float=s[t].var_float;
            }
            if(s[t].type_==stack_table_element::char_)
            {
                s[element].type_=stack_table_element::char_;
                s[element].var_string=strdup(s[t].var_string);
            }
            if(s[t].type_==stack_table_element::string_)
            {
                s[element].type_=stack_table_element::string_;
                s[element].var_string=strdup(s[t].var_string);
            }
            
            t=t-1;
            break;
        case instruction::CAL:
            
            s[t+1].var_int=base(i.l, s, b);
            s[t+2].var_int=b;
            s[t+3].var_int=p;
            
            b=t+1;
            p=i.a;
            break;
        case instruction::INI: 
            t=t+i.a;
            break;
        case instruction::JMP: 
            p=i.a;
            break;
        case instruction::JPC: 
            if(s[t].type_==stack_table_element::int_ && s[t].var_int==0)
                p=i.a;
            t=t-1;
            break;
        }
    }while (p!=0);
}