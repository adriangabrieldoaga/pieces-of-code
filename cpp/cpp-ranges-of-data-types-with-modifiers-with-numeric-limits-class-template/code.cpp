/*
Bibliography:
https://en.cppreference.com/w/cpp/language/types
https://en.cppreference.com/w/cpp/types/integer
https://en.cppreference.com/w/cpp/types/floating-point
In folder "Bibliography:
Fundamental types - cppreference.com
Fixed width integer types (since C++11) - cppreference.com
Fixed width floating-point types (since C++23) - cppreference.com
*/

#include <iostream>
#include <limits>
#include <string_view>
#include <string>

using std::cout;
using std::numeric_limits;

int main()
{
    cout << "Ranges of data types with modifiers\n";
    cout << "std::ptrdiff_t: " << numeric_limits<std::ptrdiff_t>::min() << " to " << numeric_limits<std::ptrdiff_t>::max() << "\n\n";

    cout << "1. Integral types\n";
    cout << "1.1. Standard integral types\n";
    cout << "signed char: " << numeric_limits<signed char>::min() << " to " << numeric_limits<signed char>::max() << "\n";
    cout << "unsigned char: " << numeric_limits<unsigned char>::min() << " to " << numeric_limits<unsigned char>::max() << "\n";
    cout << "short: " << numeric_limits<short>::min() << " to " << numeric_limits<short>::max() << "\n";
    cout << "short int: " << numeric_limits<short int>::min() << " to " << numeric_limits<short int>::max() << "\n";
    cout << "signed short: " << numeric_limits<signed short>::min() << " to " << numeric_limits<signed short>::max() << "\n";
    cout << "signed short int: " << numeric_limits<signed short int>::min() << " to " << numeric_limits<signed short int>::max() << "\n";
    cout << "unsigned short: " << numeric_limits<unsigned short>::min() << " to " << numeric_limits<unsigned short>::max() << "\n";
    cout << "unsigned short int: " << numeric_limits<unsigned short int>::min() << " to " << numeric_limits<unsigned short int>::max() << "\n";
    cout << "int: " << numeric_limits<int>::min() << " to " << numeric_limits<int>::max() << "\n";
    cout << "signed: " << numeric_limits<signed>::min() << " to " << numeric_limits<signed>::max() << "\n";
    cout << "signed int: " << numeric_limits<signed int>::min() << " to " << numeric_limits<signed int>::max() << "\n";
    cout << "unsigned: " << numeric_limits<unsigned>::min() << " to " << numeric_limits<unsigned>::max() << "\n";
    cout << "unsigned int: " << numeric_limits<unsigned int>::min() << " to " << numeric_limits<unsigned int>::max() << "\n";
    cout << "long: " << numeric_limits<long>::min() << " to " << numeric_limits<long>::max() << "\n";
    cout << "long int: " << numeric_limits<long int>::min() << " to " << numeric_limits<long int>::max() << "\n";
    cout << "signed long: " << numeric_limits<signed long>::min() << " to " << numeric_limits<signed long>::max() << "\n";
    cout << "signed long int: " << numeric_limits<signed long int>::min() << " to " << numeric_limits<signed long int>::max() << "\n";
    cout << "unsigned long: " << numeric_limits<unsigned long>::min() << " to " << numeric_limits<unsigned long>::max() << "\n";
    cout << "unsigned long int: " << numeric_limits<unsigned long int>::min() << " to " << numeric_limits<unsigned long int>::max() << "\n";
    cout << "long long: " << numeric_limits<long long>::min() << " to " << numeric_limits<long long>::max() << "\n";
    cout << "long long int: " << numeric_limits<long long int>::min() << " to " << numeric_limits<long long int>::max() << "\n";
    cout << "signed long long: " << numeric_limits<signed long long>::min() << " to " << numeric_limits<signed long long>::max() << "\n";
    cout << "signed long long int: " << numeric_limits<signed long long int>::min() << " to " << numeric_limits<signed long long int>::max() << "\n";
    cout << "unsigned long long: " << numeric_limits<unsigned long long>::min() << " to " << numeric_limits<unsigned long long>::max() << "\n";
    cout << "unsigned long long int: " << numeric_limits<unsigned long long int>::min() << " to " << numeric_limits<unsigned long long int>::max() << "\n";
    cout << "std::size_t: " << numeric_limits<std::size_t>::min() << " to " << numeric_limits<std::size_t>::max() << "\n\n";

    cout << "1.2. Boolean type\n";
    cout << "bool: " << numeric_limits<bool>::min() << " to " << numeric_limits<bool>::max() << "\n\n";

    cout << "1.3. Character types\n";
    cout << "signed char: " << numeric_limits<signed char>::min() << " to " << numeric_limits<signed char>::max() << "\n";
    cout << "unsigned char: " << numeric_limits<unsigned char>::min() << " to " << numeric_limits<unsigned char>::max() << "\n";
    cout << "char: " << numeric_limits<char>::min() << " to " << numeric_limits<char>::max() << "\n";
    cout << "wchar_t: " << numeric_limits<wchar_t>::min() << " to " << numeric_limits<wchar_t>::max() << "\n";
    cout << "char16_t: " << numeric_limits<char16_t>::min() << " to " << numeric_limits<char16_t>::max() << "\n";
    cout << "char32_t: " << numeric_limits<char32_t>::min() << " to " << numeric_limits<char32_t>::max() << "\n\n";
    // cout << "char8_t: " << numeric_limits<char8_t>::min() << " to " << numeric_limits<char8_t>::max() << "\n";

    cout << "1.4. Extended integer types (Fixed width integer types)\n";
    cout << "int8_t: " << numeric_limits<int8_t>::min() << " to " << numeric_limits<int8_t>::max() << "\n";
    cout << "int16_t: " << numeric_limits<int16_t>::min() << " to " << numeric_limits<int16_t>::max() << "\n";
    cout << "int32_t: " << numeric_limits<int32_t>::min() << " to " << numeric_limits<int32_t>::max() << "\n";
    cout << "int64_t: " << numeric_limits<int64_t>::min() << " to " << numeric_limits<int64_t>::max() << "\n";
    cout << "int_fast8_t: " << numeric_limits<int_fast8_t>::min() << " to " << numeric_limits<int_fast8_t>::max() << "\n";
    cout << "int_fast16_t: " << numeric_limits<int_fast16_t>::min() << " to " << numeric_limits<int_fast16_t>::max() << "\n";
    cout << "int_fast32_t: " << numeric_limits<int_fast32_t>::min() << " to " << numeric_limits<int_fast32_t>::max() << "\n";
    cout << "int_fast64_t: " << numeric_limits<int_fast64_t>::min() << " to " << numeric_limits<int_fast64_t>::max() << "\n";
    cout << "int_least8_t: " << numeric_limits<int_least8_t>::min() << " to " << numeric_limits<int_least8_t>::max() << "\n";
    cout << "int_least16_t: " << numeric_limits<int_least16_t>::min() << " to " << numeric_limits<int_least16_t>::max() << "\n";
    cout << "int_least32_t: " << numeric_limits<int_least32_t>::min() << " to " << numeric_limits<int_least32_t>::max() << "\n";
    cout << "int_least64_t: " << numeric_limits<int_least64_t>::min() << " to " << numeric_limits<int_least64_t>::max() << "\n";
    cout << "intmax_t: " << numeric_limits<intmax_t>::min() << " to " << numeric_limits<intmax_t>::max() << "\n";
    cout << "intptr_t: " << numeric_limits<intptr_t>::min() << " to " << numeric_limits<intptr_t>::max() << "\n";
    cout << "uint8_t: " << numeric_limits<uint8_t>::min() << " to " << numeric_limits<uint8_t>::max() << "\n";
    cout << "uint16_t: " << numeric_limits<uint16_t>::min() << " to " << numeric_limits<uint16_t>::max() << "\n";
    cout << "uint32_t: " << numeric_limits<uint32_t>::min() << " to " << numeric_limits<uint32_t>::max() << "\n";
    cout << "uint64_t: " << numeric_limits<uint64_t>::min() << " to " << numeric_limits<uint64_t>::max() << "\n";
    cout << "uint_fast8_t: " << numeric_limits<uint_fast8_t>::min() << " to " << numeric_limits<uint_fast8_t>::max() << "\n";
    cout << "uint_fast16_t: " << numeric_limits<uint_fast16_t>::min() << " to " << numeric_limits<uint_fast16_t>::max() << "\n";
    cout << "uint_fast32_t: " << numeric_limits<uint_fast32_t>::min() << " to " << numeric_limits<uint_fast32_t>::max() << "\n";
    cout << "uint_fast64_t: " << numeric_limits<uint_fast64_t>::min() << " to " << numeric_limits<uint_fast64_t>::max() << "\n";
    cout << "uint_least8_t: " << numeric_limits<uint_least8_t>::min() << " to " << numeric_limits<uint_least8_t>::max() << "\n";
    cout << "uint_least16_t: " << numeric_limits<uint_least16_t>::min() << " to " << numeric_limits<uint_least16_t>::max() << "\n";
    cout << "uint_least32_t: " << numeric_limits<uint_least32_t>::min() << " to " << numeric_limits<uint_least32_t>::max() << "\n";
    cout << "uint_least64_t: " << numeric_limits<uint_least64_t>::min() << " to " << numeric_limits<uint_least64_t>::max() << "\n";
    cout << "uintmax_t: " << numeric_limits<uintmax_t>::min() << " to " << numeric_limits<uintmax_t>::max() << "\n";
    cout << "uintptr_t: " << numeric_limits<uintptr_t>::min() << " to " << numeric_limits<uintptr_t>::max() << "\n\n";

    cout << "2. Floating-point types\n";
    cout << "2.1. Standard floating-point types\n";
    cout << "float: " << numeric_limits<float>::min() << " to " << numeric_limits<float>::max() << "\n";
    cout << "double: " << numeric_limits<double>::min() << " to " << numeric_limits<double>::max() << "\n";
    cout << "long double: " << numeric_limits<long double>::min() << " to " << numeric_limits<long double>::max() << "\n\n";
    cout << "2.2. Extended floating-point types (Fixed width floating-point types)" << "\n\n";
    // cout << "float16_t: " << numeric_limits<float16_t>::min() << " to " << numeric_limits<float16_t>::max() << "\n";
    // cout << "float32_t: " << numeric_limits<float32_t>::min() << " to " << numeric_limits<float32_t>::max() << "\n";
    // cout << "float64_t: " << numeric_limits<float64_t>::min() << " to " << numeric_limits<float64_t>::max() << "\n";
    // cout << "float128_t: " << numeric_limits<float128_t>::min() << " to " << numeric_limits<float128_t>::max() << "\n";
    // cout << "bfloat16_t: " << numeric_limits<bfloat16_t>::min() << " to " << numeric_limits<bfloat16_t>::max() << "\n";

    cout << "3. Pointer types" << "\n\n";
    // cout << "char*: " << numeric_limits<char*>::min() << " to " << numeric_limits<char*>::max() << "\n";
    // cout << "int*: " << numeric_limits<int*>::min() << " to " << numeric_limits<int*>::max() << "\n";
    // cout << "float*: " << numeric_limits<float*>::min() << " to " << numeric_limits<float*>::max() << "\n";
    // cout << "double*: " << numeric_limits<double*>::min() << " to " << numeric_limits<double*>::max() << "\n";
    // cout << "void*: " << numeric_limits<void*>::min() << " to " << numeric_limits<void*>::max() << "\n\n";

    cout << "4. String types\n";
    cout << "std::string: " << numeric_limits<std::string>::min() << " to " << numeric_limits<std::string>::max() << "\n\n";

    // cout << "std::string_view: " << numeric_limits<std::string_view>::min() << " to " << numeric_limits<std::string_view>::max() << "\n";
    // cout << "std::wstring_view: " << numeric_limits<std::wstring_view>::min() << " to " << numeric_limits<std::wstring_view>::max() << "\n";
    // cout << "std::u8string_view: " << numeric_limits<std::u8string_view>::min() << " to " << numeric_limits<std::u8string_view>::max() << "\n";
    // cout << "std::u16string_view: " << numeric_limits<std::u16string_view>::min() << " to " << numeric_limits<std::u16string_view>::max() << "\n";
    // cout << "std::u32string_view: " << numeric_limits<std::u32string_view>::min() << " to " << numeric_limits<std::u32string_view>::max() << "\n";

    cout << "5. Predefined macros\n";
    cout << "__SIZE_TYPE__: " << numeric_limits<__SIZE_TYPE__>::min() << " to " << numeric_limits<__SIZE_TYPE__>::max() << "\n";

    return 0;
}
