%{
#include<stdio.h>
%}

%%
abc     {printf("ABC");}
.|\n {ECHO;}
%%

int main()
{
        yylex();
        return 0;
}
int yywrap(){
        return 1;
}
