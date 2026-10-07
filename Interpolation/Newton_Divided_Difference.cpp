#include <iostream>
using namespace std;

int main()
{
    int n, i, j;
    double x[10], y[10][10], value, result, term;

    cout << "Enter number of data points: ";
    cin >> n;

    cout << "Enter x values:" << endl;

    for (i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    cout << "Enter y values:" << endl;

    for (i = 0; i < n; i++)
    {
        cin >> y[i][0];
    }

    // Divided Difference Table
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            y[j][i] = (y[j + 1][i - 1] - y[j][i - 1])
                      / (x[j + i] - x[j]);
        }
    }

    cout << "Enter the value of x to find f(x): ";
    cin >> value;

    // Newton's Interpolation Formula
    result = y[0][0];

    for (j = 1; j < n; j++)
    {
        term = y[0][j];

        for (i = 0; i < j; i++)
        {
            term = term * (value - x[i]);
        }

        result = result + term;
    }

    cout << "\nf(" << value << ") = " << result << endl;

    return 0;
}