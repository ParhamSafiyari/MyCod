#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points array for each letter (Scrabble scoring)
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Function to compute the score of a word
int compute_score(string word)
{
    int score = 0;

    // Iterate through each character in the word
    for (int i = 0; word[i] != '\0'; i++)
    {
        // Convert character to uppercase to simplify scoring
        char letter = toupper(word[i]);

        // Check if character is a letter
        if (letter >= 'A' && letter <= 'Z')
        {
            // Calculate score by subtracting 'A' to get index
            score += POINTS[letter - 'A'];
        }
    }

    return score;
}

int main(void)
{
    // Get words from players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Compute scores
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Determine and print winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;
}
