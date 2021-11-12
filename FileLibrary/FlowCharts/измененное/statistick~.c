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

void statistick( FILE * file )
{
    int all, different;

    all = allWords( file );
    different = diffWords( file );

    printf( "All words: %i\n", all );
    printf( "Different words: %i\n\n", different );

    histogram( file );
}

int allWords( FILE * file )//count all words
{
    int count = 0, res;
    char str[ STR_SIZE ];
    char templateSTR[ TEMPL_SIZE ];//to read a given number of characters
    sprintf( templateSTR, "%%%is", STR_SCANF );
    fseek( file, 0, SEEK_SET );

    res = fscanf( file, templateSTR, str );
    for( ; res >= 1; )
    {
        count++;
        res = fscanf( file, templateSTR, str );
    }

    return count;
}

int diffWords( FILE * file )//count different words
{
    int count = 0, pos, res;
    char word[ STR_SIZE ];
    char templateSTR[ TEMPL_SIZE ];//to read a given number of characters

    sprintf( templateSTR, "%%%is", STR_SCANF );
    fseek( file, 0, SEEK_SET );

    res = fscanf( file, templateSTR, word );
    for( ; res >= 1; )
    {
        pos = ftell( file );
        count += wordNEW( file, word, pos );  //plus 1 if word is new
        fseek( file, pos, SEEK_SET );//return the cursor to the old position
        res = fscanf( file, templateSTR, word );
    }

    return count;
}

void histogram( FILE * file )
{
    int count = 0, pos, res;
    char word[ STR_SIZE ];
    char templateSTR[ TEMPL_SIZE ];//to read a given number of characters
    sprintf( templateSTR, "%%%is", STR_SCANF );
    fseek( file, 0, SEEK_SET );

    res = fscanf( file, templateSTR, word );
    for( ; res >= 1; )
    {
        pos = ftell( file );

        if( wordNEW( file, word, pos ) )
        {
            count = wordValue( file, word );
            putWORD( word, count );
        }
        fseek( file, pos, SEEK_SET );//return the cursor to the old position
        res = fscanf( file, templateSTR, word );
    }
}

int wordValue( FILE * file, char *word )//return how many times does the word occur
{
    int res, count = 0;
    char newWORD[ STR_SIZE ];
    char templateSTR[ TEMPL_SIZE ];//to read a given number of characters

    sprintf( templateSTR, "%%%is", STR_SCANF );
    fseek( file, 0, SEEK_SET );

    res = fscanf( file, templateSTR, newWORD );
    for( ; res >= 1; )
    {
        if( strcmp( word, newWORD ) == 0 )
            count++;
        res = fscanf( file, templateSTR, newWORD );
    }

    return count;
}

int wordNEW( FILE * file, char *word, int endPOS )//return how many times does the word occur
{
    int res, pos;
    char newWORD[ STR_SIZE ];
    char templateSTR[ TEMPL_SIZE ];//to read a given number of characters

    sprintf( templateSTR, "%%%is", STR_SCANF );
    fseek( file, 0, SEEK_SET );

    res = fscanf( file, templateSTR, newWORD );
    for( ; res >= 1 ; )
    {
        if( strcmp( word, newWORD ) == 0 )
            break;
        res = fscanf( file, templateSTR, newWORD );
    }

    pos = ftell( file );
    if( pos >= endPOS )
        return 1;

    return 0;
}
