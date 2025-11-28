#include <stdio.h>
#include <string.h>

typedef enum {
    S0, S1, S2, S3, S4, S5
} State;

char output(State s) {
    switch (s) {
        case S4: return 'a';   // detected 101
        case S5: return 'b';   // detected 110
        default: return 'c';
    }
}

int main() {
    char input[200];
    printf("Enter binary string: ");
    scanf("%s", input);

    State state = S0;

    for (int i = 0; i < strlen(input); i++) {
        char bit = input[i];

        switch (state) {
            case S0:
                state = (bit == '1') ? S1 : S0;
                break;

            case S1:
                state = (bit == '1') ? S3 : S2;
                break;

            case S2:
                if (bit == '1') state = S4;  // 101 detected
                else state = S0;
                break;

            case S3:
                if (bit == '0') state = S5;  // 110 detected
                else state = S3;
                break;

            case S4:
                state = S4;  // stay after detect 101
                break;

            case S5:
                state = S5;  // stay after detect 110
                break;
        }
    }

    printf("Final output = %c\n", output(state));
    return 0;
}
