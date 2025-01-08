#include<stdio.h>
#include<stdlib.h>

// Define a structure for a node in the singly linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node **head, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    printf("Node with data %d inserted at the beginning.\n", data);
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node **head, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        printf("Node with data %d inserted at the end.\n", data);
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Node with data %d inserted at the end.\n", data);
}

// Function to delete a node by its value
void deleteNode(struct Node **head, int key) {
    struct Node *temp = *head, *prev = NULL;

    // If the head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        printf("Node with data %d deleted.\n", key);
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the key was not found in the list
    if (temp == NULL) {
        printf("Node with data %d not found.\n", key);
        return;
    }

    // Unlink the node and free memory
    prev->next = temp->next;
    free(temp);
    printf("Node with data %d deleted.\n", key);
}

// Function to traverse the list and print its elements
void traverseList(struct Node *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("List elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete node\n");
        printf("4. Traverse list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data of node to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 4:
                traverseList(head);
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
