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
    ������� mixing
    ������� ������|| FILE * src_first, FILE * src_second;
    res1, res2 = 1;
    i = 0;
    char str[ STR_SIZE ], templateSTR[ TEMPL_SIZE ];//to read a given number of characters

    ����������� ������ � ����� ������ � ������;
    ��������� ������ ��� ���������� ������;
    put_unprintf( src_first );

    ������� ����� str �� 1-�� �����
    res1 ����� ���-�� ��������� ������;
    for(; ���������� �� ����� ������ �������( res1 � res2 > 0 ); )
    {
        print������� str;
        put_unprintf( src_first );
        if( i - ������ )
        {
        ������� ����� str �� 1-�� �����
        res1 ����� ���-�� ��������� ������;
        ������� ����� str �� 2-�� �����
        res2 ����� ���-�� ��������� ������;
        }
        else
        {
        ������� ����� str �� 2-�� �����
        res2 ����� ���-�� ��������� ������;
        ������� ����� str �� 1-�� �����
        res1 ����� ���-�� ��������� ������;
        }
        i = i + 1;
    }
    put_remaining( src_first, res1, str );//prints characters after the end of the second file
}
