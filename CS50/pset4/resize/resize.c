// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>


#include "bmp.h"

int main(int argc, char *argv[])
{
    //need 4 arguments to work
    if (argc != 4)
    {
        fprintf(stderr, "Usage: resize n infile outfile\n");
        return 1;
    }

    //remember filenames
    int n = atoi(argv[1]);
    char *infile = argv[2];
    char *outfile = argv[3];

    //open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    //open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fprintf(stderr, "Could not creat %s.\n", outfile);
        return 3;
    }

    //read infile's bitmapfileheader and hold in memory
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    //read infile's bitmapinfohead and hold in memory
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);



    BITMAPFILEHEADER newbf = bf;
    BITMAPINFOHEADER newbi = bi;

    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int newpadding = (4 - (newbi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    newbi.biWidth *= n;
    newbi.biHeight = abs(bi.biHeight) * n;
    newbi.biSizeImage = (sizeof(RGBTRIPLE) * newbi.biWidth + newpadding) * newbi.biHeight;
    newbf.bfSize = newbi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);



    //write outfile's bitmapfileheader
    fwrite(&newbf, sizeof(BITMAPFILEHEADER), 1, outptr);

    //write outfile's bitmapinfoheader
    fwrite(&newbi, sizeof(BITMAPINFOHEADER), 1, outptr);



    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        //temporary triple

        RGBTRIPLE triple;
        RGBTRIPLE *arr = malloc((sizeof(RGBTRIPLE)) * newbi.biWidth);

        //iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {


            //read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            for (int k = 0; k < n; k++)
            {
                arr[k + n * j] = triple; //what?
            }

        }
                //write RGB triple to outfile
        for (int m = 0; m < n; m++)
        {
            fwrite(&arr, sizeof(RGBTRIPLE), 1, outptr);

            for (int k = 0; k < newpadding; k++)
            {
                fputc(0x00, outptr);
            }

        }


        //skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

        free(arr);

    }

    //close infile
    fclose(inptr);

    //close outfile
    fclose(outptr);

    return 0;

}