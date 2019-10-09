%{
// Rabi Roshan
// CSB S7
// 12170054

#include<stdio.h>
#include<string.h>

int i = 0;
%}

%%
[0-1]*(000)[0-1]*	{i = 1;}
.   {i = 0;}

"\n" {if(i==1)printf("\nvalid\n"); if(i==0)printf("\ninvalid\n"); i=0;}
%%

int main(){
    yylex();
    return 1;
}

int yywrap(){
    return 1;
}

