#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t  BYTE;

int main(int argc, char *argv[])
{
    // ensure proper usage
    if(argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    //remember image file name
    char *infile = argv[1];

    //open image file
    FILE *card = fopen(infile, "r");

    //create storage for blocks to be read into
    int block = 512;
    BYTE buffer[block];

    //create the ability to create new names for the jpg files
    int filenumber = 0;
    char filename[8];
    char *newfile = filename;
    FILE *image = NULL;

    while(fread(&buffer, block, 1, card) == 1) //create a loop to read through the whole memory card
    {

        //read the block into the storage
        //fread(&buffer, block, 1, card);

        //if the block is a header block
        if((buffer[0] == 0xff)
        && (buffer[1] == 0xd8)
        && (buffer[2] == 0xff)
        && ((buffer[3] & 0xf0) == 0xe0))
        {
            //if the block isn't the start of the images, then close the previous file
            //if(filenumber > 0)
            //{
                //fclose(image);
            //}

            //create the name of the new file
            sprintf(filename, "%03i.jpg",filenumber);

            //open the new file
            image = fopen(newfile, "w");

            //write the block into the new file
            fwrite(&buffer, block, 1, image);

            //increase the counter so that the next time a header comes up, the file number is ready to capture it
            filenumber++;

        }
        //if the block being read isn't a header but it is already after the first header was found, add the block to the latest image
        else if (filenumber > 0)
        {
            fwrite(&buffer, block, 1, image);
        }

    }

    //close the last image
    fclose(image);

}