#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 20

typedef struct {
    char op;     
    char a[10];  
    char b[10];  
    char r[10];  
} Quad;

Quad q[MAX];
int n;

int isnum(char s[]) {
    for(int i=0; s[i]!='\0'; i++)
        if(!isdigit(s[i])) return 0;
    return 1;
}

int eval(char a[], char b[], char op) {
    int x = atoi(a), y = atoi(b);
    switch(op) {
        case '+': return x + y;
        case '-': return x - y;
        case '*': return x * y;
        case '/': return y != 0 ? x / y : 0;
    }
    return 0;
}


void constantFold() {
    for(int i=0; i<n; i++) {
        if(isnum(q[i].a) && isnum(q[i].b)) {
            int val = eval(q[i].a, q[i].b, q[i].op);
            q[i].op = '=';
            sprintf(q[i].a, "%d", val);
            strcpy(q[i].b, "-");
        }
    }
}

void constantProp() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(q[j].op=='=' && strcmp(q[i].a,q[j].r)==0)
                strcpy(q[i].a, q[j].a);
            if(q[j].op=='=' && strcmp(q[i].b,q[j].r)==0)
                strcpy(q[i].b, q[j].a);
        }
    }
}

int main() {
    printf("Enter number of instructions: ");
    scanf("%d", &n);

    printf("Enter instructions (op a b result):\n");
    for(int i=0; i<n; i++)
        scanf(" %c %s %s %s", &q[i].op, q[i].a, q[i].b, q[i].r);

    constantFold();
    constantProp();
    constantFold();

    printf("\nOptimized code:\n");
    printf("OP\tARG1\tARG2\tRES\n");
    for(int i=0;i<n;i++)
        printf("%c\t%s\t%s\t%s\n", q[i].op, q[i].a, q[i].b, q[i].r);

    return 0;
}
