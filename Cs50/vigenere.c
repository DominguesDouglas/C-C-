#include <cs50.h>
#include <stdio.h>
#include <string.h>

int check_up_low(int letter);
int fill_ciph(int i, int key, string text);
void print_ciph(int chequer, int ciphered);
int keykey(int key);
int check_space(int ciphered);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        //length is the key length
        int length = strlen(argv[1]), key[length];
        //array para pegar o codigo ascii de cada letra, em um int
        for (int i = 0; i < length; i++)
        {
            //get letters for the key
            key[i] = (int) argv[1][i];
            //fill array key with the actual keys
            key[i] = keykey(key[i]);
        }
        //get the text that will be applied the changes
        string text = get_string("plaintext: ");
        //tl is the text length
        int tl = strlen(text) + 1;    
        int ciphered[tl];
        //loop to fill ciphered
        for (int i = 0; i < tl ; i++)
        {
            int j = 0;
            for (i = 0; i < tl ; i++)
            {
                if (j >= length)
                {
                    j = 0;
                }
                //apply the key to the ciphered array
                ciphered[i] = fill_ciph(i, key[j], text);
                // check if its a space charactere
                int space = check_space(ciphered[i]);
                //if its true, the key will not be applied
                if (space == 1)
                {
                    j --;
                }
                j++;
            }
            printf("ciphertext: ");
            for (i = 0; i < tl ; i++)
            {
                // check upper or lower case
                int chequer =  check_up_low(text[i]);
                //resete the word if it pass the Z or z
                print_ciph(chequer, ciphered[i]);
            }
        }
        printf("\n");
    }
    else
    {
        printf("Usage: ./vigenere keyword\n");
    }
    printf("\n");
    return 0;
}
//auxiliar functions
int check_up_low(int letter)
{
    if (letter < 91)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int fill_ciph(int i, int key, string text)
{
    int cipher;
    //ve se o caractere é espaço, assim deixando ele igual, ou se o caractere é passivel da aplicação da kay
    if (text[i] == 32)
    {
        cipher = text[i];
    }
    else
    {
        cipher = text[i] + (int) key; 
    }
    return cipher;
}

void print_ciph(int chequer, int ciphered)
{
    if (chequer == 1)//letra minuscula 97 - 122
    {
        //se a letra + a key passar a letra 'z', subtrai 26
        if (ciphered > 122)
        {
            ciphered -= 26;
            printf("%c",ciphered);
        }
        else
        {
            printf("%c",ciphered);
        }
    }
    else //letra maiuscula 65 -90
    {
        //se a letra + a key passar a letra 'Z', subtrai 26
        if (ciphered > 90)
        {
            ciphered -= 26;
            printf("%c",ciphered);
        }
        else
        {
            printf("%c",ciphered);
        }
    }
}
int keykey(int key)
{
    if (key > 96)
    {
        key -= 97;   
    }
    else
    {
        key -= 65;
    }
    return key;
}
int check_space(int ciphered)
{
    int space = 0;
    if (ciphered == 32)
    {
        space = 1;
    }
    return space;
}

    

