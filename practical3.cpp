#include <stdio.h>
#include <ctype.h>
#include <string.h>

// List of C keywords
const char *keywords[] = {
    "auto","break","case","char","const","continue","default","do","double",
    "else","enum","extern","float","for","goto","if","int","long",
    "register","return","short","signed","sizeof","static","struct",
    "switch","typedef","union","unsigned","void","volatile","while"
};

// Function to check if string is a C keyword
int isKeyword(char *str) {
    for (int i = 0; i < 32; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;   // true
    }
    return 0;
}

// Function to check if string is a valid C identifier
int isValidIdentifier(char *str) {
    // Check first character
    if (!(isalpha(str[0]) || str[0] == '_'))
        return 0;

    // Check rest of characters
    for (int i = 1; str[i] != '\0'; i++) {
        if (!(isalnum(str[i]) || str[i] == '_'))
            return 0;
    }

    return 1;
}

int main() {
    char str[50];

    printf("Enter a string: ");
    scanf("%s", str);

    if (isKeyword(str)) {
        printf("'%s' is a C keyword.\n", str);
    }
    else if (isValidIdentifier(str)) {
        printf("'%s' is a valid identifier.\n", str);
    }
    else {
        printf("'%s' is NOT a valid identifier.\n", str);
    }

    return 0;
}

