#include <stdio.h>
#include <cs50.h>
#include <math.h>

void coins(float change);  

int main(void)
{
    float change;
    do
    {
    change = get_float("What is the change?\n");          // user input
    }
    while (change < 0);
        
    coins(change);    
}
    
void coins(float change)
{
    int change_cents = round(change*100); // convert change to cents
    int coins = 0;
    
    while (change_cents >= 25)          // when amount is more than 25, divide by 25. Add no. of division of amt of coins
    {                                   // when amount less than 25, move to next loop
        change_cents -= 25;
        coins++;
    }
    
    while (change_cents >= 10)          // 10 cents
    {
        change_cents -= 10;
        coins++;
    }
    
        while (change_cents >= 5)       // 5 cents
    {
        change_cents -= 5;
        coins++;
    }
    
        while (change_cents >= 1)       // 1 cent
    {
        change_cents -= 1;
        coins++;
    }
    
    printf("%i\n", coins);
    
}

