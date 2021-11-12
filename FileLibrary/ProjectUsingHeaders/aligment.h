#ifndef _FILEALI_H_
#define _FILEALI_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_SIZE ( 100 )
#define STR_SCANF ( STR_SIZE - 1 )
#define TEMPL_SIZE ( 20 )

void alignment( FILE * file, int spaceValue );//var1 alignment
void alignmentChoose( FILE * file_first, FILE * file_second, int argc, char **argv, int *number );

#endif