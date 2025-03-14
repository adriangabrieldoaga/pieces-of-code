// Also called quadratic equation

#include <iostream>
#include <cmath>

using std::cout;
using std::cin;

int main()
{
    double a, b, c, x1, x2, delta;

    cout << "Quadratic equation: ax^2 + bx + c = 0\n";
    while (1)
    {
        cout << "a = ";
        cin >> a;
        cout << "b = ";
        cin >> b;
        cout << "c = ";
        cin >> c;
        delta = b * b - 4 * a * c;
        cout << "delta = " << delta;
        if ( (a == 0) && (b == 0) && (c == 0) )
        {
            cout << "\nx can be any real number\n\n";
            continue;
        }
        if ( (a == 0) && (b == 0) && (c != 0) )
        {
            cout << "\nThe equation has no solutions\n\n";
            continue;
        }
        if (delta >= 0)
        {
            if (delta == 0)
            {
                cout << " ===> x1 = x2 (one solution)\n";
            }
            else
            {
                cout << "\n";
            }
            cout << "x1 = " << (-b + sqrt(delta) ) / (2 * a) << "\nx2 = "
                 << (-b - sqrt(delta) ) / (2 * a);
        }
        else
        {
            cout << "\nx1 = " << - b / (2 * a);
            if (sqrt(-delta) / (2 * a) >= 0)
            {
                cout << " + ";
            }
            else
            {
                cout << " - ";
            }
            cout << abs(sqrt(-delta) / (2 * a)) << "i\n";
            cout << "x2 = " << -b / (2 * a);
            if (-sqrt(-delta) / (2 * a) >= 0)
            {
                cout << " + ";
            }
            else
            {
                cout << " - ";
            }
            cout << abs(-sqrt(-delta) / (2 * a)) << "i";
        }
        cout << "\n\n";
    }

    return 0;
}
