#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char words[][6] = {"apple", "mango", "grape", "pearl", "lemon"};
    char display[] = "_ _ _ _ _";
    char guess;
    int attempts = 6;
    int correct = 0;
    int guessed[26] = {0};
    int i, found, index;

    srand(time(0));
    index = rand() % 5;
    char *word = words[index];

    printf("Welcome to the Word Guessing Game!\n");
    printf("%s\n", display);

    while (attempts > 0 && correct < 5) {
        printf("Enter a letter: ");
        scanf(" %c", &guess);

        if (guess < 'a' || guess > 'z') {
            printf("Invalid input. Please enter a lowercase letter.\n");
            continue;
        }

        if (guessed[guess - 'a']) {
            printf("You already guessed that letter.\n");
            continue;
        }

        guessed[guess - 'a'] = 1;
        found = 0;

        for (i = 0; i < 5; i++) {
            if (word[i] == guess && display[i * 2] == '_') {
                display[i * 2] = guess;
                correct++;
                found = 1;
            }
        }

        if (!found) {
            attempts--;
            printf("Wrong guess! Attempts left: %d\n", attempts);
        }

        printf("%s\n", display);
    }

    if (correct == 5)
        printf("You win! The word was: %s\n", word);
    else
        printf("You lose! The word was: %s\n", word);

    return 0;
}

