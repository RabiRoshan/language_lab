%{
// Rabi Roshan
// CSB S7
// 12170054

#include<stdio.h>
#include<string.h>

int i = 0;
%}

%%
(aa)([a+b])*(bb)	{i = 1;}
.   {i = 0;}

"\n" {if(i==1)printf("valid\n"); if(i==0)printf("invalid\n"); i=0;}
%%

int main(){
    yylex();
    return 1;
}

int yywrap(){
    return 1;
}
