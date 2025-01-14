#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node
};

// Function to insert a new node at the beginning of a linked list
void insert(Node** head_ref, int new_data) {
    Node* new_node = new Node();    // Create a new node
    new_node->data = new_data;      // Assign data to the new node
    new_node->next = (*head_ref);   // Point the new node to the current head
    (*head_ref) = new_node;         // Update the head to point to the new node
}

// Function to perform insertion sort on a linked list
void insertionSort(Node** head_ref) {
    Node* sorted = NULL;            // Initialize sorted list as empty
    Node* current = *head_ref;      // Start with the head of the list

    while (current != NULL) {       // Traverse through the list
        Node* next = current->next; // Store the next node

        if (sorted == NULL || sorted->data >= current->data) {  // If sorted list is empty or current node is smaller than first node in sorted list
            current->next = sorted;     // Insert at the beginning of sorted list
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data) {  // Find correct position in sorted list
                temp = temp->next;
            }
            current->next = temp->next;  // Insert in between nodes in sorted list
            temp->next = current;
        }

        current = next;  // Move to the next unsorted node
    }

    *head_ref = sorted;  // Update head to point to the sorted list
}

// Function to print the linked list
void printList(Node* node) {
    while (node != NULL) {   // Traverse through the list
        cout << node->data << " ";  // Print data of each node
        node = node->next;          // Move to the next node
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    int n, value;

    cout << "Enter the number of elements in the linked list: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        insert(&head, value);  // Insert elements into the linked list based on user input
    }

    cout << "Linked List before sorting: ";
    printList(head);   // Print unsorted linked list

    // Perform insertion sort
    insertionSort(&head);

    cout << "\nLinked List after sorting: ";
    printList(head);   // Print sorted linked list

    return 0;
}