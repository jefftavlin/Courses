#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("bad");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (!file)
    {
        return 2;
    }

    unsigned char buffer[512];
    char filename[8];
    FILE * img;
    int counter = 0;

    while (fread(buffer, 512, 1, file) == 1)
    {
        // Open file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xff) == 0xe0)
        {
            if (counter > 0)
            {
                fclose(img);
                sprintf(filename, "%03i.jpg", counter);
                img = fopen(filename, "w");
                counter += 1;
                fwrite(buffer,512, 1, img);
            }
            if (counter == 0)
            {
                sprintf(filename, "%03i.jpg", counter);
                img = fopen(filename, "w");
                counter += 1;
                fwrite(buffer,512, 1, img);
            }

        }
        else if (counter > 0)
        {
            fwrite(buffer, 512, 1, img);
        }

    }

}
