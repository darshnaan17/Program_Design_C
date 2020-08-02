#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*Darshan Vala
  This program displays options for trucks and asks the user to select a truck by picking a number 1-4. If they
  select a number not within the range it will tell the user it is not within range and end the program. It then asks
  the user to select how many hours they want to rent the truck for and then how many minutes. The program then calculates
  the information given and prints out how much the cost would be to rent out the particular truck with the given time rented.
*/



/*This lists my variables and the max, min, and rate cost related to each truck numerically and according to the menu
  printed on line 32.
*/
int main(void)
{
    #define max_truck4 99
    #define max_truck3 89
    #define max_truck2 69
    #define max_truck1 49
    #define min_truck4 29
    #define min_truck3 25
    #define min_truck2 19
    #define min_truck1 15
    #define rate_truck4 10
    #define rate_truck3 8
    #define rate_truck2 5
    #define rate_truck1 4
    int minutes, hours, truck, total_min, total_cost, total_rate;

    /* This asks the user to select from the menu by typing a number 1 through 4. If the number they input is
       less than 1 or greater than 4 then the program lets the user know that the number they selected is out
       of range and ends the program. If the input is a number 1 through 4 then the program saves this input
       under the variable "trucks." Next the program prompts the user to input the hours rented and saves the
       input under "hours."The program then asks the user to input the minutes rented and saves it under the
       variable "minutes."
    */

    printf("Please select from the following menu: 1. Flatbed pickup truck I, 2. Flatbed pickup truck II, 3. Cargo van, 4. Moving box truck\n");
    printf("Enter truck selection:\n ");
    scanf("%d", &truck);
    if(truck < 1 || truck > 4)
    {
        printf("Not within range. Please select a number 1-4");
        exit(0);
    }
    printf("Enter hours rented:\n ");
    scanf("%d", &hours);
    printf("Enter minutes rented:\n ");
    scanf("%d", &minutes);


 /*
    According to the 1-4 input given for "trucks" the program will go to that particular case and
    execute three math equations to solve for the total cost. The math equation is the same for
    each case while the numbers only change, so I am going to describe the equations. First the
    program solves for the total minutes (total_min) by adding the minutes input to the hours
    input multiplied by 60 (to convert hours to minutes) and then subtracting that total by 75.
    We are subtracting the total by 75 because for the first 75 minutes the cost for any truck
    will just be its minimum truck cost (min_truck1, min_truck2, min_truck3, min_truck4). The
    program then checks to see if total_min is greater than 0 (or is a positive number). If it
    greater than 0 then it solves for a variable called total_rate (total rate) which takes the
    ceiling (ceil) of the total minutes divided by 15 and then that number is multiplied by the
    rate according to the related truck (rate_truck4, rate_truck3, rate_truck2, rate_truck1). The
    final variable to be solved for is the total cost (total_cost) which adds the total_rate and
    the minimum cost according to the related truck (min_truck1, min_truck2, min_truck3, min_truck4).
    But if the total cost is greater than the maximum cost for the trucks (max_truck4 = 99,
    max_truck3 = 89, max_truck2 = 69, max_truck1 = 49) then the program will print that the amount
    due is equal to the maximum cost for the truck. However, if the total minutes is less than or
    equal to 0 then the program will print that the amount due is equal to the minimum cost for the truck.
    Otherwise the program will print the total_cost as the amount due. The system breaks and the program
    ends.
 */
    switch (truck)
    {
        case 4:
               total_min = ((((((minutes+((hours*60)))-75)))));
                 if(total_min > 0)
                 {
                    total_rate = ((ceil(((total_min/15.0))))*rate_truck4);
                    total_cost = (total_rate + min_truck4);
                 }
                 else if(total_min <=0)
                 {
                    printf("Amount due ($): %d", min_truck4);
                 }
                 else if ((total_cost > max_truck4))
                 {
                    printf("Amount due ($): %d", max_truck4);
                 }
                 else
                 {
                    printf("Amount due is ($): %d", total_cost);
                 }

                 break;
        case 3:
                 total_min = ((((((minutes+((hours*60)))-75)))));
                 if(total_min > 0)
                 {
                    total_rate = ((ceil(((total_min/15.0))))*rate_truck3);
                    total_cost = (total_rate + min_truck3);
                 }
                 else if (total_min <= 0)
                 {
                    printf("Amount due ($): %d", min_truck3);
                 }
                 if ((total_cost > max_truck3))
                 {
                    printf("Amount due ($): %d", max_truck3);
                 }
                 else
                 {
                    printf("Amount due is ($): %d", total_cost);
                 }
                 break;
        case 2:
                 total_min = ((((((minutes+((hours*60)))-75)))));
                 if(total_min > 0)
                 {
                    total_rate = ((ceil(((total_min/15.0))))*rate_truck2);
                    total_cost = (total_rate + min_truck2);
                 }
                 else if (total_min <= 0)
                 {
                    printf("Amount due ($): %d", min_truck2);
                 }
                 if ((total_cost > max_truck2))
                 {
                    printf("Amount due ($): %d", max_truck2);
                 }
                 else
                 {
                    printf("Amount due is ($): %d", total_cost);
                 }
                 break;
        case 1:
                 total_min = ((((((minutes+((hours*60)))-75)))));
                 if(total_min > 0)
                 {
                    total_rate = ((ceil(((total_min/15.0))))*rate_truck1);
                    total_cost = (total_rate + min_truck1);
                 }
                 else if (total_min <= 0)
                 {
                    printf("Amount due ($): %d", min_truck1);
                 }
                 if ((total_cost > max_truck1))
                 {
                    printf("Amount due ($): %d", max_truck1);
                 }
                 else
                 {
                    printf("Amount due is ($): %d", total_cost);
                 }
                 break;
        default:                                               // The default is just in case the user hacks and gets past my code in lines 35 - 39 :) .
                    printf("Not within range");
                    exit(0);

    }
    return 0;  // ends the program.
}
