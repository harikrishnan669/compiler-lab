#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX 50

char operands[MAX][10];
char operators[MAX];
int topOpnd = -1, topOp = -1;

int precedence(char c) {
        if(c == '+' || c == '-')
                return 1;
        if(c == '*' || c == '/')
                return 2;
        if(c == '=')
                return -1;
        return 0;
}

void generateICG(char exp[]) {
        int i = 0, t = 1;
        char temp[10];

        while(exp[i] != '\0') {
                if(isalnum(exp[i])) {
                        int j = 0;
                        while(isalnum(exp[i])) temp[j++] = exp[i++];
                        temp[j] = '\0';
                        strcpy(operands[++topOpnd],temp);
                }
                else {
                        while(topOp >= 0 && precedence(operators[topOp]) >= precedence(exp[i])) {
                                char op = operators[topOp--];
                                if(op == '=') {
                                        printf("%s = %s\n",operands[topOpnd-1],operands[topOpnd]);
                                        topOpnd -= 2;
                                }
                                else {
                                        printf("t%d = %s %c %s\n",t,operands[topOpnd-1],op,operands[topOpnd]);
                                        sprintf(operands[--topOpnd],"t%d",t++);
                                }
                        }
                        operators[++topOp] = exp[i++];
                }
        }
        while(topOp >= 0) {
                char op = operators[topOp--];
                if(op == '=')
                        printf("%s = %s\n",operands[topOpnd-1],operands[topOpnd]);
                else {
                        printf("t%d = %s %c %s\n",t,operands[topOpnd-1],op,operands[topOpnd]);
                        sprintf(operands[--topOpnd],"t%d",t++);
                }
        }
}

int main() {
        char exp[MAX];
        printf("Enter infix expression without space: ");
        scanf("%[^\n]",exp);
        generateICG(exp);
        return 0;
}
