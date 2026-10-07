#include <iostream>
using namespace std;

int main()
{
    int n, i, j;
    double x[10], y[10];
    double xp, result = 0;
    double term;

    cout << "Enter number of data points: ";
    cin >> n;

    cout << "Enter x and y values:" << endl;

    for (i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    cout << "Enter the value of x to find y: ";
    cin >> xp;

    for (i = 0; i < n; i++)
    {
        term = y[i];

        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                term = term * (xp - x[j]) / (x[i] - x[j]);
            }
        }

        result = result + term;
    }

    cout << "Interpolated value of y = " << result << endl;

    return 0;
}