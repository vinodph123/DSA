// Spiral printing of given matrix

#include<stdio.h>
#define n 4

// top   1 -> 2 -> 3 -> 4 
//       8 -> 7 -> 6    5
//       9    10<-11   12
// down  16 <-15 <-14 <-13
//       left          right

void print_spiral(int a[][n],int r,int c)
{
    int top=0, down=r-1, right=c-1, left=0;
    int k=0,dir=0;
    while(top <= down && left <= right)
    {
        if(dir == 0)
        {
            for(k=left;k<=right;k++)
            {
                printf("%d ",a[top][k]);
            }
            top++;
        }
        else if(dir == 1)
        {
            for(k=top;k<=down;k++)
            {
                printf("%d ",a[k][right]);
            }
            right--;
        }
        else if(dir == 2)
        {
            for(k=right;k>=left;k--)
            {
                printf("%d ",a[down][k]);
            }
            down--;
        }
        else if(dir == 3)
        {
            for(k=down;k>=top;k--)
            {
                printf("%d ",a[k][left]);
            }
            left++;
        }
        dir = (dir + 1)%4;

    }
    
}

void display(int a[][n])
{
    int i=0,j=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

int main()
{

    int a[n][n],i=0,j=0,k=1;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            a[i][j]=k++;
        }
    }

    display(a);

    print_spiral(a,n,n);
/*
    int i=0,j=0;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
*/
    /*int i=0;
    for(i=0;i<5;i++)
    printf("%d ",i);
    printf("\n");
    printf("%d\n",i);*/

    return 0;
}