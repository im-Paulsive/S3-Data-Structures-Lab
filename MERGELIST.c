//MERGE TWO LINKED LIST ONE LIST AFTER ANOTHER
#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node* insert(struct node*,int );
struct node* delete(struct node*,int );
struct node *head1=NULL,*head2=NULL,*head3=NULL,*ptr1,*ptr2;


struct node* insert(struct node *head,int dat)
{
    struct node *ptr;
    ptr=head;
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
        head=newnode;
        newnode->data=dat;
        newnode->link=NULL;
    }
    else if(head->link==NULL)
    {
        head->link=newnode;
        newnode->data=dat;
        newnode->link=NULL;
    }
    else
    {
        newnode->data=dat;
        newnode->link=NULL;
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=newnode;
    }
    return head;
}
struct node* delete(struct node *head,int key)
{
    struct node *ptr,*s;
    ptr=head;
    if(head==NULL)
        printf("list empty\n");
    else if(head->link==NULL)
    {
        free(head);
        head=NULL;
    }
    else
    {
        while(ptr->data!=key)
        {
            s=ptr;
            ptr=ptr->link;
            
        }
        s->link=ptr->link;
        free(ptr);
        ptr=NULL;
    }
    return head;
}
struct node* merge(struct node *h1,struct node *h2)
{
    struct node *h3,*p1,*p2,*p3;
    if(h1==NULL)
        return h2;
    if(h2==NULL)
        return h1;
    
    if(h1->data<=h2->data)
    {
        h1->link=merge(h1->link,h2);
        return h1;
    }
    else
    {
        h2->link=merge(h1,h2->link);
        return h2;
    }
}
void display(struct node *head)
{
    struct node *ptr;
    ptr=head;
    if(head==NULL)
        printf("list empty\n");
    else 
    {
        while(ptr!=NULL)
        {
            printf("%d",ptr->data);
            ptr=ptr->link;
        }
    }
}
int main() 
{
    int ch,n;
    do
    {
    printf("enter choice\n");
    printf("1.insert list1\n2.insert list 2\n3.delete list1\n4.delete list2\n5.merge\n6.display\n7.exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: printf("enter element\n");
                scanf("%d",&n);
                head1=insert(head1,n);
                break;
                
        case 2: printf("enter element\n");
                scanf("%d",&n);
                head2=insert(head2,n);
                break;
                
        case 3: printf("enter element to be deleted\n");
                scanf("%d",&n);
                head1=delete(head1,n);
                break;
                
        case 4: printf("enter element to be deleted\n");
                scanf("%d",&n);
                head2=delete(head2,n);
                break;
                
        case 5: head3=merge(head1,head2);
                break;
                
        case 6: display(head3);
                break;
        case 7: break;
        default:printf("invalid choice\n");
    }
    }while(ch!=7);
    return 0;
}
