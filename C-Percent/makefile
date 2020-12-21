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