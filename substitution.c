#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])  //take the command line argument
{
    if (argc != 2) //if more or less than 2 arguments(including ./substitution) passed then print this as per instruction
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (atol(argv[1]) != 0)  //if any integer value or charecter(starts from int) passed
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)  //if the length of the passed string is not equal to 26 then encryption will not be possible
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        bool repeat = false, invalid = false;  //for checking repeated value or invalid element(non alphabet) inside the string
        int i = 0, j;
        while (i < 26)
        {
            if (isalpha(argv[1][i]) ==
                false)  //if invalid(non alphabet) exists inside the string then turn the bool invalid into true AND BREAK
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
                if (tolower(argv[1][i]) == tolower(
                        argv[1][j]))  //if any repeated alphabet found inside the string then turn the bool repeat into true AND BREAK
                {
                    repeat = true;
                    break;
                }
            }
        }
        if (invalid)  //if invalid is true then print this and return 1 as per instructed
        {
            printf("invalid charecter inside string\n");
            return 1;
        }
        else if (repeat)  //else if repeat is true then print this and return 1 as per instructed
        {
            printf("repeated charecter inside string\n");
            return 1;
        }
        else
        {
            string text = get_string("plaintext:  ");  //if the all before statements satisfied then get the text from the user to be ciphered
            for (i = 0; i < strlen(text); i++)  //iterate over the length of the given text
            {
                if (isalpha(text[i]))
                {
                    if (isupper(text[i]))
                    {
                        text[i] = toupper(argv[1][(int)text[i] - 65]);  //if the text alphabet is uppercase then covert it into uppercase cipher text
                    }
                    else
                    {
                        text[i] = tolower(argv[1][(int)text[i] - 97]);  //if the text alphabet is lowercase then covert it into lowercase cipher text
                    }
                }
                else
                {
                    text[i] = text[i];  //if not alphabet keep unchanged
                }
            }
            printf("ciphertext:  ");
            for (i = 0; i < strlen(text); i++)  //print the cipher text
            {
                printf("%c", text[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
