#include <stdio.h>

int sumNumbers(int n) {
    if (n == 0) {
        return 0;
    }
    return n + sumNumbers(n - 1);
}

int main() {
    int N;
    scanf("%d", &N);
    
    int result = sumNumbers(N);
    printf("%d", result);
    
    return 0;
}
