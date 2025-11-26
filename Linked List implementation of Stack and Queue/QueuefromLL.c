#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;
void enqueue();
void dequeue();
void display();
void main()
{
    int choice;
    while (choice != 4)
    {
        printf("\n\n1.insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");  
        printf("Enter your choice:\n");  
        scanf("%d",&choice);
        switch(choice)  
        {
                case 1: enqueue();
                        break;
                case 2: dequeue();
                        break;
                case 3: display();
                        break;
                case 4: exit(0);
                default : printf("\nEnter valid choice:\n");  
        }
    }
}
void enqueue() // similar to lastinsert() of singly linked list
{
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("OVERFLOW!!\n");
        return;
    }
    else
    {
        printf("Enter value to be inserted:\n");
        scanf("%d", &item);
        ptr->data = item;
        if (front == NULL)
        {
            front = ptr;
            rear = ptr;
            front->next = NULL;
            rear->next = NULL;
            printf("\nItem enqueued");
        }
        else
        {
            rear->next = ptr;
            ptr->next = NULL;
            rear = ptr;
            printf("Item enqueued");
        }
    }
}
void dequeue() // similar to begin_delete() of singly linked list
{
    struct node *ptr;
    if (front == NULL)
    {
        printf("Empty Queue. UNDERFLOW ERROR!!\n");
        return;
    }
    else if (front->next == NULL)
    {
        ptr = front;
        printf("\nItem dequeued %d ", ptr->data);
        front = rear = NULL;
        free(ptr);
        printf("Item dequeued !\n");
        return;
    }
    else
    {
        ptr = front;
        printf("Item dequeued %d", ptr->data);
        front = ptr->next;
        free(ptr);
        printf("Item dequeued !\n");
        return;
    }
}
void display()
{
    struct node *ptr;
    ptr = front;
    if (front == NULL)
        printf("\nEmpty queue\n");
    else
    {
        printf("Elements of the queue:\n");
        while (ptr != NULL)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}
