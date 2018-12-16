// Helper functions for music

#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    //assume numerator and denominator are each one digit , the first chara is numerator, slash at mid, last chara is denominator
    //convert that chara into a number
    int numerator = atoi(&fraction[0]);
    int denominator = atoi(&fraction[2]);
    
    //assume that the fraction works out to a whole number of eight notes, make math to get 8 / demon. and * numer.
    int eights = (8 / denominator) * numerator;
    return eights;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    char letter = note[0];
    char accidental = 'x'; //x is a placeholder to not have bugs with the statements
    int octaveNum;
    double freq = 0.0;
    
    //check string lenght to get the accidental and the octave(turning it into a int)
    if (strlen(note) == 3) 
    {
        accidental = note[1];
        octaveNum = atoi(&note[2]);
    }
    else
    {
        octaveNum = atoi(&note[1]);
    }
    
    //calculating letters freq without octaves
    if (letter == 'A')
    {
        freq = 440;
    }
    else if (letter == 'B')
    {
        freq = 440 * pow(2.0, (2.0 / 12));
    }
    else if (letter == 'C')
    {
        freq = 440 / pow(2.0, (9.0 / 12));
    }
    else if (letter == 'D')
    {
        freq = 440 / pow(2.0, (7.0 / 12));
    }
    else if (letter == 'E')
    {
        freq = 440 / pow(2.0, (5.0 / 12));
    }
    else if (letter == 'F')
    {
        freq = 440 / pow(2.0, (4.0 / 12));
    }
    else if (letter == 'G')
    {
        freq = 440 / pow(2.0, (2.0 / 12));
    }
    
    //calculate the frequency of the note in the given octave
    //I used a if, else if, tried a shorter for loop
    if (octaveNum < 4)
    {
        for (int i = 0; i < 4 - octaveNum; i++)
        {
            freq = freq / 2.0;
        }
    }
    else if (octaveNum > 4)
    {
        for (int i = 0; i < octaveNum - 4; i++)
        {
            freq = freq * 2.0;
        }
    }
    
    //Adding the calculation to the notes with the accidental
    if (accidental == '#') 
    {
        freq = freq * pow(2.0, (1.0 / 12.0));
    }
    else if (accidental == 'b')
    {
        freq = freq / pow(2.0, (1.0 / 12.0));
    }
    
    //return the frequency 
    return round(freq);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    //if S represents a rest(fist chara is the null character) returns true 
    if (s[0] == '\0')
    {
        return true;
    } 
    else
    {
        return false;
    }
}
