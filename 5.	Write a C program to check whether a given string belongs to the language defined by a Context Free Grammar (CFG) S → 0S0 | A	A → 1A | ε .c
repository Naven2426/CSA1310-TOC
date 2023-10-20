#include <stdio.h>
#include <string.h>

int S(char* str);
int A(char* str);

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
    if (str[0] == '0') {
        int i = 1;
        int len = strlen(str);
        while (i < len - 1) {
            if (str[i] == '0') {
                int result = S(str + i);
                if (result == 1) {
                    return 1;
                }
            }
            i++;
        }
    } else if (str[0] == 'A') {
        int result = A(str + 1);
        if (result == 1) {
            return 1;
        }
    }
    return 0;
}

int A(char* str) {
    if (str[0] == '1') {
        int result = A(str + 1);
        if (result == 1) {
            return 1;
        }
    } else if (str[0] == '\0') {
        return 1; // A derives epsilon
    }
    return 0;
}
