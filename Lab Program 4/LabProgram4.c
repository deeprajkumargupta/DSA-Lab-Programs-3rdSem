#include <stdio.h>
#include <stdlib.h>
int *queue;
int max, rear, front, count = 0;

void enqueue(int item)
{
    if (count == max)
        printf("Queue overflow");
    else
    {
        rear = (rear + 1) % max;
        queue[rear] = item;
        count++;
    }
}
int dequeue()
{
    if (count == 0)
    {
        printf("Queue underflow");
        return -999;
    }
    else
    {
        front = (front + 1) % max;
        count--;
        return queue[front];
    }
}
void display()
{
    int i, k;
    if (count == 0)
        printf("Queue is empty");
    else
    {
        k = (front + 1) % max;
        for (i = 0; i < count; i++)
        {
            printf("%d\t", queue[k]);
            k = (k + 1) % max;
        }
    }
}
int main()
{
    int choice, ele;
    printf("Enter the size of the queue: ");
    scanf("%d", &max);
    rear = max - 1;
    front = max - 1;
    queue = (int *)malloc(max * sizeof(int));
    while (1)
    {
        printf("\nEnter your choice");
        printf("\n1 for enqueue\n2 for dequeue\n3 for display\n4 for exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the number to be enqueued\n");
            scanf("%d", &ele);
            enqueue(ele);
            break;
        case 2:
            ele = dequeue();
            if (ele != -999)
                printf("Dequeued element is %d\n", ele);
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting the Program...");
            free(queue);
            exit(0);
        default:
            printf("Invalid choice.");
        }
    }
    return 0;
}