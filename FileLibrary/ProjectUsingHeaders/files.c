#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_SIZE ( 100 )
#define STR_SCANF ( STR_SIZE - 1 )
#define ERROR_OPEN ( 1 )

void check_file( FILE * file )
{
    if( file == NULL )
    {
        printf( "File doesn't found\n" );
        exit( ERROR_OPEN );
    }
}

void find_files( FILE ** file, char *str, int argc, char **argv, int *number )
{
    if( strcmp( str, "-EXIST\0" ) == 0 || *str == 'E' )
    {
        file_exist( file, argc, argv, number );
    }
    else if( strcmp( str, "-NEW\0" ) == 0 || *str == 'N' )
    {
        file_create( file, argc, argv, number );
    }
    else
        *file = NULL;
}

void file_exist( FILE ** file, int argc, char **argv, int *number )
{
    char name[ STR_SIZE ];

    if( *number + 1 > argc )
        printf("\nEnter the name of exist file: ");
    scanfCMD( name, argc, argv, number );
    *file = fopen( name, "r" );
    check_file( *file );
}

void file_create( FILE **file, int argc, char **argv, int *number )
{
    char name[ STR_SIZE ];
    char str[ STR_SIZE ];

    if( *number + 1 > argc )
        printf("\nEnter the name of new file: ");
    scanfCMD( name, argc, argv, number );
    *file = fopen( name, "w+" );
    check_file( *file );

    if( *number + 1 > argc )
        printf("\nFill out the file, the word STOP stops entering\n ");
    scanfCMD( str, argc, argv, number );

    for( ; strcmp( str, "STOP\0" ) != 0; )
    {
        fprintf( *file, "%s ", str);
        scanfCMD( str, argc, argv, number );
    }
    fseek( *file, 0, SEEK_SET);
}

void operation( FILE * file_first, FILE * file_second, char *str, int argc, char **argv, int *number )
{
    int numFile;

    if( strcmp( str, "-MIX\0" ) == 0 )
        mixing( file_first, file_second );

    if( strcmp( str, "-SEARCH\0" ) == 0 )
    {
        searchChoose( file_first, file_second, argc, argv, number );
    }
    if( strcmp( str, "-ALIGN\0" ) == 0)
    {
        alignmentChoose( file_first, file_second, argc, argv, number );
    }
    if( strcmp( str, "-STAT\0" ) == 0 )
    {
        if( *number + 1 > argc )
            printf("\nEnter file number: ");
        scanfCMD( str, argc, argv, number );//count the file number
        numFile = atoi( str );
        if( numFile == 1 )
            statistick( file_first );
        else
            statistick( file_second );
    }
}