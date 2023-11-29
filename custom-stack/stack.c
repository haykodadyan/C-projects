#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    struct Node *next;
    int value;
} Node;

typedef struct {
    Node *head;
} CustomStack;

void stackPush(CustomStack *customStack, int elem) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        exit(EXIT_FAILURE);
    }

    newNode->value = elem;
    newNode->next = customStack->head;
    customStack->head = newNode;
}

int stackPop(CustomStack *customStack) {
    if (customStack->head == NULL) {
        printf("Stack underflow problem.\n");
        exit(EXIT_FAILURE);
    }

    int elem = customStack->head->value;
    customStack->head = customStack->head->next;
    return elem;
}

int showPeak(CustomStack *customStack) {
    if (customStack->head == NULL) {
        printf("Stack is empty.\n");
        exit(EXIT_FAILURE);
    }
    return customStack->head->value;
}

void toFreeStack(CustomStack *customStack) {
    while (customStack->head != NULL) {
        Node *tmp = customStack->head;
        customStack->head = customStack->head->next;
        free(tmp);
    }
}

void createStack(CustomStack *customStack) {
    customStack->head = NULL;
}

bool stackIsEmpty(CustomStack *customStack) {
    return customStack->head == NULL;
}

void fillStack(CustomStack *customStack) {
    int size = 0;
    printf("Input size: ");

    if (scanf("%d", &size) != 1) {
        printf("Input should be number.\n");
        while(getchar() != '\n');
        fillStack(customStack);
    }

    if (size < 0) {
        printf("Invalid input. Please input positive number.\n");
        fillStack(customStack);
    }

    for (int i = 1; i <= size; ++i) {
        stackPush(customStack, i);
    }
}

void showStack(CustomStack *customStack) {
    Node *tmp = customStack->head;
    printf("Stack: ");
    while (tmp != NULL) {
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

int main() {
    CustomStack myCustomStack;
    createStack(&myCustomStack);

    printf("\nInput any number will fill stack from 1 to your inputed number.\n\n");
    fillStack(&myCustomStack);

    printf("\nTop: %d\n", showPeak(&myCustomStack));
    printf("Popped element: %d\n", stackPop(&myCustomStack));
    printf("New top of stack: %d\n", showPeak(&myCustomStack));
    showStack(&myCustomStack);

    toFreeStack(&myCustomStack);

    return 0;
}
