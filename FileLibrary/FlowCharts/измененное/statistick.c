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
    Функция statistick
    Входные данные|| FILE * file;
    int all, different;

    all = allWords( file );
    different = diffWords( file );

    printВывести all;
    printВывести different;

    histogram( file );
}

int allWords( FILE * file )//count all words
{
    Функция allWords
    Входные данные|| FILE * file;
    int count = 0, res;
    char str[ STR_SIZE ];
    char templateSTR[ TEMPL_SIZE ];//to read a given number of characters
    Заполнить шаблон для считывания строки;
    Установить курсор в начало файла;

    printСчитать слово str;
    res = кол-во считанных элементов;
    for( ; res >= 1; )
    {
        printСчитать слово str;
    res = кол-во считанных элементов;
    }

    Вернуть count;
}

int diffWords( FILE * file )//count different words
{
    Функция diffWords
    Входные данные|| FILE * file;
    int count = 0, pos, res;
    char word[ STR_SIZE ];
    char templateSTR[ TEMPL_SIZE ];//to read a given number of characters

    Заполнить шаблон для считывания строки;
    Установить курсор в начало файла;

    printСчитать слово word;
    res = кол-во считанных элементов;
    for( ; res >= 1; )
    {
        pos = Позиция курсора;
        Прибавить к count число wordNEW(file, word, pos);  //plus 1 if word is new
        Поставить курсор на позицию pos;//return the cursor to the old position
        printСчитать слово word;
    res = кол-во считанных элементов;
    }

    Вернуть count;
}

void histogram( FILE * file )
{
    Функция histogram
    Входные данные|| FILE * file;
    int count = 0, pos, res;
    char word[ STR_SIZE ];
    char templateSTR[ TEMPL_SIZE ];//to read a given number of characters
    Заполнить шаблон для считывания строки;
    Установить курсор в начало файла;

    printСчитать слово word;
    res = кол-во считанных элементов;
    for( ; res >= 1; )
    {
        pos = Позиция курсора;

        if( wordNEW( file, word, pos ) = 1 )
        {
            count = wordValue( file, word );
            putWORD( word, count );
        }
        Поставить курсор на позицию pos;//return the cursor to the old position
        printСчитать слово word;
    res = кол-во считанных элементов;
    }
}

int wordValue( FILE * file, char *word )//return how many times does the word occur
{
    Функция wordValue
    Входные данные||  FILE * file, char *word;
    int res, count = 0;
    char newWORD[ STR_SIZE ];
    char templateSTR[ TEMPL_SIZE ];//to read a given number of characters

    Заполнить шаблон для считывания строки;
    Установить курсор в начало файла;

    printСчитать слово newWORD;
    res = кол-во считанных элементов;
    for( ; res >= 1; )
    {
        if( word = newWORD )
            count = count + 1;
        printСчитать слово newWORD;
       res = кол-во считанных элементов;
    }

    Вернуть count;
}

int wordNEW( FILE * file, char *word, int endPOS )//return how many times does the word occur
{
    Функция wordNEW
    Входные данные|| FILE * file, char *word, int endPOS;
    int res, pos;
    char newWORD[ STR_SIZE ];
    char templateSTR[ TEMPL_SIZE ];//to read a given number of characters

    Заполнить шаблон для считывания строки;
    Установить курсор в начало файла;

    printСчитать слово newWORD;
    res = кол-во считанных элементов;
    for( ; res >= 1 ; )
    {
        if( word = newWORD )
            break;
        printСчитать слово newWORD;
        res = кол-во считанных элементов;
    }

    pos = Позиция курсора;
    if( pos >= endPOS )
        Вернуть 1;

    else Вернуть 0;
}
