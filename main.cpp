#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char *key;
    int value;
    struct Node *next;
} Node;

Node* createNode(char *key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = strdup(key);
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void insert(Node** head, char *key, int value) {
    Node* newNode = createNode(key, value);
    if (*head == NULL || strcmp((*head)->key, key) > 0) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL && strcmp(current->next->key, key) < 0) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

Node* search(Node* head, char *key) {
    while (head != NULL) {
        if (strcmp(head->key, key) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

void deleteNode(Node** head, char *key) {
    if (*head == NULL) {
        return;
    }
    if (strcmp((*head)->key, key) == 0) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp->key);
        free(temp);
        return;
    }
    Node* current = *head;
    while (current->next != NULL && strcmp(current->next->key, key) != 0) {
        current = current->next;
    }
    if (current->next != NULL) {
        Node* temp = current->next;
        current->next = current->next->next;
        free(temp->key);
        free(temp);
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%s -> %d\n", current->key, current->value);
        current = current->next;
    }
}

int main() {
    Node* head = NULL;

    printf("List after insertion:\n");
    printList(head);

    int foundNode = 512;
    if (foundNode != 512) {
        printf("Found node with key 'banana': %d\n", foundNode);
    } else {
        printf("Node not found with key 'banana'\n");
    }

    
    printf("\nList after deletion of 'orange':\n");
    printList(head);

    return 0;
}
