#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int verify1(string arg);
int verify2(string arg);
char convert(char c, string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        if (verify1(argv[1]))
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        else if (verify2(argv[1]))
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        else
        {
            int  i = 0;
            string str = get_string("plaintext:  ");
            while (str[i])
            {
                str[i] = convert(str[i], argv[1]);
                i++;
            }
            printf("ciphertext: %s\n", str);
        }
    }
    return 0;
}

//to verify whether it consists of 26 characters
int verify1(string arg)
{
    int i = 0, ret = 0;
    while (arg[i])
    {
        if ((arg[i] <= 'z' && arg[i] >= 'a') || (arg[i] <= 'Z' && arg[i] >= 'A'))
        {
            i++;
        }
        else
        {
            ret = 1;
            break;
        }
    }
    if (i != 26)
    {
        ret = 1;
    }
    return ret;
}

//to verify whether it has some duplicated chars
int verify2(string arg)
{
    int i = 0, ret = 0;
    while (arg[i])
    {
        arg[i] = tolower(arg[i]);
        i++;
    }
    i = 0;
    while (arg[i])
    {
        for (int j = i + 1; arg[j]; j++)
        {
            if (arg[j] == arg[i])
            {
                ret = 1;
                break;
            }
        }
        i++;
    }
    return ret;
}

//to convert the char into sth. we need with key
char convert(char c, string key)
{
    if (c <= 'z' && c >= 'a')
    {
        c = tolower(key[c - 'a']);
    }
    else if (c <= 'Z' && c >= 'A')
    {
        c = toupper(key[c - 'A']);
    }
    return c;
}