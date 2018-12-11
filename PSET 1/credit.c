#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //user input w long long
    long long cc_number = get_long_long("Number: ");
    
    //number without last number for calculations
    long long card = (cc_number / 10);
    
    //getting last number
    int last_digit = (cc_number % 10);
    // odd and even ints for the position inside the credit card
    int even = 0;
    int odd = 0;
    //counter for the sum of the credit card checksum
    int count = 0;
    //to seperate the digits for the final sum
    int tmp_ld = 0;
    int oth_num = 0;
    int ld_odd = 0;
    int ld_even = 0;
    //int to use as checksum and number of digits to check company
    int final_check = 0;
    int num_digits = 0;
    
    //checking number's length
    for (long long i = cc_number; i > 0; i = i / 10)
    {
        num_digits++;
    }

    //looping through the number to verify if card is valid
    do 
    {
        if (count % 2 != 1) //par
        {
            //get last digit and multiply it by 2
            ld_odd = (card % 10 * 2);
            
            //if the multiplied n is higher than 10, then separate both numbers to sum them 
            if (ld_odd >= 10) 
            {
                //temporary last digit and other number will be used to separate the digits of the numbers bigger than 10, and sum them separetly 
                tmp_ld = (ld_odd % 10);
                oth_num = (ld_odd / 10);
                even = (even + tmp_ld + oth_num);
            }
            else 
            {
                //sum the numbers
                even = (even + ld_odd);
            }
            
            // take 1 number from the card, and update count
            card = (card / 10);
            count = count + 1;
        }
        
        else if (count % 2 != 0) //impar
        {
            //get last digit
            ld_even = (card % 10);
        
            //odd sums with the last digit number
            odd = (odd + ld_even);
            
            // take 1 number from the card, and update count
            card = (card / 10);
            count = count + 1;
        }
    } 
    while (count < num_digits - 1);
   
    //validate checksum
    final_check = (odd + even + last_digit);
    
    //declaring longs to use in the checksum and getting a clear code
    long long amex_num = (cc_number / 10000000000000);
    
    long long master_num = (cc_number / 100000000000000);
    
    long long visa_num_short = (cc_number / 1000000000000);
    
    long long visa_num_long = (cc_number / 1000000000000000);
    
    //if the checksum is 0, it's valid and goes on, if not, give invalid
    if ((final_check % 10 != 0) || (num_digits < 12) || (num_digits > 17)) 
    {
        printf("INVALID\n");
    }
    else if ((num_digits = 16) && ((master_num == 51) || (master_num == 52) || (master_num == 53) || (master_num == 54)
                                   || (master_num == 55)))
    {
        printf("MASTERCARD\n");
    }
    else if ((num_digits = 13 && visa_num_short == 4) || (num_digits = 16 && visa_num_long == 4)) 
    {
        printf("VISA\n");
    }
    else if ((num_digits = 15) && ((amex_num == 34) || (amex_num == 37)))
    {
        printf("AMEX\n");
    }
    else 
    {
        printf("INVALID\n");
    }
}