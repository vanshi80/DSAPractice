#include <stdio.h>

// Recursive function to compute power using divide-and-conquer
long long int power(int base, int exponent) {
    printf("power(%d, %d) called\n", base, exponent); // Print the current recursive call
    
    // Base case: any number raised to the power of 0 is 1
    if (exponent == 0)
        return 1;

    // If the exponent is even
    if (exponent % 2 == 0) {
        long long int temp = power(base, exponent / 2);
        long long int result = temp * temp;
        printf("power(%d, %d) returns %lld\n", base, exponent, result); // Print the result before returning
        return result;
    } 
    // If the exponent is odd
    else {
        long long int result = base * power(base, exponent - 1);
        printf("power(%d, %d) returns %lld\n", base, exponent, result); // Print the result before returning
        return result;
    }
}

int main() {
    int base, exponent;

    // Read base and exponent from standard input
    scanf("%d", &base); 
    scanf("%d", &exponent);
    
    // Calculate base^exponent using the recursive function
    long long int result = power(base, exponent);
    
    // Print the final result
    printf("Result: %lld\n", result);
    return 0;
}
