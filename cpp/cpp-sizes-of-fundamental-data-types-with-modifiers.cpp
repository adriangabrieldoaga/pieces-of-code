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

using std::cout;

int main()
{
    cout << "Sizes (in bytes) of fundamental data types with modifiers\n";
    cout << "std::nullptr_t: " << sizeof(std::nullptr_t) << "\n";
    cout << "std::ptrdiff_t: " << sizeof(std::ptrdiff_t) << "\n\n";

    cout << "1. Integral types\n";
    cout << "1.1. Standard integral types\n";
    cout << "signed char: " << sizeof(signed char) << "\n";
    cout << "unsigned char: " << sizeof(unsigned char) << "\n";
    cout << "short: " << sizeof(short) << "\n";
    cout << "short int: " << sizeof(short int) << "\n";
    cout << "signed short: " << sizeof(signed short) << "\n";
    cout << "signed short int: " << sizeof(signed short int) << "\n";
    cout << "unsigned short: " << sizeof(unsigned short) << "\n";
    cout << "unsigned short int: " << sizeof(unsigned short int) << "\n";
    cout << "int: " << sizeof(int) << "\n";
    cout << "signed: " << sizeof(signed) << "\n";
    cout << "signed int: " << sizeof(signed int) << "\n";
    cout << "unsigned: " << sizeof(unsigned) << "\n";
    cout << "unsigned int: " << sizeof(unsigned int) << "\n";
    cout << "long: " << sizeof(long) << "\n";
    cout << "long int: " << sizeof(long int) << "\n";
    cout << "signed long: " << sizeof(signed long) << "\n";
    cout << "signed long int: " << sizeof(signed long int) << "\n";
    cout << "unsigned long: " << sizeof(unsigned long) << "\n";
    cout << "unsigned long int: " << sizeof(unsigned long int) << "\n";
    cout << "long long: " << sizeof(long long) << "\n";
    cout << "long long int: " << sizeof(long long int) << "\n";
    cout << "signed long long: " << sizeof(signed long long) << "\n";
    cout << "signed long long int: " << sizeof(signed long long int) << "\n";
    cout << "unsigned long long: " << sizeof(unsigned long long) << "\n";
    cout << "unsigned long long int: " << sizeof(unsigned long long int) << "\n";
    cout << "std::size_t: " << sizeof(std::size_t) << "\n\n";

    cout << "1.2. Boolean type\n";
    cout << "bool: " << sizeof(bool) << "\n\n";

    cout << "1.3. Character types\n";
    cout << "signed char: " << sizeof(signed char) << "\n";
    cout << "unsigned char: " << sizeof(unsigned char) << "\n";
    cout << "char: " << sizeof(char) << "\n";
    cout << "wchar_t: " << sizeof(wchar_t) << "\n";
    cout << "char16_t: " << sizeof(char16_t) << "\n";
    cout << "char32_t: " << sizeof(char32_t) << "\n\n";
    // cout << "char8_t: " << sizeof(char8_t) << "\n";

    cout << "1.4. Extended integer types (Fixed width integer types)\n";
    cout << "int8_t: " << sizeof(int8_t) << "\n";
    cout << "int16_t: " << sizeof(int16_t) << "\n";
    cout << "int32_t: " << sizeof(int32_t) << "\n";
    cout << "int64_t: " << sizeof(int64_t) << "\n";
    cout << "int_fast8_t: " << sizeof(int_fast8_t) << "\n";
    cout << "int_fast16_t: " << sizeof(int_fast16_t) << "\n";
    cout << "int_fast32_t: " << sizeof(int_fast32_t) << "\n";
    cout << "int_fast64_t: " << sizeof(int_fast64_t) << "\n";
    cout << "int_least8_t: " << sizeof(int_least8_t) << "\n";
    cout << "int_least16_t: " << sizeof(int_least16_t) << "\n";
    cout << "int_least32_t: " << sizeof(int_least32_t) << "\n";
    cout << "int_least64_t: " << sizeof(int_least64_t) << "\n";
    cout << "intmax_t: " << sizeof(intmax_t) << "\n";
    cout << "intptr_t: " << sizeof(intptr_t) << "\n";
    cout << "uint8_t: " << sizeof(uint8_t) << "\n";
    cout << "uint16_t: " << sizeof(uint16_t) << "\n";
    cout << "uint32_t: " << sizeof(uint32_t) << "\n";
    cout << "uint64_t: " << sizeof(uint64_t) << "\n";
    cout << "uint_fast8_t: " << sizeof(uint_fast8_t) << "\n";
    cout << "uint_fast16_t: " << sizeof(uint_fast16_t) << "\n";
    cout << "uint_fast32_t: " << sizeof(uint_fast32_t) << "\n";
    cout << "uint_fast64_t: " << sizeof(uint_fast64_t) << "\n";
    cout << "uint_least8_t: " << sizeof(uint_least8_t) << "\n";
    cout << "uint_least16_t: " << sizeof(uint_least16_t) << "\n";
    cout << "uint_least32_t: " << sizeof(uint_least32_t) << "\n";
    cout << "uint_least64_t: " << sizeof(uint_least64_t) << "\n";
    cout << "uintmax_t: " << sizeof(uintmax_t) << "\n";
    cout << "uintptr_t: " << sizeof(uintptr_t) << "\n\n";

    cout << "2. Floating-point types\n";
    cout << "2.1. Standard floating-point types\n";
    cout << "float: " << sizeof(float) << "\n";
    cout << "double: " << sizeof(double) << "\n";
    cout << "long double: " << sizeof(long double) << "\n\n";
    cout << "2.2. Extended floating-point types (Fixed width floating-point types)" << "\n\n";
    // cout << "float16_t: " << sizeof(float16_t) << "\n";
    // cout << "float32_t: " << sizeof(float32_t) << "\n";
    // cout << "float64_t: " << sizeof(float64_t) << "\n";
    // cout << "float128_t: " << sizeof(float128_t) << "\n";
    // cout << "bfloat16_t: " << sizeof(bfloat16_t) << "\n";

    cout << "3. Pointer types\n";
    cout << "char*: " << sizeof(char*) << "\n";
    cout << "int*: " << sizeof(int*) << "\n";
    cout << "float*: " << sizeof(float*) << "\n";
    cout << "double*: " << sizeof(double*) << "\n";
    cout << "void*: " << sizeof(void*) << "\n\n";

    cout << "4. String types\n";
    cout << "std::string: " << sizeof(std::string) << "\n\n";
    // cout << "std::string_view: " << sizeof(std::string_view) << "\n";
    // cout << "std::wstring_view: " << sizeof(std::wstring_view) << "\n";
    // cout << "std::u8string_view: " << sizeof(std::u8string_view) << "\n";
    // cout << "std::u16string_view: " << sizeof(std::u16string_view) << "\n";
    // cout << "std::u32string_view: " << sizeof(std::u32string_view) << "\n";

    cout << "5. Predefined macros\n";
    cout << "__SIZE_TYPE__: " << sizeof(__SIZE_TYPE__) << "\n";

    return 0;
}

/*
Output:
Sizes (in bytes) of fundamental data types with modifiers
std::nullptr_t: 8
std::ptrdiff_t: 8

1. Integral types
1.1. Standard integral types
signed char: 1
unsigned char: 1
short: 2
short int: 2
signed short: 2
signed short int: 2
unsigned short: 2
unsigned short int: 2
int: 4
signed: 4
signed int: 4
unsigned: 4
unsigned int: 4
long: 4
long int: 4
signed long: 4
signed long int: 4
unsigned long: 4
unsigned long int: 4
long long: 8
long long int: 8
signed long long: 8
signed long long int: 8
unsigned long long: 8
unsigned long long int: 8
std::size_t: 8

1.2. Boolean type
bool: 1

1.3. Character types
signed char: 1
unsigned char: 1
char: 1
wchar_t: 2
char16_t: 2
char32_t: 4

1.4. Extended integer types (Fixed width integer types)
int8_t: 1
int16_t: 2
int32_t: 4
int64_t: 8
int_fast8_t: 1
int_fast16_t: 2
int_fast32_t: 4
int_fast64_t: 8
int_least8_t: 1
int_least16_t: 2
int_least32_t: 4
int_least64_t: 8
intmax_t: 8
intptr_t: 8
uint8_t: 1
uint16_t: 2
uint32_t: 4
uint64_t: 8
uint_fast8_t: 1
uint_fast16_t: 2
uint_fast32_t: 4
uint_fast64_t: 8
uint_least8_t: 1
uint_least16_t: 2
uint_least32_t: 4
uint_least64_t: 8
uintmax_t: 8
uintptr_t: 8

2. Floating-point types
2.1. Standard floating-point types
float: 4
double: 8
long double: 16

2.2. Extended floating-point types (Fixed width floating-point types)

3. Pointer types
char*: 8
int*: 8
float*: 8
double*: 8
void*: 8

4. String types
std::string: 32

5. Predefined macros
__SIZE_TYPE__: 8

*/
