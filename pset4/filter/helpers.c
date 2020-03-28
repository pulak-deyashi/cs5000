#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int val = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3;
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = val;


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
            int r = image[i][j].rgbtRed;
            int g = image[i][j].rgbtGreen;
            int b = image[i][j].rgbtBlue;
            int sr = .393 * r + .769 * g + .189 * b;
            int sg = .349 * r + .686 * g + .168 * b;
            int sb = .272 * r + .534 * g + .131 * b;
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
    int arr[3];
    for(int i = 0; i < w; i++)
    {
        for(int j = 0; j < height; j++)
        {
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

    return;
}

