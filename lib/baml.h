#ifndef BAML_H
# define BAML_H
# define ENTRYTOKEN "->"
# define HEADERTOKEN ';'
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * "valid_arg" takes the first argument and returns output format string list
 * if the argument is valid. returns NULL if the argument is invalid.
 * "valid_token" takes the line read from the file and check whether it has a 
 * valid entry token, returns index position located after the token. returns
 * zero if the argument is invalid.
 * "pheader" takes the line "hstr" comprising a valid token and prints header 
 * output according to the "format"; "hopen" is passed 0 when there is no 
 * previous header in the file.
 * "pentry" takes the line "hstr" comprising a valid token and prints entry
 * output according to the "format"; "hopen" is passed 1 when there is no
 * previous entry in the header, it is set to 2 when an entry is inserted.
 * "pitem" takes the target string and prints it by adding '\' for any quote
 * character and trimming the end of it.
 * "dstr" takes a "base" string and concatenates "tail" by dynamically
 * allocating memory. this function is used to store a complete line from
 * the file.
 */

char	**valid_arg(char *arg);
size_t	valid_token(char *store);
void	pitem(char *istr);
void	pheader(char *hstr, char **format, char *hopen);
void	pentry(char *estr, char **format, char *hopen);
size_t	dstr(char *base, char *tail);

#endif
