#include <stdio.h>

int power(int n, int p) {
    int result = 1;
    
    for (int i = 0; i < p; i++) {
        result *= n;
    }
    
    return result;
}

int main() {
    int N, P;
     
    scanf("%d %d", &N, &P);
    
    printf("%d\n", power(N, P));
    
    return 0;
}
