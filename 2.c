#include <stdio.h>

int isAccepted(char str[]) {
    int currentState = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (currentState == 0 && str[i] == '0') {
            currentState = 1;
        } else if (currentState == 1 && str[i] == '1') {
            currentState = 2;
        } else {
            currentState = -1;
        }

        i++;
    }

    return currentState == 2;
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    if (isAccepted(str)) {
        printf("String accepted\n");
    } else {
        printf("String not accepted\n");
    }

    return 0;
}

