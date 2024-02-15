#include "bmp.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]);

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]);

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width]);

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]);

int verify(int i, int j, int height, int width);

void initial(int height, int width, RGBTRIPLE modify[height + 2][width + 2]);

void pass(int height, int width, RGBTRIPLE image[height][width], RGBTRIPLE modify[height + 2][width + 2]);