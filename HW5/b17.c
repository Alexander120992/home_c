#include <stdio.h>

int main() {
    int n;
    int found = 0; 
    
    scanf("%d", &n);
    
    if (n <= 10) {
        return 1; 
    }
    
    for (int num = 10; num <= n; num++) {
        int temp = num;
        int sum = 0;
        int product = 1;
        
        while (temp > 0) {
            int digit = temp % 10;
            sum += digit;
            product *= digit;
            temp /= 10;
        }
        
        if (sum == product) {
            if (found) {
                printf(" "); 
            }
            printf("%d", num);
            found = 1;
        }
    }
    
    if (found) {
        printf("\n");
    }
    
    return 0;
}
