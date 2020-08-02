/*
****************************************************
*   Darshan Vala                                   *
*   COP3514                                        *
*   Project 4                                      *
*   array2.c                                       *
*                                                  *
****************************************************
This program adds the first and last elements of an integer array
and then uses pointer arithmetics in order to do so. Then it prints
out the array from the summation. If there is an odd amount of numbers
then all except the median is summed.
*/

#include <stdio.h>

void compute (int *a1, int n1, int *a2, int n2);

int main(void)
{
    int n, i, output_n; // array length, i, output length

    printf("Enter the length of the array: ");
    scanf("%d", &n);

    int a1[n]; // input array

    printf("Enter the elements of the array: ");
    for(i =0; i <n; i++)
        scanf("%d", &a1[i]);

    if(n % 2 == 1) // if it is odd
        output_n = ((n - 1) / 2 + 1);

    else
        output_n = (n / 2);

    int output_a[output_n];

    compute(a1, n, output_a, output_n); // function call
    printf("Output: \n");
    for(i = 0; i < output_n; i++)
    {
        printf("%d ", output_a[i]);
    }

return 0;
}

void compute (int *a1, int n1, int *a2, int n2)
{
    int *b, *c, loop_count = 0;
    b = a1;
    c = (a1 + (n1 - 1));

    if (n1 % 2 ==0) // if even
        for(; ; ) // infinite loop
        {
            *a2 = (*b + *c);
            b++;
            c--;
            a2++;
            loop_count++;
                        break;
        }
    else
        for(; ; )
        {
            if (loop_count == (n2 - 1))
            {
                *a2 = *b;
                break;
            }
            else
                *a2 = (*b + *c);
                b++;
                c--;
                a2++;
                loop_count++;
        }
}
