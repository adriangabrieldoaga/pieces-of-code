/*
Bibliography:
https://en.cppreference.com/w/cpp/language/types
In folder "Bibliography:
Fundamental types - cppreference.com
*/

#include <iostream>
#include <limits>

using std::cout;
using std::numeric_limits;

int main()
{
    cout << "float" << "\n";
    cout << "Min value: " << numeric_limits<float>::min() << "\n";
    cout << "Max value: " << numeric_limits<float>::max() << "\n";
    cout << "Lowest: " << numeric_limits<float>::lowest() << "\n";
    cout << "Epsilon: " << numeric_limits<float>::epsilon() << "\n";
    cout << "Rounding error: " << numeric_limits<float>::round_error() << "\n";
    cout << "Infinity: " << numeric_limits<float>::infinity() << "\n";
    cout << "Quiet NaN: " << numeric_limits<float>::quiet_NaN() << "\n";
    cout << "Signaling NaN: " << numeric_limits<float>::signaling_NaN() << "\n\n";

    cout << "double" << "\n";
    cout << "Min value: " << numeric_limits<double>::min() << "\n";
    cout << "Max value: " << numeric_limits<double>::max() << "\n";
    cout << "Lowest: " << numeric_limits<double>::lowest() << "\n";
    cout << "Epsilon: " << numeric_limits<double>::epsilon() << "\n";
    cout << "Rounding error: " << numeric_limits<double>::round_error() << "\n";
    cout << "Infinity: " << numeric_limits<double>::infinity() << "\n";
    cout << "Quiet NaN: " << numeric_limits<double>::quiet_NaN() << "\n";
    cout << "Signaling NaN: " << numeric_limits<double>::signaling_NaN() << "\n\n";

    cout << "long double: " << "\n";
    cout << "Min value: " << numeric_limits<long double>::min() << "\n";
    cout << "Max value: " << numeric_limits<long double>::max() << "\n";
    cout << "Lowest: " << numeric_limits<long double>::lowest() << "\n";
    cout << "Epsilon: " << numeric_limits<long double>::epsilon() << "\n";
    cout << "Rounding error: " << numeric_limits<long double>::round_error() << "\n";
    cout << "Infinity: " << numeric_limits<long double>::infinity() << "\n";
    cout << "Quiet NaN: " << numeric_limits<long double>::quiet_NaN() << "\n";
    cout << "Signaling NaN: " << numeric_limits<long double>::signaling_NaN() << "\n";

    return 0;
}

/*
Output:
float
Min value: 1.17549e-38
Max value: 3.40282e+38
Lowest: -3.40282e+38
Epsilon: 1.19209e-07
Rounding error: 0.5
Infinity: inf
Quiet NaN: nan
Signaling NaN: nan

double
Min value: 2.22507e-308
Max value: 1.79769e+308
Lowest: -1.79769e+308
Epsilon: 2.22045e-16
Rounding error: 0.5
Infinity: inf
Quiet NaN: nan
Signaling NaN: nan

long double:
Min value: 3.3621e-4932
Max value: 1.18973e+4932
Lowest: -1.18973e+4932
Epsilon: 1.0842e-19
Rounding error: 0.5
Infinity: inf
Quiet NaN: nan
Signaling NaN: nan

*/
