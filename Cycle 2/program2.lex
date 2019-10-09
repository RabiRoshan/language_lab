%{
// Rabi Roshan
// CSB S7
// 12170054

#include<stdio.h>
#include<string.h>

int i = 0;
%}

%%
(0+1)*(000)(0+1)*	{i = 1;}

"\n" {if(i==1)printf("valid\n"); if(i==0)printf("invalid\n"); i=0;}
%%

int yywrap(void){}

