#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
// #include<ctype.h>
char istack[30];
int tos=-1;
float stack[30];
int top=-1;
void ipush(char s)
{
    istack[++tos]=s;
}
char ipop()
{
    return istack[tos--];
}
int precd(char s)
{
    switch(s)
    {
        case '^': return 4;
        case '*':
        case '/':
        case '%': return 3;
        case '+':
        case '-': return 2;
        case '(':
        case ')': return 1;
    }
    return 0;
}
void convertip(char infix[30],char postfix[30])
{
    int i,j=0,n;
    char symbol;
    ipush('(');
    n=strlen(infix);
    infix[n]=')';
    n=n+1;
    for(i=0;i<n;i++)
    {
        symbol=infix[i];
        switch(symbol)
        {
            case '(': ipush('(');
                      break;
            case ')': while(istack[tos]!='(')
                            postfix[j++]=ipop();
                      ipop();
                      break;
            case '^':
            case '*':
            case '/':
            case '%':
            case '+':
            case '-': while(precd(istack[tos])>=precd(symbol))
                            postfix[j++]=ipop();
                      ipush(symbol);
                      break;
            default: postfix[j++]=symbol;
                      
        }
    }
    postfix[j]='\0';
}
void push(float ele)
{
    stack[++top]=ele;
}
float pop()
{
    return stack[top--];
}
void evaluate(char postfix[30])
{
    int i;
    char sym;
    float op1,op2,result,x;
    for(i=0;i<strlen(postfix);i++)
    {
        sym=postfix[i];
        if(isalpha(sym))
        {
            printf("Enter the value for %c\t",sym);
            scanf("%f",&x);
            push(x);
        }
        else
        {
            op2=pop();
            op1=pop();
            switch(sym)
            {
                case '+': push(op1+op2);
                          break;
                case '-': push(op1-op2);
                          break;
                case '*': push(op1*op2);
                          break;
                case '/': push(op1/op2);
                          break;
                case '%': push((int)op1%(int)op2);
                          break;
                case '^': push(pow(op1,op2));
                          break;
                default: printf("Invalid postfix expression");
                         exit(0);
            }
        }
    }
    result=pop();
    printf("The result is %f",result);
}
int main()
{
    char infix[30],postfix[30];
    printf("Enter the infix expression:");
    gets(infix);
    convertip(infix,postfix);
    printf("\nPostfix expression is %s\n",postfix);
    evaluate(postfix);
    return 0;
}
