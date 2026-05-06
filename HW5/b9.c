#include <stdio.h>

int main() {
    int number;
    
    scanf("%d", &number);

    if (number == 0) {
        printf("NO\n");
        return 0;
    }

    while (number > 0) {
        int digit = number % 10; 

        if (digit % 2 != 0) { 
            printf("NO\n");
            return 0; 
        }
        
        number /= 10; 
    }
    
    printf("YES\n");
    
    return 0;
}
