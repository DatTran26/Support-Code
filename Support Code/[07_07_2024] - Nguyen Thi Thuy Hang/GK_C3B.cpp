#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DeThiGK_20232.pdf
// 3B
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
    char ls[50][50];
    char temp[50];
    int dem = 0;
    char name[100];
    int day, month, year;

    while (scanf("%s", &temp) == 1 && strcmp(temp, "end") != 0 && dem < 100)
    {
        dem++;
        strcpy(ls[dem], temp);
    }
    int count[2024] = {0};
    for (int j = 0; j <= dem; j++)
    {
        sscanf(ls[j], "%d-%d-%d, %s", &day, &month, &year, name);
        if (check(day, month, year) == 1)
            count[year]++;
    }
    for (int year = 2023; year > 1970; year--)
    {
        if (count[year] > 0)
            printf("%d %d\n", year, count[year]);
    }

    return 0;
}