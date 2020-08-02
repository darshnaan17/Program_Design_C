/*
*****************************************
*                                       *
*     Darshan Vala                      *
*     COP 3514                          *
*     U39780959                         *
*                                       *
*****************************************
*/
#include <stdio.h>
#include <ctype.h>
#include "readline.h"

int read_line(char str[], int n)
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  str[i++] = ch;
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;

   }
   str[i] = '\0';
   return i;
}
