/**
 * by webprog26
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLENGTH 1001

#define TRUE 1
#define FALSE 0

void _strcopy(char* fromS, char* toS, int from, int to)
{
    char* tp = fromS + to;

    fromS += from;


    while(*fromS && fromS < tp)
    {
        *toS = *fromS;
        fromS++;
        toS++;
    }
    *toS = '\0';
}

int _strlen(char* s)
{
    int counter = 0;

    while(*s)
    {
        counter++;
        s++;
    }

    return counter;
}

int _strcmp(char* s, char* s1)
{
    while(*s)
    {
        if(*s != *s1)
        {
            return FALSE;
        }
        s++;
        s1++;
    }
    return TRUE;
}

int main()
{

    char text[MAXLENGTH];

    scanf("%s", text);

    char strings[MAXLENGTH][MAXLENGTH];

    int index = 0;

    int wordFirst = 0;
    int wordLast = 0;

    for(int i = 0; i <= _strlen(text); i++)
    {
        if((text[i] == ' ' || text[i] == '\0') && text[i + 1] != ' ')
        {
            _strcopy(text, strings[index], wordFirst, ++wordLast);
            wordFirst += _strlen(strings[index]);
            index++;
        } else {
            wordLast++;
        }
    }

    int wordsMarkers[index];

    for(int i = 0; i < index; i++)
    {
        wordsMarkers[i] = 0;
    }

    for(int i = 0; i < index; i++)
    {
        for(int j = 0; j < index; j++)
        {
            if(_strcmp(strings[i], strings[j]))
            {
                wordsMarkers[i]++;
            }
        }
    }

    int popularWordIndex = 0;
    int popularWordMarker = 0;

    for(int i = 0; i < index; i++)
    {
        if(wordsMarkers[i] > popularWordIndex)
        {
            popularWordMarker = wordsMarkers[i];
            popularWordIndex = i;
        }
    }

    for(int i = 0; i < _strlen(strings[popularWordIndex]); i++)
    {
        printf("%c", toupper(strings[popularWordIndex][i]));
    }

    return 0;
}
