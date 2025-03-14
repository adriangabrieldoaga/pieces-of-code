// Bibliography:
// https://en.cppreference.com/w/cpp/language/types
// In folder "Bibliography:
// Fundamental types - cppreference.com

#include <iostream>

using std::cout;

int main()
{
    cout << "Ranges of integral data types\n";
    cout << "char: " << static_cast<int>(CHAR_MIN) << " to " << static_cast<int>(CHAR_MAX) << "\n";
    cout << "signed char: " << static_cast<int>(SCHAR_MIN) << " to " << static_cast<int>(SCHAR_MAX) << "\n";
    cout << "unsigned char: 0 to " << static_cast<int>(UCHAR_MAX) << "\n";
    cout << "short: " << SHRT_MIN << " to " << SHRT_MAX << "\n";
    cout << "unsigned short: 0 to " << USHRT_MAX << "\n";
    cout << "int: " << INT_MIN << " to " << INT_MAX << "\n";
    cout << "unsigned int: 0 to " << UINT_MAX << "\n";
    cout << "long: " << LONG_MIN << " to " << LONG_MAX << "\n";
    cout << "unsigned long: 0 to " << ULONG_MAX << "\n";
    cout << "long long: " << LLONG_MIN << " to " << LLONG_MAX << "\n";
    cout << "unsigned long long: 0 to " << ULLONG_MAX << "\n";

    return 0;
}
