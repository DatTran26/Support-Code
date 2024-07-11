#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> phanSo(n);

    for (int i = 0; i < n; i++)
    {
        cin >> phanSo[i].first >> phanSo[i].second;
    }

    double minKhoangCach = numeric_limits<double>::max();
    pair<int, int> capGanNhat;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double giaTri1 = (double)phanSo[i].first / phanSo[i].second;
            double giaTri2 = (double)phanSo[j].first / phanSo[j].second;
            double khoangCach = abs(giaTri1 - giaTri2);
            if (khoangCach < minKhoangCach)
            {
                minKhoangCach = khoangCach;
                capGanNhat = {i, j};
            }
        }
    }
    cout << capGanNhat.first << " " << capGanNhat.second << endl;

    return 0;
}
