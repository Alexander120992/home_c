#ifndef TEMP_FUNCTIONS_H
#define TEMP_FUNCTIONS_H

struct temperature {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int temp;
};

void print_month_stats(struct temperature data[], int size, int month);
void print_year_stats(struct temperature data[], int size);
void print_all_stats(struct temperature data[], int size);
int load_csv(const char *filename, struct temperature **data, int *size);
void free_data(struct temperature *data);

#endif
