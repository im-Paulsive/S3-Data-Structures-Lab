#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root=NULL;
struct node* FindMin(struct node*);
struct node* insert(struct node *root,int dat)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=dat;
    newnode->left=NULL;
    newnode->right=NULL;
    if(root==NULL)
    {
        root=newnode;
        return root;
    }
    else if(root->data<newnode->data)
    {
        root->right=insert(root->right,dat);
        return root;
    }
    else if(root->data>newnode->data)
    {
        root->left=insert(root->left,dat);
        return root;
    }
}
void display(struct node *ptr)
{
    if (ptr!=NULL)
    {
        display(ptr->left);
        printf("%d\n",ptr->data);
        display(ptr->right);
    }
}

struct node *deletee(struct node *root,int key)
{
    if(root==NULL)
        return root;
    else if(root->data>key)
    {
        root->left=deletee(root->left,key);
        return root;
    }
    else if(root->data<key)
    {
        root->right=deletee(root->right,key);
        return root;
    }
    else if(root->data==key)
    {
        if(root->left==NULL&&root->right==NULL)
        {
            free(root);
            root=NULL;
        }
        else if(root->left==NULL||root->right==NULL)
        {
            if(root->left!=NULL)
            {
                struct node *temp=root;
                root=root->left;
                free(temp);
                temp==NULL;
                return root;
            }
            else
            {
                struct node *temp=root;
                root=root->right;
                free(temp);
                temp==NULL;
                return root;
            }
        }
        else
        {
            struct node *temp=FindMin(root->right);
            root->data=temp->data;
            root->right=deletee(root->right,temp->data);
            return root;
        }
    }
}
struct node* FindMin(struct node *ptr)
{
      while (ptr && ptr->left != NULL)
    {
        ptr = ptr->left; // Traverse left to find the minimum
    }
    return ptr; // Return the leftmost (minimum) node
}
int main() 
{
    int ch,d;
    do
    {
    printf("1.insert\n2.delete\n3.display\n4.Exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: printf("enter element to be inserted\n");
                scanf("%d",&d);
                root=insert(root,d);
                break;
        case 2: printf("enter element to be deleted\n");
                scanf("%d",&d);
                root=deletee(root,d);
                break;
        case 3: printf("tree nodes are:\n");
                display(root);
                break;
        case 4: break;
        default:printf("invalid choice\n");
    }
    }while(ch!=4);
    return 0;
}
