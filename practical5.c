#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char input[MAX];
    char stack[MAX];
    int top = -1;        // stack pointer
    int state = 0;       // q0 = 0, q1 = 1

    printf("Enter a string of 0s followed by 1s: ");
    scanf("%s", input);

    int len = strlen(input);

    // Initial stack symbol Z0
    stack[++top] = 'Z';

    for (int i = 0; i < len; i++) {
        char ch = input[i];

        if (state == 0) {               // q0: reading 0's
            if (ch == '0') {
                stack[++top] = 'X';     // push X for each 0
            }
            else if (ch == '1') {
                if (stack[top] == 'X') {
                    top--;              // pop X
                    state = 1;          // move to q1
                } else {
                    printf("Rejected\n");
                    return 0;
                }
            } 
            else {
                printf("Rejected\n");
                return 0;
            }
        }

        else if (state == 1) {          // q1: reading 1's only
            if (ch == '1') {
                if (stack[top] == 'X') {
                    top--;              // pop X for each 1
                } else {
                    printf("Rejected\n");
                    return 0;
                }
            }
            else {                       // 0 not allowed in q1
                printf("Rejected\n");
                return 0;
            }
        }
    }

    // Accept by final state: must be in q1 and stack has only Z0
    if (state == 1 && top == 0 && stack[top] == 'Z') {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }

    return 0;
}
