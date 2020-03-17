#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (atol(argv[1]) != 0)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        bool repeat = false, invalid = false;
        int i = 0, j;
        while (i < 26)
        {
            if (isalpha(argv[1][i]) == false)
            {
                invalid = true;
                break;
            }
            i++;

        }
        for (i = 0; i < 26; i++)
        {
            for (j = i + 1; j < 26; j++)
            {
                if (tolower(argv[1][i]) == tolower(argv[1][j]))
                {
                    repeat = true;
                    break;
                }
            }
        }
        if (invalid)
        {
            printf("invalid charecter inside string\n");
            return 1;
        }
        else if (repeat)
        {
            printf("repeated charecter inside string\n");
            return 1;
        }
        else
        {
            string text = get_string("plaintext:  ");
            for (i = 0; i < strlen(text); i++)
            {
                if (isalpha(text[i]))
                {
                    if (isupper(text[i]))
                    {
                        text[i] = toupper(argv[1][(int)text[i] - 65]);
                    }
                    else
                    {
                        text[i] = tolower(argv[1][(int)text[i] - 97]);
                    }
                }
                else
                {
                    text[i] = text[i];
                }
            }
            printf("ciphertext:  ");
            for (i = 0; i < strlen(text); i++)  //printing the cipher text
            {
                printf("%c", text[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
