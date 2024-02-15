#include <cs50.h>
#include <stdio.h>

int only_digits(string arg);
int toint(string arg);
char convert(char c, int key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        if (only_digits(argv[1]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        else
        {
            int key = toint(argv[1]), i = 0;
            string str = get_string("plaintext:  ");
            key %= 26;
            while (str[i])
            {
                str[i] = convert(str[i], key);
                i++;
            }
            printf("ciphertext: %s\n", str);
        }
    }
    return 0;
}

int only_digits(string arg)
{
    int ret = 0, i = 0;
    while (arg[i])
    {
        if (arg[i] < '0' || arg[i] > '9')
        {
            ret = 1;
            break;
        }
        i++;
    }
    return ret;
}

int toint(string arg)
{
    int n = 0, i = 0;
    while (arg[i])
    {
        n = 10 * n + arg[i] - '0';
        i++;
    }
    return n;
}

char convert(char c, int key)
{
    if (c >= 'a' && c <= 'z')
    {
        c = (c + key - 'a') % 26 + 'a';
    }
    else if (c >= 'A' && c <= 'Z')
    {
        c = (c + key - 'A') % 26 + 'A';
    }
    return c;
}