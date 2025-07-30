/*
Bibliography:
https://en.cppreference.com/w/cpp/language/types
In folder "Bibliography:
Fundamental types - cppreference.com
*/

#include <iostream>
#include <limits>
#include <iomanip>

using std::cout;
using std::numeric_limits;
using std::fixed;
using std::setprecision;
using std::numeric_limits;

int main()
{
    cout << fixed << setprecision(50);

    cout << "float\n";
    cout << "Precision: " << numeric_limits<float>::digits10 << " decimal digits\n";
    cout << "Max significant digits: " << numeric_limits<float>::max_digits10 << "\n";
    cout << "Example epsilon value: " << numeric_limits<float>::epsilon() << "\n";
    cout << "Min positive normalized value: " << numeric_limits<float>::min() << "\n";
    cout << "Min positive subnormal value: " << numeric_limits<float>::denorm_min() << "\n";
    cout << "Max value: " << numeric_limits<float>::max() << "\n\n";

    cout << "double\n";
    cout << "Precision: " << numeric_limits<double>::digits10 << " decimal digits\n";
    cout << "Max significant digits: " << numeric_limits<double>::max_digits10 << "\n";
    cout << "Example epsilon value: " << numeric_limits<double>::epsilon() << "\n";
    cout << "Min positive normalized value: " << numeric_limits<double>::min() << "\n";
    cout << "Min positive subnormal value: " << numeric_limits<double>::denorm_min() << "\n";
    cout << "Max value: " << numeric_limits<double>::max() << "\n\n";

    cout << "long double\n";
    cout << "Precision: " << numeric_limits<long double>::digits10 << " decimal digits\n";
    cout << "Max significant digits: " << numeric_limits<long double>::max_digits10 << "\n";
    cout << "Example epsilon value: " << numeric_limits<long double>::epsilon() << "\n";
    cout << "Min positive normalized value: " << numeric_limits<long double>::min() << "\n";
    cout << "Min positive subnormal value: " << numeric_limits<long double>::denorm_min() << "\n";
    cout << "Max value: " << numeric_limits<long double>::max() << "\n";

    return 0;
}

