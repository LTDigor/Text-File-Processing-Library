#ifndef _FILECMD_H_
#define _FILECMD_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_SIZE ( 100 )
#define STR_SCANF ( STR_SIZE - 1 )
#define TEMPL_SIZE ( 20 )
#define TEMPL_OUT ( 15 )
#define ERROR_OPEN ( 1 )

void put_remaining( FILE * file, int res, char * str );//prints characters after the end of the second file
void put_unprintf( FILE * file );//prints unprinted characters
int check_space( FILE * file );//checks for a space in a string
void put_space( int value );
void putWORD( char *word, int value );
void put_STAR( int value );
void scanfCMD( char *str, int argc, char **argv, int *number );//returns a pointer to the read line from CMD or menu

#endif
