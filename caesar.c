#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//take command line argument
int main(int argc, string argv[])  
{
    //show |Usage: ./caesar key| message if extra arguments passed(as per problem statement)
    if (argc != 2) 
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //if any non numeric value such as abcd/y67t/s888 passed then |string to int conv. function| such as atoi/atol/atoll returns 0
    else if (atol(argv[1]) ==  0) 
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
        //if non numeric value which starts from numeric value(such as 23bb/6hgdtst/78fh) then atoi/atol/atoll returns the first integer value
    {
        int n = atol(argv[1]);
        int i, c = n;
        for (i = 0; c != 0  ; i++)
        {
            c /= 10;
        }
        //here we are checking whether the num of digits in the integer is equal to the length of string value TO CHECK WHETHER PURE INTEGER VALUE PASSED OR NOT
        if (i != strlen(argv[1]))  
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        else
        {
            string text = get_string("plaintext:  ");  //taking the text to be ciphered
            for (i = 0; i < strlen(text); i++)  //iterating over the length of the text
            {
                if (isalpha(text[i]))  //checking whether the element is alphabet or not
                {
                    if (isupper(text[i])) //ASCII value of upper case letters starts from 65 ||ci = (pi + k)%26||
                    {
                        text[i] = (char)(65 + ((((int)(text[i])) - 65 + n) % 26));
                    }
                    else  //ASCII value of upper case letters starts from 97 ||ci = (pi + k)%26||
                    {
                        text[i] = (char)(97 + ((((int)(text[i])) - 97 + n) % 26));
                    }

                }
                else  //if the element is not a text then keeping it unchanged
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

