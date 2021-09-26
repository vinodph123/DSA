#include<stdio.h>
#include<stdlib.h>

struct node
{
    int inf;
    struct node *left;
    struct node *right;
};

struct node *newNode(struct node *root,int data)
{
    struct node *new=(struct node *)malloc(sizeof(struct node));
    new->inf=data;
    new->left=NULL;
    new->right=NULL;
    return new;
}

// Adding node for creation of the BST
struct node *addNode(struct node *root,int data)
{
    if(root == NULL)
    {
        return newNode(root,data);
    }
    else if(data < root->inf)
    {
        root->left=addNode(root->left,data);
    }
    else if(data > root->inf)
    {
        root->right=addNode(root->right,data);
    }
    return root;
}

void DLR(struct node *root)
{
    if(root)
    {
        printf("%d ",root->inf);
        DLR(root->left);
        DLR(root->right);
    }
}

void LDR(struct node *root)
{
    if(root)
    {
        LDR(root->left);
        printf("%d ",root->inf);
        LDR(root->right);
    }
}

void LRD(struct node *root)
{
    if(root)
    {
        LRD(root->left);
        LRD(root->right);
        printf("%d ",root->inf);
    }
}

int main()
{
    struct node *root=NULL;

    root=addNode(root,10);
    addNode(root,1);
    addNode(root,18);
    addNode(root,7);
    addNode(root,5);
    addNode(root,40);

    DLR(root);
    printf("\n");
    LDR(root);
    printf("\n");
    LRD(root);
    printf("\n");

    return 0;
}
