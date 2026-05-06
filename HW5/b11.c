#include <stdio.h>

int main() {
    int number;
    int reversed = 0;
    
    scanf("%d", &number);

    if (number < 0) {
        printf("число должно быть неотрицательным\n");
        return 1;
    }

    if (number == 0) {
        printf("0\n");
        return 0;
    }

    while (number > 0) {
        int digit = number % 10;           
        reversed = reversed * 10 + digit;  
        number /= 10;                      
    }

    printf("%d\n", reversed);
    
    return 0;
}
