#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "files.h"
#include "console.h"

#define STR_SIZE ( 100 )
#define STR_SCANF ( STR_SIZE - 1 )
#define TEMPL_SIZE ( 20 )

void mixing( FILE * src_first, FILE * src_second )//var6 mixing
{
    int i, res1, res2 = 1;
    char str[ STR_SIZE ], templateSTR[ TEMPL_SIZE ];//to read a given number of characters

    fseek( src_first, 0, SEEK_SET );
    fseek( src_second, 0, SEEK_SET );
    sprintf( templateSTR, "%%%is", STR_SCANF );

    printf( "\n" );
    put_unprintf( src_first );

    res1 = fscanf( src_first, templateSTR, str );
    for( i = 0; res1 >= 1 && res2 >= 1; i++ )
    {
        printf( "%s", str );
        put_unprintf( src_first );
        if( i % 2 == 0 )
        {
            res1 = fscanf( src_first, templateSTR, str );
            res2 = fscanf( src_second, templateSTR, str );
        }
        else
        {
            res2 = fscanf( src_second, templateSTR, str );
            res1 = fscanf( src_first, templateSTR, str );
        }
    }
    put_remaining( src_first, res1, str );//prints characters after the end of the second file
    printf( "\n" );
}
