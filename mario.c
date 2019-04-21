#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    
    do
    {
        height = get_int("Height: ");
    }
    while (height <= 0 || height > 8);
    
    for(int i=0; i<height; i++) // Line
    {
        for(int j=height-i; j>1 ;j--) // Front space
        {
            printf(" ");
        }
        for(int j=0; j<i+1; j++) // Hash
        {
            printf("#");
        }
        {
            printf("  "); // Middle gap
        }
        for(int j=0; j<i+1; j++) // Hash 2
        {
            printf("#");
        }
        printf("\n");
    }
}
