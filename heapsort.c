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

// Function to swap data of two nodes
void swap(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Function to get the node at the specified index
Node* getNodeAt(Node* head, int index) {
    Node* temp = head;
    for (int i = 0; temp != NULL && i < index; i++) {
        temp = temp->next;
    }
    return temp;
}

// Max-Heapify function
void maxHeapify(Node* head, int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    Node* largestNode = getNodeAt(head, largest);
    Node* leftNode = getNodeAt(head, left);
    Node* rightNode = getNodeAt(head, right);

    // Compare with left child
    if (left < size && leftNode->data > largestNode->data) {
        largest = left;
        largestNode = leftNode;
    }

    // Compare with right child
    if (right < size && rightNode->data > largestNode->data) {
        largest = right;
        largestNode = rightNode;
    }

    // If largest is not the current node, swap and heapify
    if (largest != i) {
        Node* currentNode = getNodeAt(head, i);
        swap(currentNode, largestNode);
        maxHeapify(head, size, largest);
    }
}

// Function to perform heapsort on the linked list using max-heap
void heapSort(Node* head, int size) {
    // Build max-heap
    for (int i = size / 2 - 1; i >= 0; i--) {
        maxHeapify(head, size, i);
    }

    // Extract elements from the heap
    for (int i = size - 1; i > 0; i--) {
        Node* firstNode = getNodeAt(head, 0);
        Node* lastNode = getNodeAt(head, i);
        swap(firstNode, lastNode);

        // Reduce the heap size and heapify the root element
        maxHeapify(head, i, 0);
    }
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
    int n, value;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insert(head, value);
    }

    printf("Original List:\n");
    printList(head);

    heapSort(head, n);

    printf("Sorted List (Heapsort using Max-Heap):\n");
    printList(head);

    return 0;
}
