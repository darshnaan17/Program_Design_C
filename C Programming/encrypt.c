#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

//Darshan Vala COP3514
/*
    This program asks the user to input the length of the number they're wanting to type.
    Then the user inputs any number that is the same length as what they previously input, and is stored as arr[i].
    The program then print the key array that has been swapped and randomized 10 times.
    The program then compares the initial key array to arr[i] and stores the index/position of each number in a variable
    called j.
    A new array called b[] is then set to b[j] so that it stores all of the index positions.
    The program then prints the output that shows the index of each number that the user printed compared to the key array.
*/

// initializing functions
void swap(int arr[], int n);
void replace(int arr[], int b[], int key[], int n);

void swap(int arr[], int n)
{
    int temp, first_pos, second_pos;
    srand((unsigned)time(NULL)); // unsigned makes sure that we have no negative numbers

    int k;

    for(k = 0; k < N; k++)// Loop 10 times
    {
        first_pos = rand() % 10;
        second_pos = rand() % 10;

        temp = arr[first_pos];
        arr[first_pos] = arr[second_pos];
        arr[second_pos] = temp;
    }
}
void replace(int arr[], int b[], int key[], int n) // this is for array b
{
    int i, j;
    for(i = 0; i < n; i++)
    {
       for(j=0; j<N; j++)
       {
         if (arr[i] == key[j])      // sets arr[i] equal to the key array and j stores the index/ position
            b[i] = j;               // stores j and all of the index positions into array b
       }
    }
}
int main()
{
    int i,n;
    int arr[N],b[N], key[N]= {0,1,2,3,4,5,6,7,8,9}; // initializing variables
    printf("Enter the number of digits of the number: ");
    scanf("%d", &n);

    printf("Enter the number: ");
    for(i = 0; i < n; i++)
        scanf("%1d", &arr[i]);      // stores the number in arr[i]


    swap(key, N);                   //call the swap function and swaps/randomizes key array 10 times
    printf("Key array:");
    for(i = 0; i < N; i++)
    {
        printf(" %1d", key[i]);    // prints the 10 times randomized key array
    }
    replace(arr,b,key,n);          //calls the replace function and stores the index positions into array b

    printf("\nOutput: ");
    for(i = 0; i < n; i++)
        printf("%1d", b[i]);        //prints array b

    return 0;
}
