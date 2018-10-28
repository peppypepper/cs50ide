#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>

typedef uint8_t BYTE;


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "need 2 command line arguments\n");
        return 1;
    }

    char *infile = argv[1];

    FILE *card = fopen(infile, "r");
    if (card == NULL)
    {
        fprintf(stderr, "can't open the file\n");
        return 2;
    }

    BYTE buffer[555];  //only need 512, 555 wouldn't hurt?
    int filenumber = 0;
    char filename[8]; //an array to use with sprintf
    char *newfile = filename;
    FILE *image = NULL;

    while (fread(&buffer, 512, 1, card) == 1)
    {

        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            //create a new file name
            sprintf(filename, "%03i.jpg", filenumber);

            //open the new file
            image = fopen(newfile, "w");

            //write to new file
            fwrite(&buffer, 512, 1, image);

            filenumber++;

        }
        else if(filenumber > 0) //keep writing the next 512 block to the same image file until encounter another header
        {
            fwrite(&buffer, 512, 1, image);
        }


    }
    //close the last image
    fclose(image);


}










































