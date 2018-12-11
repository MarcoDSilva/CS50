#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[]) 
{
    //verifying if argc has value 2, else program is terminated
    if (argc != 2) 
    {
        printf("Error! Please give only 1 key value, nor more or less.\n");
        return 1;
    }
    
    //passes the argv string, to an int named key
    int key = atoi(argv[1]);
    
    //ask he user and define the text that will be cyphered
    string text = get_string("plaintext: ");
    printf("ciphertext: ");
    
    //encipher the plaintext - for each character in the text, loops 1 by 1
    for (int i = 0, n = strlen(text); i < n; i++) 
    {
        //if it's alphabetic preserve case, and shift it by key
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                text[i] = (text[i] - 'A' + key) % 26 + 'A';
                printf("%c", text[i]);
            } 
            else if (islower(text[i]))
            {
                text[i] = (text[i] - 'a' + key) % 26 + 'a';
                printf("%c", text[i]);
            }
        }
        else //if it isn't text, just print the non text value
        {
            printf("%c", text[i]);
        }
    }

    printf("\n");
    return 0;
}