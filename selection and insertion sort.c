#include <stdio.h>
#include<stdlib.h>
void insertionsort(int[],int);
void selectionsort(int[],int);
int a[100];

int main() 
{
    int ch,n;
    do
    {
    printf("enter choice\n");
    
    printf("1.insert\n2.selection sort\n3.insertion sort\n4.exit");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: printf("enter size\n");
                scanf("%d",&n);
                printf("enter array elements\n");
                for(int i=0;i<n;++i)
                {
                    scanf("%d",&a[i]);
                }
                break;
                
        case 2: selectionsort(a,n);
                break;
                
        case 3: insertionsort(a,n);
                break;
                
        case 4: break;
        default:    printf("invalid choice\n");
            
    }
    }while(ch!=4);

    return 0;
}
void insertionsort(int a[],int n)
{
    int i,j,key;
    for(i=1;i<n;++i)
    {
        j=i-1;
        key=a[i];
        while(j>=0&&a[j]>key)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=key;
    }
    for(int i=0;i<n;++i)
                {
                    printf("%d\n",a[i]);
                }
    
}
void selectionsort(int a[],int n)
{
    int i,j,min,temp;
    for(i=0;i<n-1;++i)
    {
       min=i;
       for(j=i+1;j<n;++j)
       {
           if(a[j]<a[min])
                min=j;
       }
       if(i!=min)
       {
           temp=a[i];
           a[i]=a[min];
           a[min]=temp;
       }
    }
    for(int i=0;i<n;++i)
                {
                    printf("%d\n",a[i]);
                }
}
