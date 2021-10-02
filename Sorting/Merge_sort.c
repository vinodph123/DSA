// Merge sort
// Time complexity Best, Worst, Average case = O(n log(n));

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

void merge(int a[],int l,int r,int m)
{
    int n1=(m-l)+1;
    int n2=(r-m);
    int left[n1];
    int right[n2];
    int i=0,j=0,k=0;
    for(i=0;i<n1;i++)
    {
        left[i]=a[l+i];
    }
    for(j=0;j<n2;j++)
    {
        right[j]=a[j+m+1];
    }
    i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(left[i] <= right[j])
        {
            a[k++]=left[i++];
        }
        else if(left[i] > right[j])
        {
            a[k++]=right[j++];
        }
    }
    while(i<n1)
    {
        a[k++]=left[i++];
    }
    while(j<n2)
    {
        a[k++]=right[j++];
    }
}

void mergesoort(int a[],int l,int r)
{
    if(l<r)
    {
        int m=l+(r-l)/2;
        mergesoort(a,l,m);
        mergesoort(a,m+1,r);
        merge(a,l,r,m);
    }
}

int main()
{
    int a[n]={4,1,3,2,5};

    display(a);

    mergesoort(a,0,n-1);

    display(a);

    return 0;
}