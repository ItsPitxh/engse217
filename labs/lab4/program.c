#include <stdio.h>
#include <string.h>

#define MaxStack 40 // Maximum stack size

char infix1[80] = {"A+B*(C^D*E/F)-G"}; // Input infix expression
char OpSt[MaxStack]; // Operator stack
int SP = 0; // Stack pointer

// Push an operator onto the stack
void push(char oper) {
    if (SP == MaxStack) {
        printf("ERROR: STACK OVERFLOW!!!\n");
    } else {
        SP++;
        OpSt[SP] = oper;
    }
}

// Pop an operator from the stack
char pop() {
    if (SP != 0) {
        char oper = OpSt[SP];
        SP--;
        return oper;
    } else {
        printf("ERROR: STACK UNDERFLOW!!!\n");
        return '\0'; // Return null character for empty stack
    }
}

// Precedence of input operators
int precedenceIP(char oper) {
    switch (oper) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 4;
        default: return 0; // Invalid operator
    }
}

// Precedence of operators in the stack
int precedenceST(char oper) {
    switch (oper) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
        case '(': return 0;
        default: return 0; // Invalid operator
    }
}

// Convert infix to postfix
void infixTOpostfix(char infix2[80]) {
    int len = strlen(infix2);
    printf("INFIX: %s\n", infix2);
    printf("POSTFIX IS: ");

    for (int i = 0; i < len; i++) {
        char ch = infix2[i];

        if (strchr("+-*/^()", ch) == NULL) { // If operand
            printf("%c", ch);
        } else { // If operator
            if (ch == '(') {
                push(ch);
            } else if (ch == ')') {
                char temp = pop();
                while (temp != '(' && temp != '\0') {
                    printf("%c", temp);
                    temp = pop();
                }
            } else {
                while (SP != 0 && precedenceIP(ch) <= precedenceST(OpSt[SP])) {
                    printf("%c", pop());
                }
                push(ch);
            }
        }
    }

    // Pop remaining operators in the stack
    while (SP != 0) {
        printf("%c", pop());
    }
    printf("\n");
}

int main() {
    printf("INFIX to POSTFIX CONVERSION PROGRAM\n");
    infixTOpostfix(infix1);
    return 0;
}