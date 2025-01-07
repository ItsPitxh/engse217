#include <stdio.h>
#include <string.h>
#include <math.h>

#define MaxStack 40 // Maximum stack size

char postfixExpr[80] = {"AB+C-D/"}; // Assigned postfix expression
float operandValues[80];           // Values for operands in postfix expression
float operandStack[MaxStack];      // Operand stack
int stackPointer = 0;              // Stack pointer initialized to 0

// Function to push a value onto the stack
void push(float value) {
    if (stackPointer == MaxStack) {
        printf("ERROR: STACK OVERFLOW!!!\n");
    } else {
        stackPointer++;
        operandStack[stackPointer] = value;
    }
}

// Function to pop a value from the stack
float pop() {
    if (stackPointer != 0) {
        float value = operandStack[stackPointer];
        stackPointer--;
        return value;
    } else {
        printf("ERROR: STACK UNDERFLOW!!!\n");
        return 0; // Return 0 in case of underflow
    }
}

// Function to calculate the result of the postfix expression
void calculatePostfix(char postfix[80]) {
    float operand1, operand2, result;
    int len = strlen(postfix);
    char currentChar;

    printf("Postfix expression: %s\n", postfix);

    // Step 1: Input values for operands
    for (int i = 0; i < len; i++) {
        currentChar = postfix[i];
        if (strchr("+-*/^", currentChar) == NULL) { // Check if operand
            printf("Enter value for operand '%c': ", currentChar);
            scanf("%f", &operandValues[i]);
        }
    }

    // Step 2: Process the postfix expression
    for (int i = 0; i < len; i++) {
        currentChar = postfix[i];
        if (strchr("+-*/^", currentChar) == NULL) { // If operand
            push(operandValues[i]);
        } else { // If operator
            operand1 = pop();
            operand2 = pop();
            switch (currentChar) {
                case '+':
                    result = operand2 + operand1;
                    break;
                case '-':
                    result = operand2 - operand1;
                    break;
                case '*':
                    result = operand2 * operand1;
                    break;
                case '/':
                    result = operand2 / operand1;
                    break;
                case '^':
                    result = pow(operand2, operand1);
                    break;
                default:
                    result = 0;
                    printf("Invalid operator encountered.\n");
                    break;
            }
            push(result);
        }
    }

    // The final result is the only value left on the stack
    printf("\nFinal result = %.2f\n", pop());
}

int main() {
    printf("POSTFIX CALCULATION PROGRAM\n");
    printf("===========================\n");
    calculatePostfix(postfixExpr);
    return 0;
}