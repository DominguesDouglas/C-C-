#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main(void)
{
    //Declare the height of the pyramid
    int height = get_int("Height: "); 
    //Declared the space variable
    char space, hash;
    space = ' ';
    hash  = '#';
    
    //Check if its a valid value or Height   
    if (height > 0 && height < 9)
    {
        //Make the pyramide lines, if its a valid value
        for (int i = 1; i <= height; i++)
        {
            // Uses another loop to make the spaces
            for (int j = height - i; j > 0; j--)
            {
                printf("%c", space);      
            }
            // Uses another loop to make the first side of the pyramide
            for (int k = i; k > 0; k--)
            {
                printf("%c", hash);
            }
            // Print the spaces between the 2 pyramid sides
            printf("  ");
            // Uses another loop to make the second side
            for (int k = i; k > 0; k--)
            {
                printf("%c", hash);
            }
            printf("\n");
        }
    }
    //If its not a valid value, repeat the question
    else
    {
        main();
    }
}
