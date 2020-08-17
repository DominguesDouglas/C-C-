#include <cs50.h>
#include <stdio.h>
#include <crypt.h>
#include <string.h>

int nchar(char *strn, int size);

//strcmp
int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string hashed = {0};
        hashed = argv[1];
        if (strlen(hashed) != 13)
        {
            printf("INVALID HASH\n");
            return 1;
        }
        else
        {
            int size = 5;
            char salt [2] = {0}, strn[5] = {0};
            //pega os 2 primeiros numeros da hash para usar como salt
            salt[0] = hashed [0];
            salt[1] = hashed [1];
            while(nchar(strn, size))
            {
                if (strcmp(argv[1], crypt(strn,salt)) == 0)
                {
                    printf("%s",strn);
                    break;
                }
            }
            printf("\n");
        }
    }
    else
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
    return 0;
}

//function that makes the possible combinations by char
int nchar(char *strn, int size) 
{
    for (int i = 0; i < size; i++) {
        if (strn[i] == '\0') {
            strn[i] = 'A';
            break;
        }
        if (strn[i] == 'Z') {
            strn[i] = 'a';
            break;
        }
        if (strn[i] == 'z') {
            if (i == size - 1)
                return 0;
            strn[i] = 'A';
        }
        else {
            strn[i]++;
            break;
        }
    }
    return 1;
}
