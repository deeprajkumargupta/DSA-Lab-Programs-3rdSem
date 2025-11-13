#include<stdio.h>
#include<stdlib.h>
int max,top=-1,ele,*stack;
void push(int ele)
{
    if(top==max-1)
    {
        printf("Stack Overflow, doubling the size of stack\n");
        max=max*2;
        stack=realloc(stack,max*sizeof(int));
    }
    stack[++top]=ele;
    printf("Pushed: %d",ele);
}
int pop()
{
    if(top==-1)
    {
        printf("Stack Underflow(The stack is empty)");
        return -999;
    }
    ele=stack[top];
    top--;
    return ele;
}
void display()
{
    int i;
    if(top==-1)
    {
        printf("Stack is empty");
    }
    else{
        printf("The elements in the stack are: ");
        for(i=top;i>-1;i--)
            printf("%d\t",stack[i]);
    }
}
int main()
{
    int choice,i;
    printf("Enter the max size of stack: ");
    scanf("%d",&max);
    stack=(int*)malloc(max*sizeof(int));
    while(1)
    {
        printf("\n\nChoose an option\n1. Push\n2. Pop\n3. Display\n4.Exit\nEnter your Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the element to push: ");
                    scanf("%d",&ele);
                    push(ele);
                    break;
            case 2: ele=pop();
                    if(ele!=-999)
                    {
                        printf("Popped %d",ele);
                    }
                    break;
            case 3: display();
                    break;
            case 4: printf("Exiting the Program...");
                    free(stack);
                    exit(0);
            default: printf("Invalid Choice");
        }
    }
    return 0;
}