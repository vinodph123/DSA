#include<stdlib.h>
#include<stdio.h>

struct node
{
    int inf;
    struct node *link;    
    /* data */
};

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

// Function to print Nth node from end of the linkde list
void Nth(struct node *start,int n)
{
    struct node *temp=start;
    int c=0;
    while(temp!=NULL)
    {
        c+=1;
        temp=temp->link;
    }
    temp=start;
    int i=0;
    for(i=0;i<(c-n);i++)
    {
        temp=temp->link;
    }
    printf("Nth node from end of list = %d",temp->inf);
}

int main()
{
    struct node *start=NULL;
    int i;
    for(i=1;i<=5;i++)
    addNode(&start,i,i);

    display(start);

    Nth(start,5);

    return 0;
}