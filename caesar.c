#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else if(atol(argv[1]) == 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        int n = atol(argv[1]);
        int i, c = n;
        for (i = 0; c != 0  ; i++)
        {
            c /= 10;
        }
        if (i != strlen(argv[1]))
        {
            printf("Usage: ./caesar key\n");
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
                        text[i] = (char) (65 + ((((int) (text[i])) - 65 + n) % 26));
                    }
                    else
                    {
                        text[i] = (char) (97 + ((((int) (text[i])) - 97 + n) % 26));
                    }

                }
                else
                {
                    text[i] = text[i];
                }
            }
            printf("ciphertext:  ");
            for (i = 0; i < strlen(text); i++)
            {
                printf("%c", text[i]);
            }
            printf("\n");
        }

    }

}
