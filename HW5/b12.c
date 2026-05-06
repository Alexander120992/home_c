#include <stdio.h>

int main() {
    int number;
    
    scanf("%d", &number);

    if (number < 0) {
        printf("число должно быть неотрицательным\n");
        return 1;
    }

     if (number == 0) {
        printf("0 0\n");
        return 0;
    }
    
    int min_digit = number % 10;
    int max_digit = number % 10;
    
    number /= 10;
    
    while (number > 0) {
        int digit = number % 10;
        
        if (digit < min_digit) 
            min_digit = digit; 

        if (digit > max_digit) 
            max_digit = digit;
        
        number /= 10;
    }

    printf("%d %d\n", min_digit, max_digit);
    
    return 0;
}
