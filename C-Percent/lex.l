%{
#include "parser.tab.h"
#include "string.h"
#include "def.h"

#define YYSTYPE YYLVAL
#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno;\
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn + yyleng - 1; yycolumn += yyleng;

int yycolumn = 1;	// 每一行的字符数
int StringId = 1;
int SingleID = 1;
int DoubleID = 1;

typedef union {
	int type_int;
	float type_float;
	char *type_id;
} YYLVAL;
%}


%option yylineno


pointer [a-zA-Z][a-zA-Z0-9]*@
id     [a-zA-Z][a-zA-Z0-9]*\??
int    0|[1-9][0-9]*
float  (0|[1-9][0-9]*)\.[0-9]*f?
AR    @|&

%%
\'.\'       {strcpy(yylval.type_id, yytext); return CHAR;}
\".+\"      {yytext[yyleng] = '\0'; yyleng = yyleng + 1; strcpy(yylval.type_id, yytext); return STRING;}
{int}       {yylval.type_int = atoi(yytext); return INTEGER;}
{float}     {yylval.type_float = atof(yytext); return FLOAT;}
{AR}         {return ADDRESS;}
"return"    {return RETURN;}
"if"        {return IF;}
"else"      {return ELSE;}
"while"     {return WHILE;}
"for"       {return FOR;}
"break"     {return BREAK;}
"struct"    {return STRUCT;}
"#include"  {return DF;}
"null"      {return MyNULL;}
{pointer}   {strcpy(yylval.type_id, yytext); return TYPE;}
"int"       {strcpy(yylval.type_id, yytext); return TYPE;}
"float"     {strcpy(yylval.type_id, yytext); return TYPE;}
"char"      {strcpy(yylval.type_id, yytext); return TYPE;}
"string"    {strcpy(yylval.type_id, yytext); return TYPE;}
[<][a-zA-Z]+\.[h][>] {strcpy(yylval.type_id, yytext); return LIBRARY;}
{id}        {if(SingleID){strcpy(yylval.type_id, yytext); return ID;}}
";"			{return SEMI;}
","			{return COMMA;}
">"|"<"|">="|"<="|"=="|"!=" {strcpy(yylval.type_id, yytext); return RELOP;}
"++"|"--"   {strcpy(yylval.type_id, yytext); return PLUSPLUS;}
"+="|"-="|"*="|"/="   {strcpy(yylval.type_id, yytext); return FUHE;}
"//"        {char c = input(); while(c != '\n'){c = input();}}
"/*"        {char c = input(); loop: while(c != '*'){c = input();} c = input(); if(c != '/') goto loop;}
"="			{return ASSIGNOP;}
"+"			{return PLUS;}
"-"			{return MINUS;}
"*"			{return STAR;}
"/"			{return DIV;}
"&&"        {return AND;}
"||"        {return OR;}
"!"			{return NOT;}
"("			{return LP;}
")"			{return RP;}
"["			{return LB;}
"]"			{return RB;}
"{"			{return LC;}
"}"			{return RC;} 
[\.]        {return DOT;}
[\"]        {return DQ;}
[\']        {return SQ;}
[\n]        {yycolumn = 1;}
[ \r\t]     {}   
.			{printf("UnKnown Error: \"%s\"\n\t at Line %d\n", yytext, yylineno);}
%%


int yywrap() {
	return 1;
}

