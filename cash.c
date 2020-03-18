#include<cs50.h>
#include<math.h>
#include<stdio.h>

int main(void)
{
    float dollers;
    int i=0;   //Declare variable for counting the number of coins needed
    do
    {
        dollers = get_float("Change owed: ");  // Get non negetive change value
    }
    while(dollers < 0);
    int coins = round(dollers * 100);    // Round the float to integer
    while(coins > 0)
    {
       if(coins >= 25)     //check while greater than 25
       {
           coins -= 25;
           i++;
       }
       else if(coins >= 10)    //check whether greater than 10
       {
           coins -= 10;
           i++;
       }
       else if(coins >= 5)    //check whether grearher than 5
       {
           coins -= 5;
           i++;
       }
       else    //check for the rest 1
       {
           coins -= 1;
           i++;
       }
               
    }
    printf("%d\n", i);    //print the number of coins needed
}
© 2020 GitHub, Inc.
