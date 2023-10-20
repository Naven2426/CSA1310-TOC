#include <stdio.h>

// Define the states
#define STATE_INITIAL 0
#define STATE_ACCEPT 1

int main() {
    char input[100];
    int state = STATE_INITIAL;

    printf("Enter a string: ");
    scanf("%s", input);

    for (int i = 0; input[i] != '\0'; i++) {
        if (state == STATE_INITIAL) {
            if (input[i] == 'b') {
                state = STATE_ACCEPT;
            }
        } else if (state == STATE_ACCEPT) {
            if (input[i] == 'a') {
                state = STATE_INITIAL;
            }
        }
    }

    if (state == STATE_INITIAL) {
        printf("The string is accepted.\n");
    } else {
        printf("The string is not accepted.\n");
    }

    return 0;
}
