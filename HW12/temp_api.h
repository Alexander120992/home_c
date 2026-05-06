#ifndef TEMP_API_H
#define TEMP_API_H

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
void add_record(struct temperature **data, int *size, struct temperature record);
void delete_record(struct temperature **data, int *size, int index);
void sort_by_temp(struct temperature data[], int size);
void sort_by_date(struct temperature data[], int size);
void print_array(struct temperature data[], int size);
int load_csv(const char *filename, struct temperature **data, int *size);

#endif
