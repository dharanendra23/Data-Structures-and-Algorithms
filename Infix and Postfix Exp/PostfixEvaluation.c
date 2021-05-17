#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int stack[100];
int top = -1;

void push(int ele){
    if(top > 100){
        printf("Stack is Overflow!\n");
    }
    stack[++top] = ele;
}

int pop(){
    if(top == -1){
        printf("Stack is underflow!\n");
    }
    return stack[top--];
}

void postfixEval(char str[]){
    int i = 0;
    while(str[i] != '\0'){
        if(isdigit(str[i])){
            push(str[i]-'0');
        }else{
            int operand1 = pop(), operand2 = pop(), operation = 0;
            switch(str[i]){
                case '+' : operation = operand1 + operand2;
                           break;

                case '-' : operation = operand2 - operand1;
                           break;

                case '*' : operation = operand2 * operand1;
                           break;

                case '/' : operation = operand2 / operand1;
                           break;                                 
            }

            push(operation);
        }
        i++;
    }
    printf("%d", pop());
}

int main(){
    char str[100];
    printf("Enter the valid postfix expression : ");
    scanf("%s", str);

    postfixEval(str);

    return 0;
}
