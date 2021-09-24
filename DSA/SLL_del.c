#include<stdlib.h>
#include<stdio.h>

struct node
{
    int inf;
    struct node *link;    
    /* data */
};


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

void display(struct node *start)
{
    while(start!=NULL)
    {
        printf("%d ",start->inf);
        start=start->link;
    }
    printf("\n");
}

// deletion of the node in a given position
void delete(struct node **start,int pos)
{
    int k=1;

    struct node *temp,*temp1;
    temp=*start;
    if(pos < 1 || *start == NULL)
    {
        printf("Invalid position or List is empty\n");
        return;
    }
    if(pos == 1)
    {
        *start=(*start)->link;
        free(temp);
    }
    else
    {
        while(temp!=NULL && k<pos)
        {
            temp1=temp;
            temp=temp->link;
            k++;
        }
        if(temp == NULL)
        {
            printf("Out of range position = %d\n",pos);
            return;
        }
        temp1->link=temp->link;
        free(temp);
    }
    
}


int main()
{
    struct node *start=NULL;
    int i;
    for(i=1;i<=5;i++)
    addNode(&start,i,i);

    display(start);

    delete(&start,5);

    display(start);

    return 0;
}