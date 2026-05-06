#include <stdio.h>

int main() {
    int n;
    
    scanf("%d", &n);

    if (n <= 0) {
        printf("число должно быть натуральным (больше 0)\n");
        return 1;
    }

    long long fib1 = 1;  // F(1)
    long long fib2 = 1;  // F(2)
    
    if (n >= 1) {
        printf("%lld", fib1);
    }
    
    if (n >= 2) {
        printf(" %lld", fib2);
    }

    for (int i = 3; i <= n; i++) {
        long long next = fib1 + fib2;
        printf(" %lld", next);

        fib1 = fib2;
        fib2 = next;
    }
    
    printf("\n");
    
    return 0;
}
