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
    ������� search
    ������� ������|| FILE * file, int length;
    char templateSTR[ TEMPL_SIZE ];//to read a given number of characters
    int res, i, position = 0;
    char str[ STR_SIZE ];

    ��������� ������ ��� ���������� ������;
    ���������� ������ � ������;

    print������� ����� str;
    res ����� ���-�� ��������� ���������;
    for( ; res >= 1; )
    {
        if( ����� str ����� length )
        {
            position = ������� ������� - length + 1;
            print������� ������� � ����� �����;
        }
        print������� ����� str;
        res ����� ���-�� ��������� ���������;
    }
    if( position = 0 )
        print������� "��� ���� �������� �����";
}

void searchChoose( FILE * file_first, FILE * file_second, int argc, char **argv, int *number )
{
    ������� searchChoose
    ������� ������|| FILE * file_first, FILE * file_second, int argc, char **argv, int *number;
    int numFile, length;
    char str[ STR_SIZE ];
    char templateSTR[ TEMPL_SIZE ];
    ��������� ������ ��� ���������� ������;

    if( *number + 1 > argc )
        print����� "������� ����� �����";
    scanfCMD( str, argc, argv, number );//count the file number
    numFile = ����� �� str;

    if( *number + 1 > argc )
        print����� "������� ����� �����";
    scanfCMD( str, argc, argv, number );//count the word length
    length = ����� �� str;

    if( numFile = 1 )
        search( file_first, length );
    else
        search( file_second, length );
}
