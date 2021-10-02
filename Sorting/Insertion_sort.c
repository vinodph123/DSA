// Insertion sort
// This one is better compared to bubble and selection sort
// Time complexity, Best case = O(n) when a[i] left are less than a[i]
// Worst case = O(n^2)
// Average case = O(n^2)

#include<stdio.h>
#define n 5

void display(int a[])
{
    int i=0;
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void insertion(int a[])
{
    int i=0,j=0,k=0,v=0;
    for(i=1;i<n;i++)
    {
        j=i;
        v=a[j];
        while(a[j-1] > v && j > 0)
        {
            a[j]=a[j-1];
            j--;
        }
        a[j]=v;
    }
}

int main()
{
    int a[5]={4,1,3,2,5};

    display(a);

    insertion(a);

    display(a);

    return 0;
}