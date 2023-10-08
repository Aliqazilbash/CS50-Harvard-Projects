#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Get input text from the user
    string text = get_string("Text: ");

    // Initialize variables
    int letters = 0;
    int words = 1; // Assuming there's at least one word
    int sentences = 0;
    float L = 0;
    float S = 0;
    int index = 0;

    // Loop through the input text to calculate statistics
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
        else if (text[i] == ' ')
        {
            words++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    // Calculate the average number of letters and sentences per 100 words
    L = (float) letters / (float) words * 100;
    S = (float) sentences / (float) words * 100;

    // Calculate the Coleman-Liau index
    index = round(0.0588 * L - 0.296 * S - 15.8);

    // Determine the reading level and print the result
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
