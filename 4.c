

#include<stdio.h>
#pragma pack(1) // to avoid structure paading 


struct temp
{
    char z;
    int a;
    float b;
    char c;
};

struct temp1
{
    unsigned a:2;
    //int a:2;
};

int main()
{
    struct temp *p=0;

    p++;
    printf("%d\n",p);

    struct temp1 t;
    t.a=2;
    printf("%d\n",t.a);

    return 0;
}