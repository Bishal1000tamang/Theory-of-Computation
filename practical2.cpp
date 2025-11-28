#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int state = 0;  // start state

    printf("Enter a binary string: ");
    scanf("%s", str);

    for (int i = 0; i < strlen(str); i++) {
        char c = str[i];

        switch(state) {
            case 0: // start
                if (c == '0') state = 1;
                else state = 0;  // dead
                break;

            case 1: // seen "0"
                if (c == '0') state = 2; // ACCEPT
                else state = 0; // dead
                break;

            case 2: // ACCEPT state (string starts with 01)
                if (c == '1')
                    state = 3;
				else
					state =1; // remain in accept (anything allowed)
                break;
			case 3: // ACCEPT state (string starts with 01)
                
                    state = 3;
                break;

            
        }
    }

    if (state == 3)
        printf("String is ACCEPTED \n");
    else
        printf("String is REJECTED\n");

    return 0;
}
