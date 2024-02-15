#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int n = (image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3;
            image[i][j].rgbtRed = n;
            image[i][j].rgbtBlue = n;
            image[i][j].rgbtGreen = n;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j <= width / 2; j++)
        {
            RGBTRIPLE rgb;
            rgb = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = rgb;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = 0, blue = 0, green = 0, val = 0;
            for (int k = i - 1; k < i + 2; k++)
            {
                for (int l = j - 1; l < j + 2; l++)
                {
                    if (verify(k, l, height, width))
                    {
                        val++;
                        red += image[k][l].rgbtRed;
                        blue += image[k][l].rgbtBlue;
                        green += image[k][l].rgbtGreen;
                    }
                }
            }
            image[i][j].rgbtRed = red / val;
            image[i][j].rgbtBlue = blue / val;
            image[i][j].rgbtGreen = green / val;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE modify[height + 2][width + 2];
    initial(height, width, modify);
    pass(height, width, image, modify);
    for (int i = 1; i < height + 1; i++)
    {
        for (int j = 1; j < width + 1; j++)
        {
            int gxred = 0, gyred = 0, Gred = 0;
            gxred = -modify[i - 1][j - 1].rgbtRed - 2 * modify[i][j - 1].rgbtRed - modify[i][j + 1].rgbtRed +
                    modify[i + 1][j + 1].rgbtRed + 2 * modify[i][j + 1].rgbtRed + modify[i - 1][j + 1].rgbtRed;
            gyred = -modify[i - 1][j - 1].rgbtRed - 2 * modify[i - 1][j].rgbtRed - modify[i - 1][j + 1].rgbtRed +
                    modify[i + 1][j - 1].rgbtRed + 2 * modify[i + 1][j].rgbtRed + modify[i + 1][j + 1].rgbtRed;
            Gred = (int) sqrt(gxred * gxred + gyred * gyred);
            if (Gred > 255)
            {
                image[i - 1][j - 1].rgbtRed = 255;
                image[i - 1][j - 1].rgbtBlue = 255;
                image[i - 1][j - 1].rgbtGreen = 255;
            }
        }
    }
    return;
}

int verify(int i, int j, int height, int width)
{
    int ret = 0;
    if (i >= 0 && i < height)
    {
        if (j >= 0 && j < width)
        {
            ret = 1;
        }
    }
    return ret;
}

void initial(int height, int width, RGBTRIPLE modify[height + 2][width + 2])
{
    for (int i = 0; i < height + 2; i++)
    {
        for (int j = 0; j < width + 2; j++)
        {
            modify[i][j].rgbtRed = 0;
            modify[i][j].rgbtBlue = 0;
            modify[i][j].rgbtGreen = 0;
        }
    }
}

void pass(int height, int width, RGBTRIPLE image[height][width], RGBTRIPLE modify[height + 2][width + 2])
{
    for (int i = 1; i < height + 1; i++)
    {
        for (int j = 1; j < width + 1; j++)
        {
            modify[i][j].rgbtGreen = image[i - 1][j - 1].rgbtGreen;
            modify[i][j].rgbtRed = image[i - 1][j - 1].rgbtRed;
            modify[i][j].rgbtBlue = image[i - 1][j - 1].rgbtBlue;
        }
    }
}