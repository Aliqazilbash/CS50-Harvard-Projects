#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Function to compute the score of a word
int compute_score(string word);

int main(void)
{
    string word1, word2;
    int score1, score2;

    // Get input words from both players
    word1 = get_string("Player 1: ");
    word2 = get_string("Player 2: ");

    // Score both words
    score1 = compute_score(word1);
    score2 = compute_score(word2);

    // Determine the winner and print the result
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
    return 0;
}

// Function to compute the score of a word
int compute_score(string word)
{
    int score = 0;
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        char letter = word[i];
        if (isupper(letter))
        {
            score += POINTS[letter - 'A'];
        }
        else if (islower(letter))
        {
            score += POINTS[letter - 'a'];
        }
    }
    return score;
}

