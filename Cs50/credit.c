#include <stdio.h>
#include <cs50.h>
/**
 * American Express uses 15-digit, start with 34 or 37
 * MasterCard uses 16-digit , start with 51, 52, 53, 54, or 55
 * Visa uses 13 and 16, start with 4
 **/

int validate1(long long n, int c);
int validate2(long long n, int c);

//The mains function
int main(void)
{
    // First declaring the number, an aux to work with the number and a counter for the characteres
    long long number, aux;
    int count, a, b;
    count = 2;
    number = get_long("Number: ");
    aux = number;
    
    //Counting the characteres
    while (aux >= 100)
    {
        aux = aux / 10;
        count++;
    }
    
    //Calling the functions that will return the partial sums for validate the card
    a = validate1(number, count);
    b = validate2(number, count);
    
    //If the sum is valid, this will check what kind of card is.
    if ((a + b) % 10 == 0) 
    {
        if (count == 15 && (aux == 34 || aux == 37))
        {
            printf("AMEX\n");
        }
        else if (count == 16 && (aux == 51 || aux == 52 || aux == 53 || aux == 54 || aux == 55))
        {
            printf("MASTERCARD\n");
        }
        else if ((count == 13 || count == 16) && (aux > 39 && aux < 50))
        {
            printf("VISA\n");
        }
    }
    //If any of above are not true, INVALID message will return
    else
    {
        printf("INVALID\n");
    }
}

//Here its checking the sum from the end, as the exercises asks
int validate2(long long n, int c)
{
    int sum = n % 100;
    for (int i = 0; i <= c / 2; i++)
    {
        n = n / 100;
        sum += n % 10;
    }
    return sum;
}

// Here its checking the sum from second to last, as the exercises asks
int validate1(long long n, int c)
{
    n = n / 10;
    int sum = 2 * (n % 10);
    for (int i = 0; i <= c / 2; i++)
    {
        n = n / 100;
        if ((n % 10) > 4)
        {
            int x = (n % 10) * 2;
            sum += (x % 10) + ((x / 10) % 10);
        }
        else 
        {
            sum += 2 * (n % 10) ;
        }
    }
    return sum;
}
