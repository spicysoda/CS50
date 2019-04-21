#include <stdio.h>
#include <cs50.h>
#include <math.h>

int ccLength(long ccNumber);
int ccSum(long ccNumber);
string ccBrand(long ccNumber);
void ccValidation(long ccNumber);

int main(void) {
    long ccNumber;

    //Prompts user for input and validates it as non-negative
    do {
        ccNumber = get_long("What is the number?\n");
    }
    while (ccNumber <= 0);
    
    ccValidation(ccNumber); //run validation function
    
    return 0;
}

// check length

int ccLength(long ccNumber) {
    int length = 0;
    long tempNumber = ccNumber;
    
    while (tempNumber > 0) {
        tempNumber /= 10;
        length++;
    }
    
    return length;
}


// checksum

int ccSum(long ccNumber) {
    
    int sum_odd = 0;
    int sum_even = 0;
    long tempNumber = ccNumber;
    
    for (int i=0; i < ccLength(ccNumber); i++) {
       
        int single_number = tempNumber % 10;       // get last number of CCnumber
        tempNumber /= 10;
        
        if (i % 2 != 0) {                          // odd number
            
            single_number *= 2;
            sum_odd += (single_number / 10) + (single_number % 10);
        }        
        else {                                   // even number
            sum_even += single_number;
        }
    }
    
    int sum_number = sum_odd + sum_even;
    
    return sum_number;
}

// check brand

string ccBrand(long ccNumber) {
    
    long tempNumber = ccNumber;
    int length = ccLength(ccNumber);
    
    int amex_length = 15;
    int master_length = 16;
    int visa_length13 = 13;
    int visa_length16 = 16;
        
    // int amex_number = 34 | 37;
    // int master_number = 51 | 52 | 53 | 54;
    // int visa_number = 4;
    
    while (tempNumber > 100)                                // Get first 2 brand number
    {
        tempNumber /= 10;
    }
    
    int brand_number = tempNumber;
    
    if (length == amex_length && (brand_number == 34 || brand_number == 37)) {
        return "AMEX";
    }
    
    else if (length == master_length && (brand_number >= 51 && brand_number <= 55)) { 
        return "MASTERCARD";
    }
    
    else if ((length == visa_length13 || length == visa_length16) && brand_number / 10 == 4){    // divide 10 to compare single 4
        return "VISA";
    }
    
    return "";
}

// validation of cc

void ccValidation(long ccNumber) {
    
    if (ccLength(ccNumber) == 13 || ccLength(ccNumber) == 15 || ccLength(ccNumber) == 16) {     // validation of length
        
        if (ccSum(ccNumber) % 10 == 0) {                                                        // validation of sum
            printf("%s\n", ccBrand(ccNumber));
        }
        else {                              // decline wrong sum
            printf("INVALID\n");
        }
    }                                      //decline wrong length
    else {
        printf("INVALID\n");
    }
}


