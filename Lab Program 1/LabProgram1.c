#include<stdio.h>
#include<stdlib.h>
void selectionSort(int *a, int n)
{
    int i,j,temp,pos;
    for(i=0;i<n-1;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[pos])
            {
                pos=j;
            }
        }
        if(i!=pos)
        {
            temp= a[i];
            a[i]=a[pos];
            a[pos]=temp;
        }
    }
    printf("\nAfter Sorting: ");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
}
int main()
{
    int i,n,*a;
    printf("Enter the number of numbers: ");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    printf("Enter %d array elements: ",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("Before Sorting: ");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
        
    selectionSort(a,n);
}