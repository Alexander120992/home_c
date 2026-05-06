#include <stdio.h>

void reverseDigits(int n) {
    if (n == 0) {
        return;
    }
    
    printf("%d ", n % 10);
    reverseDigits(n / 10);
}

int main() {
    int N;
    scanf("%d", &N);
    
    if (N == 0) {
        printf("0");
    } else {
        reverseDigits(N);
    }
    
    return 0;
}
