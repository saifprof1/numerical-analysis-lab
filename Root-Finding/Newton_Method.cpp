#include <iostream>
#include <cmath>
using namespace std;

double function(double x)
{
    return x * x * x - 6 * x * x + 11 * x - 6;
}

double derivative(double x)
{
    return 3 * x * x - 12 * x + 11;
}

double newtonRaphson(double x, double epsilon)
{
    double x_new;

    for (int i = 0; i < 100; i++)
    {
        if (fabs(derivative(x)) < 1e-12)
        {
            return NAN;
        }

        x_new = x - function(x) / derivative(x);

        if (fabs(x_new - x) < epsilon)
        {
            return x_new;
        }

        x = x_new;
    }

    return NAN;
}

int main()
{
    int n;
    double epsilon;

    cout << "Enter number of initial guesses: ";
    cin >> n;

    cout << "Enter epsilon: ";
    cin >> epsilon;

    double roots[100];
    int rootCount = 0;

    for (int i = 0; i < n; i++)
    {
        double x;

        cout << "\nEnter initial guess " << i + 1 << ": ";
        cin >> x;

        double root = newtonRaphson(x, epsilon);

        if (isnan(root))
        {
            cout << "No convergence from this initial guess." << endl;
            continue;
        }

        bool duplicate = false;

        for (int j = 0; j < rootCount; j++)
        {
            if (fabs(root - roots[j]) < epsilon)
            {
                duplicate = true;
                break;
            }
        }

        if (!duplicate)
        {
            roots[rootCount] = root;
            rootCount++;
        }
    }

    cout << "\nDistinct roots are:" << endl;

    for (int i = 0; i < rootCount; i++)
    {
        cout << "Root " << i + 1 << " = " << roots[i] << endl;
    }

    return 0;
}