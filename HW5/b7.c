#include <stdio.h>

int main() {
    int number;
    scanf("%d", &number);

    for (int i = 0; i <= 9; i++) {
        int count = 0;
        int temp = number;

        while (temp > 0) {
            if (temp % 10 == i) {
                count++;
                if (count >= 2) {
                    printf("YES\n");
                    return 0;
                }
            }
            temp /= 10;
        }

        if (number == 0 && i == 0) {
            count = 1;
        }
    }
    
    printf("NO\n");
    return 0;
}
