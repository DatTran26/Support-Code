#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DeThiGK_20232.pdf
// 3A
int check(int day, int month, int year)
{
    if (year <= 1970 || year >= 2024)
        return 0;
    else if (month < 1 || month > 12)
        return 0;
    else if (day < 1 || day > 31)
        return 0;
    return 1;
}

int main()
{

    char temp[50];
    int dem = 0;
    char name[100];
    int day, month, year;

    while (scanf("%s", &temp) == 1 && strcmp(temp, "end") != 0 && dem < 100)
    {
        sscanf(temp, "%d-%d-%d,%s", &day, &month, &year, name);
        if (check(day, month, year) == 1)
            dem++;
    }
    printf("%d", dem);

    return 0;
}