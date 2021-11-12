//Name: BDZ2 -  with libraries
//Author: Olennikov V.D.
//Creation date: 30.03.2020

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aligment.h"
#include "console.h"
#include "files.h"
#include "mixing.h"
#include "search.h"
#include "statistick.h"

#define STR_SIZE ( 100 )
#define STR_SCANF ( STR_SIZE - 1 )
#define TEMPL_SIZE ( 20 )
#define TEMPL_OUT ( 15 )
#define ERROR_OPEN ( 1 )

int main( int argc, char ** argv )
{
    int number = 1;
    FILE * input_first, * input_second;
    char str[ STR_SIZE ];

    if( number + 1 > argc )
    {
        printf("Enter first file status:\n");
        printf( "\"E\" for open exist file\n" );
        printf( "\"N\" for create new file\n" );
    }
    scanfCMD( str, argc, argv, &number );
    find_files( &input_first, str, argc, argv, &number  );

    if( number + 1 > argc )
        printf("\nEnter second file status : ");
    scanfCMD( str, argc, argv, &number );
    find_files( &input_second, str, argc, argv, &number );

    if( number + 1 > argc )
        printf("\nEnter operation( -MIX, -STAT, -ALIGN, -SEARCH ): ");
    scanfCMD( str, argc, argv, &number );
    operation( input_first, input_second, str, argc, argv, &number );

    fclose( input_first );
    fclose( input_second );
}
