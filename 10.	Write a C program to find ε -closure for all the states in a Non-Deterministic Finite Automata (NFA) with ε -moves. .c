#include <stdio.h>
#include <stdbool.h>

#define MAX_STATES 10

int n; // Number of states
bool epsilonTransitions[MAX_STATES][MAX_STATES];

// Function to compute ε-closure for a state
void epsilonClosure(int state, bool visited[]) {
    visited[state] = true;
    
    for (int i = 0; i < n; i++) {
        if (epsilonTransitions[state][i] && !visited[i]) {
            epsilonClosure(i, visited);
        }
    }
}

int main() {
    printf("Enter the number of states: ");
    scanf("%d", &n);

    // Initialize epsilonTransitions matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            epsilonTransitions[i][j] = false;
        }
    }

    printf("Enter epsilon transitions (0/1 for no/yes):\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("ε-transition from state %d to state %d: ", i, j);
            int input;
            scanf("%d", &input);
            epsilonTransitions[i][j] = (input == 1);
        }
    }

    // Compute and print ε-closure for each state
    printf("Epsilon Closures:\n");

    for (int i = 0; i < n; i++) {
        bool visited[MAX_STATES] = {false};
        epsilonClosure(i, visited);

        printf("ε-closure(state %d) = {", i);
        for (int j = 0; j < n; j++) {
            if (visited[j]) {
                printf("state %d, ", j);
            }
        }
        printf("}\n");
    }

    return 0;
}
