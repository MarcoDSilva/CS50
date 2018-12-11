#include <stdio.h>
#include <cs50.h>

int main(void) 
{
    //get height from user
    int h = get_int("Height: ");
        
    // reprompt if it's negative or higher than 23
    if (h < 0 || h > 23)
    {
        h = get_int("Height: ");
    }
    
    //generate rows
    for (int i = 1; i <= h; i++) 
    {
        //loop that makes spaces equal to height number, then while is greater than row loop, reduces 1 space
        for (int sp = h; sp > i; sp--) 
        {
            printf(" ");
        }
        
        //while the loop is lower or equal to the row number (i) , add one extra
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        
        //space to change row
        printf("\n");
    }
}