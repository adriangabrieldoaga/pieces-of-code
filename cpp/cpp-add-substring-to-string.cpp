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
    string initial_string, substring_to_add;
    int position;

    cout << "Initial string: ";
    getline(cin, initial_string);
    cout << "Substring to add: ";
    getline(cin, substring_to_add);
    cout << "Add substring at position: ";
    cin >> position;

    if (cin.fail())
    {
        cerr << "Invalid input for position.\n";
        return 1;
    }

    if (position < 1 || position > initial_string.length() + 1)
    {
        cerr << "Invalid position\n";
        return 1;
    }

    string final_string = initial_string.substr(0, position - 1) + substring_to_add + initial_string.substr(position - 1);

    cout << "Final string: " << final_string << "\n";

    return 0;
}

/*
Input and output example:
Initial string: abcdefg
Substring to add: 123
Add substring at position: 4
Final string: abc123defg

*/
