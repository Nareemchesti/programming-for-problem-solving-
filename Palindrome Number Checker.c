#include <stdio.h>

int main() {
    int num, original, reversed = 0, rem;

    printf("Enter a number: ");
    scanf("%d", &num);

    original = num;

    while (num != 0) {
        rem = num % 10;
        reversed = reversed * 10 + rem;
        num /= 10;
    }

    if (original == reversed)
        printf("%d is a palindrome.\n", original);
    else
        printf("%d is not a palindrome.\n", original);

    return 0;
}

