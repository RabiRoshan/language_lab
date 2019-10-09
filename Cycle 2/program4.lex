%{

// Rabi Roshan
// S7 CSB
// 12170054

// TO RUN:
// lex program3.lex
// gcc lex.yy.c
// ./a.out

#include<stdio.h>
int statements=0, identifiers=0, assignment_o=0, relational_o=0, keywords=0, integers=0;
%}

letter [A-Za-z]
digit [0-9]

%%
[\;] { statements++;}
if|else|while|switch|for|char|false|true {keywords++;--identifiers;}
int {keywords++;}
{letter}({letter}|{digit})* identifiers++;
%%





main(void)
{
yyin= fopen("myprogram.c","r");
yylex();
printf(" This Number of ...");
printf("\n\t%d C statements", statements);
printf("\n\t%d identifiers",identifiers);
printf("\n\t%d assignment operators", assignment_o);
printf("\n\t%d relational operators",relational_o);
printf("\n\t%d keywords", keywords);
printf("\n\t%d integers",integers);
}
 
int yywrap()
{
return(1);
}
