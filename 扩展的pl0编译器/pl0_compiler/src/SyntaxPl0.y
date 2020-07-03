%{
#include "define.h"
#define MAGENTA "\033[35m"      /* Magenta */
extern int row,column;
extern void yyerror(char const* s);
extern int yylex(void);

%}

%union{
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

%start Program
%token<i_val> INTEGER_VAL 
%token<f_val> FLOAT_VAL
%token<str> CHAR_VAL STRING_VAL CMP
%token<str> IDENTIFIER
%type<i_val> ArrayType VarType
%type<count> Term Expr Factor
%type<array__> Dimension GetDi
%type<Identi> Identifier
%token PROCEDURE IF THEN WHILE DO READ WRITE CALL _BEGIN_ END CONST VAR ODD FOR TO REPEAT UNTIL ARRAY OF INT_ FLOAT CHAR STRING
%token SL_PAREN SR_PAREN ML_PAREN MR_PAREN LL_PAREN LR_PAREN COMMA COLON SEMI DOTDOT DOT
%left PLUS MINUS
%left TIMES DIVIDE
%nonassoc ASSIGN
%nonassoc LOWERELSE
%nonassoc ELSE

%%

Program     : SubPro DOT {
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::OPR,0,0,p);
              }
            ;
SubPro      : BeforeDec DeclarePart BeforeSta Statement {
              }
            | BeforeDec BeforeSta Statement {
              }
            ;
BeforeDec   : {
                if(symtable_size()!=0){
                  display_top++;
                  display_stack[display_top]=symtable_size()+1;
                }
                backPatch_table[++backPatch_table_top]=code_line;
                
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::JMP,0,0,p);
              }
            ;
BeforeSta   : {
                if(backPatch_table_top>-1){
                  backpatch(backPatch_table[backPatch_table_top--],code_line);
                }
                all_type_val_value p;
                init_for_gen_pcode(p);
                if(display_stack[display_top]==1){
                  gen(instruction::INI,0,sym_top+3,p);
                }
                else
                {
                  gen(instruction::INI,0,sym_top-display_stack[display_top]+1+3,p);
                }
              }
            ;
DeclarePart : ConstDec {
              }
            | ConstDec VarDec {
              }
            | ConstDec ProDec {
              }
            | ConstDec VarDec ProDec {
              }
            | VarDec ProDec {
              }
            | VarDec {
              }
            | ProDec {
              }
            ;

ConstDec    : ConstDec CONST ConstDef SEMI {
              }
            | CONST ConstDef SEMI {
              }
            ;
ConstDef    : ConstDef COMMA CDefine {
              }
            | CDefine {
              }
            ;
CDefine     :IDENTIFIER ASSIGN INTEGER_VAL {                
                if(if_declared($1)==0)
                {
                    struct all_type_val_value temp;
                    init_for_gen_pcode(temp);
                    temp.i_val=$3;
                    temp.type_=all_type_val_value::int_;
                    symtable_push($1,Symbol::const_,temp);
                }
              }
            | IDENTIFIER ASSIGN FLOAT_VAL {
                if(if_declared($1)==0)
                {
                    struct all_type_val_value temp;
                    init_for_gen_pcode(temp);
                    temp.f_val=$3;
                    temp.type_=all_type_val_value::float_;
                    symtable_push($1,Symbol::const_,temp);
                }
             }
            ;

VarDec      : VarDec VAR IdentiDef SEMI {
              }
            | VAR IdentiDef SEMI {
              }
            ;
IdentiDef   : IdentiDef COMMA IDefine {
              
              }
            | IDefine {
              
              }
            ;
IDefine     : IDENTIFIER OF VarType {
                if(if_declared($1)==0)
                {
                    struct all_type_val_value temp;
                    init_for_gen_pcode(temp);
                    temp.type_=all_type_val_value::define($3);
                    symtable_push($1,Symbol::var_,temp);
                }
              }
              | IDENTIFIER ARRAY ML_PAREN Dimension MR_PAREN OF ArrayType {
                if(if_declared($1)==0)
                {
                    array_stack_top_index++;
                    ary_stack[array_stack_top_index].id=$1;
                    ary_stack[array_stack_top_index].dimension=$4.dimension;
                    ary_stack[array_stack_top_index].type_=$7;
                    for(int index=0;index<$4.dimension;index++)
                    {
                      ary_stack[array_stack_top_index].low[index]=$4.low[index];
                      ary_stack[array_stack_top_index].high[index]=$4.high[index];
                    }
                    int s=$4.high[0]-$4.low[0]+1;
	                  if($4.dimension>1)
		                  for(int i=1;i<$4.dimension;i++)
			                  s=s*($4.high[i]-$4.low[i]+1);
	                  ary_stack[array_stack_top_index].size=s;
                    
                    all_type_val_value temp;
                    init_for_gen_pcode(temp);
                    temp.type_=all_type_val_value::define($7);                
                    for(int i=0;i<s;i++)
                      symtable_push($1,Symbol::var_,temp);
                }
              }
            
            ;
Dimension   : Dimension COMMA INTEGER_VAL DOTDOT INTEGER_VAL {
                $$.dimension=$1.dimension+1;
                $$.low[$1.dimension]=$3;
                $$.high[$1.dimension]=$5;
              }
            | INTEGER_VAL DOTDOT INTEGER_VAL {
                $$.dimension=1;
                $$.low[0]=$1;
                $$.high[0]=$3;
              }
            ;
ArrayType   : INT_ {
                $$=4;
              }
            | FLOAT {
                $$=5;
              }
            ;
VarType     : INT_ {
                $$=0;
              }
            | FLOAT {
                $$=1;
              }
            | CHAR {
                $$=2;
              }
            | STRING {
                $$=3;
              }
            ;

ProDec      : ProDec ProceHead SubPro SEMI {
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::OPR,0,0,p);
                current_Level--;
                symtable_pop();
                addr=2+symtable_size();
              }
            | ProceHead SubPro SEMI {
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::OPR,0,0,p);
                current_Level--;
                symtable_pop();
                addr=2+symtable_size();
              }
            ;
ProceHead   : PROCEDURE IDENTIFIER SEMI {
                addr=3;
                if(if_declared($2)==0 && find_pro($2)==-1)
                {
                    
                    struct all_type_val_value temp;
                    init_for_gen_pcode(temp);
                    symtable_push($2,Symbol::proc,temp);
                    current_Level++;
                }    
              }
            ;

Statement   : ComplexS {
              }
            | { 
              }
            ;
ComplexS    : _BEGIN_ States END {
              }
            ;
States      : Statements {
              }
            | States Statements {
              }
Statements  : AssignS SEMI {
              }
            | CondiS {
              }
            | Call_Func SEMI{
              }
            | Read_Func SEMI{
              }
            | Write_Func SEMI{
              }
            | While_Loop SEMI{
              }
            | For_Loop SEMI{
              }
            | Repeat_Loop {
              }
            ;


Identifier  : IDENTIFIER ML_PAREN GetDi MR_PAREN {                              
                int arypos=find_ary($1);
                if(arypos==-1)
                {
                  std::cout<<MAGENTA<<"Semantic error! "<<$1<<" isn't  array!"<<std::endl;
                  exit(1);
                }
                if(ary_stack[arypos].dimension != $3.dimension)
                { // dimension error
                  std::cout<<MAGENTA<<"Semantic error! "<<$1<<"\'s dimension is not right!"<<std::endl;
                  exit(1);
                }
                for(int i=0;i<$3.dimension;i++)
                { // search error
                  if($3.search[i]<ary_stack[arypos].low[i] || $3.search[i]>ary_stack[arypos].high[i])
                  {
                    std::cout<<MAGENTA<<$3.search[i]<<' '<<ary_stack[arypos].low[i]<<' '<<ary_stack[arypos].high[i]<<std::endl;
                    std::cout<<MAGENTA<<"Semantic Error! Array Dimension Over Bound!"<<std::endl;
                    exit(1);
                  }
                }
                
                int offset=$3.search[0]-ary_stack[arypos].low[0];
                if($3.dimension>1)
                {
                  for(int i=1;i<$3.dimension;i++)
                  {
                    offset=offset*(ary_stack[arypos].high[i]-ary_stack[arypos].low[i]+1);
                    offset=offset+$3.search[i]-ary_stack[arypos].low[i];
                  }
                }
                $$.offset=offset;
                $$.id=$1;
                $$.type_=ary_stack[arypos].type_;
              }
            | IDENTIFIER {                
                int pos=find_sign($1);
                if(symtable[pos].symtype_==Symbol::proc)
                {
                  exit(1);
                }
                if(symtable[pos].var.type_==all_type_val_value::aryint || symtable[pos].var.type_==all_type_val_value::aryfloat)
                {
                  
                  exit(1);
                }

                $$.offset=0;
                $$.id=$1;  
                $$.type_=symtable[pos].var.type_;                              
              }
            ;
GetDi       : GetDi COMMA Expr {
                $$.dimension=$1.dimension+1;
                if($3.type_==0)
                  $$.search[$1.dimension]=$3.i_val;
                else
                {
                  std::cout<<MAGENTA<<"Semantic Error! Array index must be int!"<<std::endl;
                  exit(1);
                }
              }
            | Expr {
                $$.dimension=1;
                if($1.type_==0)
                  $$.search[0]=$1.i_val;
                else
                {
                  std::cout<<MAGENTA<<"Semantic Error! Array index must be int!"<<std::endl;
                  exit(1);
                }
              }
            ;
AssignS     : Identifier ASSIGN Expr {
                int pos=find_sign($1.id);
                pos+=$1.offset;
                if(symtable[pos].symtype_!=Symbol::var_)
                { // type error
                  std::cout<<MAGENTA<<"Semaantic Error! "<<$1.id<<" type error!"<<std::endl;
                  exit(1);
                }
                
                all_type_val_value p;
                init_for_gen_pcode(p);
                p.type_=all_type_val_value::define($3.type_);
                if($3.type_==0)
                {
                  p.i_val=$3.i_val;
                  symtable[pos].var.i_val=$3.i_val;
                }
                if($3.type_==1)
                {
                  p.f_val=$3.f_val;
                  symtable[pos].var.f_val=$3.f_val;
                } 
                gen(instruction::STO,current_Level-symtable[pos].level,symtable[pos].addr,p);
              }
            | Identifier ASSIGN CHAR_VAL {
                if($1.type_!=2)
                {
                  std::cout<<MAGENTA<<"Semantic Error! "<<$1.id<<" is not char type!"<<std::endl;
                  exit(1);
                }

                int pos=find_sign($1.id);
                all_type_val_value p;
                init_for_gen_pcode(p);
                p.type_=all_type_val_value::char_;
                char* temp=strdup($3);
                temp[strlen(temp)-1]='\0';
                p.v_str=temp+1;
                symtable[pos].var.v_str=strdup($3);
                gen(instruction::LIT,0,0,p);
                gen(instruction::STO,current_Level-symtable[pos].level,symtable[pos].addr,p);
              }
            | Identifier ASSIGN STRING_VAL {
                if($1.type_!=3)
                {
                  std::cout<<MAGENTA<<"Setanmic Error! "<<$1.id<<" is not string type!"<<std::endl;
                  exit(1);
                }

                int pos=find_sign($1.id);
                all_type_val_value p;
                init_for_gen_pcode(p);
                p.type_=all_type_val_value::string_;
                char* temp=strdup($3);
                temp[strlen(temp)-1]='\0';
                p.v_str=temp+1;
                symtable[pos].var.v_str=strdup($3);
                gen(instruction::LIT,0,0,p);
                gen(instruction::STO,current_Level-symtable[pos].level,symtable[pos].addr,p);
              }
            ;
Condition   : Expr CMP Expr {
                all_type_val_value p;
                init_for_gen_pcode(p);
                if($1.type_==0 && $3.type_==0)
                {
                  if(!strcmp($2,"=="))  gen(instruction::OPR,0,8,p);
                  if(!strcmp($2,"!="))  gen(instruction::OPR,0,9,p);
                  if(!strcmp($2,"<"))   gen(instruction::OPR,0,10,p);
                  if(!strcmp($2,"<="))  gen(instruction::OPR,0,13,p);
                  if(!strcmp($2,">"))   gen(instruction::OPR,0,12,p);
                  if(!strcmp($2,">="))  gen(instruction::OPR,0,11,p);
                }
                else if($1.type_==1 && $3.type_==1)
                {
                  if(!strcmp($2,"=="))  gen(instruction::OPR,0,8,p);
                  if(!strcmp($2,"!="))  gen(instruction::OPR,0,9,p);
                  if(!strcmp($2,"<"))   gen(instruction::OPR,0,10,p);
                  if(!strcmp($2,"<="))  gen(instruction::OPR,0,13,p);
                  if(!strcmp($2,">"))   gen(instruction::OPR,0,12,p);
                  if(!strcmp($2,">="))  gen(instruction::OPR,0,11,p);
                }
                else
                {
                  std::cout<<MAGENTA<<"Type Error! Only int or float in condition!"<<std::endl;
                  exit(1);
                }
              }
            | ODD Expr {
                if($2.type_==0)
                {
                  all_type_val_value p;
                  init_for_gen_pcode(p);
                  gen(instruction::OPR,0,6,p);
                }
                else
                {
                  std::cout<<MAGENTA<<"Type Error! Only int in odd condition!"<<std::endl;
                  exit(1);
                }
              }
            ;
CondiS      : IF Condition BeforeThen THEN ComplexS SEMI %prec LOWERELSE {
                backpatch(backPatch_table[backPatch_table_top--],code_line);
              }
            | IF Condition BeforeThen THEN ComplexS SEMI ELSE BeforeElseDo ComplexS SEMI {
                backpatch(backPatch_table[backPatch_table_top--],code_line);
              }
            ;
BeforeThen  : {
                backPatch_table[++backPatch_table_top]=code_line;
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::JPC,0,0,p);
              }
            ;
BeforeElseDo: {
                backpatch(backPatch_table[backPatch_table_top--],code_line+1);
                backPatch_table[++backPatch_table_top]=code_line;
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::JMP,0,0,p);
              }
            ;
Expr        : Expr PLUS Term {
                if($1.type_==0 && $3.type_==0)
                {
                    $$.type_=0;
                    $$.i_val=$1.i_val+$3.i_val;
                }
                else if($1.type_==1 && $3.type_==1)
                {
                    $$.type_=1;
                    $$.f_val=$1.f_val+$3.f_val;
                }
                else if($1.type_==1 && $3.type_==0)
                {
                    $$.type_=1;
                    $$.f_val=$1.f_val+$3.i_val;
                }
                else if($1.type_==0 && $3.type_==1)
                {
                    $$.type_=1;
                    $$.f_val=$1.i_val+$3.f_val;
                }
                else
                {
                  std::cout<<MAGENTA<<"Type Error!"<<std::endl;
                  exit(1);
                }
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::OPR,0,2,p);
              }
            | Expr MINUS Term {
                if($1.type_==0 && $3.type_==0)
                {
                    $$.type_=0;
                    $$.i_val=$1.i_val-$3.i_val;
                }
                else if($1.type_==1 && $3.type_==1)
                {
                    $$.type_=1;
                    $$.f_val=$1.f_val-$3.f_val;
                }
                else if($1.type_==1 && $3.type_==0)
                {
                    $$.type_=1;
                    $$.f_val=$1.f_val-$3.i_val;
                }
                else if($1.type_==0 && $3.type_==1)
                {
                    $$.type_=1;
                    $$.f_val=$1.i_val-$3.f_val;
                }
                else
                {
                  std::cout<<MAGENTA<<"Type Error!"<<std::endl;
                  exit(1);
                }
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::OPR,0,3,p);
              }
            | PLUS Term {
                //$$=$2;
                if($2.type_==0)
                {
                  $$.type_=0;
                  $$.i_val=$2.i_val;
                }
                else if($2.type_==1)
                {
                  $$.type_=1;
                  $$.f_val=$2.f_val;
                }
                else
                {
                  std::cout<<MAGENTA<<"Type Error!"<<std::endl;
                  exit(1);
                }
              }
            | MINUS Term {
                //$$=-$2;
                if($2.type_==0)
                {
                    $$.type_=0;
                    $$.i_val=-$2.i_val;
                }
                else if($2.type_==1)
                {
                    $$.type_=1;
                    $$.f_val=-$2.f_val;
                }
                else
                {
                  std::cout<<MAGENTA<<"Type Error!"<<std::endl;
                  exit(1);
                }
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::OPR,0,1,p);
              }
            | Term {
                //$$=$1;
                if($1.type_==0)
                {
                  $$.type_=0;
                  $$.i_val=$1.i_val;
                }
                else if($1.type_==1)
                {
                  $$.type_=1;
                  $$.f_val=$1.f_val;
                }
                else
                {
                  std::cout<<MAGENTA<<"Type Error!"<<std::endl;
                  exit(1);
                }
              }
            ;
Term        : Term TIMES Factor {
                //$$=$1*$3;
                if($1.type_==0 && $3.type_==0)
                {
                    $$.type_=0;
                    $$.i_val=$1.i_val*$3.i_val;
                }
                else if($1.type_==1 && $3.type_==1)
                {
                    $$.type_=1;
                    $$.f_val=$1.f_val*$3.f_val;
                }
                else if($1.type_==1 && $3.type_==0)
                {
                    $$.type_=1;
                    $$.f_val=$1.f_val*$3.i_val;
                }
                else if($1.type_==0 && $3.type_==1)
                {
                    $$.type_=1;
                    $$.f_val=$1.i_val*$3.f_val;
                }
                else
                {
                  std::cout<<MAGENTA<<"Type Error!"<<std::endl;
                  exit(1);
                }
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::OPR,0,4,p);
              }
            | Term DIVIDE Factor {
                //$$=$1/$3;
                if($1.type_==0 && $3.type_==0)
                {
                    $$.type_=0;
                    if($3.i_val==0)
                      $$.i_val=0;
                    else
                      $$.i_val=$1.i_val/$3.i_val;
                }
                else if($1.type_==1 && $3.type_==1)
                {
                    $$.type_=1;
                    if($3.f_val==0)
                      $$.f_val=0;
                    else
                      $$.f_val=$1.f_val/$3.f_val;
                }
                else if($1.type_==1 && $3.type_==0)
                {
                    $$.type_=1;
                    if($3.i_val==0)
                      $$.f_val=0;
                    else
                      $$.f_val=$1.f_val/$3.i_val;
                }
                else if($1.type_==0 && $3.type_==1)
                {
                    $$.type_=1;
                    if($3.f_val==0)
                      $$.f_val=0;
                    else
                      $$.f_val=$1.i_val/$3.f_val;
                }
                else
                {
                  std::cout<<MAGENTA<<"Type Error!"<<std::endl;
                  exit(1);
                }
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::OPR,0,5,p);
              }
            | Factor {
                //$$=$1;
                if($1.type_==0)
                {
                  $$.type_=0;
                  $$.i_val=$1.i_val;
                }
                else if($1.type_==1)
                {
                  $$.type_=1;
                  $$.f_val=$1.f_val;
                }
                else
                {
                  std::cout<<MAGENTA<<"Type Error!"<<std::endl;
                  exit(1);
                }
              }
            ;
Factor      : Identifier {
                int pos=find_sign($1.id);
                pos+=$1.offset;
                all_type_val_value p;
                init_for_gen_pcode(p);
                if($1.type_==0 ||$1.type_==4)
                {
                  $$.type_=0;
                  $$.i_val=symtable[pos].var.i_val;
                  p.type_=all_type_val_value::int_;
                  p.i_val=$$.i_val;
                  if(symtable[pos].symtype_==Symbol::const_)
                    gen(instruction::LIT,0,symtable[pos].var.i_val,p);
                  if(symtable[pos].symtype_==Symbol::var_)
                    gen(instruction::LOD,current_Level-symtable[pos].level,symtable[pos].addr,p);
                }
                if($1.type_==1||$1.type_==5)
                {
                  $$.type_=1;
                  $$.f_val=symtable[pos].var.f_val;
                  p.type_=all_type_val_value::float_;
                  p.f_val=$$.f_val;
                  if(symtable[pos].symtype_==Symbol::const_)
                    gen(instruction::LIT,0,symtable[pos].var.f_val,p);
                  if(symtable[pos].symtype_==Symbol::var_)
                    gen(instruction::LOD,current_Level-symtable[pos].level,symtable[pos].addr,p);
                }   
              }
            | INTEGER_VAL {
                //$$=$1;
                $$.type_=0;
                $$.i_val=$1;
                all_type_val_value p;
                init_for_gen_pcode(p);
                p.type_=all_type_val_value::int_;
                p.i_val=$1;
                gen(instruction::LIT,0,$1,p);
              }
            | FLOAT_VAL {
                //$$=$1;
                $$.type_=1;
                $$.f_val=$1;
                all_type_val_value p;
                init_for_gen_pcode(p);
                p.type_=all_type_val_value::float_;
                p.f_val=$1;
                gen(instruction::LIT,0,$1,p);
              }
            | SL_PAREN Expr SR_PAREN {
                //$$=$2;
                if($2.type_==0)
                {
                  $$.type_=0;
                  $$.i_val=$2.i_val;
                }
                else if($2.type_==1)
                {
                  $$.type_=1;
                  $$.f_val=$2.f_val;
                }
                else
                {
                  std::cout<<MAGENTA<<"Type Error!"<<std::endl;
                  exit(1);
                }
              }
            ;
While_Loop      : WHILE BeforeCond Condition DO BeforeCondDo Statement {
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::JMP,0,whilepos[whiletop--],p);
                backpatch(backPatch_table[backPatch_table_top--],code_line);
              }
            ;
For_Loop        : FOR AssignS TO BeforeCond Condition DO BeforeCondDo Statement {
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::JMP,0,whilepos[whiletop--],p);
                backpatch(backPatch_table[backPatch_table_top--],code_line);
              }
            ;
Repeat_Loop     : REPEAT BeforeRepeat Statement SEMI UNTIL Condition { 
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::JPC,0,whilepos[whiletop--],p);
              }
            ;
BeforeCond  : {
                whilepos[++whiletop]=code_line;
              }
            ;
BeforeCondDo: {
                backPatch_table[++backPatch_table_top]=code_line;
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::JPC,0,0,p);
              }
            ;

BeforeRepeat: {
                whilepos[++whiletop]=code_line;
              }
            ;

Call_Func       : CALL SL_PAREN IDENTIFIER SR_PAREN {
                if(find_pro($3)==-1)
                {
                  std::cout<<MAGENTA<<"Semantic error! "<<$3<<" not found!"<<std::endl;
                  exit(1);
                }

                int pos=find_pro($3);
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::CAL,current_Level-pro_stack[pos].level,pro_stack[pos].pos-1,p);
              }
            ;
Read_Func       : READ SL_PAREN Identifier SR_PAREN{
                int pos=find_sign($3.id);
                pos+=$3.offset;
                all_type_val_value p;
                init_for_gen_pcode(p);
                if(symtable[pos].var.type_==0||symtable[pos].var.type_==4)
                {
                  p.type_=all_type_val_value::int_;
                  gen(instruction::OPR,0,16,p);
                  gen(instruction::STO,current_Level-symtable[pos].level,symtable[pos].addr,p);
                }
                if(symtable[pos].var.type_==1||symtable[pos].var.type_==5)
                {
                  p.type_=all_type_val_value::float_;
                  gen(instruction::OPR,0,16,p);
                  gen(instruction::STO,current_Level-symtable[pos].level,symtable[pos].addr,p);
                }
                if(symtable[pos].var.type_==2)
                {
                  p.type_=all_type_val_value::char_;
                  gen(instruction::OPR,0,16,p);
                  gen(instruction::STO,current_Level-symtable[pos].level,symtable[pos].addr,p);
                }
                if(symtable[pos].var.type_==3)
                {
                  p.type_=all_type_val_value::string_;
                  gen(instruction::OPR,0,16,p);
                  gen(instruction::STO,current_Level-symtable[pos].level,symtable[pos].addr,p);
                }
                
              }
            ;
Write_Func      : WRITE SL_PAREN Identifier SR_PAREN{
                int pos=find_sign($3.id);
                pos+=$3.offset;
                all_type_val_value p;
                init_for_gen_pcode(p);
                if($3.type_==0 ||$3.type_==4)
                {
                  p.type_=all_type_val_value::int_;
                  p.i_val=symtable[pos].var.i_val;
                  if(symtable[pos].symtype_==Symbol::const_)
                    gen(instruction::LIT,0,symtable[pos].var.i_val,p);
                  if(symtable[pos].symtype_==Symbol::var_)
                    gen(instruction::LOD,current_Level-symtable[pos].level,symtable[pos].addr,p);
                }
                if($3.type_==1||$3.type_==5)
                {
                  p.type_=all_type_val_value::float_;
                  p.f_val=symtable[pos].var.f_val;
                  
                  if(symtable[pos].symtype_==Symbol::const_)
                    gen(instruction::LIT,0,symtable[pos].var.f_val,p);
                  if(symtable[pos].symtype_==Symbol::var_)
                    gen(instruction::LOD,current_Level-symtable[pos].level,symtable[pos].addr,p);
                }
                if($3.type_==2)
                {
                  p.type_=all_type_val_value::char_;
                  if(symtable[pos].symtype_==Symbol::var_)
                    gen(instruction::LOD,current_Level-symtable[pos].level,symtable[pos].addr,p);
                }
                if($3.type_==3)
                {
                  p.type_=all_type_val_value::string_;
                  if(symtable[pos].symtype_==Symbol::var_)
                    gen(instruction::LOD,current_Level-symtable[pos].level,symtable[pos].addr,p);
                }
                gen(instruction::OPR,0,14,p);
                gen(instruction::OPR,0,15,p);
              }
            | WRITE SL_PAREN CHAR_VAL SR_PAREN {
              all_type_val_value p;
              init_for_gen_pcode(p);
              p.type_=all_type_val_value::char_;
              char* temp=strdup($3);
              temp[strlen(temp)-1]='\0';
              p.v_str=temp+1;
              gen(instruction::LIT,0,0,p);
              init_for_gen_pcode(p);
              gen(instruction::OPR,0,14,p);
              gen(instruction::OPR,0,15,p);
            }
            | WRITE SL_PAREN STRING_VAL SR_PAREN {
              all_type_val_value p;
              init_for_gen_pcode(p);
              p.type_=all_type_val_value::string_;
              char* temp=strdup($3);
              temp[strlen(temp)-1]='\0';
              p.v_str=temp+1;
              gen(instruction::LIT,0,0,p);
              init_for_gen_pcode(p);
              gen(instruction::OPR,0,14,p);
              gen(instruction::OPR,0,15,p);
            }
            ;

%%

void yyerror(char const* s)
{
    //printf("%s,(%d,%d)\n",s,row,column);
    std::cout<<MAGENTA<<s<<" ("<<row<<","<<column<<")"<<std::endl;
    return;
}