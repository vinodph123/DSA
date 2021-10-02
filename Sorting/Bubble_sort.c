// Bubble sort
// time complexity
// Worst case = O(n^2)
// Average case = O(n^2) 
// Best case = O(n) -> This is posible when the array is already sorted

#include<stdio.h>
#define n 5

void Bubble(int a[])
{
    int i=0,j=0,flag=1;
    for(i=0;i<5 && flag;i++)
    {
        flag=0;
        for(j=i+1;j<5;j++)
        {
            if(a[i] > a[j])
            {
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
                flag=1;
            }
        }
    }
}

void display(int a[])
{
    int i=0;
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main()
{
    int a[5]={4,1,3,2,5};

    display(a);

    Bubble(a);

    display(a);

    return 0;
}