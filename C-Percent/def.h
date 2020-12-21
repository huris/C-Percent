#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdarg.h"
#include "parser.tab.h"

#define MAXLENGTH 1000     // 定义符号表的大小
#define DX 3 * sizeof(int) // 活动记录控制信息需要的单元数
#define MAX_LIST 5
#define MAX_BYTE 7

enum node_kind
{
    Static_List,
    EXT_DEF_LIST,
    EXT_VAR_DEF,
    FUNC_DEF,
    FUNC_DEC,
    EXT_DEC_LIST,
    PARAM_LIST,
    PARAM_DEC,
    VAR_DEF,
    DEC_LIST,
    DEF_LIST,
    COMP_STM,
    STM_LIST,
    EXP_STMT,
    IF_THEN,
    IF_THEN_ELSE,
    FUNC_CALL,
    ARGS,
    FUNCTION,
    PARAM,
    ARG,
    CALL,
    LABEL,
    GOTO,
    JLT,
    JLE,
    JGT,
    JGE,
    EQ,
    NEQ,
    StructSpecifier,
    Includes,
    ForExp,
    LIST_INIT,
    LIST_CALL,
    STRUCT_CALL
};

struct opn
{
    int kind; // 标识操作的类型
    int type; // 标识操作数的类型
    union
    {
        int const_int;     // 整常数值, 立即数
        float const_float; // 浮点常数值, 立即数
        char const_char;   // 字符常数值, 立即数
        char const_string[33]; // 字符串常数值, 立即数
        char id[33]; // 变量或临时变量的别名或标号字符串
    };
    int level;  // 变量的层号, 0表示是全局变量, 数据保存在静态数据区
    int offset; // 变量单元偏移量, 或函数在符号表的定义位置序号, 目标代码生成时用
    int byte[MAX_BYTE];
    int list;
    int isend;
    int Point_Offset;
};

// 三地址TAC代码结点, 采用双向循环链表存放中间语言代码
struct codenode
{                                  
    int op; // TAC代码的运算符种类
    struct opn opn1, opn2, result; // 2个操作数和运算结果
    struct codenode *next, *prior;
};

// 以下对结点属性定义没有考虑存储效率, 只是简单地列出要用到的一些属性
struct node
{                        
    enum node_kind kind; // 结点类型
    union
    {
        char type_id[33]; // 由标识符生成的叶结点
        int type_int;     // 由整常数生成的叶结点
        float type_float; // 由浮点常数生成的叶结点
    };
    struct node *ptr[3];        // 子树指针, 由kind确定有多少棵子树
    int level;                  // 层号
    int place;                  // 表示结点对应的变量或运算结果符号表的位置序号
    char Etrue[15], Efalse[15]; // 对布尔表达式的翻译时, 真假转移目标的标号
    char Snext[15];             // 该结点对应语句执行后的下一条语句位置标号
    struct codenode *code;      // 该结点中间代码链表头指针
    char op[10];
    int type;   // 结点对应值的类型
    int pos;    // 语法单位所在位置行号
    int offset; // 偏移量
    int width;  // 占数据字节数
    int num;
    int string_id; // 存取对应字符串在字符串表内的id
    int isShuzu;   // 数组的判断
    int isSTRUCT;  // 结构体的判断
    int isFOR;
    int List[5]; // 存数组的信息
    int length;
    char Break[30];     // 存break的语句位置
    char struct_id[33]; // 存相应结构体的名字
    
};

// 这里只列出了一个符号表项的部分属性, 没考虑属性间的互斥
struct symbol
{
    char name[33];  // 变量或函数名
    int level;      // 层号, 外部变量名或函数名层号为0, 形参名为1, 每到1个复合语句层号加1, 退出减1
    int type;       // 变量类型或函数返回值类型
    int paramnum;   // 形式参数个数
    char alias[10]; // 别名, 为解决嵌套层次使用, 使得每一个数据名称唯一
    char flag;      // 符号标记, 函数: 'F', 变量: 'V', 数组变量: 'A', 参数: 'P', 临时变量: 'T'
    char flag2;
    int offset; // 外部变量和局部变量在其静态数据区或活动记录中的偏移量
                // 或函数活动记录大小, 目标代码生成时使用
    int width;
    int List[MAX_LIST];
    int length;
    char struct_id[33];
    int permitNull;
    int isNull;
    int PointOffset;
    //其它...
};

//字符串表，是一个顺序栈, index初值为0
struct strings
{
    char name[33];
} strings;

struct stringsTable
{
    struct strings string[MAXLENGTH];
    int index;
} stringsTable;

struct dpTable
{
    struct node *dps[MAXLENGTH];
    int id[MAXLENGTH];
    int index;
} dpTable;

struct symboltable
{
    struct symbol symbols[MAXLENGTH];
    int index;
} symbolTable;

/*当前作用域的符号在符号表的起始位置序号, 这是一个栈结构, 
每到达一个复合语句，将符号表的index值进栈, 离开复合语句时, 
取其退栈值修改符号表的index值, 完成删除该复合语句中的所有变量和临时变量*/
struct symbol_scope_begin
{
    int TX[30];
    int top;
} symbol_scope_TX;

struct node *mknode(int kind, struct node *first, struct node *second, struct node *third, int pos);
void semantic_Analysis0(struct node *T);
void semantic_Analysis(struct node *T);
void boolExp(struct node *T);
void Exp(struct node *T);
void objectCode(struct codenode *head);