/*
*****************************************
*                                       *
*     Darshan Vala                      *
*     COP 3514                          *
*     U39780959                         *
*                                       *
*****************************************

This code takes a given input file and sorts it so that the list included
is in descending order. It also takes that file and renames it with an added
"sorted_" to ensure that the file has been modified. Other than the main
function, there is a sort_games function, which does the sorts the list
in descending order, and a struct game.
*/
#include <stdio.h>
#include <string.h>
#define num_games 100
#define exit_s 1


struct game
{
    int quant, available;
    char names[num_games];
};

void sort_games(struct game list[], int n);
int main()
{
    char input[num_games];
    char output[num_games] = "sorted_"; // stores the characters but also makes sure the output has "sorted" so concatinazation is possible

    printf("Enter the file name: "); //receives file name as input
    scanf("%s", input);

    FILE *fp = fopen(input, "r");   // opens the file for reading purposes

    if(fp == NULL)
        {
            printf("Cannot open filename: %s\n", input); // for the case if file cannot be opened
            return exit_s;  // returns 1 and exit
        }

    printf("Output file name: %s\n", strcat(output, input)); // prints the output file name as having it start with sorted_
    FILE *outputfp = fopen(output,"w"); // opens the file for writing

    struct game PS4_games[num_games];

    int i;
    int count = 0;

    while(fscanf(fp, "%d %d %[^\n]\n", &PS4_games[count].quant, &PS4_games[count].available, PS4_games[count].names) == 3) // is reading the input from the listed variables
        {
            count++; // incrementing count
        }

    sort_games(PS4_games, count);
    for(i=0; i<count; i++)
        {
            fprintf(outputfp, "%d %d %s\n", PS4_games[i].quant, PS4_games[i].available, PS4_games[i].names); // prints the formatted output
        }

    fclose (outputfp), (fp); // closes both of the files.
    return 0;
}

void sort_games(struct game list[], int n) // this function is making it so it sorts the contents of the file in descending order, it uses a temporary variable to swap
{
    int j, k;

    for(j=0; j<n-1; j++)
        {
            for(k=0;k<(n-1-j); k++)
                {
                    if(list[k].quant < list[k+1].quant)
                        {
                            struct game temp = list[k];
                            list[k] = list[k+1];
                            list[k+1] = temp;
                        }
                }
        }
}
