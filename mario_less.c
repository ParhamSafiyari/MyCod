<<<<<<< HEAD
#include <cs50.h>
#include <stdio.h>

void print_row(int n, int bricks);

int main(void)
{
    // Prompt the user for the pyramid's height
    int n;

    do
    {
        n = get_int("Height: ");
    }
    while(n < 1);

    // Print a pyramid of that height
    for(int i = 0; i < n; i++){
        // Print each row
        print_row(n, i + 1);
    }
}

void print_row(int height, int bricks)
{
    // Print spaces
    for (int i = 0; i < height - bricks; i++) {
        printf(" ");
    }

    // Print bricks
    for (int j = 0; j < bricks; j++) {
        printf("#");
    }

    // Move to the next line
    printf("\n");
}
=======
#include <cs50.h>
#include <stdio.h>

void print_row(int n, int bricks);

int main(void)
{
    // Prompt the user for the pyramid's height
    int n;

    do
    {
        n = get_int("Height: ");
    }
    while(n < 1);

    // Print a pyramid of that height
    for(int i = 0; i < n; i++){
        // Print each row
        print_row(n, i + 1);
    }
}

void print_row(int height, int bricks)
{
    // Print spaces
    for (int i = 0; i < height - bricks; i++) {
        printf(" ");
    }

    // Print bricks
    for (int j = 0; j < bricks; j++) {
        printf("#");
    }

    // Move to the next line
    printf("\n");
}
>>>>>>> 331be110160c0baa747b3938e9eec3ed03011ad6
