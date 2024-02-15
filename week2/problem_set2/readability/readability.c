#include <cs50.h>
#include <stdio.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text), words = count_words(text), sentences = count_sentences(text), gra;
    float index, L, S;
    L = 100.0 * letters / words;
    S = 100.0 * sentences / words;
    index = 0.0588 * L - 0.296 * S - 15.8;
    gra = round(index);
    if (gra < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (gra >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", gra);
    }
}

int count_letters(string text)
{
    int i = 0, sum = 0;
    while (text[i])
    {
        if (text[i] <= 'z' && text[i] >= 'a')
        {
            sum++;
        }
        else if (text[i] <= 'Z' && text[i] >= 'A')
        {
            sum++;
        }
        i++;
    }
    return sum;
}

int count_words(string text)
{
    int val = 1, i = 0;
    while (text[i])
    {
        if (text[i] == ' ')
        {
            val++;
        }
        i++;
    }
    return val;
}

int count_sentences(string text)
{
    int val = 0, i = 0;
    while (text[i])
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            val++;
        }
        i++;
    }
    return val;
}