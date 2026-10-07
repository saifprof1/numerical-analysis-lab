#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x)
{
    return x * x * x - 3 * x * x + 2 * x - 2;
}

void modifiedBisection(double a, double b, int n, double epsilon)
{
    double xr, fa, fb, fxr;

    cout << "\nIteration\t a\t\t b\t\t xr\t\t f(xr)\n";

    for (int i = 1; i <= n; i++)
    {
        fa = f(a);
        fb = f(b);

        xr = (a * fabs(fb) + b * fabs(fa))
             / (fabs(fa) + fabs(fb));

        fxr = f(xr);

        cout << i << "\t\t"
             << fixed << setprecision(6)
             << a << "\t"
             << b << "\t"
             << xr << "\t"
             << fxr << endl;

        if (fabs(fxr) < epsilon)
        {
            break;
        }
        else if (fa * fxr < 0)
        {
            b = xr;
        }
        else
        {
            a = xr;
        }
    }

    cout << "\nApproximate Root = "
         << fixed << setprecision(6)
         << xr << endl;
}

int main()
{
    double a, b, epsilon;
    int n;

    cout << "Enter the value of a: ";
    cin >> a;

    cout << "Enter the value of b: ";
    cin >> b;

    cout << "Enter number of iterations: ";
    cin >> n;

    cout << "Enter epsilon: ";
    cin >> epsilon;

    modifiedBisection(a, b, n, epsilon);

    return 0;
}