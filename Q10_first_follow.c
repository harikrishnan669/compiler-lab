#include<stdio.h>
#include<string.h>
#include<ctype.h>

int n;
char a[10][10];
void first(char ch);
void follow(char ch);

int main(){
    int x;
    char ch;
    printf("Enter the no of prodction: ");
    scanf("%d",&n);

    printf("Enter the productions: ");
    for(int i=0;i<n;i++){
        scanf("%s",a[i]);
    }
    getchar();
    do{
        printf("Enter the element to find first and follow: ");
        scanf("%c",&ch);
        printf("First(%c)= {",ch);
        first(ch);
        printf("}");
        printf("\nFollow(%c)= {",ch);
        follow(ch);
        printf("}");
        printf("\nDo you want to continue?(0/1)");
        scanf("%d",&x);
        getchar();

    }while(x==1);
    return 0;
}

void first(char ch){
    if(islower(ch)){
        printf("%c, ",ch);
        return;
    }else{
        for(int i=0;i<n;i++){
            if(a[i][0]==ch){
                if(islower(a[i][2])){
                    printf("%c, ",a[i][2]);
                }else{
                    first(a[i][2]);
                }
            }
        }
    }
}

void follow(char ch){
    if(a[0][0]==ch){
        printf("$");
    }
    for(int i=0;i<n;i++){
        for(int j=2;j<strlen(a[i]);j++){
            if(a[i][j]==ch){
                if(a[i][j+1]!='\0'){
                    first(a[i][j+1]);
                }else if(a[i][0]!=ch){
                    follow(a[i][0]);
                }

            }
        }
    }
}
