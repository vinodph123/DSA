// Spiral printing of given matrix

#include<stdio.h>
#define n 2

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
        if(dir == 0) // This direction is from top left to right 1,2,3,4
        {
            for(k=left;k<=right;k++)
            {
                printf("%d ",a[top][k]);
            }
            top++; // Top holding the position of index 1
        }
        else if(dir == 1) // This direction is from top to down and rightest calumn values
        {
            for(k=top;k<=down;k++)
            {
                printf("%d ",a[k][right]);
            }
            right--; // Right decremeted due to last column covered already 
        }
        else if(dir == 2) // This direction is right to down (right corner to left corner values)
        {
            for(k=right;k>=left;k--)
            {
                printf("%d ",a[down][k]);
            }
            down--; // Down is decremented Since last row is covered 
        }
        else if(dir == 3) // THis directio is down to top and first column 
        {
            for(k=down;k>=top;k--)
            {
                printf("%d ",a[k][left]);
            }
            left++; // Since first column covered incremented to next coulmn
        }
        dir = (dir + 1)%4; // This is increase the direction value with respect to different direction

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