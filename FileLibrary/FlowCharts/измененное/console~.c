#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_SIZE ( 100 )
#define STR_SCANF ( STR_SIZE - 1 )
#define TEMPL_SIZE ( 20 )
#define TEMPL_OUT ( 15 )
#define ERROR_OPEN ( 1 )

void put_remaining( FILE * file, int res, char * str )//prints characters after the end of the second file
{
    char templateSTR[ TEMPL_SIZE ];//to read a given number of characters
    sprintf( templateSTR, "%%%is", STR_SCANF );

    for( ; res >= 1; )
    {
        printf( "%s", str );
        put_unprintf( file );
        res = fscanf( file, templateSTR, str );
    }
}

void put_unprintf( FILE * file )//prints unprinted characters
{
    char str[ STR_SIZE ];

    fscanf( file, "%[ ' ', '\n', '\t' ]", str );
    printf( "%s", str );
}

int check_space( FILE * file )//checks for a space in a string
{
    char symbol;

    symbol = fgetc( file );
    if( symbol == ' ' )
        return 1;

    fseek( file, -1, SEEK_CUR );
    return 0;
}

void put_space( FILE * file, int value )
{
    int i;

    for( i = 0; i < value; i++ )
        printf( " " );
}

void putWORD( char *word, int value )
{
     char templateOUT[ TEMPL_SIZE ];//to put word
     sprintf( templateOUT, "%%-%is", TEMPL_OUT );

     printf( templateOUT, word );
     printf( "%-3i ", value );
     put_STAR( value );
}

void put_STAR( int value )
{
    int i;

    for( i = 0; i < value; i++ )
       printf( "*" );

    printf( "\n" );
}

void scanfCMD( char *str, int argc, char **argv, int *number )//returns a pointer to the read line from CMD or menu
{
    int i;
    char templateSTR[ TEMPL_SIZE ];
    sprintf( templateSTR, "%%%is", STR_SCANF );

    if( *number + 1 > argc )//reading a line from menu
    {
        scanf( templateSTR, str );
    }
    else
    {
        for( i = 0; *( argv[ *number ] + i ); i++ )//reading a line from CMD
        {
            str[ i ] = *( argv[ *number ] + i );
        }
        str[ i ] = '\0';
        ( *number )++;
    }
}


