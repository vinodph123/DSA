#include<stdio.h>
#include<stdlib.h>

struct node
{

    int inf;
    struct node *link;
};


struct node *push(struct node *start,int data)
{
    struct node *newNode;
    newNode=(struct node *)malloc(sizeof(struct node));
    newNode->inf=data;
    newNode->link=start;
    start=newNode;
    return start;
}


struct node*pop(struct node *start)
{
    if(start == NULL)
    {
        printf("stack is empty\n");
        return;
    }
    struct node *temp =start;
    printf("poped the value = %d\n",temp->inf);
    start=start->link;
    free(temp);
    return start;
}

void display(struct node *start)
{
    struct node *temp=start;
    while(temp!=NULL)
    {
        printf("%d ",temp->inf);
        temp=temp->link;
    }
    printf("\n");
}

int main()
{
    struct node *start=NULL;

    start=push(start,1);
    start=push(start,2);
    start=push(start,3);
    start=push(start,4);
    start=push(start,5);

    display(start);

    int a=30;

    start=pop(start);

    display(start);


    return 0;
}