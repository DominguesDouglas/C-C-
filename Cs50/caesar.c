#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int check(char c, int check); // this function checks if the user is providing a valid key or not
int uplow(char c); //this one verifys if the letters provided to the plaintext are upper, lower and also if they are special characteres
int apply(int uporlow, int c,int k); // this ano apply the changes with the key provided

int main(int argc, string argv[])
{
    //leng is the length of the key
    int leng = strlen(argv[1]);
    //leng1 is the length of the provided plaintext
    int leng1 = 0;
    //k is the key number extracted from the string argv
    int k = atoi(argv[1]);
    //c is going to be set to 0 if there is any letter in the argv string, using the isdigit function
    int c = 1;
    //text is the string provided by the user to be ciphered
    string text;
    
    for (int i = 0; i < leng; i++)
    {
        c = check(argv[1][i], c);
    }
    
    if (argc != 2 || c == 0)
    {
        printf("Usage: ./caesar key\n");
    }
    else
    {
        text = get_string("plaintext: ");
        leng1 = strlen(text);
        printf("ciphertext: ");
    }
    for (int i = 0; i < leng1; i++)
    {
        int ul;
        ul = uplow(text[i]);
        text[i] = apply(ul, text[i], k);
        printf("%c",text[i]);
    }
    printf("\n");
}

int check(char c, int check)
{
    if (c != 0)
    {
        check = isdigit(c);
    }
    return check;
}
//return 1 if lower case
int uplow(char c)
{
    if (c > 96 && c < 123)
    {
        return 1;
    }
    else if (c > 64 && c < 91)
    {
        return 2;
    }
    else
    {
        return 0;
    }
    
}

int apply(int uporlow, int c, int k)
{
    if (uporlow == 2)
    {
        c = c - 65;
        c = c + k;
        c = c % 26;
        c = c + 65;
        return c;
    }
    else if (uporlow == 1)
    {
        c -= 97;
        c += k;
        c = c % 26;
        c += 97;
        return c;
    }
    else
    {
        return c;
    }
}
