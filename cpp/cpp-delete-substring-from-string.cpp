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
using std::string;

int main()
{
    string initial_string, substring_to_delete;

    cout << "Initial string: ";
    getline(cin, initial_string);
    if (initial_string.empty())
    {
        cerr << "The initial string cannot be empty.\n";
        return 1;
    }
    cout << "Substring to delete: ";
    getline(cin, substring_to_delete);
    if (substring_to_delete.empty())
    {
        cerr << "The substring to delete cannot be empty.\n";
        return 1;
    }

    size_t position = initial_string.find(substring_to_delete);

    if (position == string::npos)
    {
        cout << "Substring not found.\n";
        return 0;
    }

    while (position != string::npos)
    {
        initial_string.erase(position, substring_to_delete.length());
        position = initial_string.find(substring_to_delete);
    }

    cout << "Final string: " << initial_string << "\n";

    return 0;
}

/*
Input and output example:
Initial string: abc123def123g
Substring to delete: 123
Final string: abcdefg

*/
