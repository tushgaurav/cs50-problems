#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sum = image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed;
            int average = round(sum / 3.0);

            if (average > 255)
            {
                average = 255;
            }
            if (average < 0)
            {
                average = 0;
            }

            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            float RAWsepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue;
            float RAWsepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue;
            float RAWsepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue;

            int sepiaRed = round(RAWsepiaRed);
            int sepiaGreen = round(RAWsepiaGreen);
            int sepiaBlue = round(RAWsepiaBlue);

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            if (sepiaRed < 0)
            {
                sepiaRed = 0;
            }
            if (sepiaGreen < 0)
            {
                sepiaGreen = 0;
            }
            if (sepiaBlue < 0)
            {
                sepiaBlue = 0;
            }

            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int range;

    if (width % 2 == 0)
    {
        range = width / 2;
    }
    else
    {
        range = (width - 1) / 2;
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < range; j++)
        {
            RGBTRIPLE copy = image[i][j];
            image[i][j] = image[i][width - j];
            image[i][width - j] = copy;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j ++)
        {
            if (i < 1 || j < 1 || i + 1 == height || j + 1 == width)
            {
                continue;
            }

            int averageBlue = image[i][j].rgbtBlue +
                              image[i - 1][j + 0].rgbtBlue +
                              image[i - 1][j + 1].rgbtBlue +
                              image[i - 1][j - 1].rgbtBlue +
                              image[i + 0][j + 1].rgbtBlue +
                              image[i + 1][j + 0].rgbtBlue +
                              image[i + 1][j + 1].rgbtBlue +
                              image[i + 1][j - 1].rgbtBlue +
                              image[i + 0][j - 1].rgbtBlue;

            int averageRed = image[i + 0][j + 0].rgbtRed +
                             image[i - 1][j + 0].rgbtRed +
                             image[i - 1][j + 1].rgbtRed +
                             image[i - 1][j - 1].rgbtRed +
                             image[i + 0][j + 1].rgbtRed +
                             image[i + 1][j + 0].rgbtRed +
                             image[i + 1][j + 1].rgbtRed +
                             image[i + 1][j - 1].rgbtRed +
                             image[i + 0][j - 1].rgbtRed;

            int averageGreen = image[i + 0][j + 0].rgbtGreen +
                               image[i - 1][j + 0].rgbtGreen +
                               image[i - 1][j + 1].rgbtGreen +
                               image[i - 1][j - 1].rgbtGreen +
                               image[i + 0][j + 1].rgbtGreen +
                               image[i + 1][j + 0].rgbtGreen +
                               image[i + 1][j + 1].rgbtGreen +
                               image[i + 1][j - 1].rgbtGreen +
                               image[i + 0][j - 1].rgbtGreen;

            image[i][j].rgbtBlue = averageBlue / 9;
            image[i][j].rgbtGreen = averageGreen / 9;
            image[i][j].rgbtRed = averageRed / 9;

        }
    }
    return;
}
