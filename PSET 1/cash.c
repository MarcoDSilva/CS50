#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void) 
{
    //declared coins as variables to be easier and in case we want to change the value for testing
    float n;
    int count = 0;
    int quarter = 25;
    int dime = 10;
    int nickel = 05;
    int penny = 01;
    
    //loop to unsure the user gives valid value
    do 
    {
        n = get_float("Change owed: ");
    }
    while (n <= 0);
    
    //convert from dollars to cents and 1 dollar to 100 cents
    int d = round(n * 100);
    
    //loop to use the largest coin
    while (d >= quarter)
    {
        d -= quarter;
        count++;
    }
    
    while (d >= dime)
    {
        d -= dime;
        count++;
    }
    
    while (d >= nickel) 
    {
        d -= nickel;
        count++;
    }
    
    while (d >= penny) 
    {
        d -= penny;
        count++;
    }
    
    //print the coins needed to deliver
    printf("%i\n", count);
    
}