#include<stdio.h>
#include<stdlib.h>

struct Q
{
    int front;
    int rear;
    int capacity;
    int *array;
};

struct Q *createQ(int size)
{
    struct Q *q=(struct Q *)malloc(sizeof(struct Q));
    q->front=-1;
    q->rear=-1;
    q->capacity=size;
    q->array=(int *)malloc(q->capacity * sizeof(int));
    return q;
}

int isOverflow(struct Q *q)
{
    if(q->rear >= q->capacity - 1)
    return 1;
    else
    return 0;
}

int isUnderflow(struct Q *q)
{
    if(q->front > q->rear)
    return 1;
    else
    return 0;
}

void enque(struct Q *q, int data)
{
    if(isOverflow(q))
    {
        printf("Q is full\n");
        return;
    }
    if(q->front == -1)
    {
        q->front+=1;
    }
    q->rear+=1;
    q->array[q->rear]=data;
}

void deque(struct Q *q)
{
    if(isUnderflow(q))
    {
        printf("Q is empty\n");
        return;
    }
    int temp=q->array[q->front];
    printf("Dequed data = %d\n",temp);
    q->front+=1;
}

void display(struct Q *q)
{
    int s=q->front, d=q->rear;
    if(s > d)
    {
        printf("Q is empty \n");
        return;
    }
    while(s <= d)
    {
        printf("%d ",q->array[s++]);
    }
    printf("\n");
}

int main()
{
    struct Q *q=createQ(5);

    enque(q,1);
    enque(q,2);
    enque(q,3);
    enque(q,4);
    enque(q,5);
    enque(q,5);
    display(q); // This will print the entire data stored in queue

    deque(q);
    deque(q);
    deque(q);
    display(q); // This will print the remaining data in queue after deque
    deque(q);
    deque(q);
    display(q);
    

    return 0;
}