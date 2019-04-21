#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[]) {         // check for 2 arg 
   
     if (argc != 2) {
        printf("Usage: ./caesar key");
        
    return 1;
    }
    
    int number = atoi(argv[1]); 
        
    if (number <= 0) {                     // check for number & positive
        printf("Usage: ./caesar key");
        
    return 1;
    }    
    
// user input  
  
    string input = get_string("Input:\n");
    printf("ciphertext: "); // output
    int key = number;

// keeps key less than 26
    while (key > 26) {
        key -=26;
    }  

// cipher each char
  
    for (int i = 0, n = strlen(input); i < n; i++ ) {
 
            if (isalpha(input[i])) {

// brings char back to first of alphabet by minusing total alphabets (26). 
              
                if ((isupper(input[i]) && (input[i] + key > 'Z')) || (islower(input[i]) && (input[i] + key > 'z'))) {
                    int output = (input[i] + key) - 26;
                    printf("%c", output);
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



