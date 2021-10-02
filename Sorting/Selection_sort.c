// Selection sort
// This can be used when records are less
// Time complexity -> Best case = O(n^2), Average case = O(n^2), Worst case = O(n^2)

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

void selection(int a[])
{
    int i=0,j=0,min=0;
    for(i=0;i<n;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[min] > a[j])
            {
                min=j;
            }
        }
        if(i != min)
        {
            int temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        }
    }
}

int main()
{
    int a[5]={4,1,3,2,5};

    display(a);

    selection(a);

    display(a);

    return 0;
}