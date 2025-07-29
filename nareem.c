
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 50

int rollDice() {
    return (rand() % 6) + 1; // Returns 1 to 6
}

int main() {
    int player1 = 0, player2 = 0;
    int turn = 1;
    int dice;

    srand(time(0));  // Seed random number generator

    printf("?? Welcome to Ludo Lite (2 Player Version) ??\n");
    printf("First to reach cell %d wins!\n\n", BOARD_SIZE);

    while (player1 < BOARD_SIZE && player2 < BOARD_SIZE) {
        printf("----------\n");

        if (turn % 2 == 1) {
            printf("Player 1's turn. Press Enter to roll dice...");
            getchar();
            dice = rollDice();
            printf("Player 1 rolled a %d!\n", dice);
            player1 += dice;
            if (player1 > BOARD_SIZE) player1 = BOARD_SIZE;
            printf("Player 1 is now at position %d\n", player1);
        } else {
            printf("Player 2's turn. Press Enter to roll dice...");
            getchar();
            dice = rollDice();
            printf("Player 2 rolled a %d!\n", dice);
            player2 += dice;
            if (player2 > BOARD_SIZE) player2 = BOARD_SIZE;
            printf("Player 2 is now at position %d\n", player2);
        }

        turn++;
    }

    printf("\n?? Game Over!\n");

    if (player1 >= BOARD_SIZE)
        printf("?? Player 1 Wins!\n");
    else
        printf("?? Player 2 Wins!\n");

    return 0;
}

