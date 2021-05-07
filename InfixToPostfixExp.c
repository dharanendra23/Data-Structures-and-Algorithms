#include <stdio.h>
#include <stdlib.h>

char stk[100];
int top = -1;

void push(char ch)
{
    stk[++top] = ch;
}

char pop()
{
    if (top == -1)
        return -1;
    else
        return stk[top--];
}

int priority(char ch)
{
    if (ch == '(')
        return 0;
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
}

void PostFix(char str[])
{
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            printf("%c", str[i]);
        }
        else if (str[i] != ')')
        {
            while (top > -1 && str[i] != '(' && priority(stk[top]) >= priority(str[i]))
                printf("%c", pop());

            push(str[i]);
        }
        else if (str[i] == ')')
        {
            char ch;
            while ((ch = pop()) != '(')
                printf("%c", ch);
        }
        i++;
    }
    while (top > -1)
    {
        char ch;
        if ((ch = pop()) != '(')
            printf("%c", ch);
    }
}

int main()
{
    char str[100];
    printf("Enter infix expression : \n");
    scanf("%s", str);
    PostFix(str);
    return 0;
}
