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

struct stack
{
    int top;
    int capacity;
    int *array;
};

struct stack *createStack(int size)
{
    struct stack *s=(struct stack *)malloc(sizeof(struct stack));
    s->top=-1;
    s->capacity=size;
    s->array=(int *)malloc((s->capacity) * sizeof(int));
    return s;
}

void push(struct stack *s,int data)
{
    ++(s->top);
    s->array[s->top]=data;    
}

int pop(struct stack *s)
{
    return s->array[(s->top)--];
}

void palin(struct node *start)
{
    struct node *temp=start,*temp1;
    int c=0;
    while(temp!=NULL)
    {
        c+=1;
        temp=temp->link;
    }
    printf("Number of nodes = %d\n",c);
    temp=start;
    struct stack *s=createStack(c);
    while(temp!=NULL)
    {
        push(s,temp->inf);
        temp=temp->link;
    }
    temp=start;
    while(temp!=NULL)
    {
        int t=pop(s);
        if(temp->inf != t)
        {
            break;
        }
    }
    if(temp == NULL)
    {
        printf("List is palindrome \n");
        return;
    }
    else
    {
        printf("List is not a palindrome \n");
        return;
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

int main()
{
    struct node *start=NULL;
    int i;
    
    addNode(&start,1,1);
    addNode(&start,2,2);
    addNode(&start,3,3);
    addNode(&start,2,4);
    addNode(&start,1,5);

    display(start);

    palin(start);

    return 0;
}