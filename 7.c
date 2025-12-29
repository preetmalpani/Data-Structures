#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void create() {
    int n, i, val;
    struct node *newNode, *temp;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter element %d: ", i + 1);
        scanf("%d", &val);

        newNode->data = val;
        newNode->prev = newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
}

void insertLeft() {
    int key, val;
    struct node *temp = head, *newNode;

    printf("Enter key value: ");
    scanf("%d", &key);
    printf("Enter new value: ");
    scanf("%d", &val);

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Key not found\n");
        return;
    }

    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;

    newNode->next = temp;
    newNode->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = newNode;
    else
        head = newNode;

    temp->prev = newNode;
}

void deleteValue() {
    int val;
    struct node *temp = head;

    printf("Enter value to delete: ");
    scanf("%d", &val);

    while (temp != NULL && temp->data != val)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

void display() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("DLL contents: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice;

    do {
        printf("\n1.Create\n2.Insert Left\n3.Delete\n4.Display\n5.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                insertLeft();
                break;
            case 3:
                deleteValue();
                break;
            case 4:
                display();
                break;
            case 5:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}

OUTPUT:
1.Create
2.Insert Left
3.Delete
4.Display
5.Exit
Enter choice: 1
Enter number of nodes: 3
Enter element 1: 10
Enter element 2: 20
Enter element 3: 30

1.Create
2.Insert Left
3.Delete
4.Display
5.Exit
Enter choice: 2
Enter key value: 30
Enter new value: 60

1.Create
2.Insert Left
3.Delete
4.Display
5.Exit
Enter choice: 4
DLL contents: 10 20 60 30 

1.Create
2.Insert Left
3.Delete
4.Display
5.Exit
Enter choice: 3
Enter value to delete: 20

1.Create
2.Insert Left
3.Delete
4.Display
5.Exit
Enter choice: 4
DLL contents: 10 60 30 

1.Create
2.Insert Left
3.Delete
4.Display
5.Exit
Enter choice: 5
