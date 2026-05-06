#include <stdio.h>

int main() {
    FILE *input, *output;
    int N;
    char result[27];  
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");
    
    fscanf(input, "%d", &N);
    
    int digit = 2;     
    char letter = 'A';

    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {

            result[i] = letter;
            letter++;
        } else {
            result[i] = digit + '0';
            digit += 2;
            if (digit > 8) digit = 2; 
        }
    }
    result[N] = '\0';

    fprintf(output, "%s", result);
    
    fclose(input);
    fclose(output);
    
    return 0;
}
