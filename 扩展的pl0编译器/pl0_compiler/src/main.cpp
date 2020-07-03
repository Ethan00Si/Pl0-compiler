#include"define.h"
#include"SyntaxPl0.tab.h"
#include<fstream>
#define YELLOW  "\033[33m"      /* Yellow */
#define RESET   "\033[0m"
using std::string;
using std::fstream;
extern FILE* yyin;
extern int yyparse(void);
void ouput_pcode(string file_name){
    fstream fout;
    fout.open(file_name,std::ios::out);
    for(int i=0;i<code_line;i++)
    {
      fout<<i<<' ';
	    if(code[i].f==instruction::LIT)
      {
        fout<<"LIT"<<' '<<code[i].l<<' ';
        if(code[i].var.type_==all_type_val_value::int_)
          fout<<code[i].var.i_val<<std::endl;
        else if(code[i].var.type_==all_type_val_value::float_)
          fout<<code[i].var.f_val<<std::endl;
        else
          fout<<code[i].var.v_str<<std::endl;
      }
	    if(code[i].f==instruction::LOD)
        fout<<"LOD"<<' '<<code[i].l<<' '<<code[i].a<<std::endl; 
	    if(code[i].f==instruction::STO)
		    fout<<"STO"<<' '<<code[i].l<<' '<<code[i].a<<std::endl;
	    if(code[i].f==instruction::CAL)
		    fout<<"CAL"<<' '<<code[i].l<<' '<<code[i].a<<std::endl;
	    if(code[i].f==instruction::INI)
		    fout<<"INT"<<' '<<code[i].l<<' '<<code[i].a<<std::endl;
	    if(code[i].f==instruction::JMP)
		    fout<<"JMP"<<' '<<code[i].l<<' '<<code[i].a<<std::endl;
	    if(code[i].f==instruction::JPC)
		    fout<<"JPC"<<' '<<code[i].l<<' '<<code[i].a<<std::endl;
	    if(code[i].f==instruction::OPR)
		    fout<<"OPR"<<' '<<code[i].l<<' '<<code[i].a<<std::endl;
    }
    fout<<std::endl;
}



int main(int argc,char* argv[])
{
    if(argc < 3){
        std::cout << "lack parameters!" << std::endl;
        std::cout << "first parameter : input pl0 source code" << std::endl;
        std::cout << "second parameter : output pcode file path" << std::endl;
        exit(1);
    }
    yyin=fopen(argv[1],"r");
    init();
    std::cout<<YELLOW << "start yyparse" << std::endl;
    yyparse();
    ouput_pcode(argv[2]);
    std::cout <<YELLOW<< "start interpret pcode" << std::endl;
    std::cout << RESET ;
    interpret();
    return 0;
}

