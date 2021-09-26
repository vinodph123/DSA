#include<stdio.h>
#include<stdlib.h>

struct node
{
    int inf;
    struct node *link;
};


struct Q
{
    struct node *front;
    struct node *rear;
};

struct Q *createQ()
{
    struct Q *q=(struct Q *)malloc(sizeof(struct Q));
    q->front=NULL;
    q->rear=NULL;
    return q;
}

// Function for enque operation
void enque(struct Q *q,int data)
{
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    newNode->inf=data;
    newNode->link=NULL;
    if(q->front == NULL && q->rear == NULL)
    {
        q->front=q->rear=newNode;
        return;
    }
    else
    {
        struct node *temp=q->rear;
        while(temp->link != NULL)
        {
            temp=temp->link;
        }
        temp->link=newNode;
        return;
    }
}

// Function for deque operation
void deque(struct Q *q)
{
    if(q->front == NULL)
    {
        printf("Q is empty \n");
        return;
    }
    else
    {
        struct node *temp=q->front;
        printf("Dequed data from queue = %d \n",temp->inf);
        q->front=q->front->link;
        q->rear=q->front;
        free(temp);
    }
}

// Function return front element of the queue without removing the node
struct node *Front(struct Q *q)
{
    if(q->front == NULL)
    {
        printf("Q is empty \n");
        return;
    }
    else
    {
        struct node *temp=q->front;
        return temp;
    }    
}

int isEmpty(struct Q *q)
{
    if(q->front == NULL)
    return 1;
    else
    return 0;
}

int main()
{

    struct Q *q=createQ();

    enque(q,1);
    enque(q,2);
    enque(q,3);
    enque(q,4);
    enque(q,5);

    deque(q);
    deque(q);
    deque(q);
    deque(q);
    deque(q);
    deque(q); // To indicate end of queue elements

    struct node *t=Front(q);

    if(t)
    {
        printf("using front = %d\n",t->inf); // This is to demonstrate Front() from the queue        
    }
    

    return 0;
}