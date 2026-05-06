#include <stdio.h>
#include <math.h>

int main() {
    int n;
    
    scanf("%d", &n);
    
    if (n <= 1) {
        printf("NO\n");
        return 0;
    }
    
    if (n == 2) {
        printf("YES\n");
        return 0;
    }
    
    if (n % 2 == 0) {
        printf("NO\n");  // четные числа > 2 не простые
        return 0;
    }

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            printf("NO\n");
            return 0;
        }
    }
    
    printf("YES\n");
    return 0;
}
