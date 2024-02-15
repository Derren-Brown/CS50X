#include <cs50.h>
#include <stdio.h>

int verify1(int len, long num1, long num2);
int verify2(long num, int len);
int adjust(int n);

int main(void)
{
    int len = 1, ret1 = 0, ret2 = 0;
    long num = 0, num1 = 0, num2 = 0;
    num = num1 = get_long("Number: ");
    while (num1 > 10)
    {
        num2 = num1 % 10;
        num1 /= 10;
        len++;
    }
    ret1 = verify1(len, num1, num2);
    if (ret1)
    {
        ret2 = verify2(num, len);
    }
    if (ret2)
    {
        switch (ret1)
        {
            case 1:
                printf("AMEX\n");
                break;
            case 2:
                printf("MASTERCARD\n");
                break;
            case 3:
                printf("VISA\n");
                break;
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

int verify1(int len, long num1, long num2)
{
    int ret = 0;
    if (num1 == 3)
    {
        if (num2 == 4 || num2 == 7)
        {
            if (len == 15)
            {
                ret = 1;
            }
        }
    }
    else if (num1 == 4)
    {
        if (len == 13 || len == 16)
        {
            ret = 3;
        }
    }
    else if (num1 == 5)
    {
        if (len == 16)
        {
            if (0 < num2 && num2 < 6)
            {
                ret = 2;
            }
        }
    }
    return ret;
}

int verify2(long num, int len)
{
    int ret = 1, i = 0, val = 0, sum1 = 0, sum2 = 0, sum = 0;
    int odd[9] = {0}, even[9] = {0};
    while (num)
    {
        odd[i] = num % 10;
        num /= 10;
        even[i] = num % 10;
        num /= 10;
        i++;
    }
    val = i;
    for (i = 0; i< val; i++)
    {
        sum1 += adjust(even[i]);
        sum2 += odd[i];
    }
    sum = sum1 + sum2;
    if (sum % 10)
    {
        ret = 0;
    }
    return ret;
}

int adjust(int n)
{
    n *= 2;
    n = n / 10 + n % 10;
    return n;
}