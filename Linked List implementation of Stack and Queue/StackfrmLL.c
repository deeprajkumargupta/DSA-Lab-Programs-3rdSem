#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;
void push();
void pop();
void display();
void main()
{
    int choice = 0;
    printf("\n*********Stack operations using singly linked list*********\n");
    while (choice != 4)
    {
        printf("\n\n1.Push\n2.Pop\n3.Show\n4.Exit");
        printf("\nEnter your choice \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Please Enter valid choice ");
        }
    }
}
void push() // similar to begin_insert() of singly linked list
{
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
        printf("\nOVERFLOW ERROR");
    else
    {
        printf("\nEnter the value of the item to be inserted: \n");
        scanf("%d", &item);
        ptr->data = item;
        ptr->next = top;
        top = ptr;
        printf("\nItem Pushed!!!");
    }
}
void pop() // similar to begin_delete() of singly linked list
{
    struct node *ptr;
    if (top == NULL)
        printf("\nUNDERFLOW ERROR!!! Stack is empty\n");
    else
    {
        ptr = top;
        printf("\n Item popped %d", ptr->data);
        top = ptr->next;
        free(ptr);
    }
}
void display()
{
    struct node *ptr;
    ptr = top;
    if (ptr == NULL)
        printf("Stack is empty\n");
    else
    {
        printf("\nPrinting Stack elements \n");
        while (ptr != NULL)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
    }
}
