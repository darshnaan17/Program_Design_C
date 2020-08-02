#include <stdio.h>


// Darshan Vala COP 3514

// This program checks the users input and tells them if it is a valid input based on if it
// has a hashtag. Whatever they type in as input can also include the alphabet (capitalized or lowercase),
// spaces, or numbers 0 through 9. If the input contains any other characters not specified previously, such
// as a question mark or a exclamation point, then it will print not valid.

int main()
{
    printf("Input: "); //asks the user for input
    int check = 1, ch; //check initialized to 1 so it will be true, if it becomes 0 then false
    ch = getchar(); // reads a character from the input
    if(ch != '#')   // if the input does not have a hashtag, then flase.
    {
        check = 0;
    }

    while ((ch = getchar()) != '\n')
    {
        //this condition checks so that the input can include the alphabet (capitalized or lowercase),
        // spaces, or numbers 0 through 9.

        if((ch >= 'A' && ch <= 'Z')||(ch == '_')||(ch >= 'a' && ch <= 'z')||(ch >= '0' && ch <= '9'))
        {
            continue;
        }

        else
        {
            check = 0;
        }
    }
    if (check ==0)  // if check was 0 then print not valid
    {
        printf("\nOutput: It is not a valid hashtag");
    }

    else    // check = 1 then print valid.
    {
        printf("\nOutput: It is a valid hashtag");
    }
}
