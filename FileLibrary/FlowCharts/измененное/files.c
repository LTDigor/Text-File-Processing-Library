#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_SIZE ( 100 )
#define STR_SCANF ( STR_SIZE - 1 )
#define TEMPL_SIZE ( 20 )
#define TEMPL_OUT ( 15 )
#define ERROR_OPEN ( 1 )

void check_file( FILE * file )
{
    ������� check_file
    ������� ������|| FILE * file;
    if( file = NULL )
    {
        print ������� "File doesn't found\n";
        ��������� ���������, ��� ������ ERROR_OPEN;
    }
}

void find_files( FILE ** file, char *str, int argc, char **argv, int *number )
{

    ������� find_files
    ������� ������|| FILE ** file, char *str, int argc, char **argv, int *number;
    if( str = "-EXIST"    ��� *str == 'E' )
    {
        file_exist( file, argc, argv, number );
    }
    else if( str = "-NEW"        ��� *str = 'N' )
    {
        file_create( file, argc, argv, number );
    }
    else
        *file = NULL;
}

void file_exist( FILE ** file, int argc, char **argv, int *number )
{

    ������� file_exist
    ������� ������|| FILE ** file, int argc, char **argv, int *number;
    char name[ STR_SIZE ];

    if( *number + 1 > argc )
        print ������� "Enter the name of exist file:";
    scanfCMD( name, argc, argv, number );
    ������� ������������ ���� � ������ name;
    check_file( *file );
}

void file_create( FILE **file, int argc, char **argv, int *number )
{
    ������� file_create
    ������� ������|| FILE **file, int argc, char **argv, int *number;
    char name[ STR_SIZE ];
    char str[ STR_SIZE ];

    if( *number + 1 > argc )
        print ������� "Enter the name of new file: ";
    scanfCMD( name, argc, argv, number );
    ������� ���� � ������ name;
    check_file( *file );

    if( *number + 1 > argc )
        print ������� "Fill out the file, the word STOP stops entering";
    scanfCMD( str, argc, argv, number );

    for( ; str �� ����� "STOP"; )
    {
        print ���� str � ����;
        scanfCMD( str, argc, argv, number );
    }
    ��������� ������ � ������;
}

void operation( FILE * file_first, FILE * file_second, char *str, int argc, char **argv, int *number )
{

    ������� operation
    ������� ������|| FILE * file_first, FILE * file_second, char *str, int argc, char **argv, int *number;
    int numFile;

    if( str = "-MIX" )
        mixing( file_first, file_second );

    if( str = "-SEARCH" )
    {
        searchChoose( file_first, file_second, argc, argv, number );
    }
    if( str = "-ALIGN" )
    {
        alignmentChoose( file_first, file_second, argc, argv, number );
    }
    if( str = "-STAT" )
    {
        if( *number + 1 > argc )
            print ������� "Enter file number:";
        scanfCMD( str, argc, argv, number );//count the file number
        ���������� numFile � ����� �� str;
        if( numFile = 1 )
            statistick( file_first );
        else
            statistick( file_second );
    }
}




