#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int val;
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            //rounding the average value
            val = round((float)(image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3);
            ////inserting the rounded average value to the corrosponding pixels
            image[i][j].rgbtBlue = val;
            image[i][j].rgbtGreen = val;
            image[i][j].rgbtRed = val;


        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            //extracting the pixel values to seperate varialbles
            int r = image[i][j].rgbtRed;
            int g = image[i][j].rgbtGreen;
            int b = image[i][j].rgbtBlue;
            //calculationg the new pixel values as INSTRUCTED
            int sr = round(.393 * r + .769 * g + .189 * b);
            int sg = round(.349 * r + .686 * g + .168 * b);
            int sb = round(.272 * r + .534 * g + .131 * b);
            //if the new exceeds the maximum value then inserting the max value to the corrosponding pixel
            if(sr < 255) image[i][j].rgbtRed = sr;
            else image[i][j].rgbtRed = 255;
            if(sg < 255) image[i][j].rgbtGreen = sg;
            else image[i][j].rgbtGreen = 255;
            if(sb < 255) image[i][j].rgbtBlue = sb;
            else image[i][j].rgbtBlue = 255;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int w = width / 2;
    //declared a normal int array of length 3
    int arr[3];
    //iteratting over half length of width as REFLECTING THE IMAGE HORIZONTALLY
    for(int i = 0; i < w; i++)
    {
        for(int j = 0; j < height; j++)
        {

            //using the int array swaping the pixel values of every opposite pixels(mirror opposite)
            arr[0] = image[j][i].rgbtRed;
            arr[1] = image[j][i].rgbtGreen;
            arr[2] = image[j][i].rgbtBlue;
            image[j][i].rgbtRed = image[j][width - 1 - i].rgbtRed;
            image[j][i].rgbtGreen = image[j][width - 1 - i].rgbtGreen;
            image[j][i].rgbtBlue = image[j][width - 1 - i].rgbtBlue;
            image[j][width - 1 - i].rgbtRed = arr[0];
            image[j][width - 1 - i].rgbtGreen = arr[1];
            image[j][width - 1 - i].rgbtBlue = arr[2];
        }

    }
    //alternate way but less memory efficient
    /*RGBTRIPLE temp_image[height];
    for(int i = 0; i < w; i++)
    {
        for(int j = 0; j < height; j++)
        {
            temp_image[j].rgbtRed = image[j][i].rgbtRed;
            temp_image[j].rgbtGreen = image[j][i].rgbtGreen;
            temp_image[j].rgbtBlue = image[j][i].rgbtBlue;
            image[j][i].rgbtRed = image[j][width - 1 - i].rgbtRed;
            image[j][i].rgbtGreen = image[j][width - 1 - i].rgbtGreen;
            image[j][i].rgbtBlue = image[j][width - 1 - i].rgbtBlue;
            image[j][width - 1 - i].rgbtRed = temp_image[j].rgbtRed;
            image[j][width - 1 - i].rgbtGreen = temp_image[j].rgbtGreen;
            image[j][width - 1 - i].rgbtBlue = temp_image[j].rgbtBlue;
        }
    }*/
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    ////here we are going to use "box blur" method
    int i = 0, j = 0;
    //created a temprary image variable of type RGBTRIPLE
    RGBTRIPLE timage[height][width];
    //copying the values of image variable in temporary image variable
    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            timage[i][j].rgbtRed = image[i][j].rgbtRed;
            timage[i][j].rgbtGreen = image[i][j].rgbtGreen;
            timage[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }
    //making i and j of value 0, 0 for next steps
    i = 0;
    j = 0;
    //declaring h1, w1 for iterating over the middle pixels which are bounded by 8 indivisual pixels
    int w1 = width - 1;
    int h1 = height - 1;
    //sum variables
    int sumR, sumG, sumB;
    //average variables
    int avgR, avgG, avgB;
    //code for upper-left CORNER pixel, bounded by 3 indivisual pixels
    sumR = timage[i+1][j].rgbtRed + timage[i][j].rgbtRed + timage[i+1][j+1].rgbtRed + timage[i][j+1].rgbtRed;
    sumG = timage[i+1][j].rgbtGreen + timage[i][j].rgbtGreen + timage[i+1][j+1].rgbtGreen + timage[i][j+1].rgbtGreen;
    sumB = timage[i+1][j].rgbtBlue + timage[i][j].rgbtBlue + timage[i+1][j+1].rgbtBlue + timage[i][j+1].rgbtBlue;
    avgR = round((float)sumR / 4);
    avgG = round((float)sumG / 4);
    avgB = round((float)sumB / 4);
    image[i][j].rgbtRed = avgR;
    image[i][j].rgbtGreen = avgG;
    image[i][j].rgbtBlue = avgB;
    //code for upper EDGE pixelS, each bounded by 5 indivisual pixels
    for(j = 1; j < w1; j++)
    {
        sumR = timage[i+1][j-1].rgbtRed + timage[i][j-1].rgbtRed + timage[i+1][j].rgbtRed + timage[i][j].rgbtRed + timage[i+1][j+1].rgbtRed + timage[i][j+1].rgbtRed;
        sumG = timage[i+1][j-1].rgbtGreen + timage[i][j-1].rgbtGreen + timage[i+1][j].rgbtGreen + timage[i][j].rgbtGreen + timage[i+1][j+1].rgbtGreen + timage[i][j+1].rgbtGreen;
        sumB = timage[i+1][j-1].rgbtBlue + timage[i][j-1].rgbtBlue + timage[i+1][j].rgbtBlue + timage[i][j].rgbtBlue + timage[i+1][j+1].rgbtBlue + timage[i][j+1].rgbtBlue;
        avgR = round((float)sumR / 6);
        avgG = round((float)sumG / 6);
        avgB = round((float)sumB / 6);
        image[i][j].rgbtRed = avgR;
        image[i][j].rgbtGreen = avgG;
        image[i][j].rgbtBlue = avgB;
    }
    //code for upper-right CORNER pixel, bounded by 3 indivisual pixels
    sumR = timage[i+1][j-1].rgbtRed + timage[i][j-1].rgbtRed + timage[i+1][j].rgbtRed + timage[i][j].rgbtRed;
    sumG = timage[i+1][j-1].rgbtGreen + timage[i][j-1].rgbtGreen + timage[i+1][j].rgbtGreen + timage[i][j].rgbtGreen;
    sumB = timage[i+1][j-1].rgbtBlue + timage[i][j-1].rgbtBlue + timage[i+1][j].rgbtBlue + timage[i][j].rgbtBlue;
    avgR = round((float)sumR / 4);
    avgG = round((float)sumG / 4);
    avgB = round((float)sumB / 4);
    image[i][j].rgbtRed = avgR;
    image[i][j].rgbtGreen = avgG;
    image[i][j].rgbtBlue = avgB;
    //code for all-MIDDLE pixels
    for(i = 1; i < h1; i++)
    {
        j = 0;
        //code for right EDGE pixelS, each bounded by 5 indivisual pixels
        sumR = timage[i-1][j+1].rgbtRed + timage[i-1][j].rgbtRed + timage[i][j+1].rgbtRed + timage[i][j].rgbtRed + timage[i+1][j+1].rgbtRed + timage[i+1][j].rgbtRed;
        sumG = timage[i-1][j+1].rgbtGreen + timage[i-1][j].rgbtGreen + timage[i][j+1].rgbtGreen + timage[i][j].rgbtGreen + timage[i+1][j+1].rgbtGreen + timage[i+1][j].rgbtGreen;
        sumB = timage[i-1][j+1].rgbtBlue + timage[i-1][j].rgbtBlue + timage[i][j+1].rgbtBlue + timage[i][j].rgbtBlue + timage[i+1][j+1].rgbtBlue + timage[i+1][j].rgbtBlue;
        avgR = round((float)sumR / 6);
        avgG = round((float)sumG / 6);
        avgB = round((float)sumB / 6);
        image[i][j].rgbtRed = avgR;
        image[i][j].rgbtGreen = avgG;
        image[i][j].rgbtBlue = avgB;
        //code for MIDDLE pixels, each bounded by 8 indivisual pixels
        for(j = 1; j < w1; j++)
        {
            sumR = timage[i-1][j-1].rgbtRed + timage[i][j-1].rgbtRed + timage[i+1][j-1].rgbtRed + timage[i-1][j].rgbtRed + timage[i][j].rgbtRed + timage[i+1][j].rgbtRed + timage[i-1][j+1].rgbtRed + timage[i][j+1].rgbtRed + timage[i+1][j+1].rgbtRed;
            sumG = timage[i-1][j-1].rgbtGreen + timage[i][j-1].rgbtGreen + timage[i+1][j-1].rgbtGreen + timage[i-1][j].rgbtGreen + timage[i][j].rgbtGreen + timage[i+1][j].rgbtGreen + timage[i-1][j+1].rgbtGreen + timage[i][j+1].rgbtGreen + timage[i+1][j+1].rgbtGreen;
            sumB = timage[i-1][j-1].rgbtBlue + timage[i][j-1].rgbtBlue + timage[i+1][j-1].rgbtBlue + timage[i-1][j].rgbtBlue + timage[i][j].rgbtBlue + timage[i+1][j].rgbtBlue + timage[i-1][j+1].rgbtBlue + timage[i][j+1].rgbtBlue + timage[i+1][j+1].rgbtBlue;
            avgR = round((float)sumR / 9);
            avgG = round((float)sumG / 9);
            avgB = round((float)sumB / 9);
            image[i][j].rgbtRed = avgR;
            image[i][j].rgbtGreen = avgG;
            image[i][j].rgbtBlue = avgB;
        }
        //code for left CORNER pixelS, each bounded by 5 indivisual pixels
        sumR = timage[i-1][j-1].rgbtRed + timage[i-1][j].rgbtRed + timage[i][j-1].rgbtRed + timage[i][j].rgbtRed + timage[i+1][j-1].rgbtRed + timage[i+1][j].rgbtRed;
        sumG = timage[i-1][j-1].rgbtGreen + timage[i-1][j].rgbtGreen + timage[i][j-1].rgbtGreen + timage[i][j].rgbtGreen + timage[i+1][j-1].rgbtGreen + timage[i+1][j].rgbtGreen;
        sumB = timage[i-1][j-1].rgbtBlue + timage[i-1][j].rgbtBlue + timage[i][j-1].rgbtBlue + timage[i][j].rgbtBlue + timage[i+1][j-1].rgbtBlue + timage[i+1][j].rgbtBlue;
        avgR = round((float)sumR / 6);
        avgG = round((float)sumG / 6);
        avgB = round((float)sumB / 6);
        image[i][j].rgbtRed = avgR;
        image[i][j].rgbtGreen = avgG;
        image[i][j].rgbtBlue = avgB;
    }
    j = 0;
    //code for lower-left CORNER pixel, bounded by 3 indivisual pixels
    sumR = timage[i-1][j+1].rgbtRed + timage[i][j+1].rgbtRed + timage[i-1][j].rgbtRed + timage[i][j].rgbtRed;
    sumG = timage[i-1][j+1].rgbtGreen + timage[i][j+1].rgbtGreen + timage[i-1][j].rgbtGreen + timage[i][j].rgbtGreen;
    sumB = timage[i-1][j+1].rgbtBlue + timage[i][j+1].rgbtBlue + timage[i-1][j].rgbtBlue + timage[i][j].rgbtBlue;
    avgR = round((float)sumR / 4);
    avgG = round((float)sumG / 4);
    avgB = round((float)sumB / 4);
    image[i][j].rgbtRed = avgR;
    image[i][j].rgbtGreen = avgG;
    image[i][j].rgbtBlue = avgB;
    //code for lower EDGE pixelS, each bounded by 5 indivisual pixels
    for(j = 1; j < w1; j++)
    {
        sumR = timage[h1-1][j-1].rgbtRed + timage[h1][j-1].rgbtRed + timage[h1-1][j].rgbtRed + timage[h1][j].rgbtRed + timage[h1-1][j+1].rgbtRed + timage[h1][j+1].rgbtRed;
        sumG = timage[h1-1][j-1].rgbtGreen + timage[h1][j-1].rgbtGreen + timage[h1-1][j].rgbtGreen + timage[h1][j].rgbtGreen + timage[h1-1][j+1].rgbtGreen + timage[h1][j+1].rgbtGreen;
        sumB = timage[h1-1][j-1].rgbtBlue + timage[h1][j-1].rgbtBlue + timage[h1-1][j].rgbtBlue + timage[h1][j].rgbtBlue + timage[h1-1][j+1].rgbtBlue + timage[h1][j+1].rgbtBlue;
        avgR = round((float)sumR / 6);
        avgG = round((float)sumG / 6);
        avgB = round((float)sumB / 6);
        image[h1][j].rgbtRed = avgR;
        image[h1][j].rgbtGreen = avgG;
        image[h1][j].rgbtBlue = avgB;
    }
    //code for lower-right CORNER pixel, bounded by 3 indivisual pixels
    sumR = timage[i-1][j-1].rgbtRed + timage[i][j-1].rgbtRed + timage[i-1][j].rgbtRed + timage[i][j].rgbtRed;
    sumG = timage[i-1][j-1].rgbtGreen + timage[i][j-1].rgbtGreen + timage[i-1][j].rgbtGreen + timage[i][j].rgbtGreen;
    sumB = timage[i-1][j-1].rgbtBlue + timage[i][j-1].rgbtBlue + timage[i-1][j].rgbtBlue + timage[i][j].rgbtBlue;
    avgR = round((float)sumR / 4);
    avgG = round((float)sumG / 4);
    avgB = round((float)sumB / 4);
    image[i][j].rgbtRed = avgR;
    image[i][j].rgbtGreen = avgG;
    image[i][j].rgbtBlue = avgB;
    return;
}
