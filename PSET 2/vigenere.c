#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[]) 
{
    //verifying if argc has value 2 and the keyword is valid, else program is terminated
    if (argc != 2) 
    {
        printf("Error! Please give only 1 key value, nor more or less.\n");
        return 1;
    }
    
    //argv value passed to a string and int counters for keyword && plaintext
    string key = argv[1]; //make a string get the value of argv1
    int keySize = strlen(key); //length of key in a int
    int plaintextCount = 0; 
    int keyCount;
    
    //verifying if argv1 has non alphabetic characters
    for (int i = 0, n = strlen(key); i < n; i++) 
    {
        if (!isalpha(key[i])) //if not alpha, print error
        {
            printf("Error! Only alphabetic keys allowed.\n");
            return 1;
        }
    }
    
    //ask he user and define the text that will be cyphered
    string text = get_string("plaintext: ");
    printf("ciphertext: ");
    
    //turning the key into alphanumeric A:0, B:1, so on..
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (isupper(key[i]))
        {
            key[i] = (key[i] - 'A');
        } 
        else if (islower(key[i]))
        {
            key[i] = (key[i] - 'a');
        }    
    }
    
    //encipher the plaintext - for each character in the text, loops 1 by 1
    for (int i = 0, n = strlen(text); i < n; i++) 
    {
        //if it's alphabetic preserve case, and shift it by key
        if (isalpha(text[i]))
        {
            keyCount = plaintextCount % keySize;
                
            if (isupper(text[i]))
            {
                text[i] = ((((text[i] + key[keyCount]) - 'A') % 26)
                           + 'A'); //conversion ascii to numerical and vice versa, and looping with the key pos
                printf("%c", text[i]);
                plaintextCount++;
            } 
            else if (islower(text[i]))
            {
                text[i] = ((((text[i] + key[keyCount]) - 'a') % 26) + 'a');
                printf("%c", text[i]);
                plaintextCount++;
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