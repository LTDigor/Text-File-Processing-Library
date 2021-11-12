#ifndef _FILESTAT_H_
#define _FILESTAT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_SIZE ( 100 )
#define STR_SCANF ( STR_SIZE - 1 )
#define TEMPL_SIZE ( 20 )
#define TEMPL_OUT ( 15 )
#define ERROR_OPEN ( 1 )

void statistick( FILE * file );
int allWords( FILE * file );//count all words
int diffWords( FILE * file );//count different words
void histogram( FILE * file );
int wordValue( FILE * file, char *word );//return how many times does the word occur
int wordNEW( FILE * file, char *word, int endPOS );//return how many times does the word occur


#endif
