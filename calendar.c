#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    int year = 2023;
    int width = 2;
    int start_day = 1; // Monday
    int col_spacing = 6;

    char *month_names[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int month, day, i;

    printf("                                 %d\n", year);

    for (month = 1; month <= 12; month++) {
        printf("\n%20s\n", month_names[month]);
        printf("Mo Tu We Th Fr Sa Su\n");

        for (i = 0; i < start_day; i++) {
            printf("%*s", width + col_spacing, "");
        }

        for (day = 1; day <= days_in_month[month]; day++) {
            printf("%2d", day);

            if ((day + start_day - 1) % 7 == 0 || day == days_in_month[month]) {
                printf("\n");
            } else {
                printf("%*s", width, "");
            }
        }

        start_day = (start_day + days_in_month[month]) % 7;
    }

    return 0;
}
