#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
//#include <math.h>
int main(void)
{
    int letter = 0, word = 0, sentence = 0; //assign the variables for counting letters, words, sentences
    string text = get_string("Text: "); //get the string
    for (int i = 0; i < strlen(text); i++) //iterate over the length of the string OR FOR EXCLUDING string.h USE i != '\0'
    {
        if (tolower(text[i]) >= 'a'
            && tolower(text[i]) <= 'z') //make the elements lower case AND check whether it belongs to alphabet or not
            //then count for letters
        {
            letter++;
        }
        if (i == 0 || text[i - 1] == ' ') //before every word there is a space except the first word
            //count for words
        {
            word++;
        }
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') //check how many sentence terminating symbols exists
            //count that many sentences
        {
            sentence++;
        }
    }
    //printf("%d %d %d\n", letter, word, sentence); //FOR DEBUGGING
    float L = (letter * 100) / (float) word; //calculating the average number of letters per 100 WORDS
    float S = (sentence * 100) / (float) word; //calculating the average number of sentences per 100 WORDS

    //printf("%f %f\n", L, S); //FOR DEBUGGING

    float index = 0.0588 * L - 0.296 * S - 15.8; //calculating the index according ||Coleman-Liau|| formula
    //printf("%.0f\n", round(index)); //FOR DEBUGGING
    //as per the value of index calculating and displaying the suitable GRADES
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", index);
    }

}
