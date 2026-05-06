#include <stdio.h>

int main() {
    char ch;
    
    scanf("%c", &ch); 
    
    while (ch != '.') {  

        if (ch >= 'A' && ch <= 'Z') {
            ch = ch + 32; 
        }
        printf("%c", ch);  
        
        scanf("%c", &ch); 
    }
        
    return 0;
}
