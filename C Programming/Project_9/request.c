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
#include "request.h"


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
