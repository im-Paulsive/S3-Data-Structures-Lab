#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

// Function prototypes
struct node* insert(struct node*, int);
struct node* delete(struct node*, int);
struct node* merge_alternate(struct node*, struct node*);
void display(struct node*);

// Declare and initialize the head pointers globally
struct node *head1 = NULL, *head2 = NULL, *head3 = NULL;

struct node* insert(struct node *head, int dat) {
    struct node *ptr;
    ptr = head;
    struct node *newnode = (struct node*)malloc(sizeof(struct node)); // Correct allocation

    if (head == NULL) {
        head = newnode;
        newnode->data = dat;
        newnode->link = NULL;
    } else {
        newnode->data = dat;
        newnode->link = NULL;
        while (ptr->link != NULL) {
            ptr = ptr->link;
        }
        ptr->link = newnode;
    }
    return head;
}

struct node* delete(struct node *head, int key) {
    struct node *ptr, *s;
    ptr = head;

    if (head == NULL) {
        printf("List is empty\n");
    } else if (head->data == key) { // Special case for head node
        s = head;
        head = head->link;
        free(s);
    } else {
        while (ptr != NULL && ptr->data != key) {
            s = ptr;
            ptr = ptr->link;
        }
        if (ptr != NULL) {
            s->link = ptr->link;
            free(ptr);
        } else {
            printf("Element not found\n");
        }
    }
    return head;
}

struct node* merge_alternate(struct node *h1, struct node *h2) {
    struct node *h3, *p1, *p2, *p3;

    if (h1 == NULL)
        return h2;
    if (h2 == NULL)
        return h1;

    // Initialize merged list
    h3 = h1;  // Start with the first node of h1
    p1 = h1->link; // Points to the next node in list1
    p2 = h2;  // Start with the first node of h2
    p3 = h3;  // p3 is the pointer to the merged list

    while (p1 != NULL && p2 != NULL) {
        // Alternate between p1 and p2
        p3->link = p2;
        p3 = p2;
        p2 = p2->link;

        p3->link = p1;
        p3 = p1;
        p1 = p1->link;
    }

    // If one list is longer, attach the remaining nodes
    if (p1 != NULL) {
        p3->link = p1;
    } else {
        p3->link = p2;
    }

    return h3;
}

void display(struct node *head) {
    struct node *ptr = head;

    if (head == NULL) {
        printf("List is empty\n");
    } else {
        while (ptr != NULL) {
            printf("%d ", ptr->data);
            ptr = ptr->link;
        }
        printf("\n");
    }
}

int main() {
    int ch, n;
    do {
        printf("Enter choice\n");
        printf("1. Insert list1\n2. Insert list2\n3. Delete list1\n4. Delete list2\n5. Merge Alternately\n6. Display\n7. Exit\n");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
                printf("Enter element for list1: ");
                scanf("%d", &n);
                head1 = insert(head1, n);
                break;
                
            case 2:
                printf("Enter element for list2: ");
                scanf("%d", &n);
                head2 = insert(head2, n);
                break;
                
            case 3:
                printf("Enter element to be deleted from list1: ");
                scanf("%d", &n);
                head1 = delete(head1, n);
                break;
                
            case 4:
                printf("Enter element to be deleted from list2: ");
                scanf("%d", &n);
                head2 = delete(head2, n);
                break;
                
            case 5:
                head3 = merge_alternate(head1, head2);
                printf("Merged list alternately: ");
                display(head3);
                break;
                
            case 6:
                printf("Displaying merged list:\n");
                display(head3);
                break;

            case 7:
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (ch != 7);

    return 0;
}
