#include <stdio.h>

int main() {
    int number;
    scanf("%d", &number);

    int prev = number % 10;
    number = number / 10;

    while (number > 0) {
        int current = number % 10;
        
        if (current == prev) {
            printf("YES\n");
            return 0;
        }
        
        prev = current;
        number = number / 10;
    }

    printf("NO\n");
    return 0;
}
