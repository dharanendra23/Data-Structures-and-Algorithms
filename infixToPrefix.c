#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 100

char stk[MAX];
int top = -1;

void push(char str){
    if(top == MAX){
        printf("Stack is overflow!\n");
    }
    else{
        stk[++top] = str;
    }
}

char pop(){
    if(top == -1){
        printf("Stack is Underflow!\n");
    }else{
        return stk[top--];
    }
}

void reverseStr(char *str){
    char str1[MAX];
    strcpy(str1, str);
    int  i = 0, j = strlen(str);
    while(str1[i] != '\0'){
        if(str1[i] == '('){
            str[--j] = ')';
            i++;
        }else if(str1[i] == ')'){
             str[--j] = '(';
             i++;
        }else{
            str[--j] = str1[i++]; 
        }
    }
}

int precedence(char str){
    if(str == '('){
        return 0;
    }else if(str == '+' || str == '-'){
        return 1;
    }else if(str == '*' || str == '/'){
        return 2;
    }
}

void infixToPrefix(char str[]){
    reverseStr(str);
    char ans[MAX];
    int i = 0, j = 0;
    while(str[i] != '\0'){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            ans[j++] = str[i];
        }else if(str[i] != ')'){
            while(top > -1 && str[i] != '(' && precedence(stk[top]) >= precedence(str[i]))
                ans[j++] = pop();

            push(str[i]);
        }else if(str[i] == ')'){
            char ch;
            while((ch = pop()) != '('){
                ans[j++] = ch;
            }
        }

        i++;
    }

    while(top > -1){
        char ch;
        if((ch = pop()) != '(')
            ans[j++] = ch;
    }
    ans[j] = '\0';
    reverseStr(ans);
    printf("%s", ans);
}

int main(){
    char str[MAX];
    printf("Enter the valid infix expression : ");
    scanf("%s", str);

    infixToPrefix(str);

    return 0;
}
