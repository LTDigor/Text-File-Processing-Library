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

    Функция put_remaining
    Входные данные||                FILE * file, int res, char * str;
    char templateSTR[ TEMPL_SIZE ];//to read a given number of characters
    Заполнить шаблон для считывания строки;

    for( ; Строка считана?( res >= 1 ); )
    {
        Вывести строку str;
        put_unprintf( file );
        Считать строку str;
    }
}

void put_unprintf( FILE * file )//prints unprinted characters
{
    char str[ STR_SIZE ];
    Функция put_unprintf
    Входные данные|| FILE * file;

    print Считать в строку str непечатные символы;
    print Вывести str;
}

int check_space( FILE * file )//checks for a space in a string
{
    char symbol;
    Функция check_space
    Входные данные|| FILE * file;

    Считать символ из файла;
    if( Символ - пробел )
        Вернуть 1;

    Сдвинуть курсор на 1 влево;
    Вернуть 0;
}

void put_space( int value )
{
    Функция put_space
    Входные данные|| int value;
    
    i = 0;
    
    for(; i < value; )
    {
        print Вывести пробел;
        i = i + 1;
        }
}

void putWORD( char *word, int value )
{
     char templateOUT[ TEMPL_SIZE ];//to put word
     Функция putWORD
     Входные данные|| char *word, int value;
     Заполнить шаблон для форматированного                           вывода слова;

     print Вывести слово по шаблону;
     print Вывести сколько раз value оно встречается в тексте ;
     put_STAR( value );
}

void put_STAR( int value )
{       
     Функция put_STAR
     Входные данные|| int value;
     i = 0;
    for( ; i < value; )
    {
          print Вывести "*";
          i = i+1;
    }
       

    print Вывести символ новой строки;
}

void scanfCMD( char *str, int argc, char **argv, int *number )//returns a pointer to the read line from CMD or menu
{

     Функция scanfCMD
     Входные данные|| char *str, int argc, char **argv, int *number;
    char templateSTR[ TEMPL_SIZE ];
    Заполнить шаблон для считывания строки;

    if( *number + 1 > argc )//reading a line from menu
    {
        print Считать строку str;
    }
    else
    {
          Копировать строку argv[*number] в строку str;
         ( *number ) = 1 + *number;
    }
}


