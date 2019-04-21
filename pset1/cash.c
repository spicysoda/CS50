#include <stdio.h>
#include <cs50.h>
#include <math.h>

void coins(float change);  

int main(void)
{
    float change;
    do
    {
    change = get_float("What is the change?\n");
    }
    while (change < 0);
        
    coins(change);    
}
    
void coins(float change)
{
    int change_cents = round(change*100); // convert change to cents
    int coins = 0;
    
    while (change_cents >= 25)
    {
        change_cents -= 25;
        coins++;
    }
    
    while (change_cents >= 10)
    {
        change_cents -= 10;
        coins++;
    }
    
        while (change_cents >= 5)
    {
        change_cents -= 5;
        coins++;
    }
    
        while (change_cents >= 1)
    {
        change_cents -= 1;
        coins++;
    }
    
    printf("%i\n", coins);
    
}

