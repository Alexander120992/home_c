#include <stdio.h>

int main() {
    int number;
    int sum = 0;

    scanf("%d", &number);

    if (number <= 0) {
        printf("число должно быть натуральным (больше 0)\n");
        return 1;
    }

    while (number > 0) {
        sum += number % 10;  
        number /= 10;      
    }
    
    if (sum == 10) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}
