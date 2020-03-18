#include<cs50.h>
#include<stdio.h>
#include<math.h>

int main(void)
{
    long n = get_long("Number: ");    //get the number
    int i = 0, r, o = 0, e = 0;
    long c;
    c = n;                            //copy the number to a seperate variable
    while (c > 0)                     //count the number of digits using while loop
    {
        c /= 10;
        i++;
    }                          
    if (i == 13 || i == 15 || i == 16)        //check for valid number of digits
    {
        r = round(n / 1000000000000);
        while (n > 0)
        {
            o += (n % 10);                //take the sum of digits in the second-to-first position
            n = round(n / 10);
            e += ((((n % 10) * 2) % 10) + (round(((n % 10) * 2) / 
                                                 10))); //multiply the digits in the second-to-last position by two and break them into two separate digits if the product is more than 9, then add all the digits
            n = round(n / 10);
        }
        if ((o + e) % 10 == 0)   //check whether the sum of the sum holds 0 in the last position
        {
            if ((i == 13 && r == 4) || (i == 16 && (r / 1000) == 4))  //if given condition satisfied print VISA
            {
                printf("VISA\n");
            }
            else if (i == 15 && (r / 10 == 34 || r / 10 == 37))  //if given condition satisfied print AMEX
            {
                printf("AMEX\n");
            }
            else if (i == 16 && (r / 100 == 51 || r / 100 == 52 || r / 100 == 53 || r / 100 == 54
                                 || r / 100 == 55)) //if given condition satisfied print MASTERCARD
            {
                printf("MASTERCARD\n");
            }
            else             // if none of the above condition satisfied then print INVALID
            {
                printf("INVALID\n");
            }
        }
        else        //if the initial condition ((o + e)%10 == 0) not satisfied print INVALID
        {
            printf("INVALID\n");
        }
    }
    else        //if the initial condition (i == 13 || i == 15 || i == 16) not satisfied, print INVALID
    {
        printf("INVALID\n");
    }
}
