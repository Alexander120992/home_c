#include <stdio.h>

int main() {
    int number;
    int count9 = 0;
    
    scanf("%d", &number);

    if (number == 0) {
        printf("NO\n");
        return 0;
    }

    while (number > 0) {
        if (number % 10 == 9) {
            count9++;
        }
        number /= 10;
    }
    
    printf("%s\n", count9 == 1 ? "YES" : "NO");
    
    return 0;
}
