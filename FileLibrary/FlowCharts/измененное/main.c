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

Функция main
Входные данные|| int argc, char ** argv;
    number = 1;
    
    if( argc = 1 )
    {
        printВывести("Enter first file status:");
        printВывести " "E" for open exist file" ;
        printВывести " "N" for create new file";
    }
    scanfCMD( str, argc, argv, &number );
    find_files( &input_first, str, argc, argv, &number  );

    if( number + 1 > argc )
        printВывести "Enter second file status:";
    scanfCMD( str, argc, argv, &number );
    find_files( &input_second, str, argc, argv, &number );

    if( number + 1 > argc )
        printВывести "Enter operation(-MIX, -STAT, -ALIGN, -SEARCH ):";
    scanfCMD( str, argc, argv, &number );
    operation( input_first, input_second, str, argc, argv, &number );

    fclose( input_first );
    fclose( input_second );
}
