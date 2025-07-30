/*
The Unlicense
This is basic code, you can use it freely, without any restrictions or attribution.
Creator: Adrian-Gabriel Doaga
Email: adriangabrieldoaga@gmail.com
Website: https://github.com/adriangabrieldoaga/pieces-of-code
Year: 2025
*/

#include <iostream>

using std::cout;
using std::cin;
using std::cerr;
using std::getline;
using std::string;

int main()
{
    string initial_string, substring_to_be_replaced, substring_that_replaces;

    cout << "Initial string: ";
    getline(cin, initial_string);
    if (initial_string.empty())
    {
        cerr << "The initial string cannot be empty.\n";
        return 1;
    }
    cout << "Substring to be replaced: ";
    getline(cin, substring_to_be_replaced);
    if (substring_to_be_replaced.empty())
    {
        cerr << "The substring to be replaced cannot be empty.\n";
        return 1;
    }
    cout << "Substring that replaces: ";
    getline(cin, substring_that_replaces);

    size_t position = initial_string.find(substring_to_be_replaced);

    while (position != string::npos)
    {
        initial_string.replace(position, substring_to_be_replaced.length(), substring_that_replaces);
        position = initial_string.find(substring_to_be_replaced, position + substring_that_replaces.length());
    }

    cout << "\nFinal string: " << initial_string << "\n";

    return 0;
}

/*
Input and output example:
Initial string: abc123def123g
Substring to be replaced: 123
Substring that replaces: ABC

Final string: abcABCdefABCg

*/
