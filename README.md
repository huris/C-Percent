<img src="https://huris.oss-cn-hangzhou.aliyuncs.com/program/C-Percent/C%25.png" width=30% >

# 背景与动机

空指针/空引用异常（NullPointerException）是导致程序崩溃率最高的异常类型，被图灵奖得主托尼·霍尔（Tony Hoare）称为《十亿美元的错误》。其根源在于空指针异常是一种不受编译器检查的运行时异常，只能由程序员通过主动逻辑来判断避免，但即使是最出色的程序员，也极难将所有潜在的空指针异常都考虑周全。

因此，为了尽可能避免空指针错误，我们设计并引入了**编译时可空类型判断系统**的概念。即在程序编译阶段，一个变量必须声明是否可空，对于非可空变量，在访问其成员时必须做空处理，否则无法通过编译。例如，对于 C 语言来说，以下代码可以通过编译，但是运行结果会有问题：

```c
#include <stdio.h>

int plusplus(int *a){
    return *a + 1;
}

int main(){
    int *a = NULL;   // a为空引用
    printf("%d\n", plusplus(a)); // 函数传入空引用值，结果出错
    return 0;
}
```

而如果采用编译时可控类型判断系统，则上述代码中非空指针a赋值为NULL就无法通过编译。考虑某些情况下确实需要赋值为NULL，我们也保留了可空指针变量，后面加“?”表示，即：

```c
int *a = NULL;  // a为非空指针变量，无法通过编译
int *a? = NULL;  // a为可空指针变量，可以通过编译
```

为了验证设计方案的可行性，我们设计了C%（读作：C-Percent）语言，它是一门类C的语言，引入编译时可空类型判断系统，在很大程度上可以杜绝空指针异常所引起的错误。目前我们实现了C%语言的绝大部分常用功能（运算、分支、循环、结构体、函数、指针等），编译器完成了词法分析、语法分析、语义分析、中间代码生成和目标代码生成5个阶段的测试，程序可正常运行和定位报错。

C%语言中的百分号有多层意思：C语言的子集或超集、oo表示2个人共同完成（也表示未来可能会加入的面向对象特征）、除号（/）表示在 C 语言的基础上加入可空类型判断系统及一些语法糖同时删去一些我们认为不太好的地方。

整个项目目前累计开发超150小时，其亮点总结如下：

1. 能够以形式化、结构化、表格化的形式直观地打印出C%语言编译阶段所用到的符号表，通过打印的符号表，可以清晰地观察各作用域之间的联系，方便程序员Debug及了解语言的翻译模式。
2. 采用make编译，对整个环节进行了封装和整合，以命令行参数的方式提供各个阶段数据结构的访问接口，可以打印第一阶段词法和语法分析阶段的语法分析树，可以打印第二阶段语义分析阶段的符号表，可以打印第三阶段中间代码生成阶段的中间代码，可以指定是否需要在目标代码中添加Debug信息。
3. 实现了编译时空指针/空引用检查，同时也加入了一些诸如“if/for/while条件可删去小括号”、“只包含单个return的函数可以直接在后面用等号完成”、“指针符号用“@”代替“*”以区别乘号”等特性。

# 环境搭建

C% 语言基于 Windows 环境开发，主要以C语言实现编码，需要安装GCC编译器（安装位置：C:\MinGW）。由于开发工作量及运行效率方面的考虑，C%语言编译阶段的词法分析基于Flex完成（安装位置：C:\gnuwin32），语法分析基于Bison完成（安装位置：C:\gnuwin32），安装完毕后需要将C:\gnuwin32\lib中的libfl.a和liby.a复制到C:\MinGW\lib中，并配置环境变量。另外，需要安装QtSpim来进行对最后生成的MIPS汇编代码的验证与测试。

- mingw-get-setup.exe
- flex-2.5.4a-1.exe
- bison-2.4.1-setup.exe
- QtSpim_9.1.21_Windows.msi

进入 C-Percent 文件夹，直接执行 make 即可运行，其中 C% 代码写在test.txt中，makefile文件内容如下：

```makefile
all: clean C_Percent

C_Percent: lex.l parser.y
# 显示中文
	chcp 65001
# 先用bison, -d表示将编译结果拆分.tab.c和.tab.h两个, -v表示产生.output文件, -t进入诊断模式
	bison -d -v parser.y
# 词法分析
	flex lex.l
# 编译
	gcc -o a.exe lex.yy.c parser.tab.c def.c objectCode.c -lfl -ly
# 分析输入语句, 生成.s的汇编程序
	a.exe test.cp
# 通过QtSpim运行汇编程序
	..\tools\QtSpim\QtSpim.exe object.s

clean:
# 删除中间生成文件
	del lex.yy.c
	del parser.tab.c
	del parser.tab.h
	del lex.output
	del a.exe
	del objects.s
```

