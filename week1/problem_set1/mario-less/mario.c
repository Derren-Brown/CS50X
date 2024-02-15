#include <cs50.h>
#include <stdio.h>

void print(int i, char c);

int main(void)
{
    int hgt;
    do
    {
        printf("Height: ");
        scanf("%d", &hgt);
    }while (hgt < 1 || hgt > 8);
    int j;
    for (int i = 1; i <= hgt; i++)
    {
        print(hgt - i, ' ');
        print(i, '#');
        printf("\n");
    }
}

void print(int i, char c)
{
    for (int j = 0; j < i; j++)
    {
        printf("%c", c);
    }
}