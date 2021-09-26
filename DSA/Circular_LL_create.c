#include<stdlib.h>
#include<stdio.h>

struct node
{
    int inf;
    struct node *link;    
    /* data */
};

// Adding the nodes to the list
void addNode(struct node **start,int data)
{
    struct node *newNode, *temp=*start;
    newNode=(struct node *)malloc(sizeof(struct node));
    newNode->inf=data;
    newNode->link=NULL;
    if(*start == NULL)
    {
        *start=newNode;
        newNode->link=*start;
        return;
    }
    else
    {
        while(temp->link != *start)
        {
            temp=temp->link;
        }
        newNode->link=temp->link;
        temp->link=newNode;
        return;
    }

}

// Displaying the list
void display(struct node *start)
{
    struct node *temp=start;
    if(start == NULL)
    {
        printf("list is empty\n");
        return;
    }
    do
    {
        printf("%d ",temp->inf);
        temp=temp->link;
    } while (temp != start);    
    printf("\n");
}

int main()
{
    struct node *start=NULL;
    int i;
    for(i=1;i<=5;i++)
    addNode(&start,i);

    display(start);

    return 0;
}