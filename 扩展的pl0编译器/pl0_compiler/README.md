# 语法分析器实验



## Tested Environment:
- **Mac OS测试环境**
  - macOS Catallina 10.15.3
  - Apple clang version 11.0.3
  - flex 2.5.35 Apple(flex-32)
  - bison (GNU Bison) 2.3
- ***Linux测试环境为***

  * Ubuntu 18.04.4 LTS
  * flex 2.6.4
  * bison (GNU Bison) 3.0.4
  * g++ (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0

## Compile the code & Run:

###编译所有程序

```bash
flex LexicalPl0.l
bison SyntaxPl0.y -d
g++ main.cpp interpret.cpp lex.yy.c SyntaxPl0.tab.c define.cpp
```

### 对测试程序进行分析

例如：运行test_sum.pl0

```shell
./a.out  ../succ_pl0/gcd.pl0 ../pcode/gcd.pcode
```

## 文件夹描述

* src：源程序
* error_pl0:错误的pl0程序，用于测试报错
* succ_pl0: 正确的pl0程序
* pcode：生成的pcode文件



