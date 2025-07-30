#include <iostream>

using std::cout;

int main()
{
    cout << "' ' = " << ' ' << "\n"; // Prints Space character
    cout << "' ' - 0 = " << ' ' - 0 << "\n"; // Prints 32
    cout << "'3' = " << '3' << "\n"; // Prints 3
    cout << "'3' - 0 = " << '3' - 0 << "\n"; // Prints 51
    cout << "'3' - '0' = " << '3' - '0' << "\n"; // Prints 3
    cout << "'A' + 32 = " << 'A' + 32 << "\n"; // Prints 97
    cout << "'A' + ' ' = " << 'A' + ' ' << "\n"; // Prints 97
    cout << "char('A' + 32) = " << char('A' + 32) << "\n"; // Prints a
    cout << "char('A' + ' ') = " << char('A' + ' ') << "\n"; // Prints a
    cout << "'a' - 32 = " << 'a' - 32 << "\n"; // Prints 65
    cout << "'a' - ' ' = " << 'a' - ' ' << "\n"; // Prints 65
    cout << "char('a' - 32) = " << char('a' - 32) << "\n"; // Prints A
    cout << "char('a' - ' ') = " << char('a' - ' ') << "\n"; // Prints A

    return 0;
}
