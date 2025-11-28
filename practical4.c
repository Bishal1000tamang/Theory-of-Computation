#include <stdio.h>
#include <string.h>

#define MAX 100

// Stack implementation
char stack[MAX];
int top = -1;

// Push to stack
void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    } else {
        printf("Stack overflow\n");
    }
}

// Pop from stack
char pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        return '\0'; // Stack empty
    }
}

// Peek top of stack
char peek() {
    if (top >= 0) return stack[top];
    return '\0';
}

// PDA simulation
int pda_accept(char input[]) {
    int i;
    char symbol, top_symbol;

    // Initialize stack with Z0
    push('Z');  // Z0 represented as 'Z'

    for (i = 0; i < strlen(input); i++) {
        symbol = input[i];
        top_symbol = peek();

        if (symbol == '0') {
            if (top_symbol == '1') {
                pop(); // cancel out
            } else {
                push('0');
            }
        } else if (symbol == '1') {
            if (top_symbol == '0') {
                pop(); // cancel out
            } else {
                push('1');
            }
        } else {
            printf("Invalid symbol in input.\n");
            return 0; // reject
        }
    }

    // Accept if only Z0 remains in stack
    if (top == 0 && stack[top] == 'Z') {
        return 1; // accepted
    } else {
        return 0; // rejected
    }
}
int main() {
    char input[100];

    printf("Enter a string over {0,1}: ");
    scanf("%s", input);

    if (pda_accept(input)) {
        printf("String accepted by PDA.\n");
    } else {
        printf("String rejected by PDA.\n");
    }

    return 0;
}
