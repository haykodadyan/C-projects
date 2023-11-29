#include <stdio.h>
#include <stdlib.h>

#define SOURCE_CAP 4

typedef struct {
    int *arrptr;
    int capacity;
    int elements;
} DynamicArray;

DynamicArray* createDynamicArray();
int validInput(char *text);
void push(DynamicArray *arr, int elem, char *text);
int removeByIndex(DynamicArray *arr, int index, char *text);
int removeByValue(DynamicArray *arr, int value, char *text);
void showArray(DynamicArray *arr);
void getAccesByIndex(DynamicArray *arr, char *text);
void controller(DynamicArray *arr, int operation);
void menu();
void toFree(DynamicArray *arr);

int main () {

    DynamicArray *array = createDynamicArray();
    int operation = 0;
    char *text;

    if (array == NULL) {
        return 1;
    }

    printf("\nDynamic Array\n");
    printf("\n-> Enter the command number from the list below that you want to do <-\n");

    while(operation != 6) {
        menu();
        text = "Enter: ";
        operation = validInput(text);
        controller(array, operation);
    }
    
    printf("\n");
    toFree(array);
    printf("Exiting...\n");
    return 0;

}

DynamicArray* createDynamicArray () {

    DynamicArray *arr = (DynamicArray*)malloc(sizeof(DynamicArray));
    
    if (arr == NULL) {
        printf("Memory allocation problem. Exiting...\n");
        return NULL;
    }

    arr->arrptr = (int*)malloc(SOURCE_CAP * sizeof(int));
    arr->elements = 0;
    arr->capacity = SOURCE_CAP;

    if (arr->arrptr == NULL) {
        printf("Memory allocation problem. Exiting...\n");
        free(arr);
        return NULL;
    }

    return arr;
}

int validInput(char *text) {
    int input = 0;
    int scanResult;
    printf("%s", text);
    scanResult = scanf("%d", &input);

    if (scanResult != 1) {
        printf("Invalid input.\n");
        while(getchar() != '\n');
        return validInput(text);
    }

    return input;
}

void push(DynamicArray *arr, int elem, char *text) {
    elem = validInput(text);
    if (arr->elements == arr->capacity) {
        arr->capacity *= 2;
        arr->arrptr = (int*)realloc(arr->arrptr, arr->capacity * sizeof(int));
        if (arr->arrptr == NULL) {
            printf("Memory reallocation error. Exiting\n");
            return;
        }
    }
    (*arr).arrptr[(*arr).elements] = elem;
    ++(*arr).elements;
}

int removeByIndex(DynamicArray *arr, int index, char *text) {
    index = validInput(text);
    if (index >= arr->elements || index < 0) {
        return 0;
    }

    for (int i = index; i < arr->elements; ++i) {
        arr->arrptr[i] = arr->arrptr[i + 1];
    }

    --arr->elements;

    if (arr->elements < (arr->capacity / 4)) { // shrinks free space if used less than a quarter
        arr->capacity /= 2;                    // of array's capacity, but leaves a little bit space
        arr->arrptr = (int*)realloc(arr->arrptr, (arr->capacity) * sizeof(int));
    }

    return 1;
}

int removeByValue(DynamicArray *arr, int value, char *text) {
    int index = 0;

    while(index < arr->elements) {
        if (value == arr->arrptr[index]) {
            return removeByIndex(arr, index, text) ? 1 : 0;
        } else {
            ++index;
        }
    }

    return 0;
}

void showArray(DynamicArray *arr) { // shows array, updated elements count and current capacity
    printf("Array: ");
    for (int i = 0; i < arr->elements; ++i) {
        printf("%d ", arr->arrptr[i]);
    }

    printf("\nElements: %d\n", arr->elements);
    printf("Capacity: %d\n", arr->capacity);
    return;
}

void getAccesByIndex(DynamicArray *arr, char *text) {
    int index = 0;
    index = validInput(text);

    if (index >= arr->elements || index < 0) {
        printf("No element with such index.\n");
        return;
    }

    printf("Element: %d\n", arr->arrptr[index]);
}

void controller(DynamicArray *arr, int operation) {
    int input = 0;
    char *text;

    switch(operation) {
        case 1:
            text = "Pushing value: ";
            push(arr, input, text);
            printf("Element was successfully pushed.\n");
            break;
        case 2:
            text = "Removing element value: ";
            if (removeByValue(arr, input, text)) {
                printf("Element with this value has been successfully removed.\n");
            } else {
                printf("No element with such value.\n");
            }
            break;
        case 3:
            text = "Removing element index: ";
            if (removeByIndex(arr, input, text)) {
                printf("Element under this index has been successfully removed.\n");
            } else {
                printf("No element under this index.\n");
            }
            break;
        case 4:
            text = "Input index of element you want to get access: ";
            getAccesByIndex(arr, text);
            break;
        case 5:
            showArray(arr);
            break;
    }
}

void menu() {
    printf("\n1. Insert element\n");
    printf("2. Remove element by value\n");
    printf("3. Remove element by index\n");
    printf("4. Get access to element by index\n");
    printf("5. Show array (elements, elements count, capacity)\n");
    printf("6. >>EXIT\n\n");
}

void toFree(DynamicArray *arr) {
    free(arr->arrptr);
    free(arr);
}