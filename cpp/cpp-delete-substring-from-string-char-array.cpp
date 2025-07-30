/*
The Unlicense
This is basic code, you can use it freely, without any restrictions or attribution.
Creator: Adrian-Gabriel Doaga
Email: adriangabrieldoaga@gmail.com
Website: https://github.com/adriangabrieldoaga/pieces-of-code
Year: 2025
*/

#include <iostream>
#include <cstring>

using std::cout;
using std::cerr;

int main()
{
    char initial_string[] = "abc123def123g";
    if (strlen(initial_string) == 0)
    {
        cerr << "The initial string cannot be empty.\n";
        return 1;
    }
    char substring_to_delete[] = "123";
    if (strlen(substring_to_delete) == 0)
    {
        cerr << "The substring to delete cannot be empty.\n";
        return 1;
    }

    int substring_to_delete_length = strlen(substring_to_delete);
    char *p = nullptr;

    p = strstr(initial_string, substring_to_delete);
    while (p)
    {
        strcpy(p, p + substring_to_delete_length);
        p = strstr(initial_string, substring_to_delete);
    }

    cout << initial_string << "\n";

    return 0;
}

/*
Output:
abcdefg

*/
