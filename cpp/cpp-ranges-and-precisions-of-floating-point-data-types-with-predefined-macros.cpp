/*
Bibliography:
https://en.cppreference.com/w/cpp/language/types
In folder "Bibliography:
Fundamental types - cppreference.com
*/

#include <iostream>
#include <iomanip>
#include <cfloat>

using std::cout;
using std::setprecision;

int main()
{
    cout << "Floating-point type ranges and precisions (number of decimal digits)\n";
    cout << "float\n";
    cout << "Min value: " << FLT_MIN << "\n";
    cout << "Max value: " << FLT_MAX << "\n";
    cout << "Precision: " << FLT_DIG << "\n\n";

    cout << "double\n";
    cout << "Min value: " << DBL_MIN << "\n";
    cout << "Max value: " << DBL_MAX << "\n";
    cout << "Precision: " << DBL_DIG << "\n\n";

    cout << "long double\n";
    cout << "Min value: " << LDBL_MIN << "\n";
    cout << "Max value: " << LDBL_MAX << "\n";
    cout << "Precision: " << LDBL_DIG << "\n\n";

    cout << "Demonstrating precision with example computations\n";
    float f = 1.0f / 3.0f;
    double d = 1.0 / 3.0;
    long double ld = 1.0L / 3.0L;

    cout << setprecision(10); // Set precision to show 10 digits
    cout << "float (1/3): " << f << "\n";

    cout << setprecision(15); // Set precision to show 15 digits
    cout << "double (1/3): " << d << "\n";

    cout << setprecision(18); // Set precision to show 18 digits
    cout << "long double (1/3): " << ld << "\n";

    return 0;
}

/*
Output:
Floating-point type ranges and precisions (number of decimal digits)
float
Min value: 1.17549e-38
Max value: 3.40282e+38
Precision: 6

double
Min value: 2.22507e-308
Max value: 1.79769e+308
Precision: 15

long double
Min value: 3.3621e-4932
Max value: 1.18973e+4932
Precision: 18

Demonstrating precision with example computations
float (1/3): 0.3333333433
double (1/3): 0.333333333333333
long double (1/3): 0.333333333333333333

*/
