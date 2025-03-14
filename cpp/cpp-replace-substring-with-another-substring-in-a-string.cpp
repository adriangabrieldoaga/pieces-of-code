#include <iostream>

using std::cout;
using std::cin;
using std::cerr;
using std::string;

int main()
{
    string initial_string, substring_that_replaces, substring_to_be_replaced;

    cout << "Initial string: ";
    cin >> initial_string;
    cout << "Substring that replaces: ";
    cin >> substring_that_replaces;
    cout << "Substring to be replaced: ";
    cin >> substring_to_be_replaced;

    size_t position = initial_string.find(substring_to_be_replaced);

    while (position != string::npos)
    {
        initial_string.replace(position, substring_to_be_replaced.length(), substring_that_replaces);
        position = initial_string.find(substring_to_be_replaced, position + substring_that_replaces.length());
    }

    cout << "\nFinal string: " << initial_string << "\n";

    return 0;
}
