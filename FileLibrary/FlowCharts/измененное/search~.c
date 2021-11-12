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
    char templateSTR[ TEMPL_SIZE ];//to read a given number of characters
    int res, i, position = 0;
    char str[ STR_SIZE ];

    sprintf( templateSTR, "%%%is", STR_SCANF );
    fseek( file, 0, SEEK_SET);

    printf( "\n" );
    res = fscanf( file, templateSTR, str );
    for( ; res >= 1; )
    {
        for( i = 0; str[ i ]; i++ )
        {};
        if( i == length )
        {
            position = ftell( file ) - length + 1;
            printf( "Position: %3i, word: %s\n", position, str );
        }
        res = fscanf( file, templateSTR, str );
    }
    if( position == 0 )
        printf( "No words of a given length\n" );
}

void searchChoose( FILE * file_first, FILE * file_second, int argc, char **argv, int *number )
{
    int numFile, length;
    char str[ STR_SIZE ];
    char templateSTR[ TEMPL_SIZE ];
    sprintf( templateSTR, "%%%is", STR_SCANF );

    if( *number + 1 > argc )
        printf("\nEnter file number: ");
    scanfCMD( str, argc, argv, number );//count the file number
    numFile = atoi( str );

    if( *number + 1 > argc )
        printf("\nEnter the word length: ");
    scanfCMD( str, argc, argv, number );//count the word length
    length = atoi( str );

    if( numFile == 1 )
        search( file_first, length );
    else
        search( file_second, length );
}
