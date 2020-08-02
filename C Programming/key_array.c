#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

//Darshan Vala COP3514

/*
    This program generates a key array, consisting of numbers 0-9, and randomizes the positions by swapping indexes 10 times.
    It then outputs the key array.
*/
void swap (int arr[], int n)
{
    int temp, first_pos, second_pos;
    srand(time(NULL));

    for(n = 0; n < N; n++)// Loop 10 times
    {
        first_pos = rand() % 10;
        second_pos = rand() % 10;

        temp = arr[first_pos];
        arr[first_pos] = arr[second_pos];
        arr[second_pos] = temp;
    }
}
int main()
{
    int arr[N] = {0,1,2,3,4,5,6,7,8,9}; // set the numbers in the array
    swap(arr,N);                        // swaps the array N amount of times, which is 10.
    int i;
    for(i = 0; i < N; i++)
    printf("%d ", arr[i]);
    return 0;
}


