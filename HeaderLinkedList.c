#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

void begin_insert();
void begin_delete();
void display();
void search();
void main()
{
	head = (struct node *)malloc(sizeof(struct node));
	head->data = 0;
	head->next = NULL;
	
    int choice;
    while (1)
    {
        printf("\n\n1.Insert in begining\n2.Delete from Beginning");
        printf("\n3Search for an element\n4.Show\n5.Total nodes\n6.Exit ");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            begin_insert();
            break;
        case 2:
            begin_delete();
            break;
        case 3:
            search();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Total number of nodes: %d", head->data);
            break;
        case 6:
            free(head);
            exit(0);
            break;
        default:
            printf("Please enter valid choice..");
        }
    }
}
void begin_insert()
{
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter value: ");
        scanf("%d", &item);
        ptr->data = item;
        ptr->next = head->next;
        head->next = ptr;
        head->data++;
        printf("Node inserted");
    }
}
void begin_delete()
{
    struct node *temp;
    if (head->next == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        temp = head->next;
        head->next = temp->next;
        free(temp);
        printf("\nNode deleted from the begining ...\n");
        head->data--;
    }
}
void search()
{
    struct node *temp;
    int key, i = 1;
    if (head->next == NULL)
    {
        printf("\nEmpty List\n");
        return;
    }
    printf("\nEnter item which you want to search?: ");
    scanf("%d", &key);
    if (head->next->data == key)
    {
        printf("item found at location %d ", i);
    }
    else
    {
        temp = head->next;
        while (temp != NULL && temp->data != key)
        {
            i++;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            printf("Item not found\n");
            return;
        }
        printf("item found at location %d ", i);
    }
}
void display()
{
    struct node *temp=head->next;
    if (temp == NULL)
    {
        printf("Nothing to print");
    }
    else
    {
        printf("\nprinting values . . . . .");
        temp = head->next;
        while (temp != NULL)
        {
            printf("\n%d", temp->data);
            temp = temp->next;
        }
    }
}
