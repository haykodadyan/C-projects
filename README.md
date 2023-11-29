
# Bitwise Calculator

This is a bitwise calculator, which have following operators: AND, OR, XOR, NOR, Left Shift, and Right Shift.

In this program you can input following 3 bases for both input and output: binary(2), decimal(10) and hexadecimal(16).

Functions:

1. baseGetter - getting base of input and output with validations.
2. showMenu - shows the menu of operators (interface) to user to choose.
3. isDecimal - function checks if a given string represents a decimal number.
4. validateInputCorrectness - checks whether a given input string is a valid representation of a number in a specified base. It ensures that the format of the input string matches the expected format for the chosen number system.
5. inputValue - function is responsible for taking user input for a number in the specified base (binary, decimal, or hexadecimal)
6. toOperate - performs bitwise operations on two given unsigned 32-bit integers (num1 and num2) based on the specified operation code (operator)
7. operationChecker - function is responsible for obtaining and validating the user's choice of operation in the bitwise calculator program
8. finalResult - displaying the final result of a bitwise operation to the user.


# Dynamic Array

The dynamic array program showcases the creation and manipulation of a dynamic array, allowing users to insert elements, remove elements by value or index, get access to elements by index, and view the current state of the array.

Functions:

1. createDynamicArray: Allocates memory for a dynamic array and initializes its fields.
2. validInput: Reads and validates integer input from the user.
3. push: Inserts a new element into the dynamic array.
4. removeByIndex: Removes an element at a specified index.
5. removeByValue: Removes elements by value from the dynamic array.
6. showArray: Displays the current elements, element count, and capacity of the array.
7. getAccesByIndex: Gets access to an element by index.
8. controller: Controls the execution of different operations based on user input.
9. menu: Displays the menu of available operations.
10. toFree: Frees the allocated memory for the dynamic array.

# Stack

The custom stack program utilizes a linked list to implement a stack data structure. It provides functionalities like pushing elements onto the stack, popping elements off the stack, displaying the top element, checking if the stack is empty, filling the stack with user-defined values, and displaying the current stack contents.

Functions:

1. stackPush: Pushes an element onto the stack.
2. stackPop: Pops an element from the stack.
3. showPeak: Displays the top element of the stack.
4. toFreeStack: Frees the memory allocated for the stack.
5. createStack: Initializes the stack.
6. stackIsEmpty: Checks if the stack is empty.
7. fillStack: Fills the stack with elements based on user input.
8. showStack: Displays the current elements of the stack.