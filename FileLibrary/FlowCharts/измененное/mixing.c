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

void mixing( FILE * src_first, FILE * src_second )//var6 mixing
{
    Функция mixing
    Входные данные|| FILE * src_first, FILE * src_second;
    res1, res2 = 1;
    i = 0;
    char str[ STR_SIZE ], templateSTR[ TEMPL_SIZE ];//to read a given number of characters

    Передвинуть курсор в обоих файлах в начало;
    Заполнить шаблон для считывания строки;
    put_unprintf( src_first );

    Считать слово str из 1-го файла
    res1 равен кол-ву считанных файлов;
    for(; Считывание из обоих файлов успешно( res1 и res2 > 0 ); )
    {
        printВывести str;
        put_unprintf( src_first );
        if( i - чётное )
        {
        Считать слово str из 1-го файла
        res1 равен кол-ву считанных файлов;
        Считать слово str из 2-го файла
        res2 равен кол-ву считанных файлов;
        }
        else
        {
        Считать слово str из 2-го файла
        res2 равен кол-ву считанных файлов;
        Считать слово str из 1-го файла
        res1 равен кол-ву считанных файлов;
        }
        i = i + 1;
    }
    put_remaining( src_first, res1, str );//prints characters after the end of the second file
}
