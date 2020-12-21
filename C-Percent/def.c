#include "def.h"

struct node *mknode(int kind, struct node *first, struct node *second, struct node *third, int pos) {
    struct node *T = (struct node *)malloc(sizeof(struct node));
    T->kind = kind;
    T->ptr[0] = first;
    T->ptr[1] = second;
    T->ptr[2] = third;
    T->pos = pos;
    T->length = 0;
    T->isSTRUCT = 0;
    T->isShuzu = 0;
    T->place = -2;

    if (kind == Static_List) {
        T->num = 1;
    }


    for (int i = 0; i < 5; i++)
    {
        T->List[i] = 0;
    }
    return T;
}

//工具函数，用于消除字符串中的@
void fun(char *a)
{
	int i=0,j;
	char *p=a;
	//计算字符串长度 
	while(*p)
	{
		i++;
		p++;
	}
	
	//i=i-1使a[i]第一次指向最后一个字符 
	//从字符串尾部向前，遇到第一个不为*号停止 
	for(i=i-1;a[i]=='@';i--)
	{
		a[i]='\0';
	}
	
 } 

////工具函数，用于消除字符串中的?
void fun2(char *a)
{
	int i=0,j;
	char *p=a;
	//计算字符串长度 
	while(*p)
	{
		i++;
		p++;
	}
	//i=i-1使a[i]第一次指向最后一个字符 
	//从字符串尾部向前，遇到第一个不为*号停止 
	for(i=i-1;a[i]=='?';i--)
	{
		a[i]='\0';
	}
	
 } 

void display(struct node *T, int indent) { //对抽象语法树的先根遍历
    int i = 1;
    struct node *T0;
    if (T) {
        switch (T->kind)
        {
        case EXT_DEF_LIST:
            display(T->ptr[0], indent); // 显示该外部定义列表中的第一个
            display(T->ptr[1], indent); // 显示该外部定义列表中的其它外部定义
            break;
        case EXT_VAR_DEF:
            printf("%*c外部变量定义：\n", indent, ' ');
            display(T->ptr[0], indent + 3); //显示外部变量类型
            printf("%*c变量名：\n", indent + 3, ' ');
            display(T->ptr[1], indent + 6); //显示变量列表
            break;
        case TYPE:
            printf("%*c类型： %s\n", indent, ' ', T->type_id);
            break;
        case EXT_DEC_LIST:
            display(T->ptr[0], indent); //依次显示外部变量名
            display(T->ptr[1], indent); //后续还有相同的, 仅显示语法树此处理代码可以和类似代码合并
            break;
        case Includes:
            printf("%*c引用库函数：%s\n", indent, ' ', T->type_id);
            break;
        case FUNC_DEF:
            printf("%*c函数定义：\n", indent, ' ');
            display(T->ptr[0], indent + 3); //显示函数返回类型
            display(T->ptr[1], indent + 3); //显示函数名和参数
            display(T->ptr[2], indent + 3); //显示函数体
            break;
        case FUNC_DEC:
            printf("%*c函数名：%s\n", indent, ' ', T->type_id);
            if (T->ptr[0] != NULL)
            {
                printf("%*c函数形参：\n", indent, ' ');
                display(T->ptr[0], indent + 3); //显示函数参数列表
            }
            else
                printf("%*c无参函数\n", indent + 3, ' ');
            break;
        case StructSpecifier:
            if (T->type_id == "0")
                printf("%*c结构体：%s\n", indent, ' ', "无");
            else
                printf("%*c结构体：%s\n", indent, ' ', T->type_id);
            if (T->ptr[0])
            {
                printf("%*c结构体主体：\n", indent, ' ');
                display(T->ptr[0], indent + 3);
            }
            break;
        case Static_List:
            if (T->ptr[0]->kind == ID)
                printf("%*c数组名：%s\n", indent, ' ', T->ptr[0]->type_id);
            else
                display(T->ptr[0], indent);
            printf("%*c数组维数：\n", indent, ' ');
            display(T->ptr[1], indent);
            break;
        case PARAM_LIST:
            display(T->ptr[0], indent); //依次显示全部参数类型和名称，
            display(T->ptr[1], indent);
            break;
        case PARAM_DEC:
            printf("%*c类型：%s, 参数名：%s\n", indent, ' ', T->ptr[0]->type_id, T->ptr[1]->type_id);
            break;
        case EXP_STMT:
            printf("%*c表达式语句：\n", indent, ' ');
            display(T->ptr[0], indent + 3);
            break;
        case RETURN:
            printf("%*c返回语句：\n", indent, ' ');
            display(T->ptr[0], indent + 3);
            break;
        case COMP_STM:
            printf("%*c复合语句：\n", indent, ' ');
            printf("%*c复合语句的变量定义：\n", indent + 3, ' ');
            display(T->ptr[0], indent + 6); //显示定义部分
            printf("%*c复合语句的语句部分：\n", indent + 3, ' ');
            display(T->ptr[1], indent + 6); //显示语句部分
            break;
        case STM_LIST:
            display(T->ptr[0], indent); //显示第一条语句
            display(T->ptr[1], indent); //显示剩下语句
            break;
        case WHILE:
            printf("%*cWHILE循环语句：\n", indent, ' ');
            printf("%*c循环条件：\n", indent + 3, ' ');
            display(T->ptr[0], indent + 6); //显示循环条件
            printf("%*c循环体：\n", indent + 3, ' ');
            display(T->ptr[1], indent + 6); //显示循环体
            break;
        case FOR:
            printf("%*cFOR循环语句：\n", indent, ' ');
            printf("%*c循环条件：\n", indent + 3, ' ');
            display(T->ptr[0], indent + 6);
            printf("%*c循环体：\n", indent + 3, ' ');
            display(T->ptr[1], indent + 6);
            break;
        case ForExp:
            printf("%*c初始化：\n", indent, ' ');
            display(T->ptr[0], indent + 3);
            printf("%*c终止条件：\n", indent, ' ');
            display(T->ptr[1], indent + 3);
            printf("%*c变化：\n", indent, ' ');
            display(T->ptr[2], indent + 3);
            break;
        case IF_THEN:
            printf("%*c条件语句(IF_THEN)：\n", indent, ' ');
            printf("%*c条件：\n", indent + 3, ' ');
            display(T->ptr[0], indent + 6); //显示条件
            printf("%*cIF子句：\n", indent + 3, ' ');
            display(T->ptr[1], indent + 6); //显示if子句
            break;
        case IF_THEN_ELSE:
            printf("%*c条件语句(IF_THEN_ELSE)：\n", indent, ' ');
            printf("%*c条件：\n", indent + 3, ' ');
            display(T->ptr[0], indent + 6); //显示条件
            printf("%*cIF子句：\n", indent + 3, ' ');
            display(T->ptr[1], indent + 6); //显示if子句
            printf("%*cELSE子句：\n", indent + 3, ' ');
            display(T->ptr[2], indent + 6); //显示else子句
            break;
        case DEF_LIST:
            display(T->ptr[0], indent); //显示该局部变量定义列表中的第一个
            display(T->ptr[1], indent); //显示其它局部变量定义
            break;
        case VAR_DEF:
            printf("%*cLOCAL VAR_NAME：\n", indent, ' ');
            display(T->ptr[0], indent + 3); //显示变量类型
            display(T->ptr[1], indent + 3); //显示该定义的全部变量名
            break;
        case DEC_LIST:
            printf("%*cVAR_NAME：\n", indent, ' ');
            T0 = T;
            while (T0)
            {
                if (T0->ptr[0]->kind == ID)
                    printf("%*c %s\n", indent + 3, ' ', T0->ptr[0]->type_id);
                else if (T0->ptr[0]->kind == ASSIGNOP)
                {
                    printf("%*c %s ASSIGNOP\n ", indent + 3, ' ', T0->ptr[0]->ptr[0]->type_id);
                    //显示初始化表达式
                    display(T0->ptr[0]->ptr[1], indent + strlen(T0->ptr[0]->ptr[0]->type_id) + 4);
                }
                else if (T0->ptr[0]->kind == FUHE)
                {
                    printf("%*c %s %s\n ", indent + 3, ' ', T0->ptr[0]->ptr[0]->type_id, T0->ptr[0]->type_id);
                    display(T0->ptr[0]->ptr[1], indent + strlen(T0->ptr[0]->ptr[0]->type_id) + 4);
                }
                else if (T0->ptr[0]->kind == Static_List)
                {
                    display(T0->ptr[0], indent + 3);
                    display(T0->ptr[1], indent + 3);
                }
                T0 = T0->ptr[1];
            }
            break;
        case ID:
            printf("%*cID： %s\n", indent, ' ', T->type_id);
            break;
        case INTEGER:
            printf("%*cINT：%d\n", indent, ' ', T->type_int);
            break;
        case FLOAT:
            printf("%*cFLAOT：%f\n", indent, ' ', T->type_float);
            break;
        case CHAR:
            printf("%*cCHAR： %c\n", indent, ' ', T->type_id[1]);
            break;
        case STRING:
            printf("%*cSTRING： %s\n", indent, ' ', T->type_id);
            break;
        case POINTER:
            printf("%*cPointer： %s\n", indent, ' ', T->type_id);
            break;
        case ASSIGNOP:
        case AND:
        case OR:
        case RELOP:
        case PLUS:
        case MINUS:
        case STAR:
        case DIV:
        case FUHE:
            printf("%*c%s\n", indent, ' ', T->type_id);
            display(T->ptr[0], indent + 3);
            display(T->ptr[1], indent + 3);
            break;
        case PLUSPLUS:
            printf("%*c%s\n", indent, ' ', T->type_id);
            display(T->ptr[0], indent + 3);
            break;
        case NOT:
        case UMINUS:
            printf("%*c%s\n", indent, ' ', T->type_id);
            display(T->ptr[0], indent + 3);
            break;
        case FUNC_CALL:
            printf("%*c函数调用：\n", indent, ' ');
            printf("%*c函数名：%s\n", indent + 3, ' ', T->type_id);
            display(T->ptr[0], indent + 3);
            break;
        case ARGS:
            i = 1;
            while (T)
            { //ARGS表示实际参数表达式序列结点，其第一棵子树为其一个实际参数表达式，第二棵子树为剩下的。
                struct node *T0 = T->ptr[0];
                printf("%*c第%d个实际参数表达式：\n", indent, ' ', i++);
                display(T0, indent + 3);
                T = T->ptr[1];
            }
            // printf("%*c第%d个实际参数表达式：\n",indent,' ',i);
            // display(T,indent+3);
            printf("\n");
            break;
        }
    }
}

char *strcat0(char *s1, char *s2)
{
    static char result[10];
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

 // 变量
char *newAlias()
{
    static int no = 1;
    char s[10];
    itoa(no++, s, 10);
    return strcat0("v", s);
}

// Goto的label
char *newLabel()
{
    static int no = 1;
    char s[10];
    itoa(no++, s, 10);
    return strcat0("label", s);
}

// 中间变量
char *newTemp()
{
    static int no = 1;
    char s[10];
    itoa(no++, s, 10);
    return strcat0("temp", s);
}

// 数组
char *newList()
{
    static int no = 1;
    char s[10];
    itoa(no++, s, 10);
    return strcat0("a", s);
}

//生成一条TAC代码的结点组成的双向循环链表，返回头指针
struct codenode *genIR(int op, struct opn opn1, struct opn opn2, struct opn result)
{
    struct codenode *h = (struct codenode *)malloc(sizeof(struct codenode));
    h->op = op;
    h->opn1 = opn1;
    h->opn2 = opn2;
    h->result = result;
    h->next = h->prior = h;
    return h;
}

//生成一条标号语句，返回头指针
struct codenode *genLabel(char *label)
{
    struct codenode *h = (struct codenode *)malloc(sizeof(struct codenode));
    h->op = LABEL;
    strcpy(h->result.id, label);
    h->next = h->prior = h;
    return h;
}

//生成GOTO语句，返回头指针
struct codenode *genGoto(char *label)
{
    struct codenode *h = (struct codenode *)malloc(sizeof(struct codenode));
    h->op = GOTO;
    strcpy(h->result.id, label);
    h->next = h->prior = h;
    return h;
}

//合并多个中间代码的双向循环链表，首尾相连
struct codenode *merge(int num, ...)
{
    struct codenode *h1, *h2, *p, *t1, *t2;
    va_list ap;
    va_start(ap, num);
    h1 = va_arg(ap, struct codenode *);
    while (--num > 0)
    {
        h2 = va_arg(ap, struct codenode *);
        if (h1 == NULL)
            h1 = h2;
        else if (h2)
        {
            t1 = h1->prior;
            t2 = h2->prior;
            t1->next = h2;
            t2->next = h1;
            h1->prior = t2;
            h2->prior = t1;
        }
    }
    va_end(ap);
    return h1;
}

//输出中间代码
void prnIR(struct codenode *head)
{
    char opnstr1[32], opnstr2[32], resultstr[32];
    struct codenode *h = head;
    do
    {
        if (h->opn1.kind == INTEGER)
            sprintf(opnstr1, "#%d", h->opn1.const_int);
        if (h->opn1.kind == FLOAT)
            sprintf(opnstr1, "#%f", h->opn1.const_float);
        if (h->opn1.kind == CHAR)
            sprintf(opnstr1, "%c", h->opn1.const_char);
        if (h->opn1.kind == STRING)
            sprintf(opnstr1, "%s", h->opn1.const_string);
        if (h->opn1.kind == ID)
            sprintf(opnstr1, "%s", h->opn1.id);
        if (h->opn1.kind == POINTER)
            sprintf(opnstr1, "*%s", h->opn1.id);
        if (h->opn2.kind == INTEGER)
            sprintf(opnstr2, "#%d", h->opn2.const_int);
        if (h->opn2.kind == FLOAT)
            sprintf(opnstr2, "#%f", h->opn2.const_float);
        if (h->opn2.kind == CHAR)
            sprintf(opnstr2, "%c", h->opn2.const_char);
        if (h->opn2.kind == STRING)
            sprintf(opnstr2, "%s", h->opn2.const_string);
        if (h->opn2.kind == ID)
            sprintf(opnstr2, "%s", h->opn2.id);
        if (h->opn2.kind == POINTER)
            sprintf(opnstr2, "*%s", h->opn2.id);
        sprintf(resultstr, "%s", h->result.id);
        switch (h->op)
        {
        case ASSIGNOP:
            printf("  %s := %s\n", resultstr, opnstr1);
            break;
        case Static_List:
            printf("  %s := addr(%s)\n", resultstr, opnstr1);
            break;
        case PLUS:
        case MINUS:
        case STAR:
        case DIV:
            printf("  %s := %s %c %s\n", resultstr, opnstr1,
                   h->op == PLUS ? '+' : h->op == MINUS ? '-' : h->op == STAR ? '*' : '\\', opnstr2);
            break;
        case FUNCTION:
            printf("\nFUNCTION %s :\n", h->result.id);
            break;
        case StructSpecifier:
            printf("\nSTRUCT %s :\n", h->result.id);
            break;
        case PARAM:
            printf("  PARAM %s\n", h->result.id);
            break;
        case LABEL:
            printf("LABEL %s :\n", h->result.id);
            break;
        case GOTO:
            printf("  GOTO %s\n", h->result.id);
            break;
        case JLE:
            printf("  IF %s <= %s GOTO %s\n", opnstr1, opnstr2, resultstr);
            break;
        case JLT:
            printf("  IF %s < %s GOTO %s\n", opnstr1, opnstr2, resultstr);
            break;
        case JGE:
            printf("  IF %s >= %s GOTO %s\n", opnstr1, opnstr2, resultstr);
            break;
        case JGT:
            printf("  IF %s > %s GOTO %s\n", opnstr1, opnstr2, resultstr);
            break;
        case EQ:
            printf("  IF %s == %s GOTO %s\n", opnstr1, opnstr2, resultstr);
            break;
        case NEQ:
            printf("  IF %s != %s GOTO %s\n", opnstr1, opnstr2, resultstr);
            break;
        case ARG:
            printf("  ARG %s\n", h->result.id);
            break;
        case CALL:
            printf("  %s := CALL %s\n", resultstr, opnstr1);
            break;
        case RETURN:
            if (h->result.kind)
                printf("  RETURN %s\n", resultstr);
            else
                printf("  RETURN\n");
            break;
        case UMINUS:
        case NOT:
            printf("  %s := not %s\n", resultstr, opnstr1);
            break;
        }
        h = h->next;
    } while (h != head);
}

void semantic_error(int line, char *msg1, char *msg2)
{
    //这里可以只收集错误信息，最后在一次显示
    printf("在%d行,%s %s\n", line, msg1, msg2);
}

void prn_symbol()
{ //显示符号表
    int i = 0;
    printf("%6s    %6s     %6s  %6s   %5s  %7s %7s %7s\n","变量名","别名","层号","类型","标记","偏移量","空允许","是否为空");
    for (i = 0; i < symbolTable.index; i++)
    {
        char c[10];
        if (symbolTable.symbols[i].type == INTEGER)
            strcpy(c, "INT");
        else if (symbolTable.symbols[i].type == FLOAT)
            strcpy(c, "FLOAT");
        else if (symbolTable.symbols[i].type == CHAR)
            strcpy(c, "CHAR");
        else if (symbolTable.symbols[i].type == STRING)
            strcpy(c, "STRING");
        //修改点：指针
        else if (symbolTable.symbols[i].type == POINTER)
            strcpy(c, "POINT");
        if (symbolTable.symbols[i].flag == 'S' || symbolTable.symbols[i].type == STRUCT)
        {
            symbolTable.symbols[i].type = STRUCT;
            strcpy(c, "STRUCT");
        }
        printf("%6s %6s %6d  %6s %5c %7d %7d %7d\n",symbolTable.symbols[i].name,\
                symbolTable.symbols[i].alias,symbolTable.symbols[i].level,\
                c,\
                symbolTable.symbols[i].flag,symbolTable.symbols[i].offset,
                symbolTable.symbols[i].permitNull,symbolTable.symbols[i].isNull);
    }
}

int searchSymbolTable(char *name)
{
    int i;
    for (i = symbolTable.index - 1; i >= 0; i--)
        if (!strcmp(symbolTable.symbols[i].name, name))
            return i;
    return -1;
}

int fillSymbolTable(char *name, char *alias, int level, int type, char flag, int offset)
{
    //首先根据name查符号表，不能重复定义 重复定义返回-1
    int i;
    /*符号查重，考虑外部变量声明前有函数定义，
    其形参名还在符号表中，这时的外部变量与前函数的形参重名是允许的*/
    for (i = symbolTable.index - 1; symbolTable.symbols[i].level == level || (level == 0 && i >= 0); i--)
    {
        if (level == 0 && symbolTable.symbols[i].level == 1)
            continue; //外部变量和形参不必比较重名
        if (!strcmp(symbolTable.symbols[i].name, name))
            return -1;
    }
    symbolTable.symbols[symbolTable.index].permitNull = 0;
    //修改点
    if(type==POINTER)
    {
        int a = strlen(name);
        fun2(name);
        int b = strlen(name);
        if(a!=b)symbolTable.symbols[symbolTable.index].permitNull = 1;
    }

    //填写符号表内容
    strcpy(symbolTable.symbols[symbolTable.index].name, name);
    strcpy(symbolTable.symbols[symbolTable.index].alias, alias);
    symbolTable.symbols[symbolTable.index].level = level;
    symbolTable.symbols[symbolTable.index].type = type;
    symbolTable.symbols[symbolTable.index].flag = flag;
    symbolTable.symbols[symbolTable.index].offset = offset;
    return symbolTable.index++; //返回的是符号在符号表中的位置序号，中间代码生成时可用序号取到符号别名
}

//填写临时变量到符号表，返回临时变量在符号表中的位置
int fill_Temp(char *name, int level, int type, char flag, int offset)
{
    strcpy(symbolTable.symbols[symbolTable.index].name, "");
    strcpy(symbolTable.symbols[symbolTable.index].alias, name);
    symbolTable.symbols[symbolTable.index].level = level;
    symbolTable.symbols[symbolTable.index].type = type;
    symbolTable.symbols[symbolTable.index].flag = flag;
    symbolTable.symbols[symbolTable.index].offset = offset;
    return symbolTable.index++; //返回的是临时变量在符号表中的位置序号
}

int prn_string()
{
    int i;
    for (i = 0; i < stringsTable.index; i++)
    {
        printf("%s\n", stringsTable.string[i].name);
    }
}

int fillString(struct node *T)
{
    int i;
    for (i = 0; i < stringsTable.index; i++)
    {
        if (strcmp(T->type_id, stringsTable.string[i].name) == 0)
        {
            T->string_id = i;
            break;
        }
    }
    if (i == stringsTable.index)
    {
        T->string_id = i;
        strcpy(stringsTable.string[i].name, T->type_id);
        stringsTable.index++;
    }
}

int LEV = 0;   //层号
int func_size; //1个函数的活动记录大小
int getwidth(int rtn)
{
    int width = 0;
    int num = 1;
    if (symbolTable.symbols[rtn].type == INTEGER) width = 4;
    else if (symbolTable.symbols[rtn].type == FLOAT) width = 8;
    else if (symbolTable.symbols[rtn].type == CHAR) width = 4;
    else if (symbolTable.symbols[rtn].type == STRING) width = 4;
    //修改点：指针
    else if (symbolTable.symbols[rtn].type == POINTER)width = 4;
    if (symbolTable.symbols[rtn].flag == 'A')
    {
        for (int i = 0; i < symbolTable.symbols[rtn].length; i++)
        {
            num *= symbolTable.symbols[rtn].List[i];
        }
        return num * width;
    }
    else if (symbolTable.symbols[rtn].flag == 'S')
    {
        return symbolTable.symbols[rtn].width;
    }
    return width;
}

// 检查数组越界
void listcall(struct node *T, int rtn)
{
    struct node *T0 = T;
    int i = 0, width = 0;
    while (T0->ptr[0]->kind != ID)
    {
        T->List[i] = T0->ptr[1]->type_int;
        i++;
        T0 = T0->ptr[0];
    }
    T->List[i] = T0->ptr[1]->type_int;
    T->length = i + 1;
    if (symbolTable.symbols[rtn].length != T->length)
    {
        semantic_error(T->pos, T0->ptr[0]->type_id, "数组访问违法或越界,维数不一致");
        goto a;
    }
    int offset = 0;
    for (int j = T->length - 1; j > 0; j--)
    {
        int num = T->List[j];
        for (int k = j - 1; k >= 0; k--)
        {
            num *= symbolTable.symbols[rtn].List[k];
        }
        offset += num;
        if (T->List[j] > symbolTable.symbols[rtn].List[j] - 1)
        {
            semantic_error(T->pos, T0->ptr[0]->type_id, "数组访问违法或越界,OutOfIndex");
            goto a;
        }
    }
a:
    offset += T->List[0];
    T->type = symbolTable.symbols[rtn].type;
    width = 0;
    if (T->type == INTEGER)
        width = 4;
    else if (T->type == FLOAT)
        width = 8;
    else if (T->type == CHAR)
        width = 4;
    else if (T->type == STRING)
        width = 4;
    //修改点：指针
    else if (T->type == POINTER)
        width = 4;
    T->width = width;
    T->place = rtn;
    T->offset += offset * width;
    T->code = NULL;
}

void ext_var_list(struct node *T)
{ //处理变量列表
    int rtn, num = 1;
    switch (T->kind)
    {
    case EXT_DEC_LIST:
        T->ptr[0]->type = T->type;                //将类型属性向下传递变量结点
        T->ptr[0]->offset = T->offset;            //外部变量的偏移量向下传递
        T->ptr[1]->type = T->type;                //将类型属性向下传递变量结点
        T->ptr[1]->offset = T->offset + T->width; //外部变量的偏移量向下传递
        T->ptr[1]->width = T->width;
        ext_var_list(T->ptr[0]);
        T->ptr[1]->offset = T->offset + T->width * T->ptr[0]->num;
        ext_var_list(T->ptr[1]);
        T->num = T->ptr[1]->num + T->ptr[0]->num;
        break;
    case ID:
        rtn = fillSymbolTable(T->type_id, newAlias(), LEV, T->type, 'V', T->offset); //最后一个变量名
        if (rtn == -1)
            semantic_error(T->pos, T->type_id, "变量重复定义");
        else
            T->place = rtn;
        T->num = 1;
        break;

    case Static_List:
        if (T->ptr[0]->kind == ID)
        {
            int i = 0;
            for (i = 0; i < 5; i++)
            {
                if (T->List[i] != 0)
                    T->num *= T->List[i];
                else
                {
                    T->List[i] = T->ptr[1]->type_int;
                    T->num *= T->List[i];
                    break;
                }
            }
            T->length = i + 1;
            rtn = fillSymbolTable(T->ptr[0]->type_id, newList(), LEV, T->type, 'A', T->offset);
            if (rtn == -1)
                semantic_error(T->pos, T->type_id, "变量重复定义");
            else
            {
                T->place = rtn;
                symbolTable.symbols[rtn].length = i + 1;
                for (int j = 0; j <= i; j++)
                {
                    symbolTable.symbols[rtn].List[j] = T->List[j];
                }
            }
        }
        else
        {
            int i;
            for (i = 0; i < 5; i++)
            {
                if (T->List[i] != 0)
                    T->ptr[0]->List[i] = T->List[i];
                else
                {
                    T->ptr[0]->List[i] = T->ptr[1]->type_int;
                    break;
                }
            }
            T->ptr[0]->type = T->type;
            T->ptr[0]->offset = T->offset;
            if (T->ptr[0]->List[i] == 0)
                semantic_error(T->pos, T->type_id, "数组大小不能为零");
            else
                ext_var_list(T->ptr[0]);
            T->num = T->ptr[0]->num;
            T->place = T->ptr[0]->place;
            T->length = T->ptr[0]->length;
        }
        break;
    }
}

int match_param(int i, struct node *T)
{
    int j, num = symbolTable.symbols[i].paramnum;
    int type1, type2;
    if (num == 0 && T == NULL)
        return 1;
    for (j = 1; j <= num; j++)
    {
        if (!T)
        {
            semantic_error(T->pos, "", "函数调用参数太少");
            return 0;
        }
        type1 = symbolTable.symbols[i + j].type; //形参类型
        int rtn = searchSymbolTable(T->ptr[0]->type_id);
        type2 = T->ptr[0]->type;
        if (type1 != type2 && i>2)
        {
            semantic_error(T->pos, "", "参数类型不匹配");
            return 0;
        }
        //修改点：指针
        if (type1 == POINTER)
        {
            if (strcmp(symbolTable.symbols[i + j].struct_id, symbolTable.symbols[rtn].struct_id))
            {
                printf("%s %s %d\n",symbolTable.symbols[i + j].struct_id, symbolTable.symbols[rtn].struct_id,rtn);
                semantic_error(T->pos, "", "指针参数不匹配");
            }else if(symbolTable.symbols[i + j].permitNull == 0 && symbolTable.symbols[rtn].isNull == 1)
            {  
                semantic_error(T->pos, "", "指针实参为空 不允许");
            }
            
        }
        if (type1 == STRUCT)
        {
            if (strcmp(symbolTable.symbols[i + j].struct_id, T->ptr[0]->struct_id))
            {
                semantic_error(T->pos, "", "结构体类型参数不匹配");
            }
        }
        T = T->ptr[1];
    }
    if (T)
    { //num个参数已经匹配完，还有实参表达式
        semantic_error(T->pos, "", "函数调用参数太多");
        return 0;
    }
    return 1;
}

int match_struct(int i, struct node *T)
{
    int j, num = symbolTable.symbols[i].paramnum;
    int width2 = 0, rtn = 0;
    if (num == 0 && T == NULL)
        return 1;
    for (j = 1; j <= num; j++)
    {
        if (!strcmp(symbolTable.symbols[i + j].name, T->type_id))
        {
            T->type = symbolTable.symbols[i + j].type;
            int width = 0; //一个变量宽度
            if (T->type == INTEGER)
                width = 4;
            else if (T->type == FLOAT)
                width = 8;
            else if (T->type == CHAR)
                width = 4;
            else if (T->type == STRING)
                width = 4;
            T->width = width;
            T->offset += width2;
            rtn = i + j;
            break;
        }
        width2 += getwidth(i + j);
    }
    if (j == num + 1)
    {
        semantic_error(T->pos, T->type_id, "成员未定义");
    }
    if (symbolTable.symbols[i + j].length > 0)
    {
        if (T->isShuzu != 1)
        {
            semantic_error(T->pos, T->type_id, "不是数组");
        }
        else
        {
            listcall(T, rtn);
        }
    }
}

//
struct node *getdp(struct node *T, int id, int offset)
{
    struct node *S3 = mknode(INTEGER, NULL, NULL, NULL, 0);
    S3->type_int = 1;
    struct node *S = mknode(PLUS, T, S3, NULL, 0);
    strcpy(S->type_id, "PLUS");
    if (id == 1)
    {
        S->kind = MINUS;
        strcpy(S->type_id, "MINUS");
    }
    struct node *p = mknode(ASSIGNOP, T, S, NULL, 0);
    strcpy(p->type_id, "ASSIGNOP");
    p->offset = offset;
    Exp(p);
    p->place = T->place;
    return p;
}

// bool表达式
void boolExp(struct node *T)
{ //布尔表达式
    struct opn opn1, opn2, result;
    int op;
    int rtn;
    if (T)
    {
        switch (T->kind)
        {
        case INTEGER:
            if (T->type_int != 0)
                T->code = genGoto(T->Etrue);
            else
                T->code = genGoto(T->Efalse);
            T->width = 0;
            break;
        case FLOAT:
            if (T->type_float != 0.0)
                T->code = genGoto(T->Etrue);
            else
                T->code = genGoto(T->Efalse);
            T->width = 0;
            break;
        case STRING:
            semantic_error(T->pos, "不能将字符串作为判断条件", "");
            break;
        case CHAR:
            if (T->type_id != NULL)
                T->code = genGoto(T->Etrue);
            else
                T->code = genGoto(T->Efalse);
            T->width = 0;
            break;
        case ID: //查符号表，获得符号表中的位置，类型送type
            rtn = searchSymbolTable(T->type_id);
            if (rtn == -1)
                semantic_error(T->pos, T->type_id, "变量未定义");
            if (symbolTable.symbols[rtn].flag == 'F')
                semantic_error(T->pos, T->type_id, "是函数名，类型不匹配");
            else
            {
                opn1.kind = ID;
                strcpy(opn1.id, symbolTable.symbols[rtn].alias);
                opn1.offset = symbolTable.symbols[rtn].offset;
                opn2.kind = INTEGER;
                opn2.const_int = 0;
                result.kind = ID;
                strcpy(result.id, T->Etrue);
                T->code = genIR(NEQ, opn1, opn2, result);
                T->code = merge(2, T->code, genGoto(T->Efalse));
            }
            T->width = 0;
            break;
        case RELOP: //处理关系运算表达式,2个操作数都按基本表达式处理
            T->ptr[0]->offset = T->ptr[1]->offset = T->offset;
            Exp(T->ptr[0]);
            T->width = T->ptr[0]->width;
            Exp(T->ptr[1]);
            if (T->width < T->ptr[1]->width)
                T->width = T->ptr[1]->width;
            opn1.kind = ID;
            strcpy(opn1.id, symbolTable.symbols[T->ptr[0]->place].alias);
            opn1.offset = symbolTable.symbols[T->ptr[0]->place].offset;
            opn2.kind = ID;
            strcpy(opn2.id, symbolTable.symbols[T->ptr[1]->place].alias);
            opn2.offset = symbolTable.symbols[T->ptr[1]->place].offset;
            result.kind = ID;
            strcpy(result.id, T->Etrue);
            if (strcmp(T->type_id, "<") == 0)
                op = JLT;
            else if (strcmp(T->type_id, "<=") == 0)
                op = JLE;
            else if (strcmp(T->type_id, ">") == 0)
                op = JGT;
            else if (strcmp(T->type_id, ">=") == 0)
                op = JGE;
            else if (strcmp(T->type_id, "==") == 0)
                op = EQ;
            else if (strcmp(T->type_id, "!=") == 0)
                op = NEQ;
            T->code = genIR(op, opn1, opn2, result);
            T->code = merge(4, T->ptr[0]->code, T->ptr[1]->code, T->code, genGoto(T->Efalse));
            break;
        case AND:
        case OR:
            if (T->kind == AND)
            {
                strcpy(T->ptr[0]->Etrue, newLabel());
                strcpy(T->ptr[0]->Efalse, T->Efalse);
            }
            else
            {
                strcpy(T->ptr[0]->Etrue, T->Etrue);
                strcpy(T->ptr[0]->Efalse, newLabel());
            }
            strcpy(T->ptr[1]->Etrue, T->Etrue);
            strcpy(T->ptr[1]->Efalse, T->Efalse);
            T->ptr[0]->offset = T->ptr[1]->offset = T->offset;
            boolExp(T->ptr[0]);
            T->width = T->ptr[0]->width;
            boolExp(T->ptr[1]);
            if (T->width < T->ptr[1]->width)
                T->width = T->ptr[1]->width;
            if (T->kind == AND)
                T->code = merge(3, T->ptr[0]->code, genLabel(T->ptr[0]->Etrue), T->ptr[1]->code);
            else
                T->code = merge(3, T->ptr[0]->code, genLabel(T->ptr[0]->Efalse), T->ptr[1]->code);
            break;
        case NOT:
            strcpy(T->ptr[0]->Etrue, T->Efalse);
            strcpy(T->ptr[0]->Efalse, T->Etrue);
            boolExp(T->ptr[0]);
            T->code = T->ptr[0]->code;
            break;
        }
    }
}

//修改点：此函数应该没有引用
void dec(struct node *T)
{
    if (strcmp(T->ptr[0]->type_id, "int") == 0)
        T->ptr[0]->type = INTEGER;
    else if (strcmp(T->ptr[0]->type_id, "float") == 0)
        T->ptr[0]->type = FLOAT;
    else if (strcmp(T->ptr[0]->type_id, "char") == 0)
        T->ptr[0]->type = CHAR;
    else
        T->ptr[0]->type = STRING;
}

void Exp(struct node *T)
{ //处理基本表达式
    int rtn, num, width;
    struct node *T0;
    struct opn opn1, opn2, result;
    struct node *pp = (struct node *)malloc(sizeof(struct node));
    if (T)
    {
        switch (T->kind)
        {
        case LIST_CALL:
            T->code = NULL;
            T0 = T;
            int i = 0;
            while (T0->ptr[0]->kind != ID)
            {
                T0->ptr[1]->isShuzu = 1;
                Exp(T0->ptr[1]);
                if (T0->ptr[1]->type != INTEGER)
                {
                    semantic_error(T->pos, T0->ptr[0]->type_id, "必须是整形（数组访问）");
                }
                else if (T0->ptr[1]->kind == INTEGER)
                    T->List[i] = T0->ptr[1]->type_int;
                else
                    T->List[i] = 1;
                i++;
                T0 = T0->ptr[0];
            }
            T0->ptr[1]->isShuzu = 1;
            Exp(T0->ptr[1]);
            if (T0->ptr[1]->type != INTEGER)
            {
                semantic_error(T->pos, T0->ptr[0]->type_id, "必须是整形（数组访问）");
            }
            else if (T0->ptr[1]->kind == INTEGER)
                T->List[i] = T0->ptr[1]->type_int;
            else
                T->List[i] = -1;
            T->length = i + 1;
            rtn = searchSymbolTable(T0->ptr[0]->type_id);
            if (rtn == -1)
            {
                semantic_error(T->pos, T0->ptr[0]->type_id, "数组未定义");
                goto a;
            }
            if (symbolTable.symbols[rtn].flag == 'F')
            {
                semantic_error(T->pos, T0->ptr[0]->type_id, "是函数名，语法错误");
                goto a;
            }
            if (symbolTable.symbols[rtn].flag != 'A')
            {
                semantic_error(T->pos, T0->ptr[0]->type_id, "不是数组，不能进行数组访问");
                goto a;
            }
            if (symbolTable.symbols[rtn].length != T->length)
            {
                semantic_error(T->pos, T0->ptr[0]->type_id, "数组访问违法或越界,维数不一致");
                goto a;
            }
            //printf("axaa\n");
            int offset = 0;
            for (int j = T->length - 1; j >= 0; j--)
            {
                int num = T->List[j];
                int k = 1;
                for (int k = j - 1; k >= 0; k--)
                {
                    k *= symbolTable.symbols[rtn].List[k];
                }
                offset += num;
                if (T->List[j] > symbolTable.symbols[rtn].List[j] - 1)
                {
                    semantic_error(T->pos, T0->ptr[0]->type_id, "数组访问违法或越界,OutOfIndex");
                    goto a;
                }
                T->List[j] = k;
            }
        a:
            T0 = T;
            i = 0;
            struct codenode *code2;
            struct node *t = mknode(INTEGER, NULL, NULL, NULL, 0);
            t->type_int = 0;
            T0->offset = T->offset;
            t->offset = T->offset;
            for (int j = 0; j < T->length; j++)
            {
                struct node *m = mknode(INTEGER, NULL, NULL, NULL, 0);
                m->type_int = 1;
                struct node *t1 = mknode(PLUS, T0->ptr[1], m, NULL, 0);
                strcpy(t1->type_id, "PLUS");
                struct node *t2 = mknode(INTEGER, NULL, NULL, NULL, 0);
                t2->type_int = T->List[j];
                struct node *t3 = mknode(STAR, t2, t1, NULL, 0);
                strcpy(t3->type_id, "STAR");
                struct node *t4 = mknode(PLUS, t3, t, NULL, 0);
                strcpy(t4->type_id, "PLUS");
                t = t4;
                T0 = T0->ptr[0];
            }
            struct node *t2 = mknode(INTEGER, NULL, NULL, NULL, 0);
            t2->type_int = symbolTable.symbols[rtn].offset;
            struct node *t5 = mknode(INTEGER, NULL, NULL, NULL, 0);
            t5->type_int = 4;
            struct node *t6 = mknode(STAR, t, t5, NULL, 0);
            strcpy(t6->type_id, "STAR");
            struct node *t4 = mknode(PLUS, t2, t6, NULL, 0);
            strcpy(t4->type_id, "PLUS");
            t = t4;
            t->offset = T->offset;
            Exp(t);
            T->type = symbolTable.symbols[rtn].type;
            opn1.kind = Static_List;
            strcpy(opn1.id, symbolTable.symbols[t->place].alias); //右值一定是个变量或临时变量
            opn1.offset = symbolTable.symbols[t->place].offset;
            result.offset = opn1.offset + 4;
            T->offset = result.offset;
            T->place = fill_Temp(newTemp(), LEV, T->type, 'T', T->offset);
            result.kind = ID;
            strcpy(result.id, symbolTable.symbols[T->place].alias);
            result.offset = symbolTable.symbols[T->place].offset;
            T->code = merge(2, t->code, genIR(ASSIGNOP, opn1, opn2, result));
            T->type = symbolTable.symbols[rtn].type;
            width = 0;
            T->width = 0;
            T->offset = result.offset + 4;
            break;
        case ID: //查符号表，获得符号表中的位置，类型送type
            rtn = searchSymbolTable(T->type_id);
            if (rtn == -1)
                semantic_error(T->pos, T->type_id, "变量未定义");
            if (symbolTable.symbols[rtn].flag == 'F')
                semantic_error(T->pos, T->type_id, "是函数名，类型不匹配");
            else
            {
                T->place = rtn; //结点保存变量在符号表中的位置
                T->code = NULL; //标识符不需要生成TAC
                T->type = symbolTable.symbols[rtn].type;
                T->offset = symbolTable.symbols[rtn].offset;
                strcpy(T->struct_id, symbolTable.symbols[rtn].struct_id);
                T->width = 0; //未再使用新单元
            }
            break;
         //修改点：指针
        case POINTER:
            rtn = searchSymbolTable(T->type_id);
            if (rtn == -1)
                semantic_error(T->pos, T->type_id, "变量未定义");
            if (symbolTable.symbols[rtn].flag == 'F')
                semantic_error(T->pos, T->type_id, "是函数名，类型不匹配");
            else
            {
                if(symbolTable.symbols[rtn].type != POINTER)
                {
                    // T->type = POINTER;
                    // T->place = fill_Temp(newTemp(), LEV, T->type, 'T', T->offset); //为取址指针生成一个临时变量
                    // opn1.kind = POINTER;
                    // strcpy(opn1.id, symbolTable.symbols[rtn].alias);
                    // result.kind = POINTER;
                    // strcpy(result.id, symbolTable.symbols[T->place].alias);
                    // result.offset = symbolTable.symbols[T->place].offset;
                    // strcmp(symbolTable.symbols[T->place].struct_id , T->type_id);
                    // symbolTable.symbols[T->place].isNull = 0;
                    // T->code = genIR(ASSIGNOP, opn1, opn2, result);
                    // T->width = 4;
                    T->place = rtn; //结点保存变量在符号表中的位置
                    T->code = NULL; //标识符不需要生成TAC
                    T->type = POINTER;
                    T->offset = symbolTable.symbols[rtn].offset;
                    strcpy(T->struct_id, symbolTable.symbols[rtn].struct_id);
                    T->width = 0; //未再使用新单元
                }
                else
                {
                    if(strcmp(symbolTable.symbols[rtn].struct_id,"int"))
                        T->type = INTEGER;
                    else if(strcmp(symbolTable.symbols[rtn].struct_id,"float"))
                        T->type = FLOAT;
                    else if(strcmp(symbolTable.symbols[rtn].struct_id,"char"))
                        T->type = CHAR;
                    else 
                        T->type = STRING;
                    // T->place = fill_Temp(newTemp(), LEV, T->type, 'T', T->offset); //为取址指针生成一个临时变量
                    // opn1.kind = T->type;
                    // strcpy(opn1.id, symbolTable.symbols[rtn].alias);
                    // result.kind = T->type;
                    // strcpy(result.id, symbolTable.symbols[T->place].alias);
                    // result.offset = symbolTable.symbols[T->place].offset;
                    // strcmp(symbolTable.symbols[T->place].struct_id , T->type_id);
                    
                    // printf("sss:  %d\n",symbolTable.symbols[rtn].offset);

                    // symbolTable.symbols[T->place].isNull = 0;
                    // T->code = genIR(ASSIGNOP, opn1, opn2, result);
                    // T->width = 4;
                     T->place = rtn; //结点保存变量在符号表中的位置
                    T->code = NULL; //标识符不需要生成TAC
                    
                    T->offset = symbolTable.symbols[rtn].offset;
                    strcpy(T->struct_id, symbolTable.symbols[rtn].struct_id);
                    T->width = 0; //未再使用新单元
                }
            }
            break;
        case CHAR:
            T->type = CHAR;
            T->place = fill_Temp(newTemp(), LEV, T->type, 'T', T->offset); //为浮点常量生成一个临时变量
            opn1.kind = CHAR;
            opn1.const_char = T->type_id[1];
            result.kind = ID;
            strcpy(result.id, symbolTable.symbols[T->place].alias);
            result.offset = symbolTable.symbols[T->place].offset;
            T->code = genIR(ASSIGNOP, opn1, opn2, result);
            T->width = 4;

            break;
        case STRING:
            T->type = STRING;
            T->place = fill_Temp(newTemp(), LEV, T->type, 'T', T->offset); //为浮点常量生成一个临时变量
            opn1.kind = STRING;
            strcpy(opn1.const_string, T->type_id);
            result.kind = ID;
            strcpy(result.id, symbolTable.symbols[T->place].alias);
            result.offset = symbolTable.symbols[T->place].offset;
            T->code = genIR(ASSIGNOP, opn1, opn2, result);
            T->width = T->num;
            fillString(T);
            break;
        case INTEGER:
            T->type = INTEGER;
            T->place = fill_Temp(newTemp(), LEV, T->type, 'T', T->offset); //为整常量生成一个临时变量
            opn1.kind = INTEGER;
            opn1.const_int = T->type_int;
            result.kind = ID;
            strcpy(result.id, symbolTable.symbols[T->place].alias);
            result.offset = symbolTable.symbols[T->place].offset;
            T->code = genIR(ASSIGNOP, opn1, opn2, result);
            T->width = 4;
            break;
        case FLOAT:
            T->type = FLOAT;
            float x = T->type_float - (int)T->type_float;
            int y = 0;
            for (int i = 0; i < MAX_BYTE; i++)
            {
                result.byte[i] = (int)(x * 2);
                x = x * 2 - result.byte[i];
            }
            T->place = fill_Temp(newTemp(), LEV, T->type, 'T', T->offset); //为浮点常量生成一个临时变量
            opn1.kind = FLOAT;
            opn1.const_float = T->type_float;
            result.kind = ID;
            strcpy(result.id, symbolTable.symbols[T->place].alias);
            result.offset = symbolTable.symbols[T->place].offset;
            T->code = genIR(ASSIGNOP, opn1, opn2, result);
            T->width = 4;
            break;
        case ASSIGNOP:
            if (T->ptr[0]->kind != ID && T->ptr[0]->kind != STRUCT_CALL && T->ptr[0]->kind != LIST_CALL)
            {
                semantic_error(T->pos, "", "赋值语句需要左值");
            }
            else
            {
                if (T->ptr[0]->kind == LIST_CALL)
                {
                    T->ptr[0]->offset = T->offset;
                }
                Exp(T->ptr[0]); //处理左值，例中仅为变量
                T->ptr[1]->offset = T->offset;
                if (T->ptr[0]->kind == LIST_CALL)
                {
                    T->ptr[1]->offset = T->ptr[0]->offset;
                }
                Exp(T->ptr[1]);
                T->type = T->ptr[0]->type;
                T->width = T->ptr[1]->width;
                if (T->type == FLOAT && T->ptr[1]->type == INTEGER)
                {
                    goto b;
                }
                if (T->type != T->ptr[1]->type)
                {
                    semantic_error(T->pos, "", "赋值语句两边的表达式类型不匹配");
                }
                if (T->type == POINTER)
                {
                    int rtn1 = searchSymbolTable(T->ptr[0]->type_id);
                    int rtn2 = searchSymbolTable(T->ptr[1]->type_id);
                    if (strcmp(symbolTable.symbols[rtn1].struct_id, symbolTable.symbols[rtn2].struct_id))
                    {
                        printf("aa%s aa%s\n",symbolTable.symbols[rtn1].struct_id, symbolTable.symbols[rtn2].struct_id);
                        semantic_error(T->pos, "", "赋值语句两边的指针类型不匹配");
                    }
                    symbolTable.symbols[rtn1].isNull=symbolTable.symbols[rtn2].isNull;
                }
                if (T->type == STRUCT)
                {
                    int rtn1 = searchSymbolTable(T->ptr[0]->type_id);
                    int rtn2 = searchSymbolTable(T->ptr[1]->type_id);
                    if (strcmp(T->ptr[0]->struct_id, T->ptr[1]->struct_id))
                    {
                        semantic_error(T->pos, "", "赋值语句两边的结构体类型不匹配");
                    }
                }
            b:
                T->code = merge(2, T->ptr[0]->code, T->ptr[1]->code);
                opn1.kind = ID;
                strcpy(opn1.id, symbolTable.symbols[T->ptr[1]->place].alias); //右值一定是个变量或临时变量
                opn1.offset = symbolTable.symbols[T->ptr[1]->place].offset;
                result.kind = ID;
                strcpy(result.id, symbolTable.symbols[T->ptr[0]->place].alias);
                result.offset = symbolTable.symbols[T->ptr[0]->place].offset;
                if (T->ptr[0]->kind == LIST_CALL)
                {
                    result.kind = Static_List;
                }
                T->offset = result.offset;
                T->code = merge(2, T->code, genIR(ASSIGNOP, opn1, opn2, result));
            }
            break;
        case AND:   //按算术表式方式计算布尔值，未写完
        case OR:    //按算术表达式方式计算布尔值，未写完
        case RELOP: //按算术表达 式方式计算布尔值，未写完
            T->type = INTEGER;
            T->ptr[0]->offset = T->ptr[1]->offset = T->offset;
            Exp(T->ptr[0]);
            Exp(T->ptr[1]);
            if (T->ptr[0]->type == FLOAT && T->ptr[1]->type == INTEGER)
                goto d;
            if (T->ptr[0]->type != T->ptr[1]->type)
            {
                semantic_error(T->pos, "", "操作数类型不匹配");
            }
        d:
            T->width = T->ptr[0]->width + T->ptr[1]->width + 2;
            T->place = fill_Temp(newTemp(), LEV, T->type, 'T', T->offset + T->ptr[0]->width + T->ptr[1]->width);
            T->place = fill_Temp(newTemp(), LEV, T->type, 'T', T->offset + T->ptr[0]->width + T->ptr[1]->width);
            opn1.kind = ID;
            strcpy(opn1.id, symbolTable.symbols[T->ptr[0]->place].alias);
            opn1.type = T->ptr[0]->type;
            opn1.offset = symbolTable.symbols[T->ptr[0]->place].offset;
            opn2.kind = ID;
            strcpy(opn2.id, symbolTable.symbols[T->ptr[1]->place].alias);
            opn2.type = T->ptr[1]->type;
            opn2.offset = symbolTable.symbols[T->ptr[1]->place].offset;
            result.kind = ID;
            strcpy(result.id, symbolTable.symbols[T->place].alias);
            result.type = T->type;
            result.offset = symbolTable.symbols[T->place].offset;
            T->code = merge(3, T->ptr[0]->code, T->ptr[1]->code, genIR(T->kind, opn1, opn2, result));
            T->width = T->ptr[0]->width + T->ptr[1]->width + 4;
            break;

        case PLUS:
        case MINUS:
        case STAR:
        case DIV:
            T->ptr[0]->offset = T->offset;
            Exp(T->ptr[0]);
            T->ptr[1]->offset = T->offset + T->ptr[0]->width;
            Exp(T->ptr[1]);
            if (T->ptr[0]->type == FLOAT && T->ptr[1]->type == INTEGER)
                goto c;
            if (T->ptr[0]->type != T->ptr[1]->type)
            {
                semantic_error(T->pos, "", "操作数类型不匹配");
            }
            //判断T->ptr[0]，T->ptr[1]类型是否正确，可能根据运算符生成不同形式的代码，给T的type赋值
            //下面的类型属性计算，没有考虑错误处理情况
        c:
            if (T->ptr[0]->type == FLOAT || T->ptr[1]->type == FLOAT)
                T->type = FLOAT, T->width = T->ptr[0]->width + T->ptr[1]->width + 4;
            else
                T->type = INTEGER, T->width = T->ptr[0]->width + T->ptr[1]->width + 2;
            T->place = fill_Temp(newTemp(), LEV, T->type, 'T', T->offset + T->ptr[0]->width + T->ptr[1]->width);
            opn1.kind = ID;
            strcpy(opn1.id, symbolTable.symbols[T->ptr[0]->place].alias);
            opn1.type = T->ptr[0]->type;
            opn1.offset = symbolTable.symbols[T->ptr[0]->place].offset;
            opn2.kind = ID;
            strcpy(opn2.id, symbolTable.symbols[T->ptr[1]->place].alias);
            opn2.type = T->ptr[1]->type;
            opn2.offset = symbolTable.symbols[T->ptr[1]->place].offset;
            result.kind = ID;
            strcpy(result.id, symbolTable.symbols[T->place].alias);
            result.type = T->type;
            result.offset = symbolTable.symbols[T->place].offset;
            T->code = merge(3, T->ptr[0]->code, T->ptr[1]->code, genIR(T->kind, opn1, opn2, result));
            width = 0; //一个变量宽度
            if (T->type == INTEGER)
                width = 4;
            else if (T->type == FLOAT)
                width = 8;
            else if (T->type == CHAR)
                width = 4;
            else if (T->type == STRING)
                width = 4;
            T->width = T->ptr[0]->width + T->ptr[1]->width + width;
            break;
        case UMINUS: //未写完整
            T->ptr[0]->offset = T->offset;
            struct node *S3 = mknode(INTEGER, NULL, NULL, NULL, 0);
            S3->type_int = -1;
            struct node *S = mknode(STAR, T->ptr[0], S3, NULL, 0);
            strcpy(S->type_id, "STAR");
            S->offset = T->offset;
            Exp(S);
            T->code = S->code;
            T->type = S->type;
            T->width = S->width;
            T->place = S->place;
            break;
        case NOT: //未写完整
            T->ptr[0]->offset = T->offset;
            Exp(T->ptr[0]);
            if (T->ptr[0]->type != INTEGER)
            {
                semantic_error(T->pos, "", "操作数类型不匹配");
                break;
            }
            T->type = INTEGER;
            T->width = T->ptr[0]->width + 4;
            T->place = fill_Temp(newTemp(), LEV, T->type, 'T', T->offset + T->ptr[0]->width);
            opn1.kind = ID;
            strcpy(opn1.id, symbolTable.symbols[T->ptr[0]->place].alias);
            opn1.type = T->ptr[0]->type;
            opn1.offset = symbolTable.symbols[T->ptr[0]->place].offset;
            result.kind = ID;
            strcpy(result.id, symbolTable.symbols[T->place].alias);
            result.type = T->type;
            result.offset = symbolTable.symbols[T->place].offset;
            T->code = merge(2, T->ptr[0]->code, genIR(T->kind, opn1, opn2, result));
            break;
        case PLUSPLUS2:
        case PLUSPLUS:
            T->type = INTEGER;
            if (T->ptr[0]->kind != ID && T->ptr[0]->kind != STRUCT_CALL && T->ptr[0]->kind == LIST_CALL)
            {
                semantic_error(T->pos, "", "自增自减操作对象不能是表达式");
                break;
            }
            T->ptr[0]->offset = T->offset;
            Exp(T->ptr[0]);
            if (T->ptr[0]->type != INTEGER)
            {
                semantic_error(T->pos, "", "自增自减操作对象必须是整形");
                break;
            }
            if (T->kind == PLUSPLUS)
            {
                int id = 0;
                if (strcmp(T->type_id, "++") == 0)
                    ;
                else
                    id = 1;
                struct node *p = getdp(T->ptr[0], id, T->offset);
                T->code = p->code;
                T->place = p->place;
                T->width = p->width;
            }
            else
            {
                dpTable.dps[dpTable.index] = T->ptr[0];
                if (strcmp(T->type_id, "++") == 0)
                    dpTable.id[dpTable.index] = 0;
                else
                    dpTable.id[dpTable.index] = 1;
                dpTable.index++;
                T->place = T->ptr[0]->place;
                T->code = T->ptr[0]->code;
                T->width = T->ptr[0]->width;
            }
            break;
        case FUHE:
            if (strcmp(T->type_id, "+=") == 0)
            {
                pp = mknode(PLUS, T->ptr[0], T->ptr[1], NULL, 0), strcpy(pp->type_id, "PLUS");
            }
            else if (strcmp(T->type_id, "-=") == 0)
            {
                pp = mknode(MINUS, T->ptr[0], T->ptr[1], NULL, 0), strcpy(pp->type_id, "MINUS");
            }
            else if (strcmp(T->type_id, "*=") == 0)
            {
                pp = mknode(STAR, T->ptr[0], T->ptr[1], NULL, 0), strcpy(pp->type_id, "STAR");
            }
            else if (strcmp(T->type_id, "/=") == 0)
            {
                pp = mknode(DIV, T->ptr[0], T->ptr[1], NULL, 0), strcpy(pp->type_id, "DIV");
            }
            struct node *p2 = mknode(ASSIGNOP, T->ptr[0], pp, NULL, 0);
            strcpy(p2->type_id, "ASSIGNOP");
            p2->offset = T->offset;
            Exp(p2);
            T->offset = p2->offset + p2->width;
            T->code = p2->code;
            T->place = p2->place;
            break;
        case FUNC_CALL: //根据T->type_id查出函数的定义，如果语言中增加了实验教材的read，write需要单独处理一下
            rtn = searchSymbolTable(T->type_id);
            if (rtn == -1)
            {
                semantic_error(T->pos, T->type_id, "函数未定义");
                break;
            }
            if (symbolTable.symbols[rtn].flag != 'F')
            {
                semantic_error(T->pos, T->type_id, "不是一个函数");
                break;
            }
            T->type = symbolTable.symbols[rtn].type;
            width = 0; //一个变量宽度
            if (T->type == INTEGER)
                width = 4;
            else if (T->type == FLOAT)
                width = 8;
            else if (T->type == CHAR)
                width = 4;
            else if (T->type == STRING)
                width = 4;
            if (T->ptr[0])
            {
                T->ptr[0]->offset = T->offset;
                Exp(T->ptr[0]);                      //处理所有实参表达式求值，及类型
                T->width = T->ptr[0]->width + width; //累加上计算实参使用临时变量的单元数
                T->code = T->ptr[0]->code;
            }
            else
            {
                T->width = width;
                T->code = NULL;
            }
            if (symbolTable.symbols[rtn].paramnum > 0 && T->ptr[0] == NULL)
            {
                semantic_error(T->pos, "", "函数调用参数太少");
            }
            else
                match_param(rtn, T->ptr[0]); //处理所以参数的匹配
            //处理参数列表的中间代码
            T0 = T->ptr[0];
            while (T0)
            {
                result.kind = ID;
                strcpy(result.id, symbolTable.symbols[T0->ptr[0]->place].alias);
                result.offset = symbolTable.symbols[T0->ptr[0]->place].offset;
                T->code = merge(2, T->code, genIR(ARG, opn1, opn2, result));
                T0 = T0->ptr[1];
            }
            T->place = fill_Temp(newTemp(), LEV, T->type, 'T', T->offset + T->width - width);
            opn1.kind = ID;
            strcpy(opn1.id, T->type_id); //保存函数名
            opn1.offset = rtn;           //这里offset用以保存函数定义入口,在目标代码生成时，能获取相应信息
            result.kind = ID;
            strcpy(result.id, symbolTable.symbols[T->place].alias);
            result.offset = symbolTable.symbols[T->place].offset;
            T->code = merge(2, T->code, genIR(CALL, opn1, opn2, result)); //生成函数调用中间代码
            break;
        case STRUCT_CALL:
            rtn = searchSymbolTable(T->type_id);
            if (rtn == -1)
            {
                semantic_error(T->pos, T->type_id, "结构未定义");
                break;
            }
            if (strcmp(symbolTable.symbols[rtn].struct_id, "") == 0)
            {
                semantic_error(T->pos, T->type_id, "不是一个结构体，不能使用成员符");
                break;
            }
            int rtn2 = searchSymbolTable(symbolTable.symbols[rtn].struct_id);
            T->ptr[0]->pos = T->pos;
            T->ptr[0]->offset = symbolTable.symbols[rtn].offset;
            match_struct(rtn2, T->ptr[0]);
            T->type = T->ptr[0]->type;
            T->offset = T->ptr[0]->offset;
            T->width = T->ptr[0]->width;
            T->place = fill_Temp(newTemp(), LEV, T->type, 'T', T->offset);
            T->code = NULL;
            break;
        case BREAK:
            if (strcmp(T->Break, "") == 0)
            {
                semantic_error(T->pos, T->type_id, "位置不在循环结构体内");
            }
            else
                T->code = genGoto(T->Break);
            break;
        case ARGS: //此处仅处理各实参表达式的求值的代码序列，不生成ARG的实参系列
            T->ptr[0]->offset = T->offset;
            Exp(T->ptr[0]);
            T->width = T->ptr[0]->width;
            T->code = T->ptr[0]->code;
            if (T->ptr[1])
            {
                T->ptr[1]->offset = T->offset + T->ptr[0]->width;
                Exp(T->ptr[1]);
                T->width += T->ptr[1]->width;
                T->code = merge(2, T->code, T->ptr[1]->code);
            }
            break;
        }
    }
}

void semantic_Analysis(struct node *T)
{ //对抽象语法树的先根遍历,按display的控制结构修改完成符号表管理和语义检查和TAC生成（语句部分）
    int rtn, num, width;
    struct node *T0;
    struct opn opn1, opn2, result;
    if (T)
    {
        switch (T->kind)
        {
        case EXT_DEF_LIST:
            if (!T->ptr[0])
                break;
            T->ptr[0]->offset = T->offset;
            semantic_Analysis(T->ptr[0]); //访问外部定义列表中的第一个
            T->code = T->ptr[0]->code;
            if (T->ptr[1])
            {
                T->ptr[1]->offset = T->ptr[0]->offset + T->ptr[0]->width;
                semantic_Analysis(T->ptr[1]); //访问该外部定义列表中的其它外部定义
                T->code = merge(2, T->code, T->ptr[1]->code);
            }
            break;
        case EXT_VAR_DEF: //处理外部说明,将第一个孩子(TYPE结点)中的类型送到第二个孩子的类型域
            if (strcmp(T->ptr[0]->type_id, "int") == 0)
                T->type = INTEGER;
            else if (strcmp(T->ptr[0]->type_id, "float") == 0)
                T->type = FLOAT;
            else if (strcmp(T->ptr[0]->type_id, "char") == 0)
                T->type = CHAR;
            else if (strcmp(T->ptr[0]->type_id, "string") == 0)
                T->type = STRING;
            //修改点：指针
            else T->type = POINTER;
            if (T->ptr[0]->kind == StructSpecifier)
            {
                T->ptr[0]->offset = T->offset;
                T->ptr[0]->isSTRUCT = 1;
                semantic_Analysis(T->ptr[0]);
            }
            if (T->ptr[1])
            {
                T->ptr[1]->type = T->type;
                T->ptr[1]->offset = T->offset;
                //这个外部变量的偏移量向下传递
                if (T->type == INTEGER)
                    T->ptr[1]->width = 4;
                else if (T->type == FLOAT)
                    T->ptr[1]->width = 8;
                else if (T->type == CHAR)
                    T->ptr[1]->width = 4;
                else if (T->type == STRING)
                    T->ptr[1]->width = 4;
                //修改点：指针
                else T->ptr[1]->width = 4;
                ext_var_list(T->ptr[1]);                      //处理外部变量说明中的标识符序列
                T->width = T->ptr[1]->width * T->ptr[1]->num; //计算这个外部变量说明的宽度
                T->code = NULL;
                break;
            }
            break;
        case FUNC_DEF: //填写函数定义信息到符号表
            if (strcmp(T->ptr[0]->type_id, "int") == 0)
                T->ptr[1]->type = INTEGER;
            else if (strcmp(T->ptr[0]->type_id, "float") == 0)
                T->ptr[1]->type = FLOAT;
            else if (strcmp(T->ptr[0]->type_id, "char") == 0)
                T->ptr[1]->type = CHAR;
            else if (strcmp(T->ptr[0]->type_id, "string") == 0)
                T->type = STRING;
            //修改点：指针
            else T->type = POINTER;
            if (T->ptr[0]->isSTRUCT == 1)
            {
                T->ptr[1]->type = STRUCT;
                strcpy(T->ptr[1]->struct_id, T->ptr[0]->type_id);
            }
            T->type = T->ptr[1]->type;
            T->width = 0;                  //函数的宽度设置为0，不会对外部变量的地址分配产生影响
            T->offset = DX;                //设置局部变量在活动记录中的偏移量初值
            semantic_Analysis(T->ptr[1]);  //处理函数名和参数结点部分，这里不考虑用寄存器传递参数
            T->offset += T->ptr[1]->width; //用形参单元宽度修改函数局部变量的起始偏移量
            T->ptr[2]->offset = T->offset;
            strcpy(T->ptr[2]->Snext, newLabel()); //函数体语句执行结束后的位置属性
            semantic_Analysis(T->ptr[2]);         //处理函数体结点
            //计算活动记录大小,这里offset属性存放的是活动记录大小，不是偏移
            symbolTable.symbols[T->ptr[1]->place].offset = T->offset + T->ptr[2]->width;
            T->code = merge(3, T->ptr[1]->code, T->ptr[2]->code, genLabel(T->ptr[2]->Snext));
            //函数体的代码作为函数的代码
            break;
        case FUNC_DEC:                                                           //根据返回类型，函数名填写符号表
            rtn = fillSymbolTable(T->type_id, newAlias(), LEV, T->type, 'F', 0); //函数不在数据区中分配单元，偏移量为0
            if (rtn == -1)
            {
                semantic_error(T->pos, T->type_id, "函数重复定义");
                break;
            }
            else
                T->place = rtn;
            if (T->type == STRUCT)
            {
                strcpy(symbolTable.symbols[rtn].struct_id, T->struct_id);
            }
            result.kind = ID;
            strcpy(result.id, T->type_id);
            result.offset = rtn;
            T->code = genIR(FUNCTION, opn1, opn2, result); //生成中间代码：FUNCTION 函数名
            T->offset = DX;                                //设置形式参数在活动记录中的偏移量初值
            if (T->ptr[0])
            { //判断是否有参数
                T->ptr[0]->offset = T->offset;
                semantic_Analysis(T->ptr[0]); //处理函数参数列表
                T->width = T->ptr[0]->width;
                symbolTable.symbols[rtn].paramnum = T->ptr[0]->num;
                T->code = merge(2, T->code, T->ptr[0]->code); //连接函数名和参数代码序列
            }
            else
                symbolTable.symbols[rtn].paramnum = 0, T->width = 0;
            break;
        case StructSpecifier:
            rtn = fillSymbolTable(T->type_id, newAlias(), LEV, T->type, 'S', T->offset); //函数不在数据区中分配单元，偏移量为0
            if (rtn == -1)
            {
                semantic_error(T->pos, T->type_id, "结构体重复定义");
                break;
            }
            else
                T->place = rtn;
            result.kind = ID;
            strcpy(result.id, T->type_id);
            result.offset = rtn;
            T->code = genIR(StructSpecifier, opn1, opn2, result); //生成中间代码：FUNCTION 函数名
            if (T->ptr[0])
            { //判断是否有参数
                T->ptr[0]->offset = T->offset;
                T->ptr[0]->isSTRUCT = T->isSTRUCT;
                semantic_Analysis(T->ptr[0]); //处理函数参数列表
                T->width = T->ptr[0]->width;
                symbolTable.symbols[rtn].width = T->width;
                symbolTable.symbols[rtn].paramnum = T->ptr[0]->num;
                T->code = merge(2, T->code, T->ptr[0]->code); //连接函数名和参数代码序列
            }
            else
                symbolTable.symbols[rtn].paramnum = 0, T->width = 0, symbolTable.symbols[rtn].width = 0;
            break;
        case PARAM_LIST: //处理函数形式参数列表
            T->ptr[0]->offset = T->offset;
            semantic_Analysis(T->ptr[0]);
            if (T->ptr[1])
            {
                T->ptr[1]->offset = T->offset + T->ptr[0]->width;
                semantic_Analysis(T->ptr[1]);
                T->num = T->ptr[0]->num + T->ptr[1]->num;             //统计参数个数
                T->width = T->ptr[0]->width + T->ptr[1]->width;       //累加参数单元宽度
                T->code = merge(2, T->ptr[0]->code, T->ptr[1]->code); //连接参数代码
            }
            else
            {
                T->num = T->ptr[0]->num;
                T->width = T->ptr[0]->width;
                T->code = T->ptr[0]->code;
            }
            break;
        case PARAM_DEC:
            if (strcmp(T->ptr[0]->type_id, "int") == 0)
                T->ptr[0]->type = INTEGER;
            else if (strcmp(T->ptr[0]->type_id, "float") == 0)
                T->ptr[0]->type = FLOAT;
            else if (strcmp(T->ptr[0]->type_id, "char") == 0)
                T->ptr[0]->type = CHAR;
            else if (strcmp(T->ptr[0]->type_id, "string") == 0)
                T->ptr[0]->type = STRING;
            //修改点：指针
            else if(T->ptr[0]->type_id[strlen(T->ptr[0]->type_id)-1]=='@')
            {
                fun(T->ptr[0]->type_id);
                T->ptr[0]->type = POINTER;
            }                
            else
            {
                T->ptr[0]->type = STRUCT;
            }
            rtn = fillSymbolTable(T->ptr[1]->type_id, newAlias(), 1, T->ptr[0]->type, 'P', T->offset);
            if (rtn == -1)
                semantic_error(T->ptr[1]->pos, T->ptr[1]->type_id, "参数名重复定义");
            else
                T->ptr[1]->place = rtn;
            strcpy(symbolTable.symbols[rtn].struct_id, T->ptr[0]->type_id);
            T->num = 1; //参数个数计算的初始值
            T->ptr[1]->width = getwidth(rtn);
            T->width = T->ptr[1]->width;
            result.kind = ID;
            strcpy(result.id, symbolTable.symbols[rtn].alias);
            result.offset = T->offset;
            T->code = genIR(PARAM, opn1, opn2, result); //生成：FUNCTION 函数名
            break;
        case COMP_STM:
            LEV++;
            //设置层号加1，并且保存该层局部变量在符号表中的起始位置在symbol_scope_TX
            symbol_scope_TX.TX[symbol_scope_TX.top++] = symbolTable.index;
            T->width = 0;
            T->code = NULL;
            //printf("%s\n",T->offset);
            if (T->ptr[0])
            {
                T->ptr[0]->offset = T->offset;
                strcpy(T->ptr[0]->Break, T->Break);
                semantic_Analysis(T->ptr[0]); //处理该层的局部变量DEF_LIST
                T->width += T->ptr[0]->width;
                T->code = T->ptr[0]->code;
            }
            if (T->ptr[1])
            {
                T->ptr[1]->offset = T->offset + T->width;
                strcpy(T->ptr[1]->Snext, T->Snext); //S.next属性向下传递
                strcpy(T->ptr[1]->Break, T->Break);
                semantic_Analysis(T->ptr[1]); //处理复合语句的语句序列
                T->width += T->ptr[1]->width;
                T->code = merge(2, T->code, T->ptr[1]->code);
            }
            //prn_symbol();       //c在退出一个符合语句前显示的符号表
            LEV--; //出复合语句，层号减1
            //symbolTable.index=symbol_scope_TX.TX[--symbol_scope_TX.top]; //删除该作用域中的符号
            break;
        case DEF_LIST:
            T->code = NULL;
            T->num = 0;
            if (T->ptr[0])
            {
                T->ptr[0]->offset = T->offset;
                T->ptr[0]->isSTRUCT = T->isSTRUCT;
                semantic_Analysis(T->ptr[0]); //处理一个局部变量定义
                T->num += T->ptr[0]->num;
                T->code = T->ptr[0]->code;
                T->width = T->ptr[0]->width;
            }
            if (T->ptr[1])
            {
                T->ptr[1]->offset = T->offset + T->ptr[0]->width;
                T->ptr[1]->isSTRUCT = T->isSTRUCT;
                semantic_Analysis(T->ptr[1]); //处理剩下的局部变量定义
                T->num += T->ptr[1]->num;
                T->code = merge(2, T->code, T->ptr[1]->code);
                T->width += T->ptr[1]->width;
            }
            break;
        case VAR_DEF: //处理一个局部变量定义,将第一个孩子(TYPE结点)中的类型送到第二个孩子的类型域
                      //类似于上面的外部变量EXT_VAR_DEF，换了一种处理方法
            T->code = NULL;
            if (strcmp(T->ptr[0]->type_id, "int") == 0)
                T->ptr[1]->type = INTEGER;
            else if (strcmp(T->ptr[0]->type_id, "float") == 0)
                T->ptr[1]->type = FLOAT;
            else if (strcmp(T->ptr[0]->type_id, "char") == 0)
                T->ptr[1]->type = CHAR;
            else if (strcmp(T->ptr[0]->type_id, "string") == 0)
                T->ptr[1]->type = STRING;
            //修改点：指针
            else{
                fun(T->ptr[0]->type_id);
                strcpy(T->ptr[1]->type_id, T->ptr[0]->type_id);
                T->ptr[1]->type = POINTER;
            } 

            if (T->ptr[0]->kind == StructSpecifier)
            {
                strcpy(T->ptr[1]->struct_id, T->ptr[0]->type_id);
                T->ptr[1]->type = STRUCT;
            }
            T->type = T->ptr[1]->type;
            T0 = T->ptr[1]; //T0为变量名列表子树根指针，对ID、ASSIGNOP类结点在登记到符号表，作为局部变量
            T->num = 0;
            T0->offset = T->offset;
            T->width = 0;
            width = 0; //
            int lev = 0, num2 = 0;
            char flag2 = 'V';
            if (T->isSTRUCT == 1)
                lev = LEV + 1;
            else
                lev = LEV;
            if (T->type == INTEGER)
                width = 4;
            else if (T->type == FLOAT)
                width = 8;
            else if (T->type == CHAR)
                width = 4;
            else if (T->type == STRING)
                width = 4;
            else if (T->type == POINTER)
                width = 4;
            if (T->ptr[0]->kind == StructSpecifier)
            {
                rtn = searchSymbolTable(T->ptr[0]->type_id);
                if (rtn == -1)
                {
                    semantic_error(T->pos, T->ptr[0]->type_id, "结构体未定义");
                    break;
                }
                if (symbolTable.symbols[rtn].flag != 'S')
                {
                    semantic_error(T->pos, T->ptr[0]->type_id, "不是结构体");
                    break;
                }
                width = symbolTable.symbols[rtn].width;
                flag2 = 'S';
                T0->type = STRUCT;
                num2 = symbolTable.symbols[rtn].paramnum;
            }
            while (T0)
            { //处理所以DEC_LIST结点

                T0->ptr[0]->type = T0->type; //类型属性向下传递
                if (T0->ptr[1])
                    T0->ptr[1]->type = T0->type;
                T0->ptr[0]->offset = T0->offset; //类型属性向下传递
                if (T0->ptr[1])
                    T0->ptr[1]->offset = T0->offset + width;
                if (T0->ptr[0]->kind == ID)
                {
                    rtn = fillSymbolTable(T0->ptr[0]->type_id, newAlias(), lev, T0->ptr[0]->type, flag2, T->offset + T->width); //此处偏移量未计算，暂时为0
                    if (rtn == -1)
                        semantic_error(T0->ptr[0]->pos, T0->ptr[0]->type_id, "变量重复定义");
                    else
                        T0->ptr[0]->place = rtn;
                    if (flag2 == 'S' && rtn != -1)
                    {
                        symbolTable.symbols[rtn].paramnum = num2;
                        strcpy(symbolTable.symbols[rtn].struct_id, T->ptr[0]->type_id);
                    }
                    T->width += width;
                    T->num += 1;
                    symbolTable.symbols[rtn].isNull = 1;
                }
                else if (T0->ptr[0]->kind == Static_List)
                {
                    ext_var_list(T0->ptr[0]);
                    T->width += width * T0->ptr[0]->num;
                    T->num += T0->ptr[0]->num;
                }
                else if (T0->ptr[0]->kind == ASSIGNOP)
                {
                    T0->ptr[0]->ptr[0]->type = T0->ptr[0]->type;
                    if (lev == LEV + 1)
                    {
                        semantic_error(T->pos, "", "结构体成员定义时不能初始化");
                    }
                    if (T0->ptr[0]->ptr[0]->isShuzu == 1)
                    {
                        ext_var_list(T0->ptr[0]->ptr[0]);
                        rtn = T0->ptr[0]->ptr[0]->place;
                    }
                    else
                        rtn = fillSymbolTable(T0->ptr[0]->ptr[0]->type_id, newAlias(), LEV, T0->ptr[0]->type, 'V', T->offset + T->width); //此处偏移量未计算，暂时为0
                    if (rtn == -1 || rtn == -2)
                        semantic_error(T0->ptr[0]->ptr[0]->pos, T0->ptr[0]->ptr[0]->type_id, "变量重复定义");
                    else
                    {
                        T0->ptr[0]->place = rtn;
                        T0->ptr[0]->ptr[1]->offset = T->offset + T->width + width;
                        Exp(T0->ptr[0]->ptr[1]);
                        if (T0->ptr[0]->ptr[0]->type == FLOAT && T0->ptr[0]->ptr[1]->type == INTEGER)
                        {
                            goto b2;
                        }
                        if (T0->ptr[0]->ptr[0]->type != T0->ptr[0]->ptr[1]->type)
                        {
                            semantic_error(T->pos, "", "定义语句两边的表达式类型不匹配");
                            break;
                        }

                    b2:
                        symbolTable.symbols[rtn].isNull = 0;


                        opn1.kind = ID;
                        strcpy(opn1.id, symbolTable.symbols[T0->ptr[0]->ptr[1]->place].alias);
                        result.kind = ID;
                        strcpy(result.id, symbolTable.symbols[T0->ptr[0]->place].alias);
                        result.offset = T->offset + T->width;
                        opn1.offset = T0->ptr[0]->ptr[1]->offset;
                        T->code = merge(3, T->code, T0->ptr[0]->ptr[1]->code, genIR(ASSIGNOP, opn1, opn2, result));
                    }
                    T->width += width + T0->ptr[0]->ptr[1]->width;
                    T->num += T0->ptr[0]->ptr[1]->num;
                }
                strcpy(symbolTable.symbols[rtn].struct_id,T->ptr[0]->type_id);
                T0 = T0->ptr[1];
            }
            break;
        case STM_LIST:
            if (!T->ptr[0])
            {
                T->code = NULL;
                T->width = 0;
                break;
            }              //空语句序列
            if (T->ptr[1]) //2条以上语句连接，生成新标号作为第一条语句结束后到达的位置
                strcpy(T->ptr[0]->Snext, newLabel());
            else //语句序列仅有一条语句，S.next属性向下传递
                strcpy(T->ptr[0]->Snext, T->Snext);
            T->ptr[0]->offset = T->offset;
            strcpy(T->ptr[0]->Break, T->Break);
            semantic_Analysis(T->ptr[0]);
            T->code = T->ptr[0]->code;
            T->width = T->ptr[0]->width;
            if (T->ptr[1])
            { //2条以上语句连接,S.next属性向下传递
                strcpy(T->ptr[1]->Snext, T->Snext);
                T->ptr[1]->offset = T->offset; //顺序结构共享单元方式
                                               //                  T->ptr[1]->offset=T->offset+T->ptr[0]->width; //顺序结构顺序分配单元方式
                strcpy(T->ptr[1]->Break, T->Break);
                semantic_Analysis(T->ptr[1]);
                //序列中第1条为表达式语句，返回语句，复合语句时，第2条前不需要标号
                if (T->ptr[0]->kind == RETURN || T->ptr[0]->kind == EXP_STMT || T->ptr[0]->kind == COMP_STM)
                    T->code = merge(2, T->code, T->ptr[1]->code);
                else
                    T->code = merge(3, T->code, genLabel(T->ptr[0]->Snext), T->ptr[1]->code);
                if (T->ptr[1]->width > T->width)
                    T->width = T->ptr[1]->width; //顺序结构共享单元方式
                                                 //                        T->width+=T->ptr[1]->width;//顺序结构顺序分配单元方式
            }
            break;
        case IF_THEN:
            strcpy(T->ptr[0]->Etrue, newLabel()); //设置条件语句真假转移位置
            strcpy(T->ptr[0]->Efalse, T->Snext);
            T->ptr[0]->offset = T->ptr[1]->offset = T->offset;
            boolExp(T->ptr[0]);
            T->width = T->ptr[0]->width;
            strcpy(T->ptr[1]->Snext, T->Snext);
            strcpy(T->ptr[1]->Break, T->Break);
            semantic_Analysis(T->ptr[1]); //if子句
            if (T->width < T->ptr[1]->width)
                T->width = T->ptr[1]->width;
            T->code = merge(3, T->ptr[0]->code, genLabel(T->ptr[0]->Etrue), T->ptr[1]->code);
            break; //控制语句都还没有处理offset和width属性
        case IF_THEN_ELSE:
            strcpy(T->ptr[0]->Etrue, newLabel()); //设置条件语句真假转移位置
            strcpy(T->ptr[0]->Efalse, newLabel());
            T->ptr[0]->offset = T->ptr[1]->offset = T->ptr[2]->offset = T->offset;
            boolExp(T->ptr[0]); //条件，要单独按短路代码处理
            T->width = T->ptr[0]->width;
            strcpy(T->ptr[1]->Snext, T->Snext);
            strcpy(T->ptr[1]->Break, T->Break);
            semantic_Analysis(T->ptr[1]); //if子句
            if (T->width < T->ptr[1]->width)
                T->width = T->ptr[1]->width;
            strcpy(T->ptr[2]->Snext, T->Snext);
            strcpy(T->ptr[2]->Break, T->Break);
            semantic_Analysis(T->ptr[2]); //else子句
            if (T->width < T->ptr[2]->width)
                T->width = T->ptr[2]->width;
            T->code = merge(6, T->ptr[0]->code, genLabel(T->ptr[0]->Etrue), T->ptr[1]->code,
                            genGoto(T->Snext), genLabel(T->ptr[0]->Efalse), T->ptr[2]->code);
            break;
        case WHILE:
            strcpy(T->ptr[0]->Etrue, newLabel()); //子结点继承属性的计算
            strcpy(T->ptr[0]->Efalse, T->Snext);
            T->ptr[0]->offset = T->ptr[1]->offset = T->offset;
            boolExp(T->ptr[0]); //循环条件，要单独按短路代码处理
            T->width = T->ptr[0]->width;
            strcpy(T->ptr[1]->Snext, newLabel());
            strcpy(T->ptr[1]->Break, T->Snext);
            semantic_Analysis(T->ptr[1]); //循环体
            if (T->width < T->ptr[1]->width)
                T->width = T->ptr[1]->width;
            T->code = merge(5, genLabel(T->ptr[1]->Snext), T->ptr[0]->code,
                            genLabel(T->ptr[0]->Etrue), T->ptr[1]->code, genGoto(T->ptr[1]->Snext));
            break;
        case FOR:
            T0 = T->ptr[0];
            T0->ptr[0]->offset = T->offset;
            strcpy(T0->ptr[0]->Snext, newLabel());
            semantic_Analysis(T0->ptr[0]);
            T->width = T0->ptr[0]->width;
            strcpy(T0->ptr[1]->Etrue, newLabel()); //子结点继承属性的计算
            strcpy(T0->ptr[1]->Efalse, T->Snext);
            T0->ptr[0]->offset = T0->ptr[1]->offset = T0->ptr[2]->offset = T->ptr[1]->offset = T->offset;
            boolExp(T0->ptr[1]);
            T->width += T0->ptr[1]->width;
            strcpy(T0->ptr[2]->Snext, T0->ptr[0]->Snext);
            Exp(T0->ptr[2]);
            T->width += T0->ptr[2]->width;
            strcpy(T->ptr[1]->Snext, newLabel());
            strcpy(T->ptr[1]->Break, T->Snext);
            semantic_Analysis(T->ptr[1]);
            if (T->width < T->ptr[1]->width)
                T->width = T->ptr[1]->width;
            T->code = merge(8, T0->ptr[0]->code, genLabel(T0->ptr[0]->Snext), T0->ptr[1]->code,
                            genLabel(T0->ptr[1]->Etrue), T->ptr[1]->code, genLabel(T->ptr[1]->Snext), T0->ptr[2]->code,
                            genGoto(T0->ptr[2]->Snext));
            break;
        case EXP_STMT:
            T->ptr[0]->offset = T->offset;
            semantic_Analysis(T->ptr[0]);
            T->code = T->ptr[0]->code;
            T->width = T->ptr[0]->width;
            for (int i = 0; i < dpTable.index; i++)
            {
                dpTable.dps[i]->offset = T->ptr[0]->offset + T->width;
                struct node *p = getdp(dpTable.dps[i], dpTable.id[i], T->offset);
                T->code = merge(2, T->code, p->code);
                p->offset += p->width;
            }
            dpTable.index = 0;
            break;
        case RETURN:
            if (T->ptr[0])
            {
                T->ptr[0]->offset = T->offset;
                Exp(T->ptr[0]);
                num = symbolTable.index;
                do
                    num--;
                while (symbolTable.symbols[num].flag != 'F');
                if (T->ptr[0]->type != symbolTable.symbols[num].type)
                {
                    semantic_error(T->pos, "返回值类型错误", "");
                    T->width = 0;
                    T->code = NULL;
                    break;
                }
                if (T->ptr[0]->type == STRUCT)
                {
                    if (strcmp(T->ptr[0]->struct_id, symbolTable.symbols[num].struct_id) != 0)
                    {
                        semantic_error(T->pos, "返回值类型错误", "");
                        T->width = 0;
                        T->code = NULL;
                        break;
                    }
                }
                T->width = T->ptr[0]->width;
                result.kind = ID;
                strcpy(result.id, symbolTable.symbols[T->ptr[0]->place].alias);
                result.offset = symbolTable.symbols[T->ptr[0]->place].offset;
                T->code = merge(2, T->ptr[0]->code, genIR(RETURN, opn1, opn2, result));
            }
            else
            {
                T->width = 0;
                result.kind = 0;
                T->code = genIR(RETURN, opn1, opn2, result);
            }
            break;
        case ID:
        case INTEGER:
        case FLOAT:
        case ASSIGNOP:
        case AND:
        case OR:
        case RELOP:
        case PLUS:
        case MINUS:
        case STAR:
        case DIV:
        case NOT:
        case UMINUS:
        case FUHE:
        case PLUSPLUS:
        case PLUSPLUS2:
        case FUNC_CALL:
        case LIST_CALL:
        case STRUCT_CALL:
        case BREAK:
            Exp(T); //处理基本表达式
            break;
        }
    }
}

void semantic_Analysis0(struct node *T)
{
    symbolTable.index = 0; //符号表
    stringsTable.index = 0;
    dpTable.index = 0;
    fillSymbolTable("read", "", 0, INTEGER, 'F', 4);
    symbolTable.symbols[0].paramnum = 0; //read的形参个数
    fillSymbolTable("x", "", 1, INTEGER, 'P', 12);
    fillSymbolTable("write", "", 0, INTEGER, 'F', 4);
    symbolTable.symbols[2].paramnum = 1;
    symbol_scope_TX.TX[0] = 0; //外部变量在符号表中的起始序号为0
    symbol_scope_TX.top = 1;
    T->offset = 0; //外部变量在数据区的偏移量
    semantic_Analysis(T);
    prn_symbol();
    prn_string();
    prnIR(T->code);
    objectCode(T->code);
}
