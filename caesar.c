#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string swap(string input);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    if (strlen(argv[1]) == 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int j = 0; j < strlen(argv[1]); j++)
    {
        if (!isdigit(argv[1][j]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]);
    string text = get_string("plain text: ");

    for (int i = 0; i < strlen(text); i++)
    {
        int currentKey = key;
        if (text[i] >= 65 && text[i] <= 90)
        {
            if (90 - currentKey < 65)
            {
                int alpha = text[i] - 65;
                int cypher = (alpha + currentKey) % 26;
                currentKey = cypher;
                text[i] = 'A' + currentKey;
            }
            else if (text[i] + currentKey > 90)
            {
                int alpha = text[i] - 65;
                int cypher = (alpha + currentKey) % 26;
                currentKey = cypher;
                text[i] = 'A' + currentKey;
            }
            else
            {
                text[i] = text[i] + currentKey;
            }
        }

        else if (text[i] >= 97 && text[i] <= 122)
        {
            if (122 - currentKey < 96)
            {
                int alpha = text[i] - 97;
                int cypher = (alpha + currentKey) % 26;
                currentKey = cypher;
                text[i] = 'a' + currentKey;
            }
            else if (text[i] + currentKey > 122)
            {
                int alpha = text[i] - 97;
                int cypher = (alpha + currentKey) % 26;
                currentKey = cypher;
                text[i] = 'a' + currentKey;
            }
            else
            {
                text[i] = text[i] + currentKey;
            }
        }
    }

    printf("ciphertext: %s\n", text);
    return 0;
}
