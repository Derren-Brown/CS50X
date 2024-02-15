// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool ret = false;
    int s[4] = {}, i = 0;
    char c = 0;
    while (password[i])
    {
        c = password[i];
        i++;
        if (c <=  'z' && c >= 'a')
        {
            s[0] = 1;
        }
        else if (c <= 'Z' && c >= 'A')
        {
            s[1] = 1;
        }
        else if (c >= '0' && c <= '9')
        {
            s[2] = 1;
        }
        else
        {
            s[3] = 1;
        }
    }
    if (s[0] && s[1] && s[2] && s[3])
    {
        ret = true;
    }
    return ret;
}
