#include <iostream>

using std::cout;
using std::cin;
using std::cerr;
using std::string;

int main()
{
    string initial_string, substring_to_delete;

    cout << "Initial string: ";
    cin >> initial_string;
    cout << "Substring to delete: ";
    cin >> substring_to_delete;

    size_t position = initial_string.find(substring_to_delete);

    while (position != string::npos)
    {
        initial_string.erase(position, substring_to_delete.length());
        position = initial_string.find(substring_to_delete);
    }

    cout << "Final string: " << initial_string << "\n";

    return 0;
}
