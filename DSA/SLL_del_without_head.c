#include<stdlib.h>
#include<stdio.h>

struct node
{
    int inf;
    struct node *link;    
    /* data */
};

struct node *a[10]; // This array of pointers to structure is to store the address of each node to pass input
int c=0;

// Adding the nodes to the list
void addNode(struct node **start,int data,int pos)
{
    int k=1;
    struct node *newNode,*temp,*temp1;
    temp=*start;
    newNode=(struct node *)malloc(sizeof(struct node));
    newNode->inf=data;
    newNode->link=NULL;
    if(pos < 1)
    {
        printf("Invalid position ....!\n");
        return;
    }

    if(*start == NULL || pos == 1)
    {
        if(*start)
        newNode->link=*start;
        *start=newNode;
        a[c++]=newNode;
        return;
    }
    else
    {
        while(temp!=NULL && k<pos)
        {
            temp1=temp;
            temp=temp->link;
            k++;
        }
        newNode->link=temp;
        temp1->link=newNode;
        a[c++]=newNode;
    }

}

// Displaying the list
void display(struct node *start)
{
    while(start!=NULL)
    {
        printf("%d ",start->inf);
        start=start->link;
    }
    printf("\n");
}

// Function to delete the node without head pointer
// NOTE : This will not work for last node deletion
void del(struct node *start)
{
    struct node *temp=start,*next;
    next=temp->link;
    temp->inf=next->inf;
    temp->link=next->link;
}

int main()
{
    struct node *start=NULL;
    int i;
    for(i=1;i<=5;i++)
    addNode(&start,i,i);

    display(start);

    del(a[3]); // For last node wont work because next of last node will be null which cant be assigned

    display(start);

    return 0;
}