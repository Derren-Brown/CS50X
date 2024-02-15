#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        printf("Wrong usage.\n");
        return 1;
    }

    // Open input file for reading
    // TODO #2
    FILE *input = fopen(argv[1], "r");
    if (!input)
    {
        printf("Can't open.\n");
        return 1;
    }

    // Read header
    // TODO #3
    WAVHEADER header;
    fread(&header, 1, sizeof(WAVHEADER), input);

    // Use check_format to ensure WAV format
    // TODO #4
    if (!check_format(header))
    {
        printf("Wrong format.\n");
        return 1;
    }
    // Open output file for writing
    // TODO #5
    FILE *output = fopen(argv[2], "w");
    // Write header to file
    // TODO #6
    fwrite(&header, 1, sizeof(WAVHEADER), output);
    // Use get_block_size to calculate size of block
    // TODO #7
    int block_size = get_block_size(header);
    // Write reversed audio to file
    // TODO #8
    void *buffer = malloc(block_size);
    fseek(input, -block_size, SEEK_END);
    while (ftell(input) >= 44)
    {
        fread(buffer, 1, block_size, input);
        fwrite(buffer, 1, block_size, output);
        fseek(input, -2 * block_size, SEEK_CUR);
    }
    free(buffer);
    fclose(input);
    fclose(output);
    return 0;
}

int check_format(WAVHEADER header)
{
    // TODO #4
    int ret = 0;
    if (header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E')
    {
        ret = 1;
    }
    return ret;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    return header.bitsPerSample * header.numChannels / 8;
}