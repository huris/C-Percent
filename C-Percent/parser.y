%error-verbose
%locations
%{
#include "stdio.h"
#include "math.h"
#include "string.h"
#include "def.h"

extern int yylineno;
extern char *yytext;
extern FILE *yyin;
void yyerror(const char* fmt, ...);
void display(struct node *, int);
%}


%union {
	int    type_int;
	float  type_float;
	char   type_id[32];
	struct node *ptr;
};
	
// %type 定义非终结符的语义值类型
%type <ptr> Program ExtDefList ListNum ListDec ExtDef Specifier
            StructSpecifier Includes ForExp ForNull ExtDecList
            FuncDec CompSt VarList VarDec ParamDec Stmt StmList
            DefList Def DecList Dec Exp Args AssReturn
            
// 指定INT的语义值是type_int, 由词法分析得到的数值
%token <type_int> INTEGER

// 指定ID,RELOP...的语义值是type_id, 由词法分析得到的标识符字符串
%token <type_id> TYPE POINTER MyNULL ID RELOP LIBRARY CHAR PLUSPLUS PLUSPLUS2 FUHE STRING

// 指定FLOAT的语义值是type_float, 由词法分析得到的浮点数
%token <type_float> FLOAT

// 用bison对该文件编译时, 带参数-d, 生成的parser.tab.h中给这些单词进行编码, 可在lex.l中包含parser.tab.h使用这些单词种类码
%token LP RP LB RB LC RC SEMI COMMA DOT 
%token PLUS MINUS STAR DIV ASSIGNOP AND OR NOT IF ELSE WHILE RETURN FOR STRUCT BREAK 
%token DF DQ SQ  // DF:#include

// 左结合
%left ASSIGNOP
%left FUHE
%left OR
%left AND
%left RELOP
%left PLUS MINUS 
%left STAR DIV
%left ADDRESS

// 右结合 
%right UMINUS NOT PLUSPLUS PLUSPLUS2

// 不可结合
%nonassoc LOWER_THEN_ELSE  // 优先级比ELSE更低
%nonassoc ELSE


%%
Program: ExtDefList {display($1, 0); semantic_Analysis0($1);}     /*构造语法树,语义分析*/
    ;
// 库函数
ExtDefList: {$$ = NULL;}
            |ExtDef ExtDefList {$$ = mknode(EXT_DEF_LIST, $1, $2, NULL, yylineno);}
    ;     
// 表示一个全局变量，结构体或函数
ExtDef: Specifier ExtDecList SEMI {$$ = mknode(EXT_VAR_DEF, $1, $2, NULL, yylineno);} 
      | StructSpecifier SEMI {$$ = $1;}  
      | Specifier FuncDec CompSt {$$ = mknode(FUNC_DEF, $1, $2, $3, yylineno);} 
      | Specifier FuncDec ASSIGNOP AssReturn {$$ = mknode(FUNC_DEF, $1, $2, $4, yylineno);} 
      | Includes {$$ = $1;}	
    ;
AssReturn: Exp SEMI {$$ = mknode(RETURN, $1, NULL, NULL, yylineno);}
    ;

Includes: DF LIBRARY {$$ = mknode(Includes, NULL, NULL, NULL, yylineno); strcpy($$->type_id, $2);} 
	;
ExtDecList: VarDec {$$ = $1;}  /*每一个EXT_DEC_LIST的结点, 其第一棵子树对应一个变量名(ID类型的结点), 第二棵子树对应剩下的外部变量名*/
          | VarDec COMMA ExtDecList {$$ = mknode(EXT_DEC_LIST, $1, $3, NULL, yylineno);}
    ;
// 结构体或类型符
Specifier: TYPE {$$ = mknode(TYPE, NULL, NULL, NULL, yylineno); strcpy($$ -> type_id, $1); 
            if(strcmp($$ -> type_id, "int") == 0) $$ -> type = INTEGER;
			else if(strcmp($$ -> type_id, "float") == 0)$$ -> type = FLOAT;
			else if(strcmp($$ -> type_id, "char") == 0)$$ -> type = CHAR;
            else if(strcmp($$ -> type_id, "string") == 0) $$ -> type = STRING;
			else $$ -> type = POINTER;} 
         | STRUCT ID {$$ = mknode(StructSpecifier, NULL, NULL, NULL, yylineno); strcpy($$ -> type_id, $2);}
    ;
// 结构体
StructSpecifier: STRUCT ID LC DefList RC {$$ = mknode(StructSpecifier, $4, NULL, NULL, yylineno); strcpy($$ -> type_id, $2); $$ -> isSTRUCT = 1;}
	;
// 变量定义，数组
VarDec: ID {$$ = mknode(ID, NULL, NULL, NULL, yylineno); strcpy($$ -> type_id, $1);} 
	  | VarDec LB ListNum RB {$$ = mknode(Static_List, $1, $3, NULL, yylineno); strcpy($$ -> type_id, $1 -> type_id); $$ -> isShuzu = 1;}
    ;
ListDec: ID {$$ = mknode(ID, NULL, NULL, NULL, yylineno); strcpy($$ -> type_id, $1);} 
	   | ListDec LB Exp RB {$$ = mknode(Static_List, $1, $3, NULL, yylineno); strcpy($$ -> type_id, $1 -> type_id); $$ -> isShuzu = 1;}
    ;
ListNum: INTEGER {$$ = mknode(INTEGER, NULL, NULL, NULL, yylineno); $$ -> type_int = $1; $$ -> type = INTEGER;}
    ;
// 函数头定义, 函数名存放在$$ -> type_id
FuncDec: ID LP VarList RP {$$ = mknode(FUNC_DEC, $3, NULL, NULL, yylineno); strcpy($$ -> type_id, $1);}
       | ID LP RP {$$ = mknode(FUNC_DEC, NULL, NULL, NULL, yylineno); strcpy($$ -> type_id, $1);}
	;
// 参数定义
VarList: ParamDec COMMA VarList {$$ = mknode(PARAM_LIST, $1, $3, NULL, yylineno);}
       | ParamDec {$$ = mknode(PARAM_LIST, $1, NULL, NULL, yylineno); strcpy($$ -> type_id, $1);}
	;  
ParamDec: Specifier VarDec {$$ = mknode(PARAM_DEC, $1, $2, NULL, yylineno);}
    ;
// CompSt: 花括号内的语句块, DefList: 一连串变量定义, StmList: 语句
CompSt: LC DefList StmList RC {$$ = mknode(COMP_STM, $2, $3, NULL, yylineno);}
    ;
StmList: {$$ = NULL;}
       | Stmt StmList {$$ = mknode(STM_LIST, $1, $2, NULL, yylineno);}
	;   
Stmt: Exp SEMI {$$ = mknode(EXP_STMT, $1, NULL, NULL, yylineno);}
      | CompSt {$$ = $1;}  //复合语句结点直接作为语句结点，不再生成新的结点
      | RETURN Exp SEMI {$$ = mknode(RETURN, $2, NULL, NULL, yylineno);}
      | IF Exp Stmt %prec LOWER_THEN_ELSE {$$ = mknode(IF_THEN, $2, $3, NULL, yylineno);}
      | IF Exp Stmt ELSE Stmt {$$ = mknode(IF_THEN_ELSE, $2, $3, $5, yylineno);}
      | WHILE Exp Stmt {$$ = mknode(WHILE, $2, $3, NULL, yylineno);}
	  | FOR ForExp Stmt {$$ = mknode(FOR, $2, $3, NULL, yylineno);}
      | BREAK SEMI {$$ = mknode(BREAK, NULL, NULL, NULL, yylineno);}
	  | error SEMI {$$ = NULL;}
    ;
ForExp: ForNull SEMI ForNull SEMI ForNull {$$ = mknode(ForExp, $1, $3, $5, yylineno);}
      | Def ForNull SEMI ForNull {$$ = mknode(ForExp, $1, $2, $4, yylineno);}
ForNull: {$$ = NULL;} 
       | Exp{$$ = $1;}
DefList: {$$ = NULL;}
       | Def DefList {$$ = mknode(DEF_LIST, $1, $2, NULL, yylineno);}
    ;
Def: Specifier DecList SEMI {$$ = mknode(VAR_DEF, $1, $2, NULL, yylineno);}
    ;
DecList: Dec {$$ = mknode(DEC_LIST, $1, NULL, NULL, yylineno);}
       | Dec COMMA DecList {$$ = mknode(DEC_LIST, $1, $3, NULL, yylineno);}
    ;
Dec: VarDec {$$ = $1;}
   | VarDec ASSIGNOP Exp {$$ = mknode(ASSIGNOP, $1, $3, NULL, yylineno); strcpy($$ -> type_id, "ASSIGNOP");}
   | VarDec FUHE Exp {$$ = mknode(FUHE, $1, $3, NULL, yylineno); strcpy($$ -> type_id, $2);}
    ;
Exp: Exp ASSIGNOP Exp {$$ = mknode(ASSIGNOP, $1, $3, NULL, yylineno); strcpy($$ -> type_id, "ASSIGNOP");} // $$结点type_id空置未用, 正好存放运算符
   | Exp AND Exp {$$ = mknode(AND, $1, $3, NULL, yylineno); strcpy($$ -> type_id, "AND");}
   | Exp OR Exp {$$ = mknode(OR, $1, $3, NULL, yylineno); strcpy($$ -> type_id, "OR");}
   | Exp RELOP Exp {$$ = mknode(RELOP, $1, $3, NULL, yylineno); strcpy($$ -> type_id, $2);}  // 词法分析关系运算符号自身值保存在$2中
   | Exp PLUS Exp {$$ = mknode(PLUS, $1, $3, NULL, yylineno); strcpy($$ -> type_id, "PLUS");}
   | Exp MINUS Exp {$$ = mknode(MINUS, $1, $3, NULL, yylineno); strcpy($$ -> type_id, "MINUS");}
   | Exp STAR Exp {$$ = mknode(STAR, $1,$3, NULL, yylineno); strcpy($$ -> type_id, "STAR");}
   | Exp DIV Exp {$$ = mknode(DIV, $1, $3, NULL, yylineno); strcpy($$ -> type_id, "DIV");}
   | Exp FUHE Exp {$$ = mknode(FUHE ,$1, $3, NULL, yylineno); strcpy($$ -> type_id, $2);}
   | LP Exp RP {$$ = $2;}
   | MINUS Exp %prec UMINUS {$$ = mknode(UMINUS, $2, NULL, NULL, yylineno); strcpy($$ -> type_id, "UMINUS");}
   | NOT Exp {$$ = mknode(NOT, $2, NULL, NULL, yylineno); strcpy($$ -> type_id, "NOT");}
   | PLUSPLUS Exp {$$ = mknode(PLUSPLUS, $2, NULL, NULL, yylineno); strcpy($$ -> type_id, $1);}
   | Exp PLUSPLUS {$$ = mknode(PLUSPLUS2, $1, NULL, NULL, yylineno); strcpy($$ -> type_id, $2);}
   | ListDec LB Exp RB {$$ = mknode(LIST_CALL, $1, $3, NULL, yylineno); if($1 -> kind == ID) strcpy($$ -> type_id, $1); else strcpy($$ -> type_id, $1 -> type_id); $$ -> isShuzu = 1;}
   | ADDRESS ID {$$ = mknode(POINTER, $2, NULL, NULL, yylineno);strcpy($$ -> type_id, $2);}
   | ID LP Args RP {$$ = mknode(FUNC_CALL, $3, NULL, NULL, yylineno); strcpy($$ -> type_id, $1);}
   | ID LP RP {$$ = mknode(FUNC_CALL, NULL, NULL, NULL, yylineno); strcpy($$ -> type_id, $1);}
   | ID DOT ListDec {$$ = mknode(STRUCT_CALL, $3, NULL, NULL, yylineno); strcpy($$ -> type_id, $1);}
   | ID {$$ = mknode(ID, NULL, NULL, NULL, yylineno); strcpy($$ -> type_id, $1);}
   | INTEGER {$$ = mknode(INTEGER, NULL, NULL, NULL, yylineno); $$ -> type_int = $1; $$ -> type = INTEGER;}
   | FLOAT {$$ = mknode(FLOAT, NULL, NULL, NULL, yylineno); $$ -> type_float = $1; $$ -> type = FLOAT;}
   | CHAR {$$ = mknode(CHAR, NULL, NULL, NULL, yylineno); strcpy($$ -> type_id, $1); $$ -> type = CHAR;}
   | STRING {$$ = mknode(STRING, NULL, NULL, NULL, yylineno); strcpy($$ -> type_id, $1); $$ -> type = STRING; $$ -> num = strlen($1);}
Args: Exp COMMA Args {$$ = mknode(ARGS, $1, $3, NULL, yylineno);}
    | Exp {$$ = mknode(ARGS, $1, NULL, NULL, yylineno);}
    ;
%%


#include<stdarg.h>

void yyerror(const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);

    fprintf(stderr, "Grammar Error at Line %d Column %d: ", yylloc.first_line, yylloc.first_column);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, ".\n");
}

int main(int argc, char *argv[]) {
	if (!(yyin = fopen(argv[1], "r"))) return 1;
	
    yylineno = 1;
	yyparse();

	return 0;
}