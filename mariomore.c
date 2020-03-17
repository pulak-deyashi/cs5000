#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n, i, j, c;
    do
    {
        n = get_int("Height: ");    //Get the height from the user
    }
    while(n<1 || n>8);
    c = n;
    while(n > 0)
    {
        for(i=0; i<n-1; i++) //loop for printing the spaces
        {
            printf(" ");
        }
        for(i=0; i<=c-n; i++) //loop for printing reverse hashes
        {
            printf("#");
        }
        printf("  ");    //Space in the middle
        for(i=0; i<=c-n; i++) //loop for printing forward hashes
        {
            printf("#");
        }
        printf("\n");
        n -= 1;
    }
}
