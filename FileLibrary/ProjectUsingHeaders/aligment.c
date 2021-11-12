#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "files.h"
#include "console.h"

#define STR_SIZE ( 100 )
#define STR_SCANF ( STR_SIZE - 1 )
#define TEMPL_SIZE ( 20 )

void alignment( FILE * file, int spaceValue )//var1 alignment
{
    int res;
    char str[ STR_SIZE ];
    char templateAligment[ TEMPL_SIZE ];//to read until new line

    fseek( file, 0, SEEK_SET );
    sprintf( templateAligment, "%%%i[^\n]", STR_SCANF );

    if( check_space( file ) )
            put_space( spaceValue );

    res = fscanf( file, templateAligment, str );
    for( ; res >= 1; )
    {
        printf( "%s\n", str );
        fseek( file, 2, SEEK_CUR );

        if( check_space( file ) )
            put_space( spaceValue);

        res = fscanf( file, templateAligment, str );
    }
}

void alignmentChoose( FILE * file_first, FILE * file_second, int argc, char **argv, int *number )
{
    int numFile, length;
    char str[ STR_SIZE ];

    if( *number + 1 > argc )
        printf("\nEnter file number: ");
    scanfCMD( str, argc, argv, number );//count the file number
    numFile = atoi( str );

    if( *number + 1 > argc )
        printf("\nEnter the length of the red string: ");
    scanfCMD( str, argc, argv, number );//count the length of the red string
    length = atoi( str );

    if( numFile == 1 )
        alignment( file_first, length );
    else
        alignment( file_second, length );
}
