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
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    ////here we are going to use "box blur" method
    int i = 0, j = 0, k, l;
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
    sumR = sumG = sumB = 0;
    //code for upper EDGE pixelS, each bounded by 5 indivisual pixels
    for(j = 1; j < w1; j++)
    {
        for(k = i; k <= i+1; k++)
        {
                for(l = j-1; l <= j+1; l++)
            {
                sumR += timage[k][l].rgbtRed;
                sumG += timage[k][l].rgbtGreen;
                sumB += timage[k][l].rgbtBlue;
            }
        }
        avgR = round((float)sumR / 6);
        avgG = round((float)sumG / 6);
        avgB = round((float)sumB / 6);
        image[i][j].rgbtRed = avgR;
        image[i][j].rgbtGreen = avgG;
        image[i][j].rgbtBlue = avgB;
        sumR = sumG = sumB = 0;
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
    sumR = sumG = sumB = 0;
    //code for all-MIDDLE pixels
    for(i = 1; i < h1; i++)
    {
        j = 0;
        //code for right EDGE pixelS, each bounded by 5 indivisual pixels
        for(k = i-1; k <= i+1; k++)
        {
                for(l = j; l <= j+1; l++)
            {
                sumR += timage[k][l].rgbtRed;
                sumG += timage[k][l].rgbtGreen;
                sumB += timage[k][l].rgbtBlue;
            }
        }
        avgR = round((float)sumR / 6);
        avgG = round((float)sumG / 6);
        avgB = round((float)sumB / 6);
        image[i][j].rgbtRed = avgR;
        image[i][j].rgbtGreen = avgG;
        image[i][j].rgbtBlue = avgB;
        sumR = sumG = sumB = 0;
        //code for MIDDLE pixels, each bounded by 8 indivisual pixels
        for(j = 1; j < w1; j++)
        {
            for(k = i-1; k <= i+1; k++)
            {
                for(l = j-1; l <= j+1; l++)
                {
                    sumR += timage[k][l].rgbtRed;
                    sumG += timage[k][l].rgbtGreen;
                    sumB += timage[k][l].rgbtBlue;
                }
            }
            avgR = round((float)sumR / 9);
            avgG = round((float)sumG / 9);
            avgB = round((float)sumB / 9);
            image[i][j].rgbtRed = avgR;
            image[i][j].rgbtGreen = avgG;
            image[i][j].rgbtBlue = avgB;
            sumR = sumG = sumB = 0;
        }
        //code for left CORNER pixelS, each bounded by 5 indivisual pixels
        for(k = i-1; k <= i+1; k++)
        {
                for(l = j-1; l <= j; l++)
            {
                sumR += timage[k][l].rgbtRed;
                sumG += timage[k][l].rgbtGreen;
                sumB += timage[k][l].rgbtBlue;
            }
        }
        avgR = round((float)sumR / 6);
        avgG = round((float)sumG / 6);
        avgB = round((float)sumB / 6);
        image[i][j].rgbtRed = avgR;
        image[i][j].rgbtGreen = avgG;
        image[i][j].rgbtBlue = avgB;
        sumR = sumG = sumB = 0;
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
    sumR = sumG = sumB = 0;
    //code for lower EDGE pixelS, each bounded by 5 indivisual pixels
    for(j = 1; j < w1; j++)
    {
        for(k = h1-1; k <= h1; k++)
        {
                for(l = j-1; l <= j+1; l++)
            {
                sumR += timage[k][l].rgbtRed;
                sumG += timage[k][l].rgbtGreen;
                sumB += timage[k][l].rgbtBlue;
            }
        }
        avgR = round((float)sumR / 6);
        avgG = round((float)sumG / 6);
        avgB = round((float)sumB / 6);
        image[h1][j].rgbtRed = avgR;
        image[h1][j].rgbtGreen = avgG;
        image[h1][j].rgbtBlue = avgB;
        sumR = sumG = sumB = 0;
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    //temporary image file
    RGBTRIPLE timage[height][width];
    int i=0, j=0, k=0, l=0;
    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            timage[i][j].rgbtRed = image[i][j].rgbtRed;
            timage[i][j].rgbtGreen = image[i][j].rgbtGreen;
            timage[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }
    int gxm[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gym[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    int x = 0, y = 0;
    long sumRx = 0, sumGx = 0, sumBx = 0;
    long sumRy = 0, sumGy = 0, sumBy = 0;
    int sqroot = 0;

    //making i and j of value 0, 0 for next steps
    i = 0;
    j = 0;
    //declaring h1, w1 for iterating over the middle pixels which are bounded by 8 indivisual pixels
    int w1 = width - 1;
    int h1 = height - 1;
    //code for upper-left CORNER pixel, bounded by 3 indivisual pixels
    sumRx = sumGx = sumBx = 0;
    sumRy = sumGy = sumBy = 0;
    x = 1; y = 1;
    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            sumRx += timage[i][j].rgbtRed * gxm[x][y];
            sumRy += timage[i][j].rgbtRed * gym[x][y];
            sumGx += timage[i][j].rgbtGreen * gxm[x][y];
            sumGy += timage[i][j].rgbtGreen * gym[x][y];
            sumBx += timage[i][j].rgbtBlue * gxm[x][y];
            sumBy += timage[i][j].rgbtBlue * gym[x][y];
            y++;
        }
        x++;
        y = 1;
    }
    sqroot = round(sqrt((sumRx*sumRx) + (sumRy*sumRy)));
    if(sqroot > 255) image[i][j].rgbtRed = 255;
    else image[i][j].rgbtRed = sqroot;
    sqroot = round(sqrt((sumGx*sumGx) + (sumGy*sumGy)));
    if(sqroot > 255) image[i][j].rgbtGreen = 255;
    else image[i][j].rgbtGreen = sqroot;
    sqroot = round(sqrt((sumBx*sumBx) + (sumBy*sumBy)));
    if(sqroot > 255) image[i][j].rgbtBlue = 255;
    else image[i][j].rgbtBlue = sqroot;
    //code for upper EDGE pixelS, each bounded by 5 indivisual pixels
    for(j = 1; j < w1; j++)
    {
        sumRx = sumGx = sumBx = 0;
        sumRy = sumGy = sumBy = 0;
        x = 1; y = 0;
        for(k = i; k <= i+1; k++)
        {
            for(l = j-1; l <= j+1; l++)
            {
                sumRx += timage[k][l].rgbtRed * gxm[x][y];
                sumRy += timage[k][l].rgbtRed * gym[x][y];
                sumGx += timage[k][l].rgbtGreen * gxm[x][y];
                sumGy += timage[k][l].rgbtGreen * gym[x][y];
                sumBx += timage[k][l].rgbtBlue * gxm[x][y];
                sumBy += timage[k][l].rgbtBlue * gym[x][y];
                y++;
            }
            x++;
            y = 0;
        }sqroot = round(sqrt((sumRx*sumRx) + (sumRy*sumRy)));
        if(sqroot > 255) image[i][j].rgbtRed = 255;
        else image[i][j].rgbtRed = sqroot;
        sqroot = round(sqrt((sumGx*sumGx) + (sumGy*sumGy)));
        if(sqroot > 255) image[i][j].rgbtGreen = 255;
        else image[i][j].rgbtGreen = sqroot;
        sqroot = round(sqrt((sumBx*sumBx) + (sumBy*sumBy)));
        if(sqroot > 255) image[i][j].rgbtBlue = 255;
        else image[i][j].rgbtBlue = sqroot;

    }
    //code for upper-right CORNER pixel, bounded by 3 indivisual pixels
    sumRx = 0; sumGx = 0; sumBx = 0;
    sumRy = 0; sumGy = 0; sumBy = 0;
    x = 1; y = 0;
    for(k = i; k <= i+1; k++)
    {
        for(l = j-1; l <= j; l++)
        {
            sumRx += timage[i][j].rgbtRed * gxm[x][y];
            sumRy += timage[i][j].rgbtRed * gym[x][y];
            sumGx += timage[i][j].rgbtGreen * gxm[x][y];
            sumGy += timage[i][j].rgbtGreen * gym[x][y];
            sumBx += timage[i][j].rgbtBlue * gxm[x][y];
            sumBy += timage[i][j].rgbtBlue * gym[x][y];
            y++;
        }
        x++;
        y = 0;
    }
    sqroot = round(sqrt((sumRx*sumRx) + (sumRy*sumRy)));
    if(sqroot > 255) image[i][j].rgbtRed = 255;
    else image[i][j].rgbtRed = sqroot;
    sqroot = round(sqrt((sumGx*sumGx) + (sumGy*sumGy)));
    if(sqroot > 255) image[i][j].rgbtGreen = 255;
    else image[i][j].rgbtGreen = sqroot;
    sqroot = round(sqrt((sumBx*sumBx) + (sumBy*sumBy)));
    if(sqroot > 255) image[i][j].rgbtBlue = 255;
    else image[i][j].rgbtBlue = sqroot;
    //code for all-MIDDLE pixels
    for(i = 1; i < h1; i++)
    {
        j = 0;
        //code for left EDGE pixelS, each bounded by 5 indivisual pixels
        sumRx = 0; sumGx = 0; sumBx = 0;
        sumRy = 0; sumGy = 0; sumBy = 0;
        x = 0; y = 1;
        for(k = i-1; k <= i+1; k++)
        {
            for(l = j; l <= j+1; l++)
            {
                sumRx += timage[k][l].rgbtRed * gxm[x][y];
                sumRy += timage[k][l].rgbtRed * gym[x][y];
                sumGx += timage[k][l].rgbtGreen * gxm[x][y];
                sumGy += timage[k][l].rgbtGreen * gym[x][y];
                sumBx += timage[k][l].rgbtBlue * gxm[x][y];
                sumBy += timage[k][l].rgbtBlue * gym[x][y];
                y++;
            }
            x++;
            y = 1;
        }
        sqroot = round(sqrt((sumRx*sumRx) + (sumRy*sumRy)));
        if(sqroot > 255) image[i][j].rgbtRed = 255;
        else image[i][j].rgbtRed = sqroot;
        sqroot = round(sqrt((sumGx*sumGx) + (sumGy*sumGy)));
        if(sqroot > 255) image[i][j].rgbtGreen = 255;
        else image[i][j].rgbtGreen = sqroot;
        sqroot = round(sqrt((sumBx*sumBx) + (sumBy*sumBy)));
        if(sqroot > 255) image[i][j].rgbtBlue = 255;
        else image[i][j].rgbtBlue = sqroot;
        //code for MIDDLE pixels, each bounded by 8 indivisual pixels
        for(j = 1; j < w1; j++)
        {
            sumRx = 0; sumGx = 0; sumBx = 0;
            sumRy = 0; sumGy = 0; sumBy = 0;
            x = 0; y = 0;
            for(k = i-1; k <= i+1; k++)
            {
                for(l = j-1; l <= j+1; l++)
                {
                    sumRx += (timage[k][l].rgbtRed * gxm[x][y]);
                    sumRy += (timage[k][l].rgbtRed * gym[x][y]);
                    sumGx += (timage[k][l].rgbtGreen * gxm[x][y]);
                    sumGy += (timage[k][l].rgbtGreen * gym[x][y]);
                    sumBx += (timage[k][l].rgbtBlue * gxm[x][y]);
                    sumBy += (timage[k][l].rgbtBlue * gym[x][y]);
                    y++;
                }
                x++;
                y = 0;
            }
            sqroot = round(sqrt((sumRx*sumRx) + (sumRy*sumRy)));
            if(sqroot > 255) image[i][j].rgbtRed = 255;
            else image[i][j].rgbtRed = sqroot;
            sqroot = round(sqrt((sumGx*sumGx) + (sumGy*sumGy)));
            if(sqroot > 255) image[i][j].rgbtGreen = 255;
            else image[i][j].rgbtGreen = sqroot;
            sqroot = round(sqrt((sumBx*sumBx) + (sumBy*sumBy)));
            if(sqroot > 255) image[i][j].rgbtBlue = 255;
            else image[i][j].rgbtBlue = sqroot;
        }
        //code for right EDGE pixelS, each bounded by 5 indivisual pixels
        sumRx = 0; sumGx = 0; sumBx = 0;
        sumRy = 0; sumGy = 0; sumBy = 0;
        x = 0; y = 0;
        for(k = i-1; k <= i+1; k++)
        {
            for(l = j-1; l <= j; l++)
            {
                sumRx += timage[k][l].rgbtRed * gxm[x][y];
                sumRy += timage[k][l].rgbtRed * gym[x][y];
                sumGx += timage[k][l].rgbtGreen * gxm[x][y];
                sumGy += timage[k][l].rgbtGreen * gym[x][y];
                sumBx += timage[k][l].rgbtBlue * gxm[x][y];
                sumBy += timage[k][l].rgbtBlue * gym[x][y];
                y++;
            }
            x++;
            y = 0;
        }
        sqroot = round(sqrt((sumRx*sumRx) + (sumRy*sumRy)));
        if(sqroot > 255) image[i][j].rgbtRed = 255;
        else image[i][j].rgbtRed = sqroot;
        sqroot = round(sqrt((sumGx*sumGx) + (sumGy*sumGy)));
        if(sqroot > 255) image[i][j].rgbtGreen = 255;
        else image[i][j].rgbtGreen = sqroot;
        sqroot = round(sqrt((sumBx*sumBx) + (sumBy*sumBy)));
        if(sqroot > 255) image[i][j].rgbtBlue = 255;
        else image[i][j].rgbtBlue = sqroot;
    }
    j = 0;
    //code for lower-left CORNER pixel, bounded by 3 indivisual pixels
    sumRx = 0; sumGx = 0; sumBx = 0;
    sumRy = 0; sumGy = 0; sumBy = 0;
    x = 0; y = 1;
    for(k = i-1; k <= i; k++)
    {
        for(l = j; l <= j+1; l++)
        {
            sumRx += timage[k][l].rgbtRed * gxm[x][y];
            sumRy += timage[k][l].rgbtRed * gym[x][y];
            sumGx += timage[k][l].rgbtGreen * gxm[x][y];
            sumGy += timage[k][l].rgbtGreen * gym[x][y];
            sumBx += timage[k][l].rgbtBlue * gxm[x][y];
            sumBy += timage[k][l].rgbtBlue * gym[x][y];
            y++;
        }
        x++;
        y = 1;
    }
    sqroot = round(sqrt((sumRx*sumRx) + (sumRy*sumRy)));
    if(sqroot > 255) image[i][j].rgbtRed = 255;
    else image[i][j].rgbtRed = sqroot;
    sqroot = round(sqrt((sumGx*sumGx) + (sumGy*sumGy)));
    if(sqroot > 255) image[i][j].rgbtGreen = 255;
    else image[i][j].rgbtGreen = sqroot;
    sqroot = round(sqrt((sumBx*sumBx) + (sumBy*sumBy)));
    if(sqroot > 255) image[i][j].rgbtBlue = 255;
    else image[i][j].rgbtBlue = sqroot;
    //code for lower EDGE pixelS, each bounded by 5 indivisual pixels
    for(j = 1; j < w1; j++)
    {
        sumRx = 0; sumGx = 0; sumBx = 0;
        sumRy = 0; sumGy = 0; sumBy = 0;
        x = 0; y = 0;
        for(k = h1-1; k <= h1; k++)
        {
                for(l = j-1; l <= j+1; l++)
            {
                sumRx += timage[k][l].rgbtRed * gxm[x][y];
                sumRy += timage[k][l].rgbtRed * gym[x][y];
                sumGx += timage[k][l].rgbtGreen * gxm[x][y];
                sumGy += timage[k][l].rgbtGreen * gym[x][y];
                sumBx += timage[k][l].rgbtBlue * gxm[x][y];
                sumBy += timage[k][l].rgbtBlue * gym[x][y];
                y++;
            }
            x++;
            y = 0;
        }sqroot = round(sqrt((sumRx*sumRx) + (sumRy*sumRy)));
        if(sqroot > 255) image[i][j].rgbtRed = 255;
        else image[i][j].rgbtRed = sqroot;
        sqroot = round(sqrt((sumGx*sumGx) + (sumGy*sumGy)));
        if(sqroot > 255) image[i][j].rgbtGreen = 255;
        else image[i][j].rgbtGreen = sqroot;
        sqroot = round(sqrt((sumBx*sumBx) + (sumBy*sumBy)));
        if(sqroot > 255) image[i][j].rgbtBlue = 255;
        else image[i][j].rgbtBlue = sqroot;
    }
    sumRx = 0; sumGx = 0; sumBx = 0;
    sumRy = 0; sumGy = 0; sumBy = 0;
    x = 0; y = 0;
    for(k = i-1; k <= i; k++)
    {
        for(l = j-1; l <= j; l++)
        {
            sumRx += timage[k][l].rgbtRed * gxm[x][y];
            sumRy += timage[k][l].rgbtRed * gym[x][y];
            sumGx += timage[k][l].rgbtGreen * gxm[x][y];
            sumGy += timage[k][l].rgbtGreen * gym[x][y];
            sumBx += timage[k][l].rgbtBlue * gxm[x][y];
            sumBy += timage[k][l].rgbtBlue * gym[x][y];
            y++;
        }
        x++;
        y = 0;
    }
    sqroot = round(sqrt((sumRx*sumRx) + (sumRy*sumRy)));
    if(sqroot > 255) image[i][j].rgbtRed = 255;
    else image[i][j].rgbtRed = sqroot;
    sqroot = round(sqrt((sumGx*sumGx) + (sumGy*sumGy)));
    if(sqroot > 255) image[i][j].rgbtGreen = 255;
    else image[i][j].rgbtGreen = sqroot;
    sqroot = round(sqrt((sumBx*sumBx) + (sumBy*sumBy)));
    if(sqroot > 255) image[i][j].rgbtBlue = 255;
    else image[i][j].rgbtBlue = sqroot;
    return;
}
/*void edges(int height, int width, RGBTRIPLE image[height][width])
{
    //temporary image file
    int h1 = height+2; int w1 = width+2;
    //temporary image file
    RGBTRIPLE timage[h1][w1];
    int i, j, k, l, x, y;
    //inserting zeros to the extra border(upper, lower) pixels
    for(i = 0; i < h1; i += h1-1)
    {
        for(j = 0; j < w1; j++)
        {
            timage[i][j].rgbtRed = 0;
            timage[i][j].rgbtGreen = 0;
            timage[i][j].rgbtBlue = 0;
        }
    }
    //inserting zeros to the extra border(left, right) pixels
    for(i = 1; i <= height; i++)
    {
        for(j = 0; j < w1; j += w1-1)
        {
            timage[i][j].rgbtRed = 0;
            timage[i][j].rgbtGreen = 0;
            timage[i][j].rgbtBlue = 0;
        }
    }
    //copying the image inside temp image file
    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            timage[i+1][j+1].rgbtRed = image[i][j].rgbtRed;
            timage[i+1][j+1].rgbtGreen = image[i][j].rgbtGreen;
            timage[i+1][j+1].rgbtBlue = image[i][j].rgbtBlue;
        }
    }
    //variable for storing the value of square root
    int sqroot;
    //values of x and y kernals
    int gxm[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gym[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    //sum variables
    int sumRx, sumGx, sumBx;
    int sumRy, sumGy, sumBy;
    //iterating over the height and width of given pixel
    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            //initializing sum as zero for every new step
            sumRx = 0; sumGx = 0; sumBx = 0;
            sumRy = 0; sumGy = 0; sumBy = 0;
            //x, y = 0 for indexing gxm, gym
            x = 0; y = 0;
            for(k = i-1; k <= i+1; k++)
            {
                for(l = j-1; l <= j+1; l++)
                {
                    sumRx += (timage[k+1][l+1].rgbtRed * gxm[x][y]);
                    sumRy += (timage[k+1][l+1].rgbtRed * gym[x][y]);
                    sumGx += (timage[k+1][l+1].rgbtGreen * gxm[x][y]);
                    sumGy += (timage[k+1][l+1].rgbtGreen * gym[x][y]);
                    sumBx += (timage[k+1][l+1].rgbtBlue * gxm[x][y]);
                    sumBy += (timage[k+1][l+1].rgbtBlue * gym[x][y]);
                    y++;
                }
                x++;
                y = 0;
            }
            //inserting corrosponding value
            sqroot = round(sqrt((sumRx*sumRx) + (sumRy*sumRy)));
            if(sqroot > 255) image[i][j].rgbtRed = 255;
            else image[i][j].rgbtRed = sqroot;
            sqroot = round(sqrt((sumGx*sumGx) + (sumGy*sumGy)));
            if(sqroot > 255) image[i][j].rgbtGreen = 255;
            else image[i][j].rgbtGreen = sqroot;
            sqroot = round(sqrt((sumBx*sumBx) + (sumBy*sumBy)));
            if(sqroot > 255) image[i][j].rgbtBlue = 255;
            else image[i][j].rgbtBlue = sqroot;
        }
    }

    return;
}*/
