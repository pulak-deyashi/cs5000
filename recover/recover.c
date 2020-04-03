#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>

typedef uint8_t  BYTE;

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    int count = 0;
    char filename[8];
    BYTE buffer[512];
    FILE *img = NULL;
    FILE *file = fopen(argv[1], "r");
    if(file == NULL)
    {
        fprintf(stderr, "Could not open\n");
        return 2;
    }
    while(fread(buffer, 1, 512, file) != 0x00)
    {
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if(count == 0)
            {
            sprintf(filename, "%03i.jpg", count);
            count++;
            img = fopen(filename, "w");
            fwrite(buffer, 1, 512, img);
            }
            else
            {
            fclose(img);
            sprintf(filename, "%03i.jpg", count);
            count++;
            img = fopen(filename, "w");
            fwrite(buffer, 1, 512, img);
            }
        }
        else if(count != 0)
        {
            fwrite(buffer, 1, 512, img);
        }

    }
    if(img != NULL)
    fclose(img);
    fclose(file);

}
