import os
your_command = input("type what to do:\ncompile, parse, clean or quit\n")
while your_command != 'quit':
    if your_command == 'compile':
        os.system('flex LexicalPl0.l')
        os.system('bison SyntaxPl0.y -d')
        os.system('g++ SyntaxPl0.tab.c lex.yy.c -o res')
        os.system('g++ -std=c++11 draw.cpp -o draw')
    if your_command == 'parse':
        file_name = input("type the name of testing file:\n")
        res = './res < '+file_name
        os.system(res)
        os.system('./draw')
        os.system('dot -Tpdf ASTvis.gv -o AST.pdf')
    if your_command == 'clean':
        os.system(
            'rm res lex.yy.c SyntaxPl0.tab.c SyntaxPl0.tab.h *.txt draw  ASTvis.gv')
    if your_command == 'quit':
        break
    your_command = input("compile, parse or quit\n")
