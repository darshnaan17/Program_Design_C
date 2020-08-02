/*
*****************************************
*                                       *
*     Darshan Vala                      *
*     COP 3514                          *
*     U39780959                         *
*                                       *
*****************************************

This program uses the users prompt to sort out the requests for permits using a linked list. Depending
on what the user presses (a,u,p,q) different things will happen. If the user presses "a" then they
will be asked to enter the courseid, studentid, first name and last name. Their status then prints.
Once the user presses p it prints.  "u" updates the list and "q" clears.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define COURSE_LEN 100
#define NAME_LEN 30
#define STATUS_LEN 30

struct request{
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

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
  char code;

  struct request *permit_list = NULL;
  printf("Operation Code: a for appending to the list, u for updating a request"
	  ", p for printing the list; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': permit_list = append_to_list(permit_list);
                break;
      case 'u': update(permit_list);
                break;
      case 'p': printList(permit_list);
                break;
      case 'q': clearList(permit_list);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}

struct request *append_to_list(struct request *list){

 //this function asks the user for their courseID and studentID
 //Checks if the request already exists through their courseid and studentID
 //If it doesnt exist then it asks the user for their first and last name
 // It is then stored at the end of the list
 //
 struct request *execute;
 struct request *initial,*current;

 char *c_id, *s_id;
 char *f_name, *l_name;
 c_id = (char*) malloc (sizeof(char) *COURSE_LEN);
 s_id = (char*) malloc (sizeof(char) *NAME_LEN);
 l_name = (char*) malloc (sizeof(char) *NAME_LEN);
 f_name = (char*) malloc (sizeof(char) *NAME_LEN);

 printf("Enter courseID: ");
 read_line(c_id, COURSE_LEN);
  printf("Enter studentID: ");
 read_line(s_id, NAME_LEN);


 if(list == NULL) // if the list reaches the end it copies
                  // the courseID and studentID, takes the name,
                  //and prints pending until further updated
 {
     list = (struct request *) malloc(sizeof(struct request));
     list -> next = NULL;
     strcpy(list -> courseID, c_id);
     strcpy(list -> studentID, s_id);

     printf("Enter student last name: ");
     read_line(list -> last, NAME_LEN);
     printf("Enter student first name: ");
     read_line(list -> first, NAME_LEN);

     strcpy(list -> status, "pending"); return list;
 }
else
{
    current = list;
    while(current != NULL) // if it is not at the null value
                           // compare the studentID and the courseID
                           //If they are the same then tell the user
                           // return the list unchanged
    {
        if(!strcmp(current -> studentID,s_id) && !strcmp(current -> courseID,c_id))
        {
            printf("Already exists"); return list;

        }
        else // if there is a change then the current value is changed
        {
            initial = current;
            current = current -> next;
        }
    }
}
//this block of code takes
execute = (struct request *) malloc(sizeof(struct request));
execute -> next = NULL;
strcpy(execute -> courseID, c_id);
strcpy(execute -> studentID, s_id);
printf("Enter student last name: ");
read_line(execute -> last, NAME_LEN);
printf("Enter student first name: ");
read_line(execute -> first, NAME_LEN);
strcpy(list -> status, "pending");
initial -> next = execute;
return list;
}

void update(struct request *list)
{
// This function updates the requests
// The user enters their courseID and their studentID and then the status changes
//

struct request *initial,*temp;
char * c_id,* s_id;
char * status;
c_id = (char *)malloc(COURSE_LEN*sizeof(char));
s_id = (char *)malloc(NAME_LEN*sizeof(char));
status = (char *)malloc(STATUS_LEN*sizeof(char));

printf("Enter courseID: ");
read_line(c_id,COURSE_LEN);
printf("Enter studentID: ");
read_line(s_id,NAME_LEN);

if (list == NULL)
    {
        printf("No elements in the list");
    }
        else // Checking whether courseId and StudId exist then adding.
            {
                temp = list;
                while(temp != NULL)
                    {
                        if(!strcmp(temp->studentID,s_id) && !strcmp(temp->courseID,c_id))
                            {
                                printf("Enter new status: ");
                                read_line(temp->status,STATUS_LEN+1);
                                return;
                            }
                        else
                            {
                                initial = temp;
                                temp = temp->next;
                            }
                    }
            }
printf("No elements in the list are matching");
}


void printList(struct request *list){

  // prints the information sent
  while(list != NULL)
  {
      printf("\nCourseID: %s", list -> courseID);
      printf("\nStudentID: %s", list -> studentID);
      printf("\nFirst Name: %s", list -> first);
      printf("\nLast Name: %s", list -> last);
      printf("\nStatus: %s", list -> status);
      printf("\n***************************");
      list = list -> next;

  }

}
void clearList(struct request *list)
{

 //this command clears the list
 free(list);

}

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
