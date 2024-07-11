#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DeThiGK_20232.pdf
int main()
{
    int numbers[100];
    int count = 0;
    char input[10];

    while (scanf("%s", input) == 1 && strcmp(input, "end") != 0 && count < 100)
    {
        int num = atoi(input);
        if (num > 0)
        {
            numbers[count++] = num;
        }
    }

    if (count == 0)
    {
        printf("Null\n");
        return 0;
    }

    double sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += numbers[i];
    }
    double tbds = sum / count;

    // for (int i = 0; i < count - 1; i++)
    // {
    //     for (int j = i + 1; j < count; j++)
    //     {
    //         if (numbers[i] > numbers[j])
    //         {
    //             int temp = numbers[i];
    //             numbers[i] = numbers[j];
    //             numbers[j] = temp;
    //         }
    //     }
    // }

    double median;
    if (count % 2 == 0)
    {
        median = double(numbers[count / 2 - 1] + numbers[count / 2]) / 2;
    }
    else
    {
        median = numbers[count / 2];
    }

    if (tbds > median)
    {
        printf("greater");
    }
    else if (tbds < median)
    {
        printf("smaller");
    }
    else
    {
        printf("equal");
    }

    return 0;
}
