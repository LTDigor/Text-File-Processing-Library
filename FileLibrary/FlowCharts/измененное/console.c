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

    ������� put_remaining
    ������� ������||                FILE * file, int res, char * str;
    char templateSTR[ TEMPL_SIZE ];//to read a given number of characters
    ��������� ������ ��� ���������� ������;

    for( ; ������ �������?( res >= 1 ); )
    {
        ������� ������ str;
        put_unprintf( file );
        ������� ������ str;
    }
}

void put_unprintf( FILE * file )//prints unprinted characters
{
    char str[ STR_SIZE ];
    ������� put_unprintf
    ������� ������|| FILE * file;

    print ������� � ������ str ���������� �������;
    print ������� str;
}

int check_space( FILE * file )//checks for a space in a string
{
    char symbol;
    ������� check_space
    ������� ������|| FILE * file;

    ������� ������ �� �����;
    if( ������ - ������ )
        ������� 1;

    �������� ������ �� 1 �����;
    ������� 0;
}

void put_space( int value )
{
    ������� put_space
    ������� ������|| int value;
    
    i = 0;
    
    for(; i < value; )
    {
        print ������� ������;
        i = i + 1;
        }
}

void putWORD( char *word, int value )
{
     char templateOUT[ TEMPL_SIZE ];//to put word
     ������� putWORD
     ������� ������|| char *word, int value;
     ��������� ������ ��� ����������������                           ������ �����;

     print ������� ����� �� �������;
     print ������� ������� ��� value ��� ����������� � ������ ;
     put_STAR( value );
}

void put_STAR( int value )
{       
     ������� put_STAR
     ������� ������|| int value;
     i = 0;
    for( ; i < value; )
    {
          print ������� "*";
          i = i+1;
    }
       

    print ������� ������ ����� ������;
}

void scanfCMD( char *str, int argc, char **argv, int *number )//returns a pointer to the read line from CMD or menu
{

     ������� scanfCMD
     ������� ������|| char *str, int argc, char **argv, int *number;
    char templateSTR[ TEMPL_SIZE ];
    ��������� ������ ��� ���������� ������;

    if( *number + 1 > argc )//reading a line from menu
    {
        print ������� ������ str;
    }
    else
    {
          ���������� ������ argv[*number] � ������ str;
         ( *number ) = 1 + *number;
    }
}


