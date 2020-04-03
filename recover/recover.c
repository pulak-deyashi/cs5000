#include <stdio.h>
#include <stdlib.h>
//FOR RAW DATA EXCLUDED SLAG SPACE  
int main(int argc, char *argv[])
{
    //check whether 2 arguments are passed in the command line
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    int count = 0;
    //file name of 8 chae long as 000.jpg
    char filename[8];
    //array of unsigned char ie 8 byte each space to store the read data initially
    unsigned char buffer[512];
    //new image file pointer
    FILE *img = NULL;
    //opened the passed raw file
    FILE *file = fopen(argv[1], "r");
    //if passed file not exists print couldn't open and return a non zero value
    if (file == NULL)
    {
        fprintf(stderr, "Could not open\n");
        return 2;
    }
    //while loop upto the end of raw file
    while (fread(buffer, 1, 512, file) != 0x00)
    {
        //if jpeg image block found
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //if the jpeg image block is not the first one then close the previously opened new img file
            if (count != 0)
            {
                fclose(img);
            }
            //create file name
            sprintf(filename, "%03i.jpg", count);
            count++;
            //open a image file of that name to write the new image file
            img = fopen(filename, "w");
            fwrite(buffer, 1, 512, img);
        }
        //if any image file found before then add the block to the previous image file until new image starting block found
        else if (count != 0)
        {
            fwrite(buffer, 1, 512, img);
        }

    }
    //close the opened files
    if (img != NULL)
    {
        fclose(img);
    }
    fclose(file);

}
