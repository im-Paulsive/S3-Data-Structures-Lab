#include <stdio.h>
#include<stdlib.h>
struct node
{
    char data;
    struct node *lchild;
    struct node *rchild;
};

struct node* Newnode()
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data='\0';
    newnode->lchild=NULL;
    newnode->rchild=NULL;
    return newnode;
}
void insert(struct node *ptr)
{
    char dat[2];
    int ch;
    printf("enter data\n");
    scanf("%s", dat);
    ptr->data=(char)dat;
    printf("does %c have left child 1/0\n",ptr->data);
    scanf("%d",&ch);
    if(ch==1)
    {
        ptr->lchild=Newnode();
        insert(ptr->lchild);
    }
    printf("does %c have right child 1/0",ptr->data);
    scanf("%d",&ch);
    if(ch==1)
    {
        ptr->rchild=Newnode();
        insert(ptr->rchild);
    }
    
}
void preorder(struct node *ptr)
{
    if(ptr!=NULL)
    {
        printf("%c",ptr->data);
        preorder(ptr->lchild);
        preorder(ptr->rchild);
    }
}
void inorder(struct node *ptr)
{
    if(ptr!=NULL)
    {
        
        inorder(ptr->lchild);
        printf("%c",ptr->data);
        inorder(ptr->rchild);
    }
}
void postorder(struct node *ptr)
{
    if(ptr!=NULL)
    {
        
        postorder(ptr->lchild);
        postorder(ptr->rchild);
        printf("%c",ptr->data);
    }
}
int main() 
{
    int cho;
    struct node *root=Newnode();
    do
    {
    printf("enter choice\n");
    printf("1.insert\n2.preorder\n3.inorder\n4.postorder\n5.exit\n");
    scanf("%d",&cho);
    switch(cho)
    {
        case 1: insert(root);
                break;
        case 2:preorder(root);
                break;
        case 3: inorder(root);
                break;
        case 4: postorder(root);
                break;
        case 5: break;
        default:printf("invalid choice\n");
    }
    }while(cho!=5);

    return 0;
}
