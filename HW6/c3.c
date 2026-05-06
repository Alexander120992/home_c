#include <stdio.h>

int sumFrom1ToN(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

int main() {
    int N;
   
    scanf("%d", &N);

    printf("%d\n", sumFrom1ToN(N));
    
    return 0;
}
