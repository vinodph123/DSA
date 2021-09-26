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

// Function to delete the nodes in circular linked list
void del(struct node **start)
{
    struct node *temp=*start,*temp1;
    if(*start == NULL)
    {
        printf("List is empty \n");
        return;
    }
    else
    {
        temp=*start;
        temp1=*start;
        while(temp1->link != *start)
        {
            temp1=temp1->link;
        }
        temp1->link=(*start)->link;
        *start=(*start)->link;
        free(temp);
        return;
    }

}

int main()
{
    struct node *start=NULL;
    int i;
    for(i=1;i<=5;i++)
    addNode(&start,i);

    display(start);

    for(i=0;i<5;i++)
    {
        display(start);
        del(&start);
    }
    
    

    return 0;
}