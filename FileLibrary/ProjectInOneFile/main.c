//Name: BDZ2 - all in one file
//"Creating a project and a library of custom
//text file processing programs"
//Author: Vadim Olennikov.
//Creation date: 27.03.2020

//o1 1.txt o2 2.txt s 1 e

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_SIZE ( 100 )
#define STR_SCANF ( STR_SIZE - 1 )
#define TEMPL_SIZE ( 20 )
#define TEMPL_OUT ( 15 )
#define ERROR_OPEN ( 1 )

void check_file( FILE * file );//file open success
void mixing( FILE * src_first, FILE * src_second );//var6 mixing
void mixingChoose( FILE * file_first, FILE * file_second, int argc, char **argv, int *number );
void put_remaining( FILE * file, int res, char * str );//prints characters after the end of the second file
void put_unprintf( FILE * file );//prints unprinted characters
void alignment( FILE * file, int spaceValue );//var1 alignment
void alignmentChoose( FILE * file_first, FILE * file_second, int argc, char **argv, int *number );
int check_space( FILE * file );//checks for a space in a string
void put_space( FILE * file, int value );
void search( FILE * file, int length );//var5 search
void searchChoose( FILE * file_first, FILE * file_second, int argc, char **argv, int *number );
void find_files( FILE ** file, char *str, int argc, char **argv, int *number );
void file_exist( FILE ** file, int argc, char **argv, int *number );
void file_create( FILE **file, int argc, char **argv, int *number );
void statistick( FILE * file );
int allWords( FILE * file );//count all words
int diffWords( FILE * file );//count different words
void histogram( FILE * file );
void putWORD( char *word, int value );
void put_STAR( int value );
int wordValue( FILE * file, char *word );//return how many times does the word occur
int wordNEW( FILE * file, char *word, int endPOS );//return how many times does the word occur
void operation( FILE *file_first, FILE *file_second, char *str, int argc, char **argv, int *number );
void operationFiles( FILE * file_first, FILE * file_second, char *str, int argc, char **argv, int *number );
void scanfCMD( char *str, int argc, char **argv, int *number );//returns a pointer to the read line from CMD or menu
void menuChoose();
void menuFile();


int main( int argc, char ** argv )
{
    int number = 1;
    FILE * input_first, * input_second;
    char str[ STR_SIZE ];

    if( number + 1 > argc )
    {
        printf("For first file\n");
        menuFile();
    }

    scanfCMD( str, argc, argv, &number );
    find_files( &input_first, str, argc, argv, &number  );

    if( number + 1 > argc )
    {
        printf("\nFor second file\n");
        menuFile();
    }
    scanfCMD( str, argc, argv, &number );
    find_files( &input_second, str, argc, argv, &number );

    operation( input_first, input_second, str, argc, argv, &number );

    fclose( input_first );
    fclose( input_second );
}

void check_file( FILE * file )
{
    if( file == NULL )
    {
        printf( "File doesn't found\n" );
        exit( ERROR_OPEN );
    }
}

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

void mixingChoose( FILE * file_first, FILE * file_second, int argc, char **argv, int *number )
{
    int numFile, length;
    char str[ STR_SIZE ];
    char templateSTR[ TEMPL_SIZE ];
    sprintf( templateSTR, "%%%is", STR_SCANF );

    if( *number + 1 > argc )
        printf("\nEnter the file number in which you want to replace the words: ");
    scanfCMD( str, argc, argv, number );//count the file number
    numFile = atoi( str );

    if( numFile == 1 )
        mixing( file_first, file_second );
    else
        mixing( file_second, file_first );
}

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

void alignment( FILE * file, int spaceValue )//var1 alignment
{
    int res;
    char str[ STR_SIZE ];
    char templateAligment[ TEMPL_SIZE ];//to read until new line

    fseek( file, 0, SEEK_SET );
    sprintf( templateAligment, "%%%i[^\n]", STR_SCANF );

    check_space( file );
    res = fscanf( file, templateAligment, str );
    for( ; res >= 1; )
    {
        printf( "%s\n", str );
        fseek( file, 2, SEEK_CUR );

        res = check_space( file );
        if( res )
            put_space( file, spaceValue);

        res = fscanf( file, templateAligment, str );
    }
}

void alignmentChoose( FILE * file_first, FILE * file_second, int argc, char **argv, int *number )
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
        printf("\nEnter the length of the red string: ");
    scanfCMD( str, argc, argv, number );//count the length of the red string
    length = atoi( str );

    if( numFile == 1 )
        alignment( file_first, length );
    else
        alignment( file_second, length );
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

void find_files( FILE ** file, char *str, int argc, char **argv, int *number )
{
    if( strcmp( str, "-EXIST\0" ) == 0 || *str == 'o' )
    {
        file_exist( file, argc, argv, number );
    }
    else if( strcmp( str, "-NEW\0" ) == 0 || *str == 'n' )
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

    for( ; strncmp( str, "STOP\0", 5 ) != 0; )
    {
        fprintf( *file, "%s ", str);
        scanfCMD( str, argc, argv, number );
    }
    fseek( *file, 0, SEEK_SET);
}

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

int wordNEW( FILE * file, char *word, int endPOS )//return 1 if the word occur once
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

void operation( FILE * file_first, FILE * file_second, char *str, int argc, char **argv, int *number )
{
    int numFile;
    if( *number + 1 > argc )
        menuChoose();
    scanfCMD( str, argc, argv, number );

    if( strcmp( str, "-MIX\0" ) == 0 || *str == 'm' )
        mixingChoose( file_first, file_second, argc, argv, number );
    if( strcmp( str, "-SEARCH\0" ) == 0  || *str == 's' )
        searchChoose( file_first, file_second, argc, argv, number );
    if( strcmp( str, "-ALIGN\0" ) == 0 || *str == 'a' )
        alignmentChoose( file_first, file_second, argc, argv, number );
    if( strcmp( str, "-STAT\0" ) == 0 || *str == 'h' )
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
    operationFiles( file_first, file_second, str, argc, argv, number );
    operation( file_first, file_second, str, argc, argv, number );
}

void operationFiles( FILE * file_first, FILE * file_second, char *str, int argc, char **argv, int *number )
{
    if( strcmp( str, "n1\0" ) == 0 )
    {
        find_files(  &file_first, "N", argc, argv, number );
        operation( file_first, file_second, str, argc, argv, number );
    }
    if( strcmp( str, "n2\0" ) == 0 )
    {
        find_files(  &file_second, "n", argc, argv, number );
        operation( file_first, file_second, str, argc, argv, number );
    }
    if( strcmp( str, "o1\0" ) == 0 )
    {
        find_files(  &file_first, "o", argc, argv, number );
        operation( file_first, file_second, str, argc, argv, number );
    }
    if( strcmp( str, "o2\0" ) == 0 )
    {
        find_files(  &file_second, "o", argc, argv, number );
        operation( file_first, file_second, str, argc, argv, number );
    }
    if( *str == 'e' )
        exit( 0 );
}

void scanfCMD( char *str, int argc, char **argv, int *number )//returns a pointer to the read line from CMD or menu
{
    char templateSTR[ TEMPL_SIZE ];
    sprintf( templateSTR, "%%%is", STR_SCANF );

    if( *number + 1 > argc )//reading a line from menu
    {
        scanf( templateSTR, str );
    }
    else
    {
        strcpy( str, argv[ *number ] );
        ( *number )++;
    }
}

void menuChoose()
{
    printf( "\nEnter operation:\n" );
    printf( "m - mixing, replace all even words of the first file with odd words from the second file\n" );
    printf( "s - search, find a word of a given length in the file, display the word and its position\n" );
    printf( "a - alignment, set a red line of size N spaces if the line starts with a space\n" );
    printf( "h - histogram and statistics, count the total number and number of different words in the file and plot the distribution histogram\n" );
    printf( "n1 - create new first file\n" );
    printf( "n2 - create new second file\n" );
    printf( "o1 - open exist first file\n" );
    printf( "o2 - open exist second file\n" );
    printf( "e - exit\n\n" );
    printf( "Operation: " );

}

void menuFile()
{
    printf("Choose operation:\n");
    printf( "n - for create new file\n" );
    printf( "o - for open exist file\n" );
    printf("Operation: ");
}
//o1 text.txt o2 1.txt s 1 e
