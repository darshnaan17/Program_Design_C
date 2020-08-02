#include <stdio.h>

// Darshan Vala COP 3514

int main()
{
    #define straw_b 1.99
    #define blue_b 4.39
    #define black_b 3.69
    #define rasp_b 5.99
    double weight_straw, weight_blue, weight_black, weight_rasp, change, amount_due = 0, payment;
    int preference, check = 0;

    //giving the user a menu for input

    printf("Please select a product: \n 1. strawberry - $1.99/lb \n 2. blueberry- $4.39/lb \n 3. blackberry $3.69/lb \n 4. raspberry - $5.99 \nEnter 0 to stop selection.");

    while(1)    // checking for exit statement
    {
        if(check == 1)
                    break;
        printf("\nEnter product selection: ");
        scanf("%d", &preference);

        //This switch statement will ask the user input for the weight and then multiply it by the
        //price per pound (lb) and then add that total towards amount_due. The loop will continue
        //for whatever preference chosen and then leave the loop once preference is 0.

        switch(preference)
        {
            case 4:  printf("\nEnter the product weight (lb): ");
                     scanf("%lf", &weight_rasp);
                     amount_due += weight_rasp * rasp_b;
                                                            break;

            case 3:  printf("\nEnter the product weight (lb): ");
                     scanf("%lf", &weight_black);
                     amount_due += weight_black * black_b;
                                                            break;

            case 2:  printf("\nEnter the product weight (lb): ");
                     scanf("%lf", &weight_blue);
                     amount_due += weight_blue * blue_b;
                                                            break;

            case 1:  printf("\nEnter the product weight (lb): ");
                     scanf("%lf", &weight_straw);
                     amount_due += weight_straw * straw_b;
                                                            break;

            case 0:
                     check = 1;                                                    // exit statement
                                                            break;

            default: printf("Invalid selection, select from 1 to 4, enter 0 to stop selection");  //pops up if preference<-1 or preference >5

        }
    }
     // Tell the user how much their total is for their selections and then prompts the user
     // to provide input for how much they are going to pay. Then the program calculates
     // and tells the user what their change is.

      printf("Amount due ($): $%.2f", amount_due);
      printf("\nCash received: $");
      scanf("%lf", &payment);
      change = payment - amount_due;
      printf("\nYour change is $%.2f", change);
}


    //This was something I was working on in case the user did not
    //provide enough money for the payment but I decided to comment
    //it out because I could not get it to work,


    /* while(amount_due > payment)
    {

     printf("Amount due ($): %d", &amount_due);
     printf("Cash received: ");
     scanf("d%", &payment);
     change = payment - amount_due;
        if (payment < amount_due)
        printf("Insufficient funds, you are short ($): %d", &change);


        else
         printf("Your change is ($): %d", &change);*/
   // }

