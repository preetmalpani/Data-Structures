#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node {
    char name[50];           
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(const char* studentName) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, studentName);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void displayList(Node* head) {
    Node* temp = head;
    printf("\nDoubly Linked List Structure (Student Names):\n");
    printf("--------------------------------------------------------------------------\n");
    printf("| %-14s | %-14s | %-15s | %-14s |\n", "Node Addr", "Prev Addr", "Student Name", "Next Addr");
    printf("--------------------------------------------------------------------------\n");

    while (temp != NULL) {
        printf("| %-14p | %-14p | %-15s | %-14p |\n",
               (void*)temp,
               (void*)temp->prev,
               temp->name,
               (void*)temp->next);
        temp = temp->next;
    }
    printf("--------------------------------------------------------------------------\n");
}

int main() {
    Node* N1 = createNode("Alice");
    Node* N2 = createNode("Bob");
    Node* N3 = createNode("Charlie");
    Node* N4 = createNode("Diana");
    Node* N5 = createNode("Ethan");

    
    N1->next = N2;

    N2->prev = N1;
    N2->next = N3;

    N3->prev = N2;
    N3->next = N4;

    N4->prev = N3;
    N4->next = N5;

    N5->prev = N4;

    displayList(N1);
    free(N1);
    free(N2);
    free(N3);
    free(N4);
    free(N5);

    return 0;
}

Output:

Doubly Linked List Structure (Student Names):
--------------------------------------------------------------------------
| Node Addr      | Prev Addr      | Student Name    | Next Addr       |
--------------------------------------------------------------------------
| 0x55f3c1f2e2a0 | 0x0            | Alice           | 0x55f3c1f2e2d0  |
| 0x55f3c1f2e2d0 | 0x55f3c1f2e2a0 | Bob             | 0x55f3c1f2e300  |
| 0x55f3c1f2e300 | 0x55f3c1f2e2d0 | Charlie         | 0x55f3c1f2e330  |
| 0x55f3c1f2e330 | 0x55f3c1f2e300 | Diana           | 0x55f3c1f2e360  |
| 0x55f3c1f2e360 | 0x55f3c1f2e330 | Ethan           | 0x0             |
--------------------------------------------------------------------------
