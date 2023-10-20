#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Define the states
#define STATE_INITIAL 0
#define STATE_ACCEPT 1

int main() {
    char input[100];
    int state = STATE_INITIAL;

    printf("Enter a string: ");
    scanf("%s", input);

    for (int i = 0; i < strlen(input); i++) {
        char current_char = input[i];

        if (state == STATE_INITIAL) {
            if (current_char == 'o') {
                state = STATE_ACCEPT;
            }
        } else if (state == STATE_ACCEPT) {
            if (current_char == '1') {
                state = STATE_INITIAL;
            }
        }
    }

    bool isAccepted = (state == STATE_INITIAL);

    if (isAccepted) {
        printf("The string is accepted.\n");
    } else {
        printf("The string is not accepted.\n");
    }

    return 0;
}
