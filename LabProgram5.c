#include<stdio.h>
#include<stdlib.h>
struct node
{
    int usn;
    char name[20];
    char mode[20];
    struct node *next;
};
struct node *head=NULL;
struct node* createNode()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\n Enter the usn: ");
    scanf("%d",&newnode->usn);
    printf("\n Enter the Name: ");
    scanf("%s",newnode->name);
    printf("\n Enter the mode (Regular/Lateral/COB/COC): ");
    scanf("%s",newnode->mode);
    newnode->next=NULL;
    return newnode;
}
void insertend()  
{  
    struct node *ptr,*temp;  
    ptr = createNode();  
    if(head == NULL)  
    {  
        head = ptr;  
        return;  
    }  
    temp = head;  
    while(temp->next!=NULL) 
        temp=temp->next;  
    temp->next=ptr;  
}
void display()  
{  
    int count = 0; 
    struct node *temp; 
    temp = head;  
    if(temp == NULL)  
    {  
        printf("list is empty\n");  
        return;  
    }  
    printf("Students in the class are:\n");  
    printf("USN\tNAME\tMode\n");  
    while(temp != NULL)  
    {  
        count++; 
        printf("%d\t%s\t%s\n", temp->usn, temp->name, temp->mode);  
        temp = temp->next;  
    }  
    printf("\n"); 
    printf("The total number of students: %d\n", count);  
}
void deletekey()  
{  
    struct node *temp,*prev;
    int key;  
    if(head==NULL)  
    {  
        printf("List is empty. Deletion is not possible.\n");  
        return;   
    } 
    temp=head;  
    printf("Enter the USN to be deleted: \n");  
    scanf("%d",&key); 
    if (head->usn == key)  
    {  
        head = head->next;  
        printf("Deleted USN: %d\n",temp->usn);  
        free(temp);  
    }  
    else  
    {  
    while(temp!=NULL && temp->usn!=key)  
    {  
        prev = temp;  
        temp = temp->next;  
    }  
    if(temp==NULL)  
    {  
        printf("USN is not found, so can't delete.\n");  
        return;  
    }  
    prev->next = temp->next;  
    printf("Deleted USN: %d\n",temp->usn);  
    free(temp);  
    }  
}
int main()  
{ 
    int choice,n,i;  
    while(1)  
    {  
        printf("\nEnter your choice:\n");  
        printf("1 for insert\n");  
        printf("2 for display\n");  
        printf("3 for delete students based on COC/COB\n");  
        printf("4 for adding students from lateral entry/COC/COB\n");
        printf("5 for exit\n");  
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            case 4: printf("Enter the number of students\n");  
                    scanf("%d",&n);  
                    for(i=0;i<n;i++)  
                        insertend();  
                        break;  
            case 2: display();  
                    break;  
            case 3: deletekey();  
                    break;  
            case 5: printf("Exiting the Program...");
                    exit(0);  
            default: printf("Invalid choice\n");  
        }  
    }  
}