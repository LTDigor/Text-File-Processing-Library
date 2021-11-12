#ifndef _FILESEARCH_H_
#define _FILESEARCH_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_SIZE ( 100 )
#define STR_SCANF ( STR_SIZE - 1 )
#define TEMPL_SIZE ( 20 )

void search( FILE * file, int length );//var5 search
void searchChoose( FILE * file_first, FILE * file_second, int argc, char **argv, int *number );


#endif