#include <stdio.h>
#include <string.h>

int is_palindrom(char str[]) {
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }
    
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    FILE *input, *output;
    char str[1002];
    
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");
    
    fgets(str, sizeof(str), input);
    
    if (is_palindrom(str)) {
        fprintf(output, "YES");
    } else {
        fprintf(output, "NO");
    }
    
    fclose(input);
    fclose(output);
    
    return 0;
}
