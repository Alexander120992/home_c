#include <stdio.h>


unsigned long long RICE(int n) {
    unsigned long long grains = 1;
    
    for (int i = 1; i < n; i++) {
        grains *= 2;
    }
    
    return grains;
}

int main() {
    int N;
    
    scanf("%d", &N);
    
    if (N >= 1 && N <= 64) {
 
        printf("%llu\n", RICE(N));
    }
    
    return 0;
}
