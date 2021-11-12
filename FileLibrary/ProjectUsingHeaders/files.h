#ifndef _FILE_H_
#define _FILE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_SIZE ( 100 )
#define STR_SCANF ( STR_SIZE - 1 )
#define ERROR_OPEN ( 1 )

void check_file( FILE * file );//file open success
void find_files( FILE ** file, char *str, int argc, char **argv, int *number );//add file in programm
void file_exist( FILE ** file, int argc, char **argv, int *number );//open exist file
void file_create( FILE **file, int argc, char **argv, int *number );//create new file
void operation( FILE *file_first, FILE *file_second, char *str, int argc, char **argv, int *number );

#endif