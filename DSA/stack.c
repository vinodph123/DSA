#include<stdlib.h>
#include<stdio.h>

// Stack implemetation using dynamic memory allocation 

struct stack
{
    int top;
    int capacity;
    int *arry;
};

// Creating stack using dynamic allocation
struct stack *createStack()
{
    struct stack *s=(struct stack *)malloc(sizeof(struct stack));
    s->top=-1;
    s->capacity=1;
    s->arry=(int *)malloc(s->capacity * sizeof(int)); // Keeping capacity as 1 initialy to increase when needed
    return s;
}

// To check stack overflow
int isFull(struct stack **s)
{
    if((*s)->top >= (*s)->capacity)
    return 1;
    else
    return 0;
}

// To check stack underflow
int isUnderflow(struct stack **s)
{
    if((*s)->top <= -1)
    return 1;
    else
    return 0;
}

// Every time to increase the size of stack dynamically based on the requirement of push operations
struct stack *double_the_size(struct stack **s)
{
    (*s)->capacity *= 2;
    (*s)->arry=(int *)realloc((*s)->arry, (*s)->capacity * sizeof(int));
    return *s;
}

// Function to push data
void push(struct stack **s,int data)
{
    if(isFull(s))
    {
        printf("stack is full, push operation cant be done \n");
        return;
    }
    *s=double_the_size(s);
    (*s)->top++;
    (*s)->arry[(*s)->top]=data;
}

// Function for pop operation
int pop(struct stack **s)
{
    if(isUnderflow(s))
    {
        printf("Stack is underflow, pop operation cant be done \n");
        return -1;
    }
    return ((*s)->arry[(*s)->top--]);
}

// Function returns top of the stac
int top(struct stack **s)
{
    if(isUnderflow(s))
    {
        printf("Stack is underflow, top operation cant be done \n");
        return -1;
    }
    return ((*s)->arry[(*s)->top]);
}



int main()
{
    struct stack *s=createStack();

    int i=0;
    for(i=1;i<=10;i++)
    {
        push(&s,i);
    }

    for(i=1;i<=8;i++)
    {
        printf("%d ",pop(&s));
        printf("\n");
    }

    printf("Topped value = %d\n",top(&s));

    return 0;
}