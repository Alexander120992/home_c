#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "temp_api.h"

void print_help() {
    printf("Temperature statistics application\n\n");
    printf("Usage: app [options]\n\n");
    printf("Options:\n");
    printf("  -h                 Show this help message\n");
    printf("  -f <filename>      Input CSV file with temperature data\n");
    printf("  -m <month>         Show statistics only for specified month (1-12)\n");
    printf("\nInput file format:\n");
    printf("  YYYY MM DD HH MM TEMP\n");
    printf("  Example: 2024 01 15 12 30 -5\n");
}

int main(int argc, char *argv[]) {
    struct temperature *data = NULL;
    int size = 0;
    char *filename = NULL;
    int month = -1;
    
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0) {
            print_help();
            return 0;
        } else if (strcmp(argv[i], "-f") == 0) {
            if (i + 1 < argc) {
                filename = argv[i + 1];
                i++;
            } else {
                printf("Error: -f requires filename\n");
                return 1;
            }
        } else if (strcmp(argv[i], "-m") == 0) {
            if (i + 1 < argc) {
                month = atoi(argv[i + 1]);
                i++;
            } else {
                printf("Error: -m requires month number\n");
                return 1;
            }
        }
    }
    
    if (filename == NULL) {
        printf("Error: input file required (-f filename)\n");
        printf("Use -h for help\n");
        return 1;
    }
    
    if (!load_csv(filename, &data, &size)) {
        return 1;
    }
    
    if (month != -1) {
        if (month < 1 || month > 12) {
            printf("Error: month must be between 1 and 12\n");
            free(data);
            return 1;
        }
        print_month_stats(data, size, month);
    } else {
        print_all_stats(data, size);
    }
    
    free(data);
    return 0;
}
