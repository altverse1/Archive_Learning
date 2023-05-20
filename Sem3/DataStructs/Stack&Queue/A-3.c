//Check Palindrome Using Stack

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10

typedef struct STACK
{
    char a[MAX];
    int top;
}stack;

void push(stack *s, char a)
{
    s->top++;
    s->a[s->top] = a;
}

char pop(stack *s)
{
    char temp;
    temp = s->a[s->top];
    s->top--;
    return temp;
}

bool ispalindrome(stack *s,char str[10])
{
    int i;
    for(i=0;i<(strlen(str)/2);i++)
    {
        push(s,str[i]);
    }
    if(strlen(str)%2!=0)
        i++;

    while(str[i]!='\0')
    {
        char a = pop(s);
        if(a!=str[i]){
            printf("The String is not palindrome\n");
            return false;
        }
        i++;
    }
    return true;
}

int main()
{
    stack s1;
    s1.top=-1;
    char s[10];
    printf("Enter your stirng: ");
    scanf("%s",s);
    printf("\n");
    if(ispalindrome(&s1,s))
        printf("It is palindrome\n");
    return 0;
}