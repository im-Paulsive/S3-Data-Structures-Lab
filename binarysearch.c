#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
Node* insert(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to find the middle of the linked list using the slow and fast pointer technique
Node* findMiddle(Node* start, Node* end) {
    if (start == NULL) return NULL;

    Node* slow = start;
    Node* fast = start;

    while (fast != end && fast->next != end) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Function to perform binary search on a sorted linked list
Node* binarySearch(Node* head, int target) {
    Node* start = head;
    Node* end = NULL;

    while (start != end) {
        // Find the middle node
        Node* mid = findMiddle(start, end);

        // If the middle element is the target
        if (mid == NULL) return NULL;
        if (mid->data == target) {
            return mid;
        }

        // If the target is less, search the left half
        if (mid->data > target) {
            end = mid;
        }
        // If the target is greater, search the right half
        else {
            start = mid->next;
        }
    }

    // Target not found
    return NULL;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    Node* head = NULL;
    int n, value, target;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the sorted elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insert(head, value);
    }

    printf("Enter the target element to search: ");
    scanf("%d", &target);

    printf("Linked List:\n");
    printList(head);

    // Perform binary search
    Node* result = binarySearch(head, target);

    if (result != NULL) {
        printf("Element %d found in the linked list.\n", target);
    } else {
        printf("Element %d not found in the linked list.\n", target);
    }

    return 0;
}
