#include <stdio.h>

int main() {
    int number;
    int even_count = 0;  // счетчик четных цифр
    int odd_count = 0;   // счетчик нечетных цифр
    
    scanf("%d", &number);

    if (number < 0) {
        printf("Ошибка: число должно быть неотрицательным\n");
        return 1;
    }

    if (number == 0) {
        printf("1 0\n");
        return 0;
    }

    while (number > 0) {
        int digit = number % 10; 
        
        if (digit % 2 == 0) {     
            even_count++;
        } else {                  
            odd_count++;
        }
        
        number /= 10; 
    }

    printf("%d %d\n", even_count, odd_count);
    
    return 0;
}
