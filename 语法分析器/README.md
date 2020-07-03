# 语法分析器实验

## Tested Environment:
- macOS Catallina 10.15.3
- Apple clang version 11.0.3
- flex 2.5.35 Apple(flex-32)
- bison (GNU Bison) 2.3
- graphviz: stable 2.44.0 (bottled), HEAD

## Compile the code & Run:

###编译所有程序

```shell
flex LexicalPl0.l
bison SyntaxPl0.y -d
g++ SyntaxPl0.tab.c lex.yy.c -o res
g++ -std=c++11 draw.cpp -o draw
```

### 对测试程序进行分析

例如：运行test_sum.pl0

```shell
./res < ../tests/test_sum.pl0
```

### 画图

```shell
./draw
dot -Tpdf ASTvis.gv -o AST.pdf
```

### 结果文件

* SynOutput.txt
  * 按照规约顺序用到语法规则序列
* AST.pdf
  * 语法树

### 另外的方法

也可以按照下文中的提示使用run.py进行编译和运行

## Instructions:

### 各个文件功能

* draw.cpp
  * 画图函数，通过读取词法和文法分析的输出结果建立抽象语法树(Abstract Syntax Tree, AST)
  * 将AST输出到一个dot可以运行到文件ASTvis.gv中
* SyntaxPl0.y
  * 语法分析器
* LexicalPl0.l
  * 词法分析器
* main.h
  * 语法分析器和词法分析器的共同的头文件

###运行方法以及运行环境额外说明

* 没有在windows环境下测试，不保证在windos下能够正确编译和运行

* 在Linux下通过测试，可以正确运行

     ***Linux测试环境为***

  * Ubuntu 18.04.4 LTS
  * flex 2.6.4
  * bison (GNU Bison) 3.0.4
  * g++ (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
  * graphviz 2.40.1-2

* run.py 

  * 这是一个写好的用来编译程序，运行并画图的脚本

  * 使用方法

    ```bash
    python run.py
    ```

    命令行会提示

    ```bash
    type what to do:
    compile, parse, clean or quit
    ```

    接着按顺序键入

    ```
    compile
    parse
    ```

    出现提示  type the name of testing file:

    假设选取我的测试集中的../tests/test_sum.pl0

    需键入

    ```bash
    ../test/test_sum.pl0
    ```

    推出python脚本

    ```
    quit
    ```

    

