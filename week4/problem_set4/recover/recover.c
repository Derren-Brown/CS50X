#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
typedef uint8_t BYTE;
#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Wrong usage.\n");
        return 1;
    }
    FILE *raw_file = fopen(argv[1], "r");
    if (raw_file == NULL)
    {
        printf("Can't open.\n");
        return 1;
    }
    BYTE buffer[BLOCK_SIZE];
    int val = 0;
    FILE *file = NULL;
    char p[8];
    while (fread(buffer, 1, BLOCK_SIZE, raw_file))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] <= 0xef && buffer[3] >= 0xe0)
        {
            if (val > 0)
            {
                fclose(file);
            }
            sprintf(p, "%03i.jpg", val);
            val++;
            file = fopen(p, "w");
        }
        if (val > 0)
        {
            fwrite(buffer, 1, BLOCK_SIZE, file);
        }
    }
    fclose(raw_file);
    fclose(file);
    return 0;
}