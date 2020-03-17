#include <cs50.h>
#include <stdio.h>

int main(void)
{
   int h, i, l;
   do
   {
       h = get_int("Height: ");     // Take the height between 1 and 8, both inclusive
   }
   while(h < 1 || h > 8);
   l = h;
   
   while(h > 0)
   {
       for(i = 1; i < h; i++)       // iteration for printing the spaces
       {      
           printf(" ");
       }
       
       for(i = 0; i <= l-h; i++)   // iteration for printing the hashes 
       {
           printf("#");
       }
       
       printf("\n");                // go to a new line
       h -= 1;
   }
}
