// Quick sort implementation
// Time complexity Worst case = O(n^2), Best case = O(n log(n)), Average case = O(n log(n))
// Worst case can be avoided by randomizing the data in array

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

void swap(int a[],int left,int right)
{
    int temp=a[left];
    a[left]=a[right];
    a[right]=temp;
}
// This function is used to randomize the array elements to avoid Worst case complexity
void randomize(int a[])
{
    srand(time(NULL));

    int i,j;
    for(i=n-1;i>0;i--)
    {
        int j=rand()%(i+1);
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
}
// Partition function used to select pivot index
int partition(int a[],int l,int r)
{
    int left=l;
    int right=r;
    int p=a[l];
    while(left < right)
    {
        while(a[left] < p)
        left++;

        while(a[right] > p)
        right--;

        if(left < right)
        swap(a,left,right);
    }
    a[left]=a[right];
    p=a[right];
    return right;
}

// Quick sort algorithm 
void QuickSort(int a[],int l,int r)
{
    if(l < r)
    {
        int p=partition(a,l,r);
        QuickSort(a,l,p-1);
        QuickSort(a,p+1,r);
    }
}

int main()
{
    int a[n]={4,1,3,2,5};

    display(a);

    randomize(a);

    display(a);

    QuickSort(a,0,5);

    display(a);

    return 0;
}