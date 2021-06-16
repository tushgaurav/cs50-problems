 #include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Data type to store a byte
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Usage: %s image\n", argv[0]);
        return 1;
    }

    // opening the forensic image
    FILE *memorycard = fopen(argv[1], "r");
    if (memorycard == NULL)
    {
        printf("Cannot open the file.\n");
        return 1;
    }

    // creating a buffer to store the blocks of data
    BYTE buffer[512];

    // output jpeg file pointer
    FILE *out = NULL;
    int count = 0;
    char filename[8];

    while (fread(&buffer, 512, 1, memorycard) == 1)
    {


        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (count == 0)
            {
                sprintf(filename, "%03i.jpg", count);
                out = fopen(filename, "w");
                fwrite(buffer, 512, 1, out);
                count++;


            }
            else
            {
                fclose(out);
                sprintf(filename, "%03i.jpg", count);
                out = fopen(filename, "w");
                fwrite(buffer, 512, 1, out);
                count++;
            }
        }
        else if (count > 0)
        {
            fwrite(buffer, 512, 1, out);
        }
    }
    fclose(memorycard);
    fclose(out);
}