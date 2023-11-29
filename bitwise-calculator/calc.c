#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

int baseGetter(int wordChooser);
void showMenu();
int isDecimal(const char *str);
bool validateInputCorrectness(const char *str, int base);
uint32_t inputValue(int base);
uint32_t toOperate(uint32_t num1, uint32_t num2, int operator);
void finalResult(uint32_t result, int base);
int operationChecker();

int main() {
    int inputBase, outputBase;
    int operator;
    uint32_t num1, num2, result;

    printf("\nWelcome to our bitwise calculator!\n\n");

    while (operator != 8) {
        inputBase = baseGetter(0); // 0 - if function is used to get the base of input
        outputBase = baseGetter(1); // 1 - if function is used to get the base of output
        while (true) {
            showMenu();

            operator = operationChecker();

            if (operator == 8 || operator == 7) {
                break;
            }

            num1 = inputValue(inputBase);
            num2 = inputValue(inputBase);
            result = toOperate(num1, num2, operator);
            finalResult(result, outputBase);
        }
    }

    printf("Program terminated.\n");

    return 0;
}

int baseGetter(int wordChooser) {
    int base = 0;
    char *messages[] = {"Input", "Output"};
    char *word = messages[wordChooser];

    while (true) {
        printf("Enter number system for %s (2 for binary, 10 for decimal, 16 for hexadecimal): ", word);
        scanf("%d", &base);

        if (base == 2 || base == 10 || base == 16) {
            return base;
        } else {
            while (getchar() != '\n');
            printf("Invalid number system. Please try again.\n");
        }
    }
}

void showMenu() {
    printf("\n1. AND\n");
    printf("2. OR\n");
    printf("3. XOR\n");
    printf("4. NOR\n");
    printf("5. Left shift\n");
    printf("6. Right Shift\n");
    printf("7. Replay\n");
    printf("8. Exit\n");
}

int isDecimal(const char *str) {
    
    char *endptr;
    strtol(str, &endptr, 10);

    return (*endptr == '\0');
}

bool validateInputCorrectness(const char *str, int base) {

    switch (base) {
        case 2:
            return (str[0] == '0' && str[1] == 'b');
        case 10:
            return isDecimal(str);
        case 16:
            return (str[0] == '0' && str[1] == 'x');
        default:
            return false;
    }
}

uint32_t inputValue(int base) {
    char str[256];
    uint32_t result;

    printf("Enter a number: ");
    scanf("%s", str);

    while (!validateInputCorrectness(str, base)) {
        printf("Invalid number for the selected base. Please try again.\n");
        printf("Enter a number: ");
        scanf("%s", str);
    }

    switch (base) {
        case 2:
            result = strtoul(str + 2, NULL, 2);
            break;
        case 10:
            result = strtoul(str, NULL, 10);
            break;
        case 16:
            result = strtoul(str + 2, NULL, 16);
            break;
        default:
            result = 0;
    }

    return result;
}

uint32_t toOperate(uint32_t num1, uint32_t num2, int operator) {
    switch (operator) {
        case 1:
            return num1 & num2;
        case 2:
            return num1 | num2;
        case 3:
            return num1 ^ num2;
        case 4:
            return ~(num1 | num2);
        case 5:
            return num1 << num2;
        case 6:
            return num1 >> num2;
        default:
            return 0;
    }
}

void finalResult(uint32_t result, int base) {

    switch (base) {

        case 2:
            printf("Result: ");
            for (int i = 31; i >= 0; i--) {
                printf("%c", (result & (1 << i)) ? '1' : '0');
            }
            printf("\n");
            break;

        case 10:
            printf("Result: %u\n", result);
            break;

        case 16:
            printf("Result: %08x\n", result);
            break;
    }
}

int operationChecker() {
    char input[256];
    int operator;

    printf("Choose an operation: ");
    scanf(" %s", input);

    operator = atoi(input);

    if (operator < 1 || operator > 8) {
        printf("Invalid operation. Please try again.\n");
        return operationChecker();
    }
    return operator;
}