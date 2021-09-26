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

void search(struct node *root,int key)
{
    if(root == NULL)
    {
        printf("BST is empty or Key not found \n");
        return;
    }
    else if(key < root->inf)
    {
        search(root->left,key);
    }
    else if(key > root->inf)
    {
        search(root->right,key);
    }
    else if(root->inf == key)
    {
        printf("Search found.....!\n",root->inf);
        return;
    }
    else
    {
        printf("BST doesn't has key mentioned \n");
        return;
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

    search(root,100);

    return 0;
}
