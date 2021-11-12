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


void alignment( FILE * file, int spaceValue )//var1 alignment
{
    Функция alignment
    Входные данные||  FILE * file, int spaceValue;
    int res;
    char str[ STR_SIZE ];
    char templateAligment[ TEMPL_SIZE ];//to read until new line

    Передвинуть курсор в начало файла;
    Заполнить шаблон для считывания строки до символа новой строки;

    if( check_space( file ) )
            put_space( file, spaceValue);

    printСчитать строку str;
    res = кол-во считанных строк;
    for( ; res >= 1; )
    {
        printВывести str;
        Передвинуть курсор в файле вперед на 2;

        if( check_space( file ) )
            put_space( file, spaceValue);

        printСчитать строку str0;
       res = кол-во считанных строк;
    }
}

void alignmentChoose( FILE * file_first, FILE * file_second, int argc, char **argv, int *number )
{   
    Функция alignmentChoose
    Входные данные||  FILE * file_first, FILE * file_second, int argc, char **argv, int *number;
    int numFile, length;
    char str[ STR_SIZE ];
                                  p
    if( *number + 1 > argc )
        printf("\nEnter file number: ");
    scanfCMD( str, argc, argv, number );//count the file number
    numFile = atoi( str );

    if( *number + 1 > argc )
        printВывести "Введ;
    scanfCMD( str, argc, argv, number );//count the length of the red string
    length = atoi( str );

    if( numFile = 1 )
        alignment( file_first, length );
    else
        alignment( file_second, length );
}
