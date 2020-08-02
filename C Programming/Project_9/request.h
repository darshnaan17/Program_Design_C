/*
*****************************************
*                                       *
*     Darshan Vala                      *
*     COP 3514                          *
*     U39780959                         *
*                                       *
*****************************************
*/
#ifndef REQUEST_H_INCLUDED
#define REQUEST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define COURSE_LEN 100
#define NAME_LEN 30
#define STATUS_LEN 30
struct request
{
    char courseID[COURSE_LEN+1];
	char studentID[NAME_LEN+1];
	char first[NAME_LEN+1];
	char last[NAME_LEN+1];
	char status[STATUS_LEN+1];
	struct request *next;
};

struct request *append_to_list(struct request *list);
void update(struct request *list);
void printList(struct request *list);
void clearList(struct request *list);
int read_line(char str[], int n);

#endif // REQUEST_H_INCLUDED
