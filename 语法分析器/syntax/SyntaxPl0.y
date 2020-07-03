%{
#include"main.h"

FILE *fi;
FILE *fh;
extern int row,column;

extern void yyerror(char const* s);
extern int yylex(void);
%}

%start Program
%token<m_int> INTEGER_VAL
%token<m_float> FLOAT_VAL
%token<m_char> CHAR_VAL
%token<m_string> STRING_VAL
%token<m_ID> IDENTIFIER
%token PROCEDURE IF THEN ELSE WHILE DO READ WRITE CALL _BEGIN_ END CONST VAR ODD FOR TO REPEAT UNTIL ARRAY OF INT FLOAT CHAR STRING
%token SL_PAREN SR_PAREN LEFTBRAC RIGHTBRAC LL_PAREN LR_PAREN COMMA COLON SEMI OMIT DOT
%left PLUS MINUS
%left TIMES DIVIDE
%nonassoc ASSIGN
%nonassoc LESS GREATER EQUAL NOTEQUAL GREATER_EQUAL LESS_EQUAL
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%%

Program     : SubPro DOT {
                fprintf(fi,"Program -> SubPro DOT\n");  
                fprintf(fh,"Program -> SubPro DOT\n");  }
            ;
SubPro      : DeclarePart Statement {
                fprintf(fi,"SubPro -> DeclarePart Statement\n");  
                fprintf(fh,"SubPro -> DeclarePart Statement\n");  }
            | Statement {
                fprintf(fi,"SubPro -> Statement\n");  
                fprintf(fh,"SubPro -> Statement\n");  
            }
            ;
DeclarePart : ConstDec {
                  fprintf(fi,"DeclarePart -> ConstDec\n");
                  fprintf(fh,"DeclarePart -> ConstDec\n");
            }
            |ConstDec VarDec {
                  fprintf(fi,"DeclarePart -> ConstDec VarDec\n");
                  fprintf(fh,"DeclarePart -> ConstDec VarDec\n");
            }
            |ConstDec ProDec {
                  fprintf(fi,"DeclarePart -> ConstDec ProDec\n");
                  fprintf(fh,"DeclarePart -> ConstDec ProDec\n");
            }
            |ConstDec VarDec ProDec {
                  fprintf(fi,"DeclarePart -> ConstDec VarDec ProDec\n");
                  fprintf(fh,"DeclarePart -> ConstDec VarDec ProDec\n");
            }
            |VarDec ProDec {
                  fprintf(fi,"DeclarePart -> VarDec ProDec\n");
                  fprintf(fh,"DeclarePart -> VarDec ProDec\n");
            } 
            |VarDec {
                  fprintf(fi,"DeclarePart -> VarDec\n");
                  fprintf(fh,"DeclarePart -> VarDec\n");
            }
            |ProDec {
                  fprintf(fi,"DeclarePart -> ProDec\n");
                  fprintf(fh,"DeclarePart -> ProDec\n");
            }
            ;
ConstDec    : ConstDec CONST ConstDef SEMI {
                fprintf(fi,"ConstDec -> ConstDec const ConstDef SEMI\n");
                fprintf(fh,"ConstDec -> ConstDec const ConstDef SEMI\n");
                  }
            | CONST ConstDef SEMI {
                fprintf(fi,"ConstDec -> const ConstDef SEMI\n");
                fprintf(fh,"ConstDec -> const ConstDef SEMI\n");
                  }
            ;
ConstDef    : ConstDef COMMA CDefine {
                fprintf(fi,"ConstDef -> ConstDef , CDefine\n"); 
                fprintf(fh,"ConstDef -> ConstDef , CDefine\n");
                 }
            | CDefine{
                fprintf(fi,"ConstDef -> CDefine\n"); 
                fprintf(fh,"ConstDef -> CDefine\n");
            }
            ;
CDefine     :IDENTIFIER ASSIGN INTEGER_VAL {
                fprintf(fi,"CDefine -> IDENTIFIER := INTEGER_VAL\n");
                fprintf(fh,"CDefine -> IDENTIFIER := INTEGER_VAL\n");
                  }
            | IDENTIFIER ASSIGN FLOAT_VAL {
                fprintf(fi,"CDefine -> IDENTIFIER := FLOAT_VAL\n"); 
                fprintf(fh,"CDefine -> IDENTIFIER := FLOAT_VAL\n");
                 }
            ;

VarDec      : VarDec VarObj {
                fprintf(fi,"VarDec -> VarDec VarObj\n");
                 fprintf(fh,"VarDec -> VarDec VarObj\n");
                }
            | VarObj{
                fprintf(fi,"VarDec -> VarObj\n");
                 fprintf(fh,"VarDec -> VarObj\n");
                
            }
            ;
VarObj      :VAR IdentiDef SEMI {
                fprintf(fi,"VarObj -> var IdentiDef SEMI\n"); 
                fprintf(fh,"VarObj -> var IdentiDef SEMI\n");
                 }
            ;
IdentiDef   : IdentiDef COMMA IdentiObject {
                fprintf(fi,"IdentiDef -> IdentiDef , IdentiObject\n");  
                fprintf(fh,"IdentiDef -> IdentiDef , IdentiObject\n"); 
            }
            | IdentiObject{
                fprintf(fi,"IdentiDef -> IdentiObject\n");  
                fprintf(fh,"IdentiDef -> IdentiObject\n"); 
            }
            ;

IdentiObject   : IDENTIFIER ARRAY Realm OF ArrayType {
                fprintf(fi,"IdentiObject -> IDENTIFIER ARRAY Realm OF ArrayType\n"); 
                fprintf(fh,"IdentiObject -> IDENTIFIER ARRAT Realm OF ArrayType\n");
             }
            | IDENTIFIER OF ValueType {
                fprintf(fi,"IdentiObject -> IDENTIFIER OF ValueType\n");
                fprintf(fh,"IdentiObject -> IDENTIFIER OF ValueType\n");
            }
            | IDENTIFIER {
                fprintf(fi,"IdentiObject -> IDENTIFIER\n");
                fprintf(fh,"IdentiObject -> IDENTIFIER\n");
            }
            ;
Realm       : LEFTBRAC ArrayNDim RIGHTBRAC {
                fprintf(fi,"Realm -> [ ArrayNDim ]\n");  
                fprintf(fh,"Realm -> [ ArrayNDim ]\n"); 
            }
            ;
ArrayNDim   : ArrayNDim COMMA ArrayDimObj {
                fprintf(fi,"ArrayNDim -> ArrayNDim COMMA ArrayDimObj\n");  
                fprintf(fh,"ArrayNDim -> ArrayNDim COMMA ArrayDimObj\n");  
            }
            | ArrayDimObj{
                fprintf(fi,"ArrayNDim -> ArrayDimObj\n");  
                fprintf(fh,"ArrayNDim -> ArrayDimObj\n");
            }
            ;
ArrayDimObj : INTEGER_VAL OMIT INTEGER_VAL {
                fprintf(fi,"ArrayDimObj -> INTEGER_VAL OMIT INTEGER_VAL\n");  
                fprintf(fh,"ArrayDimObj -> INTEGER_VAL OMIT INTEGER_VAL\n");  
            }
ArrayType   : INT {
                fprintf(fi,"ArrayType -> INT\n"); 
                fprintf(fh,"ArrayType -> INT\n");  
            }
            | FLOAT {
                fprintf(fi,"ArrayType -> FLOAT\n"); 
                fprintf(fh,"ArrayType -> FLOAT\n"); 
            }
            ;
ValueType   : INT {
                fprintf(fi,"ValueType -> INT\n");  
                 fprintf(fh,"ValueType -> INT\n");
            }
            | FLOAT {
                fprintf(fi,"ValueType -> FLOAT\n");  
                fprintf(fh,"ValueType -> FLOAT\n");  
            }
            | CHAR {
                fprintf(fi,"ValueType -> CHAR\n"); 
                fprintf(fh,"ValueType -> CHAR\n"); 
            }
            | STRING {
                fprintf(fi,"ValueType -> STRING\n"); 
                fprintf(fh,"ValueType -> STRING\n");
            }
            ;
ProDec      : ProceHead SubPro SEMI {
                fprintf(fi,"ProDec -> ProceHead SubPro SEMI\n"); 
                fprintf(fh,"ProDec -> ProceHead SubPro SEMI\n"); 
            }
            | ProDec ProceHead SubPro SEMI {
                fprintf(fi,"ProDec -> ProDec ProceHead SubPro SEMI\n"); 
                fprintf(fh,"ProDec -> ProDec ProceHead SubPro SEMI\n"); 
            }
            ;
ProceHead   : PROCEDURE IDENTIFIER SEMI {
                fprintf(fi,"ProceHead -> procedure IDENTIFIER SEMI\n");
                fprintf(fh,"ProceHead -> procedure IDENTIFIER SEMI\n");
            }
            ;

Statement   : ComplexStm {
                fprintf(fi,"Statement -> ComplexStm\n");
                fprintf(fh,"Statement -> ComplexStm\n");
                  }
            | { // empty
                //fprintf(fi,"Statement -> Empty\n");
                //fprintf(fh,"Statement -> Empty\n");
                  }
            ;
States      : Statements {
                fprintf(fi,"States -> Statement\n"); 
                fprintf(fh,"States -> Statement\n");
                 }
            | States Statements {
                fprintf(fi,"States -> States Statement\n"); 
                fprintf(fh,"States -> States Statement\n");
                 }
Statements  : AssignStm SEMI {
                fprintf(fi,"Statements -> AssignStm SEMI\n");
                fprintf(fh,"Statements -> AssignStm SEMI\n");
                  }
            | CondiStm {
                fprintf(fi,"Statements -> CondiStm\n"); 
                fprintf(fh,"Statements -> CondiStm\n");
                 }
            | WhileStm SEMI{
                fprintf(fi,"Statements -> WhileStm SEMI\n");
                fprintf(fh,"Statements -> WhileStm SEMI\n");
                  }
            | ForStm SEMI{
                fprintf(fi,"Statements -> ForStm SEMI\n"); 
                fprintf(fh,"Statements -> ForStm SEMI\n");
                 }
            | RepeatS {
                fprintf(fi,"Statements -> RepeatS\n");
                fprintf(fh,"Statements -> RepeatS\n");
                  }
            | CallS SEMI{
                fprintf(fi,"Statements -> CallS SEMI\n");
                fprintf(fh,"Statements -> CallS SEMI\n");
                  }
            | ReadS SEMI{
                fprintf(fi,"Statements -> ReadS SEMI\n"); 
                fprintf(fh,"Statements -> ReadS SEMI\n");
                 }
            | WriteS SEMI{
                fprintf(fi,"Statements -> WriteS SEMI\n");
                fprintf(fh,"Statements -> WriteS SEMI\n");
                  }
            ;

Identifier  : IDENTIFIER LEFTBRAC INdex_Index RIGHTBRAC {
                fprintf(fi,"Identifier -> IDENTIFIER LEFTBRAC INdex_Index RIGHTBRAC\n");
                fprintf(fh,"Identifier -> IDENTIFIER LEFTBRAC INdex_Index RIGHTBRAC\n");
            }
            | IDENTIFIER {
                fprintf(fi,"Identifier -> IDENTIFIER\n");
                fprintf(fh,"Identifier -> IDENTIFIER\n");
            }
            ;
INdex_Index  : INdex_Index COMMA INTEGER_VAL {
                fprintf(fi,"INdex_Index -> INdex_Index COMMA INTEGER_VAL\n");  
                fprintf(fh,"INdex_Index -> INdex_Index COMMA INTEGER_VAL\n");
            }
            | INTEGER_VAL {
                fprintf(fi,"INdex_Index -> INTEGER_VAL\n");
                fprintf(fh,"INdex_Index -> INTEGER_VAL\n"); 
            }
            ;
AssignStm    : Identifier ASSIGN Expr {
                
                fprintf(fi,"AssignStm -> Identifier ASSIGN Expr\n");
                fprintf(fh,"AssignStm -> Identifier ASSIGN Expr\n");
            }
            | Identifier ASSIGN CHAR_VAL {
                
                fprintf(fi,"AssignStm -> Identifier ASSIGN CHAR_VAL\n");
                fprintf(fh,"AssignStm -> Identifier ASSIGN CHAR_VAL\n");
            }
            | Identifier ASSIGN STRING_VAL {
                
                fprintf(fi,"AssignStm -> Identifier ASSIGN STRING_VAL\n");
                fprintf(fh,"AssignStm -> Identifier ASSIGN STRING_VAL\n");
            }
            ;
ComplexStm    : _BEGIN_ States END {
                fprintf(fi,"ComplexStm -> _BEGIN_ States END\n"); 
                fprintf(fh,"ComplexStm -> _BEGIN_ States END\n"); 
                }
            ;
Condition   : Expr CMP Expr {
                fprintf(fi,"Condition -> Expr CMP Expr\n");
                fprintf(fh,"Condition -> Expr CMP Expr\n");
                }
            | ODD Expr {
                fprintf(fi,"Condition -> ODD Expr\n");
                fprintf(fh,"Condition -> ODD Expr\n");
              }
            ;
CMP          : EQUAL {
                fprintf(fi,"CMP -> EQUAL\n"); 
                fprintf(fh,"CMP -> EQUAL\n"); 
             }
            | NOTEQUAL {
                fprintf(fi,"CMP -> NOTEQUAL\n");
                fprintf(fh,"CMP -> NOTEQUAL\n");
              }
            | LESS {
                fprintf(fi,"CMP -> LESS\n"); 
                fprintf(fh,"CMP -> LESS\n");
            }
            | GREATER {
                fprintf(fi,"CMP -> GREATER\n");
                fprintf(fh,"CMP -> GREATER\n");
              }
            | LESS_EQUAL {
                fprintf(fi,"CMP -> LESS_EQUAL\n"); 
                fprintf(fh,"CMP -> LESS_EQUAL\n"); 
             }
            | GREATER_EQUAL {
                fprintf(fi,"CMP -> GREATER_EQUAL\n");  
                fprintf(fh,"CMP -> GREATER_EQUAL\n");
            }
            ;
CondiStm      : IF Condition THEN Statement %prec LOWER_THAN_ELSE {
                fprintf(fi,"CondiStm -> IF Condition THEN Statement\n"); 
                fprintf(fh,"CondiStm -> IF Condition THEN Statement\n"); 
                 }
            | IF Condition THEN Statement ELSE Statement {
                fprintf(fi,"CondiStm -> IF Condition THEN Statement ELSE Statement\n");
                fprintf(fh,"CondiStm -> IF Condition THEN Statement ELSE Statement\n");
                  }
            ;
Expr        : Expr PLUS Term {
                
                fprintf(fi,"Expr -> Expr PLUS Term\n"); 
                fprintf(fh,"Expr -> Expr PLUS Term\n");
                }
            | Expr MINUS Term {
                
                fprintf(fi,"Expr -> Expr MINUS Term\n");
                fprintf(fh,"Expr -> Expr MINUS Term\n");
                  }
            | PLUS Term {
                
                fprintf(fi,"Expr -> PLUS Term\n");  
                fprintf(fh,"Expr -> PLUS Term\n"); 
                }
            | MINUS Term {
                
                fprintf(fi,"Expr -> MINUS Term\n"); 
                fprintf(fh,"Expr -> MINUS Term\n");
                 }
            | Term {
                
                fprintf(fi,"Expr -> Term\n"); 
                fprintf(fh,"Expr -> Term\n");
                 }
            ;
Term        : Term TIMES Factor {
                
                fprintf(fi,"Term -> Term TIMES Factor\n"); 
                fprintf(fh,"Term -> Term TIMES Factor\n");
                 }
            | Term DIVIDE Factor {
                
                fprintf(fi,"Term -> Term DIVIDE Factor\n"); 
                fprintf(fh,"Term -> Term DIVIDE Factor\n");
                 }
            | Factor {
                
                fprintf(fi,"Term -> Factor\n"); 
                fprintf(fh,"Term -> Factor\n"); 
                 }
            ;
Factor      : Identifier {
                //$$=$1;
                fprintf(fi,"Factor -> Identifier\n"); 
                fprintf(fh,"Factor -> Identifier\n");
                 }
            | INTEGER_VAL {
                //$$=$1;
                fprintf(fi,"Factor -> INTEGER_VAL\n"); 
                fprintf(fh,"Factor -> INTEGER_VAL\n");
                 }
            | FLOAT_VAL {
                //$$=$1;
                fprintf(fi,"Factor -> FLOAT_VAL\n"); 
                fprintf(fh,"Factor -> FLOAT_VAL\n");
                 }
            | SL_PAREN Expr SR_PAREN {
                //$$=$2;
                fprintf(fi,"Factor -> SL_PAREN Expr SR_PAREN\n");
                fprintf(fh,"Factor -> SL_PAREN Expr SR_PAREN\n");
                  }
            ;
WhileStm    : WHILE Condition DO Statement {
                fprintf(fi,"WhileStm -> WHILE Condition DO Statement\n"); 
                fprintf(fh,"WhileStm -> WHILE Condition DO Statement\n");
            }
            ;
ForStm        : FOR IDENTIFIER ASSIGN Expr TO Expr DO Statement {
                fprintf(fi,"ForStm -> FOR IDENTIFIER := Expr TO Expr DO Statement\n");  
                fprintf(fh,"ForStm -> FOR IDENTIFIER := Expr TO Expr DO Statement\n"); 
            }
            ;
RepeatS     : REPEAT Statement  SEMI UNTIL Condition {
                fprintf(fi,"RepeatS -> REPEAT Statement SEMI UNTIL Condition\n"); 
                 fprintf(fh,"RepeatS -> REPEAT Statement SEMI UNTIL Condition\n");
            }
            ;
CallS       : CALL SL_PAREN IDENTIFIER SR_PAREN {
                fprintf(fi,"CallS -> call SL_PAREN IDENTIFIER SR_PAREN\n");  
                fprintf(fh,"CallS -> call SL_PAREN IDENTIFIER SR_PAREN\n"); 
            }
            ;
ReadS       : READ SL_PAREN IDENTIFIER SR_PAREN{
                fprintf(fi,"ReadS -> read SL_PAREN IDENTIFIER SR_PAREN\n"); 
                fprintf(fh,"ReadS -> read SL_PAREN IDENTIFIER SR_PAREN\n"); 
            }
            ;
WriteS      : WRITE SL_PAREN Wcontent SR_PAREN{
                fprintf(fi,"WriteS -> write SL_PAREN Wcontent SR_PAREN\n");
                fprintf(fh,"WriteS -> write SL_PAREN Wcontent SR_PAREN\n");
                  }
            ;
Wcontent    : Wcontent COMMA WconObj {
                fprintf(fi,"Wcontent -> Wcontent COMMA WconObj\n"); 
                fprintf(fh,"Wcontent -> Wcontent COMMA WconObj\n");
                 }
            | WconObj{
                fprintf(fi,"Wcontent -> WconObj\n"); 
                fprintf(fh,"Wcontent -> WconObj\n");
                 }
            ;
WconObj     : Expr {
                fprintf(fi,"WconObj -> Expr\n");
                fprintf(fh,"WconObj -> Expr\n");
                  }
            | CHAR_VAL {
                fprintf(fi,"WconObj -> CHAR_VAL\n");
                fprintf(fh,"WconObj -> CHAR_VAL\n");
                }
            | STRING_VAL {
                fprintf(fi,"WconObj -> STRING_VAL\n");
                fprintf(fh,"WconObj -> STRING_VAL\n");
                }
            ;

%%

int main()
{
    fi = fopen("SynOutput.txt", "w+");
    fh = fopen("helperOutput.txt", "w+");
    yyparse();
    return 1;
}

void yyerror(char const* s)
{
    printf("%s,(%d,%d)\n",s,row,column);
    return;
}