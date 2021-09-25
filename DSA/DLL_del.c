#include<stdio.h>
#include<stdlib.h>

struct node
{
    int inf;
    struct node *left;
    struct node *right;
};

// Adding the node to create DLL
void addNode(struct node **start,int pos,int data)
{
    int k=1;
    struct node *newNode,*temp=*start,*temp1;
    newNode=(struct node *)malloc(sizeof(struct node));
    newNode->inf=data;
    newNode->left=NULL;
    newNode->right=NULL;
    if(pos < 1)
    {
        printf("Invalid position \n");
        return;
    }
    if(pos == 1 || *start == NULL)
    {
        if(*start)
        {
            newNode->right=*start;
            (*start)->left=newNode;
        }
        *start=newNode;
        return;
    }
    else
    {
        while(temp!=NULL && k<pos)
        {
            temp1=temp;
            temp=temp->right;
            k++;
        }
        newNode->right=temp;
        if(temp)
        temp->left=newNode;
        temp1->right=newNode;
        newNode->left=temp1;
        return;
    }
}

// Display the DLL in both direction
void display(struct node *start)
{
    struct node *temp=start,*temp1;
    while(temp!=NULL)
    {
        temp1=temp;
        printf("%d ",temp->inf);
        temp=temp->right;
    }
    printf("\n");
    temp=temp1;
    while (temp!=NULL)
    {
        printf("%d ",temp->inf);
        temp=temp->left;
        /* code */
    }
    printf("\n");
    
}

// Deletion function for the mentioned position
void del(struct node **start,int pos)
{
    int k=1;
    struct node *temp=*start,*temp1;
    if(pos < 1 || *start == NULL)
    {
        printf("Invalid position or DLL is empty\n");
        return;
    }
    if(pos == 1)
    {
        *start=(*start)->right;
        if(*start)
        (*start)->left=NULL;
        free(temp);
        return;
    }
    else
    {
        while(temp!=NULL && k < pos)
        {
            temp1=temp;
            temp=temp->right;
            k++;
        }
        if(temp == NULL || temp->left != temp1)
        {
            printf("Out of range node position selection, Please select withing below choices \n");
            return;
        }
        temp1->right=temp->right;
        if(temp->right)
        temp->left=temp1;
        free(temp);
        return;
    }
}

int main()
{
    struct node *start=NULL;
    int i=0;
    for(i=1;i<=5;i++)
    {
        addNode(&start,i,i);
    }

    display(start);

    del(&start,6);

    display(start);

    return 0;
}