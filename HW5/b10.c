#include <stdio.h>

int main() {
    int number;
    
    scanf("%d", &number);

    if (number < 10) {
        printf("YES\n");
        return 0;
    }

    int prev_digit = number % 10;
    number /= 10;

    while (number > 0) {
        int current_digit = number % 10;

        if (current_digit >= prev_digit) {
            printf("NO\n");
            return 0;
        }
        
        prev_digit = current_digit;
        number /= 10;
    }
    
    printf("YES\n");
    return 0;
}
