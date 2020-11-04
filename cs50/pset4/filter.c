#include "helpers.h"
#include <math.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int last_row = height -1;
    int last_col = width - 1;

    for (int i =0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double sum = image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue;
            double avg = sum / 3;

            image[i][j].rgbtRed = round(avg);
            image[i][j].rgbtGreen = round(avg);
            image[i][j].rgbtBlue = round(avg);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int last_row = height -1;
    int last_col = width - 1;

    for (int i =0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double red = 0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue;
            double green = 0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue;
            double blue = 0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue;

            if (red > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = round(red);

            }

            if (green > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = round(green);
            }

            if (blue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = round(blue);
            }

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int half = round((float)1/2 * width);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < half; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j -1];
            image[i][width-j-1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //Create copy for input
    RGBTRIPLE original[height][width];

    for (int i = 0; i < height; i++)
    {
        //and every column
        for (int j = 0; j < width; j++)
        {
            original[i][j].rgbtRed = image[i][j].rgbtRed;
            original[i][j].rgbtGreen = image[i][j].rgbtGreen;
            original[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //introduce variable count which will be value which sum is averaged by
            float count = 1;
            int red = original[i][j].rgbtRed;
            int green = original[i][j].rgbtGreen;
            int blue = original[i][j].rgbtBlue;
            //1 if pixel directly above exists (i-1)(j)
            if (i - 1 >= 0)
            {
                red += original[i-1][j].rgbtRed;
                green += original[i-1][j].rgbtGreen;
                blue += original[i-1][j].rgbtBlue;
                count++;
            }
            //2 if pixel above left exists (i-1)(j-1) corner
            if (i - 1 >= 0 && j - 1 >= 0 )
            {
                red += original[i-1][j-1].rgbtRed;
                green += original[i-1][j-1].rgbtGreen;
                blue += original[i-1][j-1].rgbtBlue;
                count++;
            }
            //3 if pixel above right exists (i-1)(j-1)
            if (j + 1 < width && i - 1 >= 0)
            {
                red += original[i-1][j+1].rgbtRed;
                green += original[i-1][j+1].rgbtGreen;
                blue += original[i-1][j+1].rgbtBlue;
                //count is extended
                count++;
            }
            //4 if pixel directly below exists (i+1)(j)
            if (i + 1 < height)
            {
                red += original[i+1][j].rgbtRed;
                green += original[i+1][j].rgbtGreen;
                blue += original[i+1][j].rgbtBlue;
                //count is extended
                count++;
            }
            //5 if pixel below left exist (i+1)(j-1)
            if (j - 1 >= 0 && i + 1 < height)
            {
                red += original[i+1][j-1].rgbtRed;
                green += original[i+1][j-1].rgbtGreen;
                blue += original[i+1][j-1].rgbtBlue;
                //count is extended
                count++;
            }
            //6 if pixel below right exists (i+1)(j+1)
            if (j + 1 < width && i + 1 < height)
            {
                red += original[i+1][j+1].rgbtRed;
                green += original[i+1][j+1].rgbtGreen;
                blue += original[i+1][j+1].rgbtBlue;
                count++;
            }
            //7 if pixel to the left exists (i)(j-1)
            if (j - 1 >= 0)
            {
                red += original[i][j-1].rgbtRed;
                green += original[i][j-1].rgbtGreen;
                blue += original[i][j-1].rgbtBlue;
                count++;
            }
            //8 if pixel to the right exists (i)(j+1)
            if (j + 1 < width)
            {
                //sum of all red, green and blue values are updated to new pixel values
                red += original[i][j+1].rgbtRed;
                green += original[i][j+1].rgbtGreen;
                blue += original[i][j+1].rgbtBlue;
                //count is extended
                count++;
            }
            //finishes adding values of middle pixel (i)(j)
            count = count*1.0;
            image[i][j].rgbtRed = round(red/count);
            image[i][j].rgbtGreen = round(green/count);
            image[i][j].rgbtBlue = round(blue/count);
        }
    }
    return;
}
