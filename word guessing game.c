#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char words[][10] = {"apple","banana","orange","grape","mango"};
    char hints[][50] = {
        "Keeps the doctor away",
        "A yellow curved fruit",
        "A citrus fruit",
        "Small and grows in bunches",
        "King of fruits"
    };
    srand(time(0));
    int index = rand() % 5;
    char word[10], guess;
    strcpy(word, words[index]);
    int len = strlen(word), attempts = 6, wrong = 0, correct = 0;
    int guessed[26] = {0};
    printf("Welcome to the Word Guessing Game!\n");
    for (int i = 0; i < len; i++) printf("_ ");
    printf("\n");
    while (attempts > 0) {
        printf("Enter a letter: ");
        scanf(" %c", &guess);
        if (guess < 'a' || guess > 'z') {
            printf("Invalid input.\n");
            continue;
        }
        if (guessed[guess - 'a']) {
            printf("Already guessed.\n");
            continue;
        }
        guessed[guess - 'a'] = 1;
        int found = 0;
        for (int i = 0; i < len; i++) {
            if (word[i] == guess) {
                found = 1;
                correct++;
            }
        }
        if (!found) {
            wrong++;
            attempts--;
            printf("Wrong guess. Attempts left: %d\n", attempts);
            if (wrong == 3) printf("Hint: %s\n", hints[index]);
        }
        for (int i = 0; i < len; i++) {
            if (guessed[word[i] - 'a']) printf("%c ", word[i]);
            else printf("_ ");
        }
        printf("\n");
        if (correct == len) {
            printf("You win! The word was: %s\n", word);
            return 0;
        }
    }
    printf("You lose! The word was: %s\n", word);
    return 0;
}

