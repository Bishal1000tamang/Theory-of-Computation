#include <stdio.h>
#include <string.h>

typedef enum { S0, S1, S2 } State;

char output(State s, char input) {
    switch (s) {
        case S0:
            return 'c';  // cannot determine yet
        case S1:  // last bit = 0
            if (input == '0') return 'a';  // 00
            else return 'c';               // 01
        case S2:  // last bit = 1
            if (input == '1') return 'b';  // 11
            else return 'c';               // 10
    }
    return 'c';
}

int main() {
    char str[200];
    printf("Enter binary input string: ");
    scanf("%s", str);

    State s = S0;

    for (int i = 0; i < strlen(str); i++) {
        char in = str[i];
        char out = output(s, in);

        printf("Input: %c -> Output: %c\n", in, out);

        // state transitions
        if (in == '0') s = S1;
        else s = S2;
    }

    return 0;
}
