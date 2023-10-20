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
    if (str[0] == '0' || str[0] == '1') {
        int i = 1;
        int len = strlen(str);
        while (i < len - 2) {
            if (str[i] == '0' || str[i] == '1') {
                int result = A(str + i);
                if (result == 1 && str[i + 1] == '0' && str[i + 2] == '1') {
                    return 1;
                }
            }
            i++;
        }
    }
    return 0;
}

int A(char* str) {
    if (str[0] == '0' || str[0] == '1') {
        int result = A(str + 1);
        return result;
    } else if (str[0] == '\0') {
        return 1; // A derives epsilon
    }
    return 0;
}
