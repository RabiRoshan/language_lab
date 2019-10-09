%{ 
// Rabi Roshan
// S7 CSB
// 12170054

// TO RUN:
// lex program3.lex
// gcc lex.yy.c
// ./a.out

// INFO: Not a perfect solution! ✌🏻😉

#include<stdio.h> 
#include<string.h> 
char line[100]; 
%} 

%% 
['\n'] { fprintf(yyout,"%s\n",line);} 
([^a-zA-Z ]*)	 { strcpy(line,yytext); } 
%% 

int yywrap() 
{ 
	return 1; 
} 

int main() 
{ 
	extern FILE *yyin, *yyout; 
	yyin=fopen("input.txt","r"); 
	yyout=fopen("output.txt","w"); 
	yylex(); 
} 
