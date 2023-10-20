#include <stdio.h>
#include <string.h>

int S(char* str);

int main() {
    char input[100];
    
    printf("Enter a string: ");
    scanf("%s", input);

    if (S(input) == 1) {
        printf("The string is in the language defined by the CFG.\n");
    } else {
        printf("The string is not in the language defined by the CFG.\n");
    }
    
    return 0;
}

int S(char* str) {
    if (str[0] == '0' && str[strlen(str) - 1] == '1') {
        if (strlen(str) == 2) {
            return 1; // Matches '01'
        } else {
            return S(str + 1); // Check the inner part
        }
    } else if (strlen(str) == 0) {
        return 1; // Empty string (epsilon)
    }
    return 0; // Not part of the language
}
