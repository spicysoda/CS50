#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{ 
    if (argc != 2)
    {
        printf("Usage: ./caesar key");
        
    return 1;
    }
    
    int key = atoi(argv[1]);
        
        if (key <= 0)
    {
        printf("Usage: ./caesar key");
        
    return 1;
    }    
    
    string input = get_string("Input:\n"); // input
    printf("ciphertext: "); // output
      
    for (int i = 0, n = strlen(input); i < n; i++ ) {
 
        if (isalpha(input[i])) {
                
            if (isupper(input[i])) {
                input[i] = ((input[i] + key) - 'A') % 26;
                printf("%c", input[i] + 'A');
            }
                
            else if (islower(input[i])) {
                input[i] = ((input[i] + key) - 'a') % 26;
                printf("%c", input[i] + 'a');
            }  
                     
            else {
                int output =  input[i] + key;
                printf("%c", output);
            }
        }
        
        else {
            printf("%c", input[i]);         
         }
    }
 
    printf("\n");
    return 0;    
        
}



