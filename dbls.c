#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct node {
    int data;                // Data held by the node
    struct node *prev;      // Pointer to the previous node
    struct node *next;      // Pointer to the next node
};

// Global variables for the head and end of the list
struct node *head = NULL, *end = NULL;
static int size = 0;       // Size of the linked list

// Function to insert a new node at the head
void insert_head(int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node)); // Allocate memory for a new node
    new_node->data = data;      // Set the node's data
    new_node->next = head;      // Link new node to the current head
    new_node->prev = NULL;      // There is no previous node for the new head
    if (head != NULL) {
        head->prev = new_node;  // Link current head back to the new node
    } else {
        end = new_node;         // If the list was empty, new node is also the end
    }
    head = new_node;            // Update head to the new node
    size++;
}

// Function to insert a new node at the end
void insert_end(int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;      // New node will be the last, so next is NULL
    new_node->prev = end;       // Link new node back to the current end
    if (end != NULL) {
        end->next = new_node;   // Link the current end to the new node
    } else {
        head = new_node;        // If the list was empty, new node is also the head
    }
    end = new_node;              // Update end to the new node
    size++;
}

// Function to delete the head node
void delete_head() {
    if (head == NULL) {
        printf("Linked List is Empty!\n");
        return;
    }
    struct node *temp = head;   // Store the current head
    head = head->next;          // Move head to the next node
    if (head != NULL) {
        head->prev = NULL;       // Update the new head's previous pointer
    } else {
        end = NULL;              // If the list is now empty, set end to NULL
    }
    printf("Node deleted: %d\n", temp->data);
    free(temp);                 // Free the memory of the deleted node
    size--;
}

// Function to display the list from head to end
void display_forward() {
    if (head == NULL) {
        printf("Linked List is Empty!\n");
        return;
    }
    struct node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function
int main() {
    int choice, data;

    do {
        printf("Choose:\n1. Insert head\n2. Insert end\n3. Delete head\n4. Display Forward\n5. Exit\n:: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to store at head: ");
                scanf("%d", &data);
                insert_head(data);
                break;
            case 2:
                printf("Enter data to store at end: ");
                scanf("%d", &data);
                insert_end(data);
                break;
            case 3:
                delete_head();
                break;
            case 4:
                display_forward();
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
