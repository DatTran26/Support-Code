
#include <stdio.h>

// DeThiGK_20232.pdf

int main()
{
    int n;
    double x, y, minX, maxX, minY, maxY;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {

        scanf("%lf %lf", &x, &y);
        if (x < minX)
            minX = x;
        if (x > maxX)
            maxX = x;
        if (y < minY)
            minY = y;
        if (y > maxY)
            maxY = y;
    }

    double x_trongtam = (minX + maxX) / 2;
    double y_trongtam = (minY + maxY) / 2;

    printf("%.4lf %.4lf\n", x_trongtam, y_trongtam);
    printf("%.4lf %.4lf %.4lf %.4lf\n", minX, minY, maxX, maxY);

    return 0;
}
