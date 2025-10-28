#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define LEN 4
#define SIZE 50

struct
{
        char res[LEN];
        char op;
        char opnd1[LEN];
        char opnd2[LEN];
}tac[SIZE];

int num,i;
char instr[SIZE];

void three_address_code()
{
printf("Enter the number of instruction:");
scanf("%d",&num);
printf("Enter each instruction as Eg: s = a + b\n");
for(i=0;i<num;i++)
{
        scanf("%s = %s %c %s",tac[i].res,tac[i].opnd1,&tac[i].op,tac[i].opnd2);
}
}

char *get_instr(char op)
{
char mnemonics[][LEN]={"MUL","ADD","","SUB","","DIV"};
strcpy(instr,mnemonics[op-'*']);
return instr;
}


void generate_three_addresscode()
{
for(i=0;i<num;i++)
{
        printf("MOV AX,%s\n%s AX,%s\nMOV %s,AX\n",tac[i].opnd1,get_instr(tac[i].op),tac[i].opnd2,tac[i].res);
}
}

int main()
{
three_address_code();
printf("Equivalent assembly code is:\n");
generate_three_addresscode();
}
