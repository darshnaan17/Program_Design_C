/*
*****************************************
*                                       *
*     Darshan Vala                      *
*     COP 3514                          *
*     U39780959                         *
*                                       *
*****************************************
*/
#include "readline.h"
#include "request.h"


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
      case 'a': permit_list = insert_to_order(permit_list);
                //permit_list = append_to_list(permit_list);
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
