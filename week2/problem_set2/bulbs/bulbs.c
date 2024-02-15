#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);
int *convert(int n);

int main(void)
{
    // TODO
    string str = get_string("Message: ");
    int i = 0;
    while (str[i])
    {
        int *p = convert(str[i]);
        for (int j = 0; j < 8; j++)
        {
            print_bulb(p[j]);
        }
        printf("\n");
        i++;
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}

int *convert(int n)
{
    int i = 7;
    int *p = calloc(8, sizeof(int));
    while (n)
    {
        p[i] = n % 2;
        n /= 2;
        i--;
    }
    return p;
}