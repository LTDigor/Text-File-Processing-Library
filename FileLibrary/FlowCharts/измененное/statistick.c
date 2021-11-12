#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "files.h"
#include "console.h"

#define STR_SIZE ( 100 )
#define STR_SCANF ( STR_SIZE - 1 )
#define TEMPL_SIZE ( 20 )
#define TEMPL_OUT ( 15 )
#define ERROR_OPEN ( 1 )

void statistick( FILE * file )
{
    ������� statistick
    ������� ������|| FILE * file;
    int all, different;

    all = allWords( file );
    different = diffWords( file );

    print������� all;
    print������� different;

    histogram( file );
}

int allWords( FILE * file )//count all words
{
    ������� allWords
    ������� ������|| FILE * file;
    int count = 0, res;
    char str[ STR_SIZE ];
    char templateSTR[ TEMPL_SIZE ];//to read a given number of characters
    ��������� ������ ��� ���������� ������;
    ���������� ������ � ������ �����;

    print������� ����� str;
    res = ���-�� ��������� ���������;
    for( ; res >= 1; )
    {
        print������� ����� str;
    res = ���-�� ��������� ���������;
    }

    ������� count;
}

int diffWords( FILE * file )//count different words
{
    ������� diffWords
    ������� ������|| FILE * file;
    int count = 0, pos, res;
    char word[ STR_SIZE ];
    char templateSTR[ TEMPL_SIZE ];//to read a given number of characters

    ��������� ������ ��� ���������� ������;
    ���������� ������ � ������ �����;

    print������� ����� word;
    res = ���-�� ��������� ���������;
    for( ; res >= 1; )
    {
        pos = ������� �������;
        ��������� � count ����� wordNEW(file, word, pos);  //plus 1 if word is new
        ��������� ������ �� ������� pos;//return the cursor to the old position
        print������� ����� word;
    res = ���-�� ��������� ���������;
    }

    ������� count;
}

void histogram( FILE * file )
{
    ������� histogram
    ������� ������|| FILE * file;
    int count = 0, pos, res;
    char word[ STR_SIZE ];
    char templateSTR[ TEMPL_SIZE ];//to read a given number of characters
    ��������� ������ ��� ���������� ������;
    ���������� ������ � ������ �����;

    print������� ����� word;
    res = ���-�� ��������� ���������;
    for( ; res >= 1; )
    {
        pos = ������� �������;

        if( wordNEW( file, word, pos ) = 1 )
        {
            count = wordValue( file, word );
            putWORD( word, count );
        }
        ��������� ������ �� ������� pos;//return the cursor to the old position
        print������� ����� word;
    res = ���-�� ��������� ���������;
    }
}

int wordValue( FILE * file, char *word )//return how many times does the word occur
{
    ������� wordValue
    ������� ������||  FILE * file, char *word;
    int res, count = 0;
    char newWORD[ STR_SIZE ];
    char templateSTR[ TEMPL_SIZE ];//to read a given number of characters

    ��������� ������ ��� ���������� ������;
    ���������� ������ � ������ �����;

    print������� ����� newWORD;
    res = ���-�� ��������� ���������;
    for( ; res >= 1; )
    {
        if( word = newWORD )
            count = count + 1;
        print������� ����� newWORD;
       res = ���-�� ��������� ���������;
    }

    ������� count;
}

int wordNEW( FILE * file, char *word, int endPOS )//return how many times does the word occur
{
    ������� wordNEW
    ������� ������|| FILE * file, char *word, int endPOS;
    int res, pos;
    char newWORD[ STR_SIZE ];
    char templateSTR[ TEMPL_SIZE ];//to read a given number of characters

    ��������� ������ ��� ���������� ������;
    ���������� ������ � ������ �����;

    print������� ����� newWORD;
    res = ���-�� ��������� ���������;
    for( ; res >= 1 ; )
    {
        if( word = newWORD )
            break;
        print������� ����� newWORD;
        res = ���-�� ��������� ���������;
    }

    pos = ������� �������;
    if( pos >= endPOS )
        ������� 1;

    else ������� 0;
}
