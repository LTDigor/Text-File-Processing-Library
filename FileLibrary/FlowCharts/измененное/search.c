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

void search( FILE * file, int length )//var5 search
{
    Функция search
    Входные данные|| FILE * file, int length;
    char templateSTR[ TEMPL_SIZE ];//to read a given number of characters
    int res, i, position = 0;
    char str[ STR_SIZE ];

    Заполнить шаблон для считывания строки;
    Установить курсор в начало;

    printСчитать слово str;
    res равен кол-ву считанных элементов;
    for( ; res >= 1; )
    {
        if( Длина str равна length )
        {
            position = Позиция курсора - length + 1;
            printВывести позицию и номер слова;
        }
        printСчитать слово str;
        res равен кол-ву считанных элементов;
    }
    if( position = 0 )
        printВывести "Нет слов заданной длины";
}

void searchChoose( FILE * file_first, FILE * file_second, int argc, char **argv, int *number )
{
    Функция searchChoose
    Входные данные|| FILE * file_first, FILE * file_second, int argc, char **argv, int *number;
    int numFile, length;
    char str[ STR_SIZE ];
    char templateSTR[ TEMPL_SIZE ];
    Заполнить шаблон для считывания строки;

    if( *number + 1 > argc )
        printВывод "Введите номер файла";
    scanfCMD( str, argc, argv, number );//count the file number
    numFile = число из str;

    if( *number + 1 > argc )
        printВывод "Введите длину слова";
    scanfCMD( str, argc, argv, number );//count the word length
    length = число из str;

    if( numFile = 1 )
        search( file_first, length );
    else
        search( file_second, length );
}
