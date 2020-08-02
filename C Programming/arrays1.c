/*
****************************************************
*   Darshan Vala                                   *
*   COP3514                                        *
*   Project 4                                      *
*   array1.c                                       *
*                                                  *                                                 *
****************************************************

This program compares two arrays of same length and determines is
they are different by only one element or if they are not different
by only one element. The program prompts the user to enter the length
of the array. Then the user enters the array elements for array 1 and
then for array 2. The function one_element_different is called and
says that if array 1 is not equal to array 2 then return the positions
of where they are not the same. Else, add to both arrays.


*/
#include <stdio.h>

int one_element_different(int *a1, int *a2, int n, int *element1, int *element2);

int main()
{
    int i, j, num1, num2, n, decision;

    printf("Enter the length of the array: ");
    scanf("%d", &n);    // contains the length of the array

    int a1[n], a2[n]; //initialize array now that we have the length

    printf("Enter the elements of the first array: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a1[i]); // stores the input into array 1

    printf("Enter the elements of the second array: ");
    for (j = 0; j < n; j++)
        scanf("%d", &a2[j]); // stores the input into array 2

    decision = one_element_different(a1, a2, n, &num1, &num2); // sets decision equal to the one_element_different function and calls it
    {
        if(decision == 1)
        {
            printf("The arrays are different by one element, %d and %d.", num1, num2);
        }
        else
        {
            printf("The arrays are NOT different by one element.");
        }
    }

return 0;
}

int one_element_different(int *a1, int *a2, int n, int *element1, int *element2)
{
   int count = 0, loop_count = 0, decision = 0;
   for ( ; ; )      //infinite loop
   {
       if((*a1) != (*a2)) // if they do not equal each other
       {
           *element1 = *a1; //set the pointer elements equal to the pointer array
           *element2 = *a2;
           count++;     // increase the count
       }
       loop_count++;    // increase the loop count
       if( loop_count == n)  // once the loop count reaches the array length
                        break;
       else
       {
           a1++;
           a2++;
       }
   }
   if (count == 1)
    decision = 1;
    return decision;
}

