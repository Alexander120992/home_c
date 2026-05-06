#include <stdio.h>
#include <string.h>

int main() {
    FILE *input, *output;
    char str[102];  
    
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");

    fgets(str, sizeof(str), input);

    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }

    fprintf(output, "%s, %s, %s %d", str, str, str, len);
    
    fclose(input);
    fclose(output);
    
    return 0;
}
